#ifndef DART_CORE_ITERABLE
#define DART_CORE_ITERABLE
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E>
class IterableCls : public ObjectCls {
public:

     IterableCls();
    virtual void  generate(int count, std::function<E(int index)> generator);

    virtual void  empty();
    template<typename S, typename T>
 static Iterable<T> castFrom(Iterable<S> source);

    virtual Iterator<E> iterator();
    template<typename R>
 virtual Iterable<R> cast();

    virtual Iterable<E> followedBy(Iterable<E> other);

    template<typename T>
 virtual Iterable<T> map(std::function<T(E e)> toElement);

    virtual Iterable<E> where(std::function<bool(E element)> test);

    template<typename T>
 virtual Iterable<T> whereType();

    template<typename T>
 virtual Iterable<T> expand(std::function<Iterable<T>(E element)> toElements);

    virtual bool contains(Object element);

    virtual void forEach(std::function<void(E element)> action);

    virtual E reduce(std::function<E(E element, E value)> combine);

    template<typename T>
 virtual T fold(std::function<T(E element, T previousValue)> combine, T initialValue);

    virtual bool every(std::function<bool(E element)> test);

    virtual String join(String separator);

    virtual bool any(std::function<bool(E element)> test);

    virtual List<E> toList(bool growable);

    virtual Set<E> toSet();

    virtual int length();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual Iterable<E> take(int count);

    virtual Iterable<E> takeWhile(std::function<bool(E value)> test);

    virtual Iterable<E> skip(int count);

    virtual Iterable<E> skipWhile(std::function<bool(E value)> test);

    virtual E first();

    virtual E last();

    virtual E single();

    virtual E firstWhere(std::function<E()> orElse, std::function<bool(E element)> test);

    virtual E lastWhere(std::function<E()> orElse, std::function<bool(E element)> test);

    virtual E singleWhere(std::function<E()> orElse, std::function<bool(E element)> test);

    virtual E elementAt(int index);

    virtual String toString();

private:

};
template<typename E>
using Iterable = std::shared_ptr<IterableCls<E>>;

template<typename E>
class _GeneratorIterableCls : public ListIterableCls<E> {
public:
    int length;


    virtual E elementAt(int index);

private:
    std::function<E(int )> _generator;


     _GeneratorIterableCls(std::function<E(int index)> generator, int length);

    static int _id(int n);

};
template<typename E>
using _GeneratorIterable = std::shared_ptr<_GeneratorIterableCls<E>>;

template<typename E>
class BidirectionalIteratorCls : public ObjectCls {
public:

    virtual bool movePrevious();
private:

};
template<typename E>
using BidirectionalIterator = std::shared_ptr<BidirectionalIteratorCls<E>>;


#endif