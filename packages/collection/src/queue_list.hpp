#ifndef PACKAGES_COLLECTION_SRC_QUEUE_LIST
#define PACKAGES_COLLECTION_SRC_QUEUE_LIST
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>


template<typename E>
class QueueListCls : public ObjectCls {
public:

     QueueListCls(int initialCapacity);

    virtual void  from(Iterable<E> source);

    virtual void add(E element);

    virtual void addAll(Iterable<E> iterable);

    template<typename T>
 virtual QueueList<T> cast();

    template<typename T>
 virtual QueueList<T> retype();

    virtual String toString();

    virtual void addLast(E element);

    virtual void addFirst(E element);

    virtual E removeFirst();

    virtual E removeLast();

    virtual int length();

    virtual void  length(int value);

    virtual E operator[](int index);

    virtual void operator[]=(int index, E value);

private:
    static int _initialCapacity;

    List<E> _table;

    int _head;

    int _tail;


    template<typename S, typename T>
 static QueueList<T> _castFrom(QueueList<S> source);

    virtual void  _init(int initialCapacity);

    virtual void  _(int _head, List<E> _table, int _tail);
    static int _computeInitialCapacity(int initialCapacity);

    static bool _isPowerOf2(int number);

    static int _nextPowerOf2(int number);

    virtual void _add(E element);

    virtual void _grow();

    virtual int _writeToList(List<E> target);

    virtual void _preGrow(int newElementCount);

};
template<typename E>
using QueueList = std::shared_ptr<QueueListCls<E>>;

template<typename S, typename T>
class _CastQueueListCls : public QueueListCls<T> {
public:

private:
    QueueList<S> _delegate;


     _CastQueueListCls(QueueList<S> _delegate);

    virtual int _head();

    virtual void  _head(int value);

    virtual int _tail();

    virtual void  _tail(int value);

};
template<typename S, typename T>
using _CastQueueList = std::shared_ptr<_CastQueueListCls<S, T>>;


#endif