#ifndef DART_COLLECTION_ITERABLE
#define DART_COLLECTION_ITERABLE
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E>
class IterableMixinCls : public ObjectCls {
public:

    template<typename R>
 virtual Iterable<R> cast();

    template<typename T>
 virtual Iterable<T> map(T toElement(E element) );

    virtual Iterable<E> where(bool test(E element) );

    template<typename T>
 virtual Iterable<T> whereType();

    template<typename T>
 virtual Iterable<T> expand(Iterable<T> toElements(E element) );

    virtual Iterable<E> followedBy(Iterable<E> other);

    virtual bool contains(Object element);

    virtual void forEach(void action(E element) );

    virtual E reduce(E combine(E element, E value) );

    template<typename T>
 virtual T fold(T combine(E element, T previousValue) , T initialValue);

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

    virtual E firstWhere(E orElse() , bool test(E value) );

    virtual E lastWhere(E orElse() , bool test(E value) );

    virtual E singleWhere(E orElse() , bool test(E element) );

    virtual E elementAt(int index);

    virtual String toString();

private:

};
template<typename E>
using IterableMixin = std::shared_ptr<IterableMixinCls<E>>;

template<typename E>
class IterableBaseCls : public IterableCls<E> {
public:

     IterableBaseCls();
    static String iterableToShortString(Iterable iterable, String leftDelimiter, String rightDelimiter);

    static String iterableToFullString(Iterable iterable, String leftDelimiter, String rightDelimiter);

private:

};
template<typename E>
using IterableBase = std::shared_ptr<IterableBaseCls<E>>;
List<Object> _toStringVisiting;

bool _isToStringVisiting(Object o);

void _iterablePartsToStrings(Iterable<Object> iterable, List<String> parts);



#endif