#include "basic_types.hpp"
Iterator<E> CachingIterable::iterator() {
    return <E>_LazyListIterator(this);
}

Iterable<T> CachingIterable::map<T>(FunctionType toElement) {
    return <T>CachingIterable(super.<T>map(toElement).iterator);
}

Iterable<E> CachingIterable::where(FunctionType test) {
    return <E>CachingIterable(super.where(test).iterator);
}

Iterable<T> CachingIterable::expand<T>(FunctionType toElements) {
    return <T>CachingIterable(super.<T>expand(toElements).iterator);
}

Iterable<E> CachingIterable::take(int count) {
    return <E>CachingIterable(super.take(count).iterator);
}

Iterable<E> CachingIterable::takeWhile(FunctionType test) {
    return <E>CachingIterable(super.takeWhile(test).iterator);
}

Iterable<E> CachingIterable::skip(int count) {
    return <E>CachingIterable(super.skip(count).iterator);
}

Iterable<E> CachingIterable::skipWhile(FunctionType test) {
    return <E>CachingIterable(super.skipWhile(test).iterator);
}

int CachingIterable::length() {
    _precacheEntireList();
    return _results.length;
}

List<E> CachingIterable::toList(bool growable) {
    _precacheEntireList();
    return <E>of(_resultsgrowable);
}

void CachingIterable::_precacheEntireList() {
    while (_fillNext()) {
    }
}

bool CachingIterable::_fillNext() {
    if (!_prefillIterator.moveNext()) {
        return false;
    }
    _results.add(_prefillIterator.current);
    return true;
}

E _LazyListIterator::current() {
    assert(_index >= 0);
    if ( < 0 || _index == _owner._results.length) {
        ;
    }
    return _owner._results[_index];
}

bool _LazyListIterator::moveNext() {
    if (_index >= _owner._results.length) {
        return false;
    }
    _index = 1;
    if (_index == _owner._results.length) {
        return _owner._fillNext();
    }
    return true;
}

_LazyListIterator::_LazyListIterator(CachingIterable<E> _owner) {
    {
        _index = -1;
    }
}

Factory::Factory(ValueGetter<T> constructor) {
    {
        assert(constructor != nullptr);
    }
}

Type Factory::type() {
    return T;
}

String Factory::toString() {
    return "Factory(type: $type)";
}

Duration lerpDuration(Duration a, Duration b, double t) {
    return Duration((a.inMicroseconds + (b.inMicroseconds - a.inMicroseconds) * t).round());
}
