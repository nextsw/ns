#include "linked_list.hpp"
template<typename E>
void LinkedListCls<E>::addFirst(E entry) {
    auto _c1 = <E>make<LinkedHashSetCls>();_c1.addAll(elements);_insertBefore(_first, entrytrue);
    _first = entry;
}

template<typename E>
void LinkedListCls<E>::add(E entry) {
    _insertBefore(_first, entryfalse);
}

template<typename E>
void LinkedListCls<E>::addAll(Iterable<E> entries) {
    entries->forEach(add);
}

template<typename E>
bool LinkedListCls<E>::remove(E entry) {
    if (entry->_list != this)     {
        return false;
    }
    _unlink(entry);
    return true;
}

template<typename E>
bool LinkedListCls<E>::contains(Object entry) {
    return is<LinkedListEntry>(entry) && identical(this, entry->list);
}

template<typename E>
Iterator<E> LinkedListCls<E>::iterator() {
    return <E>make<_LinkedListIteratorCls>(this);
}

template<typename E>
int LinkedListCls<E>::length() {
    return _length;
}

template<typename E>
void LinkedListCls<E>::clear() {
    _modificationCount++;
    if (isEmpty())     {
        return;
    }
    E next = _first!;
    do {
        E entry = next;
        next = entry->_next!;
        entry->_next = entry->_previous = entry->_list = nullptr;
    } while (!identical(next, _first));
    _first = nullptr;
    _length = 0;
}

template<typename E>
E LinkedListCls<E>::first() {
    if (isEmpty()) {
        ;
    }
    return _first!;
}

template<typename E>
E LinkedListCls<E>::last() {
    if (isEmpty()) {
        ;
    }
    return _first!->_previous!;
}

template<typename E>
E LinkedListCls<E>::single() {
    if (isEmpty()) {
        ;
    }
    if (_length > 1) {
        ;
    }
    return _first!;
}

template<typename E>
void LinkedListCls<E>::forEach(void action(E entry) ) {
    int modificationCount = _modificationCount;
    if (isEmpty())     {
        return;
    }
    E current = _first!;
    do {
        action(current);
        if (modificationCount != _modificationCount) {
            ;
        }
        current = current->_next!;
    } while (!identical(current, _first));
}

template<typename E>
bool LinkedListCls<E>::isEmpty() {
    return _length == 0;
}

template<typename E>
void LinkedListCls<E>::_insertBefore(E entry, E newEntry, bool updateFirst) {
    if (newEntry->list != nullptr) {
        ;
    }
    _modificationCount++;
    newEntry->_list = this;
    if (isEmpty()) {
        assert(entry == nullptr);
        newEntry->_previous = newEntry->_next = newEntry;
        _first = newEntry;
        _length++;
        return;
    }
    E predecessor = entry!->_previous!;
    E successor = entry;
    newEntry->_previous = predecessor;
    newEntry->_next = successor;
    predecessor->_next = newEntry;
    successor->_previous = newEntry;
    if (updateFirst && identical(entry, _first)) {
        _first = newEntry;
    }
    _length++;
}

template<typename E>
void LinkedListCls<E>::_unlink(E entry) {
    _modificationCount++;
    entry->_next!->_previous = entry->_previous;
    E next = entry->_previous!->_next = entry->_next;
    _length--;
    entry->_list = entry->_next = entry->_previous = nullptr;
    if (isEmpty()) {
        _first = nullptr;
    } else     {
        if (identical(entry, _first)) {
        _first = next;
    }
;
    }}

template<typename E>
E _LinkedListIteratorCls<E>::current() {
    return as<E>(_current);
}

template<typename E>
bool _LinkedListIteratorCls<E>::moveNext() {
    if (_modificationCount != _list->_modificationCount) {
        ;
    }
    if (_list->isEmpty() || (_visitedFirst && identical(_next, _list->first()))) {
        _current = nullptr;
        return false;
    }
    _visitedFirst = true;
    _current = _next;
    _next = _next!->_next;
    return true;
}

template<typename E>
_LinkedListIteratorCls<E>::_LinkedListIteratorCls(LinkedList<E> list) {
    {
        _list = list;
        _modificationCount = list->_modificationCount;
        _next = list->_first;
        _visitedFirst = false;
    }
}

template<typename E>
LinkedList<E> LinkedListEntryCls<E>::list() {
    return _list;
}

template<typename E>
void LinkedListEntryCls<E>::unlink() {
    _list!->_unlink(as<E>(this));
}

template<typename E>
E LinkedListEntryCls<E>::next() {
    if (_list == nullptr || identical(_list!->first(), _next))     {
        return nullptr;
    }
    return _next;
}

template<typename E>
E LinkedListEntryCls<E>::previous() {
    if (_list == nullptr || identical(this, _list!->first()))     {
        return nullptr;
    }
    return _previous;
}

template<typename E>
void LinkedListEntryCls<E>::insertAfter(E entry) {
    _list!->_insertBefore(_next, entryfalse);
}

template<typename E>
void LinkedListEntryCls<E>::insertBefore(E entry) {
    _list!->_insertBefore(as<E>(this), entrytrue);
}
