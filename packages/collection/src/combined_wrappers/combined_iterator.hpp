#ifndef PACKAGES_COLLECTION_SRC_COMBINED_WRAPPERS_COMBINED_ITERATOR
#define PACKAGES_COLLECTION_SRC_COMBINED_WRAPPERS_COMBINED_ITERATOR
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class CombinedIteratorCls : public ObjectCls {
public:

     CombinedIteratorCls(Iterator<Iterator<T>> iterators);

    virtual T current();

    virtual bool moveNext();

private:
    Iterator<Iterator<T>> _iterators;


};
template<typename T>
using CombinedIterator = std::shared_ptr<CombinedIteratorCls<T>>;


#endif