#include "PriceRecorder.h"

#include <cstdio>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <memory>
#include <semaphore>
#include <thread>
#include <vector>

#include "Menu.h"

PriceRecorder::PriceRecorder(std::shared_ptr<Menu> menu): pendingWork_{0} {
    // Periodically records each product's price into separate files in the same folder.
    // Each file is accessed by an independent thread, which track a single product.
    // On each update, a shared timer variable is updated so all threads use the same timestamp.
    //
    // ASSUMPTION 1: worker_'s processing time is greater than the time taken to have all workers started.
    // ASSUMPTION 2: coordinator_'s sleep is greater than any worker_'s processing time.
    
    size_t numProducts = menu->products().size();

    coordinator_ = std::jthread([this, numProducts](std::stop_token sToken){

        while (this->workers_.size() != numProducts) {
            // Wait until all workers are created
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::cout << "Waiting..." << std::endl;
        }

        std::chrono::system_clock::time_point tpNow = std::chrono::system_clock::now();
        std::chrono::system_clock::time_point tpNext = tpNow + std::chrono::seconds(5);

        while (!sToken.stop_requested()) {
            // Sleep until next timestamp capture
            std::this_thread::sleep_until(tpNext);
            tpNow = tpNext;
            tpNext = tpNow + std::chrono::seconds(5);

            // // Do his job: update timestamp
            this->timestamp_ = std::chrono::duration_cast<std::chrono::seconds>(tpNow.time_since_epoch()).count();
            
            // Signal workers to resume their job
            this->pendingWork_.release(numProducts);
        }
    });

    std::string dirPath = "./data/historical";
    if (!std::filesystem::exists(dirPath)) {
        std::filesystem::create_directories(dirPath);
    }

    for (const auto& product : menu->products()) {
        workers_.push_back(
            std::jthread([&product, dirPath, this](std::stop_token sToken){
                std::string filename = dirPath + "/" + product.ticker() + ".csv";

                remove(filename.c_str());
                
                std::ofstream outfile(filename.c_str(), std::ios::app);
                if (!outfile.is_open()) {
                    std::cout << "Unable to open file '" << filename << "' for appending." << std::endl;
                    return;
                }

                while (!sToken.stop_requested()) {
                    // Register access to the timestamp
                    this->pendingWork_.acquire();

                    // Do its stuff
                    outfile << this->timestamp_ << "," << product.ticker() << "," << product.price() << "," << product.stock() << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(10));
                }

                outfile.close();
            })
        );
    }
}

PriceRecorder::~PriceRecorder() {
    for (auto& worker : workers_) {
        worker.request_stop();
    }
    coordinator_.request_stop();
}
