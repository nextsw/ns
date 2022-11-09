#ifndef PACKAGES_COLLECTION_SRC_UNION_SET_CONTROLLER
#define PACKAGES_COLLECTION_SRC_UNION_SET_CONTROLLER
#include <base.hpp>

#include <dart/core/core.hpp>
#include "union_set.hpp"


template<typename E> class UnionSetControllerCls : public ObjectCls {
public:
    UnionSet<E> set;


     UnionSetControllerCls(bool disjoint);

    virtual void add(Set<E> component);

    virtual bool remove(Set<E> component);

private:
    Set<Set<E>> _sets;


    virtual void  _(Set<Set<E>> _sets, bool disjoint);

};
template<typename E> using UnionSetController = std::shared_ptr<UnionSetControllerCls<E>>;


#endif