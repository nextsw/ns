#ifndef PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_ERROR_HELPERS
#define PACKAGES_VECTOR_MATH_SRC_VECTOR_MATH_64_ERROR_HELPERS
#include <base.hpp>

#include <dart/core/core.hpp>

double relativeError(Object calculated, Object correct);

double absoluteError(Object calculated, Object correct);



#endif