#ifndef ITERATOR_H
#define ITERATOR_H
#include <memory>




class HasNextIterator<E> {
public:

     HasNextIterator(Iterator<E> _iterator);

    bool hasNext();

    E next();

private:
    static const int _HAS_NEXT_AND_NEXT_IN_CURRENT;

    static const int _NO_NEXT;

    static const int _NOT_MOVED_YET;

    Iterator<E> _iterator;

    int _state;


    void _move();

};

#endif