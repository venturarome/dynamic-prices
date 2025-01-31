#ifndef UPDATEPRICERANGESTRATEGY_H
#define UPDATEPRICERANGESTRATEGY_H

#include "Order.h"
#include "UpdateStrategy.h"

class UpdatePriceRangePercentStrategy: public UpdateStrategy {
    public:
    void update(Updatable& updatable, const Order& order) const override;
};

#endif // UPDATEPRICERANGESTRATEGY_H