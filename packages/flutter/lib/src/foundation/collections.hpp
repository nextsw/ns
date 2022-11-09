#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_COLLECTIONS
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_COLLECTIONS
#include <base.hpp>

#include <dart/core/core.hpp>

template<typename T>  bool setEquals(Set<T> a, Set<T> b);

template<typename T>  bool listEquals(List<T> a, List<T> b);

template<typename T, typename U>  bool mapEquals(Map<T, U> a, Map<T, U> b);

template<typename T : Comparable<Object>>  int binarySearch(List<T> sortedList, T value);

int _kMergeSortLimit;

template<typename T>  void mergeSort(int compare(T , T ) , int end, List<T> list, int start);

template<typename T>  Comparator<T> _defaultCompare();

template<typename T>  void _insertionSort(int compare(T , T ) , int end, List<T> list, int start);

template<typename T>  void _movingInsertionSort(int compare(T , T ) , int end, List<T> list, int start, List<T> target, int targetOffset);

template<typename T>  void _mergeSort(int compare(T , T ) , int end, List<T> list, int start, List<T> target, int targetOffset);

template<typename T>  void _merge(int compare(T , T ) , int firstEnd, List<T> firstList, int firstStart, int secondEnd, List<T> secondList, int secondStart, List<T> target, int targetOffset);



#endif