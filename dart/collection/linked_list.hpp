#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <memory>




class LinkedList<E extends LinkedListEntry<E>> : Iterable<E> {
public:

     LinkedList();

    void addFirst(E entry);

    void add(E entry);

    void addAll(Iterable<E> entries);

    bool remove(E entry);

    bool contains(Object entry);

    Iterator<E> iterator();

    int length();

    void clear();

    E first();

    E last();

    E single();

    void forEach(FunctionType action);

    bool isEmpty();

private:
    int _modificationCount;

    int _length;

    E _first;


    void _insertBefore(E entry, E newEntry, bool updateFirst);

    void _unlink(E entry);

};

class _LinkedListIterator<E extends LinkedListEntry<E>> {
public:

    E current();

    bool moveNext();

private:
    LinkedList<E> _list;

    int _modificationCount;

    E _current;

    E _next;

    bool _visitedFirst;


     _LinkedListIterator(LinkedList<E> list);

};

class LinkedListEntry<E extends LinkedListEntry<E>> {
public:

    LinkedList<E> list();

    void unlink();

    E next();

    E previous();

    void insertAfter(E entry);

    void insertBefore(E entry);

private:
    LinkedList<E> _list;

    E _next;

    E _previous;


};

#endif