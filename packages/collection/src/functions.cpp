#include "functions.hpp"
template<typename K1, typename V1, typename K2, typename V2>
Map<K2, V2> mapMap(Map<K1, V1> map, std::function<K2(K1 , V1 )> key, std::function<V2(K1 , V1 )> value) {
    auto keyFn = key | [=] (Unknown  mapKey,Unknown  _) {
    as<K2>(mapKey);
};
    auto valueFn = value | [=] (Unknown  _,Unknown  mapValue) {
    as<V2>(mapValue);
};
    auto result = makeMap(makeList(), makeList();
    map->forEach([=] (Unknown  mapKey,Unknown  mapValue) {
        result[keyFn(mapKey, mapValue)] = valueFn(mapKey, mapValue);
    });
    return result;
}

template<typename K, typename V>
Map<K, V> mergeMaps(Map<K, V> map1, Map<K, V> map2, std::function<V(V , V )> value) {
    auto result = <K, V>of(map1);
    auto _c1 = result;_c1.addAll(map2);if (value == nullptr) {
        return _c1;
    }
    map2->forEach([=] (Unknown  key,Unknown  mapValue) {
        result[key] = result->containsKey(key)? value(as<V>(result[key]), mapValue) : mapValue;
    });
    return result;
}

template<typename S, typename T>
Map<T, List<S>> groupBy(Iterable<S> values, std::function<T(S )> key) {
    auto map = makeMap(makeList(), makeList();
    for (auto element : values) {
        (map[key(element)] ??= makeList())->add(element);
    }
    return map;
}

template<typename S, typename T>
S minBy(Iterable<S> values, std::function<T(S )> orderBy, std::function<int(T , T )> compare) {
    compare |= defaultCompare;
    S minValue;
    T minOrderBy;
    for (auto element : values) {
        auto elementOrderBy = orderBy(element);
        if (minOrderBy == nullptr || compare(elementOrderBy, minOrderBy) < 0) {
            minValue = element;
            minOrderBy = elementOrderBy;
        }
    }
    return minValue;
}

template<typename S, typename T>
S maxBy(Iterable<S> values, std::function<T(S )> orderBy, std::function<int(T , T )> compare) {
    compare |= defaultCompare;
    S maxValue;
    T maxOrderBy;
    for (auto element : values) {
        auto elementOrderBy = orderBy(element);
        if (maxOrderBy == nullptr || compare(elementOrderBy, maxOrderBy)! > 0) {
            maxValue = element;
            maxOrderBy = elementOrderBy;
        }
    }
    return maxValue;
}

template<typename T>
Map<T, Set<T>> transitiveClosure(Map<T, Iterable<T>> graph) {
    auto result = makeMap(makeList(), makeList();
    graph->forEach([=] (Unknown  vertex,Unknown  edges) {
        result[vertex] = <T>from(edges);
    });
    auto keys = graph->keys()->toList();
    for (auto vertex1 : keys) {
        for (auto vertex2 : keys) {
            for (auto vertex3 : keys) {
                if (result[vertex2]!->contains(vertex1) && result[vertex1]!->contains(vertex3)) {
                    result[vertex2]!->add(vertex3);
                }
            }
        }
    }
    return result;
}

template<typename T>
List<Set<T>> stronglyConnectedComponents(Map<T, Iterable<T>> graph) {
    auto index = 0;
    auto stack = makeList();
    auto result = makeList();
    auto indices = <T, int>make<HashMapCls>();
    auto lowLinks = <T, int>make<HashMapCls>();
    auto onStack = <T>make<HashSetCls>();
    InlineMethod;
    for (auto vertex : graph->keys()) {
        if (!indices->containsKey(vertex)) {
            strongConnect(vertex);
        }
    }
    return result->reversed->toList();
}
