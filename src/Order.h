#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order
{
    public:
    Order(std::string productTicker);
    ~Order() = default;

    std::string productTicker() const;

    private:
    // TODO change this for a list of tickers to allow multiple products per order.
    std::string productTicker_;
};

#endif // ORDER_H