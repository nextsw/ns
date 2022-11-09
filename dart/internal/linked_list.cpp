#include "linked_list.hpp"
template<typename T : LinkedListEntry<T>> T LinkedListCls<T>::first() {
    return ((T)_first);
}

template<typename T : LinkedListEntry<T>> T LinkedListCls<T>::last() {
    return ((T)_last);
}

template<typename T : LinkedListEntry<T>> bool LinkedListCls<T>::isEmpty() {
    return length == 0;
}

template<typename T : LinkedListEntry<T>> void LinkedListCls<T>::add(T newLast) {
    assert(newLast->_next == nullptr && newLast->_previous == nullptr);
    if (_last != nullptr) {
        assert(_last!->_next == nullptr);
        _last!->_next = newLast;
    } else {
        _first = newLast;
    }
    newLast->_previous = _last;
    _last = newLast;
    _last!->_list = this;
    length++;
}

template<typename T : LinkedListEntry<T>> void LinkedListCls<T>::addFirst(T newFirst) {
    if (_first != nullptr) {
        assert(_first!->_previous == nullptr);
        _first!->_previous = newFirst;
    } else {
        _last = newFirst;
    }
    newFirst->_next = _first;
    _first = newFirst;
    _first!->_list = this;
    length++;
}

template<typename T : LinkedListEntry<T>> void LinkedListCls<T>::remove(T node) {
    if (node->_list != this)     {
        return;
    }
    length--;
    if (node->_previous == nullptr) {
        assert(identical(node, _first));
        _first = node->_next;
    } else {
        node->_previous!->_next = node->_next;
    }
    if (node->_next == nullptr) {
        assert(identical(node, _last));
        _last = node->_previous;
    } else {
        node->_next!->_previous = node->_previous;
    }
    node->_next = node->_previous = nullptr;
    node->_list = nullptr;
}

template<typename T : LinkedListEntry<T>> Iterator<T> LinkedListCls<T>::iterator() {
    return <T>make<_LinkedListIteratorCls>(this);
}

template<typename T : LinkedListEntry<T>> void LinkedListEntryCls<T>::unlink() {
    _list?->remove(((T)this));
}

template<typename T : LinkedListEntry<T>> T _LinkedListIteratorCls<T>::current() {
    return ((T)_current);
}

template<typename T : LinkedListEntry<T>> bool _LinkedListIteratorCls<T>::moveNext() {
    if (_current == nullptr) {
        auto list = _list;
        if (list == nullptr)         {
            return false;
        }
        assert(list->length > 0);
        _current = list->first;
        _list = nullptr;
        return true;
    }
    _current = _current!->_next;
    return _current != nullptr;
}

template<typename T : LinkedListEntry<T>> _LinkedListIteratorCls<T>::_LinkedListIteratorCls(LinkedList<T> list) {
    {
        _list = list;
    }
    {
        if (list->length == 0)         {
            _list = nullptr;
        }
    }
}
