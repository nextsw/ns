#include "collections.hpp"
template<typename E> UnmodifiableListViewCls<E>::UnmodifiableListViewCls(Iterable<E> source) {
    {
        _source = source;
    }
}

template<typename E> List<R> UnmodifiableListViewCls<E>::casttemplate<typename R> () {
    return make<UnmodifiableListViewCls>(_source-><R>cast());
}

template<typename E> int UnmodifiableListViewCls<E>::length() {
    return _source->length();
}

template<typename E> E UnmodifiableListViewCls<E>::[](int index) {
    return _source->elementAt(index);
}
