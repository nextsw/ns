#include "unmodifiable_wrappers.hpp"
template<typename E>
NonGrowableListViewCls<E>::NonGrowableListViewCls(List<E> listBase) {
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
void NonGrowableListMixinCls<E>::insert(E element, int index) {
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
void NonGrowableListMixinCls<E>::removeWhere(bool test(E ) ) {
    return _throw();
}

template<typename E>
void NonGrowableListMixinCls<E>::retainWhere(bool test(E ) ) {
    return _throw();
}

template<typename E>
void NonGrowableListMixinCls<E>::removeRange(int end, int start) {
    return _throw();
}

template<typename E>
void NonGrowableListMixinCls<E>::replaceRange(int end, Iterable<E> iterable, int start) {
    return _throw();
}

template<typename E>
void NonGrowableListMixinCls<E>::clear() {
    return _throw();
}

template<typename E>
Never NonGrowableListMixinCls<E>::_throw() {
    ;
}

template<typename E>
UnmodifiableSetViewCls<E>::UnmodifiableSetViewCls(Set<E> setBase) {
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
void UnmodifiableSetMixinCls<E>::removeAll(Iterable elements) {
    return _throw();
}

template<typename E>
void UnmodifiableSetMixinCls<E>::retainAll(Iterable elements) {
    return _throw();
}

template<typename E>
void UnmodifiableSetMixinCls<E>::removeWhere(bool test(E ) ) {
    return _throw();
}

template<typename E>
void UnmodifiableSetMixinCls<E>::retainWhere(bool test(E ) ) {
    return _throw();
}

template<typename E>
void UnmodifiableSetMixinCls<E>::clear() {
    return _throw();
}

template<typename E>
Never UnmodifiableSetMixinCls<E>::_throw() {
    ;
}

template<typename K, typename V>
void UnmodifiableMapMixinCls<K, V>::[]=(K key, V value) {
    return _throw();
}

template<typename K, typename V>
V UnmodifiableMapMixinCls<K, V>::putIfAbsent(V ifAbsent() , K key) {
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
    ;
}
