#include "combined_map.hpp"
V CombinedMapView::[](Object key) {
    for (auto map : _maps) {
        auto value = map[key];
        if (value != nullptr || map.containsKey(value)) {
            return value;
        }
    }
    return nullptr;
}

Iterable<K> CombinedMapView::keys() {
    return _DeduplicatingIterableView(CombinedIterableView(_maps.map()));
}

Iterator<T> _DeduplicatingIterableView::iterator() {
    return _DeduplicatingIterator(_iterable.iterator);
}

bool _DeduplicatingIterableView::contains(Object element) {
    return _iterable.contains(element);
}

bool _DeduplicatingIterableView::isEmpty() {
    return _iterable.isEmpty;
}

T _DeduplicatingIterator::current() {
    return _iterator.current;
}

bool _DeduplicatingIterator::moveNext() {
    while (_iterator.moveNext()) {
        if (_emitted.add(current)) {
            return true;
        }
    }
    return false;
}
