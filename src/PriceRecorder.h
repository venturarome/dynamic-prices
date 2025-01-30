#ifndef PRICERECORDER_H
#define PRICERECORDER_H

#include <semaphore>
#include <thread>
#include <vector>

#include "Menu.h"

class PriceRecorder {
    public:
    PriceRecorder(std::shared_ptr<Menu> menu);
    ~PriceRecorder();

    // Copy semantics - copy constructor and copy assignment operator are disabled
    PriceRecorder(const PriceRecorder&) = delete;
    PriceRecorder& operator=(const PriceRecorder&) = delete;

    // Move semantics - move constructor and move assignment operator are disabled
    PriceRecorder(PriceRecorder&& other) = delete;
    PriceRecorder& operator=(PriceRecorder&& other) = delete;

    private:
    std::jthread coordinator_;
    std::vector<std::jthread> workers_;

    long int timestamp_;
    std::binary_semaphore pendingWork_;

    // std::mutex timestampMutex_;
    // std::condition_variable timestampCondition_;
    // /*std::chrono::seconds*/ long int timestamp_;
    // bool timestampUpdated_;
    // int timestampAccesses_;
};

#endif // PRICERECORDER_H
