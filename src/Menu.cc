#include "Menu.h"

#include <vector>
#include <memory>
#include <stdexcept>

#include "RenderStrategy.h"

Menu::Menu(std::string name, std::shared_ptr<RenderStrategy>renderService = nullptr)
    : Renderable(renderService), products_(), name_(name) {}

void Menu::addProduct(Product&& product) {
    products_.push_back(product);
}

bool Menu::containsTicker(std::string ticker) {
    for (auto& product: products_) {
        if (product.ticker() == ticker) {
            return true;
        }
    }
    return false;
}

Product& Menu::findByTicker(std::string ticker) {
    for (auto& product: products_) {
        if (product.ticker() == ticker) {
            return product;
        }
    }
    throw std::invalid_argument("Product with supplied ticker does not exist");
}

bool Menu::hasEnoughStock(std::string ticker) {
    return this->findByTicker(ticker).stock() > 0;
}

std::string Menu::name() const {
    return name_;
}

std::vector<Product>& Menu::products() {
    return products_;
}

const std::vector<Product>& Menu::products() const {
    return products_;
}
