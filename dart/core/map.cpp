#include "map.hpp"
template<typename K, typename V> Map<K2, V2> MapCls<K, V>::castFromtemplate<typename K, typename V, typename K2, typename V2> (Map<K, V> source) {
    return <K, V, K2, V2>make<CastMapCls>(source);
}

template<typename K, typename V> void MapCls<K, V>::fromEntries(Iterable<MapEntry<K, V>> entries) {
    return _c1;
}

template<typename K, typename V> String MapEntryCls<K, V>::toString() {
    return __s("MapEntry($key: $value)");
}
