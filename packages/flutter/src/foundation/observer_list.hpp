#ifndef OBSERVER_LIST_H
#define OBSERVER_LIST_H
#include <memory>

#include <collection/collection.hpp>



class ObserverList<T> : Iterable<T> {
public:

    void add(T item);

    bool remove(T item);

    void clear();

    bool contains(Object element);

    Iterator<T> iterator();

    bool isEmpty();

    bool isNotEmpty();

    List<T> toList(bool growable);

private:
    List<T> _list;

    bool _isDirty;

    HashSet<T> _set;


};

class HashedObserverList<T> : Iterable<T> {
public:

    void add(T item);

    bool remove(T item);

    bool contains(Object element);

    Iterator<T> iterator();

    bool isEmpty();

    bool isNotEmpty();

private:
    LinkedHashMap<T, int> _map;


};

#endif