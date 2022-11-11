#include "iterator.hpp"
template<typename E>
bool HasNextIteratorCls<E>::hasNext() {
    if (_state == _NOT_MOVED_YET) {
        _move();
    }
    return _state == _HAS_NEXT_AND_NEXT_IN_CURRENT;
}

template<typename E>
E HasNextIteratorCls<E>::next() {
    if (!hasNext()) {
        throw make<StateErrorCls>(__s("No more elements"));
    }
    assert(_state == _HAS_NEXT_AND_NEXT_IN_CURRENT);
    E result = _iterator->current();
    _move();
    return result;
}

template<typename E>
void HasNextIteratorCls<E>::_move() {
    if (_iterator->moveNext()) {
        _state = _HAS_NEXT_AND_NEXT_IN_CURRENT;
    } else {
        _state = _NO_NEXT;
    }
}
