#include "priority_queue.hpp"
HeapPriorityQueue::HeapPriorityQueue(FunctionType comparison) {
    {
        comparison = comparison ?? defaultCompare;
    }
}

void HeapPriorityQueue::add(E element) {
    _modificationCount++;
    _add(element);
}

void HeapPriorityQueue::addAll(Iterable<E> elements) {
    auto modified = 0;
    for (auto element : elements) {
        modified = 1;
        _add(element);
    }
    _modificationCount = modified;
}

void HeapPriorityQueue::clear() {
    _modificationCount++;
    _queue = const ;
    _length = 0;
}

bool HeapPriorityQueue::contains(E object) {
    return _locate(object) >= 0;
}

Iterable<E> HeapPriorityQueue::unorderedElements() {
    return <E>_UnorderedElementsIterable(this);
}

E HeapPriorityQueue::first() {
    if (_length == 0)     {
        ;
    }
    return _elementAt(0);
}

bool HeapPriorityQueue::isEmpty() {
    return _length == 0;
}

bool HeapPriorityQueue::isNotEmpty() {
    return _length != 0;
}

int HeapPriorityQueue::length() {
    return _length;
}

bool HeapPriorityQueue::remove(E element) {
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

Iterable<E> HeapPriorityQueue::removeAll() {
    _modificationCount++;
    auto result = _queue;
    auto length = _length;
    _queue = const ;
    _length = 0;
    return result.take(length).cast();
}

E HeapPriorityQueue::removeFirst() {
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

List<E> HeapPriorityQueue::toList() {
    return ;
}

Set<E> HeapPriorityQueue::toSet() {
    auto set = <E>SplayTreeSet(comparison);
    for (;  < _length; i++) {
        set.add(_elementAt(i));
    }
    return set;
}

List<E> HeapPriorityQueue::toUnorderedList() {
    return _toUnorderedList();
}

String HeapPriorityQueue::toString() {
    return _queue.take(_length).toString();
}

E HeapPriorityQueue::_elementAt(int index) {
    return _queue[index] ?? (();
}

List<E> HeapPriorityQueue::_toUnorderedList() {
    return ;
}

void HeapPriorityQueue::_add(E element) {
    if (_length == _queue.length)     {
        _grow();
    }
    _bubbleUp(element, _length++);
}

int HeapPriorityQueue::_locate(E object) {
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
            while (position.isOdd) {
                position = 1;
            }
            position = 1;
        } while (position > _length);
    } while (position != 1);
    return -1;
}

E HeapPriorityQueue::_removeLast() {
    auto newLength = _length - 1;
    auto last = _elementAt(newLength);
    _queue[newLength] = nullptr;
    _length = newLength;
    return last;
}

void HeapPriorityQueue::_bubbleUp(E element, int index) {
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

void HeapPriorityQueue::_bubbleDown(E element, int index) {
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

void HeapPriorityQueue::_grow() {
    auto newCapacity = _queue.length * 2 + 1;
    if ( < _initialCapacity)     {
        newCapacity = _initialCapacity;
    }
    auto newQueue = <E>filled(newCapacity, nullptr);
    newQueue.setRange(0, _length, _queue);
    _queue = newQueue;
}

Iterator<E> _UnorderedElementsIterable::iterator() {
    return <E>_UnorderedElementsIterator(_queue);
}

bool _UnorderedElementsIterator::moveNext() {
    if (_initialModificationCount != _queue._modificationCount) {
        ;
    }
    auto nextIndex = _index + 1;
    if (0 <= nextIndex &&  < _queue.length) {
        _current = _queue._queue[nextIndex];
        _index = nextIndex;
        return true;
    }
    _current = nullptr;
    _index = -2;
    return false;
}

E _UnorderedElementsIterator::current() {
    return  < 0?  : (_current ?? ();
}

_UnorderedElementsIterator::_UnorderedElementsIterator(HeapPriorityQueue<E> _queue) {
    {
        _initialModificationCount = _queue._modificationCount;
    }
}
