#include "combined_iterator.hpp"
template<typename T> CombinedIteratorCls<T>::CombinedIteratorCls(Iterator<Iterator<T>> iterators) {
    {
            auto _c1 = toSet();    _c1.addAll(other);_iterators = iterators;
    }
    {
        if (!iterators->moveNext())         {
            _iterators = nullptr;
        }
    }
}

template<typename T> T CombinedIteratorCls<T>::current() {
    auto iterators = _iterators;
    if (iterators != nullptr)     {
        return iterators->current()->current();
    }
    return as<T>(nullptr);
}

template<typename T> bool CombinedIteratorCls<T>::moveNext() {
    auto iterators = _iterators;
    if (iterators != nullptr) {
        do {
            if (iterators->current()->moveNext()) {
                return true;
            }
        } while (iterators->moveNext());
        _iterators = nullptr;
    }
    return false;
}
