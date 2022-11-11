#ifndef DART_CORE_SET
#define DART_CORE_SET
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E>
class SetCls : public EfficientLengthIterableCls<E> {
public:

     SetCls();
    virtual void  identity();
    virtual void  from(Iterable<any> elements);
    virtual void  of(Iterable<E> elements);
    virtual void  unmodifiable(Iterable<E> elements);

    template<typename S, typename T>
 static Set<T> castFrom(Set<S> source, std::function<Set<R>()> newSet);

    template<typename R>
 virtual Set<R> cast();
    virtual Iterator<E> iterator();
    virtual bool contains(Object value);
    virtual bool add(E value);
    virtual void addAll(Iterable<E> elements);
    virtual bool remove(Object value);
    virtual E lookup(Object object);
    virtual void removeAll(Iterable<Object> elements);
    virtual void retainAll(Iterable<Object> elements);
    virtual void removeWhere(std::function<bool(E element)> test);
    virtual void retainWhere(std::function<bool(E element)> test);
    virtual bool containsAll(Iterable<Object> other);
    virtual Set<E> intersection(Set<Object> other);
    virtual Set<E> union(Set<E> other);
    virtual Set<E> difference(Set<Object> other);
    virtual void clear();
    virtual Set<E> toSet();
private:

};
template<typename E>
using Set = std::shared_ptr<SetCls<E>>;


#endif