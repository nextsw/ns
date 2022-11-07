#include "combined_list.hpp"
Iterator<T> CombinedListView::iterator() {
    return <T>CombinedIterator(_lists.map().iterator);
}

void CombinedListView::length(int length) {
    _throw();
}

int CombinedListView::length() {
    return _lists.fold(0, );
}

T CombinedListView::[](int index) {
    auto initialIndex = index;
    for (;  < _lists.length; i++) {
        auto list = _lists[i];
        if ( < list.length) {
            return list[index];
        }
        index = list.length;
    }
    ;
}

void CombinedListView::[]=(int index, T value) {
    _throw();
}

void CombinedListView::clear() {
    _throw();
}

bool CombinedListView::remove(Object element) {
    _throw();
}

void CombinedListView::removeWhere(FunctionType test) {
    _throw();
}

void CombinedListView::retainWhere(FunctionType test) {
    _throw();
}

Never CombinedListView::_throw() {
    ;
}
