#ifndef DART_CORE_MAP
#define DART_CORE_MAP
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename K, typename V>
class MapCls : public ObjectCls {
public:

     MapCls();
    virtual void  from(Map other);
    virtual void  of(Map<K, V> other);
    void  unmodifiable(Map<dynamic, dynamic> other);
    virtual void  identity();
    virtual void  fromIterable(Iterable iterable, std::function<K(dynamic element)> key, std::function<V(dynamic element)> value);
    virtual void  fromIterables(Iterable<K> keys, Iterable<V> values);
    template<typename K, typename V, typename K2, typename V2>
 static Map<K2, V2> castFrom(Map<K, V> source);

    virtual void  fromEntries(Iterable<MapEntry<K, V>> entries);

    template<typename RK, typename RV>
 virtual Map<RK, RV> cast();
    virtual bool containsValue(Object value);
    virtual bool containsKey(Object key);
    virtual V operator[](Object key);
    virtual void operator[]=(K key, V value);
    virtual Iterable<MapEntry<K, V>> entries();
    template<typename K2, typename V2>
 virtual Map<K2, V2> map(std::function<MapEntry<K2, V2>(K key, V value)> convert);
    virtual void addEntries(Iterable<MapEntry<K, V>> newEntries);
    virtual V update(K key, std::function<V(V value)> update, std::function<V()> ifAbsent);
    virtual void updateAll(std::function<V(K key, V value)> update);
    virtual void removeWhere(std::function<bool(K key, V value)> test);
    virtual V putIfAbsent(K key, std::function<V()> ifAbsent);
    virtual void addAll(Map<K, V> other);
    virtual V remove(Object key);
    virtual void clear();
    virtual void forEach(std::function<void(K key, V value)> action);
    virtual Iterable<K> keys();
    virtual Iterable<V> values();
    virtual int length();
    virtual bool isEmpty();
    virtual bool isNotEmpty();
private:

};
template<typename K, typename V>
using Map = std::shared_ptr<MapCls<K, V>>;

template<typename K, typename V>
class MapEntryCls : public ObjectCls {
public:
    K key;

    V value;


     MapEntryCls(K key, V value);
    virtual String toString();

private:

    virtual void  _(K key, V value);
};
template<typename K, typename V>
using MapEntry = std::shared_ptr<MapEntryCls<K, V>>;


#endif