#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include <thread>
#include <chrono>

class Product {
public:
    Product(const std::string& name, double minPrice, double basePrice, double maxPrice) : 
        name_(name), minPrice_(minPrice), basePrice_(basePrice), maxPrice_(maxPrice) {}
    virtual ~Product() = default;
    // TODO rule of 3/5!! Copy/move constructor/operator.

    // virtual double getPrice() const = 0;
    // std::string getName() const { return name_; }

    void print() const {
        std::cout << this->name_ << " [" << this->minPrice_ << ", " << this->basePrice_ << ", " << this->maxPrice_ << "]" << std::endl;
    }
    bool operator==(const Product& rhs) const {
        return this->name_ == rhs.name_;
    }
    void updatePrice(const Product& lastBought) {
        //std::cout << "Updating price of " << this->name_ << " in thread " << std::this_thread::get_id() << std::endl;
        //std::this_thread::sleep_for(std::chrono::milliseconds((int)minPrice_*1000));

        if (*this == lastBought) {
            this->increasePrice();
        }
        else {
            this->decreasePrice();
        }
    }

protected:
    std::string name_;

    // TODO think about creating this as a functor (aka "function object", or "function with state").
    //   Or maybe use a functor to initially determine the delta! https://cplusplus.com/forum/beginner/212316/
    // TODO other option: create a class and overload the ++/-- operators.
    const double minPrice_;
    double basePrice_;
    const double maxPrice_;

    //int stockAmount;
    //std::string stockUnit;

    void increasePrice(double rate = 0.1) {
        std::cout << "Increasing Price of " << this->name_ << std::endl; 
        double delta = (this->maxPrice_ - this->minPrice_) * rate;
        this->basePrice_ = std::min(this->basePrice_ + delta, this->maxPrice_);
    }
    void decreasePrice(double rate = 0.1) {
        std::cout << "Decreasing Price of " << this->name_ << std::endl; 
        double delta = (this->maxPrice_ - this->minPrice_) * rate;
        this->basePrice_ = std::max(this->basePrice_ - delta, this->minPrice_);
    }
};

#endif
