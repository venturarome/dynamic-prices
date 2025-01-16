#ifndef MENU_H
#define MENU_H

#include <vector>
#include <memory>
#include <optional>
#include <stdexcept>

#include "Product.h"
#include "Renderable.h"

class Menu: public Renderable {
    public:
    Menu(std::string name, std::shared_ptr<RenderStrategy>renderService = nullptr)
        : Renderable(renderService), products_(), name_(name) {}

    void addProduct(Product&& product) {
        products_.push_back(product);
    }

    bool containsTicker(std::string ticker) {
        for (auto& product: products_) {
            if (product.ticker() == ticker) {
                return true;
            }
        }
        return false;
    }

    Product& findbyTicker(std::string ticker) {
        for (auto& product: products_) {
            if (product.ticker() == ticker) {
                return product;
            }
        }
        throw std::invalid_argument("Product with supplied ticker does not exist");
    }

    std::string name() const {
        return name_;
    }

    std::vector<Product>& products() {
        return products_;
    }

    const std::vector<Product>& products() const {
        return products_;
    }

    private:
    // TODO: maybe it's more efficient to have a vector of smart pointers to products, or a different container (ie. unordered_set, unordered_map, ...).
    std::vector<Product> products_;
    const std::string name_;
};

#endif // MENU_H