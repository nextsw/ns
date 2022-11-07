#include "wrappers.hpp"
bool _DelegatingIterableBase::any(FunctionType test) {
    return _base.any(test);
}

Iterable<T> _DelegatingIterableBase::cast<T>() {
    return _base.<T>cast();
}

bool _DelegatingIterableBase::contains(Object element) {
    return _base.contains(element);
}

E _DelegatingIterableBase::elementAt(int index) {
    return _base.elementAt(index);
}

bool _DelegatingIterableBase::every(FunctionType test) {
    return _base.every(test);
}

Iterable<T> _DelegatingIterableBase::expand<T>(FunctionType f) {
    return _base.expand(f);
}

E _DelegatingIterableBase::first() {
    return _base.first;
}

E _DelegatingIterableBase::firstWhere(FunctionType orElse, FunctionType test) {
    return _base.firstWhere(testorElse);
}

T _DelegatingIterableBase::fold<T>(FunctionType combine, T initialValue) {
    return _base.fold(initialValue, combine);
}

Iterable<E> _DelegatingIterableBase::followedBy(Iterable<E> other) {
    return _base.followedBy(other);
}

void _DelegatingIterableBase::forEach(FunctionType f) {
    return _base.forEach(f);
}

bool _DelegatingIterableBase::isEmpty() {
    return _base.isEmpty;
}

bool _DelegatingIterableBase::isNotEmpty() {
    return _base.isNotEmpty;
}

Iterator<E> _DelegatingIterableBase::iterator() {
    return _base.iterator;
}

String _DelegatingIterableBase::join(String separator) {
    return _base.join(separator);
}

E _DelegatingIterableBase::last() {
    return _base.last;
}

E _DelegatingIterableBase::lastWhere(FunctionType orElse, FunctionType test) {
    return _base.lastWhere(testorElse);
}

int _DelegatingIterableBase::length() {
    return _base.length;
}

Iterable<T> _DelegatingIterableBase::map<T>(FunctionType f) {
    return _base.map(f);
}

E _DelegatingIterableBase::reduce(FunctionType combine) {
    return _base.reduce(combine);
}

Iterable<T> _DelegatingIterableBase::retype<T>() {
    return <T>cast();
}

E _DelegatingIterableBase::single() {
    return _base.single;
}

E _DelegatingIterableBase::singleWhere(FunctionType orElse, FunctionType test) {
    return _base.singleWhere(testorElse);
}

Iterable<E> _DelegatingIterableBase::skip(int n) {
    return _base.skip(n);
}

Iterable<E> _DelegatingIterableBase::skipWhile(FunctionType test) {
    return _base.skipWhile(test);
}

Iterable<E> _DelegatingIterableBase::take(int n) {
    return _base.take(n);
}

Iterable<E> _DelegatingIterableBase::takeWhile(FunctionType test) {
    return _base.takeWhile(test);
}

List<E> _DelegatingIterableBase::toList(bool growable) {
    return _base.toList(growable);
}

Set<E> _DelegatingIterableBase::toSet() {
    return _base.toSet();
}

Iterable<E> _DelegatingIterableBase::where(FunctionType test) {
    return _base.where(test);
}

Iterable<T> _DelegatingIterableBase::whereType<T>() {
    return _base.<T>whereType();
}

String _DelegatingIterableBase::toString() {
    return _base.toString();
}

DelegatingIterable::DelegatingIterable(Iterable<E> base) {
    {
        _base = base;
    }
}

Iterable<E> DelegatingIterable::typed<E>(Iterable base) {
    return base.<E>cast();
}

DelegatingList::DelegatingList(List<E> base) {
    {
        _base = base;
    }
}

List<E> DelegatingList::typed<E>(List base) {
    return base.<E>cast();
}

E DelegatingList::[](int index) {
    return _base[index];
}

void DelegatingList::[]=(int index, E value) {
    _base[index] = value;
}

List<E> DelegatingList::+(List<E> other) {
    return _base + other;
}

void DelegatingList::add(E value) {
    _base.add(value);
}

void DelegatingList::addAll(Iterable<E> iterable) {
    _base.addAll(iterable);
}

Map<int, E> DelegatingList::asMap() {
    return _base.asMap();
}

List<T> DelegatingList::cast<T>() {
    return _base.<T>cast();
}

void DelegatingList::clear() {
    _base.clear();
}

void DelegatingList::fillRange(int end, E fillValue, int start) {
    _base.fillRange(start, end, fillValue);
}

void DelegatingList::first(E value) {
    if (isEmpty)     {
        ;
    }
    this[0] = value;
}

Iterable<E> DelegatingList::getRange(int end, int start) {
    return _base.getRange(start, end);
}

int DelegatingList::indexOf(E element, int start) {
    return _base.indexOf(element, start);
}

int DelegatingList::indexWhere(int start, FunctionType test) {
    return _base.indexWhere(test, start);
}

void DelegatingList::insert(E element, int index) {
    _base.insert(index, element);
}

void DelegatingList::insertAll(int index, Iterable<E> iterable) {
    _base.insertAll(index, iterable);
}

void DelegatingList::last(E value) {
    if (isEmpty)     {
        ;
    }
    this[length - 1] = value;
}

int DelegatingList::lastIndexOf(E element, int start) {
    return _base.lastIndexOf(element, start);
}

int DelegatingList::lastIndexWhere(int start, FunctionType test) {
    return _base.lastIndexWhere(test, start);
}

void DelegatingList::length(int newLength) {
    _base.length = newLength;
}

bool DelegatingList::remove(Object value) {
    return _base.remove(value);
}

E DelegatingList::removeAt(int index) {
    return _base.removeAt(index);
}

E DelegatingList::removeLast() {
    return _base.removeLast();
}

void DelegatingList::removeRange(int end, int start) {
    _base.removeRange(start, end);
}

void DelegatingList::removeWhere(FunctionType test) {
    _base.removeWhere(test);
}

void DelegatingList::replaceRange(int end, Iterable<E> iterable, int start) {
    _base.replaceRange(start, end, iterable);
}

void DelegatingList::retainWhere(FunctionType test) {
    _base.retainWhere(test);
}

List<T> DelegatingList::retype<T>() {
    return <T>cast();
}

Iterable<E> DelegatingList::reversed() {
    return _base.reversed;
}

void DelegatingList::setAll(int index, Iterable<E> iterable) {
    _base.setAll(index, iterable);
}

void DelegatingList::setRange(int end, Iterable<E> iterable, int skipCount, int start) {
    _base.setRange(start, end, iterable, skipCount);
}

void DelegatingList::shuffle(Random random) {
    _base.shuffle(random);
}

void DelegatingList::sort(FunctionType compare) {
    _base.sort(compare);
}

List<E> DelegatingList::sublist(int end, int start) {
    return _base.sublist(start, end);
}

DelegatingSet::DelegatingSet(Set<E> base) {
    {
        _base = base;
    }
}

Set<E> DelegatingSet::typed<E>(Set base) {
    return base.<E>cast();
}

bool DelegatingSet::add(E value) {
    return _base.add(value);
}

void DelegatingSet::addAll(Iterable<E> elements) {
    _base.addAll(elements);
}

Set<T> DelegatingSet::cast<T>() {
    return _base.<T>cast();
}

void DelegatingSet::clear() {
    _base.clear();
}

bool DelegatingSet::containsAll(Iterable<Object> other) {
    return _base.containsAll(other);
}

Set<E> DelegatingSet::difference(Set<Object> other) {
    return _base.difference(other);
}

Set<E> DelegatingSet::intersection(Set<Object> other) {
    return _base.intersection(other);
}

E DelegatingSet::lookup(Object element) {
    return _base.lookup(element);
}

bool DelegatingSet::remove(Object value) {
    return _base.remove(value);
}

void DelegatingSet::removeAll(Iterable<Object> elements) {
    _base.removeAll(elements);
}

void DelegatingSet::removeWhere(FunctionType test) {
    _base.removeWhere(test);
}

void DelegatingSet::retainAll(Iterable<Object> elements) {
    _base.retainAll(elements);
}

Set<T> DelegatingSet::retype<T>() {
    return <T>cast();
}

void DelegatingSet::retainWhere(FunctionType test) {
    _base.retainWhere(test);
}

Set<E> DelegatingSet::union(Set<E> other) {
    return _base.union(other);
}

Set<E> DelegatingSet::toSet() {
    return <E>DelegatingSet(_base.toSet());
}

DelegatingQueue::DelegatingQueue(Queue<E> queue) {
    {
        _base = queue;
    }
}

Queue<E> DelegatingQueue::typed<E>(Queue base) {
    return base.<E>cast();
}

void DelegatingQueue::add(E value) {
    _base.add(value);
}

void DelegatingQueue::addAll(Iterable<E> iterable) {
    _base.addAll(iterable);
}

void DelegatingQueue::addFirst(E value) {
    _base.addFirst(value);
}

void DelegatingQueue::addLast(E value) {
    _base.addLast(value);
}

Queue<T> DelegatingQueue::cast<T>() {
    return _base.<T>cast();
}

void DelegatingQueue::clear() {
    _base.clear();
}

bool DelegatingQueue::remove(Object object) {
    return _base.remove(object);
}

void DelegatingQueue::removeWhere(FunctionType test) {
    _base.removeWhere(test);
}

void DelegatingQueue::retainWhere(FunctionType test) {
    _base.retainWhere(test);
}

Queue<T> DelegatingQueue::retype<T>() {
    return <T>cast();
}

E DelegatingQueue::removeFirst() {
    return _base.removeFirst();
}

E DelegatingQueue::removeLast() {
    return _base.removeLast();
}

DelegatingMap::DelegatingMap(Map<K, V> base) {
    {
        _base = base;
    }
}

Map<K, V> DelegatingMap::typed<K, V>(Map base) {
    return base.<K, V>cast();
}

V DelegatingMap::[](Object key) {
    return _base[key];
}

void DelegatingMap::[]=(K key, V value) {
    _base[key] = value;
}

void DelegatingMap::addAll(Map<K, V> other) {
    _base.addAll(other);
}

void DelegatingMap::addEntries(Iterable<MapEntry<K, V>> entries) {
    _base.addEntries(entries);
}

void DelegatingMap::clear() {
    _base.clear();
}

Map<K2, V2> DelegatingMap::cast<K2, V2>() {
    return _base.<K2, V2>cast();
}

bool DelegatingMap::containsKey(Object key) {
    return _base.containsKey(key);
}

bool DelegatingMap::containsValue(Object value) {
    return _base.containsValue(value);
}

Iterable<MapEntry<K, V>> DelegatingMap::entries() {
    return _base.entries;
}

void DelegatingMap::forEach(FunctionType f) {
    _base.forEach(f);
}

bool DelegatingMap::isEmpty() {
    return _base.isEmpty;
}

bool DelegatingMap::isNotEmpty() {
    return _base.isNotEmpty;
}

Iterable<K> DelegatingMap::keys() {
    return _base.keys;
}

int DelegatingMap::length() {
    return _base.length;
}

Map<K2, V2> DelegatingMap::map<K2, V2>(FunctionType transform) {
    return _base.map(transform);
}

V DelegatingMap::putIfAbsent(FunctionType ifAbsent, K key) {
    return _base.putIfAbsent(key, ifAbsent);
}

V DelegatingMap::remove(Object key) {
    return _base.remove(key);
}

void DelegatingMap::removeWhere(FunctionType test) {
    return _base.removeWhere(test);
}

Map<K2, V2> DelegatingMap::retype<K2, V2>() {
    return <K2, V2>cast();
}

Iterable<V> DelegatingMap::values() {
    return _base.values;
}

String DelegatingMap::toString() {
    return _base.toString();
}

V DelegatingMap::update(FunctionType ifAbsent, K key, FunctionType update) {
    return _base.update(key, updateifAbsent);
}

void DelegatingMap::updateAll(FunctionType update) {
    return _base.updateAll(update);
}

Set<T> MapKeySet::cast<T>() {
    if (this is MapKeySet<T>) {
        return (;
    }
    return Set.<E, T>castFrom(this);
}

bool MapKeySet::contains(Object element) {
    return _baseMap.containsKey(element);
}

bool MapKeySet::isEmpty() {
    return _baseMap.isEmpty;
}

bool MapKeySet::isNotEmpty() {
    return _baseMap.isNotEmpty;
}

int MapKeySet::length() {
    return _baseMap.length;
}

String MapKeySet::toString() {
    return SetBase.setToString(this);
}

bool MapKeySet::containsAll(Iterable<Object> other) {
    return other.every(contains);
}

Set<E> MapKeySet::difference(Set<Object> other) {
    return where().toSet();
}

Set<E> MapKeySet::intersection(Set<Object> other) {
    return where(other.contains).toSet();
}

E MapKeySet::lookup(Object element) {
    return ;
}

Set<T> MapKeySet::retype<T>() {
    return Set.<E, T>castFrom(this);
}

Set<E> MapKeySet::union(Set<E> other) {
    return ;
}

Iterable<E> MapKeySet::_base() {
    return _baseMap.keys;
}

Set<T> MapValueSet::cast<T>() {
    if (this is Set<T>) {
        return (;
    }
    return Set.<V, T>castFrom(this);
}

bool MapValueSet::contains(Object element) {
    if (element is! V)     {
        return false;
    }
    auto key = _keyForValue(element);
    return _baseMap.containsKey(key);
}

bool MapValueSet::isEmpty() {
    return _baseMap.isEmpty;
}

bool MapValueSet::isNotEmpty() {
    return _baseMap.isNotEmpty;
}

int MapValueSet::length() {
    return _baseMap.length;
}

String MapValueSet::toString() {
    return toSet().toString();
}

bool MapValueSet::add(V value) {
    auto key = _keyForValue(value);
    auto result = false;
    _baseMap.putIfAbsent(key, );
    return result;
}

void MapValueSet::addAll(Iterable<V> elements) {
    return elements.forEach(add);
}

void MapValueSet::clear() {
    return _baseMap.clear();
}

bool MapValueSet::containsAll(Iterable<Object> other) {
    return other.every(contains);
}

Set<V> MapValueSet::difference(Set<Object> other) {
    return where().toSet();
}

Set<V> MapValueSet::intersection(Set<Object> other) {
    return where(other.contains).toSet();
}

V MapValueSet::lookup(Object element) {
    if (element is! V)     {
        return nullptr;
    }
    auto key = _keyForValue(element);
    return _baseMap[key];
}

bool MapValueSet::remove(Object element) {
    if (element is! V)     {
        return false;
    }
    auto key = _keyForValue(element);
    if (!_baseMap.containsKey(key))     {
        return false;
    }
    _baseMap.remove(key);
    return true;
}

void MapValueSet::removeAll(Iterable<Object> elements) {
    return elements.forEach(remove);
}

void MapValueSet::removeWhere(FunctionType test) {
    auto toRemove = ;
    _baseMap.forEach();
    toRemove.forEach(_baseMap.remove);
}

void MapValueSet::retainAll(Iterable<Object> elements) {
    auto valuesToRetain = <V>identity();
    for (auto element : elements) {
        if (element is! V)         {
            continue;
        }
        auto key = _keyForValue(element);
        if (!_baseMap.containsKey(key))         {
            continue;
        }
        valuesToRetain.add(_baseMap[key] ?? ();
    }
    auto keysToRemove = ;
    _baseMap.forEach();
    keysToRemove.forEach(_baseMap.remove);
}

void MapValueSet::retainWhere(FunctionType test) {
    return removeWhere();
}

Set<T> MapValueSet::retype<T>() {
    return Set.<V, T>castFrom(this);
}

Set<V> MapValueSet::union(Set<V> other) {
    return ;
}

Iterable<V> MapValueSet::_base() {
    return _baseMap.values;
}
