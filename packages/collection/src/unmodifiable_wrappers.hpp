#ifndef PACKAGES_COLLECTION_SRC_UNMODIFIABLE_WRAPPERS
#define PACKAGES_COLLECTION_SRC_UNMODIFIABLE_WRAPPERS
#include <base.hpp>
#include <dart/collection/collection.hpp>

#include <dart/core/core.hpp>
#include "empty_unmodifiable_set.hpp"
#include "wrappers.hpp"


template<typename E>
class NonGrowableListViewCls : public DelegatingListCls<E> {
public:

     NonGrowableListViewCls(List<E> listBase);

private:

};
template<typename E>
using NonGrowableListView = std::shared_ptr<NonGrowableListViewCls<E>>;

template<typename E>
class NonGrowableListMixinCls : public ObjectCls {
public:

    virtual void  length(int newLength);

    virtual bool add(E value);

    virtual void addAll(Iterable<E> iterable);

    virtual void insert(int index, E element);

    virtual void insertAll(int index, Iterable<E> iterable);

    virtual bool remove(Object value);

    virtual E removeAt(int index);

    virtual E removeLast();

    virtual void removeWhere(std::function<bool(E )> test);

    virtual void retainWhere(std::function<bool(E )> test);

    virtual void removeRange(int start, int end);

    virtual void replaceRange(int start, int end, Iterable<E> iterable);

    virtual void clear();

private:

    static Never _throw();

};
template<typename E>
using NonGrowableListMixin = std::shared_ptr<NonGrowableListMixinCls<E>>;

template<typename E>
class UnmodifiableSetViewCls : public DelegatingSetCls<E> {
public:

     UnmodifiableSetViewCls(Set<E> setBase);

    virtual void  empty();
private:

};
template<typename E>
using UnmodifiableSetView = std::shared_ptr<UnmodifiableSetViewCls<E>>;

template<typename E>
class UnmodifiableSetMixinCls : public ObjectCls {
public:

    virtual bool add(E value);

    virtual void addAll(Iterable<E> elements);

    virtual bool remove(Object value);

    virtual void removeAll(Iterable elements);

    virtual void retainAll(Iterable elements);

    virtual void removeWhere(std::function<bool(E )> test);

    virtual void retainWhere(std::function<bool(E )> test);

    virtual void clear();

private:

    static Never _throw();

};
template<typename E>
using UnmodifiableSetMixin = std::shared_ptr<UnmodifiableSetMixinCls<E>>;

template<typename K, typename V>
class UnmodifiableMapMixinCls : public ObjectCls {
public:

    virtual void operator[]=(K key, V value);

    virtual V putIfAbsent(K key, std::function<V()> ifAbsent);

    virtual void addAll(Map<K, V> other);

    virtual V remove(Object key);

    virtual void clear();

    virtual void  first(_ );

    virtual void  last(_ );

private:

    static Never _throw();

};
template<typename K, typename V>
using UnmodifiableMapMixin = std::shared_ptr<UnmodifiableMapMixinCls<K, V>>;


#endif