#ifndef UPDATABLE_H
#define UPDATABLE_H

#include <memory>

#include "Order.h"
#include "UpdateStrategy.h"

class Updatable {
    public:
    Updatable(std::shared_ptr<UpdateStrategy> updateService);
    virtual ~Updatable() = default;
    void update(const Order& order);

    protected:
    std::shared_ptr<UpdateStrategy> updateService_;
};

#endif // UPDATABLE_H