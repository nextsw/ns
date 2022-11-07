#include "collections.hpp"
UnmodifiableListView::UnmodifiableListView(Iterable<E> source) {
    {
        _source = source;
    }
}

List<R> UnmodifiableListView::cast<R>() {
    return UnmodifiableListView(_source.<R>cast());
}

int UnmodifiableListView::length() {
    return _source.length;
}

E UnmodifiableListView::[](int index) {
    return _source.elementAt(index);
}
