#include <condition_variable>
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <shared_mutex>


class ThreadSpawner {
private:

    std::jthread coordinator_;
    std::vector<std::jthread> workers_;

    long int timestamp_;
    std::condition_variable_any timestampCondition_;
    bool timestampUpdated_;     // Start condition for the workers
    std::atomic<int> timestampAccesses_;    // Start condition for the coordinator

    std::shared_mutex timestampMutex_;

public:
    ThreadSpawner(): timestampUpdated_(false), timestampAccesses_(10) {
        coordinator_ = std::jthread([this](std::stop_token sToken){
            while (!sToken.stop_requested()) {
                // Sleep for a while
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));

                {
                    // Acquire and lock access to the timestamp
                    std::cout << "accesses: " << this->timestampAccesses_ << ", size: " << this->timestampAccesses_ << std::endl;
                    std::unique_lock<std::shared_mutex> lockTimestamp(this->timestampMutex_);
                    this->timestampCondition_.wait(lockTimestamp, [this] { return static_cast<long unsigned int>(this->timestampAccesses_) == this->workers_.size(); });
                    this->timestampAccesses_ = 0;
                    
                    // Do his job: update timestamp
                    std::cout << "==> Coordinator thread " << std::this_thread::get_id() << " updating timestamp..." << std::endl;
                    std::chrono::system_clock::time_point tpNow = std::chrono::system_clock::now();
                    this->timestamp_ = std::chrono::duration_cast<std::chrono::seconds>(tpNow.time_since_epoch()).count();

                    // Job completed: update condition
                    this->timestampUpdated_ = true;
                    std::cout << "==> ... timestamp updated by Coordinator thread" << std::endl;
                }

                // Notify all waiting threads, so they can use the timestamp
                this->timestampCondition_.notify_all();

                // ASSUMPTION 1: worker_'s processing time is greater than the time taken to have all workers started.
                // ASSUMPTION 2: coordinator_'s sleep is greater than any worker_'s processing time.
            }
        });

        for (int i = 0; i < 10; ++i) {
            workers_.push_back(
                std::jthread([this](std::stop_token sToken){
                    while (!sToken.stop_requested()) {
                        {
                            std::shared_lock<std::shared_mutex> lockTimestamp(this->timestampMutex_);
                            timestampCondition_.wait(lockTimestamp, [this] { return this->timestampUpdated_ && static_cast<long unsigned int>(this->timestampAccesses_) < this->workers_.size(); });

                            this->timestampAccesses_++;
                            std::cout << "Thread " << std::this_thread::get_id() << " accessed timestamp " << this->timestamp_ << ". Current access count is: " << this->timestampAccesses_ << std::endl;
                            std::this_thread::sleep_for(std::chrono::milliseconds(100));
                        }

                        // Attempt to awake coordinator_
                        this->timestampCondition_.notify_one();
                    }
                })
            );
        }
    }

    ~ThreadSpawner() {
        for (auto& worker : workers_) {
            worker.request_stop();
        }
        coordinator_.request_stop();
    }
};


int main () {

    ThreadSpawner* ts = new ThreadSpawner();

    std::this_thread::sleep_for(std::chrono::seconds(23));
    
    delete ts;
    
    return 0;
    // Valgrind passed, everything freed!
}
