#ifndef DART_COLLECTION_ITERATOR
#define DART_COLLECTION_ITERATOR
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E> class HasNextIteratorCls : public ObjectCls {
public:

     HasNextIteratorCls(Iterator<E> _iterator);
    virtual bool hasNext();

    virtual E next();

private:
    static int _HAS_NEXT_AND_NEXT_IN_CURRENT;

    static int _NO_NEXT;

    static int _NOT_MOVED_YET;

    Iterator<E> _iterator;

    int _state;


    virtual void _move();

};
template<typename E> using HasNextIterator = std::shared_ptr<HasNextIteratorCls<E>>;


#endif