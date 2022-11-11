#include "wrappers.hpp"
template<typename E>
bool _DelegatingIterableBaseCls<E>::any(bool test(E ) ) {
    return _base()->any(test);
}

template<typename E>
template<typename T>
Iterable<T> _DelegatingIterableBaseCls<E>::cast() {
    return _base()-><T>cast();
}

template<typename E>
bool _DelegatingIterableBaseCls<E>::contains(Object element) {
    return _base()->contains(element);
}

template<typename E>
E _DelegatingIterableBaseCls<E>::elementAt(int index) {
    return _base()->elementAt(index);
}

template<typename E>
bool _DelegatingIterableBaseCls<E>::every(bool test(E ) ) {
    return _base()->every(test);
}

template<typename E>
template<typename T>
Iterable<T> _DelegatingIterableBaseCls<E>::expand(Iterable<T> f(E ) ) {
    return _base()->expand(f);
}

template<typename E>
E _DelegatingIterableBaseCls<E>::first() {
    return _base()->first();
}

template<typename E>
E _DelegatingIterableBaseCls<E>::firstWhere(E orElse() , bool test(E ) ) {
    return _base()->firstWhere(testorElse);
}

template<typename E>
template<typename T>
T _DelegatingIterableBaseCls<E>::fold(T combine(E element, T previousValue) , T initialValue) {
    return _base()->fold(initialValue, combine);
}

template<typename E>
Iterable<E> _DelegatingIterableBaseCls<E>::followedBy(Iterable<E> other) {
    return _base()->followedBy(other);
}

template<typename E>
void _DelegatingIterableBaseCls<E>::forEach(void f(E ) ) {
    return _base()->forEach(f);
}

template<typename E>
bool _DelegatingIterableBaseCls<E>::isEmpty() {
    return _base()->isEmpty();
}

template<typename E>
bool _DelegatingIterableBaseCls<E>::isNotEmpty() {
    return _base()->isNotEmpty();
}

template<typename E>
Iterator<E> _DelegatingIterableBaseCls<E>::iterator() {
    return _base()->iterator();
}

template<typename E>
String _DelegatingIterableBaseCls<E>::join(String separator) {
    return _base()->join(separator);
}

template<typename E>
E _DelegatingIterableBaseCls<E>::last() {
    return _base()->last();
}

template<typename E>
E _DelegatingIterableBaseCls<E>::lastWhere(E orElse() , bool test(E ) ) {
    return _base()->lastWhere(testorElse);
}

template<typename E>
int _DelegatingIterableBaseCls<E>::length() {
    return _base()->length();
}

template<typename E>
template<typename T>
Iterable<T> _DelegatingIterableBaseCls<E>::map(T f(E ) ) {
    return _base()->map(f);
}

template<typename E>
E _DelegatingIterableBaseCls<E>::reduce(E combine(E element, E value) ) {
    return _base()->reduce(combine);
}

template<typename E>
template<typename T>
Iterable<T> _DelegatingIterableBaseCls<E>::retype() {
    return <T>cast();
}

template<typename E>
E _DelegatingIterableBaseCls<E>::single() {
    return _base()->single();
}

template<typename E>
E _DelegatingIterableBaseCls<E>::singleWhere(E orElse() , bool test(E ) ) {
    return _base()->singleWhere(testorElse);
}

template<typename E>
Iterable<E> _DelegatingIterableBaseCls<E>::skip(int n) {
    return _base()->skip(n);
}

template<typename E>
Iterable<E> _DelegatingIterableBaseCls<E>::skipWhile(bool test(E ) ) {
    return _base()->skipWhile(test);
}

template<typename E>
Iterable<E> _DelegatingIterableBaseCls<E>::take(int n) {
    return _base()->take(n);
}

template<typename E>
Iterable<E> _DelegatingIterableBaseCls<E>::takeWhile(bool test(E ) ) {
    return _base()->takeWhile(test);
}

template<typename E>
List<E> _DelegatingIterableBaseCls<E>::toList(bool growable) {
    return _base()->toList(growable);
}

template<typename E>
Set<E> _DelegatingIterableBaseCls<E>::toSet() {
    return _base()->toSet();
}

template<typename E>
Iterable<E> _DelegatingIterableBaseCls<E>::where(bool test(E ) ) {
    return _base()->where(test);
}

template<typename E>
template<typename T>
Iterable<T> _DelegatingIterableBaseCls<E>::whereType() {
    return _base()-><T>whereType();
}

template<typename E>
String _DelegatingIterableBaseCls<E>::toString() {
    return _base()->toString();
}

template<typename E>
DelegatingIterableCls<E>::DelegatingIterableCls(Iterable<E> base) {
    {
        _base = base;
    }
}

template<typename E>
template<typename E>
Iterable<E> DelegatingIterableCls<E>::typed(Iterable base) {
    return base-><E>cast();
}

template<typename E>
DelegatingListCls<E>::DelegatingListCls(List<E> base) {
    {
        _base = base;
    }
}

template<typename E>
template<typename E>
List<E> DelegatingListCls<E>::typed(List base) {
    return base-><E>cast();
}

template<typename E>
E DelegatingListCls<E>::[](int index) {
    return _base[index];
}

template<typename E>
void DelegatingListCls<E>::[]=(int index, E value) {
    _base[index] = value;
}

template<typename E>
List<E> DelegatingListCls<E>::+(List<E> other) {
    return _base + other;
}

template<typename E>
void DelegatingListCls<E>::add(E value) {
    _base->add(value);
}

template<typename E>
void DelegatingListCls<E>::addAll(Iterable<E> iterable) {
    _base->addAll(iterable);
}

template<typename E>
Map<int, E> DelegatingListCls<E>::asMap() {
    return _base->asMap();
}

template<typename E>
template<typename T>
List<T> DelegatingListCls<E>::cast() {
    return _base-><T>cast();
}

template<typename E>
void DelegatingListCls<E>::clear() {
    _base->clear();
}

template<typename E>
void DelegatingListCls<E>::fillRange(int end, E fillValue, int start) {
    _base->fillRange(start, end, fillValue);
}

template<typename E>
void DelegatingListCls<E>::first(E value) {
    if (isEmpty)     {
        ;
    }
    this[0] = value;
}

template<typename E>
Iterable<E> DelegatingListCls<E>::getRange(int end, int start) {
    return _base->getRange(start, end);
}

template<typename E>
int DelegatingListCls<E>::indexOf(E element, int start) {
    return _base->indexOf(element, start);
}

template<typename E>
int DelegatingListCls<E>::indexWhere(int start, bool test(E ) ) {
    return _base->indexWhere(test, start);
}

template<typename E>
void DelegatingListCls<E>::insert(E element, int index) {
    _base->insert(index, element);
}

template<typename E>
void DelegatingListCls<E>::insertAll(int index, Iterable<E> iterable) {
    _base->insertAll(index, iterable);
}

template<typename E>
void DelegatingListCls<E>::last(E value) {
    if (isEmpty)     {
        ;
    }
    this[length - 1] = value;
}

template<typename E>
int DelegatingListCls<E>::lastIndexOf(E element, int start) {
    return _base->lastIndexOf(element, start);
}

template<typename E>
int DelegatingListCls<E>::lastIndexWhere(int start, bool test(E ) ) {
    return _base->lastIndexWhere(test, start);
}

template<typename E>
void DelegatingListCls<E>::length(int newLength) {
    _base->length() = newLength;
}

template<typename E>
bool DelegatingListCls<E>::remove(Object value) {
    return _base->remove(value);
}

template<typename E>
E DelegatingListCls<E>::removeAt(int index) {
    return _base->removeAt(index);
}

template<typename E>
E DelegatingListCls<E>::removeLast() {
    return _base->removeLast();
}

template<typename E>
void DelegatingListCls<E>::removeRange(int end, int start) {
    _base->removeRange(start, end);
}

template<typename E>
void DelegatingListCls<E>::removeWhere(bool test(E ) ) {
    _base->removeWhere(test);
}

template<typename E>
void DelegatingListCls<E>::replaceRange(int end, Iterable<E> iterable, int start) {
    _base->replaceRange(start, end, iterable);
}

template<typename E>
void DelegatingListCls<E>::retainWhere(bool test(E ) ) {
    _base->retainWhere(test);
}

template<typename E>
template<typename T>
List<T> DelegatingListCls<E>::retype() {
    return <T>cast();
}

template<typename E>
Iterable<E> DelegatingListCls<E>::reversed() {
    return _base->reversed();
}

template<typename E>
void DelegatingListCls<E>::setAll(int index, Iterable<E> iterable) {
    _base->setAll(index, iterable);
}

template<typename E>
void DelegatingListCls<E>::setRange(int end, Iterable<E> iterable, int skipCount, int start) {
    _base->setRange(start, end, iterable, skipCount);
}

template<typename E>
void DelegatingListCls<E>::shuffle(Random random) {
    _base->shuffle(random);
}

template<typename E>
void DelegatingListCls<E>::sort(int compare(E , E ) ) {
    _base->sort(compare);
}

template<typename E>
List<E> DelegatingListCls<E>::sublist(int end, int start) {
    return _base->sublist(start, end);
}

template<typename E>
DelegatingSetCls<E>::DelegatingSetCls(Set<E> base) {
    {
        _base = base;
    }
}

template<typename E>
template<typename E>
Set<E> DelegatingSetCls<E>::typed(Set base) {
    return base-><E>cast();
}

template<typename E>
bool DelegatingSetCls<E>::add(E value) {
    return _base->add(value);
}

template<typename E>
void DelegatingSetCls<E>::addAll(Iterable<E> elements) {
    _base->addAll(elements);
}

template<typename E>
template<typename T>
Set<T> DelegatingSetCls<E>::cast() {
    return _base-><T>cast();
}

template<typename E>
void DelegatingSetCls<E>::clear() {
    _base->clear();
}

template<typename E>
bool DelegatingSetCls<E>::containsAll(Iterable<Object> other) {
    return _base->containsAll(other);
}

template<typename E>
Set<E> DelegatingSetCls<E>::difference(Set<Object> other) {
    return _base->difference(other);
}

template<typename E>
Set<E> DelegatingSetCls<E>::intersection(Set<Object> other) {
    return _base->intersection(other);
}

template<typename E>
E DelegatingSetCls<E>::lookup(Object element) {
    return _base->lookup(element);
}

template<typename E>
bool DelegatingSetCls<E>::remove(Object value) {
    return _base->remove(value);
}

template<typename E>
void DelegatingSetCls<E>::removeAll(Iterable<Object> elements) {
    _base->removeAll(elements);
}

template<typename E>
void DelegatingSetCls<E>::removeWhere(bool test(E ) ) {
    _base->removeWhere(test);
}

template<typename E>
void DelegatingSetCls<E>::retainAll(Iterable<Object> elements) {
    _base->retainAll(elements);
}

template<typename E>
template<typename T>
Set<T> DelegatingSetCls<E>::retype() {
    return <T>cast();
}

template<typename E>
void DelegatingSetCls<E>::retainWhere(bool test(E ) ) {
    _base->retainWhere(test);
}

template<typename E>
Set<E> DelegatingSetCls<E>::union(Set<E> other) {
    return _base->union(other);
}

template<typename E>
Set<E> DelegatingSetCls<E>::toSet() {
    return <E>make<DelegatingSetCls>(_base->toSet());
}

template<typename E>
DelegatingQueueCls<E>::DelegatingQueueCls(Queue<E> queue) {
    {
        _base = queue;
    }
}

template<typename E>
template<typename E>
Queue<E> DelegatingQueueCls<E>::typed(Queue base) {
    return base-><E>cast();
}

template<typename E>
void DelegatingQueueCls<E>::add(E value) {
    _base->add(value);
}

template<typename E>
void DelegatingQueueCls<E>::addAll(Iterable<E> iterable) {
    _base->addAll(iterable);
}

template<typename E>
void DelegatingQueueCls<E>::addFirst(E value) {
    _base->addFirst(value);
}

template<typename E>
void DelegatingQueueCls<E>::addLast(E value) {
    _base->addLast(value);
}

template<typename E>
template<typename T>
Queue<T> DelegatingQueueCls<E>::cast() {
    return _base-><T>cast();
}

template<typename E>
void DelegatingQueueCls<E>::clear() {
    _base->clear();
}

template<typename E>
bool DelegatingQueueCls<E>::remove(Object object) {
    return _base->remove(object);
}

template<typename E>
void DelegatingQueueCls<E>::removeWhere(bool test(E ) ) {
    _base->removeWhere(test);
}

template<typename E>
void DelegatingQueueCls<E>::retainWhere(bool test(E ) ) {
    _base->retainWhere(test);
}

template<typename E>
template<typename T>
Queue<T> DelegatingQueueCls<E>::retype() {
    return <T>cast();
}

template<typename E>
E DelegatingQueueCls<E>::removeFirst() {
    return _base->removeFirst();
}

template<typename E>
E DelegatingQueueCls<E>::removeLast() {
    return _base->removeLast();
}

template<typename K, typename V>
DelegatingMapCls<K, V>::DelegatingMapCls(Map<K, V> base) {
    {
        _base = base;
    }
}

template<typename K, typename V>
template<typename K, typename V>
Map<K, V> DelegatingMapCls<K, V>::typed(Map base) {
    return base-><K, V>cast();
}

template<typename K, typename V>
V DelegatingMapCls<K, V>::[](Object key) {
    return _base[key];
}

template<typename K, typename V>
void DelegatingMapCls<K, V>::[]=(K key, V value) {
    _base[key] = value;
}

template<typename K, typename V>
void DelegatingMapCls<K, V>::addAll(Map<K, V> other) {
    _base->addAll(other);
}

template<typename K, typename V>
void DelegatingMapCls<K, V>::addEntries(Iterable<MapEntry<K, V>> entries) {
    _base->addEntries(entries);
}

template<typename K, typename V>
void DelegatingMapCls<K, V>::clear() {
    _base->clear();
}

template<typename K, typename V>
template<typename K2, typename V2>
Map<K2, V2> DelegatingMapCls<K, V>::cast() {
    return _base-><K2, V2>cast();
}

template<typename K, typename V>
bool DelegatingMapCls<K, V>::containsKey(Object key) {
    return _base->containsKey(key);
}

template<typename K, typename V>
bool DelegatingMapCls<K, V>::containsValue(Object value) {
    return _base->containsValue(value);
}

template<typename K, typename V>
Iterable<MapEntry<K, V>> DelegatingMapCls<K, V>::entries() {
    return _base->entries();
}

template<typename K, typename V>
void DelegatingMapCls<K, V>::forEach(void f(K , V ) ) {
    _base->forEach(f);
}

template<typename K, typename V>
bool DelegatingMapCls<K, V>::isEmpty() {
    return _base->isEmpty();
}

template<typename K, typename V>
bool DelegatingMapCls<K, V>::isNotEmpty() {
    return _base->isNotEmpty();
}

template<typename K, typename V>
Iterable<K> DelegatingMapCls<K, V>::keys() {
    return _base->keys();
}

template<typename K, typename V>
int DelegatingMapCls<K, V>::length() {
    return _base->length();
}

template<typename K, typename V>
template<typename K2, typename V2>
Map<K2, V2> DelegatingMapCls<K, V>::map(MapEntry<K2, V2> transform(K , V ) ) {
    return _base->map(transform);
}

template<typename K, typename V>
V DelegatingMapCls<K, V>::putIfAbsent(V ifAbsent() , K key) {
    return _base->putIfAbsent(key, ifAbsent);
}

template<typename K, typename V>
V DelegatingMapCls<K, V>::remove(Object key) {
    return _base->remove(key);
}

template<typename K, typename V>
void DelegatingMapCls<K, V>::removeWhere(bool test(K , V ) ) {
    return _base->removeWhere(test);
}

template<typename K, typename V>
template<typename K2, typename V2>
Map<K2, V2> DelegatingMapCls<K, V>::retype() {
    return <K2, V2>cast();
}

template<typename K, typename V>
Iterable<V> DelegatingMapCls<K, V>::values() {
    return _base->values();
}

template<typename K, typename V>
String DelegatingMapCls<K, V>::toString() {
    return _base->toString();
}

template<typename K, typename V>
V DelegatingMapCls<K, V>::update(V ifAbsent() , K key, V update(V ) ) {
    return _base->update(key, updateifAbsent);
}

template<typename K, typename V>
void DelegatingMapCls<K, V>::updateAll(V update(K , V ) ) {
    return _base->updateAll(update);
}

template<typename E>
template<typename T>
Set<T> MapKeySetCls<E>::cast() {
    if (is<MapKeySet<T>>(this)) {
        return as<MapKeySet<T>>(as<MapKeySetCls>(this));
    }
    return SetCls-><E, T>castFrom(this);
}

template<typename E>
bool MapKeySetCls<E>::contains(Object element) {
    return _baseMap->containsKey(element);
}

template<typename E>
bool MapKeySetCls<E>::isEmpty() {
    return _baseMap->isEmpty();
}

template<typename E>
bool MapKeySetCls<E>::isNotEmpty() {
    return _baseMap->isNotEmpty();
}

template<typename E>
int MapKeySetCls<E>::length() {
    return _baseMap->length();
}

template<typename E>
String MapKeySetCls<E>::toString() {
    return SetBaseCls->setToString(this);
}

template<typename E>
bool MapKeySetCls<E>::containsAll(Iterable<Object> other) {
    return other->every(contains);
}

template<typename E>
Set<E> MapKeySetCls<E>::difference(Set<Object> other) {
    return where([=] (Unknown  element)     {
        !other->contains(element);
    })->toSet();
}

template<typename E>
Set<E> MapKeySetCls<E>::intersection(Set<Object> other) {
    return where(other->contains)->toSet();
}

template<typename E>
E MapKeySetCls<E>::lookup(Object element) {
    return ;
}

template<typename E>
template<typename T>
Set<T> MapKeySetCls<E>::retype() {
    return SetCls-><E, T>castFrom(this);
}

template<typename E>
Set<E> MapKeySetCls<E>::union(Set<E> other) {
    return _c1;
}

template<typename E>
Iterable<E> MapKeySetCls<E>::_base() {
    return _baseMap->keys();
}

template<typename K, typename V>
template<typename T>
Set<T> MapValueSetCls<K, V>::cast() {
    if (is<Set<T>>(this)) {
            auto _c1 = toSet();    _c1.addAll(other);return as<Set<T>>(as<SetCls>(this));
    }
    return SetCls-><V, T>castFrom(this);
}

template<typename K, typename V>
bool MapValueSetCls<K, V>::contains(Object element) {
    if (!is<V>(element))     {
        return false;
    }
    auto key = _keyForValue(element);
    return _baseMap->containsKey(key);
}

template<typename K, typename V>
bool MapValueSetCls<K, V>::isEmpty() {
    return _baseMap->isEmpty();
}

template<typename K, typename V>
bool MapValueSetCls<K, V>::isNotEmpty() {
    return _baseMap->isNotEmpty();
}

template<typename K, typename V>
int MapValueSetCls<K, V>::length() {
    return _baseMap->length();
}

template<typename K, typename V>
String MapValueSetCls<K, V>::toString() {
    return toSet()->toString();
}

template<typename K, typename V>
bool MapValueSetCls<K, V>::add(V value) {
    auto key = _keyForValue(value);
    auto result = false;
    _baseMap->putIfAbsent(key, [=] () {
        result = true;
        return value;
    });
    return result;
}

template<typename K, typename V>
void MapValueSetCls<K, V>::addAll(Iterable<V> elements) {
    return elements->forEach(add);
}

template<typename K, typename V>
void MapValueSetCls<K, V>::clear() {
    return _baseMap->clear();
}

template<typename K, typename V>
bool MapValueSetCls<K, V>::containsAll(Iterable<Object> other) {
    return other->every(contains);
}

template<typename K, typename V>
Set<V> MapValueSetCls<K, V>::difference(Set<Object> other) {
    return where([=] (Unknown  element)     {
        !other->contains(element);
    })->toSet();
}

template<typename K, typename V>
Set<V> MapValueSetCls<K, V>::intersection(Set<Object> other) {
    return where(other->contains)->toSet();
}

template<typename K, typename V>
V MapValueSetCls<K, V>::lookup(Object element) {
    if (!is<V>(element))     {
        return nullptr;
    }
    auto key = _keyForValue(element);
    return _baseMap[key];
}

template<typename K, typename V>
bool MapValueSetCls<K, V>::remove(Object element) {
    if (!is<V>(element))     {
        return false;
    }
    auto key = _keyForValue(element);
    if (!_baseMap->containsKey(key))     {
        return false;
    }
    _baseMap->remove(key);
    return true;
}

template<typename K, typename V>
void MapValueSetCls<K, V>::removeAll(Iterable<Object> elements) {
    return elements->forEach(remove);
}

template<typename K, typename V>
void MapValueSetCls<K, V>::removeWhere(bool test(V ) ) {
    auto toRemove = makeList();
    _baseMap->forEach([=] (Unknown  key,Unknown  value) {
        if (test(value))         {
            toRemove->add(key);
        }
    });
    toRemove->forEach(_baseMap->remove);
}

template<typename K, typename V>
void MapValueSetCls<K, V>::retainAll(Iterable<Object> elements) {
    auto valuesToRetain = <V>identity();
    for (auto element : elements) {
        if (!is<V>(element))         {
            continue;
        }
        auto key = _keyForValue(element);
        if (!_baseMap->containsKey(key))         {
            continue;
        }
        valuesToRetain->add(_baseMap[key] or as<V>(nullptr));
    }
    auto keysToRemove = makeList();
    _baseMap->forEach([=] (Unknown  k,Unknown  v) {
        if (!valuesToRetain->contains(v))         {
            keysToRemove->add(k);
        }
    });
    keysToRemove->forEach(_baseMap->remove);
}

template<typename K, typename V>
void MapValueSetCls<K, V>::retainWhere(bool test(V ) ) {
    return removeWhere([=] (Unknown  element)     {
        !test(element);
    });
}

template<typename K, typename V>
template<typename T>
Set<T> MapValueSetCls<K, V>::retype() {
    return SetCls-><V, T>castFrom(this);
}

template<typename K, typename V>
Set<V> MapValueSetCls<K, V>::union(Set<V> other) {
    return _c1;
}

template<typename K, typename V>
Iterable<V> MapValueSetCls<K, V>::_base() {
    return _baseMap->values();
}
