#ifndef WAITER_H
#define WAITER_H

#include <memory>

#include "Menu.h"

class Waiter {
    public:
    virtual bool takeOrder(const std::shared_ptr<Menu> menu) = 0;
};

#endif // WAITER_H