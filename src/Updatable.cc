#include "Updatable.h"

#include <memory>

#include "Order.h"
#include "UpdateStrategy.h"

Updatable::Updatable(std::shared_ptr<UpdateStrategy> updateService) : updateService_(updateService) {}

void Updatable::update(const Order& order) {
    updateService_->update(*this, order);
}
