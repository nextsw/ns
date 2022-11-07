#ifndef COMBINED_ITERABLE_H
#define COMBINED_ITERABLE_H
#include <memory>

#include <collection/collection.hpp>
#include "combined_iterator.hpp"



class CombinedIterableView<T> : IterableBase<T> {
public:

     CombinedIterableView(Iterable<Iterable<T>> _iterables);

    Iterator<T> iterator();

    bool contains(Object element);

    bool isEmpty();

    int length();

private:
    Iterable<Iterable<T>> _iterables;


};

#endif