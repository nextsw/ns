#include "empty_unmodifiable_set.hpp"
template<typename E>
Iterator<E> EmptyUnmodifiableSetCls<E>::iterator() {
    return <E>empty()->iterator;
}

template<typename E>
int EmptyUnmodifiableSetCls<E>::length() {
    return 0;
}

template<typename E>
template<typename T>
EmptyUnmodifiableSet<T> EmptyUnmodifiableSetCls<E>::cast() {
    return <T>make<EmptyUnmodifiableSetCls>();
}

template<typename E>
bool EmptyUnmodifiableSetCls<E>::contains(Object element) {
    return false;
}

template<typename E>
bool EmptyUnmodifiableSetCls<E>::containsAll(Iterable<Object> other) {
    return other->isEmpty();
}

template<typename E>
Iterable<E> EmptyUnmodifiableSetCls<E>::followedBy(Iterable<E> other) {
    return make<DelegatingIterableCls>(other);
}

template<typename E>
E EmptyUnmodifiableSetCls<E>::lookup(Object element) {
    return nullptr;
}

template<typename E>
template<typename T>
EmptyUnmodifiableSet<T> EmptyUnmodifiableSetCls<E>::retype() {
    return <T>make<EmptyUnmodifiableSetCls>();
}

template<typename E>
E EmptyUnmodifiableSetCls<E>::singleWhere(std::function<bool(E )> test, std::function<E()> orElse) {
    return orElse != nullptr? orElse() : throw make<StateErrorCls>(__s("No element"));
}

template<typename E>
template<typename T>
Iterable<T> EmptyUnmodifiableSetCls<E>::whereType() {
    return IterableCls->empty();
}

template<typename E>
Set<E> EmptyUnmodifiableSetCls<E>::toSet() {
    return makeMap(makeList(), makeList();
}

template<typename E>
Set<E> EmptyUnmodifiableSetCls<E>::union(Set<E> other) {
    return SetCls->of(other);
}

template<typename E>
Set<E> EmptyUnmodifiableSetCls<E>::intersection(Set<Object> other) {
    return makeMap(makeList(), makeList();
}

template<typename E>
Set<E> EmptyUnmodifiableSetCls<E>::difference(Set<Object> other) {
    return makeMap(makeList(), makeList();
}
