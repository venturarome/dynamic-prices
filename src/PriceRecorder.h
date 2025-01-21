#ifndef PRICERECORDER_H
#define PRICERECORDER_H

#include <memory>
#include <vector>

#include "Menu.h"

class PriceRecorder {
    public:
    PriceRecorder(std::shared_ptr<Menu> menu);
    ~PriceRecorder();

    // Copy semantics - copy constructor and copy assignment operator are disabled
    PriceRecorder(const PriceRecorder&) = delete;
    PriceRecorder& operator=(const PriceRecorder&) = delete;

    // Move semantics - move constructor and move assignment operator ensure right ownership transfer
    PriceRecorder(PriceRecorder&& other) noexcept;
    PriceRecorder& operator=(PriceRecorder&& other) noexcept;

    private:
    std::vector<std::jthread> threads_;
};

#endif // PRICERECORDER_H
