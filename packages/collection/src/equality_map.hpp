#ifndef PACKAGES_COLLECTION_SRC_EQUALITY_MAP
#define PACKAGES_COLLECTION_SRC_EQUALITY_MAP
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include "equality.hpp"
#include "wrappers.hpp"


template<typename K, typename V> class EqualityMapCls : public DelegatingMapCls<K, V> {
public:

     EqualityMapCls(Equality<K> equality);

    virtual void  from(Equality<K> equality, Map<K, V> other);

private:

};
template<typename K, typename V> using EqualityMap = std::shared_ptr<EqualityMapCls<K, V>>;


#endif