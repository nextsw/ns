#ifndef SET_H
#define SET_H
#include <memory>




class SetMixin<E> {
public:

    bool add(E value);

    bool contains(Object element);

    E lookup(Object element);

    bool remove(Object value);

    Iterator<E> iterator();

    Set<E> toSet();

    int length();

    bool isEmpty();

    bool isNotEmpty();

    Set<R> cast<R>();

    Iterable<E> followedBy(Iterable<E> other);

    Iterable<T> whereType<T>();

    void clear();

    void addAll(Iterable<E> elements);

    void removeAll(Iterable<Object> elements);

    void retainAll(Iterable<Object> elements);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    bool containsAll(Iterable<Object> other);

    Set<E> union(Set<E> other);

    Set<E> intersection(Set<Object> other);

    Set<E> difference(Set<Object> other);

    List<E> toList(bool growable);

    Iterable<T> map<T>(FunctionType f);

    E single();

    String toString();

    Iterable<E> where(FunctionType f);

    Iterable<T> expand<T>(FunctionType f);

    void forEach(FunctionType f);

    E reduce(FunctionType combine);

    T fold<T>(FunctionType combine, T initialValue);

    bool every(FunctionType f);

    String join(String separator);

    bool any(FunctionType test);

    Iterable<E> take(int n);

    Iterable<E> takeWhile(FunctionType test);

    Iterable<E> skip(int n);

    Iterable<E> skipWhile(FunctionType test);

    E first();

    E last();

    E firstWhere(FunctionType orElse, FunctionType test);

    E lastWhere(FunctionType orElse, FunctionType test);

    E singleWhere(FunctionType orElse, FunctionType test);

    E elementAt(int index);

private:

};

class SetBase<E> {
public:

    static String setToString(Set set);

private:

};

class _SetBase<E> {
public:

    Set<R> cast<R>();

    Set<E> difference(Set<Object> other);

    Set<E> intersection(Set<Object> other);

    Set<E> toSet();

private:

     _SetBase();

    Set<E> _newSet();

    Set<R> _newSimilarSet<R>();

};

class _UnmodifiableSetMixin<E> {
public:

    bool add(E value);

    void clear();

    void addAll(Iterable<E> elements);

    void removeAll(Iterable<Object> elements);

    void retainAll(Iterable<Object> elements);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    bool remove(Object value);

private:

    static Never _throwUnmodifiable();

};

class _UnmodifiableSet<E> : _SetBase<E> {
public:

    bool contains(Object element);

    Iterator<E> iterator();

    int length();

    E lookup(Object element);

private:
    Map<E, Null> _map;


     _UnmodifiableSet(Map<E, Null> _map);

    Set<E> _newSet();

    Set<R> _newSimilarSet<R>();

};

class UnmodifiableSetView<E> : SetBase<E> {
public:

     UnmodifiableSetView(Set<E> source);

    bool contains(Object element);

    E lookup(Object element);

    int length();

    Iterator<E> iterator();

    Set<E> toSet();

private:
    Set<E> _source;


};

#endif