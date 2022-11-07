#ifndef BASIC_TYPES_H
#define BASIC_TYPES_H
#include <memory>

#include <collection/collection.hpp>



class CachingIterable<E> : IterableBase<E> {
public:

     CachingIterable(Iterator<E> _prefillIterator);

    Iterator<E> iterator();

    Iterable<T> map<T>(FunctionType toElement);

    Iterable<E> where(FunctionType test);

    Iterable<T> expand<T>(FunctionType toElements);

    Iterable<E> take(int count);

    Iterable<E> takeWhile(FunctionType test);

    Iterable<E> skip(int count);

    Iterable<E> skipWhile(FunctionType test);

    int length();

    List<E> toList(bool growable);

private:
    Iterator<E> _prefillIterator;

    List<E> _results;


    void _precacheEntireList();

    bool _fillNext();

};

class _LazyListIterator<E> {
public:

    E current();

    bool moveNext();

private:
    CachingIterable<E> _owner;

    int _index;


     _LazyListIterator(CachingIterable<E> _owner);

};

class Factory<T> {
public:
    ValueGetter<T> constructor;


     Factory(ValueGetter<T> constructor);

    Type type();

    String toString();

private:

};
Duration lerpDuration(Duration a, Duration b, double t);


#endif