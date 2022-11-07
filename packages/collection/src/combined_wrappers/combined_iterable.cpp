#include "combined_iterable.hpp"
Iterator<T> CombinedIterableView::iterator() {
    return <T>CombinedIterator(_iterables.map().iterator);
}

bool CombinedIterableView::contains(Object element) {
    return _iterables.any();
}

bool CombinedIterableView::isEmpty() {
    return _iterables.every();
}

int CombinedIterableView::length() {
    return _iterables.fold(0, );
}
