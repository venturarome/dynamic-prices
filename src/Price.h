#ifndef PRICE_H
#define PRICE_H

class Price {
    public:
    Price(double base);
    Price(double base, double min, double max);

    double base() const;
    double min() const;
    double max() const;

    void increaseRangePercentage(double rate = 0.1);
    void decreaseRangePercentage(double rate = 0.1);

    protected:
    double base_;
    double min_;
    double max_;

};

#endif // PRICE_H