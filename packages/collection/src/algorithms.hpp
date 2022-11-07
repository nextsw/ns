#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <memory>

#include <math/math.hpp>
#include "utils.hpp"


int binarySearch<E>(FunctionType compare, List<E> sortedList, E value);

int binarySearchBy<E, K>(FunctionType compare, int end, FunctionType keyOf, List<E> sortedList, int start, E value);

int lowerBound<E>(FunctionType compare, List<E> sortedList, E value);

int lowerBoundBy<E, K>(FunctionType compare, int end, FunctionType keyOf, List<E> sortedList, int start, E value);

void shuffle(List elements, int end, Random random, int start);

void reverse<E>(List<E> elements, int end, int start);

void _reverse<E>(List<E> elements, int end, int start);

void insertionSort<E>(FunctionType compare, List<E> elements, int end, int start);

void insertionSortBy<E, K>(FunctionType compare, List<E> elements, int end, FunctionType keyOf, int start);

const int _mergeSortLimit;


#endif