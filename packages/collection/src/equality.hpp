#ifndef EQUALITY_H
#define EQUALITY_H
#include <memory>

#include <collection/collection.hpp>
#include "comparators.hpp"


const int _hashMask;


class Equality<E> {
public:

     Equality();

    bool equals(E e1, E e2);

    int hash(E e);

    bool isValidKey(Object o);

private:

};

class EqualityBy<E, F> {
public:

     EqualityBy(FunctionType comparisonKey, Equality<F> inner);

    bool equals(E e1, E e2);

    int hash(E e);

    bool isValidKey(Object o);

private:
    FunctionType _comparisonKey;

    Equality<F> _inner;


};

class DefaultEquality<E> {
public:

     DefaultEquality();

    bool equals(Object e1, Object e2);

    int hash(Object e);

    bool isValidKey(Object o);

private:

};

class IdentityEquality<E> {
public:

     IdentityEquality();

    bool equals(E e1, E e2);

    int hash(E e);

    bool isValidKey(Object o);

private:

};

class IterableEquality<E> {
public:

     IterableEquality(Equality<E> elementEquality);

    bool equals(Iterable<E> elements1, Iterable<E> elements2);

    int hash(Iterable<E> elements);

    bool isValidKey(Object o);

private:
    Equality<E> _elementEquality;


};

class ListEquality<E> {
public:

     ListEquality(Equality<E> elementEquality);

    bool equals(List<E> list1, List<E> list2);

    int hash(List<E> list);

    bool isValidKey(Object o);

private:
    Equality<E> _elementEquality;


};

class _UnorderedEquality<E, T extends Iterable<E>> {
public:

    bool equals(T elements1, T elements2);

    int hash(T elements);

private:
    Equality<E> _elementEquality;


     _UnorderedEquality(Equality<E> _elementEquality);

};

class UnorderedIterableEquality<E> : _UnorderedEquality<E, Iterable<E>> {
public:

     UnorderedIterableEquality(Equality<E> elementEquality);

    bool isValidKey(Object o);

private:

};

class SetEquality<E> : _UnorderedEquality<E, Set<E>> {
public:

     SetEquality(Equality<E> elementEquality);

    bool isValidKey(Object o);

private:

};

class _MapEntry {
public:
    MapEquality equality;

    Object key;

    Object value;


    int hashCode();

    bool ==(Object other);

private:

     _MapEntry(MapEquality equality, Object key, Object value);

};

class MapEquality<K, V> {
public:

     MapEquality(Equality<K> keys, Equality<V> values);

    bool equals(Map<K, V> map1, Map<K, V> map2);

    int hash(Map<K, V> map);

    bool isValidKey(Object o);

private:
    Equality<K> _keyEquality;

    Equality<V> _valueEquality;


};

class MultiEquality<E> {
public:

     MultiEquality(Iterable<Equality<E>> equalities);

    bool equals(E e1, E e2);

    int hash(E e);

    bool isValidKey(Object o);

private:
    Iterable<Equality<E>> _equalities;


};

class DeepCollectionEquality {
public:

     DeepCollectionEquality(Equality base);

    void  unordered(Equality base);

    bool equals(e1 , e2 );

    int hash(Object o);

    bool isValidKey(Object o);

private:
    Equality _base;

    bool _unordered;


};

class CaseInsensitiveEquality {
public:

     CaseInsensitiveEquality();

    bool equals(String string1, String string2);

    int hash(String string);

    bool isValidKey(Object object);

private:

};

#endif