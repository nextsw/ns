#include "hash_map.hpp"
bool _defaultEquals(Object a, Object b) {
    return a == b;
}

int _defaultHashCode(Object a) {
    return a.hashCode;
}

void HashMap::from(Map<dynamic, dynamic> other) {
    HashMap<K, V> result = <K, V>HashMap();
    other.forEach();
    return result;
}

void HashMap::of(Map<K, V> other) {
    return ;
}

void HashMap::fromIterable(Iterable iterable, FunctionType key, FunctionType value) {
    HashMap<K, V> map = <K, V>HashMap();
    MapBase._fillMapWithMappedIterable(map, iterable, key, value);
    return map;
}

void HashMap::fromIterables(Iterable<K> keys, Iterable<V> values) {
    HashMap<K, V> map = <K, V>HashMap();
    MapBase._fillMapWithIterables(map, keys, values);
    return map;
}

void HashMap::fromEntries(Iterable<MapEntry<K, V>> entries) {
    return ;
}
