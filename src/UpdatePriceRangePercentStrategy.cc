#include "UpdatePriceRangePercentStrategy.h"

#include "Order.h"
#include "Product.h"
#include "Updatable.h"

UpdatePriceRangePercentStrategy::UpdatePriceRangePercentStrategy(
    float percentUp, float percentDown
): percentUp_(percentUp), percentDown_(percentDown) {}

void UpdatePriceRangePercentStrategy::update(Updatable& updatable, const Order& order) const {
    Product& product = dynamic_cast<Product&>(updatable);
    if (product.tickerIs(order.productTicker())) {
        product.updateStock(-1);
        product.increasePriceRangePercentage(this->percentUp_);
    }
    else {
        product.decreasePriceRangePercentage(this->percentDown_);
    }
}
