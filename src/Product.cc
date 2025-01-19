#include "Product.h"

Product::Product(std::string name, std::string ticker, double minPrice, double basePrice, double maxPrice, std::shared_ptr<RenderStrategy>renderService)
    : Renderable(renderService), name_(name), ticker_(ticker), minPrice_(minPrice), basePrice_(basePrice), maxPrice_(maxPrice)/*, priceHistory_()*/ {}

bool Product::operator==(const Product& rhs) const {
    return this->name_ == rhs.name_;
}

std::string Product::name() const {
    return this->name_;
}

std::string Product::ticker() const {
    return this->ticker_;
}

double Product::price() const {
    return this->basePrice_;
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

// TODO use strategy pattern to allow different ways to update/decrease price!
void Product::increasePrice(double rate) {
    //std::cout << "Increasing Price of " << this->name_ << std::endl; 
    double delta = (this->maxPrice_ - this->minPrice_) * rate;
    this->basePrice_ = std::min(this->basePrice_ + delta, this->maxPrice_);
}
void Product::decreasePrice(double rate) {
    //std::cout << "Decreasing Price of " << this->name_ << std::endl; 
    double delta = (this->maxPrice_ - this->minPrice_) * rate;
    this->basePrice_ = std::max(this->basePrice_ - delta, this->minPrice_);
}
