#include "list.hpp"
template<typename E> List<T> ListCls<E>::castFromtemplate<typename S, typename T> (List<S> source) {
    return <S, T>make<CastListCls>(source);
}

template<typename E> void ListCls<E>::copyRangetemplate<typename T> (int at, int end, List<T> source, int start, List<T> target) {
    start = 0;
    end = RangeErrorCls->checkValidRange(start, end, source->length);
    if (end == nullptr) {
        ;
    }
    int length = end - start;
    if (target->length < at + length) {
        ;
    }
    if (!identical(source, target) || start >= at) {
        for (;  < length; i++) {
            target[at + i] = source[start + i];
        }
    } else {
        for (; --i >= 0; ) {
            target[at + i] = source[start + i];
        }
    }
}

template<typename E> void ListCls<E>::writeIterabletemplate<typename T> (int at, Iterable<T> source, List<T> target) {
    RangeErrorCls->checkValueInInterval(at, 0, target->length, __s("at"));
    int index = at;
    int targetLength = target->length;
    for (auto element : source) {
        if (index == targetLength) {
            ;
        }
        target[index] = element;
        index++;
    }
}
