#ifndef WRAPPERS_H
#define WRAPPERS_H
#include <memory>

#include <collection/collection.hpp>
#include <math/math.hpp>
#include "unmodifiable_wrappers.hpp"



class _DelegatingIterableBase<E> {
public:

    bool any(FunctionType test);

    Iterable<T> cast<T>();

    bool contains(Object element);

    E elementAt(int index);

    bool every(FunctionType test);

    Iterable<T> expand<T>(FunctionType f);

    E first();

    E firstWhere(FunctionType orElse, FunctionType test);

    T fold<T>(FunctionType combine, T initialValue);

    Iterable<E> followedBy(Iterable<E> other);

    void forEach(FunctionType f);

    bool isEmpty();

    bool isNotEmpty();

    Iterator<E> iterator();

    String join(String separator);

    E last();

    E lastWhere(FunctionType orElse, FunctionType test);

    int length();

    Iterable<T> map<T>(FunctionType f);

    E reduce(FunctionType combine);

    Iterable<T> retype<T>();

    E single();

    E singleWhere(FunctionType orElse, FunctionType test);

    Iterable<E> skip(int n);

    Iterable<E> skipWhile(FunctionType test);

    Iterable<E> take(int n);

    Iterable<E> takeWhile(FunctionType test);

    List<E> toList(bool growable);

    Set<E> toSet();

    Iterable<E> where(FunctionType test);

    Iterable<T> whereType<T>();

    String toString();

private:

    Iterable<E> _base();

     _DelegatingIterableBase();

};

class DelegatingIterable<E> : _DelegatingIterableBase<E> {
public:

     DelegatingIterable(Iterable<E> base);

    static Iterable<E> typed<E>(Iterable base);

private:
    Iterable<E> _base;


};

class DelegatingList<E> : _DelegatingIterableBase<E> {
public:

     DelegatingList(List<E> base);

    static List<E> typed<E>(List base);

    E [](int index);

    void []=(int index, E value);

    List<E> +(List<E> other);

    void add(E value);

    void addAll(Iterable<E> iterable);

    Map<int, E> asMap();

    List<T> cast<T>();

    void clear();

    void fillRange(int end, E fillValue, int start);

    void  first(E value);

    Iterable<E> getRange(int end, int start);

    int indexOf(E element, int start);

    int indexWhere(int start, FunctionType test);

    void insert(E element, int index);

    void insertAll(int index, Iterable<E> iterable);

    void  last(E value);

    int lastIndexOf(E element, int start);

    int lastIndexWhere(int start, FunctionType test);

    void  length(int newLength);

    bool remove(Object value);

    E removeAt(int index);

    E removeLast();

    void removeRange(int end, int start);

    void removeWhere(FunctionType test);

    void replaceRange(int end, Iterable<E> iterable, int start);

    void retainWhere(FunctionType test);

    List<T> retype<T>();

    Iterable<E> reversed();

    void setAll(int index, Iterable<E> iterable);

    void setRange(int end, Iterable<E> iterable, int skipCount, int start);

    void shuffle(Random random);

    void sort(FunctionType compare);

    List<E> sublist(int end, int start);

private:
    List<E> _base;


};

class DelegatingSet<E> : _DelegatingIterableBase<E> {
public:

     DelegatingSet(Set<E> base);

    static Set<E> typed<E>(Set base);

    bool add(E value);

    void addAll(Iterable<E> elements);

    Set<T> cast<T>();

    void clear();

    bool containsAll(Iterable<Object> other);

    Set<E> difference(Set<Object> other);

    Set<E> intersection(Set<Object> other);

    E lookup(Object element);

    bool remove(Object value);

    void removeAll(Iterable<Object> elements);

    void removeWhere(FunctionType test);

    void retainAll(Iterable<Object> elements);

    Set<T> retype<T>();

    void retainWhere(FunctionType test);

    Set<E> union(Set<E> other);

    Set<E> toSet();

private:
    Set<E> _base;


};

class DelegatingQueue<E> : _DelegatingIterableBase<E> {
public:

     DelegatingQueue(Queue<E> queue);

    static Queue<E> typed<E>(Queue base);

    void add(E value);

    void addAll(Iterable<E> iterable);

    void addFirst(E value);

    void addLast(E value);

    Queue<T> cast<T>();

    void clear();

    bool remove(Object object);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    Queue<T> retype<T>();

    E removeFirst();

    E removeLast();

private:
    Queue<E> _base;


};

class DelegatingMap<K, V> {
public:

     DelegatingMap(Map<K, V> base);

    static Map<K, V> typed<K, V>(Map base);

    V [](Object key);

    void []=(K key, V value);

    void addAll(Map<K, V> other);

    void addEntries(Iterable<MapEntry<K, V>> entries);

    void clear();

    Map<K2, V2> cast<K2, V2>();

    bool containsKey(Object key);

    bool containsValue(Object value);

    Iterable<MapEntry<K, V>> entries();

    void forEach(FunctionType f);

    bool isEmpty();

    bool isNotEmpty();

    Iterable<K> keys();

    int length();

    Map<K2, V2> map<K2, V2>(FunctionType transform);

    V putIfAbsent(FunctionType ifAbsent, K key);

    V remove(Object key);

    void removeWhere(FunctionType test);

    Map<K2, V2> retype<K2, V2>();

    Iterable<V> values();

    String toString();

    V update(FunctionType ifAbsent, K key, FunctionType update);

    void updateAll(FunctionType update);

private:
    Map<K, V> _base;


};

class MapKeySet<E> : _DelegatingIterableBase<E> {
public:

     MapKeySet(Map<E, dynamic> _baseMap);

    Set<T> cast<T>();

    bool contains(Object element);

    bool isEmpty();

    bool isNotEmpty();

    int length();

    String toString();

    bool containsAll(Iterable<Object> other);

    Set<E> difference(Set<Object> other);

    Set<E> intersection(Set<Object> other);

    E lookup(Object element);

    Set<T> retype<T>();

    Set<E> union(Set<E> other);

private:
    Map<E, dynamic> _baseMap;


    Iterable<E> _base();

};

class MapValueSet<K, V> : _DelegatingIterableBase<V> {
public:

     MapValueSet(Map<K, V> _baseMap, FunctionType _keyForValue);

    Set<T> cast<T>();

    bool contains(Object element);

    bool isEmpty();

    bool isNotEmpty();

    int length();

    String toString();

    bool add(V value);

    void addAll(Iterable<V> elements);

    void clear();

    bool containsAll(Iterable<Object> other);

    Set<V> difference(Set<Object> other);

    Set<V> intersection(Set<Object> other);

    V lookup(Object element);

    bool remove(Object element);

    void removeAll(Iterable<Object> elements);

    void removeWhere(FunctionType test);

    void retainAll(Iterable<Object> elements);

    void retainWhere(FunctionType test);

    Set<T> retype<T>();

    Set<V> union(Set<V> other);

private:
    Map<K, V> _baseMap;

    FunctionType _keyForValue;


    Iterable<V> _base();

};

#endif