#include "maps.hpp"
string MapBase::mapToString(Map<Object, Object> m) {
    if (_isToStringVisiting(m)) {
        return "{...}";
    }
    auto result = StringBuffer();
    ;
    return result.toString();
}

Object MapBase::_id(Object x) {
    return x;
}

void MapBase::_fillMapWithMappedIterable(Iterable<Object> iterable, FunctionType key, Map<Object, Object> map, FunctionType value) {
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

void MapBase::_fillMapWithIterables(Iterable<Object> keys, Map<Object, Object> map, Iterable<Object> values) {
    Iterator<Object> keyIterator = keys.iterator;
    Iterator<Object> valueIterator = values.iterator;
    bool hasNextKey = keyIterator.moveNext();
    bool hasNextValue = valueIterator.moveNext();
    while (hasNextKey && hasNextValue) {
        map[keyIterator.current] = valueIterator.current;
        hasNextKey = keyIterator.moveNext();
        hasNextValue = valueIterator.moveNext();
    }
    if (hasNextKey || hasNextValue) {
        ;
    }
}

Map<RK, RV> MapMixin::cast<RK, RV>() {
    return Map.<K, V, RK, RV>castFrom(this);
}

void MapMixin::forEach(FunctionType action) {
    for (K key : keys) {
        action(key, ();
    }
}

void MapMixin::addAll(Map<K, V> other) {
    other.forEach();
}

bool MapMixin::containsValue(Object value) {
    for (K key : keys) {
        if (this[key] == value)         {
            return true;
        }
    }
    return false;
}

V MapMixin::putIfAbsent(FunctionType ifAbsent, K key) {
    if (containsKey(key)) {
        return (;
    }
    return this[key] = ifAbsent();
}

V MapMixin::update(FunctionType ifAbsent, K key, FunctionType update) {
    if (this.containsKey(key)) {
        return this[key] = update(();
    }
    if (ifAbsent != nullptr) {
        return this[key] = ifAbsent();
    }
    ;
}

void MapMixin::updateAll(FunctionType update) {
    for (auto key : this.keys) {
        this[key] = update(key, ();
    }
}

Iterable<MapEntry<K, V>> MapMixin::entries() {
    return keys.map();
}

Map<K2, V2> MapMixin::map<K2, V2>(FunctionType transform) {
    auto result = ;
    for (auto key : this.keys) {
        auto entry = transform(key, ();
        result[entry.key] = entry.value;
    }
    return result;
}

void MapMixin::addEntries(Iterable<MapEntry<K, V>> newEntries) {
    for (auto entry : newEntries) {
        this[entry.key] = entry.value;
    }
}

void MapMixin::removeWhere(FunctionType test) {
    auto keysToRemove = ;
    for (auto key : keys) {
        if (test(key, ())         {
            keysToRemove.add(key);
        }
    }
    for (auto key : keysToRemove) {
        this.remove(key);
    }
}

bool MapMixin::containsKey(Object key) {
    return keys.contains(key);
}

int MapMixin::length() {
    return keys.length;
}

bool MapMixin::isEmpty() {
    return keys.isEmpty;
}

bool MapMixin::isNotEmpty() {
    return keys.isNotEmpty;
}

Iterable<V> MapMixin::values() {
    return <K, V>_MapBaseValueIterable(this);
}

String MapMixin::toString() {
    return MapBase.mapToString(this);
}

int _MapBaseValueIterable::length() {
    return _map.length;
}

bool _MapBaseValueIterable::isEmpty() {
    return _map.isEmpty;
}

bool _MapBaseValueIterable::isNotEmpty() {
    return _map.isNotEmpty;
}

V _MapBaseValueIterable::first() {
    return (;
}

V _MapBaseValueIterable::single() {
    return (;
}

V _MapBaseValueIterable::last() {
    return (;
}

Iterator<V> _MapBaseValueIterable::iterator() {
    return <K, V>_MapBaseValueIterator(_map);
}

bool _MapBaseValueIterator::moveNext() {
    if (_keys.moveNext()) {
        _current = _map[_keys.current];
        return true;
    }
    _current = nullptr;
    return false;
}

V _MapBaseValueIterator::current() {
    return (;
}

_MapBaseValueIterator::_MapBaseValueIterator(Map<K, V> map) {
    {
        _map = map;
        _keys = map.keys.iterator;
    }
}

void _UnmodifiableMapMixin::[]=(K key, V value) {
    ;
}

void _UnmodifiableMapMixin::addAll(Map<K, V> other) {
    ;
}

void _UnmodifiableMapMixin::addEntries(Iterable<MapEntry<K, V>> entries) {
    ;
}

void _UnmodifiableMapMixin::clear() {
    ;
}

V _UnmodifiableMapMixin::remove(Object key) {
    ;
}

void _UnmodifiableMapMixin::removeWhere(FunctionType test) {
    ;
}

V _UnmodifiableMapMixin::putIfAbsent(FunctionType ifAbsent, K key) {
    ;
}

V _UnmodifiableMapMixin::update(FunctionType ifAbsent, K key, FunctionType update) {
    ;
}

void _UnmodifiableMapMixin::updateAll(FunctionType update) {
    ;
}

MapView::MapView(Map<K, V> map) {
    {
        _map = map;
    }
}

Map<RK, RV> MapView::cast<RK, RV>() {
    return _map.<RK, RV>cast();
}

V MapView::[](Object key) {
    return _map[key];
}

void MapView::[]=(K key, V value) {
    _map[key] = value;
}

void MapView::addAll(Map<K, V> other) {
    _map.addAll(other);
}

void MapView::clear() {
    _map.clear();
}

V MapView::putIfAbsent(FunctionType ifAbsent, K key) {
    return _map.putIfAbsent(key, ifAbsent);
}

bool MapView::containsKey(Object key) {
    return _map.containsKey(key);
}

bool MapView::containsValue(Object value) {
    return _map.containsValue(value);
}

void MapView::forEach(FunctionType action) {
    _map.forEach(action);
}

bool MapView::isEmpty() {
    return _map.isEmpty;
}

bool MapView::isNotEmpty() {
    return _map.isNotEmpty;
}

int MapView::length() {
    return _map.length;
}

Iterable<K> MapView::keys() {
    return _map.keys;
}

V MapView::remove(Object key) {
    return _map.remove(key);
}

String MapView::toString() {
    return _map.toString();
}

Iterable<V> MapView::values() {
    return _map.values;
}

Iterable<MapEntry<K, V>> MapView::entries() {
    return _map.entries;
}

void MapView::addEntries(Iterable<MapEntry<K, V>> entries) {
    _map.addEntries(entries);
}

Map<K2, V2> MapView::map<K2, V2>(FunctionType transform) {
    return _map.<K2, V2>map(transform);
}

V MapView::update(FunctionType ifAbsent, K key, FunctionType update) {
    return _map.update(key, updateifAbsent);
}

void MapView::updateAll(FunctionType update) {
    _map.updateAll(update);
}

void MapView::removeWhere(FunctionType test) {
    _map.removeWhere(test);
}

UnmodifiableMapView::UnmodifiableMapView(Map<K, V> map) {
    {
        super(map);
    }
}

Map<RK, RV> UnmodifiableMapView::cast<RK, RV>() {
    return <RK, RV>UnmodifiableMapView(_map.<RK, RV>cast());
}
