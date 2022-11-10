#ifndef DART_MATH_MATH
#define DART_MATH_MATH
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/internal/internal.hpp>

double e;

double ln10;

double ln2;

double log2e;

double log10e;

double pi;

double sqrt1_2;

double sqrt2;

template<typename T>  T min(T a, T b);
template<typename T>  T max(T a, T b);
double atan2(num a, num b);
num pow(num exponent, num x);
double sin(num radians);
double cos(num radians);
double tan(num radians);
double acos(num x);
double asin(num x);
double atan(num x);
double sqrt(num x);
double exp(num x);
double log(num x);

// Parts
#include "point.hpp"
#include "random.hpp"
#include "rectangle.hpp"

#endif