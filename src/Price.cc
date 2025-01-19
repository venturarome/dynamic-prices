#include <algorithm>
#include <limits>

#include "Price.h"

Price::Price(double base)
    : base_(base), min_(0.), max_(std::numeric_limits<double>::max()) {};

Price::Price(double base, double min, double max)
    : base_(base), min_(min), max_(max) {};

double Price::base() const {
    return this->base_;
}
double Price::min() const {
    return this->min_;
}
double Price::max() const {
    return this->max_;
}

void Price::increaseRangePercentage(double rate) {
    double delta = (this->max_ - this->min_) * rate;
    this->base_ = std::min(this->base_ + delta, this->max_);
}

void Price::decreaseRangePercentage(double rate) {
    double delta = (this->max_ - this->min_) * rate;
    this->base_ = std::max(this->base_ - delta, this->min_);
}