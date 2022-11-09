#include "iterator.hpp"
template<typename E> bool HasNextIteratorCls<E>::hasNext() {
    if (_state == _NOT_MOVED_YETCls)     {
        _move();
    }
    return _state == _HAS_NEXT_AND_NEXT_IN_CURRENTCls;
}

template<typename E> E HasNextIteratorCls<E>::next() {
    if (!hasNext)     {
        ;
    }
    assert(_state == _HAS_NEXT_AND_NEXT_IN_CURRENTCls);
    E result = _iterator->current;
    _move();
    return result;
}

template<typename E> void HasNextIteratorCls<E>::_move() {
    if (_iterator->moveNext()) {
        _state = _HAS_NEXT_AND_NEXT_IN_CURRENTCls;
    } else {
        _state = _NO_NEXTCls;
    }
}
