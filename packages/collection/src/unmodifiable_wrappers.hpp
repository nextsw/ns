#ifndef UNMODIFIABLE_WRAPPERS_H
#define UNMODIFIABLE_WRAPPERS_H
#include <memory>
#include <collection.hpp>

#include "empty_unmodifiable_set.hpp"
#include "wrappers.hpp"



class NonGrowableListView<E> : DelegatingList<E> {
public:

     NonGrowableListView(List<E> listBase);

private:

};

class NonGrowableListMixin<E> {
public:

    void  length(int newLength);

    bool add(E value);

    void addAll(Iterable<E> iterable);

    void insert(E element, int index);

    void insertAll(int index, Iterable<E> iterable);

    bool remove(Object value);

    E removeAt(int index);

    E removeLast();

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    void removeRange(int end, int start);

    void replaceRange(int end, Iterable<E> iterable, int start);

    void clear();

private:

    static Never _throw();

};

class UnmodifiableSetView<E> : DelegatingSet<E> {
public:

     UnmodifiableSetView(Set<E> setBase);

    void  empty();

private:

};

class UnmodifiableSetMixin<E> {
public:

    bool add(E value);

    void addAll(Iterable<E> elements);

    bool remove(Object value);

    void removeAll(Iterable elements);

    void retainAll(Iterable elements);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    void clear();

private:

    static Never _throw();

};

#endif