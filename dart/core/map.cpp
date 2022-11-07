#include "map.hpp"
Map<K2, V2> Map::castFrom<K, V, K2, V2>(Map<K, V> source) {
    return <K, V, K2, V2>CastMap(source);
}

void Map::fromEntries(Iterable<MapEntry<K, V>> entries) {
    return ;
}

String MapEntry::toString() {
    return "MapEntry($key: $value)";
}
