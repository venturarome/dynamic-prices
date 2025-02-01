#include "UpdatePriceWhenStockOutOfLimitsStrategy.h"

#include "Order.h"
#include "Product.h"
#include "Updatable.h"

UpdatePriceWhenStockOutOfLimitsStrategy::UpdatePriceWhenStockOutOfLimitsStrategy(
    int minStock, int maxStock
): minStock_(minStock), maxStock_(maxStock) {}

void UpdatePriceWhenStockOutOfLimitsStrategy::update(Updatable& updatable, const Order& order) const {
    Product& product = dynamic_cast<Product&>(updatable);

    if (!product.tickerIs(order.productTicker())) {
        return;
    }

    product.updateStock(-1);

    if (product.stock() < this->minStock_) {
        product.toMaxPrice();
    }
    else if (product.stock() > this->maxStock_) {
        product.toMinPrice();
    }
    else {
        product.toBasePrice();
    }
}
