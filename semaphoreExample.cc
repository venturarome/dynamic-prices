#include <condition_variable>
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <shared_mutex>
#include <semaphore>


class ThreadSpawner {
private:

    std::jthread coordinator_;
    std::vector<std::jthread> workers_;

    long int timestamp_;
    std::binary_semaphore pendingWork_;

public:
    ThreadSpawner(): pendingWork_{0} {
        coordinator_ = std::jthread([this](std::stop_token sToken){
            while (!sToken.stop_requested()) {

                // Sleep for a while
                std::this_thread::sleep_for(std::chrono::milliseconds(5000));

                // Do his job: update timestamp
                std::cout << "==> Coordinator thread " << std::this_thread::get_id() << " updating timestamp..." << std::endl;
                std::chrono::system_clock::time_point tpNow = std::chrono::system_clock::now();
                this->timestamp_ = std::chrono::duration_cast<std::chrono::seconds>(tpNow.time_since_epoch()).count();

                // Signal workers to resume their job
                this->pendingWork_.release(this->workers_.size());
            
                // ASSUMPTION 1: worker_'s processing time is greater than the time taken to have all workers started.
                // ASSUMPTION 2: coordinator_'s sleep is greater than any worker_'s processing time.
            }
        });

        for (int i = 0; i < 10; ++i) {
            workers_.push_back(
                std::jthread([this](std::stop_token sToken){
                    while (!sToken.stop_requested()) {

                        // Acquire access to the timestamp
                        this->pendingWork_.acquire();

                        // Do its stuff
                        std::cout << "Thread " << std::this_thread::get_id() << " accessed timestamp " << this->timestamp_ << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));
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

    std::this_thread::sleep_for(std::chrono::seconds(32));
    
    delete ts;
    
    return 0;
    // Valgrind passed, everything freed!
}
