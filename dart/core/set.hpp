#ifndef SET_H
#define SET_H
#include <memory>




class Set<E> : EfficientLengthIterable<E> {
public:

     Set();

    void  identity();

    void  from(Iterable elements);

    void  of(Iterable<E> elements);

    void  unmodifiable(Iterable<E> elements);

    static Set<T> castFrom<S, T>(FunctionType newSet, Set<S> source);

    Set<R> cast<R>();

    Iterator<E> iterator();

    bool contains(Object value);

    bool add(E value);

    void addAll(Iterable<E> elements);

    bool remove(Object value);

    E lookup(Object object);

    void removeAll(Iterable<Object> elements);

    void retainAll(Iterable<Object> elements);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    bool containsAll(Iterable<Object> other);

    Set<E> intersection(Set<Object> other);

    Set<E> union(Set<E> other);

    Set<E> difference(Set<Object> other);

    void clear();

    Set<E> toSet();

private:

};

#endif