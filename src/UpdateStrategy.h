#ifndef UPDATESTRATEGY_H
#define UPDATESTRATEGY_H

#include "Order.h"

class Updatable;

class UpdateStrategy {
    public:
    virtual void update(Updatable& updatable, const Order& order) const = 0;
    virtual ~UpdateStrategy() = default;
};

#endif // UPDATESTRATEGY_H