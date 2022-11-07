#ifndef COMBINED_MAP_H
#define COMBINED_MAP_H
#include <memory>

#include <collection/collection.hpp>
#include "combined_iterable.hpp"



class CombinedMapView<K, V> : UnmodifiableMapBase<K, V> {
public:

     CombinedMapView(Iterable<Map<K, V>> _maps);

    V [](Object key);

    Iterable<K> keys();

private:
    Iterable<Map<K, V>> _maps;


};

class _DeduplicatingIterableView<T> : IterableBase<T> {
public:

    Iterator<T> iterator();

    bool contains(Object element);

    bool isEmpty();

private:
    Iterable<T> _iterable;


     _DeduplicatingIterableView(Iterable<T> _iterable);

};

class _DeduplicatingIterator<T> {
public:

    T current();

    bool moveNext();

private:
    Iterator<T> _iterator;

    auto  _emitted;


     _DeduplicatingIterator(Iterator<T> _iterator);

};

#endif