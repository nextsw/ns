#include "iterable.hpp"
template<typename E> void IterableCls<E>::generate(int count, E generator(int index) ) {
    if (count <= 0)     {
        return <E>make<EmptyIterableCls>();
    }
    return <E>make<_GeneratorIterableCls>(count, generator);
}

template<typename E> Iterable<T> IterableCls<E>::castFromtemplate<typename S, typename T> (Iterable<S> source) {
    return <S, T>make<CastIterableCls>(source);
}

template<typename E> Iterable<R> IterableCls<E>::casttemplate<typename R> () {
    return IterableCls-><E, R>castFrom(this);
}

template<typename E> Iterable<E> IterableCls<E>::followedBy(Iterable<E> other) {
    auto self = this;
    if (is<EfficientLengthIterable<E>>(self)) {
        return <E>firstEfficient(self, other);
    }
    return <E>make<FollowedByIterableCls>(this, other);
}

template<typename E> Iterable<T> IterableCls<E>::maptemplate<typename T> (T toElement(E e) ) {
    return <E, T>make<MappedIterableCls>(this, toElement);
}

template<typename E> Iterable<E> IterableCls<E>::where(bool test(E element) ) {
    return <E>make<WhereIterableCls>(this, test);
}

template<typename E> Iterable<T> IterableCls<E>::whereTypetemplate<typename T> () {
    return <T>make<WhereTypeIterableCls>(this);
}

template<typename E> Iterable<T> IterableCls<E>::expandtemplate<typename T> (Iterable<T> toElements(E element) ) {
    return <E, T>make<ExpandIterableCls>(this, toElements);
}

template<typename E> bool IterableCls<E>::contains(Object element) {
    for (E e : this) {
        if (e == element)         {
            return true;
        }
    }
    return false;
}

template<typename E> void IterableCls<E>::forEach(void action(E element) ) {
    for (E element : this)     {
        action(element);
    }
}

template<typename E> E IterableCls<E>::reduce(E combine(E element, E value) ) {
    Iterator<E> iterator = this->iterator;
    if (!iterator()->moveNext()) {
        ;
    }
    E value = iterator()->current();
    while (iterator()->moveNext()) {
        value = combine(value, iterator()->current());
    }
    return value;
}

template<typename E> T IterableCls<E>::foldtemplate<typename T> (T combine(E element, T previousValue) , T initialValue) {
    auto value = initialValue;
    for (E element : this)     {
        value = combine(value, element);
    }
    return value;
}

template<typename E> bool IterableCls<E>::every(bool test(E element) ) {
    for (E element : this) {
        if (!test(element))         {
            return false;
        }
    }
    return true;
}

template<typename E> String IterableCls<E>::join(String separator) {
    Iterator<E> iterator = this->iterator;
    if (!iterator()->moveNext())     {
        return __s("");
    }
    StringBuffer buffer = make<StringBufferCls>();
    if (separator == nullptr || separator == __s("")) {
        do {
            buffer->write(iterator()->current()->toString());
        } while (iterator()->moveNext());
    } else {
        buffer->write(iterator()->current()->toString());
        while (iterator()->moveNext()) {
            buffer->write(separator);
            buffer->write(iterator()->current()->toString());
        }
    }
    return buffer->toString();
}

template<typename E> bool IterableCls<E>::any(bool test(E element) ) {
    for (E element : this) {
        if (test(element))         {
            return true;
        }
    }
    return false;
}

template<typename E> List<E> IterableCls<E>::toList(bool growable) {
    return <E>of(thisgrowable);
}

template<typename E> Set<E> IterableCls<E>::toSet() {
    return <E>of(this);
}

template<typename E> int IterableCls<E>::length() {
    assert(!is<EfficientLengthIterable>(this));
    int count = 0;
    Iterator it = iterator();
    while (it->moveNext()) {
        count++;
    }
    return count;
}

template<typename E> bool IterableCls<E>::isEmpty() {
    return !iterator()->moveNext();
}

template<typename E> bool IterableCls<E>::isNotEmpty() {
    return !isEmpty();
}

template<typename E> Iterable<E> IterableCls<E>::take(int count) {
    return <E>make<TakeIterableCls>(this, count);
}

template<typename E> Iterable<E> IterableCls<E>::takeWhile(bool test(E value) ) {
    return <E>make<TakeWhileIterableCls>(this, test);
}

template<typename E> Iterable<E> IterableCls<E>::skip(int count) {
    return <E>make<SkipIterableCls>(this, count);
}

template<typename E> Iterable<E> IterableCls<E>::skipWhile(bool test(E value) ) {
    return <E>make<SkipWhileIterableCls>(this, test);
}

template<typename E> E IterableCls<E>::first() {
    Iterator<E> it = iterator();
    if (!it->moveNext()) {
        ;
    }
    return it->current;
}

template<typename E> E IterableCls<E>::last() {
    Iterator<E> it = iterator();
    if (!it->moveNext()) {
        ;
    }
    E result;
    do {
        result = it->current;
    } while (it->moveNext());
    return result;
}

template<typename E> E IterableCls<E>::single() {
    Iterator<E> it = iterator();
    if (!it->moveNext())     {
        ;
    }
    E result = it->current;
    if (it->moveNext())     {
        ;
    }
    return result;
}

template<typename E> E IterableCls<E>::firstWhere(E orElse() , bool test(E element) ) {
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

template<typename E> E IterableCls<E>::lastWhere(E orElse() , bool test(E element) ) {
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

template<typename E> E IterableCls<E>::singleWhere(E orElse() , bool test(E element) ) {
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

template<typename E> E IterableCls<E>::elementAt(int index) {
    RangeErrorCls->checkNotNegative(index, __s("index"));
    int elementIndex = 0;
    for (E element : this) {
        if (index == elementIndex)         {
            return element;
        }
        elementIndex++;
    }
    ;
}

template<typename E> String IterableCls<E>::toString() {
    return IterableBaseCls->iterableToShortString(this, __s("("), __s(")"));
}

template<typename E> E _GeneratorIterableCls<E>::elementAt(int index) {
    RangeErrorCls->checkValidIndex(index, this);
    return _generator(index);
}

template<typename E> _GeneratorIterableCls<E>::_GeneratorIterableCls(E generator(int index) , int length) {
    {
        _generator = generator or (as<E Function(int )>(_id));
    }
}

template<typename E> int _GeneratorIterableCls<E>::_id(int n) {
    return n;
}
