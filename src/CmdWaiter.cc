#include "CmdWaiter.h"

#include <string>
#include <thread>
#include <vector>

#include "Menu.h"
#include "Order.h"
#include "Updatable.h"

bool CmdWaiter::takeOrder(const std::shared_ptr<Menu> menu) {

    std::string orderedProductTicker;
    std::cout << std::endl << "Next order! What do you want? " << std::endl;
    menu->render();
    std::cout << "   (0) Time to close" << std::endl;

    std::getline(std::cin, orderedProductTicker);
    std::cout << std::endl;

    if ("0" == orderedProductTicker) {
        return true;
    }
    
    if (!menu->containsTicker(orderedProductTicker)) {
        std::cout << "Invalid order." << std::endl;
        return false;
    }
    if (!menu->hasEnoughStock(orderedProductTicker)) {
        std::cout << "Not enough stock." << std::endl;
        return false;
    }
    
    Order order(orderedProductTicker);

    // TODO: when adding concurrency, use the M&M rule ("mutable and mutex go together"): https://www.youtube.com/watch?v=oxFgclFElnM&list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L&index=101
    std::vector<std::jthread> threads;
    for (auto& product: menu->products()) {
        threads.push_back(
            std::jthread(&Product::update, &product, std::ref(order))
        );
    }

    return false;
}