#ifndef UPDATESTOCKONLYSTRATEGY_H
#define UPDATESTOCKONLYSTRATEGY_H

#include "Order.h"
#include "UpdateStrategy.h"

class UpdateStockOnlyStrategy: public UpdateStrategy {
    public:
    void update(Updatable& updatable, const Order& order) const override;
};

#endif // UPDATESTOCKONLYSTRATEGY_H