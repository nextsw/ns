#include "utils.hpp"
int defaultCompare(Object value1, Object value2) {
    return (().compareTo(value2);
}

T identity<T>(T value) {
    return value;
}

int compareComparable<T extends Comparable<T>>(T a, T b) {
    return a.compareTo(b);
}
