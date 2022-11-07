#ifndef LIST_H
#define LIST_H
#include <memory>




class List<E> {
public:

    external  List(int length);

    external void  filled(E fill, bool growable, int length);

    external void  empty(bool growable);

    external void  from(Iterable elements, bool growable);

    external void  of(Iterable<E> elements, bool growable);

    external void  generate(FunctionType generator, bool growable, int length);

    external void  unmodifiable(Iterable elements);

    static List<T> castFrom<S, T>(List<S> source);

    static void copyRange<T>(int at, int end, List<T> source, int start, List<T> target);

    static void writeIterable<T>(int at, Iterable<T> source, List<T> target);

    List<R> cast<R>();

    E [](int index);

    void []=(int index, E value);

    void first(E value);

    void last(E value);

    int length();

    void  length(int newLength);

    void add(E value);

    void addAll(Iterable<E> iterable);

    Iterable<E> reversed();

    void sort(FunctionType compare);

    void shuffle(Random random);

    int indexOf(E element, int start);

    int indexWhere(int start, FunctionType test);

    int lastIndexWhere(int start, FunctionType test);

    int lastIndexOf(E element, int start);

    void clear();

    void insert(E element, int index);

    void insertAll(int index, Iterable<E> iterable);

    void setAll(int index, Iterable<E> iterable);

    bool remove(Object value);

    E removeAt(int index);

    E removeLast();

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    List<E> +(List<E> other);

    List<E> sublist(int end, int start);

    Iterable<E> getRange(int end, int start);

    void setRange(int end, Iterable<E> iterable, int skipCount, int start);

    void removeRange(int end, int start);

    void fillRange(int end, E fillValue, int start);

    void replaceRange(int end, Iterable<E> replacements, int start);

    Map<int, E> asMap();

    bool ==(Object other);

private:

};

#endif