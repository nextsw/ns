#include "queue.hpp"
Queue<T> Queue::castFrom<S, T>(Queue<S> source) {
    return <S, T>CastQueue(source);
}

void _DoubleLinkedQueueEntry::_link(_DoubleLinkedQueueEntry<E> next, _DoubleLinkedQueueEntry<E> previous) {
    _nextLink = next;
    _previousLink = previous;
    previous?._nextLink = this;
    next?._previousLink = this;
}

void _DoubleLinkedQueueEntry::_unlink() {
    _previousLink?._nextLink = _nextLink;
    _nextLink?._previousLink = _previousLink;
    _previousLink = _nextLink = nullptr;
}

void _DoubleLinkedQueueEntry::_append(E element, DoubleLinkedQueue<E> queue) {
    <E>_DoubleLinkedQueueElement(element, queue)._link(this, _nextLink);
}

void _DoubleLinkedQueueEntry::_prepend(E element, DoubleLinkedQueue<E> queue) {
    <E>_DoubleLinkedQueueElement(element, queue)._link(_previousLink, this);
}

void _DoubleLinkedQueueElement::append(E e) {
    _append(e, _queue);
    _queue?._elementCount++;
}

void _DoubleLinkedQueueElement::prepend(E e) {
    _prepend(e, _queue);
    _queue?._elementCount++;
}

E _DoubleLinkedQueueElement::remove() {
    _queue?._elementCount--;
    return _remove();
}

DoubleLinkedQueueEntry<E> _DoubleLinkedQueueElement::previousEntry() {
    return _previousLink?._asNonSentinelEntry();
}

DoubleLinkedQueueEntry<E> _DoubleLinkedQueueElement::nextEntry() {
    return _nextLink?._asNonSentinelEntry();
}

E _DoubleLinkedQueueElement::_remove() {
    _queue = nullptr;
    _unlink();
    return element;
}

_DoubleLinkedQueueElement<E> _DoubleLinkedQueueElement::_asNonSentinelEntry() {
    return this;
}

E _DoubleLinkedQueueSentinel::element() {
    ;
}

_DoubleLinkedQueueSentinel::_DoubleLinkedQueueSentinel() {
    {
        _previousLink = this;
        _nextLink = this;
    }
}

Null _DoubleLinkedQueueSentinel::_asNonSentinelEntry() {
    return nullptr;
}

E _DoubleLinkedQueueSentinel::_remove() {
    ;
}

void DoubleLinkedQueue::from(Iterable<dynamic> elements) {
    DoubleLinkedQueue<E> list = <E>DoubleLinkedQueue();
    for (auto e : elements) {
        list.addLast(();
    }
    return list;
}

void DoubleLinkedQueue::of(Iterable<E> elements) {
    return ;
}

Queue<R> DoubleLinkedQueue::cast<R>() {
    return Queue.<E, R>castFrom(this);
}

int DoubleLinkedQueue::length() {
    return _elementCount;
}

void DoubleLinkedQueue::addLast(E value) {
    _sentinel._prepend(value, this);
    _elementCount++;
}

void DoubleLinkedQueue::addFirst(E value) {
    _sentinel._append(value, this);
    _elementCount++;
}

void DoubleLinkedQueue::add(E value) {
    _sentinel._prepend(value, this);
    _elementCount++;
}

void DoubleLinkedQueue::addAll(Iterable<E> iterable) {
    for (E value : iterable) {
        _sentinel._prepend(value, this);
        _elementCount++;
    }
}

E DoubleLinkedQueue::removeLast() {
    E result = _sentinel._previousLink!._remove();
    _elementCount--;
    return result;
}

E DoubleLinkedQueue::removeFirst() {
    E result = _sentinel._nextLink!._remove();
    _elementCount--;
    return result;
}

bool DoubleLinkedQueue::remove(Object o) {
    _DoubleLinkedQueueEntry<E> entry = _sentinel._nextLink!;
    while (true) {
        auto elementEntry = entry._asNonSentinelEntry();
        if (elementEntry == nullptr)         {
            return false;
        }
        bool equals = (elementEntry.element == o);
        if (!identical(this, elementEntry._queue)) {
            ;
        }
        if (equals) {
            entry._remove();
            _elementCount--;
            return true;
        }
        entry = entry._nextLink!;
    }
}

void DoubleLinkedQueue::removeWhere(FunctionType test) {
    _filter(test, true);
}

void DoubleLinkedQueue::retainWhere(FunctionType test) {
    _filter(test, false);
}

E DoubleLinkedQueue::first() {
    return _sentinel._nextLink!.element;
}

E DoubleLinkedQueue::last() {
    return _sentinel._previousLink!.element;
}

E DoubleLinkedQueue::single() {
    if (identical(_sentinel._nextLink, _sentinel._previousLink)) {
        return _sentinel._nextLink!.element;
    }
    ;
}

DoubleLinkedQueueEntry<E> DoubleLinkedQueue::firstEntry() {
    return _sentinel._nextLink!._asNonSentinelEntry();
}

DoubleLinkedQueueEntry<E> DoubleLinkedQueue::lastEntry() {
    return _sentinel._previousLink!._asNonSentinelEntry();
}

bool DoubleLinkedQueue::isEmpty() {
    return identical(_sentinel._nextLink, _sentinel);
}

void DoubleLinkedQueue::clear() {
    auto cursor = _sentinel._nextLink!;
    while (true) {
        auto entry = cursor._asNonSentinelEntry();
        if (entry == nullptr)         {
                    break;
        }
        cursor = cursor._nextLink!;
        ;
    }
    _sentinel._nextLink = _sentinel;
    _sentinel._previousLink = _sentinel;
    _elementCount = 0;
}

void DoubleLinkedQueue::forEachEntry(FunctionType action) {
    auto cursor = _sentinel._nextLink!;
    while (true) {
        auto element = cursor._asNonSentinelEntry();
        if (element == nullptr)         {
                    break;
        }
        if (!identical(element._queue, this)) {
            ;
        }
        cursor = cursor._nextLink!;
        action(element);
        if (identical(this, element._queue)) {
            cursor = element._nextLink!;
        }
    }
}

_DoubleLinkedQueueIterator<E> DoubleLinkedQueue::iterator() {
    return <E>_DoubleLinkedQueueIterator(this);
}

String DoubleLinkedQueue::toString() {
    return IterableBase.iterableToFullString(this, "{", "}");
}

void DoubleLinkedQueue::_filter(bool removeMatching, FunctionType test) {
    _DoubleLinkedQueueEntry<E> entry = _sentinel._nextLink!;
    while (true) {
        auto elementEntry = entry._asNonSentinelEntry();
        if (elementEntry == nullptr)         {
            return;
        }
        bool matches = test(elementEntry.element);
        if (!identical(this, elementEntry._queue)) {
            ;
        }
        auto next = entry._nextLink!;
        if (identical(removeMatching, matches)) {
            elementEntry._remove();
            _elementCount--;
        }
        entry = next;
    }
}

bool _DoubleLinkedQueueIterator::moveNext() {
    auto nextElement = _nextEntry?._asNonSentinelEntry();
    if (nextElement == nullptr) {
        _current = nullptr;
        _nextEntry = nullptr;
        _queue = nullptr;
        return false;
    }
    if (!identical(_queue, nextElement._queue)) {
        ;
    }
    _current = nextElement.element;
    _nextEntry = nextElement._nextLink;
    return true;
}

E _DoubleLinkedQueueIterator::current() {
    return (;
}

_DoubleLinkedQueueIterator::_DoubleLinkedQueueIterator(DoubleLinkedQueue<E> _queue) {
    {
        _nextEntry = _queue._sentinel._nextLink;
    }
}

ListQueue::ListQueue(int initialCapacity) {
    {
        _head = 0;
        _tail = 0;
        _table = <E>filled(_calculateCapacity(initialCapacity), nullptr);
    }
}

void ListQueue::from(Iterable<dynamic> elements) {
    if (elements is List<dynamic>) {
        int length = elements.length;
        ListQueue<E> queue = <E>ListQueue(length + 1);
        assert(queue._table.length > length);
        for (;  < length; i++) {
            queue._table[i] = (;
        }
        queue._tail = length;
        return queue;
    } else {
        int capacity = _INITIAL_CAPACITY;
        if (elements is EfficientLengthIterable) {
            capacity = elements.length;
        }
        ListQueue<E> result = <E>ListQueue(capacity);
        for (auto element : elements) {
            result.addLast(();
        }
        return result;
    }
}

void ListQueue::of(Iterable<E> elements) {
    return ;
}

Queue<R> ListQueue::cast<R>() {
    return Queue.<E, R>castFrom(this);
}

Iterator<E> ListQueue::iterator() {
    return <E>_ListQueueIterator(this);
}

void ListQueue::forEach(FunctionType f) {
    int modificationCount = _modificationCount;
    for (; i != _tail; i = (i + 1) & (_table.length - 1)) {
        f(();
        _checkModification(modificationCount);
    }
}

bool ListQueue::isEmpty() {
    return _head == _tail;
}

int ListQueue::length() {
    return (_tail - _head) & (_table.length - 1);
}

E ListQueue::first() {
    if (_head == _tail)     {
        ;
    }
    return (;
}

E ListQueue::last() {
    if (_head == _tail)     {
        ;
    }
    return (;
}

E ListQueue::single() {
    if (_head == _tail)     {
        ;
    }
    if (length > 1)     {
        ;
    }
    return (;
}

E ListQueue::elementAt(int index) {
    RangeError.checkValidIndex(index, this);
    return (;
}

List<E> ListQueue::toList(bool growable) {
    int mask = _table.length - 1;
    int length = (_tail - _head) & mask;
    if (length == 0)     {
        return <E>empty(growable);
    }
    auto list = <E>filled(length, firstgrowable);
    for (;  < length; i++) {
        list[i] = (;
    }
    return list;
}

void ListQueue::add(E value) {
    _add(value);
}

void ListQueue::addAll(Iterable<E> elements) {
    if (elements is List<E>) {
        List<E> list = elements;
        int addCount = list.length;
        int length = this.length;
        if (length + addCount >= _table.length) {
            _preGrow(length + addCount);
            _table.setRange(length, length + addCount, list, 0);
            _tail = addCount;
        } else {
            int endSpace = _table.length - _tail;
            if ( < endSpace) {
                _table.setRange(_tail, _tail + addCount, list, 0);
                _tail = addCount;
            } else {
                int preSpace = addCount - endSpace;
                _table.setRange(_tail, _tail + endSpace, list, 0);
                _table.setRange(0, preSpace, list, endSpace);
                _tail = preSpace;
            }
        }
        _modificationCount++;
    } else {
        for (E element : elements)         {
            _add(element);
        }
    }
}

bool ListQueue::remove(Object value) {
    for (; i != _tail; i = (i + 1) & (_table.length - 1)) {
        E element = _table[i];
        if (element == value) {
            _remove(i);
            _modificationCount++;
            return true;
        }
    }
    return false;
}

void ListQueue::removeWhere(FunctionType test) {
    _filterWhere(test, true);
}

void ListQueue::retainWhere(FunctionType test) {
    _filterWhere(test, false);
}

void ListQueue::clear() {
    if (_head != _tail) {
        for (; i != _tail; i = (i + 1) & (_table.length - 1)) {
            _table[i] = nullptr;
        }
        _head = _tail = 0;
        _modificationCount++;
    }
}

String ListQueue::toString() {
    return IterableBase.iterableToFullString(this, "{", "}");
}

void ListQueue::addLast(E value) {
    _add(value);
}

void ListQueue::addFirst(E value) {
    _head = (_head - 1) & (_table.length - 1);
    _table[_head] = value;
    if (_head == _tail)     {
        _grow();
    }
    _modificationCount++;
}

E ListQueue::removeFirst() {
    if (_head == _tail)     {
        ;
    }
    _modificationCount++;
    E result = (;
    _table[_head] = nullptr;
    _head = (_head + 1) & (_table.length - 1);
    return result;
}

E ListQueue::removeLast() {
    if (_head == _tail)     {
        ;
    }
    _modificationCount++;
    _tail = (_tail - 1) & (_table.length - 1);
    E result = (;
    _table[_tail] = nullptr;
    return result;
}

int ListQueue::_calculateCapacity(int initialCapacity) {
    if (initialCapacity == nullptr ||  < _INITIAL_CAPACITY) {
        return _INITIAL_CAPACITY;
    } else     {
        if (!_isPowerOf2(initialCapacity)) {
        return _nextPowerOf2(initialCapacity);
    }
;
    }    assert(_isPowerOf2(initialCapacity));
    return initialCapacity;
}

void ListQueue::_filterWhere(bool removeMatching, FunctionType test) {
    int modificationCount = _modificationCount;
    int i = _head;
    while (i != _tail) {
        E element = (;
        bool remove = identical(removeMatching, test(element));
        _checkModification(modificationCount);
        if (remove) {
            i = _remove(i);
            modificationCount = ++_modificationCount;
        } else {
            i = (i + 1) & (_table.length - 1);
        }
    }
}

bool ListQueue::_isPowerOf2(int number) {
    return (number & (number - 1)) == 0;
}

int ListQueue::_nextPowerOf2(int number) {
    assert(number > 0);
    number = (number << 1) - 1;
    for (; ; ) {
        int nextNumber = number & (number - 1);
        if (nextNumber == 0)         {
            return number;
        }
        number = nextNumber;
    }
}

void ListQueue::_checkModification(int expectedModificationCount) {
    if (expectedModificationCount != _modificationCount) {
        ;
    }
}

void ListQueue::_add(E element) {
    _table[_tail] = element;
    _tail = (_tail + 1) & (_table.length - 1);
    if (_head == _tail)     {
        _grow();
    }
    _modificationCount++;
}

int ListQueue::_remove(int offset) {
    int mask = _table.length - 1;
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

void ListQueue::_grow() {
    List<E> newTable = <E>filled(_table.length * 2, nullptr);
    int split = _table.length - _head;
    newTable.setRange(0, split, _table, _head);
    newTable.setRange(split, split + _head, _table, 0);
    _head = 0;
    _tail = _table.length;
    _table = newTable;
}

int ListQueue::_writeToList(List<E> target) {
    assert(target.length >= length);
    if (_head <= _tail) {
        int length = _tail - _head;
        target.setRange(0, length, _table, _head);
        return length;
    } else {
        int firstPartSize = _table.length - _head;
        target.setRange(0, firstPartSize, _table, _head);
        target.setRange(firstPartSize, firstPartSize + _tail, _table, 0);
        return _tail + firstPartSize;
    }
}

void ListQueue::_preGrow(int newElementCount) {
    assert(newElementCount >= length);
    newElementCount = newElementCount >> 1;
    int newCapacity = _nextPowerOf2(newElementCount);
    List<E> newTable = <E>filled(newCapacity, nullptr);
    _tail = _writeToList(newTable);
    _table = newTable;
    _head = 0;
}

E _ListQueueIterator::current() {
    return (;
}

bool _ListQueueIterator::moveNext() {
    _queue._checkModification(_modificationCount);
    if (_position == _end) {
        _current = nullptr;
        return false;
    }
    _current = _queue._table[_position];
    _position = (_position + 1) & (_queue._table.length - 1);
    return true;
}

_ListQueueIterator::_ListQueueIterator(ListQueue<E> queue) {
    {
        _queue = queue;
        _end = queue._tail;
        _modificationCount = queue._modificationCount;
        _position = queue._head;
    }
}
