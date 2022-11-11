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

    virtual E firstWhere(std::function<bool(E element)> test, std::function<E()> orElse);

    virtual E lastWhere(std::function<bool(E element)> test, std::function<E()> orElse);

    virtual E singleWhere(std::function<bool(E element)> test, std::function<E()> orElse);

    virtual String join(String separator);

    virtual Iterable<E> where(std::function<bool(E element)> test);

    template<typename T>
 virtual Iterable<T> whereType();

    template<typename T>
 virtual Iterable<T> map(std::function<T(E element)> f);

    template<typename T>
 virtual Iterable<T> expand(std::function<Iterable<T>(E element)> f);

    virtual E reduce(std::function<E(E previousValue, E element)> combine);

    template<typename T>
 virtual T fold(T initialValue, std::function<T(T previousValue, E element)> combine);

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

    virtual List<E> sublist(int start, int end);

    virtual Iterable<E> getRange(int start, int end);

    virtual void removeRange(int start, int end);

    virtual void fillRange(int start, int end, E fill);

    virtual void setRange(int start, int end, Iterable<E> iterable, int skipCount);

    virtual void replaceRange(int start, int end, Iterable<E> newContents);

    virtual int indexOf(Object element, int start);

    virtual int indexWhere(std::function<bool(E element)> test, int start);

    virtual int lastIndexOf(Object element, int start);

    virtual int lastIndexWhere(std::function<bool(E element)> test, int start);

    virtual void insert(int index, E element);

    virtual E removeAt(int index);

    virtual void insertAll(int index, Iterable<E> iterable);

    virtual void setAll(int index, Iterable<E> iterable);

    virtual Iterable<E> reversed();

    virtual String toString();

private:

    virtual void _closeGap(int start, int end);

    virtual void _filter(std::function<bool(E element)> test, bool retainMatching);

    static int _compareAny(dynamic a, dynamic b);

};
template<typename E>
using ListMixin = std::shared_ptr<ListMixinCls<E>>;


#endif