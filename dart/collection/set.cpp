#include "set.hpp"
bool SetMixin::isEmpty() {
    return length == 0;
}

bool SetMixin::isNotEmpty() {
    return length != 0;
}

Set<R> SetMixin::cast<R>() {
    return Set.<E, R>castFrom(this);
}

Iterable<E> SetMixin::followedBy(Iterable<E> other) {
    return <E>firstEfficient(this, other);
}

Iterable<T> SetMixin::whereType<T>() {
    return <T>WhereTypeIterable(this);
}

void SetMixin::clear() {
    removeAll(toList());
}

void SetMixin::addAll(Iterable<E> elements) {
    for (E element : elements)     {
        add(element);
    }
}

void SetMixin::removeAll(Iterable<Object> elements) {
    for (Object element : elements)     {
        remove(element);
    }
}

void SetMixin::retainAll(Iterable<Object> elements) {
    Set<E> toRemove = toSet();
    for (Object o : elements) {
        toRemove.remove(o);
    }
    removeAll(toRemove);
}

void SetMixin::removeWhere(FunctionType test) {
    List<Object> toRemove = ;
    for (E element : this) {
        if (test(element))         {
            toRemove.add(element);
        }
    }
    removeAll(toRemove);
}

void SetMixin::retainWhere(FunctionType test) {
    List<Object> toRemove = ;
    for (E element : this) {
        if (!test(element))         {
            toRemove.add(element);
        }
    }
    removeAll(toRemove);
}

bool SetMixin::containsAll(Iterable<Object> other) {
    for (auto o : other) {
        if (!contains(o))         {
            return false;
        }
    }
    return true;
}

Set<E> SetMixin::union(Set<E> other) {
    return ;
}

Set<E> SetMixin::intersection(Set<Object> other) {
    Set<E> result = toSet();
    for (E element : this) {
        if (!other.contains(element))         {
            result.remove(element);
        }
    }
    return result;
}

Set<E> SetMixin::difference(Set<Object> other) {
    Set<E> result = toSet();
    for (E element : this) {
        if (other.contains(element))         {
            result.remove(element);
        }
    }
    return result;
}

List<E> SetMixin::toList(bool growable) {
    return <E>of(thisgrowable);
}

Iterable<T> SetMixin::map<T>(FunctionType f) {
    return <E, T>EfficientLengthMappedIterable(this, f);
}

E SetMixin::single() {
    if (length > 1)     {
        ;
    }
    Iterator<E> it = iterator;
    if (!it.moveNext())     {
        ;
    }
    E result = it.current;
    return result;
}

String SetMixin::toString() {
    return IterableBase.iterableToFullString(this, "{", "}");
}

Iterable<E> SetMixin::where(FunctionType f) {
    return <E>WhereIterable(this, f);
}

Iterable<T> SetMixin::expand<T>(FunctionType f) {
    return <E, T>ExpandIterable(this, f);
}

void SetMixin::forEach(FunctionType f) {
    for (E element : this)     {
        f(element);
    }
}

E SetMixin::reduce(FunctionType combine) {
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

T SetMixin::fold<T>(FunctionType combine, T initialValue) {
    auto value = initialValue;
    for (E element : this)     {
        value = combine(value, element);
    }
    return value;
}

bool SetMixin::every(FunctionType f) {
    for (E element : this) {
        if (!f(element))         {
            return false;
        }
    }
    return true;
}

String SetMixin::join(String separator) {
    Iterator<E> iterator = this.iterator;
    if (!iterator.moveNext())     {
        return "";
    }
    StringBuffer buffer = StringBuffer();
    if (separator == nullptr || separator == "") {
        do {
            buffer.write(iterator.current);
        } while (iterator.moveNext());
    } else {
        buffer.write(iterator.current);
        while (iterator.moveNext()) {
            buffer.write(separator);
            buffer.write(iterator.current);
        }
    }
    return buffer.toString();
}

bool SetMixin::any(FunctionType test) {
    for (E element : this) {
        if (test(element))         {
            return true;
        }
    }
    return false;
}

Iterable<E> SetMixin::take(int n) {
    return <E>TakeIterable(this, n);
}

Iterable<E> SetMixin::takeWhile(FunctionType test) {
    return <E>TakeWhileIterable(this, test);
}

Iterable<E> SetMixin::skip(int n) {
    return <E>SkipIterable(this, n);
}

Iterable<E> SetMixin::skipWhile(FunctionType test) {
    return <E>SkipWhileIterable(this, test);
}

E SetMixin::first() {
    Iterator<E> it = iterator;
    if (!it.moveNext()) {
        ;
    }
    return it.current;
}

E SetMixin::last() {
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

E SetMixin::firstWhere(FunctionType orElse, FunctionType test) {
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

E SetMixin::lastWhere(FunctionType orElse, FunctionType test) {
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

E SetMixin::singleWhere(FunctionType orElse, FunctionType test) {
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

E SetMixin::elementAt(int index) {
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

String SetBase::setToString(Set set) {
    return IterableBase.iterableToFullString(set, "{", "}");
}

Set<R> _SetBase::cast<R>() {
    return Set.<E, R>castFrom(this_newSimilarSet);
}

Set<E> _SetBase::difference(Set<Object> other) {
    Set<E> result = _newSet();
    for (auto element : this) {
        if (!other.contains(element))         {
            result.add(element);
        }
    }
    return result;
}

Set<E> _SetBase::intersection(Set<Object> other) {
    Set<E> result = _newSet();
    for (auto element : this) {
        if (other.contains(element))         {
            result.add(element);
        }
    }
    return result;
}

Set<E> _SetBase::toSet() {
    return ;
}

bool _UnmodifiableSetMixin::add(E value) {
    return _throwUnmodifiable();
}

void _UnmodifiableSetMixin::clear() {
    return _throwUnmodifiable();
}

void _UnmodifiableSetMixin::addAll(Iterable<E> elements) {
    return _throwUnmodifiable();
}

void _UnmodifiableSetMixin::removeAll(Iterable<Object> elements) {
    return _throwUnmodifiable();
}

void _UnmodifiableSetMixin::retainAll(Iterable<Object> elements) {
    return _throwUnmodifiable();
}

void _UnmodifiableSetMixin::removeWhere(FunctionType test) {
    return _throwUnmodifiable();
}

void _UnmodifiableSetMixin::retainWhere(FunctionType test) {
    return _throwUnmodifiable();
}

bool _UnmodifiableSetMixin::remove(Object value) {
    return _throwUnmodifiable();
}

Never _UnmodifiableSetMixin::_throwUnmodifiable() {
    ;
}

bool _UnmodifiableSet::contains(Object element) {
    return _map.containsKey(element);
}

Iterator<E> _UnmodifiableSet::iterator() {
    return _map.keys.iterator;
}

int _UnmodifiableSet::length() {
    return _map.length;
}

E _UnmodifiableSet::lookup(Object element) {
    for (auto key : _map.keys) {
        if (key == element)         {
            return key;
        }
    }
    return nullptr;
}

Set<E> _UnmodifiableSet::_newSet() {
    return <E>LinkedHashSet();
}

Set<R> _UnmodifiableSet::_newSimilarSet<R>() {
    return <R>LinkedHashSet();
}

UnmodifiableSetView::UnmodifiableSetView(Set<E> source) {
    {
        _source = source;
    }
}

bool UnmodifiableSetView::contains(Object element) {
    return _source.contains(element);
}

E UnmodifiableSetView::lookup(Object element) {
    return _source.lookup(element);
}

int UnmodifiableSetView::length() {
    return _source.length;
}

Iterator<E> UnmodifiableSetView::iterator() {
    return _source.iterator;
}

Set<E> UnmodifiableSetView::toSet() {
    return _source.toSet();
}
