#include "set.hpp"
template<typename E> bool SetMixinCls<E>::isEmpty() {
    return length == 0;
}

template<typename E> bool SetMixinCls<E>::isNotEmpty() {
    return length != 0;
}

template<typename E> Set<R> SetMixinCls<E>::casttemplate<typename R> () {
    return SetCls-><E, R>castFrom(this);
}

template<typename E> Iterable<E> SetMixinCls<E>::followedBy(Iterable<E> other) {
    return <E>firstEfficient(this, other);
}

template<typename E> Iterable<T> SetMixinCls<E>::whereTypetemplate<typename T> () {
    return <T>make<WhereTypeIterableCls>(this);
}

template<typename E> void SetMixinCls<E>::clear() {
    removeAll(toList());
}

template<typename E> void SetMixinCls<E>::addAll(Iterable<E> elements) {
    for (E element : elements)     {
        add(element);
    }
}

template<typename E> void SetMixinCls<E>::removeAll(Iterable<Object> elements) {
    for (Object element : elements)     {
        remove(element);
    }
}

template<typename E> void SetMixinCls<E>::retainAll(Iterable<Object> elements) {
    Set<E> toRemove = toSet();
    for (Object o : elements) {
        toRemove->remove(o);
    }
    removeAll(toRemove);
}

template<typename E> void SetMixinCls<E>::removeWhere(bool test(E element) ) {
    List<Object> toRemove = makeList();
    for (E element : this) {
        if (test(element))         {
            toRemove->add(element);
        }
    }
    removeAll(toRemove);
}

template<typename E> void SetMixinCls<E>::retainWhere(bool test(E element) ) {
    List<Object> toRemove = makeList();
    for (E element : this) {
        if (!test(element))         {
            toRemove->add(element);
        }
    }
    removeAll(toRemove);
}

template<typename E> bool SetMixinCls<E>::containsAll(Iterable<Object> other) {
    for (auto o : other) {
        if (!contains(o))         {
            return false;
        }
    }
    return true;
}

template<typename E> Set<E> SetMixinCls<E>::union(Set<E> other) {
    auto _c1 = toSet();_c1.addAll(other);return _c1;
}

template<typename E> Set<E> SetMixinCls<E>::intersection(Set<Object> other) {
    Set<E> result = toSet();
    for (E element : this) {
        if (!other->contains(element))         {
            result->remove(element);
        }
    }
    return result;
}

template<typename E> Set<E> SetMixinCls<E>::difference(Set<Object> other) {
    Set<E> result = toSet();
    for (E element : this) {
        if (other->contains(element))         {
            result->remove(element);
        }
    }
    return result;
}

template<typename E> List<E> SetMixinCls<E>::toList(bool growable) {
    return <E>of(thisgrowable);
}

template<typename E> Iterable<T> SetMixinCls<E>::maptemplate<typename T> (T f(E element) ) {
    return <E, T>make<EfficientLengthMappedIterableCls>(this, f);
}

template<typename E> E SetMixinCls<E>::single() {
    if (length > 1)     {
        ;
    }
    Iterator<E> it = iterator();
    if (!it->moveNext())     {
        ;
    }
    E result = it->current();
    return result;
}

template<typename E> String SetMixinCls<E>::toString() {
    return IterableBaseCls->iterableToFullString(this, __s("{"), __s("}"));
}

template<typename E> Iterable<E> SetMixinCls<E>::where(bool f(E element) ) {
    return <E>make<WhereIterableCls>(this, f);
}

template<typename E> Iterable<T> SetMixinCls<E>::expandtemplate<typename T> (Iterable<T> f(E element) ) {
    return <E, T>make<ExpandIterableCls>(this, f);
}

template<typename E> void SetMixinCls<E>::forEach(void f(E element) ) {
    for (E element : this)     {
        f(element);
    }
}

template<typename E> E SetMixinCls<E>::reduce(E combine(E element, E value) ) {
    Iterator<E> iterator = this->iterator();
    if (!iterator->moveNext()) {
        ;
    }
    E value = iterator->current();
    while (iterator->moveNext()) {
        value = combine(value, iterator->current());
    }
    return value;
}

template<typename E> T SetMixinCls<E>::foldtemplate<typename T> (T combine(E element, T previousValue) , T initialValue) {
    auto value = initialValue;
    for (E element : this)     {
        value = combine(value, element);
    }
    return value;
}

template<typename E> bool SetMixinCls<E>::every(bool f(E element) ) {
    for (E element : this) {
        if (!f(element))         {
            return false;
        }
    }
    return true;
}

template<typename E> String SetMixinCls<E>::join(String separator) {
    Iterator<E> iterator = this->iterator();
    if (!iterator->moveNext())     {
        return __s("");
    }
    StringBuffer buffer = make<StringBufferCls>();
    if (separator == nullptr || separator == __s("")) {
        do {
            buffer->write(iterator->current());
        } while (iterator->moveNext());
    } else {
        buffer->write(iterator->current());
        while (iterator->moveNext()) {
            buffer->write(separator);
            buffer->write(iterator->current());
        }
    }
    return buffer->toString();
}

template<typename E> bool SetMixinCls<E>::any(bool test(E element) ) {
    for (E element : this) {
        if (test(element))         {
            return true;
        }
    }
    return false;
}

template<typename E> Iterable<E> SetMixinCls<E>::take(int n) {
    return <E>make<TakeIterableCls>(this, n);
}

template<typename E> Iterable<E> SetMixinCls<E>::takeWhile(bool test(E value) ) {
    return <E>make<TakeWhileIterableCls>(this, test);
}

template<typename E> Iterable<E> SetMixinCls<E>::skip(int n) {
    return <E>make<SkipIterableCls>(this, n);
}

template<typename E> Iterable<E> SetMixinCls<E>::skipWhile(bool test(E value) ) {
    return <E>make<SkipWhileIterableCls>(this, test);
}

template<typename E> E SetMixinCls<E>::first() {
    Iterator<E> it = iterator();
    if (!it->moveNext()) {
        ;
    }
    return it->current();
}

template<typename E> E SetMixinCls<E>::last() {
    Iterator<E> it = iterator();
    if (!it->moveNext()) {
        ;
    }
    E result;
    do {
        result = it->current();
    } while (it->moveNext());
    return result;
}

template<typename E> E SetMixinCls<E>::firstWhere(E orElse() , bool test(E value) ) {
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

template<typename E> E SetMixinCls<E>::lastWhere(E orElse() , bool test(E value) ) {
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

template<typename E> E SetMixinCls<E>::singleWhere(E orElse() , bool test(E value) ) {
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

template<typename E> E SetMixinCls<E>::elementAt(int index) {
    checkNotNullable(index, __s("index"));
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

template<typename E> String SetBaseCls<E>::setToString(Set set) {
    return IterableBaseCls->iterableToFullString(set, __s("{"), __s("}"));
}

template<typename E> Set<R> _SetBaseCls<E>::casttemplate<typename R> () {
    return SetCls-><E, R>castFrom(this_newSimilarSet);
}

template<typename E> Set<E> _SetBaseCls<E>::difference(Set<Object> other) {
    Set<E> result = _newSet();
    for (auto element : this) {
        if (!other->contains(element))         {
            result->add(element);
        }
    }
    return result;
}

template<typename E> Set<E> _SetBaseCls<E>::intersection(Set<Object> other) {
    Set<E> result = _newSet();
    for (auto element : this) {
        if (other->contains(element))         {
            result->add(element);
        }
    }
    return result;
}

template<typename E> Set<E> _SetBaseCls<E>::toSet() {
    return _c1;
}

template<typename E> bool _UnmodifiableSetMixinCls<E>::add(E value) {
    return _throwUnmodifiable();
}

template<typename E> void _UnmodifiableSetMixinCls<E>::clear() {
    return _throwUnmodifiable();
}

template<typename E> void _UnmodifiableSetMixinCls<E>::addAll(Iterable<E> elements) {
    return _throwUnmodifiable();
}

template<typename E> void _UnmodifiableSetMixinCls<E>::removeAll(Iterable<Object> elements) {
    return _throwUnmodifiable();
}

template<typename E> void _UnmodifiableSetMixinCls<E>::retainAll(Iterable<Object> elements) {
    return _throwUnmodifiable();
}

template<typename E> void _UnmodifiableSetMixinCls<E>::removeWhere(bool test(E element) ) {
    return _throwUnmodifiable();
}

template<typename E> void _UnmodifiableSetMixinCls<E>::retainWhere(bool test(E element) ) {
    return _throwUnmodifiable();
}

template<typename E> bool _UnmodifiableSetMixinCls<E>::remove(Object value) {
    return _throwUnmodifiable();
}

template<typename E> Never _UnmodifiableSetMixinCls<E>::_throwUnmodifiable() {
    auto _c1 = _newSet();_c1.addAll(this);;
}

template<typename E> bool _UnmodifiableSetCls<E>::contains(Object element) {
    return _map->containsKey(element);
}

template<typename E> Iterator<E> _UnmodifiableSetCls<E>::iterator() {
    return _map->keys->iterator();
}

template<typename E> int _UnmodifiableSetCls<E>::length() {
    return _map->length;
}

template<typename E> E _UnmodifiableSetCls<E>::lookup(Object element) {
    for (auto key : _map->keys) {
        if (key == element)         {
            return key;
        }
    }
    return nullptr;
}

template<typename E> Set<E> _UnmodifiableSetCls<E>::_newSet() {
    return <E>make<LinkedHashSetCls>();
}

template<typename E> Set<R> _UnmodifiableSetCls<E>::_newSimilarSettemplate<typename R> () {
    return <R>make<LinkedHashSetCls>();
}

template<typename E> UnmodifiableSetViewCls<E>::UnmodifiableSetViewCls(Set<E> source) {
    {
        _source = source;
    }
}

template<typename E> bool UnmodifiableSetViewCls<E>::contains(Object element) {
    return _source->contains(element);
}

template<typename E> E UnmodifiableSetViewCls<E>::lookup(Object element) {
    return _source->lookup(element);
}

template<typename E> int UnmodifiableSetViewCls<E>::length() {
    return _source->length;
}

template<typename E> Iterator<E> UnmodifiableSetViewCls<E>::iterator() {
    return _source->iterator();
}

template<typename E> Set<E> UnmodifiableSetViewCls<E>::toSet() {
    return _source->toSet();
}
