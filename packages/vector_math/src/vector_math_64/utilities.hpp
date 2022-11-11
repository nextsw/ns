#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_UTILITIES
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_UTILITIES
#include <base.hpp>

#include <dart/core/core.hpp>

double degrees(double radians);

double radians(double degrees);

double mix(double min, double max, double a);

double smoothStep(double edge0, double edge1, double amount);

double catmullRom(double edge0, double edge1, double edge2, double edge3, double amount);



#endif