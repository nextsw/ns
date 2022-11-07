#ifndef HASH_SET_H
#define HASH_SET_H
#include <memory>




class HashSet<E> {
public:

    external  HashSet(FunctionType equals, FunctionType hashCode, FunctionType isValidKey);

    external void  identity();

    void  from(Iterable<dynamic> elements);

    void  of(Iterable<E> elements);

    Iterator<E> iterator();

private:

};

#endif