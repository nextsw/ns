#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_UTILITIES
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_UTILITIES
#include <base.hpp>

#include <dart/core/core.hpp>

double degrees(double radians);

double radians(double degrees);

double mix(double a, double max, double min);

double smoothStep(double amount, double edge0, double edge1);

double catmullRom(double amount, double edge0, double edge1, double edge2, double edge3);



#endif