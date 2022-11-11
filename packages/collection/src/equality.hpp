#ifndef PACKAGES_COLLECTION_SRC_EQUALITY
#define PACKAGES_COLLECTION_SRC_EQUALITY
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include "comparators.hpp"

int _hashMask;


template<typename E>
class EqualityCls : public ObjectCls {
public:

     EqualityCls();
    virtual bool equals(E e1, E e2);
    virtual int hash(E e);
    virtual bool isValidKey(Object o);
private:

};
template<typename E>
using Equality = std::shared_ptr<EqualityCls<E>>;

template<typename E, typename F>
class EqualityByCls : public ObjectCls {
public:

     EqualityByCls(std::function<F(E )> comparisonKey, Equality<F> inner);

    virtual bool equals(E e1, E e2);

    virtual int hash(E e);

    virtual bool isValidKey(Object o);

private:
    std::function<F(E )> _comparisonKey;

    Equality<F> _inner;


};
template<typename E, typename F>
using EqualityBy = std::shared_ptr<EqualityByCls<E, F>>;

template<typename E>
class DefaultEqualityCls : public ObjectCls {
public:

     DefaultEqualityCls();
    virtual bool equals(Object e1, Object e2);

    virtual int hash(Object e);

    virtual bool isValidKey(Object o);

private:

};
template<typename E>
using DefaultEquality = std::shared_ptr<DefaultEqualityCls<E>>;

template<typename E>
class IdentityEqualityCls : public ObjectCls {
public:

     IdentityEqualityCls();
    virtual bool equals(E e1, E e2);

    virtual int hash(E e);

    virtual bool isValidKey(Object o);

private:

};
template<typename E>
using IdentityEquality = std::shared_ptr<IdentityEqualityCls<E>>;

template<typename E>
class IterableEqualityCls : public ObjectCls {
public:

     IterableEqualityCls(Equality<E> elementEquality);

    virtual bool equals(Iterable<E> elements1, Iterable<E> elements2);

    virtual int hash(Iterable<E> elements);

    virtual bool isValidKey(Object o);

private:
    Equality<E> _elementEquality;


};
template<typename E>
using IterableEquality = std::shared_ptr<IterableEqualityCls<E>>;

template<typename E>
class ListEqualityCls : public ObjectCls {
public:

     ListEqualityCls(Equality<E> elementEquality);

    virtual bool equals(List<E> list1, List<E> list2);

    virtual int hash(List<E> list);

    virtual bool isValidKey(Object o);

private:
    Equality<E> _elementEquality;


};
template<typename E>
using ListEquality = std::shared_ptr<ListEqualityCls<E>>;

template<typename E, typename T>
class _UnorderedEqualityCls : public ObjectCls {
public:

    virtual bool equals(T elements1, T elements2);

    virtual int hash(T elements);

private:
    Equality<E> _elementEquality;


     _UnorderedEqualityCls(Equality<E> _elementEquality);
};
template<typename E, typename T>
using _UnorderedEquality = std::shared_ptr<_UnorderedEqualityCls<E, T>>;

template<typename E>
class UnorderedIterableEqualityCls : public _UnorderedEqualityCls<E, Iterable<E>> {
public:

     UnorderedIterableEqualityCls(Equality<E> elementEquality);

    virtual bool isValidKey(Object o);

private:

};
template<typename E>
using UnorderedIterableEquality = std::shared_ptr<UnorderedIterableEqualityCls<E>>;

template<typename E>
class SetEqualityCls : public _UnorderedEqualityCls<E, Set<E>> {
public:

     SetEqualityCls(Equality<E> elementEquality);

    virtual bool isValidKey(Object o);

private:

};
template<typename E>
using SetEquality = std::shared_ptr<SetEqualityCls<E>>;

class _MapEntryCls : public ObjectCls {
public:
    MapEquality<any, any> equality;

    Object key;

    Object value;


    virtual int hashCode();

    virtual bool operator==(Object other);

private:

     _MapEntryCls(MapEquality<any, any> equality, Object key, Object value);
};
using _MapEntry = std::shared_ptr<_MapEntryCls>;

template<typename K, typename V>
class MapEqualityCls : public ObjectCls {
public:

     MapEqualityCls(Equality<K> keys, Equality<V> values);

    virtual bool equals(Map<K, V> map1, Map<K, V> map2);

    virtual int hash(Map<K, V> map);

    virtual bool isValidKey(Object o);

private:
    Equality<K> _keyEquality;

    Equality<V> _valueEquality;


};
template<typename K, typename V>
using MapEquality = std::shared_ptr<MapEqualityCls<K, V>>;

template<typename E>
class MultiEqualityCls : public ObjectCls {
public:

     MultiEqualityCls(Iterable<Equality<E>> equalities);

    virtual bool equals(E e1, E e2);

    virtual int hash(E e);

    virtual bool isValidKey(Object o);

private:
    Iterable<Equality<E>> _equalities;


};
template<typename E>
using MultiEquality = std::shared_ptr<MultiEqualityCls<E>>;

class DeepCollectionEqualityCls : public ObjectCls {
public:

     DeepCollectionEqualityCls(Equality<any> base);

    virtual void  unordered(Equality<any> base);

    virtual bool equals(e1 , e2 );

    virtual int hash(Object o);

    virtual bool isValidKey(Object o);

private:
    Equality<any> _base;

    bool _unordered;


};
using DeepCollectionEquality = std::shared_ptr<DeepCollectionEqualityCls>;

class CaseInsensitiveEqualityCls : public ObjectCls {
public:

     CaseInsensitiveEqualityCls();
    virtual bool equals(String string1, String string2);

    virtual int hash(String stringValue);

    virtual bool isValidKey(Object object);

private:

};
using CaseInsensitiveEquality = std::shared_ptr<CaseInsensitiveEqualityCls>;


#endif