#ifndef DART_COLLECTION_QUEUE
#define DART_COLLECTION_QUEUE
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E>
class QueueCls : public ObjectCls {
public:

     QueueCls();
    virtual void  from(Iterable elements);
    virtual void  of(Iterable<E> elements);
    template<typename S, typename T>
 static Queue<T> castFrom(Queue<S> source);

    template<typename R>
 virtual Queue<R> cast();
    virtual E removeFirst();
    virtual E removeLast();
    virtual void addFirst(E value);
    virtual void addLast(E value);
    virtual void add(E value);
    virtual bool remove(Object value);
    virtual void addAll(Iterable<E> iterable);
    virtual void removeWhere(bool test(E element) );
    virtual void retainWhere(bool test(E element) );
    virtual void clear();
private:

};
template<typename E>
using Queue = std::shared_ptr<QueueCls<E>>;

template<typename E>
class _DoubleLinkedQueueEntryCls : public ObjectCls {
public:

    virtual E element();
private:
    _DoubleLinkedQueueEntry<E> _previousLink;

    _DoubleLinkedQueueEntry<E> _nextLink;


    virtual void _link(_DoubleLinkedQueueEntry<E> next, _DoubleLinkedQueueEntry<E> previous);

    virtual void _unlink();

    virtual _DoubleLinkedQueueElement<E> _asNonSentinelEntry();
    virtual void _append(E element, DoubleLinkedQueue<E> queue);

    virtual void _prepend(E element, DoubleLinkedQueue<E> queue);

    virtual E _remove();
};
template<typename E>
using _DoubleLinkedQueueEntry = std::shared_ptr<_DoubleLinkedQueueEntryCls<E>>;

template<typename E>
class _DoubleLinkedQueueElementCls : public _DoubleLinkedQueueEntryCls<E> {
public:
    E element;


    virtual void append(E e);

    virtual void prepend(E e);

    virtual E remove();

    virtual DoubleLinkedQueueEntry<E> previousEntry();

    virtual DoubleLinkedQueueEntry<E> nextEntry();

private:
    DoubleLinkedQueue<E> _queue;


     _DoubleLinkedQueueElementCls(DoubleLinkedQueue<E> _queue, E element);
    virtual E _remove();

    virtual _DoubleLinkedQueueElement<E> _asNonSentinelEntry();

};
template<typename E>
using _DoubleLinkedQueueElement = std::shared_ptr<_DoubleLinkedQueueElementCls<E>>;

template<typename E>
class _DoubleLinkedQueueSentinelCls : public _DoubleLinkedQueueEntryCls<E> {
public:

    virtual E element();

private:

     _DoubleLinkedQueueSentinelCls();

    virtual Null _asNonSentinelEntry();

    virtual E _remove();

};
template<typename E>
using _DoubleLinkedQueueSentinel = std::shared_ptr<_DoubleLinkedQueueSentinelCls<E>>;

template<typename E>
class DoubleLinkedQueueCls : public IterableCls<E> {
public:

     DoubleLinkedQueueCls();
    virtual void  from(Iterable<dynamic> elements);

    virtual void  of(Iterable<E> elements);

    template<typename R>
 virtual Queue<R> cast();

    virtual int length();

    virtual void addLast(E value);

    virtual void addFirst(E value);

    virtual void add(E value);

    virtual void addAll(Iterable<E> iterable);

    virtual E removeLast();

    virtual E removeFirst();

    virtual bool remove(Object o);

    virtual void removeWhere(bool test(E element) );

    virtual void retainWhere(bool test(E element) );

    virtual E first();

    virtual E last();

    virtual E single();

    virtual DoubleLinkedQueueEntry<E> firstEntry();

    virtual DoubleLinkedQueueEntry<E> lastEntry();

    virtual bool isEmpty();

    virtual void clear();

    virtual void forEachEntry(void action(DoubleLinkedQueueEntry<E> element) );

    virtual _DoubleLinkedQueueIterator<E> iterator();

    virtual String toString();

private:
    _DoubleLinkedQueueSentinel<E> _sentinel;

    int _elementCount;


    virtual void _filter(bool removeMatching, bool test(E element) );

};
template<typename E>
using DoubleLinkedQueue = std::shared_ptr<DoubleLinkedQueueCls<E>>;

template<typename E>
class _DoubleLinkedQueueIteratorCls : public ObjectCls {
public:

    virtual bool moveNext();

    virtual E current();

private:
    DoubleLinkedQueue<E> _queue;

    _DoubleLinkedQueueEntry<E> _nextEntry;

    E _current;


     _DoubleLinkedQueueIteratorCls(DoubleLinkedQueue<E> _queue);

};
template<typename E>
using _DoubleLinkedQueueIterator = std::shared_ptr<_DoubleLinkedQueueIteratorCls<E>>;

template<typename E>
class ListQueueCls : public ListIterableCls<E> {
public:

     ListQueueCls(int initialCapacity);

    virtual void  from(Iterable<dynamic> elements);

    virtual void  of(Iterable<E> elements);

    template<typename R>
 virtual Queue<R> cast();

    virtual Iterator<E> iterator();

    virtual void forEach(void f(E element) );

    virtual bool isEmpty();

    virtual int length();

    virtual E first();

    virtual E last();

    virtual E single();

    virtual E elementAt(int index);

    virtual List<E> toList(bool growable);

    virtual void add(E value);

    virtual void addAll(Iterable<E> elements);

    virtual bool remove(Object value);

    virtual void removeWhere(bool test(E element) );

    virtual void retainWhere(bool test(E element) );

    virtual void clear();

    virtual String toString();

    virtual void addLast(E value);

    virtual void addFirst(E value);

    virtual E removeFirst();

    virtual E removeLast();

private:
    static int _INITIAL_CAPACITY;

    List<E> _table;

    int _head;

    int _tail;

    int _modificationCount;


    static int _calculateCapacity(int initialCapacity);

    virtual void _filterWhere(bool removeMatching, bool test(E element) );

    static bool _isPowerOf2(int number);

    static int _nextPowerOf2(int number);

    virtual void _checkModification(int expectedModificationCount);

    virtual void _add(E element);

    virtual int _remove(int offset);

    virtual void _grow();

    virtual int _writeToList(List<E> target);

    virtual void _preGrow(int newElementCount);

};
template<typename E>
using ListQueue = std::shared_ptr<ListQueueCls<E>>;

template<typename E>
class _ListQueueIteratorCls : public ObjectCls {
public:

    virtual E current();

    virtual bool moveNext();

private:
    ListQueue<E> _queue;

    int _end;

    int _modificationCount;

    int _position;

    E _current;


     _ListQueueIteratorCls(ListQueue<E> queue);

};
template<typename E>
using _ListQueueIterator = std::shared_ptr<_ListQueueIteratorCls<E>>;


#endif