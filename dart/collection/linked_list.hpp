#ifndef DART_COLLECTION_LINKED_LIST
#define DART_COLLECTION_LINKED_LIST
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E>
class LinkedListCls : public IterableCls<E> {
public:

     LinkedListCls();
    virtual void addFirst(E entry);

    virtual void add(E entry);

    virtual void addAll(Iterable<E> entries);

    virtual bool remove(E entry);

    virtual bool contains(Object entry);

    virtual Iterator<E> iterator();

    virtual int length();

    virtual void clear();

    virtual E first();

    virtual E last();

    virtual E single();

    virtual void forEach(void action(E entry) );

    virtual bool isEmpty();

private:
    int _modificationCount;

    int _length;

    E _first;


    virtual void _insertBefore(E entry, E newEntry, bool updateFirst);

    virtual void _unlink(E entry);

};
template<typename E>
using LinkedList = std::shared_ptr<LinkedListCls<E>>;

template<typename E>
class _LinkedListIteratorCls : public ObjectCls {
public:

    virtual E current();

    virtual bool moveNext();

private:
    LinkedList<E> _list;

    int _modificationCount;

    E _current;

    E _next;

    bool _visitedFirst;


     _LinkedListIteratorCls(LinkedList<E> list);

};
template<typename E>
using _LinkedListIterator = std::shared_ptr<_LinkedListIteratorCls<E>>;

template<typename E>
class LinkedListEntryCls : public ObjectCls {
public:

    virtual LinkedList<E> list();

    virtual void unlink();

    virtual E next();

    virtual E previous();

    virtual void insertAfter(E entry);

    virtual void insertBefore(E entry);

private:
    LinkedList<E> _list;

    E _next;

    E _previous;


};
template<typename E>
using LinkedListEntry = std::shared_ptr<LinkedListEntryCls<E>>;


#endif