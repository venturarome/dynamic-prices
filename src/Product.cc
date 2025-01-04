#include "Product.h"

Product::Product(const std::string& name, double minPrice, double basePrice, double maxPrice) :
    name_(name), minPrice_(minPrice), basePrice_(basePrice), maxPrice_(maxPrice) {}

bool Product::operator==(const Product& rhs) const {
    return this->name_ == rhs.name_;
}

void Product::print() const {
    std::cout << this->name_ 
                << " [" << this->minPrice_ << ", " << this->basePrice_ << ", " << this->maxPrice_ << "]" 
                << std::endl;
}

void Product::updatePrice(const Product& lastBought) {
    //std::cout << "Updating price of " << this->name_ << " in thread " << std::this_thread::get_id() << std::endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds((int)minPrice_*1000));

    if (*this == lastBought) {
        this->increasePrice();
    }
    else {
        this->decreasePrice();
    }
}

void Product::increasePrice(double rate) {
    std::cout << "Increasing Price of " << this->name_ << std::endl; 
    double delta = (this->maxPrice_ - this->minPrice_) * rate;
    this->basePrice_ = std::min(this->basePrice_ + delta, this->maxPrice_);
}
void Product::decreasePrice(double rate) {
    std::cout << "Decreasing Price of " << this->name_ << std::endl; 
    double delta = (this->maxPrice_ - this->minPrice_) * rate;
    this->basePrice_ = std::max(this->basePrice_ - delta, this->minPrice_);
}
