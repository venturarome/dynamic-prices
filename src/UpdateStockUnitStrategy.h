#ifndef UPDATESTOCKUNITSTRATEGY_H
#define UPDATESTOCKUNITSTRATEGY_H

#include "Order.h"
#include "UpdateStrategy.h"

class UpdateStockUnitStrategy: public UpdateStrategy {
    public:
    void update(Updatable& updatable, const Order& order) const override;
};

#endif // UPDATESTOCKUNITSTRATEGY_H