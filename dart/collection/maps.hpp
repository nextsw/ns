#ifndef MAPS_H
#define MAPS_H
#include <memory>




class MapBase<K, V> : MapMixin<K, V> {
public:

    static String mapToString(Map<Object, Object> m);

private:

    static Object _id(Object x);

    static void _fillMapWithMappedIterable(Iterable<Object> iterable, FunctionType key, Map<Object, Object> map, FunctionType value);

    static void _fillMapWithIterables(Iterable<Object> keys, Map<Object, Object> map, Iterable<Object> values);

};

class MapMixin<K, V> {
public:

    Iterable<K> keys();

    V [](Object key);

    void  []=(K key, V value);

    V remove(Object key);

    void clear();

    Map<RK, RV> cast<RK, RV>();

    void forEach(FunctionType action);

    void addAll(Map<K, V> other);

    bool containsValue(Object value);

    V putIfAbsent(FunctionType ifAbsent, K key);

    V update(FunctionType ifAbsent, K key, FunctionType update);

    void updateAll(FunctionType update);

    Iterable<MapEntry<K, V>> entries();

    Map<K2, V2> map<K2, V2>(FunctionType transform);

    void addEntries(Iterable<MapEntry<K, V>> newEntries);

    void removeWhere(FunctionType test);

    bool containsKey(Object key);

    int length();

    bool isEmpty();

    bool isNotEmpty();

    Iterable<V> values();

    String toString();

private:

};

class UnmodifiableMapBase<K, V> {
public:

private:

};

class _MapBaseValueIterable<K, V> : EfficientLengthIterable<V> {
public:

    int length();

    bool isEmpty();

    bool isNotEmpty();

    V first();

    V single();

    V last();

    Iterator<V> iterator();

private:
    Map<K, V> _map;


     _MapBaseValueIterable(Map<K, V> _map);

};

class _MapBaseValueIterator<K, V> {
public:

    bool moveNext();

    V current();

private:
    Iterator<K> _keys;

    Map<K, V> _map;

    V _current;


     _MapBaseValueIterator(Map<K, V> map);

};

class _UnmodifiableMapMixin<K, V> {
public:

    void []=(K key, V value);

    void addAll(Map<K, V> other);

    void addEntries(Iterable<MapEntry<K, V>> entries);

    void clear();

    V remove(Object key);

    void removeWhere(FunctionType test);

    V putIfAbsent(FunctionType ifAbsent, K key);

    V update(FunctionType ifAbsent, K key, FunctionType update);

    void updateAll(FunctionType update);

private:

};

class MapView<K, V> {
public:

     MapView(Map<K, V> map);

    Map<RK, RV> cast<RK, RV>();

    V [](Object key);

    void []=(K key, V value);

    void addAll(Map<K, V> other);

    void clear();

    V putIfAbsent(FunctionType ifAbsent, K key);

    bool containsKey(Object key);

    bool containsValue(Object value);

    void forEach(FunctionType action);

    bool isEmpty();

    bool isNotEmpty();

    int length();

    Iterable<K> keys();

    V remove(Object key);

    String toString();

    Iterable<V> values();

    Iterable<MapEntry<K, V>> entries();

    void addEntries(Iterable<MapEntry<K, V>> entries);

    Map<K2, V2> map<K2, V2>(FunctionType transform);

    V update(FunctionType ifAbsent, K key, FunctionType update);

    void updateAll(FunctionType update);

    void removeWhere(FunctionType test);

private:
    Map<K, V> _map;


};

class UnmodifiableMapView<K, V> : MapView<K, V> {
public:

     UnmodifiableMapView(Map<K, V> map);

    Map<RK, RV> cast<RK, RV>();

private:

};

#endif