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

template<typename T : num>  extern T min(T a, T b);
template<typename T : num>  extern T max(T a, T b);
extern double atan2(num a, num b);
extern num pow(num exponent, num x);
extern double sin(num radians);
extern double cos(num radians);
extern double tan(num radians);
extern double acos(num x);
extern double asin(num x);
extern double atan(num x);
extern double sqrt(num x);
extern double exp(num x);
extern double log(num x);

// Parts
#include "point.hpp"
#include "random.hpp"
#include "rectangle.hpp"

#endif