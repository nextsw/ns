#include "utils.hpp"
int defaultCompare(Object value1, Object value2) {
    return (as<Comparable<Object>>(value1))->compareTo(value2);
}

T identitytemplate<typename T> (T value) {
    return value;
}

int compareComparabletemplate<typename T> (T a, T b) {
    return a->compareTo(b);
}
