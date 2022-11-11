#include "list.hpp"
template<typename E>
template<typename S, typename T>
List<T> ListCls<E>::castFrom(List<S> source) {
    return <S, T>make<CastListCls>(source);
}

template<typename E>
template<typename T>
void ListCls<E>::copyRange(int at, int end, List<T> source, int start, List<T> target) {
    start = 0;
    end = RangeErrorCls->checkValidRange(start, end, source->length());
    if (end == nullptr) {
        throw __s("unreachable");
    }
    int length = end - start;
    if (target->length < at + length) {
        throw ArgumentErrorCls->value(target, __s("target"), __s("Not big enough to hold $length elements at position $at"));
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

template<typename E>
template<typename T>
void ListCls<E>::writeIterable(int at, Iterable<T> source, List<T> target) {
    RangeErrorCls->checkValueInInterval(at, 0, target->length(), __s("at"));
    int index = at;
    int targetLength = target->length();
    for (auto element : source) {
        if (index == targetLength) {
            throw make<IndexErrorCls>(targetLength, target);
        }
        target[index] = element;
        index++;
    }
}
