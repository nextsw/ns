#ifndef DART_COLLECTION_HASH_MAP
#define DART_COLLECTION_HASH_MAP
#include <base.hpp>

#include <dart/core/core.hpp>

bool _defaultEquals(Object a, Object b);

int _defaultHashCode(Object a);


template<typename K, typename V>
class HashMapCls : public ObjectCls {
public:

     HashMapCls(bool equals(K , K ) , int hashCode(K ) , bool isValidKey(dynamic ) );
    void  identity();
    virtual void  from(Map<dynamic, dynamic> other);

    virtual void  of(Map<K, V> other);

    virtual void  fromIterable(Iterable iterable, K key(dynamic element) , V value(dynamic element) );

    virtual void  fromIterables(Iterable<K> keys, Iterable<V> values);

    virtual void  fromEntries(Iterable<MapEntry<K, V>> entries);

private:

};
template<typename K, typename V>
using HashMap = std::shared_ptr<HashMapCls<K, V>>;


#endif