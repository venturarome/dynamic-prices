#ifndef MENU_H
#define MENU_H

#include <vector>
#include <memory>

#include "Product.h"
#include "Renderable.h"

class Menu: public Renderable {
    public:
    Menu(std::string name, std::shared_ptr<RenderStrategy>renderService);

    void addProduct(Product&& product);

    bool containsTicker(std::string ticker);

    Product& findByTicker(std::string ticker);

    bool hasEnoughStock(std::string ticker);

    std::string name() const;

    std::vector<Product>& products();

    const std::vector<Product>& products() const;

    private:
    // TODO: maybe it's more efficient to have a vector of smart pointers to products, or a different container (ie. unordered_set, unordered_map, ...).
    std::vector<Product> products_;
    const std::string name_;
};

#endif // MENU_H