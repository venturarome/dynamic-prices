#include <iostream>
#include <thread>
#include <vector>

#include "Product.h"

void task1(std::string msg)
{
    std::cout << "task1 says: " << msg;
}

int main () {
    // std::cout << "Hello, Google IDX!" << std::endl;
        
    // std::thread t1(task1, "Hello");
    // t1.join();

    // return 0;

    std::vector<std::vector<std::string>> rawProducts {
        {"Estrella Galicia (bottle 330 ml)", "2.00", "3.00", "5.00"},
        {"Guinness (pint)", "5.00", "6.70", "9.00"},
        {"Punk IPA (can 330ml)", "3.50", "4.90", "7.50"},
        {"Paulaner (bottle 500 ml)", "3.90", "5.20", "7.70"},
    };
    
    //std::vector<int> producddts(3);   // duda: ¿por qué esta línea sí funciona, pero la siguiente no?
    //std::vector<Product> products(3);
    std::vector<Product> products;
    products.reserve(rawProducts.size());
    for (auto& rawProduct: rawProducts) {
        Product p(rawProduct[0], std::stod(rawProduct[1]), std::stod(rawProduct[2]), std::stod(rawProduct[3]));
        products.push_back(p);
        p.print();
    }
    
    std::cout << std::endl;
    
    // TODO: when adding concurrency, use the M&M rule ("mutable and mutex go together"): https://www.youtube.com/watch?v=oxFgclFElnM&list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L&index=101
    Product& lastPurchasedProduct = std::ref(products.at(2));
    std::vector<std::thread> threads;
    for (auto& product: products) {
        //product.updatePrice(lastPurchasedProduct);
        threads.push_back(
            std::thread(&Product::updatePrice, &product, lastPurchasedProduct)
        );
    }

    for (auto& thread: threads) {
        thread.join();
    }

    
    std::cout << std::endl;
    
    for (auto& product: products) {
        product.print();
    }
    
    return 0;
    
    
    bool closeTime = false;
    int numOrders = 0;
    while (!closeTime) {
        std::string beerOrder;
        std::cout << "Next order! What do you want? " << std::endl
            << "  (1) Estrella Galicia" << std::endl
            << "  (2) Mahou" << std::endl
            << "  (3) Guiness" << std::endl
            << "  (0) Time to close" << std::endl;
        std::getline(std::cin, beerOrder);
        
        if (0 == std::stoi(beerOrder)) {
            closeTime = true;
            std::cout << "Time to close" << std::endl;
        }
        else {
            numOrders++;
            std::cout << "You ordered " << numOrders << " times" << std::endl;
        }
    }
        
    return 0;
}