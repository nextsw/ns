#ifndef EQUALITY_MAP_H
#define EQUALITY_MAP_H
#include <memory>

#include <collection/collection.hpp>
#include "equality.hpp"
#include "wrappers.hpp"



class EqualityMap<K, V> : DelegatingMap<K, V> {
public:

     EqualityMap(Equality<K> equality);

    void  from(Equality<K> equality, Map<K, V> other);

private:

};

#endif