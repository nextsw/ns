#ifndef PACKAGES_COLLECTION_SRC_LIST_EXTENSIONS
#define PACKAGES_COLLECTION_SRC_LIST_EXTENSIONS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <dart/math/math.hpp>
#include "algorithms.hpp"
#include "algorithms.hpp"
#include "equality.hpp"
#include "utils.hpp"


template<typename E>
class ListExtensionsCls : public ObjectCls {
public:

    virtual int binarySearch(E element, std::function<int(E , E )> compare);

    template<typename K>
 virtual int binarySearchByCompare(E element, std::function<K(E element)> keyOf, std::function<int(K , K )> compare, int start, int end);

    template<typename K>
 virtual int binarySearchBy(E element, std::function<K(E element)> keyOf, int start, int end);

    virtual int lowerBound(E element, std::function<int(E , E )> compare);

    template<typename K>
 virtual int lowerBoundByCompare(E element, std::function<K(E )> keyOf, std::function<int(K , K )> compare, int start, int end);

    template<typename K>
 virtual int lowerBoundBy(E element, std::function<K(E )> keyOf, int start, int end);

    virtual void forEachIndexed(std::function<void(int index, E element)> action);

    virtual void forEachWhile(std::function<bool(E element)> action);

    virtual void forEachIndexedWhile(std::function<bool(int index, E element)> action);

    template<typename R>
 virtual Iterable<R> mapIndexed(std::function<R(int index, E element)> convert);

    virtual Iterable<E> whereIndexed(std::function<bool(int index, E element)> test);

    virtual Iterable<E> whereNotIndexed(std::function<bool(int index, E element)> test);

    template<typename R>
 virtual Iterable<R> expandIndexed(std::function<Iterable<R>(int index, E element)> expand);

    virtual void sortRange(int start, int end, std::function<int(E a, E b)> compare);

    template<typename K>
 virtual void sortByCompare(std::function<K(E element)> keyOf, std::function<int(K a, K b)> compare, int start, int end);

    template<typename K>
 virtual void sortBy(std::function<K(E element)> keyOf, int start, int end);

    virtual void shuffleRange(int start, int end, Random random);

    virtual void reverseRange(int start, int end);

    virtual void swap(int index1, int index2);

    virtual ListSlice<E> slice(int start, int end);

    virtual bool equals(List<E> other, Equality<E> equality);

    virtual Iterable<List<E>> slices(int length);

private:

};
template<typename E>
using ListExtensions = std::shared_ptr<ListExtensionsCls<E>>;

template<typename E>
class ListComparableExtensionsCls : public ObjectCls {
public:

    virtual int binarySearch(E element, std::function<int(E , E )> compare);

    virtual int lowerBound(E element, std::function<int(E , E )> compare);

    virtual void sortRange(int start, int end, std::function<int(E a, E b)> compare);

private:

};
template<typename E>
using ListComparableExtensions = std::shared_ptr<ListComparableExtensionsCls<E>>;

template<typename E>
class ListSliceCls : public ListBaseCls<E> {
public:
    List<E> source;

    int start;

    int length;


     ListSliceCls(List<E> source, int start, int end);

    virtual int end();

    virtual E operator[](int index);

    virtual void operator[]=(int index, E value);

    virtual void setRange(int start, int end, Iterable<E> iterable, int skipCount);

    virtual ListSlice<E> slice(int start, int end);

    virtual void shuffle(Random random);

    virtual void sort(std::function<int(E a, E b)> compare);

    virtual void sortRange(int start, int end, std::function<int(E a, E b)> compare);

    virtual void shuffleRange(int start, int end, Random random);

    virtual void reverseRange(int start, int end);

    virtual void  length(int newLength);

    virtual void add(E element);

    virtual void insert(int index, E element);

    virtual void insertAll(int index, Iterable<E> iterable);

    virtual void addAll(Iterable<E> iterable);

    virtual bool remove(Object element);

    virtual void removeWhere(std::function<bool(E element)> test);

    virtual void retainWhere(std::function<bool(E element)> test);

    virtual void clear();

    virtual E removeAt(int index);

    virtual E removeLast();

    virtual void removeRange(int start, int end);

    virtual void replaceRange(int start, int end, Iterable<E> newContents);

private:
    int _initialSize;


    virtual void  _(int _initialSize, List<E> source, int start, int length);
};
template<typename E>
using ListSlice = std::shared_ptr<ListSliceCls<E>>;


#endif