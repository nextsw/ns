#include "iterable.hpp"
template<typename E>
void IterableCls<E>::generate(int count, std::function<E(int index)> generator) {
    if (count <= 0)     {
        return <E>make<EmptyIterableCls>();
    }
    return <E>make<_GeneratorIterableCls>(count, generator);
}

template<typename E>
template<typename S, typename T>
Iterable<T> IterableCls<E>::castFrom(Iterable<S> source) {
    return <S, T>make<CastIterableCls>(source);
}

template<typename E>
template<typename R>
Iterable<R> IterableCls<E>::cast() {
    return IterableCls-><E, R>castFrom(this);
}

template<typename E>
Iterable<E> IterableCls<E>::followedBy(Iterable<E> other) {
    auto self = this;
    if (is<EfficientLengthIterable<E>>(self)) {
        return <E>firstEfficient(as<EfficientLengthIterableCls>(self), other);
    }
    return <E>make<FollowedByIterableCls>(this, other);
}

template<typename E>
template<typename T>
Iterable<T> IterableCls<E>::map(std::function<T(E e)> toElement) {
    return <E, T>make<MappedIterableCls>(this, toElement);
}

template<typename E>
Iterable<E> IterableCls<E>::where(std::function<bool(E element)> test) {
    return <E>make<WhereIterableCls>(this, test);
}

template<typename E>
template<typename T>
Iterable<T> IterableCls<E>::whereType() {
    return <T>make<WhereTypeIterableCls>(this);
}

template<typename E>
template<typename T>
Iterable<T> IterableCls<E>::expand(std::function<Iterable<T>(E element)> toElements) {
    return <E, T>make<ExpandIterableCls>(this, toElements);
}

template<typename E>
bool IterableCls<E>::contains(Object element) {
    for (E e : this) {
        if (e == element)         {
            return true;
        }
    }
    return false;
}

template<typename E>
void IterableCls<E>::forEach(std::function<void(E element)> action) {
    for (E element : this)     {
        action(element);
    }
}

template<typename E>
E IterableCls<E>::reduce(std::function<E(E element, E value)> combine) {
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
T IterableCls<E>::fold(std::function<T(E element, T previousValue)> combine, T initialValue) {
    auto value = initialValue;
    for (E element : this)     {
        value = combine(value, element);
    }
    return value;
}

template<typename E>
bool IterableCls<E>::every(std::function<bool(E element)> test) {
    for (E element : this) {
        if (!test(element))         {
            return false;
        }
    }
    return true;
}

template<typename E>
String IterableCls<E>::join(String separator) {
    Iterator<E> iterator = this->iterator();
    if (!iterator->moveNext())     {
        return __s("");
    }
    StringBuffer buffer = make<StringBufferCls>();
    if (separator == nullptr || separator == __s("")) {
        do {
            buffer->write(iterator->current()->toString());
        } while (iterator->moveNext());
    } else {
        buffer->write(iterator->current()->toString());
        while (iterator->moveNext()) {
            buffer->write(separator);
            buffer->write(iterator->current()->toString());
        }
    }
    return buffer->toString();
}

template<typename E>
bool IterableCls<E>::any(std::function<bool(E element)> test) {
    for (E element : this) {
        if (test(element))         {
            return true;
        }
    }
    return false;
}

template<typename E>
List<E> IterableCls<E>::toList(bool growable) {
    return <E>of(thisgrowable);
}

template<typename E>
Set<E> IterableCls<E>::toSet() {
    return <E>of(this);
}

template<typename E>
int IterableCls<E>::length() {
    assert(!is<EfficientLengthIterable>(this));
    int count = 0;
    Iterator it = iterator();
    while (it->moveNext()) {
        count++;
    }
    return count;
}

template<typename E>
bool IterableCls<E>::isEmpty() {
    return !iterator()->moveNext();
}

template<typename E>
bool IterableCls<E>::isNotEmpty() {
    return !isEmpty();
}

template<typename E>
Iterable<E> IterableCls<E>::take(int count) {
    return <E>make<TakeIterableCls>(this, count);
}

template<typename E>
Iterable<E> IterableCls<E>::takeWhile(std::function<bool(E value)> test) {
    return <E>make<TakeWhileIterableCls>(this, test);
}

template<typename E>
Iterable<E> IterableCls<E>::skip(int count) {
    return <E>make<SkipIterableCls>(this, count);
}

template<typename E>
Iterable<E> IterableCls<E>::skipWhile(std::function<bool(E value)> test) {
    return <E>make<SkipWhileIterableCls>(this, test);
}

template<typename E>
E IterableCls<E>::first() {
    Iterator<E> it = iterator();
    if (!it->moveNext()) {
        throw IterableElementErrorCls->noElement();
    }
    return it->current();
}

template<typename E>
E IterableCls<E>::last() {
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
E IterableCls<E>::single() {
    Iterator<E> it = iterator();
    if (!it->moveNext())     {
        throw IterableElementErrorCls->noElement();
    }
    E result = it->current();
    if (it->moveNext())     {
        throw IterableElementErrorCls->tooMany();
    }
    return result;
}

template<typename E>
E IterableCls<E>::firstWhere(std::function<E()> orElse, std::function<bool(E element)> test) {
    for (E element : this) {
        if (test(element))         {
            return element;
        }
    }
    if (orElse != nullptr)     {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E IterableCls<E>::lastWhere(std::function<E()> orElse, std::function<bool(E element)> test) {
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
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E IterableCls<E>::singleWhere(std::function<E()> orElse, std::function<bool(E element)> test) {
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
    if (foundMatching)     {
        return result;
    }
    if (orElse != nullptr)     {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E IterableCls<E>::elementAt(int index) {
    RangeErrorCls->checkNotNegative(index, __s("index"));
    int elementIndex = 0;
    for (E element : this) {
        if (index == elementIndex)         {
            return element;
        }
        elementIndex++;
    }
    throw RangeErrorCls->index(index, this, __s("index"), nullptr, elementIndex);
}

template<typename E>
String IterableCls<E>::toString() {
    return IterableBaseCls->iterableToShortString(this, __s("("), __s(")"));
}

template<typename E>
E _GeneratorIterableCls<E>::elementAt(int index) {
    RangeErrorCls->checkValidIndex(index, this);
    return _generator(index);
}

template<typename E>
_GeneratorIterableCls<E>::_GeneratorIterableCls(std::function<E(int index)> generator, int length) {
    {
        _generator = generator or (as<std::function<E(int )>>(_id));
    }
}

template<typename E>
int _GeneratorIterableCls<E>::_id(int n) {
    return n;
}
