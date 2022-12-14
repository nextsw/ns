#ifndef DART_COLLECTION_MAPS
#define DART_COLLECTION_MAPS
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename K, typename V>
class MapBaseCls : public MapMixinCls<K, V> {
public:

    static String mapToString(Map<Object, Object> m);

private:

    static Object _id(Object x);

    static void _fillMapWithMappedIterable(Map<Object, Object> map, Iterable<Object> iterable, std::function<Object(Object element)> key, std::function<Object(Object element)> value);

    static void _fillMapWithIterables(Map<Object, Object> map, Iterable<Object> keys, Iterable<Object> values);

};
template<typename K, typename V>
using MapBase = std::shared_ptr<MapBaseCls<K, V>>;

template<typename K, typename V>
class MapMixinCls : public ObjectCls {
public:

    virtual Iterable<K> keys();
    virtual V operator[](Object key);
    virtual void  operator[]=(K key, V value);
    virtual V remove(Object key);
    virtual void clear();
    template<typename RK, typename RV>
 virtual Map<RK, RV> cast();

    virtual void forEach(std::function<void(K key, V value)> action);

    virtual void addAll(Map<K, V> other);

    virtual bool containsValue(Object value);

    virtual V putIfAbsent(K key, std::function<V()> ifAbsent);

    virtual V update(K key, std::function<V(V value)> update, std::function<V()> ifAbsent);

    virtual void updateAll(std::function<V(K key, V value)> update);

    virtual Iterable<MapEntry<K, V>> entries();

    template<typename K2, typename V2>
 virtual Map<K2, V2> map(std::function<MapEntry<K2, V2>(K key, V value)> transform);

    virtual void addEntries(Iterable<MapEntry<K, V>> newEntries);

    virtual void removeWhere(std::function<bool(K key, V value)> test);

    virtual bool containsKey(Object key);

    virtual int length();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual Iterable<V> values();

    virtual String toString();

private:

};
template<typename K, typename V>
using MapMixin = std::shared_ptr<MapMixinCls<K, V>>;

template<typename K, typename V>
class UnmodifiableMapBaseCls : public ObjectCls {
public:

private:

};
template<typename K, typename V>
using UnmodifiableMapBase = std::shared_ptr<UnmodifiableMapBaseCls<K, V>>;

template<typename K, typename V>
class _MapBaseValueIterableCls : public EfficientLengthIterableCls<V> {
public:

    virtual int length();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual V first();

    virtual V single();

    virtual V last();

    virtual Iterator<V> iterator();

private:
    Map<K, V> _map;


     _MapBaseValueIterableCls(Map<K, V> _map);
};
template<typename K, typename V>
using _MapBaseValueIterable = std::shared_ptr<_MapBaseValueIterableCls<K, V>>;

template<typename K, typename V>
class _MapBaseValueIteratorCls : public ObjectCls {
public:

    virtual bool moveNext();

    virtual V current();

private:
    Iterator<K> _keys;

    Map<K, V> _map;

    V _current;


     _MapBaseValueIteratorCls(Map<K, V> map);

};
template<typename K, typename V>
using _MapBaseValueIterator = std::shared_ptr<_MapBaseValueIteratorCls<K, V>>;

template<typename K, typename V>
class _UnmodifiableMapMixinCls : public ObjectCls {
public:

    virtual void operator[]=(K key, V value);

    virtual void addAll(Map<K, V> other);

    virtual void addEntries(Iterable<MapEntry<K, V>> entries);

    virtual void clear();

    virtual V remove(Object key);

    virtual void removeWhere(std::function<bool(K key, V value)> test);

    virtual V putIfAbsent(K key, std::function<V()> ifAbsent);

    virtual V update(K key, std::function<V(V value)> update, std::function<V()> ifAbsent);

    virtual void updateAll(std::function<V(K key, V value)> update);

private:

};
template<typename K, typename V>
using _UnmodifiableMapMixin = std::shared_ptr<_UnmodifiableMapMixinCls<K, V>>;

template<typename K, typename V>
class MapViewCls : public ObjectCls {
public:

     MapViewCls(Map<K, V> map);

    template<typename RK, typename RV>
 virtual Map<RK, RV> cast();

    virtual V operator[](Object key);

    virtual void operator[]=(K key, V value);

    virtual void addAll(Map<K, V> other);

    virtual void clear();

    virtual V putIfAbsent(K key, std::function<V()> ifAbsent);

    virtual bool containsKey(Object key);

    virtual bool containsValue(Object value);

    virtual void forEach(std::function<void(K key, V value)> action);

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual int length();

    virtual Iterable<K> keys();

    virtual V remove(Object key);

    virtual String toString();

    virtual Iterable<V> values();

    virtual Iterable<MapEntry<K, V>> entries();

    virtual void addEntries(Iterable<MapEntry<K, V>> entries);

    template<typename K2, typename V2>
 virtual Map<K2, V2> map(std::function<MapEntry<K2, V2>(K key, V value)> transform);

    virtual V update(K key, std::function<V(V value)> update, std::function<V()> ifAbsent);

    virtual void updateAll(std::function<V(K key, V value)> update);

    virtual void removeWhere(std::function<bool(K key, V value)> test);

private:
    Map<K, V> _map;


};
template<typename K, typename V>
using MapView = std::shared_ptr<MapViewCls<K, V>>;

template<typename K, typename V>
class UnmodifiableMapViewCls : public MapViewCls<K, V> {
public:

     UnmodifiableMapViewCls(Map<K, V> map);

    template<typename RK, typename RV>
 virtual Map<RK, RV> cast();

private:

};
template<typename K, typename V>
using UnmodifiableMapView = std::shared_ptr<UnmodifiableMapViewCls<K, V>>;


#endif