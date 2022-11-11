#ifndef DART_INTERNAL_SORT
#define DART_INTERNAL_SORT
#include <base.hpp>

#include <dart/core/core.hpp>


class SortCls : public ObjectCls {
public:

    template<typename E>
 static void sort(List<E> a, std::function<int(E a, E b)> compare);

    template<typename E>
 static void sortRange(List<E> a, int from, int to, std::function<int(E a, E b)> compare);

private:
    static int _INSERTION_SORT_THRESHOLD;


    template<typename E>
 static void _doSort(List<E> a, int left, int right, std::function<int(E a, E b)> compare);

    template<typename E>
 static void _insertionSort(List<E> a, int left, int right, std::function<int(E a, E b)> compare);

    template<typename E>
 static void _dualPivotQuicksort(List<E> a, int left, int right, std::function<int(E a, E b)> compare);

};
using Sort = std::shared_ptr<SortCls>;


#endif