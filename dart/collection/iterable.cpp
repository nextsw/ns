#include "iterable.hpp"
template<typename E> Iterable<R> IterableMixinCls<E>::casttemplate<typename R> () {
    return IterableCls-><E, R>castFrom(this);
}

template<typename E> Iterable<T> IterableMixinCls<E>::maptemplate<typename T> (T toElement(E element) ) {
    return <E, T>make<MappedIterableCls>(this, toElement);
}

template<typename E> Iterable<E> IterableMixinCls<E>::where(bool test(E element) ) {
    return <E>make<WhereIterableCls>(this, test);
}

template<typename E> Iterable<T> IterableMixinCls<E>::whereTypetemplate<typename T> () {
    return <T>make<WhereTypeIterableCls>(this);
}

template<typename E> Iterable<T> IterableMixinCls<E>::expandtemplate<typename T> (Iterable<T> toElements(E element) ) {
    return <E, T>make<ExpandIterableCls>(this, toElements);
}

template<typename E> Iterable<E> IterableMixinCls<E>::followedBy(Iterable<E> other) {
    auto _c1 = <E>make<HashSetCls>();_c1.addAll(elements);Iterable<E> self = this;
    if (self is EfficientLengthIterable<E>) {
        return <E>firstEfficient(self, other);
    }
    return <E>make<FollowedByIterableCls>(this, other);
}

template<typename E> bool IterableMixinCls<E>::contains(Object element) {
    for (E e : this) {
        if (e == element)         {
            return true;
        }
    }
    return false;
}

template<typename E> void IterableMixinCls<E>::forEach(void action(E element) ) {
    for (E element : this)     {
        action(element);
    }
}

template<typename E> E IterableMixinCls<E>::reduce(E combine(E element, E value) ) {
    Iterator<E> iterator = this->iterator;
    if (!iterator->moveNext()) {
        ;
    }
    E value = iterator->current;
    while (iterator->moveNext()) {
        value = combine(value, iterator->current);
    }
    return value;
}

template<typename E> T IterableMixinCls<E>::foldtemplate<typename T> (T combine(E element, T previousValue) , T initialValue) {
    auto value = initialValue;
    for (E element : this)     {
        value = combine(value, element);
    }
    return value;
}

template<typename E> bool IterableMixinCls<E>::every(bool test(E element) ) {
    for (E element : this) {
        if (!test(element))         {
            return false;
        }
    }
    return true;
}

template<typename E> String IterableMixinCls<E>::join(String separator) {
    Iterator<E> iterator = this->iterator;
    if (!iterator->moveNext())     {
        return "";
    }
    StringBuffer buffer = make<StringBufferCls>();
    if (separator == nullptr || separator == "") {
        do {
            buffer->write("${iterator.current}");
        } while (iterator->moveNext());
    } else {
        buffer->write("${iterator.current}");
        while (iterator->moveNext()) {
            buffer->write(separator);
            buffer->write("${iterator.current}");
        }
    }
    return buffer->toString();
}

template<typename E> bool IterableMixinCls<E>::any(bool test(E element) ) {
    for (E element : this) {
        if (test(element))         {
            return true;
        }
    }
    return false;
}

template<typename E> List<E> IterableMixinCls<E>::toList(bool growable) {
    return <E>from(thisgrowable);
}

template<typename E> Set<E> IterableMixinCls<E>::toSet() {
    return <E>from(this);
}

template<typename E> int IterableMixinCls<E>::length() {
    assert(this is! EfficientLengthIterable);
    int count = 0;
    Iterator it = iterator;
    while (it->moveNext()) {
        count++;
    }
    return count;
}

template<typename E> bool IterableMixinCls<E>::isEmpty() {
    return !iterator->moveNext();
}

template<typename E> bool IterableMixinCls<E>::isNotEmpty() {
    return !isEmpty;
}

template<typename E> Iterable<E> IterableMixinCls<E>::take(int count) {
    return <E>make<TakeIterableCls>(this, count);
}

template<typename E> Iterable<E> IterableMixinCls<E>::takeWhile(bool test(E value) ) {
    return <E>make<TakeWhileIterableCls>(this, test);
}

template<typename E> Iterable<E> IterableMixinCls<E>::skip(int count) {
    return <E>make<SkipIterableCls>(this, count);
}

template<typename E> Iterable<E> IterableMixinCls<E>::skipWhile(bool test(E value) ) {
    return <E>make<SkipWhileIterableCls>(this, test);
}

template<typename E> E IterableMixinCls<E>::first() {
    Iterator<E> it = iterator;
    if (!it->moveNext()) {
        ;
    }
    return it->current;
}

template<typename E> E IterableMixinCls<E>::last() {
    Iterator<E> it = iterator;
    if (!it->moveNext()) {
        ;
    }
    E result;
    do {
        result = it->current;
    } while (it->moveNext());
    return result;
}

template<typename E> E IterableMixinCls<E>::single() {
    Iterator<E> it = iterator;
    if (!it->moveNext())     {
        ;
    }
    E result = it->current;
    if (it->moveNext())     {
        ;
    }
    return result;
}

template<typename E> E IterableMixinCls<E>::firstWhere(E orElse() , bool test(E value) ) {
    for (E element : this) {
        if (test(element))         {
            return element;
        }
    }
    if (orElse != nullptr)     {
        return orElse();
    }
    ;
}

template<typename E> E IterableMixinCls<E>::lastWhere(E orElse() , bool test(E value) ) {
    E result;
    bool foundMatching = false;
    for (E element : this) {
        if (test(element)) {
            result = element;
            foundMatching = true;
        }
    }
    if (foundMatching)     {
        return result;
    }
    if (orElse != nullptr)     {
        return orElse();
    }
    ;
}

template<typename E> E IterableMixinCls<E>::singleWhere(E orElse() , bool test(E element) ) {
    E result;
    bool foundMatching = false;
    for (E element : this) {
        if (test(element)) {
            if (foundMatching) {
                ;
            }
            result = element;
            foundMatching = true;
        }
    }
    if (foundMatching)     {
        return result;
    }
    if (orElse != nullptr)     {
        return orElse();
    }
    ;
}

template<typename E> E IterableMixinCls<E>::elementAt(int index) {
    checkNotNullable(index, "index");
    RangeErrorCls->checkNotNegative(index, "index");
    int elementIndex = 0;
    for (E element : this) {
        if (index == elementIndex)         {
            return element;
        }
        elementIndex++;
    }
    ;
}

template<typename E> String IterableMixinCls<E>::toString() {
    return IterableBaseCls->iterableToShortString(this, "(", ")");
}

template<typename E> String IterableBaseCls<E>::iterableToShortString(Iterable iterable, String leftDelimiter, String rightDelimiter) {
    if (_isToStringVisiting(iterable)) {
        if (leftDelimiter == "(" && rightDelimiter == ")") {
            return "(...)";
        }
        return "$leftDelimiter...$rightDelimiter";
    }
    List<String> parts = makeList();
    _toStringVisiting->add(iterable);
    try {
        _iterablePartsToStrings(iterable, parts);
    } finally {
        assert(identical(_toStringVisiting->last, iterable));
        _toStringVisiting->removeLast();
    };
    auto _c1 = make<StringBufferCls>(leftDelimiter);_c1.auto _c2 = writeAll(parts, ", ");_c2.write(rightDelimiter);_c2;return (_c1)->toString();
}

template<typename E> String IterableBaseCls<E>::iterableToFullString(Iterable iterable, String leftDelimiter, String rightDelimiter) {
    if (_isToStringVisiting(iterable)) {
        return "$leftDelimiter...$rightDelimiter";
    }
    StringBuffer buffer = make<StringBufferCls>(leftDelimiter);
    _toStringVisiting->add(iterable);
    try {
        buffer->writeAll(iterable, ", ");
    } finally {
        assert(identical(_toStringVisiting->last, iterable));
        _toStringVisiting->removeLast();
    };
    buffer->write(rightDelimiter);
    return buffer->toString();
}

bool _isToStringVisiting(Object o) {
    for (;  < _toStringVisiting->length; i++) {
        if (identical(o, _toStringVisiting[i]))         {
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
    Iterator<Object> it = iterable->iterator;
    while ( < lengthLimit ||  < headCount) {
        if (!it->moveNext())         {
            return;
        }
        String next = "${it.current}";
        parts->add(next);
        length = next->length + overhead;
        count++;
    }
    String penultimateString;
    String ultimateString;
    if (!it->moveNext()) {
        if (count <= headCount + tailCount)         {
            return;
        }
        ultimateString = parts->removeLast();
        penultimateString = parts->removeLast();
    } else {
        Object penultimate = it->current;
        count++;
        if (!it->moveNext()) {
            if (count <= headCount + 1) {
                parts->add("$penultimate");
                return;
            }
            ultimateString = "$penultimate";
            penultimateString = parts->removeLast();
            length = ultimateString->length + overhead;
        } else {
            Object ultimate = it->current;
            count++;
            assert( < maxCount);
            while (it->moveNext()) {
                penultimate = ultimate;
                ultimate = it->current;
                count++;
                if (count > maxCount) {
                    while (length > lengthLimit - ellipsisSize - overhead && count > headCount) {
                        length = parts->removeLast()->length + overhead;
                        count--;
                    }
                    parts->add("...");
                    return;
                }
            }
            penultimateString = "$penultimate";
            ultimateString = "$ultimate";
            length = ultimateString->length + penultimateString->length + 2 * overhead;
        }
    }
    String elision;
    if (count > parts->length + tailCount) {
        elision = "...";
        length = ellipsisSize + overhead;
    }
    while (length > lengthLimit && parts->length > headCount) {
        length = parts->removeLast()->length + overhead;
        if (elision == nullptr) {
            elision = "...";
            length = ellipsisSize + overhead;
        }
    }
    if (elision != nullptr) {
        parts->add(elision);
    }
    parts->add(penultimateString);
    parts->add(ultimateString);
}
