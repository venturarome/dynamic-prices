#ifndef PRODUCT_H
#define PRODUCT_H

#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include "Price.h"
#include "Renderable.h"
#include "RenderStrategy.h"
#include "Stock.h"
#include "Updatable.h"
#include "UpdateStrategy.h"

class Product: public Renderable, public Updatable {
public:
    Product(
      std::string name,
      std::string ticker,
      Price price,
      Stock stock,
      std::shared_ptr<RenderStrategy> renderService = nullptr,
      std::shared_ptr<UpdateStrategy> updateService = nullptr
    );
    virtual ~Product() = default;
    // TODO rule of 3/5!! Copy/move constructor/operator.

    bool operator==(const Product& rhs) const;

    std::string name() const;
    std::string ticker() const;

    double price() const;

    bool hasEnoughStock(int units) const;
    int stock() const;
    void updateStock(int units);

protected:
    const std::string name_;

    // TODO create rules for "tickers".
    //  ie. <ABBREVIATION OF NAME>.<CONTAINER(B:bottle|C:can|D:draught|...)>.<QUANTITY(330:330ml|P:pint|HP:half pint|...)>
    // CONTAINER may apply only to Beverage. We may have SIZE (S, M, L, XL) for both Beverage and Meal.
    // ==> Use of enums.

    const std::string ticker_;

    Price price_;
    Stock stock_;
};

#endif // PRODUCT_H
