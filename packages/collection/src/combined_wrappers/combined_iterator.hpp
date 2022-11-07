#ifndef COMBINED_ITERATOR_H
#define COMBINED_ITERATOR_H
#include <memory>




class CombinedIterator<T> {
public:

     CombinedIterator(Iterator<Iterator<T>> iterators);

    T current();

    bool moveNext();

private:
    Iterator<Iterator<T>> _iterators;


};

#endif