#include "list.hpp"
List<T> List::castFrom<S, T>(List<S> source) {
    return <S, T>CastList(source);
}

void List::copyRange<T>(int at, int end, List<T> source, int start, List<T> target) {
    start = 0;
    end = RangeError.checkValidRange(start, end, source.length);
    if (end == nullptr) {
        ;
    }
    int length = end - start;
    if (target.length < at + length) {
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

void List::writeIterable<T>(int at, Iterable<T> source, List<T> target) {
    RangeError.checkValueInInterval(at, 0, target.length, "at");
    int index = at;
    int targetLength = target.length;
    for (auto element : source) {
        if (index == targetLength) {
            ;
        }
        target[index] = element;
        index++;
    }
}
