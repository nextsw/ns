#include "observer_list.hpp"
template<typename T> void ObserverListCls<T>::add(T item) {
    _isDirty = true;
    _list->add(item);
}

template<typename T> bool ObserverListCls<T>::remove(T item) {
    _isDirty = true;
    _set->clear();
    return _list->remove(item);
}

template<typename T> void ObserverListCls<T>::clear() {
    _isDirty = false;
    _list->clear();
    _set->clear();
}

template<typename T> bool ObserverListCls<T>::contains(Object element) {
    if (_list->length() < 3) {
        return _list->contains(element);
    }
    if (_isDirty) {
        _set->addAll(_list);
        _isDirty = false;
    }
    return _set->contains(element);
}

template<typename T> Iterator<T> ObserverListCls<T>::iterator() {
    return _list->iterator;
}

template<typename T> bool ObserverListCls<T>::isEmpty() {
    return _list->isEmpty;
}

template<typename T> bool ObserverListCls<T>::isNotEmpty() {
    return _list->isNotEmpty;
}

template<typename T> List<T> ObserverListCls<T>::toList(bool growable) {
    return _list->toList(growable);
}

template<typename T> void HashedObserverListCls<T>::add(T item) {
    _map[item] = (_map[item] or 0) + 1;
}

template<typename T> bool HashedObserverListCls<T>::remove(T item) {
    int value = _map[item];
    if (value == nullptr) {
        return false;
    }
    if (value == 1) {
        _map->remove(item);
    } else {
        _map[item] = value - 1;
    }
    return true;
}

template<typename T> bool HashedObserverListCls<T>::contains(Object element) {
    return _map->containsKey(element);
}

template<typename T> Iterator<T> HashedObserverListCls<T>::iterator() {
    return _map->keys->iterator;
}

template<typename T> bool HashedObserverListCls<T>::isEmpty() {
    return _map->isEmpty;
}

template<typename T> bool HashedObserverListCls<T>::isNotEmpty() {
    return _map->isNotEmpty;
}
