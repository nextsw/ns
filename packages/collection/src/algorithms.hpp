#ifndef PACKAGES_COLLECTION_SRC_ALGORITHMS
#define PACKAGES_COLLECTION_SRC_ALGORITHMS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include "utils.hpp"

template<typename E>
 int binarySearch(List<E> sortedList, E value, std::function<int(E , E )> compare);

template<typename E, typename K>
 int binarySearchBy(List<E> sortedList, std::function<K(E element)> keyOf, std::function<int(K , K )> compare, E value, int start, int end);

template<typename E>
 int lowerBound(List<E> sortedList, E value, std::function<int(E , E )> compare);

template<typename E, typename K>
 int lowerBoundBy(List<E> sortedList, std::function<K(E element)> keyOf, std::function<int(K , K )> compare, E value, int start, int end);

void shuffle(List elements, int start, int end, Random random);

template<typename E>
 void reverse(List<E> elements, int start, int end);

template<typename E>
 void _reverse(List<E> elements, int start, int end);

template<typename E>
 void insertionSort(List<E> elements, std::function<int(E , E )> compare, int end, int start);

template<typename E, typename K>
 void insertionSortBy(List<E> elements, std::function<K(E element)> keyOf, std::function<int(K a, K b)> compare, int start, int end);

int _mergeSortLimit;



#endif