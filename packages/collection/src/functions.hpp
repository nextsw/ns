#ifndef PACKAGES_COLLECTION_SRC_FUNCTIONS
#define PACKAGES_COLLECTION_SRC_FUNCTIONS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <dart/math/math.hpp>
#include "utils.hpp"

template<typename K1, typename V1, typename K2, typename V2>
 Map<K2, V2> mapMap(Map<K1, V1> map, std::function<K2(K1 , V1 )> key, std::function<V2(K1 , V1 )> value);

template<typename K, typename V>
 Map<K, V> mergeMaps(Map<K, V> map1, Map<K, V> map2, std::function<V(V , V )> value);

template<typename S, typename T>
 Map<T, List<S>> groupBy(Iterable<S> values, std::function<T(S )> key);

template<typename S, typename T>
 S minBy(Iterable<S> values, std::function<T(S )> orderBy, std::function<int(T , T )> compare);

template<typename S, typename T>
 S maxBy(Iterable<S> values, std::function<T(S )> orderBy, std::function<int(T , T )> compare);

template<typename T>
 Map<T, Set<T>> transitiveClosure(Map<T, Iterable<T>> graph);

template<typename T>
 List<Set<T>> stronglyConnectedComponents(Map<T, Iterable<T>> graph);



#endif