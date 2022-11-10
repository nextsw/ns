#ifndef DART_COLLECTION_LINKED_HASH_SET
#define DART_COLLECTION_LINKED_HASH_SET
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E> class LinkedHashSetCls : public ObjectCls {
public:

     LinkedHashSetCls(bool equals(E , E ) , int hashCode(E ) , bool isValidKey(dynamic ) );
    void  identity();
    virtual void  from(Iterable<dynamic> elements);

    virtual void  of(Iterable<E> elements);

    virtual void forEach(void action(E element) );
    virtual Iterator<E> iterator();
private:

};
template<typename E> using LinkedHashSet = std::shared_ptr<LinkedHashSetCls<E>>;


#endif