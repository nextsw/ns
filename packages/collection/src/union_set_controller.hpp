#ifndef UNION_SET_CONTROLLER_H
#define UNION_SET_CONTROLLER_H
#include <memory>

#include "union_set.hpp"



class UnionSetController<E> {
public:
    UnionSet<E> set;


     UnionSetController(bool disjoint);

    void add(Set<E> component);

    bool remove(Set<E> component);

private:
    Set<Set<E>> _sets;


    void  _(Set<Set<E>> _sets, bool disjoint);

};

#endif