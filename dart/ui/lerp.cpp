#include "lerp.hpp"
double lerpDouble(num a, num b, double t) {
    if (a == b || (a?->isNaN() == true) && (b?->isNaN() == true))     {
        return a?->toDouble();
    }
    a = 0.0;
    b = 0.0;
    assert(a->isFinite(), __s("Cannot interpolate between finite and non-finite values"));
    assert(b->isFinite(), __s("Cannot interpolate between finite and non-finite values"));
    assert(t->isFinite, __s("t must be finite when interpolating between values"));
    return a * (1.0 - t) + b * t;
}

double _lerpDouble(double a, double b, double t) {
    return a * (1.0 - t) + b * t;
}

double _lerpInt(int a, int b, double t) {
    return a + (b - a) * t;
}

int _clampInt(int max, int min, int value) {
    assert(min <= max);
    if ( < min) {
        return min;
    } else     {
        if (value > max) {
        return max;
    } else {
        return value;
    }
;
    }}
