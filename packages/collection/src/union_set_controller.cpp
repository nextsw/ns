#include "union_set_controller.hpp"
template<typename E>
UnionSetControllerCls<E>::UnionSetControllerCls(bool disjoint) {
    {
        this->_(makeSet(), disjoint);
    }
}

template<typename E>
void UnionSetControllerCls<E>::add(Set<E> component) {
    _sets->add(component);
}

template<typename E>
bool UnionSetControllerCls<E>::remove(Set<E> component) {
    return _sets->remove(component);
}

template<typename E>
void UnionSetControllerCls<E>::_(Set<Set<E>> _sets, bool disjoint)
