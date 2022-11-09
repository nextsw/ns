#include "empty_unmodifiable_set.hpp"
template<typename E> Iterator<E> EmptyUnmodifiableSetCls<E>::iterator() {
    return <E>empty()->iterator;
}

template<typename E> int EmptyUnmodifiableSetCls<E>::length() {
    return 0;
}

template<typename E> EmptyUnmodifiableSet<T> EmptyUnmodifiableSetCls<E>::casttemplate<typename T> () {
    return <T>make<EmptyUnmodifiableSetCls>();
}

template<typename E> bool EmptyUnmodifiableSetCls<E>::contains(Object element) {
    return false;
}

template<typename E> bool EmptyUnmodifiableSetCls<E>::containsAll(Iterable<Object> other) {
    return other->isEmpty;
}

template<typename E> Iterable<E> EmptyUnmodifiableSetCls<E>::followedBy(Iterable<E> other) {
    return make<DelegatingIterableCls>(other);
}

template<typename E> E EmptyUnmodifiableSetCls<E>::lookup(Object element) {
    return nullptr;
}

template<typename E> EmptyUnmodifiableSet<T> EmptyUnmodifiableSetCls<E>::retypetemplate<typename T> () {
    return <T>make<EmptyUnmodifiableSetCls>();
}

template<typename E> E EmptyUnmodifiableSetCls<E>::singleWhere(E orElse() , bool test(E ) ) {
    return orElse != nullptr? orElse() : ;
}

template<typename E> Iterable<T> EmptyUnmodifiableSetCls<E>::whereTypetemplate<typename T> () {
    return IterableCls->empty();
}

template<typename E> Set<E> EmptyUnmodifiableSetCls<E>::toSet() {
    return makeMap(makeList(), makeList();
}

template<typename E> Set<E> EmptyUnmodifiableSetCls<E>::union(Set<E> other) {
    return SetCls->of(other);
}

template<typename E> Set<E> EmptyUnmodifiableSetCls<E>::intersection(Set<Object> other) {
    return makeMap(makeList(), makeList();
}

template<typename E> Set<E> EmptyUnmodifiableSetCls<E>::difference(Set<Object> other) {
    return makeMap(makeList(), makeList();
}
