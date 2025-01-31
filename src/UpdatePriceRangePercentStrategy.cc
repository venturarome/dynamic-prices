#include "UpdatePriceRangePercentStrategy.h"

#include "Order.h"
#include "Product.h"
#include "Updatable.h"

void UpdatePriceRangePercentStrategy::update(Updatable& updatable, const Order& order) const {
    Product& product = dynamic_cast<Product&>(updatable);
    product.ticker() == order.productTicker()
        ? product.increasePriceRangePercentage()
        : product.decreasePriceRangePercentage();
}
