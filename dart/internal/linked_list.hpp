#ifndef DART_INTERNAL_LINKED_LIST
#define DART_INTERNAL_LINKED_LIST
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class LinkedListCls : public IterableBaseCls<T> {
public:
    int length;


    virtual T first();

    virtual T last();

    virtual bool isEmpty();

    virtual void add(T newLast);

    virtual void addFirst(T newFirst);

    virtual void remove(T node);

    virtual Iterator<T> iterator();

private:
    T _first;

    T _last;


};
template<typename T>
using LinkedList = std::shared_ptr<LinkedListCls<T>>;

template<typename T>
class LinkedListEntryCls : public ObjectCls {
public:

    virtual void unlink();

private:
    T _next;

    T _previous;

    LinkedList<T> _list;


};
template<typename T>
using LinkedListEntry = std::shared_ptr<LinkedListEntryCls<T>>;

template<typename T>
class _LinkedListIteratorCls : public ObjectCls {
public:

    virtual T current();

    virtual bool moveNext();

private:
    T _current;

    LinkedList<T> _list;


     _LinkedListIteratorCls(LinkedList<T> list);

};
template<typename T>
using _LinkedListIterator = std::shared_ptr<_LinkedListIteratorCls<T>>;


#endif