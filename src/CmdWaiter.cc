#include <string>
#include <thread>
#include <vector>

#include "CmdWaiter.h"
#include "Menu.h"

bool CmdWaiter::takeOrder(std::unique_ptr<Menu>& menu) {

    std::string order;
    std::cout << std::endl << "Next order! What do you want? " << std::endl;

    for (const auto& product: menu->products()) {
        std::cout << "  (" << product.ticker() << ") " << product.name() << ": " << product.price() << " EUR" << std::endl;
    }
    std::cout << "  (0) Time to close" << std::endl;

    std::getline(std::cin, order);
    std::cout << std::endl;

    if ("0" == order) {
        return true;
    }
    
    if (!menu->containsTicker(order)) {
        std::cout << "Invalid order." << std::endl;
        return false;
    }
    Product& lastBought = menu->findbyTicker(order);

    // TODO: when adding concurrency, use the M&M rule ("mutable and mutex go together"): https://www.youtube.com/watch?v=oxFgclFElnM&list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L&index=101
    std::vector<std::jthread> threads;
    for (auto& product: menu->products()) {
        threads.push_back(
            std::jthread(&Product::updatePrice, &product, lastBought)
        );
    }

    return false;
}