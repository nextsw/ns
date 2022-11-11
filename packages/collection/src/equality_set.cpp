#include "equality_set.hpp"
template<typename E>
EqualitySetCls<E>::EqualitySetCls(Equality<E> equality) {
}

template<typename E>
void EqualitySetCls<E>::from(Equality<E> equality, Iterable<E> other) {
    addAll(other);
}
