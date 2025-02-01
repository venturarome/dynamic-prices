#include <algorithm>
#include <limits>

#include "Price.h"

Price::Price(double base)
    : base_(base), min_(0.), max_(std::numeric_limits<double>::max()), current_(base) {};

Price::Price(double base, double min, double max)
    : base_(base), min_(min), max_(max), current_(base) {};

double Price::base() const {
    return this->base_;
}
double Price::min() const {
    return this->min_;
}
double Price::max() const {
    return this->max_;
}
double Price::current() const {
    return this->current_;
}

void Price::increaseRangePercentage(double rate) {
    double delta = (this->max_ - this->min_) * rate;
    this->current_ = std::min(this->current_ + delta, this->max_);
}

void Price::decreaseRangePercentage(double rate) {
    double delta = (this->max_ - this->min_) * rate;
    this->current_ = std::max(this->current_ - delta, this->min_);
}

void Price::toMin() {
    this->current_ = this->min_;
}

void Price::toBase() {
    this->current_ = this->base_;
}

void Price::toMax() {
    this->current_ = this->max_;
}