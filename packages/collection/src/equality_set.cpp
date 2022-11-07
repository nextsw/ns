#include "equality_set.hpp"
EqualitySet::EqualitySet(Equality<E> equality) {
    {
        super(LinkedHashSet(equality.equals, equality.hash, equality.isValidKey));
    }
}

void EqualitySet::from(Equality<E> equality, Iterable<E> other) {
    addAll(other);
}
