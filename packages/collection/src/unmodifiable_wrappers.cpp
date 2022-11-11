#include "unmodifiable_wrappers.hpp"
template<typename E>
NonGrowableListViewCls<E>::NonGrowableListViewCls(List<E> listBase) : DelegatingList<E>(listBase) {
}

template<typename E>
void NonGrowableListMixinCls<E>::length(int newLength) {
    return _throw();
}

template<typename E>
bool NonGrowableListMixinCls<E>::add(E value) {
    return _throw();
}

template<typename E>
void NonGrowableListMixinCls<E>::addAll(Iterable<E> iterable) {
    return _throw();
}

template<typename E>
void NonGrowableListMixinCls<E>::insert(int index, E element) {
    return _throw();
}

template<typename E>
void NonGrowableListMixinCls<E>::insertAll(int index, Iterable<E> iterable) {
    return _throw();
}

template<typename E>
bool NonGrowableListMixinCls<E>::remove(Object value) {
    return _throw();
}

template<typename E>
E NonGrowableListMixinCls<E>::removeAt(int index) {
    return _throw();
}

template<typename E>
E NonGrowableListMixinCls<E>::removeLast() {
    return _throw();
}

template<typename E>
void NonGrowableListMixinCls<E>::removeWhere(std::function<bool(E )> test) {
    return _throw();
}

template<typename E>
void NonGrowableListMixinCls<E>::retainWhere(std::function<bool(E )> test) {
    return _throw();
}

template<typename E>
void NonGrowableListMixinCls<E>::removeRange(int start, int end) {
    return _throw();
}

template<typename E>
void NonGrowableListMixinCls<E>::replaceRange(int start, int end, Iterable<E> iterable) {
    return _throw();
}

template<typename E>
void NonGrowableListMixinCls<E>::clear() {
    return _throw();
}

template<typename E>
Never NonGrowableListMixinCls<E>::_throw() {
    throw make<UnsupportedErrorCls>(__s("Cannot change the length of a fixed-length list"));
}

template<typename E>
UnmodifiableSetViewCls<E>::UnmodifiableSetViewCls(Set<E> setBase) : DelegatingSet<E>(setBase) {
}

template<typename E>
bool UnmodifiableSetMixinCls<E>::add(E value) {
    return _throw();
}

template<typename E>
void UnmodifiableSetMixinCls<E>::addAll(Iterable<E> elements) {
    return _throw();
}

template<typename E>
bool UnmodifiableSetMixinCls<E>::remove(Object value) {
    return _throw();
}

template<typename E>
void UnmodifiableSetMixinCls<E>::removeAll(Iterable<any> elements) {
    return _throw();
}

template<typename E>
void UnmodifiableSetMixinCls<E>::retainAll(Iterable<any> elements) {
    return _throw();
}

template<typename E>
void UnmodifiableSetMixinCls<E>::removeWhere(std::function<bool(E )> test) {
    return _throw();
}

template<typename E>
void UnmodifiableSetMixinCls<E>::retainWhere(std::function<bool(E )> test) {
    return _throw();
}

template<typename E>
void UnmodifiableSetMixinCls<E>::clear() {
    return _throw();
}

template<typename E>
Never UnmodifiableSetMixinCls<E>::_throw() {
    throw make<UnsupportedErrorCls>(__s("Cannot modify an unmodifiable Set"));
}

template<typename K, typename V>
void UnmodifiableMapMixinCls<K, V>::[]=(K key, V value) {
    return _throw();
}

template<typename K, typename V>
V UnmodifiableMapMixinCls<K, V>::putIfAbsent(K key, std::function<V()> ifAbsent) {
    return _throw();
}

template<typename K, typename V>
void UnmodifiableMapMixinCls<K, V>::addAll(Map<K, V> other) {
    return _throw();
}

template<typename K, typename V>
V UnmodifiableMapMixinCls<K, V>::remove(Object key) {
    return _throw();
}

template<typename K, typename V>
void UnmodifiableMapMixinCls<K, V>::clear() {
    return _throw();
}

template<typename K, typename V>
void UnmodifiableMapMixinCls<K, V>::first(_ ) {
    return _throw();
}

template<typename K, typename V>
void UnmodifiableMapMixinCls<K, V>::last(_ ) {
    return _throw();
}

template<typename K, typename V>
Never UnmodifiableMapMixinCls<K, V>::_throw() {
    throw make<UnsupportedErrorCls>(__s("Cannot modify an unmodifiable Map"));
}
