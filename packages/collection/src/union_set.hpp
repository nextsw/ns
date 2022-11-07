#ifndef UNION_SET_H
#define UNION_SET_H
#include <memory>

#include <collection/collection.hpp>
#include "unmodifiable_wrappers.hpp"



class UnionSet<E> : SetBase<E> {
public:

     UnionSet(bool disjoint, Set<Set<E>> sets);

    void  from(bool disjoint, Iterable<Set<E>> sets);

    int length();

    Iterator<E> iterator();

    bool contains(Object element);

    E lookup(Object element);

    Set<E> toSet();

private:
    Set<Set<E>> _sets;

    bool _disjoint;


    Iterable<E> _iterable();

};

#endif