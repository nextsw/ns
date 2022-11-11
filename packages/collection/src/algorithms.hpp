#ifndef PACKAGES_COLLECTION_SRC_ALGORITHMS
#define PACKAGES_COLLECTION_SRC_ALGORITHMS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include "utils.hpp"

template<typename E>
 int binarySearch(std::function<int(E , E )> compare, List<E> sortedList, E value);

template<typename E, typename K>
 int binarySearchBy(std::function<int(K , K )> compare, int end, std::function<K(E element)> keyOf, List<E> sortedList, int start, E value);

template<typename E>
 int lowerBound(std::function<int(E , E )> compare, List<E> sortedList, E value);

template<typename E, typename K>
 int lowerBoundBy(std::function<int(K , K )> compare, int end, std::function<K(E element)> keyOf, List<E> sortedList, int start, E value);

void shuffle(List elements, int end, Random random, int start);

template<typename E>
 void reverse(List<E> elements, int end, int start);

template<typename E>
 void _reverse(List<E> elements, int end, int start);

template<typename E>
 void insertionSort(std::function<int(E , E )> compare, List<E> elements, int end, int start);

template<typename E, typename K>
 void insertionSortBy(std::function<int(K a, K b)> compare, List<E> elements, int end, std::function<K(E element)> keyOf, int start);

int _mergeSortLimit;



#endif