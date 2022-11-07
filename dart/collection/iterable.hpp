#ifndef ITERABLE_H
#define ITERABLE_H
#include <memory>




class IterableMixin<E> {
public:

    Iterable<R> cast<R>();

    Iterable<T> map<T>(FunctionType toElement);

    Iterable<E> where(FunctionType test);

    Iterable<T> whereType<T>();

    Iterable<T> expand<T>(FunctionType toElements);

    Iterable<E> followedBy(Iterable<E> other);

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

class IterableBase<E> : Iterable<E> {
public:

     IterableBase();

    static String iterableToShortString(Iterable iterable, String leftDelimiter, String rightDelimiter);

    static String iterableToFullString(Iterable iterable, String leftDelimiter, String rightDelimiter);

private:

};
List<Object> _toStringVisiting;

bool _isToStringVisiting(Object o);

void _iterablePartsToStrings(Iterable<Object> iterable, List<String> parts);


#endif