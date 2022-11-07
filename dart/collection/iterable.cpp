#include "iterable.hpp"
Iterable<R> IterableMixin::cast<R>() {
    return Iterable.<E, R>castFrom(this);
}

Iterable<T> IterableMixin::map<T>(FunctionType toElement) {
    return <E, T>MappedIterable(this, toElement);
}

Iterable<E> IterableMixin::where(FunctionType test) {
    return <E>WhereIterable(this, test);
}

Iterable<T> IterableMixin::whereType<T>() {
    return <T>WhereTypeIterable(this);
}

Iterable<T> IterableMixin::expand<T>(FunctionType toElements) {
    return <E, T>ExpandIterable(this, toElements);
}

Iterable<E> IterableMixin::followedBy(Iterable<E> other) {
    Iterable<E> self = this;
    if (self is EfficientLengthIterable<E>) {
        return <E>firstEfficient(self, other);
    }
    return <E>FollowedByIterable(this, other);
}

bool IterableMixin::contains(Object element) {
    for (E e : this) {
        if (e == element)         {
            return true;
        }
    }
    return false;
}

void IterableMixin::forEach(FunctionType action) {
    for (E element : this)     {
        action(element);
    }
}

E IterableMixin::reduce(FunctionType combine) {
    Iterator<E> iterator = this.iterator;
    if (!iterator.moveNext()) {
        ;
    }
    E value = iterator.current;
    while (iterator.moveNext()) {
        value = combine(value, iterator.current);
    }
    return value;
}

T IterableMixin::fold<T>(FunctionType combine, T initialValue) {
    auto value = initialValue;
    for (E element : this)     {
        value = combine(value, element);
    }
    return value;
}

bool IterableMixin::every(FunctionType test) {
    for (E element : this) {
        if (!test(element))         {
            return false;
        }
    }
    return true;
}

String IterableMixin::join(String separator) {
    Iterator<E> iterator = this.iterator;
    if (!iterator.moveNext())     {
        return "";
    }
    StringBuffer buffer = StringBuffer();
    if (separator == nullptr || separator == "") {
        do {
            buffer.write("${iterator.current}");
        } while (iterator.moveNext());
    } else {
        buffer.write("${iterator.current}");
        while (iterator.moveNext()) {
            buffer.write(separator);
            buffer.write("${iterator.current}");
        }
    }
    return buffer.toString();
}

bool IterableMixin::any(FunctionType test) {
    for (E element : this) {
        if (test(element))         {
            return true;
        }
    }
    return false;
}

List<E> IterableMixin::toList(bool growable) {
    return <E>from(thisgrowable);
}

Set<E> IterableMixin::toSet() {
    return <E>from(this);
}

int IterableMixin::length() {
    assert(this is! EfficientLengthIterable);
    int count = 0;
    Iterator it = iterator;
    while (it.moveNext()) {
        count++;
    }
    return count;
}

bool IterableMixin::isEmpty() {
    return !iterator.moveNext();
}

bool IterableMixin::isNotEmpty() {
    return !isEmpty;
}

Iterable<E> IterableMixin::take(int count) {
    return <E>TakeIterable(this, count);
}

Iterable<E> IterableMixin::takeWhile(FunctionType test) {
    return <E>TakeWhileIterable(this, test);
}

Iterable<E> IterableMixin::skip(int count) {
    return <E>SkipIterable(this, count);
}

Iterable<E> IterableMixin::skipWhile(FunctionType test) {
    return <E>SkipWhileIterable(this, test);
}

E IterableMixin::first() {
    Iterator<E> it = iterator;
    if (!it.moveNext()) {
        ;
    }
    return it.current;
}

E IterableMixin::last() {
    Iterator<E> it = iterator;
    if (!it.moveNext()) {
        ;
    }
    E result;
    do {
        result = it.current;
    } while (it.moveNext());
    return result;
}

E IterableMixin::single() {
    Iterator<E> it = iterator;
    if (!it.moveNext())     {
        ;
    }
    E result = it.current;
    if (it.moveNext())     {
        ;
    }
    return result;
}

E IterableMixin::firstWhere(FunctionType orElse, FunctionType test) {
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

E IterableMixin::lastWhere(FunctionType orElse, FunctionType test) {
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

E IterableMixin::singleWhere(FunctionType orElse, FunctionType test) {
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

E IterableMixin::elementAt(int index) {
    checkNotNullable(index, "index");
    RangeError.checkNotNegative(index, "index");
    int elementIndex = 0;
    for (E element : this) {
        if (index == elementIndex)         {
            return element;
        }
        elementIndex++;
    }
    ;
}

String IterableMixin::toString() {
    return IterableBase.iterableToShortString(this, "(", ")");
}

String IterableBase::iterableToShortString(Iterable iterable, String leftDelimiter, String rightDelimiter) {
    if (_isToStringVisiting(iterable)) {
        if (leftDelimiter == "(" && rightDelimiter == ")") {
            return "(...)";
        }
        return "$leftDelimiter...$rightDelimiter";
    }
    List<String> parts = ;
    _toStringVisiting.add(iterable);
    ;
    return ().toString();
}

String IterableBase::iterableToFullString(Iterable iterable, String leftDelimiter, String rightDelimiter) {
    if (_isToStringVisiting(iterable)) {
        return "$leftDelimiter...$rightDelimiter";
    }
    StringBuffer buffer = StringBuffer(leftDelimiter);
    _toStringVisiting.add(iterable);
    ;
    buffer.write(rightDelimiter);
    return buffer.toString();
}

bool _isToStringVisiting(Object o) {
    for (;  < _toStringVisiting.length; i++) {
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
    Iterator<Object> it = iterable.iterator;
    while ( < lengthLimit ||  < headCount) {
        if (!it.moveNext())         {
            return;
        }
        String next = "${it.current}";
        parts.add(next);
        length = next.length + overhead;
        count++;
    }
    String penultimateString;
    String ultimateString;
    if (!it.moveNext()) {
        if (count <= headCount + tailCount)         {
            return;
        }
        ultimateString = parts.removeLast();
        penultimateString = parts.removeLast();
    } else {
        Object penultimate = it.current;
        count++;
        if (!it.moveNext()) {
            if (count <= headCount + 1) {
                parts.add("$penultimate");
                return;
            }
            ultimateString = "$penultimate";
            penultimateString = parts.removeLast();
            length = ultimateString.length + overhead;
        } else {
            Object ultimate = it.current;
            count++;
            assert( < maxCount);
            while (it.moveNext()) {
                penultimate = ultimate;
                ultimate = it.current;
                count++;
                if (count > maxCount) {
                    while (length > lengthLimit - ellipsisSize - overhead && count > headCount) {
                        length = parts.removeLast().length + overhead;
                        count--;
                    }
                    parts.add("...");
                    return;
                }
            }
            penultimateString = "$penultimate";
            ultimateString = "$ultimate";
            length = ultimateString.length + penultimateString.length + 2 * overhead;
        }
    }
    String elision;
    if (count > parts.length + tailCount) {
        elision = "...";
        length = ellipsisSize + overhead;
    }
    while (length > lengthLimit && parts.length > headCount) {
        length = parts.removeLast().length + overhead;
        if (elision == nullptr) {
            elision = "...";
            length = ellipsisSize + overhead;
        }
    }
    if (elision != nullptr) {
        parts.add(elision);
    }
    parts.add(penultimateString);
    parts.add(ultimateString);
}
