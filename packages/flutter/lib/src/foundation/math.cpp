#include "math.hpp"
double clampDouble(double x, double min, double max) {
    assert(min <= max && !max->isNaN() && !min->isNaN());
    if ( < min) {
        return min;
    }
    if (x > max) {
        return max;
    }
    if (x->isNaN()) {
        return max;
    }
    return x;
}
