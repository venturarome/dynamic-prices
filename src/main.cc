#include <iostream>
#include <thread>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include <string>

#include "ArgsParser.h"
#include "CmdWaiter.h"
#include "CsvReader.h"
#include "Menu.h"
#include "Price.h"
#include "PriceRecorder.h"
#include "Product.h"
#include "Renderer.h"
#include "RenderMenuCmdStrategy.h"
#include "RenderProductCmdStrategy.h"
#include "Stock.h"
#include "UpdateStockUnitStrategy.h"

int main (int argc, char* argv[]) {

    std::unordered_map<std::string, std::string> args = ArgsParser::parse(argc, argv);

    auto reader = std::make_unique<CsvReader>();
    std::vector<std::map<std::string, std::string>> rawProducts = reader->read("./data/beers.csv");
    
    auto renderer = std::make_unique<Renderer>();

    std::shared_ptr<RenderStrategy> renderMenuService;
    std::shared_ptr<RenderStrategy> renderProductService;
    if (args.contains("ui") && args["ui"] == "gui") {
        // WIP
        //auto renderMenuService = std::make_shared<RenderMenuGuiStrategy>();
        //auto renderProductService = std::make_shared<RenderProductGuiStrategy>();
        // For the time being:
        renderMenuService = std::make_shared<RenderMenuCmdStrategy>();
        renderProductService = std::make_shared<RenderProductCmdStrategy>();
    }
    else { // (args["ui"] == "cmd")
        renderMenuService = std::make_shared<RenderMenuCmdStrategy>();
        renderProductService = std::make_shared<RenderProductCmdStrategy>();
    }

    std::shared_ptr<UpdateStrategy> updateProductService = std::make_shared<UpdateStockUnitStrategy>();; 

    auto menu = std::make_shared<Menu>("Beers", renderMenuService);
    for (auto& rawProduct: rawProducts) {
        //auto product = std::make_unique<Product>(
        Product product(
            rawProduct["name"],
            rawProduct["ticker"],
            Price(
                std::stod(rawProduct["basePrice"]),
                std::stod(rawProduct["minPrice"]),
                std::stod(rawProduct["maxPrice"])
            ),
            Stock(std::stoi(rawProduct["stock"])),
            renderProductService,
            updateProductService
        );
        menu->addProduct(std::move(product));
    }

    auto priceRecorder = std::make_unique<PriceRecorder>(menu);

    renderer->render(menu);

    auto waiter = std::make_shared<CmdWaiter>();
    bool closeTime = false;
    while (!closeTime) {
        closeTime = waiter->takeOrder(menu);
    }
    std::cout << "Time to close" << std::endl;
    
    return 0;
}