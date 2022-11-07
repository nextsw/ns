#include "equality.hpp"
EqualityBy::EqualityBy(FunctionType comparisonKey, Equality<F> inner) {
    {
        _comparisonKey = comparisonKey;
        _inner = inner;
    }
}

bool EqualityBy::equals(E e1, E e2) {
    return _inner.equals(_comparisonKey(e1), _comparisonKey(e2));
}

int EqualityBy::hash(E e) {
    return _inner.hash(_comparisonKey(e));
}

bool EqualityBy::isValidKey(Object o) {
    if (o is E) {
        Unknown value = _comparisonKey(o);
        return _inner.isValidKey(value);
    }
    return false;
}

bool DefaultEquality::equals(Object e1, Object e2) {
    return e1 == e2;
}

int DefaultEquality::hash(Object e) {
    return e.hashCode;
}

bool DefaultEquality::isValidKey(Object o) {
    return true;
}

bool IdentityEquality::equals(E e1, E e2) {
    return identical(e1, e2);
}

int IdentityEquality::hash(E e) {
    return identityHashCode(e);
}

bool IdentityEquality::isValidKey(Object o) {
    return true;
}

IterableEquality::IterableEquality(Equality<E> elementEquality) {
    {
        _elementEquality = elementEquality;
    }
}

bool IterableEquality::equals(Iterable<E> elements1, Iterable<E> elements2) {
    if (identical(elements1, elements2))     {
        return true;
    }
    if (elements1 == nullptr || elements2 == nullptr)     {
        return false;
    }
    auto it1 = elements1.iterator;
    auto it2 = elements2.iterator;
    while (true) {
        auto hasNext = it1.moveNext();
        if (hasNext != it2.moveNext())         {
            return false;
        }
        if (!hasNext)         {
            return true;
        }
        if (!_elementEquality.equals(it1.current, it2.current))         {
            return false;
        }
    }
}

int IterableEquality::hash(Iterable<E> elements) {
    if (elements == nullptr)     {
        return nullptr.hashCode;
    }
    auto hash = 0;
    for (auto element : elements) {
        auto c = _elementEquality.hash(element);
        hash = (hash + c) & _hashMask;
        hash = (hash + (hash << 10)) & _hashMask;
        hash = (hash >> 6);
    }
    hash = (hash + (hash << 3)) & _hashMask;
    hash = (hash >> 11);
    hash = (hash + (hash << 15)) & _hashMask;
    return hash;
}

bool IterableEquality::isValidKey(Object o) {
    return o is Iterable<E>;
}

ListEquality::ListEquality(Equality<E> elementEquality) {
    {
        _elementEquality = elementEquality;
    }
}

bool ListEquality::equals(List<E> list1, List<E> list2) {
    if (identical(list1, list2))     {
        return true;
    }
    if (list1 == nullptr || list2 == nullptr)     {
        return false;
    }
    auto length = list1.length;
    if (length != list2.length)     {
        return false;
    }
    for (;  < length; i++) {
        if (!_elementEquality.equals(list1[i], list2[i]))         {
            return false;
        }
    }
    return true;
}

int ListEquality::hash(List<E> list) {
    if (list == nullptr)     {
        return nullptr.hashCode;
    }
    auto hash = 0;
    for (;  < list.length; i++) {
        auto c = _elementEquality.hash(list[i]);
        hash = (hash + c) & _hashMask;
        hash = (hash + (hash << 10)) & _hashMask;
        hash = (hash >> 6);
    }
    hash = (hash + (hash << 3)) & _hashMask;
    hash = (hash >> 11);
    hash = (hash + (hash << 15)) & _hashMask;
    return hash;
}

bool ListEquality::isValidKey(Object o) {
    return o is List<E>;
}

bool _UnorderedEquality::equals(T elements1, T elements2) {
    if (identical(elements1, elements2))     {
        return true;
    }
    if (elements1 == nullptr || elements2 == nullptr)     {
        return false;
    }
    auto counts = <E, int>HashMap(_elementEquality.equals, _elementEquality.hash, _elementEquality.isValidKey);
    auto length = 0;
    for (auto e : elements1) {
        auto count = counts[e] ?? 0;
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

int _UnorderedEquality::hash(T elements) {
    if (elements == nullptr)     {
        return nullptr.hashCode;
    }
    auto hash = 0;
    for (E element : elements) {
        auto c = _elementEquality.hash(element);
        hash = (hash + c) & _hashMask;
    }
    hash = (hash + (hash << 3)) & _hashMask;
    hash = (hash >> 11);
    hash = (hash + (hash << 15)) & _hashMask;
    return hash;
}

UnorderedIterableEquality::UnorderedIterableEquality(Equality<E> elementEquality) {
    {
        super(elementEquality);
    }
}

bool UnorderedIterableEquality::isValidKey(Object o) {
    return o is Iterable<E>;
}

SetEquality::SetEquality(Equality<E> elementEquality) {
    {
        super(elementEquality);
    }
}

bool SetEquality::isValidKey(Object o) {
    return o is Set<E>;
}

int _MapEntry::hashCode() {
    return (3 * equality._keyEquality.hash(key) + 7 * equality._valueEquality.hash(value)) & _hashMask;
}

bool _MapEntry::==(Object other) {
    return other is _MapEntry && equality._keyEquality.equals(key, other.key) && equality._valueEquality.equals(value, other.value);
}

MapEquality::MapEquality(Equality<K> keys, Equality<V> values) {
    {
        _keyEquality = keys;
        _valueEquality = values;
    }
}

bool MapEquality::equals(Map<K, V> map1, Map<K, V> map2) {
    if (identical(map1, map2))     {
        return true;
    }
    if (map1 == nullptr || map2 == nullptr)     {
        return false;
    }
    auto length = map1.length;
    if (length != map2.length)     {
        return false;
    }
    Map<_MapEntry, int> equalElementCounts = HashMap();
    for (auto key : map1.keys) {
        auto entry = _MapEntry(this, key, map1[key]);
        auto count = equalElementCounts[entry] ?? 0;
        equalElementCounts[entry] = count + 1;
    }
    for (auto key : map2.keys) {
        auto entry = _MapEntry(this, key, map2[key]);
        auto count = equalElementCounts[entry];
        if (count == nullptr || count == 0)         {
            return false;
        }
        equalElementCounts[entry] = count - 1;
    }
    return true;
}

int MapEquality::hash(Map<K, V> map) {
    if (map == nullptr)     {
        return nullptr.hashCode;
    }
    auto hash = 0;
    for (auto key : map.keys) {
        auto keyHash = _keyEquality.hash(key);
        auto valueHash = _valueEquality.hash(();
        hash = (hash + 3 * keyHash + 7 * valueHash) & _hashMask;
    }
    hash = (hash + (hash << 3)) & _hashMask;
    hash = (hash >> 11);
    hash = (hash + (hash << 15)) & _hashMask;
    return hash;
}

bool MapEquality::isValidKey(Object o) {
    return o is Map<K, V>;
}

MultiEquality::MultiEquality(Iterable<Equality<E>> equalities) {
    {
        _equalities = equalities;
    }
}

bool MultiEquality::equals(E e1, E e2) {
    for (auto eq : _equalities) {
        if (eq.isValidKey(e1))         {
            return eq.isValidKey(e2) && eq.equals(e1, e2);
        }
    }
    return false;
}

int MultiEquality::hash(E e) {
    for (auto eq : _equalities) {
        if (eq.isValidKey(e))         {
            return eq.hash(e);
        }
    }
    return 0;
}

bool MultiEquality::isValidKey(Object o) {
    for (auto eq : _equalities) {
        if (eq.isValidKey(o))         {
            return true;
        }
    }
    return false;
}

DeepCollectionEquality::DeepCollectionEquality(Equality base) {
    {
        _base = base;
        _unordered = false;
    }
}

void DeepCollectionEquality::unordered(Equality base)

bool DeepCollectionEquality::equals(e1 , e2 ) {
    if (e1 is Set) {
        return e2 is Set && SetEquality(this).equals(e1, e2);
    }
    if (e1 is Map) {
        return e2 is Map && MapEquality(this, this).equals(e1, e2);
    }
    if (!_unordered) {
        if (e1 is List) {
            return e2 is List && ListEquality(this).equals(e1, e2);
        }
        if (e1 is Iterable) {
            return e2 is Iterable && IterableEquality(this).equals(e1, e2);
        }
    } else     {
        if (e1 is Iterable) {
        if (e1 is List != e2 is List)         {
            return false;
        }
        return e2 is Iterable && UnorderedIterableEquality(this).equals(e1, e2);
    }
;
    }    return _base.equals(e1, e2);
}

int DeepCollectionEquality::hash(Object o) {
    if (o is Set)     {
        return SetEquality(this).hash(o);
    }
    if (o is Map)     {
        return MapEquality(this, this).hash(o);
    }
    if (!_unordered) {
        if (o is List)         {
            return ListEquality(this).hash(o);
        }
        if (o is Iterable)         {
            return IterableEquality(this).hash(o);
        }
    } else     {
        if (o is Iterable) {
        return UnorderedIterableEquality(this).hash(o);
    }
;
    }    return _base.hash(o);
}

bool DeepCollectionEquality::isValidKey(Object o) {
    return o is Iterable || o is Map || _base.isValidKey(o);
}

bool CaseInsensitiveEquality::equals(String string1, String string2) {
    return equalsIgnoreAsciiCase(string1, string2);
}

int CaseInsensitiveEquality::hash(String string) {
    return hashIgnoreAsciiCase(string);
}

bool CaseInsensitiveEquality::isValidKey(Object object) {
    return object is String;
}
