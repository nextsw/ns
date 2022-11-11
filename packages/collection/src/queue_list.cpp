#include "queue_list.hpp"
template<typename E>
QueueListCls<E>::QueueListCls(int initialCapacity) {
    {
        this->_init(_computeInitialCapacity(initialCapacity));
    }
}

template<typename E>
void QueueListCls<E>::from(Iterable<E> source) {
    if (is<List>(source)) {
        auto length = as<ListCls>(source)->length();
        auto queue = <E>make<QueueListCls>(length + 1);
        assert(queue->_table->length > length);
        auto sourceList = as<ListCls>(source);
        queue->_table->setRange(0, length, sourceList, 0);
        queue->_tail = length;
        return queue;
    } else {
            auto _c1 = <E>make<QueueListCls>();    _c1.addAll(source);return _c1;
    }
}

template<typename E>
void QueueListCls<E>::add(E element) {
    _add(element);
}

template<typename E>
void QueueListCls<E>::addAll(Iterable<E> iterable) {
    if (is<List>(iterable)) {
        auto list = as<ListCls>(iterable);
        auto addCount = list->length();
        auto length = this->length();
        if (length + addCount >= _table->length) {
            _preGrow(length + addCount);
            _table->setRange(length, length + addCount, list, 0);
            _tail = addCount;
        } else {
            auto endSpace = _table->length - _tail;
            if ( < endSpace) {
                _table->setRange(_tail, _tail + addCount, list, 0);
                _tail = addCount;
            } else {
                auto preSpace = addCount - endSpace;
                _table->setRange(_tail, _tail + endSpace, list, 0);
                _table->setRange(0, preSpace, list, endSpace);
                _tail = preSpace;
            }
        }
    } else {
        for (auto element : iterable) {
            _add(element);
        }
    }
}

template<typename E>
template<typename T>
QueueList<T> QueueListCls<E>::cast() {
    return QueueListCls-><E, T>_castFrom(this);
}

template<typename E>
template<typename T>
QueueList<T> QueueListCls<E>::retype() {
    return <T>cast();
}

template<typename E>
String QueueListCls<E>::toString() {
    return IterableBaseCls->iterableToFullString(this, __s("{"), __s("}"));
}

template<typename E>
void QueueListCls<E>::addLast(E element) {
    _add(element);
}

template<typename E>
void QueueListCls<E>::addFirst(E element) {
    _head = (_head - 1) & (_table->length() - 1);
    _table[_head] = element;
    if (_head == _tail)     {
        _grow();
    }
}

template<typename E>
E QueueListCls<E>::removeFirst() {
    if (_head == _tail)     {
        ;
    }
    auto result = as<E>(_table[_head]);
    _table[_head] = nullptr;
    _head = (_head + 1) & (_table->length() - 1);
    return result;
}

template<typename E>
E QueueListCls<E>::removeLast() {
    if (_head == _tail)     {
        ;
    }
    _tail = (_tail - 1) & (_table->length() - 1);
    auto result = as<E>(_table[_tail]);
    _table[_tail] = nullptr;
    return result;
}

template<typename E>
int QueueListCls<E>::length() {
    return (_tail - _head) & (_table->length() - 1);
}

template<typename E>
void QueueListCls<E>::length(int value) {
    if ( < 0)     {
        ;
    }
    if (value > length() && !is<E>(nullptr)) {
        ;
    }
    auto delta = value - length();
    if (delta >= 0) {
        if (_table->length() <= value) {
            _preGrow(value);
        }
        _tail = (_tail + delta) & (_table->length() - 1);
        return;
    }
    auto newTail = _tail + delta;
    if (newTail >= 0) {
        _table->fillRange(newTail, _tail, nullptr);
    } else {
        newTail = _table->length();
        _table->fillRange(0, _tail, nullptr);
        _table->fillRange(newTail, _table->length(), nullptr);
    }
    _tail = newTail;
}

template<typename E>
E QueueListCls<E>::[](int index) {
    if ( < 0 || index >= length()) {
        ;
    }
    return as<E>(_table[(_head + index) & (_table->length() - 1)]);
}

template<typename E>
void QueueListCls<E>::[]=(int index, E value) {
    if ( < 0 || index >= length()) {
        ;
    }
    _table[(_head + index) & (_table->length() - 1)] = value;
}

template<typename E>
template<typename S, typename T>
QueueList<T> QueueListCls<E>::_castFrom(QueueList<S> source) {
    return <S, T>make<_CastQueueListCls>(source);
}

template<typename E>
void QueueListCls<E>::_init(int initialCapacity)

template<typename E>
int QueueListCls<E>::_computeInitialCapacity(int initialCapacity) {
    if (initialCapacity == nullptr ||  < _initialCapacity) {
        return _initialCapacity;
    }
    initialCapacity = 1;
    if (_isPowerOf2(initialCapacity)) {
        return initialCapacity;
    }
    return _nextPowerOf2(initialCapacity);
}

template<typename E>
bool QueueListCls<E>::_isPowerOf2(int number) {
    return (number & (number - 1)) == 0;
}

template<typename E>
int QueueListCls<E>::_nextPowerOf2(int number) {
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

template<typename E>
void QueueListCls<E>::_add(E element) {
    _table[_tail] = element;
    _tail = (_tail + 1) & (_table->length() - 1);
    if (_head == _tail)     {
        _grow();
    }
}

template<typename E>
void QueueListCls<E>::_grow() {
    auto newTable = <E>filled(_table->length() * 2, nullptr);
    auto split = _table->length() - _head;
    newTable->setRange(0, split, _table, _head);
    newTable->setRange(split, split + _head, _table, 0);
    _head = 0;
    _tail = _table->length();
    _table = newTable;
}

template<typename E>
int QueueListCls<E>::_writeToList(List<E> target) {
    assert(target->length() >= length());
    if (_head <= _tail) {
        auto length = _tail - _head;
        target->setRange(0, length, _table, _head);
        return length;
    } else {
        auto firstPartSize = _table->length() - _head;
        target->setRange(0, firstPartSize, _table, _head);
        target->setRange(firstPartSize, firstPartSize + _tail, _table, 0);
        return _tail + firstPartSize;
    }
}

template<typename E>
void QueueListCls<E>::_preGrow(int newElementCount) {
    assert(newElementCount >= length());
    newElementCount = newElementCount >> 1;
    auto newCapacity = _nextPowerOf2(newElementCount);
    auto newTable = <E>filled(newCapacity, nullptr);
    _tail = _writeToList(newTable);
    _table = newTable;
    _head = 0;
}

template<typename S, typename T>
_CastQueueListCls<S, T>::_CastQueueListCls(QueueList<S> _delegate) {
    {
        super->_(-1, -1, _delegate->_table-><T>cast());
    }
}

template<typename S, typename T>
int _CastQueueListCls<S, T>::_head() {
    return _delegate->_head;
}

template<typename S, typename T>
void _CastQueueListCls<S, T>::_head(int value) {
    return _delegate->_head = value;
}

template<typename S, typename T>
int _CastQueueListCls<S, T>::_tail() {
    return _delegate->_tail;
}

template<typename S, typename T>
void _CastQueueListCls<S, T>::_tail(int value) {
    return _delegate->_tail = value;
}
