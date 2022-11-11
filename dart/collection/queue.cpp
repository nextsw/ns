#include "queue.hpp"
template<typename E>
template<typename S, typename T>
Queue<T> QueueCls<E>::castFrom(Queue<S> source) {
    return <S, T>make<CastQueueCls>(source);
}

template<typename E>
void _DoubleLinkedQueueEntryCls<E>::_link(_DoubleLinkedQueueEntry<E> previous, _DoubleLinkedQueueEntry<E> next) {
    _nextLink = next;
    _previousLink = previous;
    previous?->_nextLink = this;
    next?->_previousLink = this;
}

template<typename E>
void _DoubleLinkedQueueEntryCls<E>::_unlink() {
    _previousLink?->_nextLink = _nextLink;
    _nextLink?->_previousLink = _previousLink;
    _previousLink = _nextLink = nullptr;
}

template<typename E>
void _DoubleLinkedQueueEntryCls<E>::_append(E element, DoubleLinkedQueue<E> queue) {
    <E>make<_DoubleLinkedQueueElementCls>(element, queue)->_link(this, _nextLink);
}

template<typename E>
void _DoubleLinkedQueueEntryCls<E>::_prepend(E element, DoubleLinkedQueue<E> queue) {
    <E>make<_DoubleLinkedQueueElementCls>(element, queue)->_link(_previousLink, this);
}

template<typename E>
void _DoubleLinkedQueueElementCls<E>::append(E e) {
    _append(e, _queue);
    _queue?->_elementCount++;
}

template<typename E>
void _DoubleLinkedQueueElementCls<E>::prepend(E e) {
    _prepend(e, _queue);
    _queue?->_elementCount++;
}

template<typename E>
E _DoubleLinkedQueueElementCls<E>::remove() {
    _queue?->_elementCount--;
    return _remove();
}

template<typename E>
DoubleLinkedQueueEntry<E> _DoubleLinkedQueueElementCls<E>::previousEntry() {
    return _previousLink?->_asNonSentinelEntry();
}

template<typename E>
DoubleLinkedQueueEntry<E> _DoubleLinkedQueueElementCls<E>::nextEntry() {
    return _nextLink?->_asNonSentinelEntry();
}

template<typename E>
E _DoubleLinkedQueueElementCls<E>::_remove() {
    _queue = nullptr;
    _unlink();
    return element;
}

template<typename E>
_DoubleLinkedQueueElement<E> _DoubleLinkedQueueElementCls<E>::_asNonSentinelEntry() {
    return this;
}

template<typename E>
E _DoubleLinkedQueueSentinelCls<E>::element() {
    throw IterableElementErrorCls->noElement();
}

template<typename E>
_DoubleLinkedQueueSentinelCls<E>::_DoubleLinkedQueueSentinelCls() {
    {
        _previousLink = this;
        _nextLink = this;
    }
}

template<typename E>
Null _DoubleLinkedQueueSentinelCls<E>::_asNonSentinelEntry() {
    return nullptr;
}

template<typename E>
E _DoubleLinkedQueueSentinelCls<E>::_remove() {
    throw IterableElementErrorCls->noElement();
}

template<typename E>
void DoubleLinkedQueueCls<E>::from(Iterable<dynamic> elements) {
    DoubleLinkedQueue<E> list = <E>make<DoubleLinkedQueueCls>();
    for (auto e : elements) {
        list->addLast(as<E>(e));
    }
    return list;
}

template<typename E>
void DoubleLinkedQueueCls<E>::of(Iterable<E> elements) {
    return _c1;
}

template<typename E>
template<typename R>
Queue<R> DoubleLinkedQueueCls<E>::cast() {
    return QueueCls-><E, R>castFrom(this);
}

template<typename E>
int DoubleLinkedQueueCls<E>::length() {
    return _elementCount;
}

template<typename E>
void DoubleLinkedQueueCls<E>::addLast(E value) {
    auto _c1 = <E>make<DoubleLinkedQueueCls>();_c1.addAll(elements);_sentinel->_prepend(value, this);
    _elementCount++;
}

template<typename E>
void DoubleLinkedQueueCls<E>::addFirst(E value) {
    _sentinel->_append(value, this);
    _elementCount++;
}

template<typename E>
void DoubleLinkedQueueCls<E>::add(E value) {
    _sentinel->_prepend(value, this);
    _elementCount++;
}

template<typename E>
void DoubleLinkedQueueCls<E>::addAll(Iterable<E> iterable) {
    for (E value : iterable) {
        _sentinel->_prepend(value, this);
        _elementCount++;
    }
}

template<typename E>
E DoubleLinkedQueueCls<E>::removeLast() {
    E result = _sentinel->_previousLink!->_remove();
    _elementCount--;
    return result;
}

template<typename E>
E DoubleLinkedQueueCls<E>::removeFirst() {
    E result = _sentinel->_nextLink!->_remove();
    _elementCount--;
    return result;
}

template<typename E>
bool DoubleLinkedQueueCls<E>::remove(Object o) {
    _DoubleLinkedQueueEntry<E> entry = _sentinel->_nextLink!;
    while (true) {
        auto elementEntry = entry->_asNonSentinelEntry();
        if (elementEntry == nullptr) {
            return false;
        }
        bool equals = (elementEntry->element == o);
        if (!identical(this, elementEntry->_queue)) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
        if (equals) {
            entry->_remove();
            _elementCount--;
            return true;
        }
        entry = entry->_nextLink!;
    }
}

template<typename E>
void DoubleLinkedQueueCls<E>::removeWhere(std::function<bool(E element)> test) {
    _filter(test, true);
}

template<typename E>
void DoubleLinkedQueueCls<E>::retainWhere(std::function<bool(E element)> test) {
    _filter(test, false);
}

template<typename E>
E DoubleLinkedQueueCls<E>::first() {
    return _sentinel->_nextLink!->element();
}

template<typename E>
E DoubleLinkedQueueCls<E>::last() {
    return _sentinel->_previousLink!->element();
}

template<typename E>
E DoubleLinkedQueueCls<E>::single() {
    if (identical(_sentinel->_nextLink, _sentinel->_previousLink)) {
        return _sentinel->_nextLink!->element();
    }
    throw IterableElementErrorCls->tooMany();
}

template<typename E>
DoubleLinkedQueueEntry<E> DoubleLinkedQueueCls<E>::firstEntry() {
    return _sentinel->_nextLink!->_asNonSentinelEntry();
}

template<typename E>
DoubleLinkedQueueEntry<E> DoubleLinkedQueueCls<E>::lastEntry() {
    return _sentinel->_previousLink!->_asNonSentinelEntry();
}

template<typename E>
bool DoubleLinkedQueueCls<E>::isEmpty() {
    return identical(_sentinel->_nextLink, _sentinel);
}

template<typename E>
void DoubleLinkedQueueCls<E>::clear() {
    auto cursor = _sentinel->_nextLink!;
    while (true) {
        auto entry = cursor->_asNonSentinelEntry();
        if (entry == nullptr) {
            break;
        }
        cursor = cursor->_nextLink!;
            auto _c1 = entry;    _c1._nextLink = auto _c2 = nullptr;    _c2._previousLink = auto _c3 = nullptr;    _c3._queue = nullptr;    _c3;    _c2;_c1;
    }
    _sentinel->_nextLink = _sentinel;
    _sentinel->_previousLink = _sentinel;
    _elementCount = 0;
}

template<typename E>
void DoubleLinkedQueueCls<E>::forEachEntry(std::function<void(DoubleLinkedQueueEntry<E> element)> action) {
    auto cursor = _sentinel->_nextLink!;
    while (true) {
        auto element = cursor->_asNonSentinelEntry();
        if (element == nullptr) {
            break;
        }
        if (!identical(element->_queue, this)) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
        cursor = cursor->_nextLink!;
        action(element);
        if (identical(this, element->_queue)) {
            cursor = element->_nextLink!;
        }
    }
}

template<typename E>
_DoubleLinkedQueueIterator<E> DoubleLinkedQueueCls<E>::iterator() {
    return <E>make<_DoubleLinkedQueueIteratorCls>(this);
}

template<typename E>
String DoubleLinkedQueueCls<E>::toString() {
    return IterableBaseCls->iterableToFullString(this, __s("{"), __s("}"));
}

template<typename E>
void DoubleLinkedQueueCls<E>::_filter(std::function<bool(E element)> test, bool removeMatching) {
    _DoubleLinkedQueueEntry<E> entry = _sentinel->_nextLink!;
    while (true) {
        auto elementEntry = entry->_asNonSentinelEntry();
        if (elementEntry == nullptr) {
            return;
        }
        bool matches = test(elementEntry->element);
        if (!identical(this, elementEntry->_queue)) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
        auto next = entry->_nextLink!;
        if (identical(removeMatching, matches)) {
            elementEntry->_remove();
            _elementCount--;
        }
        entry = next;
    }
}

template<typename E>
bool _DoubleLinkedQueueIteratorCls<E>::moveNext() {
    auto nextElement = _nextEntry?->_asNonSentinelEntry();
    if (nextElement == nullptr) {
        _current = nullptr;
        _nextEntry = nullptr;
        _queue = nullptr;
        return false;
    }
    if (!identical(_queue, nextElement->_queue)) {
        throw make<ConcurrentModificationErrorCls>(_queue);
    }
    _current = nextElement->element;
    _nextEntry = nextElement->_nextLink;
    return true;
}

template<typename E>
E _DoubleLinkedQueueIteratorCls<E>::current() {
    return as<E>(_current);
}

template<typename E>
_DoubleLinkedQueueIteratorCls<E>::_DoubleLinkedQueueIteratorCls(DoubleLinkedQueue<E> _queue) {
    {
        _nextEntry = _queue->_sentinel->_nextLink;
    }
}

template<typename E>
ListQueueCls<E>::ListQueueCls(int initialCapacity) {
    {
        _head = 0;
        _tail = 0;
        _table = <E>filled(_calculateCapacity(initialCapacity), nullptr);
    }
}

template<typename E>
void ListQueueCls<E>::from(Iterable<dynamic> elements) {
    if (is<List<dynamic>>(elements)) {
        int length = as<ListCls>(elements)->length();
        ListQueue<E> queue = <E>make<ListQueueCls>(length + 1);
        assert(queue->_table->length > length);
        for (;  < length; i++) {
            queue->_table[i] = as<E>(elements[i]);
        }
        queue->_tail = length;
        return queue;
    } else {
        int capacity = _INITIAL_CAPACITY;
        if (is<EfficientLengthIterable>(elements)) {
            capacity = as<EfficientLengthIterableCls>(elements)->length();
        }
        ListQueue<E> result = <E>make<ListQueueCls>(capacity);
        for (auto element : elements) {
            result->addLast(as<E>(element));
        }
        return result;
    }
}

template<typename E>
void ListQueueCls<E>::of(Iterable<E> elements) {
    return _c1;
}

template<typename E>
template<typename R>
Queue<R> ListQueueCls<E>::cast() {
    return QueueCls-><E, R>castFrom(this);
}

template<typename E>
Iterator<E> ListQueueCls<E>::iterator() {
    return <E>make<_ListQueueIteratorCls>(this);
}

template<typename E>
void ListQueueCls<E>::forEach(std::function<void(E element)> f) {
    auto _c1 = <E>make<ListQueueCls>();_c1.addAll(elements);int modificationCount = _modificationCount;
    for (; i != _tail; i = (i + 1) & (_table->length() - 1)) {
        f(as<E>(_table[i]));
        _checkModification(modificationCount);
    }
}

template<typename E>
bool ListQueueCls<E>::isEmpty() {
    return _head == _tail;
}

template<typename E>
int ListQueueCls<E>::length() {
    return (_tail - _head) & (_table->length() - 1);
}

template<typename E>
E ListQueueCls<E>::first() {
    if (_head == _tail) {
        throw IterableElementErrorCls->noElement();
    }
    return as<E>(_table[_head]);
}

template<typename E>
E ListQueueCls<E>::last() {
    if (_head == _tail) {
        throw IterableElementErrorCls->noElement();
    }
    return as<E>(_table[(_tail - 1) & (_table->length() - 1)]);
}

template<typename E>
E ListQueueCls<E>::single() {
    if (_head == _tail) {
        throw IterableElementErrorCls->noElement();
    }
    if (length() > 1) {
        throw IterableElementErrorCls->tooMany();
    }
    return as<E>(_table[_head]);
}

template<typename E>
E ListQueueCls<E>::elementAt(int index) {
    RangeErrorCls->checkValidIndex(index, this);
    return as<E>(_table[(_head + index) & (_table->length() - 1)]);
}

template<typename E>
List<E> ListQueueCls<E>::toList(bool growable) {
    int mask = _table->length() - 1;
    int length = (_tail - _head) & mask;
    if (length == 0) {
        return <E>empty(growable);
    }
    auto list = <E>filled(length, first(), growable);
    for (;  < length; i++) {
        list[i] = as<E>(_table[(_head + i) & mask]);
    }
    return list;
}

template<typename E>
void ListQueueCls<E>::add(E value) {
    _add(value);
}

template<typename E>
void ListQueueCls<E>::addAll(Iterable<E> elements) {
    if (is<List<E>>(elements)) {
        List<E> list = as<ListCls>(elements);
        int addCount = list->length();
        int length = this->length();
        if (length + addCount >= _table->length) {
            _preGrow(length + addCount);
            _table->setRange(length, length + addCount, list, 0);
            _tail += addCount;
        } else {
            int endSpace = _table->length - _tail;
            if ( < endSpace) {
                _table->setRange(_tail, _tail + addCount, list, 0);
                _tail += addCount;
            } else {
                int preSpace = addCount - endSpace;
                _table->setRange(_tail, _tail + endSpace, list, 0);
                _table->setRange(0, preSpace, list, endSpace);
                _tail = preSpace;
            }
        }
        _modificationCount++;
    } else {
        for (E element : elements) {
            _add(element);
        }
    }
}

template<typename E>
bool ListQueueCls<E>::remove(Object value) {
    for (; i != _tail; i = (i + 1) & (_table->length() - 1)) {
        E element = _table[i];
        if (element == value) {
            _remove(i);
            _modificationCount++;
            return true;
        }
    }
    return false;
}

template<typename E>
void ListQueueCls<E>::removeWhere(std::function<bool(E element)> test) {
    _filterWhere(test, true);
}

template<typename E>
void ListQueueCls<E>::retainWhere(std::function<bool(E element)> test) {
    _filterWhere(test, false);
}

template<typename E>
void ListQueueCls<E>::clear() {
    if (_head != _tail) {
        for (; i != _tail; i = (i + 1) & (_table->length() - 1)) {
            _table[i] = nullptr;
        }
        _head = _tail = 0;
        _modificationCount++;
    }
}

template<typename E>
String ListQueueCls<E>::toString() {
    return IterableBaseCls->iterableToFullString(this, __s("{"), __s("}"));
}

template<typename E>
void ListQueueCls<E>::addLast(E value) {
    _add(value);
}

template<typename E>
void ListQueueCls<E>::addFirst(E value) {
    _head = (_head - 1) & (_table->length() - 1);
    _table[_head] = value;
    if (_head == _tail) {
        _grow();
    }
    _modificationCount++;
}

template<typename E>
E ListQueueCls<E>::removeFirst() {
    if (_head == _tail) {
        throw IterableElementErrorCls->noElement();
    }
    _modificationCount++;
    E result = as<E>(_table[_head]);
    _table[_head] = nullptr;
    _head = (_head + 1) & (_table->length() - 1);
    return result;
}

template<typename E>
E ListQueueCls<E>::removeLast() {
    if (_head == _tail) {
        throw IterableElementErrorCls->noElement();
    }
    _modificationCount++;
    _tail = (_tail - 1) & (_table->length() - 1);
    E result = as<E>(_table[_tail]);
    _table[_tail] = nullptr;
    return result;
}

template<typename E>
int ListQueueCls<E>::_calculateCapacity(int initialCapacity) {
    if (initialCapacity == nullptr ||  < _INITIAL_CAPACITY) {
        return _INITIAL_CAPACITY;
    } else {
        if (!_isPowerOf2(initialCapacity)) {
        return _nextPowerOf2(initialCapacity);
    }
;
    }    assert(_isPowerOf2(initialCapacity));
    return initialCapacity;
}

template<typename E>
void ListQueueCls<E>::_filterWhere(std::function<bool(E element)> test, bool removeMatching) {
    int modificationCount = _modificationCount;
    int i = _head;
    while (i != _tail) {
        E element = as<E>(_table[i]);
        bool remove = identical(removeMatching, test(element));
        _checkModification(modificationCount);
        if (remove) {
            i = _remove(i);
            modificationCount = ++_modificationCount;
        } else {
            i = (i + 1) & (_table->length() - 1);
        }
    }
}

template<typename E>
bool ListQueueCls<E>::_isPowerOf2(int number) {
    return (number & (number - 1)) == 0;
}

template<typename E>
int ListQueueCls<E>::_nextPowerOf2(int number) {
    assert(number > 0);
    number = (number << 1) - 1;
    for (; ; ) {
        int nextNumber = number & (number - 1);
        if (nextNumber == 0) {
            return number;
        }
        number = nextNumber;
    }
}

template<typename E>
void ListQueueCls<E>::_checkModification(int expectedModificationCount) {
    if (expectedModificationCount != _modificationCount) {
        throw make<ConcurrentModificationErrorCls>(this);
    }
}

template<typename E>
void ListQueueCls<E>::_add(E element) {
    _table[_tail] = element;
    _tail = (_tail + 1) & (_table->length() - 1);
    if (_head == _tail) {
        _grow();
    }
    _modificationCount++;
}

template<typename E>
int ListQueueCls<E>::_remove(int offset) {
    int mask = _table->length() - 1;
    int startDistance = (offset - _head) & mask;
    int endDistance = (_tail - offset) & mask;
    if ( < endDistance) {
        int i = offset;
        while (i != _head) {
            int prevOffset = (i - 1) & mask;
            _table[i] = _table[prevOffset];
            i = prevOffset;
        }
        _table[_head] = nullptr;
        _head = (_head + 1) & mask;
        return (offset + 1) & mask;
    } else {
        _tail = (_tail - 1) & mask;
        int i = offset;
        while (i != _tail) {
            int nextOffset = (i + 1) & mask;
            _table[i] = _table[nextOffset];
            i = nextOffset;
        }
        _table[_tail] = nullptr;
        return offset;
    }
}

template<typename E>
void ListQueueCls<E>::_grow() {
    List<E> newTable = <E>filled(_table->length() * 2, nullptr);
    int split = _table->length() - _head;
    newTable->setRange(0, split, _table, _head);
    newTable->setRange(split, split + _head, _table, 0);
    _head = 0;
    _tail = _table->length();
    _table = newTable;
}

template<typename E>
int ListQueueCls<E>::_writeToList(List<E> target) {
    assert(target->length() >= length());
    if (_head <= _tail) {
        int length = _tail - _head;
        target->setRange(0, length, _table, _head);
        return length;
    } else {
        int firstPartSize = _table->length() - _head;
        target->setRange(0, firstPartSize, _table, _head);
        target->setRange(firstPartSize, firstPartSize + _tail, _table, 0);
        return _tail + firstPartSize;
    }
}

template<typename E>
void ListQueueCls<E>::_preGrow(int newElementCount) {
    assert(newElementCount >= length());
    newElementCount += newElementCount >> 1;
    int newCapacity = _nextPowerOf2(newElementCount);
    List<E> newTable = <E>filled(newCapacity, nullptr);
    _tail = _writeToList(newTable);
    _table = newTable;
    _head = 0;
}

template<typename E>
E _ListQueueIteratorCls<E>::current() {
    return as<E>(_current);
}

template<typename E>
bool _ListQueueIteratorCls<E>::moveNext() {
    _queue->_checkModification(_modificationCount);
    if (_position == _end) {
        _current = nullptr;
        return false;
    }
    _current = _queue->_table[_position];
    _position = (_position + 1) & (_queue->_table->length() - 1);
    return true;
}

template<typename E>
_ListQueueIteratorCls<E>::_ListQueueIteratorCls(ListQueue<E> queue) {
    {
        _queue = queue;
        _end = queue->_tail;
        _modificationCount = queue->_modificationCount;
        _position = queue->_head;
    }
}
