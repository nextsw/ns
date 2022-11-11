#include "utils.hpp"
int defaultCompare(Object value1, Object value2) {
    return (as<Comparable<Object>>(value1))->compareTo(value2);
}

template<typename T>
T identity(T value) {
    return value;
}

template<typename T>
int compareComparable(T a, T b) {
    return a->compareTo(b);
}
