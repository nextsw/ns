#include "iterable_zip.hpp"
template<typename T>
IterableZipCls<T>::IterableZipCls(Iterable<Iterable<T>> iterables) {
    {
        _iterables = iterables;
    }
}

template<typename T>
Iterator<List<T>> IterableZipCls<T>::iterator() {
    auto iterators = _iterables->map([=] (Unknown  x) {
    x->iterator;
})->toList(false);
    return <T>make<_IteratorZipCls>(iterators);
}

template<typename T>
bool _IteratorZipCls<T>::moveNext() {
    if (_iterators->isEmpty)     {
        return false;
    }
    for (;  < _iterators->length(); i++) {
        if (!_iterators[i]->moveNext()) {
            _current = nullptr;
            return false;
        }
    }
    _current = ListCls->generate(_iterators->length(), [=] (Unknown  i)     {
        _iterators[i]->current();
    }false);
    return true;
}

template<typename T>
List<T> _IteratorZipCls<T>::current() {
    return _current | (throw make<StateErrorCls>(__s("No element")));
}

template<typename T>
_IteratorZipCls<T>::_IteratorZipCls(List<Iterator<T>> iterators) {
    {
        _iterators = iterators;
    }
}
