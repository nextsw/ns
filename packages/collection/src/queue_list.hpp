#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H
#include <memory>

#include <collection/collection.hpp>



class QueueList<E> : Object {
public:

     QueueList(int initialCapacity);

    void  from(Iterable<E> source);

    void add(E element);

    void addAll(Iterable<E> iterable);

    QueueList<T> cast<T>();

    QueueList<T> retype<T>();

    String toString();

    void addLast(E element);

    void addFirst(E element);

    E removeFirst();

    E removeLast();

    int length();

    void  length(int value);

    E [](int index);

    void []=(int index, E value);

private:
    static const int _initialCapacity;

    List<E> _table;

    int _head;

    int _tail;


    static QueueList<T> _castFrom<S, T>(QueueList<S> source);

    void  _init(int initialCapacity);

    void  _(int _head, List<E> _table, int _tail);

    static int _computeInitialCapacity(int initialCapacity);

    static bool _isPowerOf2(int number);

    static int _nextPowerOf2(int number);

    void _add(E element);

    void _grow();

    int _writeToList(List<E> target);

    void _preGrow(int newElementCount);

};

class _CastQueueList<S, T> : QueueList<T> {
public:

private:
    QueueList<S> _delegate;


     _CastQueueList(QueueList<S> _delegate);

    int _head();

    void  _head(int value);

    int _tail();

    void  _tail(int value);

};

#endif