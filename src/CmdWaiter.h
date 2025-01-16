#ifndef CMDWAITER_H
#define CMDWAITER_H

#include <string>
#include <thread>
#include <vector>

#include "Menu.h"
#include "Waiter.h"

class CmdWaiter: public Waiter {
    public:
    bool takeOrder(const std::shared_ptr<Menu> menu) override;
};

#endif // CMDWAITER_H