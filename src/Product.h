#ifndef PRODUCT_H
#define PRODUCT_H

#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include "Renderable.h"
#include "RenderStrategy.h"

// https://en.cppreference.com/w/cpp/chrono/time_point/time_point
/*using DatedPrice = std::pair<std::chrono::time_point<std::chrono::steady_clock>, double>;*/

class Product: public Renderable {
public:
    Product(std::string name, std::string ticker, double minPrice, double basePrice, double maxPrice, std::shared_ptr<RenderStrategy>renderService = nullptr);
    virtual ~Product() = default;
    // TODO rule of 3/5!! Copy/move constructor/operator.

    bool operator==(const Product& rhs) const;

    std::string name() const;
    std::string ticker() const;
    double price() const;

    void updatePrice(const Product& lastBought);

protected:
    const std::string name_;

    // TODO create rules for "tickers".
    //  ie. <ABBREVIATION OF NAME>.<CONTAINER(B:bottle|C:can|D:draught|...)>.<QUANTITY(330:330ml|P:pint|HP:half pint|...)>
    // CONTAINER may apply only to Beverage. We may have SIZE (S, M, L, XL) for both Beverage and Meal.
    // ==> Use of enums.

    // Idea: A "generic product" with its own ticker will be already created.
    // On the creation of each menu, the owner will select which products to add,
    // or alternatively it can create new (private) products.
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
