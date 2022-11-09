#ifndef DART_COLLECTION_COLLECTIONS
#define DART_COLLECTION_COLLECTIONS
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E> class UnmodifiableListViewCls : public UnmodifiableListBaseCls<E> {
public:

     UnmodifiableListViewCls(Iterable<E> source);

    template<typename R>  virtual List<R> cast();

    virtual int length();

    virtual E operator[](int index);

private:
    Iterable<E> _source;


};
template<typename E> using UnmodifiableListView = std::shared_ptr<UnmodifiableListViewCls<E>>;


#endif