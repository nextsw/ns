#ifndef DART_INTERNAL_ITERABLE
#define DART_INTERNAL_ITERABLE
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class EfficientLengthIterableCls : public IterableCls<T> {
public:

     EfficientLengthIterableCls();
    virtual int length() override;
private:

};
template<typename T>
using EfficientLengthIterable = std::shared_ptr<EfficientLengthIterableCls<T>>;

template<typename E>
class ListIterableCls : public EfficientLengthIterableCls<E> {
public:

    virtual int length() override;
    virtual E elementAt(int i);
     ListIterableCls();
    virtual Iterator<E> iterator();

    virtual void forEach(std::function<void(E element)> action);

    virtual bool isEmpty();

    virtual E first();

    virtual E last();

    virtual E single();

    virtual bool contains(Object element);

    virtual bool every(std::function<bool(E element)> test);

    virtual bool any(std::function<bool(E element)> test);

    virtual E firstWhere(std::function<bool(E element)> test, std::function<E()> orElse);

    virtual E lastWhere(std::function<bool(E element)> test, std::function<E()> orElse);

    virtual E singleWhere(std::function<bool(E element)> test, std::function<E()> orElse);

    virtual String join(String separator);

    virtual Iterable<E> where(std::function<bool(E element)> test);

    template<typename T>
 virtual Iterable<T> map(std::function<T(E element)> toElement);

    virtual E reduce(std::function<E(E value, E element)> combine);

    template<typename T>
 virtual T fold(T initialValue, std::function<T(T previousValue, E element)> combine);

    virtual Iterable<E> skip(int count);

    virtual Iterable<E> skipWhile(std::function<bool(E element)> test);

    virtual Iterable<E> take(int count);

    virtual Iterable<E> takeWhile(std::function<bool(E element)> test);

    virtual List<E> toList(bool growable);

    virtual Set<E> toSet();

private:

};
template<typename E>
using ListIterable = std::shared_ptr<ListIterableCls<E>>;

template<typename E>
class SubListIterableCls : public ListIterableCls<E> {
public:

     SubListIterableCls(Iterable<E> _iterable, int _start, int _endOrLength);

    virtual int length();

    virtual E elementAt(int index);

    virtual Iterable<E> skip(int count);

    virtual Iterable<E> take(int count);

    virtual List<E> toList(bool growable);

private:
    Iterable<E> _iterable;

    int _start;

    int _endOrLength;


    virtual int _endIndex();

    virtual int _startIndex();

};
template<typename E>
using SubListIterable = std::shared_ptr<SubListIterableCls<E>>;

template<typename E>
class ListIteratorCls : public ObjectCls {
public:

     ListIteratorCls(Iterable<E> iterable);

    virtual E current();

    virtual bool moveNext();

private:
    Iterable<E> _iterable;

    int _length;

    int _index;

    E _current;


};
template<typename E>
using ListIterator = std::shared_ptr<ListIteratorCls<E>>;

template<typename S, typename T>
class MappedIterableCls : public IterableCls<T> {
public:

     MappedIterableCls(Iterable<S> iterable, std::function<T(S value)> function);

    virtual Iterator<T> iterator();

    virtual int length();

    virtual bool isEmpty();

    virtual T first();

    virtual T last();

    virtual T single();

    virtual T elementAt(int index);

private:
    Iterable<S> _iterable;

    _Transformation<S, T> _f;


    virtual void  _(Iterable<S> _iterable, _Transformation<S, T> _f);
};
template<typename S, typename T>
using MappedIterable = std::shared_ptr<MappedIterableCls<S, T>>;

template<typename S, typename T>
class EfficientLengthMappedIterableCls : public MappedIterableCls<S, T> {
public:

     EfficientLengthMappedIterableCls(Iterable<S> iterable, std::function<T(S value)> function);

private:

};
template<typename S, typename T>
using EfficientLengthMappedIterable = std::shared_ptr<EfficientLengthMappedIterableCls<S, T>>;

template<typename S, typename T>
class MappedIteratorCls : public IteratorCls<T> {
public:

     MappedIteratorCls(Iterator<S> _iterator, _Transformation<S, T> _f);
    virtual bool moveNext();

    virtual T current();

private:
    T _current;

    Iterator<S> _iterator;

    _Transformation<S, T> _f;


};
template<typename S, typename T>
using MappedIterator = std::shared_ptr<MappedIteratorCls<S, T>>;

template<typename S, typename T>
class MappedListIterableCls : public ListIterableCls<T> {
public:

     MappedListIterableCls(Iterable<S> _source, _Transformation<S, T> _f);
    virtual int length();

    virtual T elementAt(int index);

private:
    Iterable<S> _source;

    _Transformation<S, T> _f;


};
template<typename S, typename T>
using MappedListIterable = std::shared_ptr<MappedListIterableCls<S, T>>;

template<typename E>
class WhereIterableCls : public IterableCls<E> {
public:

     WhereIterableCls(Iterable<E> _iterable, _ElementPredicate<E> _f);
    virtual Iterator<E> iterator();

    template<typename T>
 virtual Iterable<T> map(std::function<T(E element)> toElement);

private:
    Iterable<E> _iterable;

    _ElementPredicate<E> _f;


};
template<typename E>
using WhereIterable = std::shared_ptr<WhereIterableCls<E>>;

template<typename E>
class WhereIteratorCls : public IteratorCls<E> {
public:

     WhereIteratorCls(Iterator<E> _iterator, _ElementPredicate<E> _f);
    virtual bool moveNext();

    virtual E current();

private:
    Iterator<E> _iterator;

    _ElementPredicate<E> _f;


};
template<typename E>
using WhereIterator = std::shared_ptr<WhereIteratorCls<E>>;

template<typename S, typename T>
class ExpandIterableCls : public IterableCls<T> {
public:

     ExpandIterableCls(Iterable<S> _iterable, _ExpandFunction<S, T> _f);
    virtual Iterator<T> iterator();

private:
    Iterable<S> _iterable;

    _ExpandFunction<S, T> _f;


};
template<typename S, typename T>
using ExpandIterable = std::shared_ptr<ExpandIterableCls<S, T>>;

template<typename S, typename T>
class ExpandIteratorCls : public ObjectCls {
public:

     ExpandIteratorCls(Iterator<S> _iterator, _ExpandFunction<S, T> _f);
    virtual T current();

    virtual bool moveNext();

private:
    Iterator<S> _iterator;

    _ExpandFunction<S, T> _f;

    Iterator<T> _currentExpansion;

    T _current;


};
template<typename S, typename T>
using ExpandIterator = std::shared_ptr<ExpandIteratorCls<S, T>>;

template<typename E>
class TakeIterableCls : public IterableCls<E> {
public:

     TakeIterableCls(Iterable<E> iterable, int takeCount);

    virtual Iterator<E> iterator();

private:
    Iterable<E> _iterable;

    int _takeCount;


    virtual void  _(Iterable<E> _iterable, int _takeCount);
};
template<typename E>
using TakeIterable = std::shared_ptr<TakeIterableCls<E>>;

template<typename E>
class EfficientLengthTakeIterableCls : public TakeIterableCls<E> {
public:

     EfficientLengthTakeIterableCls(Iterable<E> iterable, int takeCount);

    virtual int length();

private:

};
template<typename E>
using EfficientLengthTakeIterable = std::shared_ptr<EfficientLengthTakeIterableCls<E>>;

template<typename E>
class TakeIteratorCls : public IteratorCls<E> {
public:

     TakeIteratorCls(Iterator<E> _iterator, int _remaining);

    virtual bool moveNext();

    virtual E current();

private:
    Iterator<E> _iterator;

    int _remaining;


};
template<typename E>
using TakeIterator = std::shared_ptr<TakeIteratorCls<E>>;

template<typename E>
class TakeWhileIterableCls : public IterableCls<E> {
public:

     TakeWhileIterableCls(Iterable<E> _iterable, _ElementPredicate<E> _f);
    virtual Iterator<E> iterator();

private:
    Iterable<E> _iterable;

    _ElementPredicate<E> _f;


};
template<typename E>
using TakeWhileIterable = std::shared_ptr<TakeWhileIterableCls<E>>;

template<typename E>
class TakeWhileIteratorCls : public IteratorCls<E> {
public:

     TakeWhileIteratorCls(Iterator<E> _iterator, _ElementPredicate<E> _f);
    virtual bool moveNext();

    virtual E current();

private:
    Iterator<E> _iterator;

    _ElementPredicate<E> _f;

    bool _isFinished;


};
template<typename E>
using TakeWhileIterator = std::shared_ptr<TakeWhileIteratorCls<E>>;

template<typename E>
class SkipIterableCls : public IterableCls<E> {
public:

     SkipIterableCls(Iterable<E> iterable, int count);

    virtual Iterable<E> skip(int count);

    virtual Iterator<E> iterator();

private:
    Iterable<E> _iterable;

    int _skipCount;


    virtual void  _(Iterable<E> _iterable, int _skipCount);
};
template<typename E>
using SkipIterable = std::shared_ptr<SkipIterableCls<E>>;

template<typename E>
class EfficientLengthSkipIterableCls : public SkipIterableCls<E> {
public:

     EfficientLengthSkipIterableCls(Iterable<E> iterable, int count);

    virtual int length();

    virtual Iterable<E> skip(int count);

private:

    virtual void  _(Iterable<E> iterable, int count);

};
template<typename E>
using EfficientLengthSkipIterable = std::shared_ptr<EfficientLengthSkipIterableCls<E>>;
int _checkCount(int count);


template<typename E>
class SkipIteratorCls : public IteratorCls<E> {
public:

     SkipIteratorCls(Iterator<E> _iterator, int _skipCount);

    virtual bool moveNext();

    virtual E current();

private:
    Iterator<E> _iterator;

    int _skipCount;


};
template<typename E>
using SkipIterator = std::shared_ptr<SkipIteratorCls<E>>;

template<typename E>
class SkipWhileIterableCls : public IterableCls<E> {
public:

     SkipWhileIterableCls(Iterable<E> _iterable, _ElementPredicate<E> _f);
    virtual Iterator<E> iterator();

private:
    Iterable<E> _iterable;

    _ElementPredicate<E> _f;


};
template<typename E>
using SkipWhileIterable = std::shared_ptr<SkipWhileIterableCls<E>>;

template<typename E>
class SkipWhileIteratorCls : public IteratorCls<E> {
public:

     SkipWhileIteratorCls(Iterator<E> _iterator, _ElementPredicate<E> _f);
    virtual bool moveNext();

    virtual E current();

private:
    Iterator<E> _iterator;

    _ElementPredicate<E> _f;

    bool _hasSkipped;


};
template<typename E>
using SkipWhileIterator = std::shared_ptr<SkipWhileIteratorCls<E>>;

template<typename E>
class EmptyIterableCls : public EfficientLengthIterableCls<E> {
public:

     EmptyIterableCls();
    virtual Iterator<E> iterator();

    virtual void forEach(std::function<void(E element)> action);

    virtual bool isEmpty();

    virtual int length();

    virtual E first();

    virtual E last();

    virtual E single();

    virtual E elementAt(int index);

    virtual bool contains(Object element);

    virtual bool every(std::function<bool(E element)> test);

    virtual bool any(std::function<bool(E element)> test);

    virtual E firstWhere(std::function<bool(E element)> test, std::function<E()> orElse);

    virtual E lastWhere(std::function<bool(E element)> test, std::function<E()> orElse);

    virtual E singleWhere(std::function<bool(E element)> test, std::function<E()> orElse);

    virtual String join(String separator);

    virtual Iterable<E> where(std::function<bool(E element)> test);

    template<typename T>
 virtual Iterable<T> map(std::function<T(E element)> toElement);

    virtual E reduce(std::function<E(E value, E element)> combine);

    template<typename T>
 virtual T fold(T initialValue, std::function<T(T previousValue, E element)> combine);

    virtual Iterable<E> skip(int count);

    virtual Iterable<E> skipWhile(std::function<bool(E element)> test);

    virtual Iterable<E> take(int count);

    virtual Iterable<E> takeWhile(std::function<bool(E element)> test);

    virtual List<E> toList(bool growable);

    virtual Set<E> toSet();

private:

};
template<typename E>
using EmptyIterable = std::shared_ptr<EmptyIterableCls<E>>;

template<typename E>
class EmptyIteratorCls : public ObjectCls {
public:

     EmptyIteratorCls();
    virtual bool moveNext();

    virtual E current();

private:

};
template<typename E>
using EmptyIterator = std::shared_ptr<EmptyIteratorCls<E>>;

template<typename E>
class FollowedByIterableCls : public IterableCls<E> {
public:

     FollowedByIterableCls(Iterable<E> _first, Iterable<E> _second);
    virtual void  firstEfficient(EfficientLengthIterable<E> first, Iterable<E> second);

    virtual Iterator<E> iterator();

    virtual int length();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual bool contains(Object value);

    virtual E first();

    virtual E last();

private:
    Iterable<E> _first;

    Iterable<E> _second;


};
template<typename E>
using FollowedByIterable = std::shared_ptr<FollowedByIterableCls<E>>;

template<typename E>
class EfficientLengthFollowedByIterableCls : public FollowedByIterableCls<E> {
public:

     EfficientLengthFollowedByIterableCls(EfficientLengthIterable<E> first, EfficientLengthIterable<E> second);

    virtual E elementAt(int index);

    virtual E first();

    virtual E last();

private:

};
template<typename E>
using EfficientLengthFollowedByIterable = std::shared_ptr<EfficientLengthFollowedByIterableCls<E>>;

template<typename E>
class FollowedByIteratorCls : public ObjectCls {
public:

     FollowedByIteratorCls(Iterable<E> first, Iterable<E> _nextIterable);

    virtual bool moveNext();

    virtual E current();

private:
    Iterator<E> _currentIterator;

    Iterable<E> _nextIterable;


};
template<typename E>
using FollowedByIterator = std::shared_ptr<FollowedByIteratorCls<E>>;

template<typename T>
class WhereTypeIterableCls : public IterableCls<T> {
public:

     WhereTypeIterableCls(Iterable<Object> _source);
    virtual Iterator<T> iterator();

private:
    Iterable<Object> _source;


};
template<typename T>
using WhereTypeIterable = std::shared_ptr<WhereTypeIterableCls<T>>;

template<typename T>
class WhereTypeIteratorCls : public ObjectCls {
public:

     WhereTypeIteratorCls(Iterator<Object> _source);
    virtual bool moveNext();

    virtual T current();

private:
    Iterator<Object> _source;


};
template<typename T>
using WhereTypeIterator = std::shared_ptr<WhereTypeIteratorCls<T>>;

class IterableElementErrorCls : public ObjectCls {
public:

    static StateError noElement();

    static StateError tooMany();

    static StateError tooFew();

private:

};
using IterableElementError = std::shared_ptr<IterableElementErrorCls>;


#endif