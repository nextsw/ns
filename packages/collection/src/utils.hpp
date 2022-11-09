#ifndef PACKAGES_COLLECTION_SRC_UTILS
#define PACKAGES_COLLECTION_SRC_UTILS
#include <base.hpp>

#include <dart/core/core.hpp>

int defaultCompare(Object value1, Object value2);

template<typename T>  T identity(T value);

template<typename T : Comparable<T>>  int compareComparable(T a, T b);



#endif