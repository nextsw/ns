#ifndef COLLECTIONS_H
#define COLLECTIONS_H
#include <memory>



bool setEquals<T>(Set<T> a, Set<T> b);

bool listEquals<T>(List<T> a, List<T> b);

bool mapEquals<T, U>(Map<T, U> a, Map<T, U> b);

int binarySearch<T extends Comparable<Object>>(List<T> sortedList, T value);

const int _kMergeSortLimit;

void mergeSort<T>(FunctionType compare, int end, List<T> list, int start);

Comparator<T> _defaultCompare<T>();

void _insertionSort<T>(FunctionType compare, int end, List<T> list, int start);

void _movingInsertionSort<T>(FunctionType compare, int end, List<T> list, int start, List<T> target, int targetOffset);

void _mergeSort<T>(FunctionType compare, int end, List<T> list, int start, List<T> target, int targetOffset);

void _merge<T>(FunctionType compare, int firstEnd, List<T> firstList, int firstStart, int secondEnd, List<T> secondList, int secondStart, List<T> target, int targetOffset);


#endif