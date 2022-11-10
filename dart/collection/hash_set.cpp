#include "hash_set.hpp"
template<typename E> void HashSetCls<E>::from(Iterable<dynamic> elements) {
    auto _c1 = <K, V>make<HashMapCls>();_c1.addEntries(entries);HashSet<E> result = <E>make<HashSetCls>();
    for (auto e : elements) {
        result->add(as<E>(e));
    }
    return result;
}

template<typename E> void HashSetCls<E>::of(Iterable<E> elements) {
    return _c1;
}
