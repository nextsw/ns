#ifndef PACKAGES_COLLECTION_SRC_ALGORITHMS
#define PACKAGES_COLLECTION_SRC_ALGORITHMS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include "utils.hpp"

template<typename E>  int binarySearch(int compare(E , E ) , List<E> sortedList, E value);

template<typename E, typename K>  int binarySearchBy(int compare(K , K ) , int end, K keyOf(E element) , List<E> sortedList, int start, E value);

template<typename E>  int lowerBound(int compare(E , E ) , List<E> sortedList, E value);

template<typename E, typename K>  int lowerBoundBy(int compare(K , K ) , int end, K keyOf(E element) , List<E> sortedList, int start, E value);

void shuffle(List elements, int end, Random random, int start);

template<typename E>  void reverse(List<E> elements, int end, int start);

template<typename E>  void _reverse(List<E> elements, int end, int start);

template<typename E>  void insertionSort(int compare(E , E ) , List<E> elements, int end, int start);

template<typename E, typename K>  void insertionSortBy(int compare(K a, K b) , List<E> elements, int end, K keyOf(E element) , int start);

int _mergeSortLimit;



#endif