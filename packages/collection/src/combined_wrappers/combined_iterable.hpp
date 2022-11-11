#ifndef PACKAGES_COLLECTION_SRC_COMBINED_WRAPPERS_COMBINED_ITERABLE
#define PACKAGES_COLLECTION_SRC_COMBINED_WRAPPERS_COMBINED_ITERABLE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include "combined_iterator.hpp"


template<typename T>
class CombinedIterableViewCls : public IterableBaseCls<T> {
public:

     CombinedIterableViewCls(Iterable<Iterable<T>> _iterables);
    virtual Iterator<T> iterator();

    virtual bool contains(Object element);

    virtual bool isEmpty();

    virtual int length();

private:
    Iterable<Iterable<T>> _iterables;


};
template<typename T>
using CombinedIterableView = std::shared_ptr<CombinedIterableViewCls<T>>;


#endif