#ifndef DART_COLLECTION_LINKED_HASH_MAP
#define DART_COLLECTION_LINKED_HASH_MAP
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename K, typename V>
class LinkedHashMapCls : public ObjectCls {
public:

     LinkedHashMapCls(std::function<bool(K , K )> equals, std::function<int(K )> hashCode, std::function<bool(Object )> isValidKey);
    void  identity();
    virtual void  from(Map<Object, Object> other);

    virtual void  of(Map<K, V> other);

    virtual void  fromIterable(Iterable<any> iterable, std::function<K(Object element)> key, std::function<V(Object element)> value);

    virtual void  fromIterables(Iterable<K> keys, Iterable<V> values);

    virtual void  fromEntries(Iterable<MapEntry<K, V>> entries);

private:

};
template<typename K, typename V>
using LinkedHashMap = std::shared_ptr<LinkedHashMapCls<K, V>>;


#endif