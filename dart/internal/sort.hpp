#ifndef SORT_H
#define SORT_H
#include <memory>




class Sort {
public:

    static void sort<E>(List<E> a, FunctionType compare);

    static void sortRange<E>(List<E> a, FunctionType compare, int from, int to);

private:
    static const int _INSERTION_SORT_THRESHOLD;


    static void _doSort<E>(List<E> a, FunctionType compare, int left, int right);

    static void _insertionSort<E>(List<E> a, FunctionType compare, int left, int right);

    static void _dualPivotQuicksort<E>(List<E> a, FunctionType compare, int left, int right);

};

#endif