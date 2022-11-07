#ifndef MATH_H
#define MATH_H
#include <memory>

#include <internal/internal.hpp>

// Parts
#include "point.hpp"
#include "random.hpp"
#include "rectangle.hpp"

const double e;

const double ln10;

const double ln2;

const double log2e;

const double log10e;

const double pi;

const double sqrt1_2;

const double sqrt2;

external T min<T extends num>(T a, T b);

external T max<T extends num>(T a, T b);

external double atan2(num a, num b);

external num pow(num exponent, num x);

external double sin(num radians);

external double cos(num radians);

external double tan(num radians);

external double acos(num x);

external double asin(num x);

external double atan(num x);

external double sqrt(num x);

external double exp(num x);

external double log(num x);


#endif