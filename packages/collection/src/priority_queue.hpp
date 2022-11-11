#ifndef PACKAGES_COLLECTION_SRC_PRIORITY_QUEUE
#define PACKAGES_COLLECTION_SRC_PRIORITY_QUEUE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include "utils.hpp"


template<typename E>
class PriorityQueueCls : public ObjectCls {
public:

     PriorityQueueCls(std::function<int(E , E )> comparison);
    virtual int length();
    virtual bool isEmpty();
    virtual bool isNotEmpty();
    virtual bool contains(E object);
    virtual Iterable<E> unorderedElements();
    virtual void add(E element);
    virtual void addAll(Iterable<E> elements);
    virtual E first();
    virtual E removeFirst();
    virtual bool remove(E element);
    virtual Iterable<E> removeAll();
    virtual void clear();
    virtual List<E> toList();
    virtual List<E> toUnorderedList();
    virtual Set<E> toSet();
private:

};
template<typename E>
using PriorityQueue = std::shared_ptr<PriorityQueueCls<E>>;

template<typename E>
class HeapPriorityQueueCls : public ObjectCls {
public:
    Comparator<E> comparison;


     HeapPriorityQueueCls(std::function<int(E , E )> comparison);

    virtual void add(E element);

    virtual void addAll(Iterable<E> elements);

    virtual void clear();

    virtual bool contains(E object);

    virtual Iterable<E> unorderedElements();

    virtual E first();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual int length();

    virtual bool remove(E element);

    virtual Iterable<E> removeAll();

    virtual E removeFirst();

    virtual List<E> toList();

    virtual Set<E> toSet();

    virtual List<E> toUnorderedList();

    virtual String toString();

private:
    static int _initialCapacity;

    List<E> _queue;

    int _length;

    int _modificationCount;


    virtual E _elementAt(int index);

    virtual List<E> _toUnorderedList();

    virtual void _add(E element);

    virtual int _locate(E object);

    virtual E _removeLast();

    virtual void _bubbleUp(E element, int index);

    virtual void _bubbleDown(E element, int index);

    virtual void _grow();

};
template<typename E>
using HeapPriorityQueue = std::shared_ptr<HeapPriorityQueueCls<E>>;

template<typename E>
class _UnorderedElementsIterableCls : public IterableCls<E> {
public:

    virtual Iterator<E> iterator();

private:
    HeapPriorityQueue<E> _queue;


     _UnorderedElementsIterableCls(HeapPriorityQueue<E> _queue);
};
template<typename E>
using _UnorderedElementsIterable = std::shared_ptr<_UnorderedElementsIterableCls<E>>;

template<typename E>
class _UnorderedElementsIteratorCls : public ObjectCls {
public:

    virtual bool moveNext();

    virtual E current();

private:
    HeapPriorityQueue<E> _queue;

    int _initialModificationCount;

    E _current;

    int _index;


     _UnorderedElementsIteratorCls(HeapPriorityQueue<E> _queue);

};
template<typename E>
using _UnorderedElementsIterator = std::shared_ptr<_UnorderedElementsIteratorCls<E>>;


#endif