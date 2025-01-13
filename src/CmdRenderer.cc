#include <memory>

#include "CmdRenderer.h"
#include "Menu.h"

void CmdRenderer::render(const std::unique_ptr<Menu>& menu) {
    for (auto& product: menu->products()) {
        product.print();
    }
}