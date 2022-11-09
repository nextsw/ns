#ifndef DART_COLLECTION_SET
#define DART_COLLECTION_SET
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E> class SetMixinCls : public ObjectCls {
public:

    virtual bool add(E value);
    virtual bool contains(Object element);
    virtual E lookup(Object element);
    virtual bool remove(Object value);
    virtual Iterator<E> iterator();
    virtual Set<E> toSet();
    virtual int length();
    virtual bool isEmpty();

    virtual bool isNotEmpty();

    template<typename R>  virtual Set<R> cast();

    virtual Iterable<E> followedBy(Iterable<E> other);

    template<typename T>  virtual Iterable<T> whereType();

    virtual void clear();

    virtual void addAll(Iterable<E> elements);

    virtual void removeAll(Iterable<Object> elements);

    virtual void retainAll(Iterable<Object> elements);

    virtual void removeWhere(bool test(E element) );

    virtual void retainWhere(bool test(E element) );

    virtual bool containsAll(Iterable<Object> other);

    virtual Set<E> union(Set<E> other);

    virtual Set<E> intersection(Set<Object> other);

    virtual Set<E> difference(Set<Object> other);

    virtual List<E> toList(bool growable);

    template<typename T>  virtual Iterable<T> map(T f(E element) );

    virtual E single();

    virtual String toString();

    virtual Iterable<E> where(bool f(E element) );

    template<typename T>  virtual Iterable<T> expand(Iterable<T> f(E element) );

    virtual void forEach(void f(E element) );

    virtual E reduce(E combine(E element, E value) );

    template<typename T>  virtual T fold(T combine(E element, T previousValue) , T initialValue);

    virtual bool every(bool f(E element) );

    virtual String join(String separator);

    virtual bool any(bool test(E element) );

    virtual Iterable<E> take(int n);

    virtual Iterable<E> takeWhile(bool test(E value) );

    virtual Iterable<E> skip(int n);

    virtual Iterable<E> skipWhile(bool test(E value) );

    virtual E first();

    virtual E last();

    virtual E firstWhere(E orElse() , bool test(E value) );

    virtual E lastWhere(E orElse() , bool test(E value) );

    virtual E singleWhere(E orElse() , bool test(E value) );

    virtual E elementAt(int index);

private:

};
template<typename E> using SetMixin = std::shared_ptr<SetMixinCls<E>>;

template<typename E> class SetBaseCls : public ObjectCls {
public:

    static String setToString(Set set);

private:

};
template<typename E> using SetBase = std::shared_ptr<SetBaseCls<E>>;

template<typename E> class _SetBaseCls : public ObjectCls {
public:

    template<typename R>  virtual Set<R> cast();

    virtual Set<E> difference(Set<Object> other);

    virtual Set<E> intersection(Set<Object> other);

    virtual Set<E> toSet();

private:

     _SetBaseCls();
    virtual Set<E> _newSet();
    template<typename R>  virtual Set<R> _newSimilarSet();
};
template<typename E> using _SetBase = std::shared_ptr<_SetBaseCls<E>>;

template<typename E> class _UnmodifiableSetMixinCls : public ObjectCls {
public:

    virtual bool add(E value);

    virtual void clear();

    virtual void addAll(Iterable<E> elements);

    virtual void removeAll(Iterable<Object> elements);

    virtual void retainAll(Iterable<Object> elements);

    virtual void removeWhere(bool test(E element) );

    virtual void retainWhere(bool test(E element) );

    virtual bool remove(Object value);

private:

    static Never _throwUnmodifiable();

};
template<typename E> using _UnmodifiableSetMixin = std::shared_ptr<_UnmodifiableSetMixinCls<E>>;

template<typename E> class _UnmodifiableSetCls : public _SetBaseCls<E> {
public:

    virtual bool contains(Object element);

    virtual Iterator<E> iterator();

    virtual int length();

    virtual E lookup(Object element);

private:
    Map<E, Null> _map;


     _UnmodifiableSetCls(Map<E, Null> _map);
    virtual Set<E> _newSet();

    template<typename R>  virtual Set<R> _newSimilarSet();

};
template<typename E> using _UnmodifiableSet = std::shared_ptr<_UnmodifiableSetCls<E>>;

template<typename E> class UnmodifiableSetViewCls : public SetBaseCls<E> {
public:

     UnmodifiableSetViewCls(Set<E> source);

    virtual bool contains(Object element);

    virtual E lookup(Object element);

    virtual int length();

    virtual Iterator<E> iterator();

    virtual Set<E> toSet();

private:
    Set<E> _source;


};
template<typename E> using UnmodifiableSetView = std::shared_ptr<UnmodifiableSetViewCls<E>>;


#endif