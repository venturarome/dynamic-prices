#include <iostream>
#include <thread>
#include <vector>
#include <memory>

#include "Menu.h"
#include "Product.h"
#include "CmdRenderer.h"
#include "CmdWaiter.h"

int main () {

    // TODO consider using a different container (ie. unordered_set, unordered_map, ...).
    std::vector<std::vector<std::string>> rawProducts {
        {"Estrella Galicia, bottle 330 ml", "EGA.B.330", "2.00", "3.00", "5.00"},
        {"Guinness, pint", "GUI.D.P", "5.00", "6.70", "9.00"},
        {"Punk IPA, can, 330ml", "PK.C.330", "3.50", "4.90", "7.50"},
        {"Paulaner, bottle, 500 ml", "PAU.B.500", "3.90", "5.20", "7.70"},
    };
    

    // TODO create rules for "tickers".
    //  ie. <ABBREVIATION OF NAME>.<CONTAINER(B:bottle|C:can|D:draught|...)>.<QUANTITY(330:330ml|P:pint|HP:half pint|...)>
    //
    // A "generic product" with its own ticker will be already created.
    // On the creation of each menu, the owner will select which products to add,
    // or alternatively it can create new (private) products.

    auto menu = std::make_unique<Menu>("Beers");
    for (auto& rawProduct: rawProducts) {
        //auto product = std::make_unique<Product>(
        Product product = Product(
            rawProduct[0], 
            rawProduct[1],
            std::stod(rawProduct[2]), 
            std::stod(rawProduct[3]), 
            std::stod(rawProduct[4])
        );
        menu->addProduct(std::move(product));
    }

// todo: create MenuCmdRenderer, as we can render other things apart from a menu.
    auto renderer = std::make_unique<CmdRenderer>();
    renderer->render(menu);
    std::cout << std::string(15, '=') << std::endl;

    auto waiter = std::make_unique<CmdWaiter>();
    bool closeTime = false;
    while (!closeTime) {
        closeTime = waiter->takeOrder(menu);
        renderer->render(menu);
    }
    std::cout << "Time to close" << std::endl;
    
    return 0;
}