#ifndef EMPTY_UNMODIFIABLE_SET_H
#define EMPTY_UNMODIFIABLE_SET_H
#include <memory>

#include <collection/collection.hpp>
#include <collection/collection.hpp>



class EmptyUnmodifiableSet<E> : IterableBase<E> {
public:

     EmptyUnmodifiableSet();

    Iterator<E> iterator();

    int length();

    EmptyUnmodifiableSet<T> cast<T>();

    bool contains(Object element);

    bool containsAll(Iterable<Object> other);

    Iterable<E> followedBy(Iterable<E> other);

    E lookup(Object element);

    EmptyUnmodifiableSet<T> retype<T>();

    E singleWhere(FunctionType orElse, FunctionType test);

    Iterable<T> whereType<T>();

    Set<E> toSet();

    Set<E> union(Set<E> other);

    Set<E> intersection(Set<Object> other);

    Set<E> difference(Set<Object> other);

private:

};

#endif