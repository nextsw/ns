#include "iterable_zip.hpp"
IterableZip::IterableZip(Iterable<Iterable<T>> iterables) {
    {
        _iterables = iterables;
    }
}

Iterator<List<T>> IterableZip::iterator() {
    auto iterators = _iterables.map().toList(false);
    return <T>_IteratorZip(iterators);
}

bool _IteratorZip::moveNext() {
    if (_iterators.isEmpty)     {
        return false;
    }
    for (;  < _iterators.length; i++) {
        if (!_iterators[i].moveNext()) {
            _current = nullptr;
            return false;
        }
    }
    _current = List.generate(_iterators.length, false);
    return true;
}

List<T> _IteratorZip::current() {
    return _current ?? ();
}

_IteratorZip::_IteratorZip(List<Iterator<T>> iterators) {
    {
        _iterators = iterators;
    }
}
