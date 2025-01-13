#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include <thread>
#include <chrono>

// https://en.cppreference.com/w/cpp/chrono/time_point/time_point
/*using DatedPrice = std::pair<std::chrono::time_point<std::chrono::steady_clock>, double>;*/

class Product {
public:
    Product(std::string name, std::string ticker, double minPrice, double basePrice, double maxPrice);
    virtual ~Product() = default;
    // TODO rule of 3/5!! Copy/move constructor/operator.

    // virtual double getPrice() const = 0;
    // std::string getName() const { return name_; }

    bool operator==(const Product& rhs) const;

    void print() const;

    std::string name() const;
    std::string ticker() const;
    double price() const;

    void updatePrice(const Product& lastBought);

protected:
    const std::string name_;

    const std::string ticker_;

    // TODO think about creating this as a functor (aka "function object", or "function with state").
    //   Or maybe use a functor to initially determine the delta! https://cplusplus.com/forum/beginner/212316/
    // TODO other option: create a class and overload the ++/-- operators.
    const double minPrice_;
    double basePrice_;
    const double maxPrice_;

    // https://en.cppreference.com/w/cpp/chrono/time_point/time_point
  /*  std::vector<DatedPrice> priceHistory_;  */
    // Alternative: cool stuff but way out of scope: https://medium.com/@angus88toms/time-series-analysis-forecasting-in-c-9c7d991850fc

    //int stockAmount;
    //std::string stockUnit;

    void increasePrice(double rate = 0.1);
    void decreasePrice(double rate = 0.1);
};

#endif // PRODUCT_H
