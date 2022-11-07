#ifndef LINKED_HASH_MAP_H
#define LINKED_HASH_MAP_H
#include <memory>




class LinkedHashMap<K, V> {
public:

    external  LinkedHashMap(FunctionType equals, FunctionType hashCode, FunctionType isValidKey);

    external void  identity();

    void  from(Map<dynamic, dynamic> other);

    void  of(Map<K, V> other);

    void  fromIterable(Iterable iterable, FunctionType key, FunctionType value);

    void  fromIterables(Iterable<K> keys, Iterable<V> values);

    void  fromEntries(Iterable<MapEntry<K, V>> entries);

private:

};

#endif