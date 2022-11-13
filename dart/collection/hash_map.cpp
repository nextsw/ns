#include "hash_map.hpp"
bool _defaultEquals(Object a, Object b) {
    return a == b;
}

int _defaultHashCode(Object a) {
    return a->hashCode();
}

template<typename K, typename V>
void HashMapCls<K, V>::from(Map<Object, Object> other) {
    HashMap<K, V> result = <K, V>make<HashMapCls>();
    other->forEach([=] (Object k,Object v) {
        result[as<K>(k)] = as<V>(v);
    });
    return result;
}

template<typename K, typename V>
void HashMapCls<K, V>::of(Map<K, V> other) {
    return _c1;
}

template<typename K, typename V>
void HashMapCls<K, V>::fromIterable(Iterable<any> iterable, std::function<K(Object element)> key, std::function<V(Object element)> value) {
    auto _c1 = <K, V>make<HashMapCls>();_c1.addAll(other);HashMap<K, V> map = <K, V>make<HashMapCls>();
    MapBaseCls->_fillMapWithMappedIterable(map, iterable, key, value);
    return map;
}

template<typename K, typename V>
void HashMapCls<K, V>::fromIterables(Iterable<K> keys, Iterable<V> values) {
    HashMap<K, V> map = <K, V>make<HashMapCls>();
    MapBaseCls->_fillMapWithIterables(map, keys, values);
    return map;
}

template<typename K, typename V>
void HashMapCls<K, V>::fromEntries(Iterable<MapEntry<K, V>> entries) {
    return _c1;
}
