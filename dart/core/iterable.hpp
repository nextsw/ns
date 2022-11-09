#ifndef DART_CORE_ITERABLE
#define DART_CORE_ITERABLE
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E> class IterableCls : public ObjectCls {
public:

     IterableCls();
    virtual void  generate(int count, E generator(int index) );

    virtual void  empty();
    template<typename S, typename T>  static Iterable<T> castFrom(Iterable<S> source);

    virtual Iterator<E> iterator();
    template<typename R>  virtual Iterable<R> cast();

    virtual Iterable<E> followedBy(Iterable<E> other);

    template<typename T>  virtual Iterable<T> map(T toElement(E e) );

    virtual Iterable<E> where(bool test(E element) );

    template<typename T>  virtual Iterable<T> whereType();

    template<typename T>  virtual Iterable<T> expand(Iterable<T> toElements(E element) );

    virtual bool contains(Object element);

    virtual void forEach(void action(E element) );

    virtual E reduce(E combine(E element, E value) );

    template<typename T>  virtual T fold(T combine(E element, T previousValue) , T initialValue);

    virtual bool every(bool test(E element) );

    virtual String join(String separator);

    virtual bool any(bool test(E element) );

    virtual List<E> toList(bool growable);

    virtual Set<E> toSet();

    virtual int length();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual Iterable<E> take(int count);

    virtual Iterable<E> takeWhile(bool test(E value) );

    virtual Iterable<E> skip(int count);

    virtual Iterable<E> skipWhile(bool test(E value) );

    virtual E first();

    virtual E last();

    virtual E single();

    virtual E firstWhere(E orElse() , bool test(E element) );

    virtual E lastWhere(E orElse() , bool test(E element) );

    virtual E singleWhere(E orElse() , bool test(E element) );

    virtual E elementAt(int index);

    virtual String toString();

private:

};
template<typename E> using Iterable = std::shared_ptr<IterableCls<E>>;

template<typename E> class _GeneratorIterableCls : public ListIterableCls<E> {
public:
    int length;


    virtual E elementAt(int index);

private:
    E Function(int ) _generator;


     _GeneratorIterableCls(E generator(int index) , int length);

    static int _id(int n);

};
template<typename E> using _GeneratorIterable = std::shared_ptr<_GeneratorIterableCls<E>>;

template<typename E> class BidirectionalIteratorCls : public ObjectCls {
public:

    virtual bool movePrevious();
private:

};
template<typename E> using BidirectionalIterator = std::shared_ptr<BidirectionalIteratorCls<E>>;


#endif