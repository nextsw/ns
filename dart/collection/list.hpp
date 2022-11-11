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

    virtual void forEach(void action(E element) );

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual E first();

    virtual void first(E value);

    virtual E last();

    virtual void last(E value);

    virtual E single();

    virtual bool contains(Object element);

    virtual bool every(bool test(E element) );

    virtual bool any(bool test(E element) );

    virtual E firstWhere(E orElse() , bool test(E element) );

    virtual E lastWhere(E orElse() , bool test(E element) );

    virtual E singleWhere(E orElse() , bool test(E element) );

    virtual String join(String separator);

    virtual Iterable<E> where(bool test(E element) );

    template<typename T>
 virtual Iterable<T> whereType();

    template<typename T>
 virtual Iterable<T> map(T f(E element) );

    template<typename T>
 virtual Iterable<T> expand(Iterable<T> f(E element) );

    virtual E reduce(E combine(E element, E previousValue) );

    template<typename T>
 virtual T fold(T combine(E element, T previousValue) , T initialValue);

    virtual Iterable<E> skip(int count);

    virtual Iterable<E> skipWhile(bool test(E element) );

    virtual Iterable<E> take(int count);

    virtual Iterable<E> takeWhile(bool test(E element) );

    virtual List<E> toList(bool growable);

    virtual Set<E> toSet();

    virtual void add(E element);

    virtual void addAll(Iterable<E> iterable);

    virtual bool remove(Object element);

    virtual void removeWhere(bool test(E element) );

    virtual void retainWhere(bool test(E element) );

    virtual void clear();

    template<typename R>
 virtual List<R> cast();

    virtual E removeLast();

    virtual void sort(int compare(E a, E b) );

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

    virtual int indexWhere(int start, bool test(E element) );

    virtual int lastIndexOf(Object element, int start);

    virtual int lastIndexWhere(int start, bool test(E element) );

    virtual void insert(E element, int index);

    virtual E removeAt(int index);

    virtual void insertAll(int index, Iterable<E> iterable);

    virtual void setAll(int index, Iterable<E> iterable);

    virtual Iterable<E> reversed();

    virtual String toString();

private:

    virtual void _closeGap(int end, int start);

    virtual void _filter(bool retainMatching, bool test(E element) );

    static int _compareAny(dynamic a, dynamic b);

};
template<typename E>
using ListMixin = std::shared_ptr<ListMixinCls<E>>;


#endif