#ifndef DART_INTERNAL_LIST
#define DART_INTERNAL_LIST
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E>
class FixedLengthListMixinCls : public ObjectCls {
public:

    virtual void  length(int newLength);

    virtual void add(E value);

    virtual void insert(int index, E value);

    virtual void insertAll(int at, Iterable<E> iterable);

    virtual void addAll(Iterable<E> iterable);

    virtual bool remove(Object element);

    virtual void removeWhere(std::function<bool(E element)> test);

    virtual void retainWhere(std::function<bool(E element)> test);

    virtual void clear();

    virtual E removeAt(int index);

    virtual E removeLast();

    virtual void removeRange(int end, int start);

    virtual void replaceRange(int end, Iterable<E> iterable, int start);

private:

};
template<typename E>
using FixedLengthListMixin = std::shared_ptr<FixedLengthListMixinCls<E>>;

template<typename E>
class UnmodifiableListMixinCls : public ObjectCls {
public:

    virtual void operator[]=(int index, E value);

    virtual void  length(int newLength);

    virtual void  first(E element);

    virtual void  last(E element);

    virtual void setAll(int at, Iterable<E> iterable);

    virtual void add(E value);

    virtual void insert(E element, int index);

    virtual void insertAll(int at, Iterable<E> iterable);

    virtual void addAll(Iterable<E> iterable);

    virtual bool remove(Object element);

    virtual void removeWhere(std::function<bool(E element)> test);

    virtual void retainWhere(std::function<bool(E element)> test);

    virtual void sort(Comparator<E> compare);

    virtual void shuffle(Random random);

    virtual void clear();

    virtual E removeAt(int index);

    virtual E removeLast();

    virtual void setRange(int end, Iterable<E> iterable, int skipCount, int start);

    virtual void removeRange(int end, int start);

    virtual void replaceRange(int end, Iterable<E> iterable, int start);

    virtual void fillRange(int end, E fillValue, int start);

private:

};
template<typename E>
using UnmodifiableListMixin = std::shared_ptr<UnmodifiableListMixinCls<E>>;

template<typename E>
class FixedLengthListBaseCls : public ObjectCls {
public:

private:

};
template<typename E>
using FixedLengthListBase = std::shared_ptr<FixedLengthListBaseCls<E>>;

template<typename E>
class UnmodifiableListBaseCls : public ObjectCls {
public:

private:

};
template<typename E>
using UnmodifiableListBase = std::shared_ptr<UnmodifiableListBaseCls<E>>;

class _ListIndicesIterableCls : public ListIterableCls<int> {
public:

    virtual int length();

    virtual int elementAt(int index);

private:
    List _backedList;


     _ListIndicesIterableCls(List _backedList);
};
using _ListIndicesIterable = std::shared_ptr<_ListIndicesIterableCls>;

template<typename E>
class ListMapViewCls : public UnmodifiableMapBaseCls<int, E> {
public:

     ListMapViewCls(List<E> _values);
    virtual E operator[](Object key);

    virtual int length();

    virtual Iterable<E> values();

    virtual Iterable<int> keys();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual bool containsValue(Object value);

    virtual bool containsKey(Object key);

    virtual void forEach(std::function<void(int key, E value)> f);

private:
    List<E> _values;


};
template<typename E>
using ListMapView = std::shared_ptr<ListMapViewCls<E>>;

template<typename E>
class ReversedListIterableCls : public ListIterableCls<E> {
public:

     ReversedListIterableCls(Iterable<E> _source);
    virtual int length();

    virtual E elementAt(int index);

private:
    Iterable<E> _source;


};
template<typename E>
using ReversedListIterable = std::shared_ptr<ReversedListIterableCls<E>>;

class UnmodifiableListErrorCls : public ObjectCls {
public:

    static UnsupportedError add();

    static UnsupportedError change();

    static UnsupportedError length();

    static UnsupportedError remove();

private:

};
using UnmodifiableListError = std::shared_ptr<UnmodifiableListErrorCls>;

class NonGrowableListErrorCls : public ObjectCls {
public:

    static UnsupportedError add();

    static UnsupportedError length();

    static UnsupportedError remove();

private:

};
using NonGrowableListError = std::shared_ptr<NonGrowableListErrorCls>;
template<typename T>
 List<T> makeListFixedLength(List<T> growableList);
template<typename T>
 List<T> makeFixedListUnmodifiable(List<T> fixedLengthList);


#endif