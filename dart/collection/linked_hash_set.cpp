#include "linked_hash_set.hpp"
template<typename E> void LinkedHashSetCls<E>::from(Iterable<dynamic> elements) {
    auto _c1 = <K, V>make<LinkedHashMapCls>();_c1.addEntries(entries);LinkedHashSet<E> result = <E>make<LinkedHashSetCls>();
    for (auto element : elements) {
        result->add(as<E>(element));
    }
    return result;
}

template<typename E> void LinkedHashSetCls<E>::of(Iterable<E> elements) {
    return _c1;
}
