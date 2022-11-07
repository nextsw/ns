#include "empty_unmodifiable_set.hpp"
Iterator<E> EmptyUnmodifiableSet::iterator() {
    return <E>empty().iterator;
}

int EmptyUnmodifiableSet::length() {
    return 0;
}

EmptyUnmodifiableSet<T> EmptyUnmodifiableSet::cast<T>() {
    return <T>EmptyUnmodifiableSet();
}

bool EmptyUnmodifiableSet::contains(Object element) {
    return false;
}

bool EmptyUnmodifiableSet::containsAll(Iterable<Object> other) {
    return other.isEmpty;
}

Iterable<E> EmptyUnmodifiableSet::followedBy(Iterable<E> other) {
    return DelegatingIterable(other);
}

E EmptyUnmodifiableSet::lookup(Object element) {
    return nullptr;
}

EmptyUnmodifiableSet<T> EmptyUnmodifiableSet::retype<T>() {
    return <T>EmptyUnmodifiableSet();
}

E EmptyUnmodifiableSet::singleWhere(FunctionType orElse, FunctionType test) {
    return orElse != nullptr? orElse() : ;
}

Iterable<T> EmptyUnmodifiableSet::whereType<T>() {
    return Iterable.empty();
}

Set<E> EmptyUnmodifiableSet::toSet() {
    return ;
}

Set<E> EmptyUnmodifiableSet::union(Set<E> other) {
    return Set.of(other);
}

Set<E> EmptyUnmodifiableSet::intersection(Set<Object> other) {
    return ;
}

Set<E> EmptyUnmodifiableSet::difference(Set<Object> other) {
    return ;
}
