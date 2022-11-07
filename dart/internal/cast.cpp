#include "cast.hpp"
Iterator<T> _CastIterableBase::iterator() {
    return <S, T>CastIterator(_source.iterator);
}

int _CastIterableBase::length() {
    return _source.length;
}

bool _CastIterableBase::isEmpty() {
    return _source.isEmpty;
}

bool _CastIterableBase::isNotEmpty() {
    return _source.isNotEmpty;
}

Iterable<T> _CastIterableBase::skip(int count) {
    return <S, T>CastIterable(_source.skip(count));
}

Iterable<T> _CastIterableBase::take(int count) {
    return <S, T>CastIterable(_source.take(count));
}

T _CastIterableBase::elementAt(int index) {
    return (;
}

T _CastIterableBase::first() {
    return (;
}

T _CastIterableBase::last() {
    return (;
}

T _CastIterableBase::single() {
    return (;
}

bool _CastIterableBase::contains(Object other) {
    return _source.contains(other);
}

T _CastIterableBase::lastWhere(FunctionType orElse, FunctionType test) {
    return (;
}

String _CastIterableBase::toString() {
    return _source.toString();
}

bool CastIterator::moveNext() {
    return _source.moveNext();
}

T CastIterator::current() {
    return (;
}

CastIterable::CastIterable(Iterable<S> source) {
    {
        if (source is EfficientLengthIterable<S>) {
            return <S, T>_EfficientLengthCastIterable(source);
        }
        return <S, T>_(source);
    }
}

Iterable<R> CastIterable::cast<R>() {
    return <S, R>CastIterable(_source);
}

_EfficientLengthCastIterable::_EfficientLengthCastIterable(EfficientLengthIterable<S> source) {
    {
        super._(source);
    }
}

T _CastListBase::[](int index) {
    return (;
}

void _CastListBase::[]=(int index, T value) {
    _source[index] = (;
}

void _CastListBase::length(int length) {
    _source.length = length;
}

void _CastListBase::add(T value) {
    _source.add(();
}

void _CastListBase::addAll(Iterable<T> values) {
    _source.addAll(<T, S>CastIterable(values));
}

void _CastListBase::sort(FunctionType compare) {
    _source.sort(compare == nullptr? nullptr : );
}

void _CastListBase::shuffle(Random random) {
    _source.shuffle(random);
}

void _CastListBase::insert(T element, int index) {
    _source.insert(index, ();
}

void _CastListBase::insertAll(Iterable<T> elements, int index) {
    _source.insertAll(index, <T, S>CastIterable(elements));
}

void _CastListBase::setAll(Iterable<T> elements, int index) {
    _source.setAll(index, <T, S>CastIterable(elements));
}

bool _CastListBase::remove(Object value) {
    return _source.remove(value);
}

T _CastListBase::removeAt(int index) {
    return (;
}

T _CastListBase::removeLast() {
    return (;
}

void _CastListBase::removeWhere(FunctionType test) {
    _source.removeWhere();
}

void _CastListBase::retainWhere(FunctionType test) {
    _source.retainWhere();
}

Iterable<T> _CastListBase::getRange(int end, int start) {
    return <S, T>CastIterable(_source.getRange(start, end));
}

void _CastListBase::setRange(int end, Iterable<T> iterable, int skipCount, int start) {
    _source.setRange(start, end, <T, S>CastIterable(iterable), skipCount);
}

void _CastListBase::removeRange(int end, int start) {
    _source.removeRange(start, end);
}

void _CastListBase::fillRange(int end, T fillValue, int start) {
    _source.fillRange(start, end, ();
}

void _CastListBase::replaceRange(int end, Iterable<T> replacement, int start) {
    _source.replaceRange(start, end, <T, S>CastIterable(replacement));
}

List<R> CastList::cast<R>() {
    return <S, R>CastList(_source);
}

Set<R> CastSet::cast<R>() {
    return <S, R>CastSet(_source, _emptySet);
}

bool CastSet::add(T value) {
    return _source.add(();
}

void CastSet::addAll(Iterable<T> elements) {
    _source.addAll(<T, S>CastIterable(elements));
}

bool CastSet::remove(Object object) {
    return _source.remove(object);
}

void CastSet::removeAll(Iterable<Object> objects) {
    _source.removeAll(objects);
}

void CastSet::retainAll(Iterable<Object> objects) {
    _source.retainAll(objects);
}

void CastSet::removeWhere(FunctionType test) {
    _source.removeWhere();
}

void CastSet::retainWhere(FunctionType test) {
    _source.retainWhere();
}

bool CastSet::containsAll(Iterable<Object> objects) {
    return _source.containsAll(objects);
}

Set<T> CastSet::intersection(Set<Object> other) {
    if (_emptySet != nullptr)     {
        return _conditionalAdd(other, true);
    }
    return <S, T>CastSet(_source.intersection(other), nullptr);
}

Set<T> CastSet::difference(Set<Object> other) {
    if (_emptySet != nullptr)     {
        return _conditionalAdd(other, false);
    }
    return <S, T>CastSet(_source.difference(other), nullptr);
}

Set<T> CastSet::union(Set<T> other) {
    return ;
}

void CastSet::clear() {
    _source.clear();
}

Set<T> CastSet::toSet() {
    return _clone();
}

T CastSet::lookup(Object key) {
    return (;
}

Set<T> CastSet::_conditionalAdd(Set<Object> other, bool otherContains) {
    auto emptySet = _emptySet;
    Set<T> result = (emptySet == nullptr)? <T>Set() : <T>emptySet();
    for (auto element : _source) {
        T castElement = (;
        if (otherContains == other.contains(castElement))         {
            result.add(castElement);
        }
    }
    return result;
}

Set<T> CastSet::_clone() {
    auto emptySet = _emptySet;
    Set<T> result = (emptySet == nullptr)? <T>Set() : <T>emptySet();
    result.addAll(this);
    return result;
}

Map<RK, RV> CastMap::cast<RK, RV>() {
    return <SK, SV, RK, RV>CastMap(_source);
}

bool CastMap::containsValue(Object value) {
    return _source.containsValue(value);
}

bool CastMap::containsKey(Object key) {
    return _source.containsKey(key);
}

V CastMap::[](Object key) {
    return (;
}

void CastMap::[]=(K key, V value) {
    _source[(] = (;
}

V CastMap::putIfAbsent(FunctionType ifAbsent, K key) {
    return (;
}

void CastMap::addAll(Map<K, V> other) {
    _source.addAll(<K, V, SK, SV>CastMap(other));
}

V CastMap::remove(Object key) {
    return (;
}

void CastMap::clear() {
    _source.clear();
}

void CastMap::forEach(FunctionType f) {
    _source.forEach();
}

Iterable<K> CastMap::keys() {
    return <SK, K>CastIterable(_source.keys);
}

Iterable<V> CastMap::values() {
    return <SV, V>CastIterable(_source.values);
}

int CastMap::length() {
    return _source.length;
}

bool CastMap::isEmpty() {
    return _source.isEmpty;
}

bool CastMap::isNotEmpty() {
    return _source.isNotEmpty;
}

V CastMap::update(FunctionType ifAbsent, K key, FunctionType update) {
    return (;
}

void CastMap::updateAll(FunctionType update) {
    _source.updateAll();
}

Iterable<MapEntry<K, V>> CastMap::entries() {
    return _source.entries.<MapEntry<K, V>>map();
}

void CastMap::addEntries(Iterable<MapEntry<K, V>> entries) {
    for (auto entry : entries) {
        _source[(] = (;
    }
}

void CastMap::removeWhere(FunctionType test) {
    _source.removeWhere();
}

Queue<R> CastQueue::cast<R>() {
    return <S, R>CastQueue(_source);
}

T CastQueue::removeFirst() {
    return (;
}

T CastQueue::removeLast() {
    return (;
}

void CastQueue::add(T value) {
    _source.add(();
}

void CastQueue::addFirst(T value) {
    _source.addFirst(();
}

void CastQueue::addLast(T value) {
    _source.addLast(();
}

bool CastQueue::remove(Object other) {
    return _source.remove(other);
}

void CastQueue::addAll(Iterable<T> elements) {
    _source.addAll(<T, S>CastIterable(elements));
}

void CastQueue::removeWhere(FunctionType test) {
    _source.removeWhere();
}

void CastQueue::retainWhere(FunctionType test) {
    _source.retainWhere();
}

void CastQueue::clear() {
    _source.clear();
}
