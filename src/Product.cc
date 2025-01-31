#include "Product.h"

Product::Product(
    std::string name,
    std::string ticker,
    Price price,
    Stock stock,
    std::shared_ptr<RenderStrategy> renderService,
    std::shared_ptr<UpdateStrategy> updateService
) : Renderable(renderService),
    Updatable(updateService),
    name_(name),
    ticker_(ticker),
    price_(price),
    stock_(stock)
{}

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
    return this->price_.base();
}

bool Product::hasEnoughStock(int units) const {
    return this->stock_.units() >= units;
}

int Product::stock() const {
    return this->stock_.units();
}

void Product::updateStock(int units) {
    units > 0 ? this->stock_.restock(units) : this->stock_.consume(-units);
}
