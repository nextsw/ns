#include "iterator.hpp"
bool HasNextIterator::hasNext() {
    if (_state == _NOT_MOVED_YET)     {
        _move();
    }
    return _state == _HAS_NEXT_AND_NEXT_IN_CURRENT;
}

E HasNextIterator::next() {
    if (!hasNext)     {
        ;
    }
    assert(_state == _HAS_NEXT_AND_NEXT_IN_CURRENT);
    E result = _iterator.current;
    _move();
    return result;
}

void HasNextIterator::_move() {
    if (_iterator.moveNext()) {
        _state = _HAS_NEXT_AND_NEXT_IN_CURRENT;
    } else {
        _state = _NO_NEXT;
    }
}
