#ifndef PACKAGES_COLLECTION_SRC_EMPTY_UNMODIFIABLE_SET
#define PACKAGES_COLLECTION_SRC_EMPTY_UNMODIFIABLE_SET
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <packages/collection/collection.hpp>


template<typename E> class EmptyUnmodifiableSetCls : public IterableBaseCls<E> {
public:

     EmptyUnmodifiableSetCls();
    virtual Iterator<E> iterator();

    virtual int length();

    template<typename T>  virtual EmptyUnmodifiableSet<T> cast();

    virtual bool contains(Object element);

    virtual bool containsAll(Iterable<Object> other);

    virtual Iterable<E> followedBy(Iterable<E> other);

    virtual E lookup(Object element);

    template<typename T>  virtual EmptyUnmodifiableSet<T> retype();

    virtual E singleWhere(E orElse() , bool test(E ) );

    template<typename T>  virtual Iterable<T> whereType();

    virtual Set<E> toSet();

    virtual Set<E> union(Set<E> other);

    virtual Set<E> intersection(Set<Object> other);

    virtual Set<E> difference(Set<Object> other);

private:

};
template<typename E> using EmptyUnmodifiableSet = std::shared_ptr<EmptyUnmodifiableSetCls<E>>;


#endif