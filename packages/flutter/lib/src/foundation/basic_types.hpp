#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_BASIC_TYPES
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_BASIC_TYPES
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>


template<typename E>
class CachingIterableCls : public IterableBaseCls<E> {
public:

     CachingIterableCls(Iterator<E> _prefillIterator);
    virtual Iterator<E> iterator();

    template<typename T>
 virtual Iterable<T> map(std::function<T(E e)> toElement);

    virtual Iterable<E> where(std::function<bool(E element)> test);

    template<typename T>
 virtual Iterable<T> expand(std::function<Iterable<T>(E element)> toElements);

    virtual Iterable<E> take(int count);

    virtual Iterable<E> takeWhile(std::function<bool(E value)> test);

    virtual Iterable<E> skip(int count);

    virtual Iterable<E> skipWhile(std::function<bool(E value)> test);

    virtual int length();

    virtual List<E> toList(bool growable);

private:
    Iterator<E> _prefillIterator;

    List<E> _results;


    virtual void _precacheEntireList();

    virtual bool _fillNext();

};
template<typename E>
using CachingIterable = std::shared_ptr<CachingIterableCls<E>>;

template<typename E>
class _LazyListIteratorCls : public ObjectCls {
public:

    virtual E current();

    virtual bool moveNext();

private:
    CachingIterable<E> _owner;

    int _index;


     _LazyListIteratorCls(CachingIterable<E> _owner);

};
template<typename E>
using _LazyListIterator = std::shared_ptr<_LazyListIteratorCls<E>>;

template<typename T>
class FactoryCls : public ObjectCls {
public:
    ValueGetter<T> constructor;


     FactoryCls(ValueGetter<T> constructor);

    virtual Type type();

    virtual String toString();

private:

};
template<typename T>
using Factory = std::shared_ptr<FactoryCls<T>>;
Duration lerpDuration(Duration a, Duration b, double t);



#endif