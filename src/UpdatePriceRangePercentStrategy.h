#ifndef UPDATEPRICERANGEPERCENTSTRATEGY_H
#define UPDATEPRICERANGEPERCENTSTRATEGY_H

#include "Order.h"
#include "UpdateStrategy.h"

class UpdatePriceRangePercentStrategy: public UpdateStrategy {
    public:
    UpdatePriceRangePercentStrategy(float percentUp = 0.1, float percentDown = 0.025);
    void update(Updatable& updatable, const Order& order) const override;

    protected:
    float percentUp_;
    float percentDown_;
};

#endif // UPDATEPRICERANGEPERCENTSTRATEGY_H