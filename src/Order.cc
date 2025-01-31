#include "Order.h"

Order::Order(std::string productTicker) : productTicker_(productTicker) {};

std::string Order::productTicker() const {
    return this->productTicker_;
}
