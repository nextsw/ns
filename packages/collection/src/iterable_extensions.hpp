#ifndef PACKAGES_COLLECTION_SRC_ITERABLE_EXTENSIONS
#define PACKAGES_COLLECTION_SRC_ITERABLE_EXTENSIONS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/collection/src/utils.hpp>
#include "algorithms.hpp"


template<typename T>
class IterableExtensionCls : public ObjectCls {
public:

    virtual List<T> sample(int count, Random random);

    virtual Iterable<T> whereNot(std::function<bool(T element)> test);

    virtual List<T> sorted(Comparator<T> compare);

    template<typename K>
 virtual List<T> sortedBy(std::function<K(T element)> keyOf);

    template<typename K>
 virtual List<T> sortedByCompare(std::function<K(T element)> keyOf, Comparator<K> compare);

    virtual bool isSorted(Comparator<T> compare);

    template<typename K>
 virtual bool isSortedBy(std::function<K(T element)> keyOf);

    template<typename K>
 virtual bool isSortedByCompare(std::function<K(T element)> keyOf, Comparator<K> compare);

    virtual void forEachIndexed(std::function<void(int index, T element)> action);

    virtual void forEachWhile(std::function<bool(T element)> action);

    virtual void forEachIndexedWhile(std::function<bool(int index, T element)> action);

    template<typename R>
 virtual Iterable<R> mapIndexed(std::function<R(int index, T element)> convert);

    virtual Iterable<T> whereIndexed(std::function<bool(int index, T element)> test);

    virtual Iterable<T> whereNotIndexed(std::function<bool(int index, T element)> test);

    template<typename R>
 virtual Iterable<R> expandIndexed(std::function<Iterable<R>(int index, T element)> expand);

    virtual T reduceIndexed(std::function<T(int index, T previous, T element)> combine);

    template<typename R>
 virtual R foldIndexed(R initialValue, std::function<R(int index, R previous, T element)> combine);

    virtual T firstWhereOrNull(std::function<bool(T element)> test);

    virtual T firstWhereIndexedOrNull(std::function<bool(int index, T element)> test);

    virtual T firstOrNull();

    virtual T lastWhereOrNull(std::function<bool(T element)> test);

    virtual T lastWhereIndexedOrNull(std::function<bool(int index, T element)> test);

    virtual T lastOrNull();

    virtual T singleWhereOrNull(std::function<bool(T element)> test);

    virtual T singleWhereIndexedOrNull(std::function<bool(int index, T element)> test);

    virtual T singleOrNull();

    template<typename K, typename G>
 virtual Map<K, G> groupFoldBy(std::function<K(T element)> keyOf, std::function<G(G previous, T element)> combine);

    template<typename K>
 virtual Map<K, Set<T>> groupSetsBy(std::function<K(T element)> keyOf);

    template<typename K>
 virtual Map<K, List<T>> groupListsBy(std::function<K(T element)> keyOf);

    virtual Iterable<List<T>> splitBefore(std::function<bool(T element)> test);

    virtual Iterable<List<T>> splitAfter(std::function<bool(T element)> test);

    virtual Iterable<List<T>> splitBetween(std::function<bool(T first, T second)> test);

    virtual Iterable<List<T>> splitBeforeIndexed(std::function<bool(int index, T element)> test);

    virtual Iterable<List<T>> splitAfterIndexed(std::function<bool(int index, T element)> test);

    virtual Iterable<List<T>> splitBetweenIndexed(std::function<bool(int index, T first, T second)> test);

    virtual bool none(std::function<bool(T )> test);

    virtual Iterable<List<T>> slices(int length);

private:

};
template<typename T>
using IterableExtension = std::shared_ptr<IterableExtensionCls<T>>;

template<typename T>
class IterableNullableExtensionCls : public ObjectCls {
public:

    virtual Iterable<T> whereNotNull();

private:

};
template<typename T>
using IterableNullableExtension = std::shared_ptr<IterableNullableExtensionCls<T>>;

class IterableNumberExtensionCls : public ObjectCls {
public:

    virtual num minOrNull();

    virtual num min();

    virtual num maxOrNull();

    virtual num max();

    virtual num sum();

    virtual double average();

private:

};
using IterableNumberExtension = std::shared_ptr<IterableNumberExtensionCls>;

class IterableIntegerExtensionCls : public ObjectCls {
public:

    virtual int minOrNull();

    virtual int min();

    virtual int maxOrNull();

    virtual int max();

    virtual int sum();

    virtual double average();

private:

};
using IterableIntegerExtension = std::shared_ptr<IterableIntegerExtensionCls>;

class IterableDoubleExtensionCls : public ObjectCls {
public:

    virtual double minOrNull();

    virtual double min();

    virtual double maxOrNull();

    virtual double max();

    virtual double sum();

private:

};
using IterableDoubleExtension = std::shared_ptr<IterableDoubleExtensionCls>;

template<typename T>
class IterableIterableExtensionCls : public ObjectCls {
public:

    virtual Iterable<T> flattened();

private:

};
template<typename T>
using IterableIterableExtension = std::shared_ptr<IterableIterableExtensionCls<T>>;

template<typename T>
class IterableComparableExtensionCls : public ObjectCls {
public:

    virtual T minOrNull();

    virtual T min();

    virtual T maxOrNull();

    virtual T max();

    virtual List<T> sorted(Comparator<T> compare);

    virtual bool isSorted(Comparator<T> compare);

private:

};
template<typename T>
using IterableComparableExtension = std::shared_ptr<IterableComparableExtensionCls<T>>;

template<typename T>
class ComparatorExtensionCls : public ObjectCls {
public:

    virtual Comparator<T> inverse();

    template<typename R>
 virtual Comparator<R> compareBy(std::function<T(R )> keyOf);

    virtual Comparator<T> then(Comparator<T> tieBreaker);

private:

};
template<typename T>
using ComparatorExtension = std::shared_ptr<ComparatorExtensionCls<T>>;


#endif