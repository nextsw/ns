#include "list.hpp"
template<typename E> void FixedLengthListMixinCls<E>::length(int newLength) {
    ;
}

template<typename E> void FixedLengthListMixinCls<E>::add(E value) {
    ;
}

template<typename E> void FixedLengthListMixinCls<E>::insert(int index, E value) {
    ;
}

template<typename E> void FixedLengthListMixinCls<E>::insertAll(int at, Iterable<E> iterable) {
    ;
}

template<typename E> void FixedLengthListMixinCls<E>::addAll(Iterable<E> iterable) {
    ;
}

template<typename E> bool FixedLengthListMixinCls<E>::remove(Object element) {
    ;
}

template<typename E> void FixedLengthListMixinCls<E>::removeWhere(bool test(E element) ) {
    ;
}

template<typename E> void FixedLengthListMixinCls<E>::retainWhere(bool test(E element) ) {
    ;
}

template<typename E> void FixedLengthListMixinCls<E>::clear() {
    ;
}

template<typename E> E FixedLengthListMixinCls<E>::removeAt(int index) {
    ;
}

template<typename E> E FixedLengthListMixinCls<E>::removeLast() {
    ;
}

template<typename E> void FixedLengthListMixinCls<E>::removeRange(int end, int start) {
    ;
}

template<typename E> void FixedLengthListMixinCls<E>::replaceRange(int end, Iterable<E> iterable, int start) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::[]=(int index, E value) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::length(int newLength) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::first(E element) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::last(E element) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::setAll(int at, Iterable<E> iterable) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::add(E value) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::insert(E element, int index) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::insertAll(int at, Iterable<E> iterable) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::addAll(Iterable<E> iterable) {
    ;
}

template<typename E> bool UnmodifiableListMixinCls<E>::remove(Object element) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::removeWhere(bool test(E element) ) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::retainWhere(bool test(E element) ) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::sort(Comparator<E> compare) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::shuffle(Random random) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::clear() {
    ;
}

template<typename E> E UnmodifiableListMixinCls<E>::removeAt(int index) {
    ;
}

template<typename E> E UnmodifiableListMixinCls<E>::removeLast() {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::setRange(int end, Iterable<E> iterable, int skipCount, int start) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::removeRange(int end, int start) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::replaceRange(int end, Iterable<E> iterable, int start) {
    ;
}

template<typename E> void UnmodifiableListMixinCls<E>::fillRange(int end, E fillValue, int start) {
    ;
}

int _ListIndicesIterableCls::length() {
    return _backedList->length;
}

int _ListIndicesIterableCls::elementAt(int index) {
    RangeErrorCls->checkValidIndex(index, this);
    return index;
}

template<typename E> E ListMapViewCls<E>::[](Object key) {
    return containsKey(key)? _values[as<int>(key)] : nullptr;
}

template<typename E> int ListMapViewCls<E>::length() {
    return _values->length;
}

template<typename E> Iterable<E> ListMapViewCls<E>::values() {
    return <E>make<SubListIterableCls>(_values, 0, nullptr);
}

template<typename E> Iterable<int> ListMapViewCls<E>::keys() {
    return make<_ListIndicesIterableCls>(_values);
}

template<typename E> bool ListMapViewCls<E>::isEmpty() {
    return _values->isEmpty;
}

template<typename E> bool ListMapViewCls<E>::isNotEmpty() {
    return _values->isNotEmpty;
}

template<typename E> bool ListMapViewCls<E>::containsValue(Object value) {
    return _values->contains(value);
}

template<typename E> bool ListMapViewCls<E>::containsKey(Object key) {
    return is<int>(key) && key >= 0 &&  < length;
}

template<typename E> void ListMapViewCls<E>::forEach(void f(int key, E value) ) {
    int length = _values->length;
    for (;  < length; i++) {
        f(i, _values[i]);
        if (length != _values->length) {
            ;
        }
    }
}

template<typename E> int ReversedListIterableCls<E>::length() {
    return _source->length;
}

template<typename E> E ReversedListIterableCls<E>::elementAt(int index) {
    return _source->elementAt(_source->length - 1 - index);
}

UnsupportedError UnmodifiableListErrorCls::add() {
    return make<UnsupportedErrorCls>(__s("Cannot add to unmodifiable List"));
}

UnsupportedError UnmodifiableListErrorCls::change() {
    return make<UnsupportedErrorCls>(__s("Cannot change the content of an unmodifiable List"));
}

UnsupportedError UnmodifiableListErrorCls::length() {
    return make<UnsupportedErrorCls>(__s("Cannot change length of unmodifiable List"));
}

UnsupportedError UnmodifiableListErrorCls::remove() {
    return make<UnsupportedErrorCls>(__s("Cannot remove from unmodifiable List"));
}

UnsupportedError NonGrowableListErrorCls::add() {
    return make<UnsupportedErrorCls>(__s("Cannot add to non-growable List"));
}

UnsupportedError NonGrowableListErrorCls::length() {
    return make<UnsupportedErrorCls>(__s("Cannot change length of non-growable List"));
}

UnsupportedError NonGrowableListErrorCls::remove() {
    return make<UnsupportedErrorCls>(__s("Cannot remove from non-growable List"));
}
