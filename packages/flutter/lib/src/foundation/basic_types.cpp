#include "basic_types.hpp"
template<typename E> Iterator<E> CachingIterableCls<E>::iterator() {
    return <E>make<_LazyListIteratorCls>(this);
}

template<typename E> Iterable<T> CachingIterableCls<E>::maptemplate<typename T> (T toElement(E e) ) {
    return <T>make<CachingIterableCls>(super-><T>map(toElement)->iterator);
}

template<typename E> Iterable<E> CachingIterableCls<E>::where(bool test(E element) ) {
    return <E>make<CachingIterableCls>(super->where(test)->iterator);
}

template<typename E> Iterable<T> CachingIterableCls<E>::expandtemplate<typename T> (Iterable<T> toElements(E element) ) {
    return <T>make<CachingIterableCls>(super-><T>expand(toElements)->iterator);
}

template<typename E> Iterable<E> CachingIterableCls<E>::take(int count) {
    return <E>make<CachingIterableCls>(super->take(count)->iterator);
}

template<typename E> Iterable<E> CachingIterableCls<E>::takeWhile(bool test(E value) ) {
    return <E>make<CachingIterableCls>(super->takeWhile(test)->iterator);
}

template<typename E> Iterable<E> CachingIterableCls<E>::skip(int count) {
    return <E>make<CachingIterableCls>(super->skip(count)->iterator);
}

template<typename E> Iterable<E> CachingIterableCls<E>::skipWhile(bool test(E value) ) {
    return <E>make<CachingIterableCls>(super->skipWhile(test)->iterator);
}

template<typename E> int CachingIterableCls<E>::length() {
    _precacheEntireList();
    return _results->length();
}

template<typename E> List<E> CachingIterableCls<E>::toList(bool growable) {
    _precacheEntireList();
    return <E>of(_resultsgrowable);
}

template<typename E> void CachingIterableCls<E>::_precacheEntireList() {
    while (_fillNext()) {
    }
}

template<typename E> bool CachingIterableCls<E>::_fillNext() {
    if (!_prefillIterator->moveNext()) {
        return false;
    }
    _results->add(_prefillIterator->current());
    return true;
}

template<typename E> E _LazyListIteratorCls<E>::current() {
    assert(_index >= 0);
    if ( < 0 || _index == _owner->_results->length()) {
        ;
    }
    return _owner->_results[_index];
}

template<typename E> bool _LazyListIteratorCls<E>::moveNext() {
    if (_index >= _owner->_results->length()) {
        return false;
    }
    _index = 1;
    if (_index == _owner->_results->length()) {
        return _owner->_fillNext();
    }
    return true;
}

template<typename E> _LazyListIteratorCls<E>::_LazyListIteratorCls(CachingIterable<E> _owner) {
    {
        _index = -1;
    }
}

template<typename T> FactoryCls<T>::FactoryCls(ValueGetter<T> constructor) {
    {
        assert(constructor != nullptr);
    }
}

template<typename T> Type FactoryCls<T>::type() {
    return TCls;
}

template<typename T> String FactoryCls<T>::toString() {
    return __s("Factory(type: $type)");
}

Duration lerpDuration(Duration a, Duration b, double t) {
    return make<DurationCls>((a->inMicroseconds + (b->inMicroseconds - a->inMicroseconds) * t)->round());
}
