#ifndef EQUALITY_SET_H
#define EQUALITY_SET_H
#include <memory>

#include <collection/collection.hpp>
#include "equality.hpp"
#include "wrappers.hpp"



class EqualitySet<E> : DelegatingSet<E> {
public:

     EqualitySet(Equality<E> equality);

    void  from(Equality<E> equality, Iterable<E> other);

private:

};

#endif