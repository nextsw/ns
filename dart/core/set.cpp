#include "set.hpp"
template<typename E>
void SetCls<E>::unmodifiable(Iterable<E> elements) {
    return <E>make<UnmodifiableSetViewCls>(list1);
}

template<typename E>
template<typename S, typename T>
Set<T> SetCls<E>::castFrom(Set<R> newSet() , Set<S> source) {
    return <S, T>make<CastSetCls>(source, newSet);
}
