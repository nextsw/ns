#include "linked_list.hpp"
void LinkedList::addFirst(E entry) {
    _insertBefore(_first, entrytrue);
    _first = entry;
}

void LinkedList::add(E entry) {
    _insertBefore(_first, entryfalse);
}

void LinkedList::addAll(Iterable<E> entries) {
    entries.forEach(add);
}

bool LinkedList::remove(E entry) {
    if (entry._list != this)     {
        return false;
    }
    _unlink(entry);
    return true;
}

bool LinkedList::contains(Object entry) {
    return entry is LinkedListEntry && identical(this, entry.list);
}

Iterator<E> LinkedList::iterator() {
    return <E>_LinkedListIterator(this);
}

int LinkedList::length() {
    return _length;
}

void LinkedList::clear() {
    _modificationCount++;
    if (isEmpty)     {
        return;
    }
    E next = _first!;
    do {
        E entry = next;
        next = entry._next!;
        entry._next = entry._previous = entry._list = nullptr;
    } while (!identical(next, _first));
    _first = nullptr;
    _length = 0;
}

E LinkedList::first() {
    if (isEmpty) {
        ;
    }
    return _first!;
}

E LinkedList::last() {
    if (isEmpty) {
        ;
    }
    return _first!._previous!;
}

E LinkedList::single() {
    if (isEmpty) {
        ;
    }
    if (_length > 1) {
        ;
    }
    return _first!;
}

void LinkedList::forEach(FunctionType action) {
    int modificationCount = _modificationCount;
    if (isEmpty)     {
        return;
    }
    E current = _first!;
    do {
        action(current);
        if (modificationCount != _modificationCount) {
            ;
        }
        current = current._next!;
    } while (!identical(current, _first));
}

bool LinkedList::isEmpty() {
    return _length == 0;
}

void LinkedList::_insertBefore(E entry, E newEntry, bool updateFirst) {
    if (newEntry.list != nullptr) {
        ;
    }
    _modificationCount++;
    newEntry._list = this;
    if (isEmpty) {
        assert(entry == nullptr);
        newEntry._previous = newEntry._next = newEntry;
        _first = newEntry;
        _length++;
        return;
    }
    E predecessor = entry!._previous!;
    E successor = entry;
    newEntry._previous = predecessor;
    newEntry._next = successor;
    predecessor._next = newEntry;
    successor._previous = newEntry;
    if (updateFirst && identical(entry, _first)) {
        _first = newEntry;
    }
    _length++;
}

void LinkedList::_unlink(E entry) {
    _modificationCount++;
    entry._next!._previous = entry._previous;
    E next = entry._previous!._next = entry._next;
    _length--;
    entry._list = entry._next = entry._previous = nullptr;
    if (isEmpty) {
        _first = nullptr;
    } else     {
        if (identical(entry, _first)) {
        _first = next;
    }
;
    }}

E _LinkedListIterator::current() {
    return (;
}

bool _LinkedListIterator::moveNext() {
    if (_modificationCount != _list._modificationCount) {
        ;
    }
    if (_list.isEmpty || (_visitedFirst && identical(_next, _list.first))) {
        _current = nullptr;
        return false;
    }
    _visitedFirst = true;
    _current = _next;
    _next = _next!._next;
    return true;
}

_LinkedListIterator::_LinkedListIterator(LinkedList<E> list) {
    {
        _list = list;
        _modificationCount = list._modificationCount;
        _next = list._first;
        _visitedFirst = false;
    }
}

LinkedList<E> LinkedListEntry::list() {
    return _list;
}

void LinkedListEntry::unlink() {
    _list!._unlink(();
}

E LinkedListEntry::next() {
    if (_list == nullptr || identical(_list!.first, _next))     {
        return nullptr;
    }
    return _next;
}

E LinkedListEntry::previous() {
    if (_list == nullptr || identical(this, _list!.first))     {
        return nullptr;
    }
    return _previous;
}

void LinkedListEntry::insertAfter(E entry) {
    _list!._insertBefore(_next, entryfalse);
}

void LinkedListEntry::insertBefore(E entry) {
    _list!._insertBefore((, entrytrue);
}
