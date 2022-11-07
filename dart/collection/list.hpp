#ifndef LIST_H
#define LIST_H
#include <memory>




class ListBase<E> : Object {
public:

    static String listToString(List list);

private:

};

class ListMixin<E> {
public:

    Iterator<E> iterator();

    E elementAt(int index);

    Iterable<E> followedBy(Iterable<E> other);

    void forEach(FunctionType action);

    bool isEmpty();

    bool isNotEmpty();

    E first();

    void first(E value);

    E last();

    void last(E value);

    E single();

    bool contains(Object element);

    bool every(FunctionType test);

    bool any(FunctionType test);

    E firstWhere(FunctionType orElse, FunctionType test);

    E lastWhere(FunctionType orElse, FunctionType test);

    E singleWhere(FunctionType orElse, FunctionType test);

    String join(String separator);

    Iterable<E> where(FunctionType test);

    Iterable<T> whereType<T>();

    Iterable<T> map<T>(FunctionType f);

    Iterable<T> expand<T>(FunctionType f);

    E reduce(FunctionType combine);

    T fold<T>(FunctionType combine, T initialValue);

    Iterable<E> skip(int count);

    Iterable<E> skipWhile(FunctionType test);

    Iterable<E> take(int count);

    Iterable<E> takeWhile(FunctionType test);

    List<E> toList(bool growable);

    Set<E> toSet();

    void add(E element);

    void addAll(Iterable<E> iterable);

    bool remove(Object element);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    void clear();

    List<R> cast<R>();

    E removeLast();

    void sort(FunctionType compare);

    void shuffle(Random random);

    Map<int, E> asMap();

    List<E> +(List<E> other);

    List<E> sublist(int end, int start);

    Iterable<E> getRange(int end, int start);

    void removeRange(int end, int start);

    void fillRange(int end, E fill, int start);

    void setRange(int end, Iterable<E> iterable, int skipCount, int start);

    void replaceRange(int end, Iterable<E> newContents, int start);

    int indexOf(Object element, int start);

    int indexWhere(int start, FunctionType test);

    int lastIndexOf(Object element, int start);

    int lastIndexWhere(int start, FunctionType test);

    void insert(E element, int index);

    E removeAt(int index);

    void insertAll(int index, Iterable<E> iterable);

    void setAll(int index, Iterable<E> iterable);

    Iterable<E> reversed();

    String toString();

private:

    void _closeGap(int end, int start);

    void _filter(bool retainMatching, FunctionType test);

    static int _compareAny(dynamic a, dynamic b);

};

#endif