#ifndef WAITER_H
#define WAITER_H

#include <memory>

#include "Menu.h"

class Waiter {
    public:
    virtual bool takeOrder(std::unique_ptr<Menu>& menu) = 0;
};

#endif // WAITER_H