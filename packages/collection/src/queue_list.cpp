#include "queue_list.hpp"
QueueList::QueueList(int initialCapacity) {
    {
        this._init(_computeInitialCapacity(initialCapacity));
    }
}

void QueueList::from(Iterable<E> source) {
    if (source is List) {
        auto length = source.length;
        auto queue = <E>QueueList(length + 1);
        assert(queue._table.length > length);
        auto sourceList = source;
        queue._table.setRange(0, length, sourceList, 0);
        queue._tail = length;
        return queue;
    } else {
        return ;
    }
}

void QueueList::add(E element) {
    _add(element);
}

void QueueList::addAll(Iterable<E> iterable) {
    if (iterable is List) {
        auto list = iterable;
        auto addCount = list.length;
        auto length = this.length;
        if (length + addCount >= _table.length) {
            _preGrow(length + addCount);
            _table.setRange(length, length + addCount, list, 0);
            _tail = addCount;
        } else {
            auto endSpace = _table.length - _tail;
            if ( < endSpace) {
                _table.setRange(_tail, _tail + addCount, list, 0);
                _tail = addCount;
            } else {
                auto preSpace = addCount - endSpace;
                _table.setRange(_tail, _tail + endSpace, list, 0);
                _table.setRange(0, preSpace, list, endSpace);
                _tail = preSpace;
            }
        }
    } else {
        for (auto element : iterable) {
            _add(element);
        }
    }
}

QueueList<T> QueueList::cast<T>() {
    return QueueList.<E, T>_castFrom(this);
}

QueueList<T> QueueList::retype<T>() {
    return <T>cast();
}

String QueueList::toString() {
    return IterableBase.iterableToFullString(this, "{", "}");
}

void QueueList::addLast(E element) {
    _add(element);
}

void QueueList::addFirst(E element) {
    _head = (_head - 1) & (_table.length - 1);
    _table[_head] = element;
    if (_head == _tail)     {
        _grow();
    }
}

E QueueList::removeFirst() {
    if (_head == _tail)     {
        ;
    }
    auto result = (;
    _table[_head] = nullptr;
    _head = (_head + 1) & (_table.length - 1);
    return result;
}

E QueueList::removeLast() {
    if (_head == _tail)     {
        ;
    }
    _tail = (_tail - 1) & (_table.length - 1);
    auto result = (;
    _table[_tail] = nullptr;
    return result;
}

int QueueList::length() {
    return (_tail - _head) & (_table.length - 1);
}

void QueueList::length(int value) {
    if ( < 0)     {
        ;
    }
    if (value > length && nullptr is! E) {
        ;
    }
    auto delta = value - length;
    if (delta >= 0) {
        if (_table.length <= value) {
            _preGrow(value);
        }
        _tail = (_tail + delta) & (_table.length - 1);
        return;
    }
    auto newTail = _tail + delta;
    if (newTail >= 0) {
        _table.fillRange(newTail, _tail, nullptr);
    } else {
        newTail = _table.length;
        _table.fillRange(0, _tail, nullptr);
        _table.fillRange(newTail, _table.length, nullptr);
    }
    _tail = newTail;
}

E QueueList::[](int index) {
    if ( < 0 || index >= length) {
        ;
    }
    return (;
}

void QueueList::[]=(int index, E value) {
    if ( < 0 || index >= length) {
        ;
    }
    _table[(_head + index) & (_table.length - 1)] = value;
}

QueueList<T> QueueList::_castFrom<S, T>(QueueList<S> source) {
    return <S, T>_CastQueueList(source);
}

void QueueList::_init(int initialCapacity)

int QueueList::_computeInitialCapacity(int initialCapacity) {
    if (initialCapacity == nullptr ||  < _initialCapacity) {
        return _initialCapacity;
    }
    initialCapacity = 1;
    if (_isPowerOf2(initialCapacity)) {
        return initialCapacity;
    }
    return _nextPowerOf2(initialCapacity);
}

bool QueueList::_isPowerOf2(int number) {
    return (number & (number - 1)) == 0;
}

int QueueList::_nextPowerOf2(int number) {
    assert(number > 0);
    number = (number << 1) - 1;
    for (; ; ) {
        auto nextNumber = number & (number - 1);
        if (nextNumber == 0)         {
            return number;
        }
        number = nextNumber;
    }
}

void QueueList::_add(E element) {
    _table[_tail] = element;
    _tail = (_tail + 1) & (_table.length - 1);
    if (_head == _tail)     {
        _grow();
    }
}

void QueueList::_grow() {
    auto newTable = <E>filled(_table.length * 2, nullptr);
    auto split = _table.length - _head;
    newTable.setRange(0, split, _table, _head);
    newTable.setRange(split, split + _head, _table, 0);
    _head = 0;
    _tail = _table.length;
    _table = newTable;
}

int QueueList::_writeToList(List<E> target) {
    assert(target.length >= length);
    if (_head <= _tail) {
        auto length = _tail - _head;
        target.setRange(0, length, _table, _head);
        return length;
    } else {
        auto firstPartSize = _table.length - _head;
        target.setRange(0, firstPartSize, _table, _head);
        target.setRange(firstPartSize, firstPartSize + _tail, _table, 0);
        return _tail + firstPartSize;
    }
}

void QueueList::_preGrow(int newElementCount) {
    assert(newElementCount >= length);
    newElementCount = newElementCount >> 1;
    auto newCapacity = _nextPowerOf2(newElementCount);
    auto newTable = <E>filled(newCapacity, nullptr);
    _tail = _writeToList(newTable);
    _table = newTable;
    _head = 0;
}

_CastQueueList::_CastQueueList(QueueList<S> _delegate) {
    {
        super._(-1, -1, _delegate._table.<T>cast());
    }
}

int _CastQueueList::_head() {
    return _delegate._head;
}

void _CastQueueList::_head(int value) {
    return _delegate._head = value;
}

int _CastQueueList::_tail() {
    return _delegate._tail;
}

void _CastQueueList::_tail(int value) {
    return _delegate._tail = value;
}
