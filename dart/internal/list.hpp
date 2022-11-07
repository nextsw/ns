#ifndef LIST_H
#define LIST_H
#include <memory>




class FixedLengthListMixin<E> {
public:

    void  length(int newLength);

    void add(E value);

    void insert(int index, E value);

    void insertAll(int at, Iterable<E> iterable);

    void addAll(Iterable<E> iterable);

    bool remove(Object element);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    void clear();

    E removeAt(int index);

    E removeLast();

    void removeRange(int end, int start);

    void replaceRange(int end, Iterable<E> iterable, int start);

private:

};

class UnmodifiableListMixin<E> {
public:

    void []=(int index, E value);

    void  length(int newLength);

    void  first(E element);

    void  last(E element);

    void setAll(int at, Iterable<E> iterable);

    void add(E value);

    void insert(E element, int index);

    void insertAll(int at, Iterable<E> iterable);

    void addAll(Iterable<E> iterable);

    bool remove(Object element);

    void removeWhere(FunctionType test);

    void retainWhere(FunctionType test);

    void sort(Comparator<E> compare);

    void shuffle(Random random);

    void clear();

    E removeAt(int index);

    E removeLast();

    void setRange(int end, Iterable<E> iterable, int skipCount, int start);

    void removeRange(int end, int start);

    void replaceRange(int end, Iterable<E> iterable, int start);

    void fillRange(int end, E fillValue, int start);

private:

};

class FixedLengthListBase<E> {
public:

private:

};

class UnmodifiableListBase<E> {
public:

private:

};

class _ListIndicesIterable : ListIterable<int> {
public:

    int length();

    int elementAt(int index);

private:
    List _backedList;


     _ListIndicesIterable(List _backedList);

};

class ListMapView<E> : UnmodifiableMapBase<int, E> {
public:

     ListMapView(List<E> _values);

    E [](Object key);

    int length();

    Iterable<E> values();

    Iterable<int> keys();

    bool isEmpty();

    bool isNotEmpty();

    bool containsValue(Object value);

    bool containsKey(Object key);

    void forEach(FunctionType f);

private:
    List<E> _values;


};

class ReversedListIterable<E> : ListIterable<E> {
public:

     ReversedListIterable(Iterable<E> _source);

    int length();

    E elementAt(int index);

private:
    Iterable<E> _source;


};

class UnmodifiableListError {
public:

    static UnsupportedError add();

    static UnsupportedError change();

    static UnsupportedError length();

    static UnsupportedError remove();

private:

};

class NonGrowableListError {
public:

    static UnsupportedError add();

    static UnsupportedError length();

    static UnsupportedError remove();

private:

};
external List<T> makeListFixedLength<T>(List<T> growableList);

external List<T> makeFixedListUnmodifiable<T>(List<T> fixedLengthList);


#endif