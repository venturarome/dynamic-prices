#ifndef STOCK_H
#define STOCK_H

class Stock {
    public:
    Stock(int units);
    void consume(int units);
    void restock(int units);
    int units() const;

    protected:
    int units_;

};

#endif // STOCK_H