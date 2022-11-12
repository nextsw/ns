#include "canonicalized_map.hpp"
template<typename C, typename K, typename V>
CanonicalizedMapCls<C, K, V>::CanonicalizedMapCls(std::function<C(K key)> canonicalize, std::function<bool(K key)> isValidKey) {
    {
            auto _c1 = toSet();    _c1.addAll(other);_canonicalize = canonicalize;
        _isValidKeyFn = isValidKey;
    }
}

template<typename C, typename K, typename V>
void CanonicalizedMapCls<C, K, V>::from(Map<K, V> other, std::function<C(K key)> canonicalize, std::function<bool(K key)> isValidKey) {
    addAll(other);
}

template<typename C, typename K, typename V>
V CanonicalizedMapCls<C, K, V>::[](Object key) {
    if (!_isValidKey(key)) {
        return nullptr;
    }
    auto pair = _base[_canonicalize(as<K>(key))];
    return pair?->value;
}

template<typename C, typename K, typename V>
void CanonicalizedMapCls<C, K, V>::[]=(K key, V value) {
    if (!_isValidKey(key)) {
        return;
    }
    _base[_canonicalize(key)] = make<MapEntryCls>(key, value);
}

template<typename C, typename K, typename V>
void CanonicalizedMapCls<C, K, V>::addAll(Map<K, V> other) {
    other->forEach([=] (Unknown  key,Unknown  value) {
        this[key] = value;
    });
}

template<typename C, typename K, typename V>
void CanonicalizedMapCls<C, K, V>::addEntries(Iterable<MapEntry<K, V>> entries) {
    return _base->addEntries(entries->map([=] (Unknown  e) {
        make<MapEntryCls>(_canonicalize(e->key), make<MapEntryCls>(e->key, e->value));
    }));
}

template<typename C, typename K, typename V>
template<typename K2, typename V2>
Map<K2, V2> CanonicalizedMapCls<C, K, V>::cast() {
    return _base-><K2, V2>cast();
}

template<typename C, typename K, typename V>
void CanonicalizedMapCls<C, K, V>::clear() {
    _base->clear();
}

template<typename C, typename K, typename V>
bool CanonicalizedMapCls<C, K, V>::containsKey(Object key) {
    if (!_isValidKey(key)) {
        return false;
    }
    return _base->containsKey(_canonicalize(as<K>(key)));
}

template<typename C, typename K, typename V>
bool CanonicalizedMapCls<C, K, V>::containsValue(Object value) {
    return _base->values->any([=] (Unknown  pair) {
        pair->value == value;
    });
}

template<typename C, typename K, typename V>
Iterable<MapEntry<K, V>> CanonicalizedMapCls<C, K, V>::entries() {
    return _base->entries->map([=] (Unknown  e) {
        make<MapEntryCls>(e->value->key, e->value->value);
    });
}

template<typename C, typename K, typename V>
void CanonicalizedMapCls<C, K, V>::forEach(std::function<void(K , V )> f) {
    _base->forEach([=] (Unknown  key,Unknown  pair) {
        f(pair->key, pair->value);
    });
}

template<typename C, typename K, typename V>
bool CanonicalizedMapCls<C, K, V>::isEmpty() {
    return _base->isEmpty;
}

template<typename C, typename K, typename V>
bool CanonicalizedMapCls<C, K, V>::isNotEmpty() {
    return _base->isNotEmpty;
}

template<typename C, typename K, typename V>
Iterable<K> CanonicalizedMapCls<C, K, V>::keys() {
    return _base->values->map([=] (Unknown  pair) {
        pair->key;
    });
}

template<typename C, typename K, typename V>
int CanonicalizedMapCls<C, K, V>::length() {
    return _base->length;
}

template<typename C, typename K, typename V>
template<typename K2, typename V2>
Map<K2, V2> CanonicalizedMapCls<C, K, V>::map(std::function<MapEntry<K2, V2>(K , V )> transform) {
    return _base->map([=] (Unknown  _,Unknown  pair) {
        transform(pair->key, pair->value);
    });
}

template<typename C, typename K, typename V>
V CanonicalizedMapCls<C, K, V>::putIfAbsent(K key, std::function<V()> ifAbsent) {
    return _base->putIfAbsent(_canonicalize(key), [=] () {
        make<MapEntryCls>(key, ifAbsent());
    })->value;
}

template<typename C, typename K, typename V>
V CanonicalizedMapCls<C, K, V>::remove(Object key) {
    if (!_isValidKey(key)) {
        return nullptr;
    }
    auto pair = _base->remove(_canonicalize(as<K>(key)));
    return pair?->value;
}

template<typename C, typename K, typename V>
void CanonicalizedMapCls<C, K, V>::removeWhere(std::function<bool(K key, V value)> test) {
    return _base->removeWhere([=] (Unknown  _,Unknown  pair) {
        test(pair->key, pair->value);
    });
}

template<typename C, typename K, typename V>
template<typename K2, typename V2>
Map<K2, V2> CanonicalizedMapCls<C, K, V>::retype() {
    return <K2, V2>cast();
}

template<typename C, typename K, typename V>
V CanonicalizedMapCls<C, K, V>::update(K key, std::function<V(V )> update, std::function<V()> ifAbsent) {
    return _base->update(_canonicalize(key), [=] (Unknown  pair) {
        auto value = pair->value;
        auto newValue = update(value);
        if (identical(newValue, value)) {
            return pair;
        }
        return make<MapEntryCls>(key, newValue);
    }, ifAbsent == nullptr? nullptr : [=] () {
        make<MapEntryCls>(key, ifAbsent());
    })->value;
}

template<typename C, typename K, typename V>
void CanonicalizedMapCls<C, K, V>::updateAll(std::function<V(K key, V value)> update) {
    return _base->updateAll([=] (Unknown  _,Unknown  pair) {
        auto value = pair->value;
        auto key = pair->key;
        auto newValue = update(key, value);
        if (identical(value, newValue)) {
            return pair;
        }
        return make<MapEntryCls>(key, newValue);
    });
}

template<typename C, typename K, typename V>
Iterable<V> CanonicalizedMapCls<C, K, V>::values() {
    return _base->values->map([=] (Unknown  pair) {
        pair->value;
    });
}

template<typename C, typename K, typename V>
String CanonicalizedMapCls<C, K, V>::toString() {
    return MapBaseCls->mapToString(this);
}

template<typename C, typename K, typename V>
bool CanonicalizedMapCls<C, K, V>::_isValidKey(Object key) {
    return (is<K>(key)) && (_isValidKeyFn == nullptr || _isValidKeyFn!(key));
}
