#include "priority_queue.hpp"
template<typename E> HeapPriorityQueueCls<E>::HeapPriorityQueueCls(int comparison(E , E ) ) {
    {
        comparison = comparison or defaultCompare;
    }
}

template<typename E> void HeapPriorityQueueCls<E>::add(E element) {
    _modificationCount++;
    _add(element);
}

template<typename E> void HeapPriorityQueueCls<E>::addAll(Iterable<E> elements) {
    auto modified = 0;
    for (auto element : elements) {
        modified = 1;
        _add(element);
    }
    _modificationCount = modified;
}

template<typename E> void HeapPriorityQueueCls<E>::clear() {
    _modificationCount++;
    _queue = makeList();
    _length = 0;
}

template<typename E> bool HeapPriorityQueueCls<E>::contains(E object) {
    return _locate(object) >= 0;
}

template<typename E> Iterable<E> HeapPriorityQueueCls<E>::unorderedElements() {
    return <E>make<_UnorderedElementsIterableCls>(this);
}

template<typename E> E HeapPriorityQueueCls<E>::first() {
    if (_length == 0)     {
        ;
    }
    return _elementAt(0);
}

template<typename E> bool HeapPriorityQueueCls<E>::isEmpty() {
    return _length == 0;
}

template<typename E> bool HeapPriorityQueueCls<E>::isNotEmpty() {
    return _length != 0;
}

template<typename E> int HeapPriorityQueueCls<E>::length() {
    return _length;
}

template<typename E> bool HeapPriorityQueueCls<E>::remove(E element) {
    auto index = _locate(element);
    if ( < 0)     {
        return false;
    }
    _modificationCount++;
    auto last = _removeLast();
    if ( < _length) {
        auto comp = comparison(last, element);
        if (comp <= 0) {
            _bubbleUp(last, index);
        } else {
            _bubbleDown(last, index);
        }
    }
    return true;
}

template<typename E> Iterable<E> HeapPriorityQueueCls<E>::removeAll() {
    _modificationCount++;
    auto result = _queue;
    auto length = _length;
    _queue = makeList();
    _length = 0;
    return result->take(length)->cast();
}

template<typename E> E HeapPriorityQueueCls<E>::removeFirst() {
    if (_length == 0)     {
        ;
    }
    _modificationCount++;
    auto result = _elementAt(0);
    auto last = _removeLast();
    if (_length > 0) {
        _bubbleDown(last, 0);
    }
    return result;
}

template<typename E> List<E> HeapPriorityQueueCls<E>::toList() {
    return _c1;
}

template<typename E> Set<E> HeapPriorityQueueCls<E>::toSet() {
    auto _c1 = _toUnorderedList();_c1.sort(comparison);auto set = <E>make<SplayTreeSetCls>(comparison);
    for (;  < _length; i++) {
        set->add(_elementAt(i));
    }
    return set;
}

template<typename E> List<E> HeapPriorityQueueCls<E>::toUnorderedList() {
    return _toUnorderedList();
}

template<typename E> String HeapPriorityQueueCls<E>::toString() {
    return _queue->take(_length)->toString();
}

template<typename E> E HeapPriorityQueueCls<E>::_elementAt(int index) {
    return _queue[index] or (as<E>(nullptr));
}

template<typename E> List<E> HeapPriorityQueueCls<E>::_toUnorderedList() {
    return list1;
}

template<typename E> void HeapPriorityQueueCls<E>::_add(E element) {
    for (;  < _length; i++)     {        ;    }{    list1.add(ArrayItem);}if (_length == _queue->length())     {
        _grow();
    }
    _bubbleUp(element, _length++);
}

template<typename E> int HeapPriorityQueueCls<E>::_locate(E object) {
    if (_length == 0)     {
        return -1;
    }
    auto position = 1;
    do {
        auto index = position - 1;
        auto element = _elementAt(index);
        auto comp = comparison(element, object);
        if (comp <= 0) {
            if (comp == 0 && element == object)             {
                return index;
            }
            auto leftChildPosition = position * 2;
            if (leftChildPosition <= _length) {
                position = leftChildPosition;
                continue;
            }
        }
        do {
            while (position->isOdd()) {
                position = 1;
            }
            position = 1;
        } while (position > _length);
    } while (position != 1);
    return -1;
}

template<typename E> E HeapPriorityQueueCls<E>::_removeLast() {
    auto newLength = _length - 1;
    auto last = _elementAt(newLength);
    _queue[newLength] = nullptr;
    _length = newLength;
    return last;
}

template<typename E> void HeapPriorityQueueCls<E>::_bubbleUp(E element, int index) {
    while (index > 0) {
        auto parentIndex = (index - 1) ~/ 2;
        auto parent = _elementAt(parentIndex);
        if (comparison(element, parent) > 0)         {
                    break;
        }
        _queue[index] = parent;
        index = parentIndex;
    }
    _queue[index] = element;
}

template<typename E> void HeapPriorityQueueCls<E>::_bubbleDown(E element, int index) {
    auto rightChildIndex = index * 2 + 2;
    while ( < _length) {
        auto leftChildIndex = rightChildIndex - 1;
        auto leftChild = _elementAt(leftChildIndex);
        auto rightChild = _elementAt(rightChildIndex);
        auto comp = comparison(leftChild, rightChild);
        int minChildIndex;
        E minChild;
        if ( < 0) {
            minChild = leftChild;
            minChildIndex = leftChildIndex;
        } else {
            minChild = rightChild;
            minChildIndex = rightChildIndex;
        }
        comp = comparison(element, minChild);
        if (comp <= 0) {
            _queue[index] = element;
            return;
        }
        _queue[index] = minChild;
        index = minChildIndex;
        rightChildIndex = index * 2 + 2;
    }
    auto leftChildIndex = rightChildIndex - 1;
    if ( < _length) {
        auto child = _elementAt(leftChildIndex);
        auto comp = comparison(element, child);
        if (comp > 0) {
            _queue[index] = child;
            index = leftChildIndex;
        }
    }
    _queue[index] = element;
}

template<typename E> void HeapPriorityQueueCls<E>::_grow() {
    auto newCapacity = _queue->length() * 2 + 1;
    if ( < _initialCapacity)     {
        newCapacity = _initialCapacity;
    }
    auto newQueue = <E>filled(newCapacity, nullptr);
    newQueue->setRange(0, _length, _queue);
    _queue = newQueue;
}

template<typename E> Iterator<E> _UnorderedElementsIterableCls<E>::iterator() {
    return <E>make<_UnorderedElementsIteratorCls>(_queue);
}

template<typename E> bool _UnorderedElementsIteratorCls<E>::moveNext() {
    if (_initialModificationCount != _queue->_modificationCount) {
        ;
    }
    auto nextIndex = _index + 1;
    if (0 <= nextIndex &&  < _queue->length()) {
        _current = _queue->_queue[nextIndex];
        _index = nextIndex;
        return true;
    }
    _current = nullptr;
    _index = -2;
    return false;
}

template<typename E> E _UnorderedElementsIteratorCls<E>::current() {
    return  < 0?  : (_current or as<E>(nullptr));
}

template<typename E> _UnorderedElementsIteratorCls<E>::_UnorderedElementsIteratorCls(HeapPriorityQueue<E> _queue) {
    {
        _initialModificationCount = _queue->_modificationCount;
    }
}
