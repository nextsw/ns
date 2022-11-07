#ifndef ITERABLE_H
#define ITERABLE_H
#include <memory>




class Iterable<E> {
public:

     Iterable();

    void  generate(int count, FunctionType generator);

    void  empty();

    static Iterable<T> castFrom<S, T>(Iterable<S> source);

    Iterator<E> iterator();

    Iterable<R> cast<R>();

    Iterable<E> followedBy(Iterable<E> other);

    Iterable<T> map<T>(FunctionType toElement);

    Iterable<E> where(FunctionType test);

    Iterable<T> whereType<T>();

    Iterable<T> expand<T>(FunctionType toElements);

    bool contains(Object element);

    void forEach(FunctionType action);

    E reduce(FunctionType combine);

    T fold<T>(FunctionType combine, T initialValue);

    bool every(FunctionType test);

    String join(String separator);

    bool any(FunctionType test);

    List<E> toList(bool growable);

    Set<E> toSet();

    int length();

    bool isEmpty();

    bool isNotEmpty();

    Iterable<E> take(int count);

    Iterable<E> takeWhile(FunctionType test);

    Iterable<E> skip(int count);

    Iterable<E> skipWhile(FunctionType test);

    E first();

    E last();

    E single();

    E firstWhere(FunctionType orElse, FunctionType test);

    E lastWhere(FunctionType orElse, FunctionType test);

    E singleWhere(FunctionType orElse, FunctionType test);

    E elementAt(int index);

    String toString();

private:

};

class _GeneratorIterable<E> : ListIterable<E> {
public:
    int length;


    E elementAt(int index);

private:
    FunctionType _generator;


     _GeneratorIterable(FunctionType generator, int length);

    static int _id(int n);

};

class BidirectionalIterator<E> {
public:

    bool movePrevious();

private:

};

#endif