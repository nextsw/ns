#ifndef DART_COLLECTION_LIST
#define DART_COLLECTION_LIST
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E>
class ListBaseCls : public ObjectCls {
public:

    static String listToString(List list);

private:

};
template<typename E>
using ListBase = std::shared_ptr<ListBaseCls<E>>;

template<typename E>
class ListMixinCls : public ObjectCls {
public:

    virtual Iterator<E> iterator();

    virtual E elementAt(int index);

    virtual Iterable<E> followedBy(Iterable<E> other);

    virtual void forEach(std::function<void(E element)> action);

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual E first();

    virtual void first(E value);

    virtual E last();

    virtual void last(E value);

    virtual E single();

    virtual bool contains(Object element);

    virtual bool every(std::function<bool(E element)> test);

    virtual bool any(std::function<bool(E element)> test);

    virtual E firstWhere(std::function<E()> orElse, std::function<bool(E element)> test);

    virtual E lastWhere(std::function<E()> orElse, std::function<bool(E element)> test);

    virtual E singleWhere(std::function<E()> orElse, std::function<bool(E element)> test);

    virtual String join(String separator);

    virtual Iterable<E> where(std::function<bool(E element)> test);

    template<typename T>
 virtual Iterable<T> whereType();

    template<typename T>
 virtual Iterable<T> map(std::function<T(E element)> f);

    template<typename T>
 virtual Iterable<T> expand(std::function<Iterable<T>(E element)> f);

    virtual E reduce(std::function<E(E element, E previousValue)> combine);

    template<typename T>
 virtual T fold(std::function<T(E element, T previousValue)> combine, T initialValue);

    virtual Iterable<E> skip(int count);

    virtual Iterable<E> skipWhile(std::function<bool(E element)> test);

    virtual Iterable<E> take(int count);

    virtual Iterable<E> takeWhile(std::function<bool(E element)> test);

    virtual List<E> toList(bool growable);

    virtual Set<E> toSet();

    virtual void add(E element);

    virtual void addAll(Iterable<E> iterable);

    virtual bool remove(Object element);

    virtual void removeWhere(std::function<bool(E element)> test);

    virtual void retainWhere(std::function<bool(E element)> test);

    virtual void clear();

    template<typename R>
 virtual List<R> cast();

    virtual E removeLast();

    virtual void sort(std::function<int(E a, E b)> compare);

    virtual void shuffle(Random random);

    virtual Map<int, E> asMap();

    virtual List<E> operator+(List<E> other);

    virtual List<E> sublist(int end, int start);

    virtual Iterable<E> getRange(int end, int start);

    virtual void removeRange(int end, int start);

    virtual void fillRange(int end, E fill, int start);

    virtual void setRange(int end, Iterable<E> iterable, int skipCount, int start);

    virtual void replaceRange(int end, Iterable<E> newContents, int start);

    virtual int indexOf(Object element, int start);

    virtual int indexWhere(int start, std::function<bool(E element)> test);

    virtual int lastIndexOf(Object element, int start);

    virtual int lastIndexWhere(int start, std::function<bool(E element)> test);

    virtual void insert(E element, int index);

    virtual E removeAt(int index);

    virtual void insertAll(int index, Iterable<E> iterable);

    virtual void setAll(int index, Iterable<E> iterable);

    virtual Iterable<E> reversed();

    virtual String toString();

private:

    virtual void _closeGap(int end, int start);

    virtual void _filter(bool retainMatching, std::function<bool(E element)> test);

    static int _compareAny(dynamic a, dynamic b);

};
template<typename E>
using ListMixin = std::shared_ptr<ListMixinCls<E>>;


#endif