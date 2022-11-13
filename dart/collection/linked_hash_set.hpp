#ifndef DART_COLLECTION_LINKED_HASH_SET
#define DART_COLLECTION_LINKED_HASH_SET
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E>
class LinkedHashSetCls : public ObjectCls {
public:

     LinkedHashSetCls(std::function<bool(E , E )> equals, std::function<int(E )> hashCode, std::function<bool(Object )> isValidKey);
    void  identity();
    virtual void  from(Iterable<Object> elements);

    virtual void  of(Iterable<E> elements);

    virtual void forEach(std::function<void(E element)> action);
    virtual Iterator<E> iterator();
private:

};
template<typename E>
using LinkedHashSet = std::shared_ptr<LinkedHashSetCls<E>>;


#endif