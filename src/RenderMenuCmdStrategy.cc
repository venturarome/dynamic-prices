#include <format>
#include <iostream>
#include <memory>

#include "Menu.h"
#include "Renderable.h"
#include "RenderMenuCmdStrategy.h"

void RenderMenuCmdStrategy::render(const Renderable& object) const {

    const Menu& menu = dynamic_cast<const Menu&>(object);

    std::cout << std::string(15, '=') << std::endl;
    std::cout << std::format("Menu: '{}'", menu.name()) << std::endl;
    for (const auto& product: menu.products()) {
        std::cout << "   ";
        product.render();
    }
    std::cout << std::string(15, '=') << std::endl;
}