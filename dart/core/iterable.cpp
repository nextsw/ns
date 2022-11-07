#include "iterable.hpp"
void Iterable::generate(int count, FunctionType generator) {
    if (count <= 0)     {
        return <E>EmptyIterable();
    }
    return <E>_GeneratorIterable(count, generator);
}

Iterable<T> Iterable::castFrom<S, T>(Iterable<S> source) {
    return <S, T>CastIterable(source);
}

Iterable<R> Iterable::cast<R>() {
    return Iterable.<E, R>castFrom(this);
}

Iterable<E> Iterable::followedBy(Iterable<E> other) {
    auto self = this;
    if (self is EfficientLengthIterable<E>) {
        return <E>firstEfficient(self, other);
    }
    return <E>FollowedByIterable(this, other);
}

Iterable<T> Iterable::map<T>(FunctionType toElement) {
    return <E, T>MappedIterable(this, toElement);
}

Iterable<E> Iterable::where(FunctionType test) {
    return <E>WhereIterable(this, test);
}

Iterable<T> Iterable::whereType<T>() {
    return <T>WhereTypeIterable(this);
}

Iterable<T> Iterable::expand<T>(FunctionType toElements) {
    return <E, T>ExpandIterable(this, toElements);
}

bool Iterable::contains(Object element) {
    for (E e : this) {
        if (e == element)         {
            return true;
        }
    }
    return false;
}

void Iterable::forEach(FunctionType action) {
    for (E element : this)     {
        action(element);
    }
}

E Iterable::reduce(FunctionType combine) {
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

T Iterable::fold<T>(FunctionType combine, T initialValue) {
    auto value = initialValue;
    for (E element : this)     {
        value = combine(value, element);
    }
    return value;
}

bool Iterable::every(FunctionType test) {
    for (E element : this) {
        if (!test(element))         {
            return false;
        }
    }
    return true;
}

String Iterable::join(String separator) {
    Iterator<E> iterator = this.iterator;
    if (!iterator.moveNext())     {
        return "";
    }
    StringBuffer buffer = StringBuffer();
    if (separator == nullptr || separator == "") {
        do {
            buffer.write(iterator.current.toString());
        } while (iterator.moveNext());
    } else {
        buffer.write(iterator.current.toString());
        while (iterator.moveNext()) {
            buffer.write(separator);
            buffer.write(iterator.current.toString());
        }
    }
    return buffer.toString();
}

bool Iterable::any(FunctionType test) {
    for (E element : this) {
        if (test(element))         {
            return true;
        }
    }
    return false;
}

List<E> Iterable::toList(bool growable) {
    return <E>of(thisgrowable);
}

Set<E> Iterable::toSet() {
    return <E>of(this);
}

int Iterable::length() {
    assert(this is! EfficientLengthIterable);
    int count = 0;
    Iterator it = iterator;
    while (it.moveNext()) {
        count++;
    }
    return count;
}

bool Iterable::isEmpty() {
    return !iterator.moveNext();
}

bool Iterable::isNotEmpty() {
    return !isEmpty;
}

Iterable<E> Iterable::take(int count) {
    return <E>TakeIterable(this, count);
}

Iterable<E> Iterable::takeWhile(FunctionType test) {
    return <E>TakeWhileIterable(this, test);
}

Iterable<E> Iterable::skip(int count) {
    return <E>SkipIterable(this, count);
}

Iterable<E> Iterable::skipWhile(FunctionType test) {
    return <E>SkipWhileIterable(this, test);
}

E Iterable::first() {
    Iterator<E> it = iterator;
    if (!it.moveNext()) {
        ;
    }
    return it.current;
}

E Iterable::last() {
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

E Iterable::single() {
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

E Iterable::firstWhere(FunctionType orElse, FunctionType test) {
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

E Iterable::lastWhere(FunctionType orElse, FunctionType test) {
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

E Iterable::singleWhere(FunctionType orElse, FunctionType test) {
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

E Iterable::elementAt(int index) {
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

String Iterable::toString() {
    return IterableBase.iterableToShortString(this, "(", ")");
}

E _GeneratorIterable::elementAt(int index) {
    RangeError.checkValidIndex(index, this);
    return _generator(index);
}

_GeneratorIterable::_GeneratorIterable(FunctionType generator, int length) {
    {
        _generator = generator ?? (();
    }
}

int _GeneratorIterable::_id(int n) {
    return n;
}
