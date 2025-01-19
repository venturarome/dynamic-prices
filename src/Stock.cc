#include "Stock.h"

Stock::Stock(int units) : units_(units) {};

void Stock::consume(int units) {
    units_ -= units;
}
    
void Stock::restock(int units) {
    units_ += units;
}

int Stock::units() const {
    return units_;
}
