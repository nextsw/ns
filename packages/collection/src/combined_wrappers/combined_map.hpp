#ifndef PACKAGES_COLLECTION_SRC_COMBINED_WRAPPERS_COMBINED_MAP
#define PACKAGES_COLLECTION_SRC_COMBINED_WRAPPERS_COMBINED_MAP
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include "combined_iterable.hpp"


template<typename K, typename V>
class CombinedMapViewCls : public UnmodifiableMapBaseCls<K, V> {
public:

     CombinedMapViewCls(Iterable<Map<K, V>> _maps);
    virtual V operator[](Object key);

    virtual Iterable<K> keys();

private:
    Iterable<Map<K, V>> _maps;


};
template<typename K, typename V>
using CombinedMapView = std::shared_ptr<CombinedMapViewCls<K, V>>;

template<typename T>
class _DeduplicatingIterableViewCls : public IterableBaseCls<T> {
public:

    virtual Iterator<T> iterator();

    virtual bool contains(Object element);

    virtual bool isEmpty();

private:
    Iterable<T> _iterable;


     _DeduplicatingIterableViewCls(Iterable<T> _iterable);
};
template<typename T>
using _DeduplicatingIterableView = std::shared_ptr<_DeduplicatingIterableViewCls<T>>;

template<typename T>
class _DeduplicatingIteratorCls : public ObjectCls {
public:

    virtual T current();

    virtual bool moveNext();

private:
    Iterator<T> _iterator;

    auto  _emitted;


     _DeduplicatingIteratorCls(Iterator<T> _iterator);
};
template<typename T>
using _DeduplicatingIterator = std::shared_ptr<_DeduplicatingIteratorCls<T>>;


#endif