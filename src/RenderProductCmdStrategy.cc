#include <memory>

#include "Product.h"
#include "Renderable.h"
#include "RenderProductCmdStrategy.h"

void RenderProductCmdStrategy::render(const Renderable& object) const {
    const Product& product = dynamic_cast<const Product&>(object);
    std::cout << "(" << product.ticker() << ") " << product.name() << ": " << product.price() << " EUR" << std::endl;
}
