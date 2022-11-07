#ifndef ITERATOR_H
#define ITERATOR_H
#include <memory>




class Iterator<E> {
public:

    bool moveNext();

    E current();

private:

};

#endif