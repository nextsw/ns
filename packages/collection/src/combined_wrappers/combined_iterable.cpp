#include "combined_iterable.hpp"
template<typename T>
Iterator<T> CombinedIterableViewCls<T>::iterator() {
    return <T>make<CombinedIteratorCls>(_iterables->map([=] (Unknown  i)     {
        i->iterator;
    })->iterator());
}

template<typename T>
bool CombinedIterableViewCls<T>::contains(Object element) {
    return _iterables->any([=] (Unknown  i)     {
        i->contains(element);
    });
}

template<typename T>
bool CombinedIterableViewCls<T>::isEmpty() {
    return _iterables->every([=] (Unknown  i)     {
        i->isEmpty;
    });
}

template<typename T>
int CombinedIterableViewCls<T>::length() {
    return _iterables->fold(0, [=] (Unknown  length,Unknown  i)     {
        length() + i->length;
    });
}
