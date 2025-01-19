#include <memory>
#include <format>

#include "Product.h"
#include "Renderable.h"
#include "RenderProductCmdStrategy.h"

void RenderProductCmdStrategy::render(const Renderable& object) const {
    const Product& product = dynamic_cast<const Product&>(object);
    std::cout << std::format("({}) {}: {} EUR, {} units", product.ticker(), product.name(), product.price(), product.stock()) << std::endl;
}
