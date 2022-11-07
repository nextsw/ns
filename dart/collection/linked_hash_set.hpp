#ifndef LINKED_HASH_SET_H
#define LINKED_HASH_SET_H
#include <memory>




class LinkedHashSet<E> {
public:

    external  LinkedHashSet(FunctionType equals, FunctionType hashCode, FunctionType isValidKey);

    external void  identity();

    void  from(Iterable<dynamic> elements);

    void  of(Iterable<E> elements);

    void forEach(FunctionType action);

    Iterator<E> iterator();

private:

};

#endif