#include "equality_set.hpp"
template<typename E>
EqualitySetCls<E>::EqualitySetCls(Equality<E> equality) : DelegatingSet<E>(make<LinkedHashSetCls>(equality->equals, equality->hash, equality->isValidKey)) {
}

template<typename E>
void EqualitySetCls<E>::from(Equality<E> equality, Iterable<E> other) {
    addAll(other);
}
