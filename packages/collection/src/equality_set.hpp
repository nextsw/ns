#ifndef PACKAGES_COLLECTION_SRC_EQUALITY_SET
#define PACKAGES_COLLECTION_SRC_EQUALITY_SET
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include "equality.hpp"
#include "wrappers.hpp"


template<typename E>
class EqualitySetCls : public DelegatingSetCls<E> {
public:

     EqualitySetCls(Equality<E> equality);

    virtual void  from(Equality<E> equality, Iterable<E> other);

private:

};
template<typename E>
using EqualitySet = std::shared_ptr<EqualitySetCls<E>>;


#endif