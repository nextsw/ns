#ifndef ITERABLE_ZIP_H
#define ITERABLE_ZIP_H
#include <memory>

#include <collection/collection.hpp>



class IterableZip<T> : IterableBase<List<T>> {
public:

     IterableZip(Iterable<Iterable<T>> iterables);

    Iterator<List<T>> iterator();

private:
    Iterable<Iterable<T>> _iterables;


};

class _IteratorZip<T> {
public:

    bool moveNext();

    List<T> current();

private:
    List<Iterator<T>> _iterators;

    List<T> _current;


     _IteratorZip(List<Iterator<T>> iterators);

};

#endif