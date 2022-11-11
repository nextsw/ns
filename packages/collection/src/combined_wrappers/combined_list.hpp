#ifndef PACKAGES_COLLECTION_SRC_COMBINED_WRAPPERS_COMBINED_LIST
#define PACKAGES_COLLECTION_SRC_COMBINED_WRAPPERS_COMBINED_LIST
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include "combined_iterator.hpp"


template<typename T>
class CombinedListViewCls : public ListBaseCls<T> {
public:

     CombinedListViewCls(List<List<T>> _lists);
    virtual Iterator<T> iterator();

    virtual void  length(int length);

    virtual int length();

    virtual T operator[](int index);

    virtual void operator[]=(int index, T value);

    virtual void clear();

    virtual bool remove(Object element);

    virtual void removeWhere(std::function<bool(T )> test);

    virtual void retainWhere(std::function<bool(T )> test);

private:
    List<List<T>> _lists;


    static Never _throw();

};
template<typename T>
using CombinedListView = std::shared_ptr<CombinedListViewCls<T>>;


#endif