#include "linked_hash_map.hpp"
template<typename K, typename V>
void LinkedHashMapCls<K, V>::from(Map<Object, Object> other) {
    LinkedHashMap<K, V> result = <K, V>make<LinkedHashMapCls>();
    other->forEach([=] (Object k,Object v) {
        result[as<K>(k)] = as<V>(v);
    });
    return result;
}

template<typename K, typename V>
void LinkedHashMapCls<K, V>::of(Map<K, V> other) {
    return _c1;
}

template<typename K, typename V>
void LinkedHashMapCls<K, V>::fromIterable(Iterable<any> iterable, std::function<K(Object element)> key, std::function<V(Object element)> value) {
    auto _c1 = <K, V>make<LinkedHashMapCls>();_c1.addAll(other);LinkedHashMap<K, V> map = <K, V>make<LinkedHashMapCls>();
    MapBaseCls->_fillMapWithMappedIterable(map, iterable, key, value);
    return map;
}

template<typename K, typename V>
void LinkedHashMapCls<K, V>::fromIterables(Iterable<K> keys, Iterable<V> values) {
    LinkedHashMap<K, V> map = <K, V>make<LinkedHashMapCls>();
    MapBaseCls->_fillMapWithIterables(map, keys, values);
    return map;
}

template<typename K, typename V>
void LinkedHashMapCls<K, V>::fromEntries(Iterable<MapEntry<K, V>> entries) {
    return _c1;
}
