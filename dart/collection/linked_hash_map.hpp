#ifndef DART_COLLECTION_LINKED_HASH_MAP
#define DART_COLLECTION_LINKED_HASH_MAP
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename K, typename V>
class LinkedHashMapCls : public ObjectCls {
public:

     LinkedHashMapCls(bool equals(K , K ) , int hashCode(K ) , bool isValidKey(dynamic ) );
    void  identity();
    virtual void  from(Map<dynamic, dynamic> other);

    virtual void  of(Map<K, V> other);

    virtual void  fromIterable(Iterable iterable, K key(dynamic element) , V value(dynamic element) );

    virtual void  fromIterables(Iterable<K> keys, Iterable<V> values);

    virtual void  fromEntries(Iterable<MapEntry<K, V>> entries);

private:

};
template<typename K, typename V>
using LinkedHashMap = std::shared_ptr<LinkedHashMapCls<K, V>>;


#endif