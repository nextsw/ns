#ifndef DART_CORE_ITERATOR
#define DART_CORE_ITERATOR
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E> class IteratorCls : public ObjectCls {
public:

    virtual bool moveNext();
    virtual E current();
private:

};
template<typename E> using Iterator = std::shared_ptr<IteratorCls<E>>;


#endif