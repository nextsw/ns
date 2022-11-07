#ifndef CAST_H
#define CAST_H
#include <memory>




class _CastIterableBase<S, T> : Iterable<T> {
public:

    Iterator<T> iterator();

    int length();

    bool isEmpty();

    bool isNotEmpty();

    Iterable<T> skip(int count);

    Iterable<T> take(int count);

    T elementAt(int index);

    T first();

    T last();

    T single();

    bool contains(Object other);

    T lastWhere(FunctionType orElse, FunctionType test);

    String toString();

private:

    Iterable<S> _source();

};

class CastIterator<S, T> {
public:

     CastIterator(Iterator<S> _source);

    bool moveNext();

    T current();

private:
    Iterator<S> _source;


};

class CastIterable<S, T> : _CastIterableBase<S, T> {
public:

     CastIterable(Iterable<S> source);

    Iterable<R> cast<R>();

private:
    Iterable<S> _source;


    void  _(Iterable<S> _source);

};

class _EfficientLengthCastIterable<S, T> : CastIterable<S, T> {
public:

private:

     _EfficientLengthCastIterable(EfficientLengthIterable<S> source);

};

class _CastListBase<S, T> : _CastIterableBase<S, T> {
public:

    T [](int index);

    void []=(int index, T value);

    void length(int length);

    void add(T value);

    void addAll(Iterable<T> values);

    void sort(FunctionType compare);

    void shuffle(Random random);

    void insert(T element, int index);

    void insertAll(Iterable<T> elements, int index);

    void setAll(Iterable<T> elements, int index);

    bool remove(Object value);

    T removeAt(int index);

    T removeLast();

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    Iterable<T> getRange(int end, int start);

    void setRange(int end, Iterable<T> iterable, int skipCount, int start);

    void removeRange(int end, int start);

    void fillRange(int end, T fillValue, int start);

    void replaceRange(int end, Iterable<T> replacement, int start);

private:

    List<S> _source();

};

class CastList<S, T> : _CastListBase<S, T> {
public:

     CastList(List<S> _source);

    List<R> cast<R>();

private:
    List<S> _source;


};

class CastSet<S, T> : _CastIterableBase<S, T> {
public:

     CastSet(FunctionType _emptySet, Set<S> _source);

    Set<R> cast<R>();

    bool add(T value);

    void addAll(Iterable<T> elements);

    bool remove(Object object);

    void removeAll(Iterable<Object> objects);

    void retainAll(Iterable<Object> objects);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    bool containsAll(Iterable<Object> objects);

    Set<T> intersection(Set<Object> other);

    Set<T> difference(Set<Object> other);

    Set<T> union(Set<T> other);

    void clear();

    Set<T> toSet();

    T lookup(Object key);

private:
    Set<S> _source;

    FunctionType _emptySet;


    Set<T> _conditionalAdd(Set<Object> other, bool otherContains);

    Set<T> _clone();

};

class CastMap<SK, SV, K, V> : MapBase<K, V> {
public:

     CastMap(Map<SK, SV> _source);

    Map<RK, RV> cast<RK, RV>();

    bool containsValue(Object value);

    bool containsKey(Object key);

    V [](Object key);

    void []=(K key, V value);

    V putIfAbsent(FunctionType ifAbsent, K key);

    void addAll(Map<K, V> other);

    V remove(Object key);

    void clear();

    void forEach(FunctionType f);

    Iterable<K> keys();

    Iterable<V> values();

    int length();

    bool isEmpty();

    bool isNotEmpty();

    V update(FunctionType ifAbsent, K key, FunctionType update);

    void updateAll(FunctionType update);

    Iterable<MapEntry<K, V>> entries();

    void addEntries(Iterable<MapEntry<K, V>> entries);

    void removeWhere(FunctionType test);

private:
    Map<SK, SV> _source;


};

class CastQueue<S, T> : _CastIterableBase<S, T> {
public:

     CastQueue(Queue<S> _source);

    Queue<R> cast<R>();

    T removeFirst();

    T removeLast();

    void add(T value);

    void addFirst(T value);

    void addLast(T value);

    bool remove(Object other);

    void addAll(Iterable<T> elements);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    void clear();

private:
    Queue<S> _source;


};

#endif