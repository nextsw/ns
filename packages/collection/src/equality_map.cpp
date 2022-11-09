#include "equality_map.hpp"
template<typename K, typename V> EqualityMapCls<K, V>::EqualityMapCls(Equality<K> equality) {
}

template<typename K, typename V> void EqualityMapCls<K, V>::from(Equality<K> equality, Map<K, V> other) {
    addAll(other);
}
