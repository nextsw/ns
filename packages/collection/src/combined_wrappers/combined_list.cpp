#include "combined_list.hpp"
template<typename T> Iterator<T> CombinedListViewCls<T>::iterator() {
    return <T>make<CombinedIteratorCls>(_lists->map([=] (Unknown  i)     {
        i->iterator;
    })->iterator);
}

template<typename T> void CombinedListViewCls<T>::length(int length) {
    _throw();
}

template<typename T> int CombinedListViewCls<T>::length() {
    return _lists->fold(0, [=] (Unknown  length,Unknown  list)     {
        length + list->length;
    });
}

template<typename T> T CombinedListViewCls<T>::[](int index) {
    auto initialIndex = index;
    for (;  < _lists->length(); i++) {
        auto list = _lists[i];
        if ( < list->length()) {
            return list[index];
        }
        index = list->length();
    }
    ;
}

template<typename T> void CombinedListViewCls<T>::[]=(int index, T value) {
    _throw();
}

template<typename T> void CombinedListViewCls<T>::clear() {
    _throw();
}

template<typename T> bool CombinedListViewCls<T>::remove(Object element) {
    _throw();
}

template<typename T> void CombinedListViewCls<T>::removeWhere(bool test(T ) ) {
    _throw();
}

template<typename T> void CombinedListViewCls<T>::retainWhere(bool test(T ) ) {
    _throw();
}

template<typename T> Never CombinedListViewCls<T>::_throw() {
    ;
}
