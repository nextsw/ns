#include "cast.hpp"
template<typename S, typename T> Iterator<T> _CastIterableBaseCls<S, T>::iterator() {
    return <S, T>make<CastIteratorCls>(_source()->iterator());
}

template<typename S, typename T> int _CastIterableBaseCls<S, T>::length() {
    return _source()->length();
}

template<typename S, typename T> bool _CastIterableBaseCls<S, T>::isEmpty() {
    return _source()->isEmpty();
}

template<typename S, typename T> bool _CastIterableBaseCls<S, T>::isNotEmpty() {
    return _source()->isNotEmpty();
}

template<typename S, typename T> Iterable<T> _CastIterableBaseCls<S, T>::skip(int count) {
    return <S, T>make<CastIterableCls>(_source()->skip(count));
}

template<typename S, typename T> Iterable<T> _CastIterableBaseCls<S, T>::take(int count) {
    return <S, T>make<CastIterableCls>(_source()->take(count));
}

template<typename S, typename T> T _CastIterableBaseCls<S, T>::elementAt(int index) {
    return as<T>(_source()->elementAt(index));
}

template<typename S, typename T> T _CastIterableBaseCls<S, T>::first() {
    return as<T>(_source()->first());
}

template<typename S, typename T> T _CastIterableBaseCls<S, T>::last() {
    return as<T>(_source()->last());
}

template<typename S, typename T> T _CastIterableBaseCls<S, T>::single() {
    return as<T>(_source()->single());
}

template<typename S, typename T> bool _CastIterableBaseCls<S, T>::contains(Object other) {
    return _source()->contains(other);
}

template<typename S, typename T> T _CastIterableBaseCls<S, T>::lastWhere(T orElse() , bool test(T element) ) {
    return as<T>(_source()->lastWhere([=] (S element)     {
        test(as<T>(element));
    }(orElse == nullptr)? nullptr : [=] ()     {
        as<S>(orElse());
    }));
}

template<typename S, typename T> String _CastIterableBaseCls<S, T>::toString() {
    return _source()->toString();
}

template<typename S, typename T> bool CastIteratorCls<S, T>::moveNext() {
    return _source->moveNext();
}

template<typename S, typename T> T CastIteratorCls<S, T>::current() {
    return as<T>(_source->current());
}

template<typename S, typename T> CastIterableCls<S, T>::CastIterableCls(Iterable<S> source) {
    {
        if (is<EfficientLengthIterable<S>>(source)) {
            return <S, T>make<_EfficientLengthCastIterableCls>(as<EfficientLengthIterableCls>(source));
        }
        return <S, T>_(source);
    }
}

template<typename S, typename T> Iterable<R> CastIterableCls<S, T>::casttemplate<typename R> () {
    return <S, R>make<CastIterableCls>(_source);
}

template<typename S, typename T> _EfficientLengthCastIterableCls<S, T>::_EfficientLengthCastIterableCls(EfficientLengthIterable<S> source) {
    {
        super->_(source);
    }
}

template<typename S, typename T> T _CastListBaseCls<S, T>::[](int index) {
    return as<T>(_source()[index]);
}

template<typename S, typename T> void _CastListBaseCls<S, T>::[]=(int index, T value) {
    _source()[index] = as<S>(value);
}

template<typename S, typename T> void _CastListBaseCls<S, T>::length(int length) {
    _source()->length = length;
}

template<typename S, typename T> void _CastListBaseCls<S, T>::add(T value) {
    _source()->add(as<S>(value));
}

template<typename S, typename T> void _CastListBaseCls<S, T>::addAll(Iterable<T> values) {
    _source()->addAll(<T, S>make<CastIterableCls>(values));
}

template<typename S, typename T> void _CastListBaseCls<S, T>::sort(int compare(T v1, T v2) ) {
    _source()->sort(compare == nullptr? nullptr : [=] (S v1,S v2)     {
        compare(as<T>(v1), as<T>(v2));
    });
}

template<typename S, typename T> void _CastListBaseCls<S, T>::shuffle(Random random) {
    _source()->shuffle(random);
}

template<typename S, typename T> void _CastListBaseCls<S, T>::insert(T element, int index) {
    _source()->insert(index, as<S>(element));
}

template<typename S, typename T> void _CastListBaseCls<S, T>::insertAll(Iterable<T> elements, int index) {
    _source()->insertAll(index, <T, S>make<CastIterableCls>(elements));
}

template<typename S, typename T> void _CastListBaseCls<S, T>::setAll(Iterable<T> elements, int index) {
    _source()->setAll(index, <T, S>make<CastIterableCls>(elements));
}

template<typename S, typename T> bool _CastListBaseCls<S, T>::remove(Object value) {
    return _source()->remove(value);
}

template<typename S, typename T> T _CastListBaseCls<S, T>::removeAt(int index) {
    return as<T>(_source()->removeAt(index));
}

template<typename S, typename T> T _CastListBaseCls<S, T>::removeLast() {
    return as<T>(_source()->removeLast());
}

template<typename S, typename T> void _CastListBaseCls<S, T>::removeWhere(bool test(T element) ) {
    _source()->removeWhere([=] (S element)     {
        test(as<T>(element));
    });
}

template<typename S, typename T> void _CastListBaseCls<S, T>::retainWhere(bool test(T element) ) {
    _source()->retainWhere([=] (S element)     {
        test(as<T>(element));
    });
}

template<typename S, typename T> Iterable<T> _CastListBaseCls<S, T>::getRange(int end, int start) {
    return <S, T>make<CastIterableCls>(_source()->getRange(start, end));
}

template<typename S, typename T> void _CastListBaseCls<S, T>::setRange(int end, Iterable<T> iterable, int skipCount, int start) {
    _source()->setRange(start, end, <T, S>make<CastIterableCls>(iterable), skipCount);
}

template<typename S, typename T> void _CastListBaseCls<S, T>::removeRange(int end, int start) {
    _source()->removeRange(start, end);
}

template<typename S, typename T> void _CastListBaseCls<S, T>::fillRange(int end, T fillValue, int start) {
    _source()->fillRange(start, end, as<S>(fillValue));
}

template<typename S, typename T> void _CastListBaseCls<S, T>::replaceRange(int end, Iterable<T> replacement, int start) {
    _source()->replaceRange(start, end, <T, S>make<CastIterableCls>(replacement));
}

template<typename S, typename T> List<R> CastListCls<S, T>::casttemplate<typename R> () {
    return <S, R>make<CastListCls>(_source);
}

template<typename S, typename T> Set<R> CastSetCls<S, T>::casttemplate<typename R> () {
    return <S, R>make<CastSetCls>(_source, _emptySet);
}

template<typename S, typename T> bool CastSetCls<S, T>::add(T value) {
    return _source->add(as<S>(value));
}

template<typename S, typename T> void CastSetCls<S, T>::addAll(Iterable<T> elements) {
    _source->addAll(<T, S>make<CastIterableCls>(elements));
}

template<typename S, typename T> bool CastSetCls<S, T>::remove(Object object) {
    return _source->remove(object);
}

template<typename S, typename T> void CastSetCls<S, T>::removeAll(Iterable<Object> objects) {
    _source->removeAll(objects);
}

template<typename S, typename T> void CastSetCls<S, T>::retainAll(Iterable<Object> objects) {
    _source->retainAll(objects);
}

template<typename S, typename T> void CastSetCls<S, T>::removeWhere(bool test(T element) ) {
    _source->removeWhere([=] (S element)     {
        test(as<T>(element));
    });
}

template<typename S, typename T> void CastSetCls<S, T>::retainWhere(bool test(T element) ) {
    _source->retainWhere([=] (S element)     {
        test(as<T>(element));
    });
}

template<typename S, typename T> bool CastSetCls<S, T>::containsAll(Iterable<Object> objects) {
    return _source->containsAll(objects);
}

template<typename S, typename T> Set<T> CastSetCls<S, T>::intersection(Set<Object> other) {
    if (_emptySet != nullptr)     {
        return _conditionalAdd(other, true);
    }
    return <S, T>make<CastSetCls>(_source->intersection(other), nullptr);
}

template<typename S, typename T> Set<T> CastSetCls<S, T>::difference(Set<Object> other) {
    if (_emptySet != nullptr)     {
        return _conditionalAdd(other, false);
    }
    return <S, T>make<CastSetCls>(_source->difference(other), nullptr);
}

template<typename S, typename T> Set<T> CastSetCls<S, T>::union(Set<T> other) {
    return _c1;
}

template<typename S, typename T> void CastSetCls<S, T>::clear() {
    auto _c1 = _clone();_c1.addAll(other);_source->clear();
}

template<typename S, typename T> Set<T> CastSetCls<S, T>::toSet() {
    return _clone();
}

template<typename S, typename T> T CastSetCls<S, T>::lookup(Object key) {
    return as<T>(_source->lookup(key));
}

template<typename S, typename T> Set<T> CastSetCls<S, T>::_conditionalAdd(Set<Object> other, bool otherContains) {
    auto emptySet = _emptySet;
    Set<T> result = (emptySet == nullptr)? <T>make<SetCls>() : <T>emptySet();
    for (auto element : _source) {
        T castElement = as<T>(element);
        if (otherContains == other->contains(castElement))         {
            result->add(castElement);
        }
    }
    return result;
}

template<typename S, typename T> Set<T> CastSetCls<S, T>::_clone() {
    auto emptySet = _emptySet;
    Set<T> result = (emptySet == nullptr)? <T>make<SetCls>() : <T>emptySet();
    result->addAll(this);
    return result;
}

template<typename SK, typename SV, typename K, typename V> Map<RK, RV> CastMapCls<SK, SV, K, V>::casttemplate<typename RK, typename RV> () {
    return <SK, SV, RK, RV>make<CastMapCls>(_source);
}

template<typename SK, typename SV, typename K, typename V> bool CastMapCls<SK, SV, K, V>::containsValue(Object value) {
    return _source->containsValue(value);
}

template<typename SK, typename SV, typename K, typename V> bool CastMapCls<SK, SV, K, V>::containsKey(Object key) {
    return _source->containsKey(key);
}

template<typename SK, typename SV, typename K, typename V> V CastMapCls<SK, SV, K, V>::[](Object key) {
    return as<V>(_source[key]);
}

template<typename SK, typename SV, typename K, typename V> void CastMapCls<SK, SV, K, V>::[]=(K key, V value) {
    _source[as<SK>(key)] = as<SV>(value);
}

template<typename SK, typename SV, typename K, typename V> V CastMapCls<SK, SV, K, V>::putIfAbsent(V ifAbsent() , K key) {
    return as<V>(_source->putIfAbsent(as<SK>(key), [=] ()     {
        as<SV>(ifAbsent());
    }));
}

template<typename SK, typename SV, typename K, typename V> void CastMapCls<SK, SV, K, V>::addAll(Map<K, V> other) {
    _source->addAll(<K, V, SK, SV>make<CastMapCls>(other));
}

template<typename SK, typename SV, typename K, typename V> V CastMapCls<SK, SV, K, V>::remove(Object key) {
    return as<V>(_source->remove(key));
}

template<typename SK, typename SV, typename K, typename V> void CastMapCls<SK, SV, K, V>::clear() {
    _source->clear();
}

template<typename SK, typename SV, typename K, typename V> void CastMapCls<SK, SV, K, V>::forEach(void f(K key, V value) ) {
    _source->forEach([=] (SK key,SV value) {
        f(as<K>(key), as<V>(value));
    });
}

template<typename SK, typename SV, typename K, typename V> Iterable<K> CastMapCls<SK, SV, K, V>::keys() {
    return <SK, K>make<CastIterableCls>(_source->keys());
}

template<typename SK, typename SV, typename K, typename V> Iterable<V> CastMapCls<SK, SV, K, V>::values() {
    return <SV, V>make<CastIterableCls>(_source->values());
}

template<typename SK, typename SV, typename K, typename V> int CastMapCls<SK, SV, K, V>::length() {
    return _source->length();
}

template<typename SK, typename SV, typename K, typename V> bool CastMapCls<SK, SV, K, V>::isEmpty() {
    return _source->isEmpty();
}

template<typename SK, typename SV, typename K, typename V> bool CastMapCls<SK, SV, K, V>::isNotEmpty() {
    return _source->isNotEmpty();
}

template<typename SK, typename SV, typename K, typename V> V CastMapCls<SK, SV, K, V>::update(V ifAbsent() , K key, V update(V value) ) {
    return as<V>(_source->update(as<SK>(key), [=] (SV value)     {
        as<SV>(update(as<V>(value)));
    }(ifAbsent == nullptr)? nullptr : [=] ()     {
        as<SV>(ifAbsent());
    }));
}

template<typename SK, typename SV, typename K, typename V> void CastMapCls<SK, SV, K, V>::updateAll(V update(K key, V value) ) {
    _source->updateAll([=] (SK key,SV value)     {
        as<SV>(update(as<K>(key), as<V>(value)));
    });
}

template<typename SK, typename SV, typename K, typename V> Iterable<MapEntry<K, V>> CastMapCls<SK, SV, K, V>::entries() {
    return _source->entries()-><MapEntry<K, V>>map([=] (MapEntry<SK, SV> e)     {
        <K, V>make<MapEntryCls>(as<K>(e->key), as<V>(e->value));
    });
}

template<typename SK, typename SV, typename K, typename V> void CastMapCls<SK, SV, K, V>::addEntries(Iterable<MapEntry<K, V>> entries) {
    for (auto entry : entries) {
        _source[as<SK>(entry->key)] = as<SV>(entry->value);
    }
}

template<typename SK, typename SV, typename K, typename V> void CastMapCls<SK, SV, K, V>::removeWhere(bool test(K key, V value) ) {
    _source->removeWhere([=] (SK key,SV value)     {
        test(as<K>(key), as<V>(value));
    });
}

template<typename S, typename T> Queue<R> CastQueueCls<S, T>::casttemplate<typename R> () {
    return <S, R>make<CastQueueCls>(_source);
}

template<typename S, typename T> T CastQueueCls<S, T>::removeFirst() {
    return as<T>(_source->removeFirst());
}

template<typename S, typename T> T CastQueueCls<S, T>::removeLast() {
    return as<T>(_source->removeLast());
}

template<typename S, typename T> void CastQueueCls<S, T>::add(T value) {
    _source->add(as<S>(value));
}

template<typename S, typename T> void CastQueueCls<S, T>::addFirst(T value) {
    _source->addFirst(as<S>(value));
}

template<typename S, typename T> void CastQueueCls<S, T>::addLast(T value) {
    _source->addLast(as<S>(value));
}

template<typename S, typename T> bool CastQueueCls<S, T>::remove(Object other) {
    return _source->remove(other);
}

template<typename S, typename T> void CastQueueCls<S, T>::addAll(Iterable<T> elements) {
    _source->addAll(<T, S>make<CastIterableCls>(elements));
}

template<typename S, typename T> void CastQueueCls<S, T>::removeWhere(bool test(T element) ) {
    _source->removeWhere([=] (S element)     {
        test(as<T>(element));
    });
}

template<typename S, typename T> void CastQueueCls<S, T>::retainWhere(bool test(T element) ) {
    _source->retainWhere([=] (S element)     {
        test(as<T>(element));
    });
}

template<typename S, typename T> void CastQueueCls<S, T>::clear() {
    _source->clear();
}
