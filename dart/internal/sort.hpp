#ifndef DART_INTERNAL_SORT
#define DART_INTERNAL_SORT
#include <base.hpp>

#include <dart/core/core.hpp>


class SortCls : public ObjectCls {
public:

    template<typename E>
 static void sort(List<E> a, std::function<int(E a, E b)> compare);

    template<typename E>
 static void sortRange(List<E> a, std::function<int(E a, E b)> compare, int from, int to);

private:
    static int _INSERTION_SORT_THRESHOLD;


    template<typename E>
 static void _doSort(List<E> a, std::function<int(E a, E b)> compare, int left, int right);

    template<typename E>
 static void _insertionSort(List<E> a, std::function<int(E a, E b)> compare, int left, int right);

    template<typename E>
 static void _dualPivotQuicksort(List<E> a, std::function<int(E a, E b)> compare, int left, int right);

};
using Sort = std::shared_ptr<SortCls>;


#endif