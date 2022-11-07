#include "observer_list.hpp"
void ObserverList::add(T item) {
    _isDirty = true;
    _list.add(item);
}

bool ObserverList::remove(T item) {
    _isDirty = true;
    _set.clear();
    return _list.remove(item);
}

void ObserverList::clear() {
    _isDirty = false;
    _list.clear();
    _set.clear();
}

bool ObserverList::contains(Object element) {
    if (_list.length < 3) {
        return _list.contains(element);
    }
    if (_isDirty) {
        _set.addAll(_list);
        _isDirty = false;
    }
    return _set.contains(element);
}

Iterator<T> ObserverList::iterator() {
    return _list.iterator;
}

bool ObserverList::isEmpty() {
    return _list.isEmpty;
}

bool ObserverList::isNotEmpty() {
    return _list.isNotEmpty;
}

List<T> ObserverList::toList(bool growable) {
    return _list.toList(growable);
}

void HashedObserverList::add(T item) {
    _map[item] = (_map[item] ?? 0) + 1;
}

bool HashedObserverList::remove(T item) {
    int value = _map[item];
    if (value == nullptr) {
        return false;
    }
    if (value == 1) {
        _map.remove(item);
    } else {
        _map[item] = value - 1;
    }
    return true;
}

bool HashedObserverList::contains(Object element) {
    return _map.containsKey(element);
}

Iterator<T> HashedObserverList::iterator() {
    return _map.keys.iterator;
}

bool HashedObserverList::isEmpty() {
    return _map.isEmpty;
}

bool HashedObserverList::isNotEmpty() {
    return _map.isNotEmpty;
}
