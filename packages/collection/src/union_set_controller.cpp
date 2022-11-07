#include "union_set_controller.hpp"
UnionSetController::UnionSetController(bool disjoint) {
    {
        this._(, disjoint);
    }
}

void UnionSetController::add(Set<E> component) {
    _sets.add(component);
}

bool UnionSetController::remove(Set<E> component) {
    return _sets.remove(component);
}

void UnionSetController::_(Set<Set<E>> _sets, bool disjoint)
