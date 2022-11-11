#ifndef PACKAGES_COLLECTION_SRC_ITERABLE_ZIP
#define PACKAGES_COLLECTION_SRC_ITERABLE_ZIP
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>


template<typename T>
class IterableZipCls : public IterableBaseCls<List<T>> {
public:

     IterableZipCls(Iterable<Iterable<T>> iterables);

    virtual Iterator<List<T>> iterator();

private:
    Iterable<Iterable<T>> _iterables;


};
template<typename T>
using IterableZip = std::shared_ptr<IterableZipCls<T>>;

template<typename T>
class _IteratorZipCls : public ObjectCls {
public:

    virtual bool moveNext();

    virtual List<T> current();

private:
    List<Iterator<T>> _iterators;

    List<T> _current;


     _IteratorZipCls(List<Iterator<T>> iterators);

};
template<typename T>
using _IteratorZip = std::shared_ptr<_IteratorZipCls<T>>;


#endif