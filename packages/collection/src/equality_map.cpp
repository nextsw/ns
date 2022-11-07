#include "equality_map.hpp"
EqualityMap::EqualityMap(Equality<K> equality) {
    {
        super(LinkedHashMap(equality.equals, equality.hash, equality.isValidKey));
    }
}

void EqualityMap::from(Equality<K> equality, Map<K, V> other) {
    addAll(other);
}
