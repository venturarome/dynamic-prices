#include <iostream>
#include <thread>
#include <vector>
#include <map>
#include <memory>

#include "CmdWaiter.h"
#include "CsvReader.h"
#include "Menu.h"
#include "Product.h"
#include "RenderMenuCmdStrategy.h"
#include "RenderProductCmdStrategy.h"
#include "Renderer.h"

int main () {
    auto reader = std::make_unique<CsvReader>();
    std::vector<std::map<std::string, std::string>> rawProducts = reader->read("./data/beers.csv");
    
    auto renderer = std::make_unique<Renderer>();

    auto renderMenuService = std::make_shared<RenderMenuCmdStrategy>();
    auto menu = std::make_shared<Menu>("Beers", renderMenuService);
    
    auto renderProductService = std::make_shared<RenderProductCmdStrategy>();
    for (auto& rawProduct: rawProducts) {
        //auto product = std::make_unique<Product>(
        Product product(
            rawProduct["name"],
            rawProduct["ticker"],
            std::stod(rawProduct["minPrice"]),
            std::stod(rawProduct["basePrice"]),
            std::stod(rawProduct["maxPrice"]),
            renderProductService
        );
        menu->addProduct(std::move(product));
    }

    renderer->render(menu);

    auto waiter = std::make_shared<CmdWaiter>();
    bool closeTime = false;
    while (!closeTime) {
        closeTime = waiter->takeOrder(menu);
    }
    std::cout << "Time to close" << std::endl;
    
    return 0;
}