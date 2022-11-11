#ifndef PACKAGES_COLLECTION_SRC_UNION_SET
#define PACKAGES_COLLECTION_SRC_UNION_SET
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include "unmodifiable_wrappers.hpp"


template<typename E>
class UnionSetCls : public SetBaseCls<E> {
public:

     UnionSetCls(Set<Set<E>> sets, bool disjoint);

    virtual void  from(Iterable<Set<E>> sets, bool disjoint);

    virtual int length();

    virtual Iterator<E> iterator();

    virtual bool contains(Object element);

    virtual E lookup(Object element);

    virtual Set<E> toSet();

private:
    Set<Set<E>> _sets;

    bool _disjoint;


    virtual Iterable<E> _iterable();

};
template<typename E>
using UnionSet = std::shared_ptr<UnionSetCls<E>>;


#endif