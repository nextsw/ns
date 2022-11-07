#ifndef MAP_H
#define MAP_H
#include <memory>




class Map<K, V> {
public:

    external  Map();

    void  from(Map other);

    void  of(Map<K, V> other);

    external void  unmodifiable(Map<dynamic, dynamic> other);

    void  identity();

    void  fromIterable(Iterable iterable, FunctionType key, FunctionType value);

    void  fromIterables(Iterable<K> keys, Iterable<V> values);

    static Map<K2, V2> castFrom<K, V, K2, V2>(Map<K, V> source);

    void  fromEntries(Iterable<MapEntry<K, V>> entries);

    Map<RK, RV> cast<RK, RV>();

    bool containsValue(Object value);

    bool containsKey(Object key);

    V [](Object key);

    void []=(K key, V value);

    Iterable<MapEntry<K, V>> entries();

    Map<K2, V2> map<K2, V2>(FunctionType convert);

    void addEntries(Iterable<MapEntry<K, V>> newEntries);

    V update(FunctionType ifAbsent, K key, FunctionType update);

    void updateAll(FunctionType update);

    void removeWhere(FunctionType test);

    V putIfAbsent(FunctionType ifAbsent, K key);

    void addAll(Map<K, V> other);

    V remove(Object key);

    void clear();

    void forEach(FunctionType action);

    Iterable<K> keys();

    Iterable<V> values();

    int length();

    bool isEmpty();

    bool isNotEmpty();

private:

};

class MapEntry<K, V> {
public:
    K key;

    V value;


     MapEntry(K key, V value);

    String toString();

private:

    void  _(K key, V value);

};

#endif