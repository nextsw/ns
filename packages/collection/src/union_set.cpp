#include "union_set.hpp"
UnionSet::UnionSet(bool disjoint, Set<Set<E>> sets) {
    {
        _sets = sets;
        _disjoint = disjoint;
    }
}

void UnionSet::from(bool disjoint, Iterable<Set<E>> sets)

int UnionSet::length() {
    return _disjoint? _sets.fold(0, ) : _iterable.length;
}

Iterator<E> UnionSet::iterator() {
    return _iterable.iterator;
}

bool UnionSet::contains(Object element) {
    return _sets.any();
}

E UnionSet::lookup(Object element) {
    for (auto set : _sets) {
        auto result = set.lookup(element);
        if (result != nullptr || set.contains(nullptr))         {
            return result;
        }
    }
    return nullptr;
}

Set<E> UnionSet::toSet() {
    return ;
}

Iterable<E> UnionSet::_iterable() {
    auto allElements = _sets.expand();
    return _disjoint? allElements : allElements.where(.add);
}
