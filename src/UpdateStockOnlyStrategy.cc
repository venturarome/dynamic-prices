#include "UpdateStockOnlyStrategy.h"

#include "Order.h"
#include "Product.h"
#include "Updatable.h"

void UpdateStockOnlyStrategy::update(Updatable& updatable, const Order& order) const {
    Product& product = dynamic_cast<Product&>(updatable);
    if (product.tickerIs(order.productTicker())) {
        product.updateStock(-1);
    }
}
