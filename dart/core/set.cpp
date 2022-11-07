#include "set.hpp"
void Set::unmodifiable(Iterable<E> elements) {
    return <E>UnmodifiableSetView();
}

Set<T> Set::castFrom<S, T>(FunctionType newSet, Set<S> source) {
    return <S, T>CastSet(source, newSet);
}
