#ifndef PACKAGES_COLLECTION_SRC_WRAPPERS
#define PACKAGES_COLLECTION_SRC_WRAPPERS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <dart/math/math.hpp>
#include "unmodifiable_wrappers.hpp"


template<typename E> class _DelegatingIterableBaseCls : public ObjectCls {
public:

    virtual bool any(bool test(E ) );

    template<typename T>  virtual Iterable<T> cast();

    virtual bool contains(Object element);

    virtual E elementAt(int index);

    virtual bool every(bool test(E ) );

    template<typename T>  virtual Iterable<T> expand(Iterable<T> f(E ) );

    virtual E first();

    virtual E firstWhere(E orElse() , bool test(E ) );

    template<typename T>  virtual T fold(T combine(E element, T previousValue) , T initialValue);

    virtual Iterable<E> followedBy(Iterable<E> other);

    virtual void forEach(void f(E ) );

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual Iterator<E> iterator();

    virtual String join(String separator);

    virtual E last();

    virtual E lastWhere(E orElse() , bool test(E ) );

    virtual int length();

    template<typename T>  virtual Iterable<T> map(T f(E ) );

    virtual E reduce(E combine(E element, E value) );

    template<typename T>  virtual Iterable<T> retype();

    virtual E single();

    virtual E singleWhere(E orElse() , bool test(E ) );

    virtual Iterable<E> skip(int n);

    virtual Iterable<E> skipWhile(bool test(E ) );

    virtual Iterable<E> take(int n);

    virtual Iterable<E> takeWhile(bool test(E ) );

    virtual List<E> toList(bool growable);

    virtual Set<E> toSet();

    virtual Iterable<E> where(bool test(E ) );

    template<typename T>  virtual Iterable<T> whereType();

    virtual String toString();

private:

    virtual Iterable<E> _base();
     _DelegatingIterableBaseCls();
};
template<typename E> using _DelegatingIterableBase = std::shared_ptr<_DelegatingIterableBaseCls<E>>;

template<typename E> class DelegatingIterableCls : public _DelegatingIterableBaseCls<E> {
public:

     DelegatingIterableCls(Iterable<E> base);

    template<typename E>  static Iterable<E> typed(Iterable base);

private:
    Iterable<E> _base;


};
template<typename E> using DelegatingIterable = std::shared_ptr<DelegatingIterableCls<E>>;

template<typename E> class DelegatingListCls : public _DelegatingIterableBaseCls<E> {
public:

     DelegatingListCls(List<E> base);

    template<typename E>  static List<E> typed(List base);

    virtual E operator[](int index);

    virtual void operator[]=(int index, E value);

    virtual List<E> operator+(List<E> other);

    virtual void add(E value);

    virtual void addAll(Iterable<E> iterable);

    virtual Map<int, E> asMap();

    template<typename T>  virtual List<T> cast();

    virtual void clear();

    virtual void fillRange(int end, E fillValue, int start);

    virtual void  first(E value);

    virtual Iterable<E> getRange(int end, int start);

    virtual int indexOf(E element, int start);

    virtual int indexWhere(int start, bool test(E ) );

    virtual void insert(E element, int index);

    virtual void insertAll(int index, Iterable<E> iterable);

    virtual void  last(E value);

    virtual int lastIndexOf(E element, int start);

    virtual int lastIndexWhere(int start, bool test(E ) );

    virtual void  length(int newLength);

    virtual bool remove(Object value);

    virtual E removeAt(int index);

    virtual E removeLast();

    virtual void removeRange(int end, int start);

    virtual void removeWhere(bool test(E ) );

    virtual void replaceRange(int end, Iterable<E> iterable, int start);

    virtual void retainWhere(bool test(E ) );

    template<typename T>  virtual List<T> retype();

    virtual Iterable<E> reversed();

    virtual void setAll(int index, Iterable<E> iterable);

    virtual void setRange(int end, Iterable<E> iterable, int skipCount, int start);

    virtual void shuffle(Random random);

    virtual void sort(int compare(E , E ) );

    virtual List<E> sublist(int end, int start);

private:
    List<E> _base;


};
template<typename E> using DelegatingList = std::shared_ptr<DelegatingListCls<E>>;

template<typename E> class DelegatingSetCls : public _DelegatingIterableBaseCls<E> {
public:

     DelegatingSetCls(Set<E> base);

    template<typename E>  static Set<E> typed(Set base);

    virtual bool add(E value);

    virtual void addAll(Iterable<E> elements);

    template<typename T>  virtual Set<T> cast();

    virtual void clear();

    virtual bool containsAll(Iterable<Object> other);

    virtual Set<E> difference(Set<Object> other);

    virtual Set<E> intersection(Set<Object> other);

    virtual E lookup(Object element);

    virtual bool remove(Object value);

    virtual void removeAll(Iterable<Object> elements);

    virtual void removeWhere(bool test(E ) );

    virtual void retainAll(Iterable<Object> elements);

    template<typename T>  virtual Set<T> retype();

    virtual void retainWhere(bool test(E ) );

    virtual Set<E> union(Set<E> other);

    virtual Set<E> toSet();

private:
    Set<E> _base;


};
template<typename E> using DelegatingSet = std::shared_ptr<DelegatingSetCls<E>>;

template<typename E> class DelegatingQueueCls : public _DelegatingIterableBaseCls<E> {
public:

     DelegatingQueueCls(Queue<E> queue);

    template<typename E>  static Queue<E> typed(Queue base);

    virtual void add(E value);

    virtual void addAll(Iterable<E> iterable);

    virtual void addFirst(E value);

    virtual void addLast(E value);

    template<typename T>  virtual Queue<T> cast();

    virtual void clear();

    virtual bool remove(Object object);

    virtual void removeWhere(bool test(E ) );

    virtual void retainWhere(bool test(E ) );

    template<typename T>  virtual Queue<T> retype();

    virtual E removeFirst();

    virtual E removeLast();

private:
    Queue<E> _base;


};
template<typename E> using DelegatingQueue = std::shared_ptr<DelegatingQueueCls<E>>;

template<typename K, typename V> class DelegatingMapCls : public ObjectCls {
public:

     DelegatingMapCls(Map<K, V> base);

    template<typename K, typename V>  static Map<K, V> typed(Map base);

    virtual V operator[](Object key);

    virtual void operator[]=(K key, V value);

    virtual void addAll(Map<K, V> other);

    virtual void addEntries(Iterable<MapEntry<K, V>> entries);

    virtual void clear();

    template<typename K2, typename V2>  virtual Map<K2, V2> cast();

    virtual bool containsKey(Object key);

    virtual bool containsValue(Object value);

    virtual Iterable<MapEntry<K, V>> entries();

    virtual void forEach(void f(K , V ) );

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual Iterable<K> keys();

    virtual int length();

    template<typename K2, typename V2>  virtual Map<K2, V2> map(MapEntry<K2, V2> transform(K , V ) );

    virtual V putIfAbsent(V ifAbsent() , K key);

    virtual V remove(Object key);

    virtual void removeWhere(bool test(K , V ) );

    template<typename K2, typename V2>  virtual Map<K2, V2> retype();

    virtual Iterable<V> values();

    virtual String toString();

    virtual V update(V ifAbsent() , K key, V update(V ) );

    virtual void updateAll(V update(K , V ) );

private:
    Map<K, V> _base;


};
template<typename K, typename V> using DelegatingMap = std::shared_ptr<DelegatingMapCls<K, V>>;

template<typename E> class MapKeySetCls : public _DelegatingIterableBaseCls<E> {
public:

     MapKeySetCls(Map<E, dynamic> _baseMap);
    template<typename T>  virtual Set<T> cast();

    virtual bool contains(Object element);

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual int length();

    virtual String toString();

    virtual bool containsAll(Iterable<Object> other);

    virtual Set<E> difference(Set<Object> other);

    virtual Set<E> intersection(Set<Object> other);

    virtual E lookup(Object element);

    template<typename T>  virtual Set<T> retype();

    virtual Set<E> union(Set<E> other);

private:
    Map<E, dynamic> _baseMap;


    virtual Iterable<E> _base();

};
template<typename E> using MapKeySet = std::shared_ptr<MapKeySetCls<E>>;

template<typename K, typename V> class MapValueSetCls : public _DelegatingIterableBaseCls<V> {
public:

     MapValueSetCls(Map<K, V> _baseMap, K Function(V ) _keyForValue);
    template<typename T>  virtual Set<T> cast();

    virtual bool contains(Object element);

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual int length();

    virtual String toString();

    virtual bool add(V value);

    virtual void addAll(Iterable<V> elements);

    virtual void clear();

    virtual bool containsAll(Iterable<Object> other);

    virtual Set<V> difference(Set<Object> other);

    virtual Set<V> intersection(Set<Object> other);

    virtual V lookup(Object element);

    virtual bool remove(Object element);

    virtual void removeAll(Iterable<Object> elements);

    virtual void removeWhere(bool test(V ) );

    virtual void retainAll(Iterable<Object> elements);

    virtual void retainWhere(bool test(V ) );

    template<typename T>  virtual Set<T> retype();

    virtual Set<V> union(Set<V> other);

private:
    Map<K, V> _baseMap;

    K Function(V ) _keyForValue;


    virtual Iterable<V> _base();

};
template<typename K, typename V> using MapValueSet = std::shared_ptr<MapValueSetCls<K, V>>;


#endif