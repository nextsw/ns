#include "list.hpp"
template<typename E>
void FixedLengthListMixinCls<E>::length(int newLength) {
    throw make<UnsupportedErrorCls>(__s("Cannot change the length of a fixed-length list"));
}

template<typename E>
void FixedLengthListMixinCls<E>::add(E value) {
    throw make<UnsupportedErrorCls>(__s("Cannot add to a fixed-length list"));
}

template<typename E>
void FixedLengthListMixinCls<E>::insert(int index, E value) {
    throw make<UnsupportedErrorCls>(__s("Cannot add to a fixed-length list"));
}

template<typename E>
void FixedLengthListMixinCls<E>::insertAll(int at, Iterable<E> iterable) {
    throw make<UnsupportedErrorCls>(__s("Cannot add to a fixed-length list"));
}

template<typename E>
void FixedLengthListMixinCls<E>::addAll(Iterable<E> iterable) {
    throw make<UnsupportedErrorCls>(__s("Cannot add to a fixed-length list"));
}

template<typename E>
bool FixedLengthListMixinCls<E>::remove(Object element) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}

template<typename E>
void FixedLengthListMixinCls<E>::removeWhere(std::function<bool(E element)> test) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}

template<typename E>
void FixedLengthListMixinCls<E>::retainWhere(std::function<bool(E element)> test) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}

template<typename E>
void FixedLengthListMixinCls<E>::clear() {
    throw make<UnsupportedErrorCls>(__s("Cannot clear a fixed-length list"));
}

template<typename E>
E FixedLengthListMixinCls<E>::removeAt(int index) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}

template<typename E>
E FixedLengthListMixinCls<E>::removeLast() {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}

template<typename E>
void FixedLengthListMixinCls<E>::removeRange(int start, int end) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}

template<typename E>
void FixedLengthListMixinCls<E>::replaceRange(int start, int end, Iterable<E> iterable) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::[]=(int index, E value) {
    throw make<UnsupportedErrorCls>(__s("Cannot modify an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::length(int newLength) {
    throw make<UnsupportedErrorCls>(__s("Cannot change the length of an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::first(E element) {
    throw make<UnsupportedErrorCls>(__s("Cannot modify an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::last(E element) {
    throw make<UnsupportedErrorCls>(__s("Cannot modify an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::setAll(int at, Iterable<E> iterable) {
    throw make<UnsupportedErrorCls>(__s("Cannot modify an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::add(E value) {
    throw make<UnsupportedErrorCls>(__s("Cannot add to an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::insert(int index, E element) {
    throw make<UnsupportedErrorCls>(__s("Cannot add to an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::insertAll(int at, Iterable<E> iterable) {
    throw make<UnsupportedErrorCls>(__s("Cannot add to an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::addAll(Iterable<E> iterable) {
    throw make<UnsupportedErrorCls>(__s("Cannot add to an unmodifiable list"));
}

template<typename E>
bool UnmodifiableListMixinCls<E>::remove(Object element) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::removeWhere(std::function<bool(E element)> test) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::retainWhere(std::function<bool(E element)> test) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::sort(Comparator<E> compare) {
    throw make<UnsupportedErrorCls>(__s("Cannot modify an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::shuffle(Random random) {
    throw make<UnsupportedErrorCls>(__s("Cannot modify an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::clear() {
    throw make<UnsupportedErrorCls>(__s("Cannot clear an unmodifiable list"));
}

template<typename E>
E UnmodifiableListMixinCls<E>::removeAt(int index) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from an unmodifiable list"));
}

template<typename E>
E UnmodifiableListMixinCls<E>::removeLast() {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::setRange(int start, int end, Iterable<E> iterable, int skipCount) {
    throw make<UnsupportedErrorCls>(__s("Cannot modify an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::removeRange(int start, int end) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::replaceRange(int start, int end, Iterable<E> iterable) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from an unmodifiable list"));
}

template<typename E>
void UnmodifiableListMixinCls<E>::fillRange(int start, int end, E fillValue) {
    throw make<UnsupportedErrorCls>(__s("Cannot modify an unmodifiable list"));
}

int _ListIndicesIterableCls::length() {
    return _backedList->length();
}

int _ListIndicesIterableCls::elementAt(int index) {
    RangeErrorCls->checkValidIndex(index, this);
    return index;
}

template<typename E>
E ListMapViewCls<E>::[](Object key) {
    return containsKey(key)? _values[as<int>(key)] : nullptr;
}

template<typename E>
int ListMapViewCls<E>::length() {
    return _values->length();
}

template<typename E>
Iterable<E> ListMapViewCls<E>::values() {
    return <E>make<SubListIterableCls>(_values, 0, nullptr);
}

template<typename E>
Iterable<int> ListMapViewCls<E>::keys() {
    return make<_ListIndicesIterableCls>(_values);
}

template<typename E>
bool ListMapViewCls<E>::isEmpty() {
    return _values->isEmpty();
}

template<typename E>
bool ListMapViewCls<E>::isNotEmpty() {
    return _values->isNotEmpty();
}

template<typename E>
bool ListMapViewCls<E>::containsValue(Object value) {
    return _values->contains(value);
}

template<typename E>
bool ListMapViewCls<E>::containsKey(Object key) {
    return is<int>(key) && key >= 0 &&  < length();
}

template<typename E>
void ListMapViewCls<E>::forEach(std::function<void(int key, E value)> f) {
    int length = _values->length();
    for (;  < length; i++) {
        f(i, _values[i]);
        if (length != _values->length) {
            throw make<ConcurrentModificationErrorCls>(_values);
        }
    }
}

template<typename E>
int ReversedListIterableCls<E>::length() {
    return _source->length();
}

template<typename E>
E ReversedListIterableCls<E>::elementAt(int index) {
    return _source->elementAt(_source->length() - 1 - index);
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
