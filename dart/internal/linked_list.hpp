#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <memory>




class LinkedList<T extends LinkedListEntry<T>> : IterableBase<T> {
public:
    int length;


    T first();

    T last();

    bool isEmpty();

    void add(T newLast);

    void addFirst(T newFirst);

    void remove(T node);

    Iterator<T> iterator();

private:
    T _first;

    T _last;


};

class LinkedListEntry<T extends LinkedListEntry<T>> {
public:

    void unlink();

private:
    T _next;

    T _previous;

    LinkedList<T> _list;


};

class _LinkedListIterator<T extends LinkedListEntry<T>> {
public:

    T current();

    bool moveNext();

private:
    T _current;

    LinkedList<T> _list;


     _LinkedListIterator(LinkedList<T> list);

};

#endif