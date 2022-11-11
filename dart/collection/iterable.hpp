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
 virtual Iterable<T> map(std::function<T(E element)> toElement);

    virtual Iterable<E> where(std::function<bool(E element)> test);

    template<typename T>
 virtual Iterable<T> whereType();

    template<typename T>
 virtual Iterable<T> expand(std::function<Iterable<T>(E element)> toElements);

    virtual Iterable<E> followedBy(Iterable<E> other);

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

    virtual E firstWhere(std::function<E()> orElse, std::function<bool(E value)> test);

    virtual E lastWhere(std::function<E()> orElse, std::function<bool(E value)> test);

    virtual E singleWhere(std::function<E()> orElse, std::function<bool(E element)> test);

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