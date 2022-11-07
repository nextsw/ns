#include "unmodifiable_wrappers.hpp"
NonGrowableListView::NonGrowableListView(List<E> listBase) {
    {
        super(listBase);
    }
}

void NonGrowableListMixin::length(int newLength) {
    return _throw();
}

bool NonGrowableListMixin::add(E value) {
    return _throw();
}

void NonGrowableListMixin::addAll(Iterable<E> iterable) {
    return _throw();
}

void NonGrowableListMixin::insert(E element, int index) {
    return _throw();
}

void NonGrowableListMixin::insertAll(int index, Iterable<E> iterable) {
    return _throw();
}

bool NonGrowableListMixin::remove(Object value) {
    return _throw();
}

E NonGrowableListMixin::removeAt(int index) {
    return _throw();
}

E NonGrowableListMixin::removeLast() {
    return _throw();
}

void NonGrowableListMixin::removeWhere(FunctionType test) {
    return _throw();
}

void NonGrowableListMixin::retainWhere(FunctionType test) {
    return _throw();
}

void NonGrowableListMixin::removeRange(int end, int start) {
    return _throw();
}

void NonGrowableListMixin::replaceRange(int end, Iterable<E> iterable, int start) {
    return _throw();
}

void NonGrowableListMixin::clear() {
    return _throw();
}

Never NonGrowableListMixin::_throw() {
    ;
}

UnmodifiableSetView::UnmodifiableSetView(Set<E> setBase) {
    {
        super(setBase);
    }
}

bool UnmodifiableSetMixin::add(E value) {
    return _throw();
}

void UnmodifiableSetMixin::addAll(Iterable<E> elements) {
    return _throw();
}

bool UnmodifiableSetMixin::remove(Object value) {
    return _throw();
}

void UnmodifiableSetMixin::removeAll(Iterable elements) {
    return _throw();
}

void UnmodifiableSetMixin::retainAll(Iterable elements) {
    return _throw();
}

void UnmodifiableSetMixin::removeWhere(FunctionType test) {
    return _throw();
}

void UnmodifiableSetMixin::retainWhere(FunctionType test) {
    return _throw();
}

void UnmodifiableSetMixin::clear() {
    return _throw();
}

Never UnmodifiableSetMixin::_throw() {
    ;
}
