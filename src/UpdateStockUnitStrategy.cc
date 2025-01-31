#include "UpdateStockUnitStrategy.h"

#include <memory>
#include <format>

#include "Order.h"
#include "Product.h"
#include "Updatable.h"

void UpdateStockUnitStrategy::update(Updatable& updatable, const Order& order) const {
    Product& product = dynamic_cast<Product&>(updatable);
    if (product.ticker() == order.productTicker()) {
        product.updateStock(-1);
    }
}
