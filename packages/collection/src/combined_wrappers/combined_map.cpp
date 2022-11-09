#include "combined_map.hpp"
template<typename K, typename V> V CombinedMapViewCls<K, V>::[](Object key) {
    for (auto map : _maps) {
        auto value = map[key];
        if (value != nullptr || map->containsKey(value)) {
            return value;
        }
    }
    return nullptr;
}

template<typename K, typename V> Iterable<K> CombinedMapViewCls<K, V>::keys() {
    return make<_DeduplicatingIterableViewCls>(make<CombinedIterableViewCls>(_maps->map([=] (Unknown  m)     {
        m->keys;
    })));
}

template<typename T> Iterator<T> _DeduplicatingIterableViewCls<T>::iterator() {
    return make<_DeduplicatingIteratorCls>(_iterable->iterator);
}

template<typename T> bool _DeduplicatingIterableViewCls<T>::contains(Object element) {
    return _iterable->contains(element);
}

template<typename T> bool _DeduplicatingIterableViewCls<T>::isEmpty() {
    return _iterable->isEmpty;
}

template<typename T> T _DeduplicatingIteratorCls<T>::current() {
    return _iterator->current;
}

template<typename T> bool _DeduplicatingIteratorCls<T>::moveNext() {
    while (_iterator->moveNext()) {
        if (_emitted->add(current)) {
            return true;
        }
    }
    return false;
}
