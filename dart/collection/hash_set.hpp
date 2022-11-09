#ifndef DART_COLLECTION_HASH_SET
#define DART_COLLECTION_HASH_SET
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename E> class HashSetCls : public ObjectCls {
public:

    extern  HashSetCls(bool equals(E , E ) , int hashCode(E ) , bool isValidKey(dynamic ) );
    extern void  identity();
    virtual void  from(Iterable<dynamic> elements);

    virtual void  of(Iterable<E> elements);

    virtual Iterator<E> iterator();
private:

};
template<typename E> using HashSet = std::shared_ptr<HashSetCls<E>>;


#endif