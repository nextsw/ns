#ifndef QUEUE_H
#define QUEUE_H
#include <memory>




class Queue<E> {
public:

     Queue();

    void  from(Iterable elements);

    void  of(Iterable<E> elements);

    static Queue<T> castFrom<S, T>(Queue<S> source);

    Queue<R> cast<R>();

    E removeFirst();

    E removeLast();

    void addFirst(E value);

    void addLast(E value);

    void add(E value);

    bool remove(Object value);

    void addAll(Iterable<E> iterable);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    void clear();

private:

};

class _DoubleLinkedQueueEntry<E> {
public:

    E element();

private:
    _DoubleLinkedQueueEntry<E> _previousLink;

    _DoubleLinkedQueueEntry<E> _nextLink;


    void _link(_DoubleLinkedQueueEntry<E> next, _DoubleLinkedQueueEntry<E> previous);

    void _unlink();

    _DoubleLinkedQueueElement<E> _asNonSentinelEntry();

    void _append(E element, DoubleLinkedQueue<E> queue);

    void _prepend(E element, DoubleLinkedQueue<E> queue);

    E _remove();

};

class _DoubleLinkedQueueElement<E> : _DoubleLinkedQueueEntry<E> {
public:
    E element;


    void append(E e);

    void prepend(E e);

    E remove();

    DoubleLinkedQueueEntry<E> previousEntry();

    DoubleLinkedQueueEntry<E> nextEntry();

private:
    DoubleLinkedQueue<E> _queue;


     _DoubleLinkedQueueElement(DoubleLinkedQueue<E> _queue, E element);

    E _remove();

    _DoubleLinkedQueueElement<E> _asNonSentinelEntry();

};

class _DoubleLinkedQueueSentinel<E> : _DoubleLinkedQueueEntry<E> {
public:

    E element();

private:

     _DoubleLinkedQueueSentinel();

    Null _asNonSentinelEntry();

    E _remove();

};

class DoubleLinkedQueue<E> : Iterable<E> {
public:

     DoubleLinkedQueue();

    void  from(Iterable<dynamic> elements);

    void  of(Iterable<E> elements);

    Queue<R> cast<R>();

    int length();

    void addLast(E value);

    void addFirst(E value);

    void add(E value);

    void addAll(Iterable<E> iterable);

    E removeLast();

    E removeFirst();

    bool remove(Object o);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    E first();

    E last();

    E single();

    DoubleLinkedQueueEntry<E> firstEntry();

    DoubleLinkedQueueEntry<E> lastEntry();

    bool isEmpty();

    void clear();

    void forEachEntry(FunctionType action);

    _DoubleLinkedQueueIterator<E> iterator();

    String toString();

private:
    _DoubleLinkedQueueSentinel<E> _sentinel;

    int _elementCount;


    void _filter(bool removeMatching, FunctionType test);

};

class _DoubleLinkedQueueIterator<E> {
public:

    bool moveNext();

    E current();

private:
    DoubleLinkedQueue<E> _queue;

    _DoubleLinkedQueueEntry<E> _nextEntry;

    E _current;


     _DoubleLinkedQueueIterator(DoubleLinkedQueue<E> _queue);

};

class ListQueue<E> : ListIterable<E> {
public:

     ListQueue(int initialCapacity);

    void  from(Iterable<dynamic> elements);

    void  of(Iterable<E> elements);

    Queue<R> cast<R>();

    Iterator<E> iterator();

    void forEach(FunctionType f);

    bool isEmpty();

    int length();

    E first();

    E last();

    E single();

    E elementAt(int index);

    List<E> toList(bool growable);

    void add(E value);

    void addAll(Iterable<E> elements);

    bool remove(Object value);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    void clear();

    String toString();

    void addLast(E value);

    void addFirst(E value);

    E removeFirst();

    E removeLast();

private:
    static const int _INITIAL_CAPACITY;

    List<E> _table;

    int _head;

    int _tail;

    int _modificationCount;


    static int _calculateCapacity(int initialCapacity);

    void _filterWhere(bool removeMatching, FunctionType test);

    static bool _isPowerOf2(int number);

    static int _nextPowerOf2(int number);

    void _checkModification(int expectedModificationCount);

    void _add(E element);

    int _remove(int offset);

    void _grow();

    int _writeToList(List<E> target);

    void _preGrow(int newElementCount);

};

class _ListQueueIterator<E> {
public:

    E current();

    bool moveNext();

private:
    ListQueue<E> _queue;

    int _end;

    int _modificationCount;

    int _position;

    E _current;


     _ListQueueIterator(ListQueue<E> queue);

};

#endif