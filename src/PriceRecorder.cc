#include <cstdio>
#include <filesystem>
#include <fstream>
#include <memory>
#include <vector>

#include "Menu.h"
#include "PriceRecorder.h"

PriceRecorder::PriceRecorder(std::shared_ptr<Menu> menu) {
    std::string dirPath = "./data/historical";
    if (!std::filesystem::exists(dirPath)) {
        std::filesystem::create_directories(dirPath);
    }

    for (const auto& product : menu->products()) {
        threads_.push_back(
            std::jthread([&product, dirPath](std::stop_token sToken){
                std::string filename = dirPath + "/" + product.ticker() + ".csv";

                remove(filename.c_str());
                
                std::ofstream outfile(filename.c_str(), std::ios::app);
                if (!outfile.is_open()) {
                    std::cout << "Unable to open file '" << filename << "' for appending." << std::endl;
                    return;
                }

                while (!sToken.stop_requested()) {
                    outfile << product.ticker() << "," << product.price() << "," << product.stock() << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                }

                outfile.close();
            })
        );
    }
}

PriceRecorder::~PriceRecorder() {
    for (auto& thread : threads_) {
        thread.request_stop();
        thread.join();      // TODO test if this is really needed (they are "J"threads).
    }
}

PriceRecorder::PriceRecorder(PriceRecorder&& other) noexcept : threads_(std::move(other.threads_)) {}
PriceRecorder& PriceRecorder::operator=(PriceRecorder&& other) noexcept {
    if (this != &other) {
        threads_ = std::move(other.threads_);
    }
    return *this;
}
