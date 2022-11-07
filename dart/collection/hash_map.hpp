#ifndef HASH_MAP_H
#define HASH_MAP_H
#include <memory>



bool _defaultEquals(Object a, Object b);

int _defaultHashCode(Object a);


class HashMap<K, V> {
public:

    external  HashMap(FunctionType equals, FunctionType hashCode, FunctionType isValidKey);

    external void  identity();

    void  from(Map<dynamic, dynamic> other);

    void  of(Map<K, V> other);

    void  fromIterable(Iterable iterable, FunctionType key, FunctionType value);

    void  fromIterables(Iterable<K> keys, Iterable<V> values);

    void  fromEntries(Iterable<MapEntry<K, V>> entries);

private:

};

#endif