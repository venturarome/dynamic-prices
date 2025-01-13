#ifndef MENU_H
#define MENU_H

#include <vector>
#include <memory>
#include <optional>
#include <stdexcept>

#include "Product.h"
#include "Renderer.h"

class Menu {
    public:
    Menu(std::string name): products_(), name_(name) {}

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

    void printProducts() const {
        for (auto& product: products_) {
            product.print();
        }
    }

    std::vector<Product>& products() {
        return products_;
    }

    private:
    std::vector<Product> products_;  // TODO: maybe it's more efficient to have a vector of smart pointers to products, or a map.
    const std::string name_;
};

#endif // MENU_H