#include "maps.hpp"
template<typename K, typename V> String MapBaseCls<K, V>::mapToString(Map<Object, Object> m) {
    if (_isToStringVisiting(m)) {
        return __s("{...}");
    }
    auto result = make<StringBufferCls>();
    try {
        _toStringVisiting->add(m);
        result->write(__s("{"));
        bool first = true;
        m->forEach([=] (Object k,Object v) {
            if (!first) {
                result->write(__s(", "));
            }
            first = false;
            result->write(k);
            result->write(__s(": "));
            result->write(v);
        });
        result->write(__s("}"));
    } finally {
        assert(identical(_toStringVisiting->last, m));
        _toStringVisiting->removeLast();
    };
    return result->toString();
}

template<typename K, typename V> Object MapBaseCls<K, V>::_id(Object x) {
    return x;
}

template<typename K, typename V> void MapBaseCls<K, V>::_fillMapWithMappedIterable(Iterable<Object> iterable, Object key(Object element) , Map<Object, Object> map, Object value(Object element) ) {
    key = _id;
    value = _id;
    if (key == nullptr)     {
        ;
    }
    if (value == nullptr)     {
        ;
    }
    for (auto element : iterable) {
        map[key(element)] = value(element);
    }
}

template<typename K, typename V> void MapBaseCls<K, V>::_fillMapWithIterables(Iterable<Object> keys, Map<Object, Object> map, Iterable<Object> values) {
    Iterator<Object> keyIterator = keys->iterator;
    Iterator<Object> valueIterator = values->iterator;
    bool hasNextKey = keyIterator->moveNext();
    bool hasNextValue = valueIterator->moveNext();
    while (hasNextKey && hasNextValue) {
        map[keyIterator->current] = valueIterator->current;
        hasNextKey = keyIterator->moveNext();
        hasNextValue = valueIterator->moveNext();
    }
    if (hasNextKey || hasNextValue) {
        ;
    }
}

template<typename K, typename V> Map<RK, RV> MapMixinCls<K, V>::casttemplate<typename RK, typename RV> () {
    return MapCls-><K, V, RK, RV>castFrom(this);
}

template<typename K, typename V> void MapMixinCls<K, V>::forEach(void action(K key, V value) ) {
    for (K key : keys()) {
        action(key, as<V>(this[key]));
    }
}

template<typename K, typename V> void MapMixinCls<K, V>::addAll(Map<K, V> other) {
    other->forEach([=] (K key,V value) {
        this[key] = value;
    });
}

template<typename K, typename V> bool MapMixinCls<K, V>::containsValue(Object value) {
    for (K key : keys()) {
        if (this[key] == value)         {
            return true;
        }
    }
    return false;
}

template<typename K, typename V> V MapMixinCls<K, V>::putIfAbsent(V ifAbsent() , K key) {
    if (containsKey(key)) {
        return as<V>(this[key]);
    }
    return this[key] = ifAbsent();
}

template<typename K, typename V> V MapMixinCls<K, V>::update(V ifAbsent() , K key, V update(V value) ) {
    if (this->containsKey(key)) {
        return this[key] = update(as<V>(this[key]));
    }
    if (ifAbsent != nullptr) {
        return this[key] = ifAbsent();
    }
    ;
}

template<typename K, typename V> void MapMixinCls<K, V>::updateAll(V update(K key, V value) ) {
    for (auto key : this->keys) {
        this[key] = update(key, as<V>(this[key]));
    }
}

template<typename K, typename V> Iterable<MapEntry<K, V>> MapMixinCls<K, V>::entries() {
    return keys()->map([=] (K key)     {
        <K, V>make<MapEntryCls>(key, as<V>(this[key]));
    });
}

template<typename K, typename V> Map<K2, V2> MapMixinCls<K, V>::maptemplate<typename K2, typename V2> (MapEntry<K2, V2> transform(K key, V value) ) {
    auto result = makeMap(makeList(), makeList();
    for (auto key : this->keys) {
        auto entry = transform(key, as<V>(this[key]));
        result[entry->key] = entry->value;
    }
    return result;
}

template<typename K, typename V> void MapMixinCls<K, V>::addEntries(Iterable<MapEntry<K, V>> newEntries) {
    for (auto entry : newEntries) {
        this[entry->key] = entry->value;
    }
}

template<typename K, typename V> void MapMixinCls<K, V>::removeWhere(bool test(K key, V value) ) {
    auto keysToRemove = makeList();
    for (auto key : keys()) {
        if (test(key, as<V>(this[key])))         {
            keysToRemove->add(key);
        }
    }
    for (auto key : keysToRemove) {
        this->remove(key);
    }
}

template<typename K, typename V> bool MapMixinCls<K, V>::containsKey(Object key) {
    return keys()->contains(key);
}

template<typename K, typename V> int MapMixinCls<K, V>::length() {
    return keys()->length();
}

template<typename K, typename V> bool MapMixinCls<K, V>::isEmpty() {
    return keys()->isEmpty();
}

template<typename K, typename V> bool MapMixinCls<K, V>::isNotEmpty() {
    return keys()->isNotEmpty();
}

template<typename K, typename V> Iterable<V> MapMixinCls<K, V>::values() {
    return <K, V>make<_MapBaseValueIterableCls>(this);
}

template<typename K, typename V> String MapMixinCls<K, V>::toString() {
    return MapBaseCls->mapToString(this);
}

template<typename K, typename V> int _MapBaseValueIterableCls<K, V>::length() {
    return _map->length();
}

template<typename K, typename V> bool _MapBaseValueIterableCls<K, V>::isEmpty() {
    return _map->isEmpty();
}

template<typename K, typename V> bool _MapBaseValueIterableCls<K, V>::isNotEmpty() {
    return _map->isNotEmpty();
}

template<typename K, typename V> V _MapBaseValueIterableCls<K, V>::first() {
    return as<V>(_map[_map->keys()->first()]);
}

template<typename K, typename V> V _MapBaseValueIterableCls<K, V>::single() {
    return as<V>(_map[_map->keys()->single()]);
}

template<typename K, typename V> V _MapBaseValueIterableCls<K, V>::last() {
    return as<V>(_map[_map->keys()->last()]);
}

template<typename K, typename V> Iterator<V> _MapBaseValueIterableCls<K, V>::iterator() {
    return <K, V>make<_MapBaseValueIteratorCls>(_map);
}

template<typename K, typename V> bool _MapBaseValueIteratorCls<K, V>::moveNext() {
    if (_keys->moveNext()) {
        _current = _map[_keys->current()];
        return true;
    }
    _current = nullptr;
    return false;
}

template<typename K, typename V> V _MapBaseValueIteratorCls<K, V>::current() {
    return as<V>(_current);
}

template<typename K, typename V> _MapBaseValueIteratorCls<K, V>::_MapBaseValueIteratorCls(Map<K, V> map) {
    {
        _map = map;
        _keys = map->keys->iterator;
    }
}

template<typename K, typename V> void _UnmodifiableMapMixinCls<K, V>::[]=(K key, V value) {
    ;
}

template<typename K, typename V> void _UnmodifiableMapMixinCls<K, V>::addAll(Map<K, V> other) {
    ;
}

template<typename K, typename V> void _UnmodifiableMapMixinCls<K, V>::addEntries(Iterable<MapEntry<K, V>> entries) {
    ;
}

template<typename K, typename V> void _UnmodifiableMapMixinCls<K, V>::clear() {
    ;
}

template<typename K, typename V> V _UnmodifiableMapMixinCls<K, V>::remove(Object key) {
    ;
}

template<typename K, typename V> void _UnmodifiableMapMixinCls<K, V>::removeWhere(bool test(K key, V value) ) {
    ;
}

template<typename K, typename V> V _UnmodifiableMapMixinCls<K, V>::putIfAbsent(V ifAbsent() , K key) {
    ;
}

template<typename K, typename V> V _UnmodifiableMapMixinCls<K, V>::update(V ifAbsent() , K key, V update(V value) ) {
    ;
}

template<typename K, typename V> void _UnmodifiableMapMixinCls<K, V>::updateAll(V update(K key, V value) ) {
    ;
}

template<typename K, typename V> MapViewCls<K, V>::MapViewCls(Map<K, V> map) {
    {
        _map = map;
    }
}

template<typename K, typename V> Map<RK, RV> MapViewCls<K, V>::casttemplate<typename RK, typename RV> () {
    return _map-><RK, RV>cast();
}

template<typename K, typename V> V MapViewCls<K, V>::[](Object key) {
    return _map[key];
}

template<typename K, typename V> void MapViewCls<K, V>::[]=(K key, V value) {
    _map[key] = value;
}

template<typename K, typename V> void MapViewCls<K, V>::addAll(Map<K, V> other) {
    _map->addAll(other);
}

template<typename K, typename V> void MapViewCls<K, V>::clear() {
    _map->clear();
}

template<typename K, typename V> V MapViewCls<K, V>::putIfAbsent(V ifAbsent() , K key) {
    return _map->putIfAbsent(key, ifAbsent);
}

template<typename K, typename V> bool MapViewCls<K, V>::containsKey(Object key) {
    return _map->containsKey(key);
}

template<typename K, typename V> bool MapViewCls<K, V>::containsValue(Object value) {
    return _map->containsValue(value);
}

template<typename K, typename V> void MapViewCls<K, V>::forEach(void action(K key, V value) ) {
    _map->forEach(action);
}

template<typename K, typename V> bool MapViewCls<K, V>::isEmpty() {
    return _map->isEmpty();
}

template<typename K, typename V> bool MapViewCls<K, V>::isNotEmpty() {
    return _map->isNotEmpty();
}

template<typename K, typename V> int MapViewCls<K, V>::length() {
    return _map->length();
}

template<typename K, typename V> Iterable<K> MapViewCls<K, V>::keys() {
    return _map->keys();
}

template<typename K, typename V> V MapViewCls<K, V>::remove(Object key) {
    return _map->remove(key);
}

template<typename K, typename V> String MapViewCls<K, V>::toString() {
    return _map->toString();
}

template<typename K, typename V> Iterable<V> MapViewCls<K, V>::values() {
    return _map->values();
}

template<typename K, typename V> Iterable<MapEntry<K, V>> MapViewCls<K, V>::entries() {
    return _map->entries();
}

template<typename K, typename V> void MapViewCls<K, V>::addEntries(Iterable<MapEntry<K, V>> entries) {
    _map->addEntries(entries());
}

template<typename K, typename V> Map<K2, V2> MapViewCls<K, V>::maptemplate<typename K2, typename V2> (MapEntry<K2, V2> transform(K key, V value) ) {
    return _map-><K2, V2>map(transform);
}

template<typename K, typename V> V MapViewCls<K, V>::update(V ifAbsent() , K key, V update(V value) ) {
    return _map->update(key, updateifAbsent);
}

template<typename K, typename V> void MapViewCls<K, V>::updateAll(V update(K key, V value) ) {
    _map->updateAll(update);
}

template<typename K, typename V> void MapViewCls<K, V>::removeWhere(bool test(K key, V value) ) {
    _map->removeWhere(test);
}

template<typename K, typename V> UnmodifiableMapViewCls<K, V>::UnmodifiableMapViewCls(Map<K, V> map) : MapView<K, V>(map) {
}

template<typename K, typename V> Map<RK, RV> UnmodifiableMapViewCls<K, V>::casttemplate<typename RK, typename RV> () {
    return <RK, RV>make<UnmodifiableMapViewCls>(_map-><RK, RV>cast());
}
