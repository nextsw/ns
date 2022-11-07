#include "combined_iterator.hpp"
CombinedIterator::CombinedIterator(Iterator<Iterator<T>> iterators) {
    {
        _iterators = iterators;
    }
    {
        if (!iterators.moveNext())         {
            _iterators = nullptr;
        }
    }
}

T CombinedIterator::current() {
    auto iterators = _iterators;
    if (iterators != nullptr)     {
        return iterators.current.current;
    }
    return (;
}

bool CombinedIterator::moveNext() {
    auto iterators = _iterators;
    if (iterators != nullptr) {
        do {
            if (iterators.current.moveNext()) {
                return true;
            }
        } while (iterators.moveNext());
        _iterators = nullptr;
    }
    return false;
}
