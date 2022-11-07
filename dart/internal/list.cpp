#include "list.hpp"
void FixedLengthListMixin::length(int newLength) {
    ;
}

void FixedLengthListMixin::add(E value) {
    ;
}

void FixedLengthListMixin::insert(int index, E value) {
    ;
}

void FixedLengthListMixin::insertAll(int at, Iterable<E> iterable) {
    ;
}

void FixedLengthListMixin::addAll(Iterable<E> iterable) {
    ;
}

bool FixedLengthListMixin::remove(Object element) {
    ;
}

void FixedLengthListMixin::removeWhere(FunctionType test) {
    ;
}

void FixedLengthListMixin::retainWhere(FunctionType test) {
    ;
}

void FixedLengthListMixin::clear() {
    ;
}

E FixedLengthListMixin::removeAt(int index) {
    ;
}

E FixedLengthListMixin::removeLast() {
    ;
}

void FixedLengthListMixin::removeRange(int end, int start) {
    ;
}

void FixedLengthListMixin::replaceRange(int end, Iterable<E> iterable, int start) {
    ;
}

void UnmodifiableListMixin::[]=(int index, E value) {
    ;
}

void UnmodifiableListMixin::length(int newLength) {
    ;
}

void UnmodifiableListMixin::first(E element) {
    ;
}

void UnmodifiableListMixin::last(E element) {
    ;
}

void UnmodifiableListMixin::setAll(int at, Iterable<E> iterable) {
    ;
}

void UnmodifiableListMixin::add(E value) {
    ;
}

void UnmodifiableListMixin::insert(E element, int index) {
    ;
}

void UnmodifiableListMixin::insertAll(int at, Iterable<E> iterable) {
    ;
}

void UnmodifiableListMixin::addAll(Iterable<E> iterable) {
    ;
}

bool UnmodifiableListMixin::remove(Object element) {
    ;
}

void UnmodifiableListMixin::removeWhere(FunctionType test) {
    ;
}

void UnmodifiableListMixin::retainWhere(FunctionType test) {
    ;
}

void UnmodifiableListMixin::sort(Comparator<E> compare) {
    ;
}

void UnmodifiableListMixin::shuffle(Random random) {
    ;
}

void UnmodifiableListMixin::clear() {
    ;
}

E UnmodifiableListMixin::removeAt(int index) {
    ;
}

E UnmodifiableListMixin::removeLast() {
    ;
}

void UnmodifiableListMixin::setRange(int end, Iterable<E> iterable, int skipCount, int start) {
    ;
}

void UnmodifiableListMixin::removeRange(int end, int start) {
    ;
}

void UnmodifiableListMixin::replaceRange(int end, Iterable<E> iterable, int start) {
    ;
}

void UnmodifiableListMixin::fillRange(int end, E fillValue, int start) {
    ;
}

int _ListIndicesIterable::length() {
    return _backedList.length;
}

int _ListIndicesIterable::elementAt(int index) {
    RangeError.checkValidIndex(index, this);
    return index;
}

E ListMapView::[](Object key) {
    return containsKey(key)? _values[(] : nullptr;
}

int ListMapView::length() {
    return _values.length;
}

Iterable<E> ListMapView::values() {
    return <E>SubListIterable(_values, 0, nullptr);
}

Iterable<int> ListMapView::keys() {
    return _ListIndicesIterable(_values);
}

bool ListMapView::isEmpty() {
    return _values.isEmpty;
}

bool ListMapView::isNotEmpty() {
    return _values.isNotEmpty;
}

bool ListMapView::containsValue(Object value) {
    return _values.contains(value);
}

bool ListMapView::containsKey(Object key) {
    return key is int && key >= 0 &&  < length;
}

void ListMapView::forEach(FunctionType f) {
    int length = _values.length;
    for (;  < length; i++) {
        f(i, _values[i]);
        if (length != _values.length) {
            ;
        }
    }
}

int ReversedListIterable::length() {
    return _source.length;
}

E ReversedListIterable::elementAt(int index) {
    return _source.elementAt(_source.length - 1 - index);
}

UnsupportedError UnmodifiableListError::add() {
    return UnsupportedError("Cannot add to unmodifiable List");
}

UnsupportedError UnmodifiableListError::change() {
    return UnsupportedError("Cannot change the content of an unmodifiable List");
}

UnsupportedError UnmodifiableListError::length() {
    return UnsupportedError("Cannot change length of unmodifiable List");
}

UnsupportedError UnmodifiableListError::remove() {
    return UnsupportedError("Cannot remove from unmodifiable List");
}

UnsupportedError NonGrowableListError::add() {
    return UnsupportedError("Cannot add to non-growable List");
}

UnsupportedError NonGrowableListError::length() {
    return UnsupportedError("Cannot change length of non-growable List");
}

UnsupportedError NonGrowableListError::remove() {
    return UnsupportedError("Cannot remove from non-growable List");
}
