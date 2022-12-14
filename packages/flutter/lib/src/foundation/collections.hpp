#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_COLLECTIONS
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_COLLECTIONS
#include <base.hpp>

#include <dart/core/core.hpp>

template<typename T>
 bool setEquals(Set<T> a, Set<T> b);

template<typename T>
 bool listEquals(List<T> a, List<T> b);

template<typename T, typename U>
 bool mapEquals(Map<T, U> a, Map<T, U> b);

template<typename T>
 int binarySearch(List<T> sortedList, T value);

int _kMergeSortLimit;

template<typename T>
 void mergeSort(List<T> list, std::function<int(T , T )> compare, int end, int start);

template<typename T>
 Comparator<T> _defaultCompare();

template<typename T>
 void _insertionSort(List<T> list, std::function<int(T , T )> compare, int end, int start);

template<typename T>
 void _movingInsertionSort(List<T> list, std::function<int(T , T )> compare, int start, int end, List<T> target, int targetOffset);

template<typename T>
 void _mergeSort(List<T> list, std::function<int(T , T )> compare, int start, int end, List<T> target, int targetOffset);

template<typename T>
 void _merge(std::function<int(T , T )> compare, List<T> firstList, int firstStart, int firstEnd, List<T> secondList, int secondStart, int secondEnd, List<T> target, int targetOffset);



#endif