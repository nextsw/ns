#include "iterable.hpp"
template<typename E>
template<typename R>
Iterable<R> IterableMixinCls<E>::cast() {
    return IterableCls-><E, R>castFrom(this);
}

template<typename E>
template<typename T>
Iterable<T> IterableMixinCls<E>::map(std::function<T(E element)> toElement) {
    return <E, T>make<MappedIterableCls>(this, toElement);
}

template<typename E>
Iterable<E> IterableMixinCls<E>::where(std::function<bool(E element)> test) {
    return <E>make<WhereIterableCls>(this, test);
}

template<typename E>
template<typename T>
Iterable<T> IterableMixinCls<E>::whereType() {
    return <T>make<WhereTypeIterableCls>(this);
}

template<typename E>
template<typename T>
Iterable<T> IterableMixinCls<E>::expand(std::function<Iterable<T>(E element)> toElements) {
    return <E, T>make<ExpandIterableCls>(this, toElements);
}

template<typename E>
Iterable<E> IterableMixinCls<E>::followedBy(Iterable<E> other) {
    auto _c1 = <E>make<HashSetCls>();_c1.addAll(elements);Iterable<E> self = this;
    if (is<EfficientLengthIterable<E>>(self)) {
        return <E>firstEfficient(as<EfficientLengthIterableCls>(self), other);
    }
    return <E>make<FollowedByIterableCls>(this, other);
}

template<typename E>
bool IterableMixinCls<E>::contains(Object element) {
    for (E e : this) {
        if (e == element) {
            return true;
        }
    }
    return false;
}

template<typename E>
void IterableMixinCls<E>::forEach(std::function<void(E element)> action) {
    for (E element : this) {
        action(element);
    }
}

template<typename E>
E IterableMixinCls<E>::reduce(std::function<E(E value, E element)> combine) {
    Iterator<E> iterator = this->iterator();
    if (!iterator->moveNext()) {
        throw IterableElementErrorCls->noElement();
    }
    E value = iterator->current();
    while (iterator->moveNext()) {
        value = combine(value, iterator->current());
    }
    return value;
}

template<typename E>
template<typename T>
T IterableMixinCls<E>::fold(T initialValue, std::function<T(T previousValue, E element)> combine) {
    auto value = initialValue;
    for (E element : this) {
        value = combine(value, element);
    }
    return value;
}

template<typename E>
bool IterableMixinCls<E>::every(std::function<bool(E element)> test) {
    for (E element : this) {
        if (!test(element)) {
            return false;
        }
    }
    return true;
}

template<typename E>
String IterableMixinCls<E>::join(String separator) {
    Iterator<E> iterator = this->iterator();
    if (!iterator->moveNext()) {
        return __s("");
    }
    StringBuffer buffer = make<StringBufferCls>();
    if (separator == nullptr || separator == __s("")) {
        do {
            buffer->write(__s("${iterator.current}"));
        } while (iterator->moveNext());
    } else {
        buffer->write(__s("${iterator.current}"));
        while (iterator->moveNext()) {
            buffer->write(separator);
            buffer->write(__s("${iterator.current}"));
        }
    }
    return buffer->toString();
}

template<typename E>
bool IterableMixinCls<E>::any(std::function<bool(E element)> test) {
    for (E element : this) {
        if (test(element)) {
            return true;
        }
    }
    return false;
}

template<typename E>
List<E> IterableMixinCls<E>::toList(bool growable) {
    return <E>from(this, growable);
}

template<typename E>
Set<E> IterableMixinCls<E>::toSet() {
    return <E>from(this);
}

template<typename E>
int IterableMixinCls<E>::length() {
    assert(!is<EfficientLengthIterable<any>>(this));
    int count = 0;
    Iterator<any> it = iterator();
    while (it->moveNext()) {
        count++;
    }
    return count;
}

template<typename E>
bool IterableMixinCls<E>::isEmpty() {
    return !iterator()->moveNext();
}

template<typename E>
bool IterableMixinCls<E>::isNotEmpty() {
    return !isEmpty();
}

template<typename E>
Iterable<E> IterableMixinCls<E>::take(int count) {
    return <E>make<TakeIterableCls>(this, count);
}

template<typename E>
Iterable<E> IterableMixinCls<E>::takeWhile(std::function<bool(E value)> test) {
    return <E>make<TakeWhileIterableCls>(this, test);
}

template<typename E>
Iterable<E> IterableMixinCls<E>::skip(int count) {
    return <E>make<SkipIterableCls>(this, count);
}

template<typename E>
Iterable<E> IterableMixinCls<E>::skipWhile(std::function<bool(E value)> test) {
    return <E>make<SkipWhileIterableCls>(this, test);
}

template<typename E>
E IterableMixinCls<E>::first() {
    Iterator<E> it = iterator();
    if (!it->moveNext()) {
        throw IterableElementErrorCls->noElement();
    }
    return it->current();
}

template<typename E>
E IterableMixinCls<E>::last() {
    Iterator<E> it = iterator();
    if (!it->moveNext()) {
        throw IterableElementErrorCls->noElement();
    }
    E result;
    do {
        result = it->current();
    } while (it->moveNext());
    return result;
}

template<typename E>
E IterableMixinCls<E>::single() {
    Iterator<E> it = iterator();
    if (!it->moveNext()) {
        throw IterableElementErrorCls->noElement();
    }
    E result = it->current();
    if (it->moveNext()) {
        throw IterableElementErrorCls->tooMany();
    }
    return result;
}

template<typename E>
E IterableMixinCls<E>::firstWhere(std::function<bool(E value)> test, std::function<E()> orElse) {
    for (E element : this) {
        if (test(element)) {
            return element;
        }
    }
    if (orElse != nullptr) {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E IterableMixinCls<E>::lastWhere(std::function<bool(E value)> test, std::function<E()> orElse) {
    E result;
    bool foundMatching = false;
    for (E element : this) {
        if (test(element)) {
            result = element;
            foundMatching = true;
        }
    }
    if (foundMatching) {
        return result;
    }
    if (orElse != nullptr) {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E IterableMixinCls<E>::singleWhere(std::function<bool(E element)> test, std::function<E()> orElse) {
    E result;
    bool foundMatching = false;
    for (E element : this) {
        if (test(element)) {
            if (foundMatching) {
                throw IterableElementErrorCls->tooMany();
            }
            result = element;
            foundMatching = true;
        }
    }
    if (foundMatching) {
        return result;
    }
    if (orElse != nullptr) {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E IterableMixinCls<E>::elementAt(int index) {
    checkNotNullable(index, __s("index"));
    RangeErrorCls->checkNotNegative(index, __s("index"));
    int elementIndex = 0;
    for (E element : this) {
        if (index == elementIndex) {
            return element;
        }
        elementIndex++;
    }
    throw RangeErrorCls->index(index, this, __s("index"), nullptr, elementIndex);
}

template<typename E>
String IterableMixinCls<E>::toString() {
    return IterableBaseCls->iterableToShortString(this, __s("("), __s(")"));
}

template<typename E>
String IterableBaseCls<E>::iterableToShortString(Iterable<any> iterable, String leftDelimiter, String rightDelimiter) {
    if (_isToStringVisiting(iterable)) {
        if (leftDelimiter == __s("(") && rightDelimiter == __s(")")) {
            return __s("(...)");
        }
        return __s("$leftDelimiter...$rightDelimiter");
    }
    List<String> parts = makeList();
    _toStringVisiting->add(iterable);
    try {
        _iterablePartsToStrings(iterable, parts);
    } finally {
        assert(identical(_toStringVisiting->last, iterable));
        _toStringVisiting->removeLast();
    };
    auto _c1 = make<StringBufferCls>(leftDelimiter);_c1.auto _c2 = writeAll(parts, __s(", "));_c2.write(rightDelimiter);_c2;return (_c1)->toString();
}

template<typename E>
String IterableBaseCls<E>::iterableToFullString(Iterable<any> iterable, String leftDelimiter, String rightDelimiter) {
    if (_isToStringVisiting(iterable)) {
        return __s("$leftDelimiter...$rightDelimiter");
    }
    StringBuffer buffer = make<StringBufferCls>(leftDelimiter);
    _toStringVisiting->add(iterable);
    try {
        buffer->writeAll(iterable, __s(", "));
    } finally {
        assert(identical(_toStringVisiting->last, iterable));
        _toStringVisiting->removeLast();
    };
    buffer->write(rightDelimiter);
    return buffer->toString();
}

bool _isToStringVisiting(Object o) {
    for (;  < _toStringVisiting->length; i++) {
        if (identical(o, _toStringVisiting[i])) {
            return true;
        }
    }
    return false;
}

void _iterablePartsToStrings(Iterable<Object> iterable, List<String> parts) {
    int lengthLimit = 80;
    int headCount = 3;
    int tailCount = 2;
    int maxCount = 100;
    int overhead = 2;
    int ellipsisSize = 3;
    int length = 0;
    int count = 0;
    Iterator<Object> it = iterable->iterator();
    while ( < lengthLimit ||  < headCount) {
        if (!it->moveNext()) {
            return;
        }
        String next = __s("${it.current}");
        parts->add(next);
        length += next->length + overhead;
        count++;
    }
    String penultimateString;
    String ultimateString;
    if (!it->moveNext()) {
        if (count <= headCount + tailCount) {
            return;
        }
        ultimateString = parts->removeLast();
        penultimateString = parts->removeLast();
    } else {
        Object penultimate = it->current();
        count++;
        if (!it->moveNext()) {
            if (count <= headCount + 1) {
                parts->add(__s("$penultimate"));
                return;
            }
            ultimateString = __s("$penultimate");
            penultimateString = parts->removeLast();
            length += ultimateString->length + overhead;
        } else {
            Object ultimate = it->current();
            count++;
            assert( < maxCount);
            while (it->moveNext()) {
                penultimate = ultimate;
                ultimate = it->current();
                count++;
                if (count > maxCount) {
                    while (length > lengthLimit - ellipsisSize - overhead && count > headCount) {
                        length -= parts->removeLast()->length + overhead;
                        count--;
                    }
                    parts->add(__s("..."));
                    return;
                }
            }
            penultimateString = __s("$penultimate");
            ultimateString = __s("$ultimate");
            length += ultimateString->length + penultimateString->length + 2 * overhead;
        }
    }
    String elision;
    if (count > parts->length + tailCount) {
        elision = __s("...");
        length += ellipsisSize + overhead;
    }
    while (length > lengthLimit && parts->length > headCount) {
        length -= parts->removeLast()->length + overhead;
        if (elision == nullptr) {
            elision = __s("...");
            length += ellipsisSize + overhead;
        }
    }
    if (elision != nullptr) {
        parts->add(elision);
    }
    parts->add(penultimateString);
    parts->add(ultimateString);
}
