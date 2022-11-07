#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <memory>

#include <collection/collection.hpp>
#include "utils.hpp"



class PriorityQueue<E> {
public:

     PriorityQueue(FunctionType comparison);

    int length();

    bool isEmpty();

    bool isNotEmpty();

    bool contains(E object);

    Iterable<E> unorderedElements();

    void add(E element);

    void addAll(Iterable<E> elements);

    E first();

    E removeFirst();

    bool remove(E element);

    Iterable<E> removeAll();

    void clear();

    List<E> toList();

    List<E> toUnorderedList();

    Set<E> toSet();

private:

};

class HeapPriorityQueue<E> {
public:
    Comparator<E> comparison;


     HeapPriorityQueue(FunctionType comparison);

    void add(E element);

    void addAll(Iterable<E> elements);

    void clear();

    bool contains(E object);

    Iterable<E> unorderedElements();

    E first();

    bool isEmpty();

    bool isNotEmpty();

    int length();

    bool remove(E element);

    Iterable<E> removeAll();

    E removeFirst();

    List<E> toList();

    Set<E> toSet();

    List<E> toUnorderedList();

    String toString();

private:
    static const int _initialCapacity;

    List<E> _queue;

    int _length;

    int _modificationCount;


    E _elementAt(int index);

    List<E> _toUnorderedList();

    void _add(E element);

    int _locate(E object);

    E _removeLast();

    void _bubbleUp(E element, int index);

    void _bubbleDown(E element, int index);

    void _grow();

};

class _UnorderedElementsIterable<E> : Iterable<E> {
public:

    Iterator<E> iterator();

private:
    HeapPriorityQueue<E> _queue;


     _UnorderedElementsIterable(HeapPriorityQueue<E> _queue);

};

class _UnorderedElementsIterator<E> {
public:

    bool moveNext();

    E current();

private:
    HeapPriorityQueue<E> _queue;

    int _initialModificationCount;

    E _current;

    int _index;


     _UnorderedElementsIterator(HeapPriorityQueue<E> _queue);

};

#endif