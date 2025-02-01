#ifndef UPDATEPRICEWHENSTOCKOUTOFLIMITSSTRATEGY_H
#define UPDATEPRICEWHENSTOCKOUTOFLIMITSSTRATEGY_H

#include "Order.h"
#include "UpdateStrategy.h"

class UpdatePriceWhenStockOutOfLimitsStrategy: public UpdateStrategy {
    public:
    UpdatePriceWhenStockOutOfLimitsStrategy(int minStock = 5, int maxStock = 15);
    void update(Updatable& updatable, const Order& order) const override;

    protected:
    int minStock_;
    int maxStock_;
};

#endif // UPDATEPRICEWHENSTOCKOUTOFLIMITSSTRATEGY_H