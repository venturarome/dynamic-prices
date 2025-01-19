#include "Product.h"

Product::Product(
    std::string name,
    std::string ticker,
    Price price,
    Stock stock,
    std::shared_ptr<RenderStrategy> renderService //,
    //std::shared_ptr<UpdateStrategy> updateService
) : Renderable(renderService),
    //Updatable(updateService),
    name_(name),
    ticker_(ticker),
    price_(price),
    stock_(stock)
    /*, priceHistory_()*/ 
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

int Product::stock() const {
    return this->stock_.units();
}


// TODO use strategy pattern to allow different ways to update/decrease price!
void Product::updatePrice(const Product& lastBought) {
    //std::cout << "Updating price of " << this->name_ << " in thread " << std::this_thread::get_id() << std::endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds((int)minPrice_*1000));

    if (*this == lastBought) {
        //this->increasePrice();
        this->price_.increaseRangePercentage();
        this->stock_.consume(1);
    }
    else {
        //this->decreasePrice();
        this->price_.decreaseRangePercentage();

    }
}
