#include "linked_hash_map.hpp"
void LinkedHashMap::from(Map<dynamic, dynamic> other) {
    LinkedHashMap<K, V> result = <K, V>LinkedHashMap();
    other.forEach();
    return result;
}

void LinkedHashMap::of(Map<K, V> other) {
    return ;
}

void LinkedHashMap::fromIterable(Iterable iterable, FunctionType key, FunctionType value) {
    LinkedHashMap<K, V> map = <K, V>LinkedHashMap();
    MapBase._fillMapWithMappedIterable(map, iterable, key, value);
    return map;
}

void LinkedHashMap::fromIterables(Iterable<K> keys, Iterable<V> values) {
    LinkedHashMap<K, V> map = <K, V>LinkedHashMap();
    MapBase._fillMapWithIterables(map, keys, values);
    return map;
}

void LinkedHashMap::fromEntries(Iterable<MapEntry<K, V>> entries) {
    return ;
}
