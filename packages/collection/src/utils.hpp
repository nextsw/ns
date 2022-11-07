#ifndef UTILS_H
#define UTILS_H
#include <memory>



int defaultCompare(Object value1, Object value2);

T identity<T>(T value);

int compareComparable<T extends Comparable<T>>(T a, T b);


#endif