#include "collections.hpp"
template<typename E>
UnmodifiableListViewCls<E>::UnmodifiableListViewCls(Iterable<E> source) {
    {
        _source = source;
    }
}

template<typename E>
template<typename R>
List<R> UnmodifiableListViewCls<E>::cast() {
    return make<UnmodifiableListViewCls>(_source-><R>cast());
}

template<typename E>
int UnmodifiableListViewCls<E>::length() {
    return _source->length();
}

template<typename E>
E UnmodifiableListViewCls<E>::[](int index) {
    return _source->elementAt(index);
}
