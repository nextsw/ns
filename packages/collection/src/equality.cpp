#include "equality.hpp"
template<typename E, typename F>
EqualityByCls<E, F>::EqualityByCls(std::function<F(E )> comparisonKey, Equality<F> inner) {
    {
        _comparisonKey = comparisonKey;
        _inner = inner;
    }
}

template<typename E, typename F>
bool EqualityByCls<E, F>::equals(E e1, E e2) {
    return _inner->equals(_comparisonKey(e1), _comparisonKey(e2));
}

template<typename E, typename F>
int EqualityByCls<E, F>::hash(E e) {
    return _inner->hash(_comparisonKey(e));
}

template<typename E, typename F>
bool EqualityByCls<E, F>::isValidKey(Object o) {
    if (is<E>(o)) {
        Unknown value = _comparisonKey(o);
        return _inner->isValidKey(value);
    }
    return false;
}

template<typename E>
bool DefaultEqualityCls<E>::equals(Object e1, Object e2) {
    return e1 == e2;
}

template<typename E>
int DefaultEqualityCls<E>::hash(Object e) {
    return e->hashCode();
}

template<typename E>
bool DefaultEqualityCls<E>::isValidKey(Object o) {
    return true;
}

template<typename E>
bool IdentityEqualityCls<E>::equals(E e1, E e2) {
    return identical(e1, e2);
}

template<typename E>
int IdentityEqualityCls<E>::hash(E e) {
    return identityHashCode(e);
}

template<typename E>
bool IdentityEqualityCls<E>::isValidKey(Object o) {
    return true;
}

template<typename E>
IterableEqualityCls<E>::IterableEqualityCls(Equality<E> elementEquality) {
    {
        _elementEquality = elementEquality;
    }
}

template<typename E>
bool IterableEqualityCls<E>::equals(Iterable<E> elements1, Iterable<E> elements2) {
    if (identical(elements1, elements2))     {
        return true;
    }
    if (elements1 == nullptr || elements2 == nullptr)     {
        return false;
    }
    auto it1 = elements1->iterator();
    auto it2 = elements2->iterator();
    while (true) {
        auto hasNext = it1->moveNext();
        if (hasNext != it2->moveNext())         {
            return false;
        }
        if (!hasNext)         {
            return true;
        }
        if (!_elementEquality->equals(it1->current(), it2->current()))         {
            return false;
        }
    }
}

template<typename E>
int IterableEqualityCls<E>::hash(Iterable<E> elements) {
    if (elements == nullptr)     {
        return nullptr->hashCode;
    }
    auto hash = 0;
    for (auto element : elements) {
        auto c = _elementEquality->hash(element);
        hash = (hash + c) & _hashMask;
        hash = (hash + (hash << 10)) & _hashMask;
        hash = (hash >> 6);
    }
    hash = (hash + (hash << 3)) & _hashMask;
    hash = (hash >> 11);
    hash = (hash + (hash << 15)) & _hashMask;
    return hash;
}

template<typename E>
bool IterableEqualityCls<E>::isValidKey(Object o) {
    return is<Iterable<E>>(o);
}

template<typename E>
ListEqualityCls<E>::ListEqualityCls(Equality<E> elementEquality) {
    {
        _elementEquality = elementEquality;
    }
}

template<typename E>
bool ListEqualityCls<E>::equals(List<E> list1, List<E> list2) {
    if (identical(list1, list2))     {
        return true;
    }
    if (list1 == nullptr || list2 == nullptr)     {
        return false;
    }
    auto length = list1->length();
    if (length != list2->length)     {
        return false;
    }
    for (;  < length; i++) {
        if (!_elementEquality->equals(list1[i], list2[i]))         {
            return false;
        }
    }
    return true;
}

template<typename E>
int ListEqualityCls<E>::hash(List<E> list) {
    if (list == nullptr)     {
        return nullptr->hashCode;
    }
    auto hash = 0;
    for (;  < list->length(); i++) {
        auto c = _elementEquality->hash(list[i]);
        hash = (hash + c) & _hashMask;
        hash = (hash + (hash << 10)) & _hashMask;
        hash = (hash >> 6);
    }
    hash = (hash + (hash << 3)) & _hashMask;
    hash = (hash >> 11);
    hash = (hash + (hash << 15)) & _hashMask;
    return hash;
}

template<typename E>
bool ListEqualityCls<E>::isValidKey(Object o) {
    return is<List<E>>(o);
}

template<typename E, typename T>
bool _UnorderedEqualityCls<E, T>::equals(T elements1, T elements2) {
    if (identical(elements1, elements2))     {
        return true;
    }
    if (elements1 == nullptr || elements2 == nullptr)     {
        return false;
    }
    auto counts = <E, int>make<HashMapCls>(_elementEquality->equals, _elementEquality->hash, _elementEquality->isValidKey);
    auto length = 0;
    for (auto e : elements1) {
        auto count = counts[e] or 0;
        counts[e] = count + 1;
        length++;
    }
    for (auto e : elements2) {
        auto count = counts[e];
        if (count == nullptr || count == 0)         {
            return false;
        }
        counts[e] = count - 1;
        length--;
    }
    return length == 0;
}

template<typename E, typename T>
int _UnorderedEqualityCls<E, T>::hash(T elements) {
    if (elements == nullptr)     {
        return nullptr->hashCode;
    }
    auto hash = 0;
    for (E element : elements) {
        auto c = _elementEquality->hash(element);
        hash = (hash + c) & _hashMask;
    }
    hash = (hash + (hash << 3)) & _hashMask;
    hash = (hash >> 11);
    hash = (hash + (hash << 15)) & _hashMask;
    return hash;
}

template<typename E>
UnorderedIterableEqualityCls<E>::UnorderedIterableEqualityCls(Equality<E> elementEquality) {
}

template<typename E>
bool UnorderedIterableEqualityCls<E>::isValidKey(Object o) {
    return is<Iterable<E>>(o);
}

template<typename E>
SetEqualityCls<E>::SetEqualityCls(Equality<E> elementEquality) {
}

template<typename E>
bool SetEqualityCls<E>::isValidKey(Object o) {
    return is<Set<E>>(o);
}

int _MapEntryCls::hashCode() {
    return (3 * equality->_keyEquality->hash(key) + 7 * equality->_valueEquality->hash(value)) & _hashMask;
}

bool _MapEntryCls::==(Object other) {
    return is<_MapEntry>(other) && equality->_keyEquality->equals(key, other->key) && equality->_valueEquality->equals(value, other->value);
}

template<typename K, typename V>
MapEqualityCls<K, V>::MapEqualityCls(Equality<K> keys, Equality<V> values) {
    {
        _keyEquality = keys;
        _valueEquality = values;
    }
}

template<typename K, typename V>
bool MapEqualityCls<K, V>::equals(Map<K, V> map1, Map<K, V> map2) {
    if (identical(map1, map2))     {
        return true;
    }
    if (map1 == nullptr || map2 == nullptr)     {
        return false;
    }
    auto length = map1->length();
    if (length != map2->length)     {
        return false;
    }
    Map<_MapEntry, int> equalElementCounts = make<HashMapCls>();
    for (auto key : map1->keys()) {
        auto entry = make<_MapEntryCls>(this, key, map1[key]);
        auto count = equalElementCounts[entry] or 0;
        equalElementCounts[entry] = count + 1;
    }
    for (auto key : map2->keys()) {
        auto entry = make<_MapEntryCls>(this, key, map2[key]);
        auto count = equalElementCounts[entry];
        if (count == nullptr || count == 0)         {
            return false;
        }
        equalElementCounts[entry] = count - 1;
    }
    return true;
}

template<typename K, typename V>
int MapEqualityCls<K, V>::hash(Map<K, V> map) {
    if (map == nullptr)     {
        return nullptr->hashCode;
    }
    auto hash = 0;
    for (auto key : map->keys()) {
        auto keyHash = _keyEquality->hash(key);
        auto valueHash = _valueEquality->hash(as<V>(map[key]));
        hash = (hash + 3 * keyHash + 7 * valueHash) & _hashMask;
    }
    hash = (hash + (hash << 3)) & _hashMask;
    hash = (hash >> 11);
    hash = (hash + (hash << 15)) & _hashMask;
    return hash;
}

template<typename K, typename V>
bool MapEqualityCls<K, V>::isValidKey(Object o) {
    return is<Map<K, V>>(o);
}

template<typename E>
MultiEqualityCls<E>::MultiEqualityCls(Iterable<Equality<E>> equalities) {
    {
        _equalities = equalities;
    }
}

template<typename E>
bool MultiEqualityCls<E>::equals(E e1, E e2) {
    for (auto eq : _equalities) {
        if (eq->isValidKey(e1))         {
            return eq->isValidKey(e2) && eq->equals(e1, e2);
        }
    }
    return false;
}

template<typename E>
int MultiEqualityCls<E>::hash(E e) {
    for (auto eq : _equalities) {
        if (eq->isValidKey(e))         {
            return eq->hash(e);
        }
    }
    return 0;
}

template<typename E>
bool MultiEqualityCls<E>::isValidKey(Object o) {
    for (auto eq : _equalities) {
        if (eq->isValidKey(o))         {
            return true;
        }
    }
    return false;
}

DeepCollectionEqualityCls::DeepCollectionEqualityCls(Equality base) {
    {
        _base = base;
        _unordered = false;
    }
}

void DeepCollectionEqualityCls::unordered(Equality base)

bool DeepCollectionEqualityCls::equals(e1 , e2 ) {
    if (is<Set>(e1)) {
        return is<Set>(e2) && make<SetEqualityCls>(this)->equals(as<SetCls>(e1), e2);
    }
    if (is<Map>(e1)) {
        return is<Map>(e2) && make<MapEqualityCls>(this, this)->equals(as<MapCls>(e1), e2);
    }
    if (!_unordered) {
        if (is<List>(e1)) {
            return is<List>(e2) && make<ListEqualityCls>(this)->equals(as<ListCls>(e1), e2);
        }
        if (is<Iterable>(e1)) {
            return is<Iterable>(e2) && make<IterableEqualityCls>(this)->equals(as<IterableCls>(e1), e2);
        }
    } else     {
        if (is<Iterable>(e1)) {
        if (is<List>(as<IterableCls>(e1)) != is<List>(e2))         {
            return false;
        }
        return is<Iterable>(e2) && make<UnorderedIterableEqualityCls>(this)->equals(as<IterableCls>(e1), e2);
    }
;
    }    return _base->equals(e1, e2);
}

int DeepCollectionEqualityCls::hash(Object o) {
    if (is<Set>(o))     {
        return make<SetEqualityCls>(this)->hash(as<SetCls>(o));
    }
    if (is<Map>(o))     {
        return make<MapEqualityCls>(this, this)->hash(as<MapCls>(o));
    }
    if (!_unordered) {
        if (is<List>(o))         {
            return make<ListEqualityCls>(this)->hash(as<ListCls>(o));
        }
        if (is<Iterable>(o))         {
            return make<IterableEqualityCls>(this)->hash(as<IterableCls>(o));
        }
    } else     {
        if (is<Iterable>(o)) {
        return make<UnorderedIterableEqualityCls>(this)->hash(as<IterableCls>(o));
    }
;
    }    return _base->hash(o);
}

bool DeepCollectionEqualityCls::isValidKey(Object o) {
    return is<Iterable>(o) || is<Map>(o) || _base->isValidKey(o);
}

bool CaseInsensitiveEqualityCls::equals(String string1, String string2) {
    return equalsIgnoreAsciiCase(string1, string2);
}

int CaseInsensitiveEqualityCls::hash(String stringValue) {
    return hashIgnoreAsciiCase(stringValue);
}

bool CaseInsensitiveEqualityCls::isValidKey(Object object) {
    return is<String>(object);
}
