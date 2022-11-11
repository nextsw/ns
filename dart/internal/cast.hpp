#ifndef DART_INTERNAL_CAST
#define DART_INTERNAL_CAST
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename S, typename T>
class _CastIterableBaseCls : public IterableCls<T> {
public:

    virtual Iterator<T> iterator();

    virtual int length();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual Iterable<T> skip(int count);

    virtual Iterable<T> take(int count);

    virtual T elementAt(int index);

    virtual T first();

    virtual T last();

    virtual T single();

    virtual bool contains(Object other);

    virtual T lastWhere(std::function<T()> orElse, std::function<bool(T element)> test);

    virtual String toString();

private:

    virtual Iterable<S> _source();
};
template<typename S, typename T>
using _CastIterableBase = std::shared_ptr<_CastIterableBaseCls<S, T>>;

template<typename S, typename T>
class CastIteratorCls : public ObjectCls {
public:

     CastIteratorCls(Iterator<S> _source);
    virtual bool moveNext();

    virtual T current();

private:
    Iterator<S> _source;


};
template<typename S, typename T>
using CastIterator = std::shared_ptr<CastIteratorCls<S, T>>;

template<typename S, typename T>
class CastIterableCls : public _CastIterableBaseCls<S, T> {
public:

     CastIterableCls(Iterable<S> source);

    template<typename R>
 virtual Iterable<R> cast();

private:
    Iterable<S> _source;


    virtual void  _(Iterable<S> _source);
};
template<typename S, typename T>
using CastIterable = std::shared_ptr<CastIterableCls<S, T>>;

template<typename S, typename T>
class _EfficientLengthCastIterableCls : public CastIterableCls<S, T> {
public:

private:

     _EfficientLengthCastIterableCls(EfficientLengthIterable<S> source);

};
template<typename S, typename T>
using _EfficientLengthCastIterable = std::shared_ptr<_EfficientLengthCastIterableCls<S, T>>;

template<typename S, typename T>
class _CastListBaseCls : public _CastIterableBaseCls<S, T> {
public:

    virtual T operator[](int index);

    virtual void operator[]=(int index, T value);

    virtual void length(int length);

    virtual void add(T value);

    virtual void addAll(Iterable<T> values);

    virtual void sort(std::function<int(T v1, T v2)> compare);

    virtual void shuffle(Random random);

    virtual void insert(T element, int index);

    virtual void insertAll(Iterable<T> elements, int index);

    virtual void setAll(Iterable<T> elements, int index);

    virtual bool remove(Object value);

    virtual T removeAt(int index);

    virtual T removeLast();

    virtual void removeWhere(std::function<bool(T element)> test);

    virtual void retainWhere(std::function<bool(T element)> test);

    virtual Iterable<T> getRange(int end, int start);

    virtual void setRange(int end, Iterable<T> iterable, int skipCount, int start);

    virtual void removeRange(int end, int start);

    virtual void fillRange(int end, T fillValue, int start);

    virtual void replaceRange(int end, Iterable<T> replacement, int start);

private:

    virtual List<S> _source() override;
};
template<typename S, typename T>
using _CastListBase = std::shared_ptr<_CastListBaseCls<S, T>>;

template<typename S, typename T>
class CastListCls : public _CastListBaseCls<S, T> {
public:

     CastListCls(List<S> _source);
    template<typename R>
 virtual List<R> cast();

private:
    List<S> _source;


};
template<typename S, typename T>
using CastList = std::shared_ptr<CastListCls<S, T>>;

template<typename S, typename T>
class CastSetCls : public _CastIterableBaseCls<S, T> {
public:

     CastSetCls(std::function<Set<R>()> _emptySet, Set<S> _source);
    template<typename R>
 virtual Set<R> cast();

    virtual bool add(T value);

    virtual void addAll(Iterable<T> elements);

    virtual bool remove(Object object);

    virtual void removeAll(Iterable<Object> objects);

    virtual void retainAll(Iterable<Object> objects);

    virtual void removeWhere(std::function<bool(T element)> test);

    virtual void retainWhere(std::function<bool(T element)> test);

    virtual bool containsAll(Iterable<Object> objects);

    virtual Set<T> intersection(Set<Object> other);

    virtual Set<T> difference(Set<Object> other);

    virtual Set<T> union(Set<T> other);

    virtual void clear();

    virtual Set<T> toSet();

    virtual T lookup(Object key);

private:
    Set<S> _source;

    std::function<Set<R>()> _emptySet;


    virtual Set<T> _conditionalAdd(Set<Object> other, bool otherContains);

    virtual Set<T> _clone();

};
template<typename S, typename T>
using CastSet = std::shared_ptr<CastSetCls<S, T>>;

template<typename SK, typename SV, typename K, typename V>
class CastMapCls : public MapBaseCls<K, V> {
public:

     CastMapCls(Map<SK, SV> _source);
    template<typename RK, typename RV>
 virtual Map<RK, RV> cast();

    virtual bool containsValue(Object value);

    virtual bool containsKey(Object key);

    virtual V operator[](Object key);

    virtual void operator[]=(K key, V value);

    virtual V putIfAbsent(std::function<V()> ifAbsent, K key);

    virtual void addAll(Map<K, V> other);

    virtual V remove(Object key);

    virtual void clear();

    virtual void forEach(std::function<void(K key, V value)> f);

    virtual Iterable<K> keys();

    virtual Iterable<V> values();

    virtual int length();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual V update(std::function<V()> ifAbsent, K key, std::function<V(V value)> update);

    virtual void updateAll(std::function<V(K key, V value)> update);

    virtual Iterable<MapEntry<K, V>> entries();

    virtual void addEntries(Iterable<MapEntry<K, V>> entries);

    virtual void removeWhere(std::function<bool(K key, V value)> test);

private:
    Map<SK, SV> _source;


};
template<typename SK, typename SV, typename K, typename V>
using CastMap = std::shared_ptr<CastMapCls<SK, SV, K, V>>;

template<typename S, typename T>
class CastQueueCls : public _CastIterableBaseCls<S, T> {
public:

     CastQueueCls(Queue<S> _source);
    template<typename R>
 virtual Queue<R> cast();

    virtual T removeFirst();

    virtual T removeLast();

    virtual void add(T value);

    virtual void addFirst(T value);

    virtual void addLast(T value);

    virtual bool remove(Object other);

    virtual void addAll(Iterable<T> elements);

    virtual void removeWhere(std::function<bool(T element)> test);

    virtual void retainWhere(std::function<bool(T element)> test);

    virtual void clear();

private:
    Queue<S> _source;


};
template<typename S, typename T>
using CastQueue = std::shared_ptr<CastQueueCls<S, T>>;


#endif