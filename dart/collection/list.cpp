#include "list.hpp"
template<typename E>
String ListBaseCls<E>::listToString(List<any> list) {
    return IterableBaseCls->iterableToFullString(list, __s("["), __s("]"));
}

template<typename E>
Iterator<E> ListMixinCls<E>::iterator() {
    return <E>make<ListIteratorCls>(this);
}

template<typename E>
E ListMixinCls<E>::elementAt(int index) {
    return this[index];
}

template<typename E>
Iterable<E> ListMixinCls<E>::followedBy(Iterable<E> other) {
    return <E>firstEfficient(this, other);
}

template<typename E>
void ListMixinCls<E>::forEach(std::function<void(E element)> action) {
    int length = this->length();
    for (;  < length; i++) {
        action(this[i]);
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
}

template<typename E>
bool ListMixinCls<E>::isEmpty() {
    return length() == 0;
}

template<typename E>
bool ListMixinCls<E>::isNotEmpty() {
    return !isEmpty();
}

template<typename E>
E ListMixinCls<E>::first() {
    if (length() == 0) {
        throw IterableElementErrorCls->noElement();
    }
    return this[0];
}

template<typename E>
void ListMixinCls<E>::first(E value) {
    if (length() == 0) {
        throw IterableElementErrorCls->noElement();
    }
    this[0] = value;
}

template<typename E>
E ListMixinCls<E>::last() {
    if (length() == 0) {
        throw IterableElementErrorCls->noElement();
    }
    return this[length() - 1];
}

template<typename E>
void ListMixinCls<E>::last(E value) {
    if (length() == 0) {
        throw IterableElementErrorCls->noElement();
    }
    this[length() - 1] = value;
}

template<typename E>
E ListMixinCls<E>::single() {
    if (length() == 0) {
        throw IterableElementErrorCls->noElement();
    }
    if (length() > 1) {
        throw IterableElementErrorCls->tooMany();
    }
    return this[0];
}

template<typename E>
bool ListMixinCls<E>::contains(Object element) {
    int length = this->length();
    for (;  < length; i++) {
        if (this[i] == element) {
            return true;
        }
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    return false;
}

template<typename E>
bool ListMixinCls<E>::every(std::function<bool(E element)> test) {
    int length = this->length();
    for (;  < length; i++) {
        if (!test(this[i])) {
            return false;
        }
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    return true;
}

template<typename E>
bool ListMixinCls<E>::any(std::function<bool(E element)> test) {
    int length = this->length();
    for (;  < length; i++) {
        if (test(this[i])) {
            return true;
        }
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    return false;
}

template<typename E>
E ListMixinCls<E>::firstWhere(std::function<bool(E element)> test, std::function<E()> orElse) {
    int length = this->length();
    for (;  < length; i++) {
        E element = this[i];
        if (test(element)) {
            return element;
        }
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    if (orElse != nullptr) {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E ListMixinCls<E>::lastWhere(std::function<bool(E element)> test, std::function<E()> orElse) {
    int length = this->length();
    for (; i >= 0; i--) {
        E element = this[i];
        if (test(element)) {
            return element;
        }
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    if (orElse != nullptr) {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
E ListMixinCls<E>::singleWhere(std::function<bool(E element)> test, std::function<E()> orElse) {
    int length = this->length();
    E match;
    bool matchFound = false;
    for (;  < length; i++) {
        E element = this[i];
        if (test(element)) {
            if (matchFound) {
                throw IterableElementErrorCls->tooMany();
            }
            matchFound = true;
            match = element;
        }
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    if (matchFound) {
        return match;
    }
    if (orElse != nullptr) {
        return orElse();
    }
    throw IterableElementErrorCls->noElement();
}

template<typename E>
String ListMixinCls<E>::join(String separator) {
    if (length() == 0) {
        return __s("");
    }
    auto _c1 = make<StringBufferCls>();_c1.writeAll(this, separator);StringBuffer buffer = _c1;
    return buffer->toString();
}

template<typename E>
Iterable<E> ListMixinCls<E>::where(std::function<bool(E element)> test) {
    return <E>make<WhereIterableCls>(this, test);
}

template<typename E>
template<typename T>
Iterable<T> ListMixinCls<E>::whereType() {
    return <T>make<WhereTypeIterableCls>(this);
}

template<typename E>
template<typename T>
Iterable<T> ListMixinCls<E>::map(std::function<T(E element)> f) {
    return <E, T>make<MappedListIterableCls>(this, f);
}

template<typename E>
template<typename T>
Iterable<T> ListMixinCls<E>::expand(std::function<Iterable<T>(E element)> f) {
    return <E, T>make<ExpandIterableCls>(this, f);
}

template<typename E>
E ListMixinCls<E>::reduce(std::function<E(E previousValue, E element)> combine) {
    int length = this->length();
    if (length == 0) {
        throw IterableElementErrorCls->noElement();
    }
    E value = this[0];
    for (;  < length; i++) {
        value = combine(value, this[i]);
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    return value;
}

template<typename E>
template<typename T>
T ListMixinCls<E>::fold(T initialValue, std::function<T(T previousValue, E element)> combine) {
    auto value = initialValue;
    int length = this->length();
    for (;  < length; i++) {
        value = combine(value, this[i]);
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    return value;
}

template<typename E>
Iterable<E> ListMixinCls<E>::skip(int count) {
    return <E>make<SubListIterableCls>(this, count, nullptr);
}

template<typename E>
Iterable<E> ListMixinCls<E>::skipWhile(std::function<bool(E element)> test) {
    return <E>make<SkipWhileIterableCls>(this, test);
}

template<typename E>
Iterable<E> ListMixinCls<E>::take(int count) {
    return <E>make<SubListIterableCls>(this, 0, checkNotNullable(count, __s("count")));
}

template<typename E>
Iterable<E> ListMixinCls<E>::takeWhile(std::function<bool(E element)> test) {
    return <E>make<TakeWhileIterableCls>(this, test);
}

template<typename E>
List<E> ListMixinCls<E>::toList(bool growable) {
    if (this->isEmpty()) {
        return <E>empty(growable);
    }
    auto first = this[0];
    auto result = <E>filled(this->length(), first, growable);
    for (;  < this->length(); i++) {
        result[i] = this[i];
    }
    return result;
}

template<typename E>
Set<E> ListMixinCls<E>::toSet() {
    Set<E> result = <E>make<SetCls>();
    for (;  < length(); i++) {
        result->add(this[i]);
    }
    return result;
}

template<typename E>
void ListMixinCls<E>::add(E element) {
    this[this->length()++] = element;
}

template<typename E>
void ListMixinCls<E>::addAll(Iterable<E> iterable) {
    int i = this->length();
    for (E element : iterable) {
        assert(this->length() == i || (throw make<ConcurrentModificationErrorCls>(this)));
        add(element);
        i++;
    }
}

template<typename E>
bool ListMixinCls<E>::remove(Object element) {
    for (;  < this->length(); i++) {
        if (this[i] == element) {
            this->_closeGap(i, i + 1);
            return true;
        }
    }
    return false;
}

template<typename E>
void ListMixinCls<E>::removeWhere(std::function<bool(E element)> test) {
    _filter(test, false);
}

template<typename E>
void ListMixinCls<E>::retainWhere(std::function<bool(E element)> test) {
    _filter(test, true);
}

template<typename E>
void ListMixinCls<E>::clear() {
    this->length() = 0;
}

template<typename E>
template<typename R>
List<R> ListMixinCls<E>::cast() {
    return ListCls-><E, R>castFrom(this);
}

template<typename E>
E ListMixinCls<E>::removeLast() {
    if (length() == 0) {
        throw IterableElementErrorCls->noElement();
    }
    E result = this[length() - 1];
    length()--;
    return result;
}

template<typename E>
void ListMixinCls<E>::sort(std::function<int(E a, E b)> compare) {
    SortCls->sort(this, compare | _compareAny);
}

template<typename E>
void ListMixinCls<E>::shuffle(Random random) {
    random |= make<RandomCls>();
    if (random == nullptr) {
        throw __s("!");
    }
    int length = this->length();
    while (length > 1) {
        int pos = random->nextInt(length);
        length -= 1;
        auto tmp = this[length];
        this[length] = this[pos];
        this[pos] = tmp;
    }
}

template<typename E>
Map<int, E> ListMixinCls<E>::asMap() {
    return <E>make<ListMapViewCls>(this);
}

template<typename E>
List<E> ListMixinCls<E>::+(List<E> other) {
    return list1;
}

template<typename E>
List<E> ListMixinCls<E>::sublist(int start, int end) {
    for (auto _x1 : this) {{    list1.add(_x1);}for (auto _x1 : other) {{    list1.add(_x1);}int listLength = this->length();
    end |= listLength;
    if (end == nullptr) {
        throw __s("!");
    }
    RangeErrorCls->checkValidRange(start, end, listLength);
    return ListCls->from(getRange(start, end));
}

template<typename E>
Iterable<E> ListMixinCls<E>::getRange(int start, int end) {
    RangeErrorCls->checkValidRange(start, end, this->length());
    return <E>make<SubListIterableCls>(this, start, end);
}

template<typename E>
void ListMixinCls<E>::removeRange(int start, int end) {
    RangeErrorCls->checkValidRange(start, end, this->length());
    if (end > start) {
        _closeGap(start, end);
    }
}

template<typename E>
void ListMixinCls<E>::fillRange(int start, int end, E fill) {
    E value = as<E>(fill);
    RangeErrorCls->checkValidRange(start, end, this->length());
    for (;  < end; i++) {
        this[i] = value;
    }
}

template<typename E>
void ListMixinCls<E>::setRange(int start, int end, Iterable<E> iterable, int skipCount) {
    RangeErrorCls->checkValidRange(start, end, this->length());
    int length = end - start;
    if (length == 0) {
        return;
    }
    RangeErrorCls->checkNotNegative(skipCount, __s("skipCount"));
    List<E> otherList;
    int otherStart;
    if (is<List<E>>(iterable)) {
        otherList = as<ListCls>(iterable);
        otherStart = skipCount;
    } else {
        otherList = iterable->skip(skipCount)->toList(false);
        otherStart = 0;
    }
    if (otherStart + length > otherList->length) {
        throw IterableElementErrorCls->tooFew();
    }
    if ( < start) {
        for (; i >= 0; i--) {
            this[start + i] = otherList[otherStart + i];
        }
    } else {
        for (;  < length; i++) {
            this[start + i] = otherList[otherStart + i];
        }
    }
}

template<typename E>
void ListMixinCls<E>::replaceRange(int start, int end, Iterable<E> newContents) {
    RangeErrorCls->checkValidRange(start, end, this->length());
    if (start == this->length()) {
        addAll(newContents);
        return;
    }
    if (!is<EfficientLengthIterable<any>>(newContents)) {
        as<EfficientLengthIterableCls>(newContents) = as<EfficientLengthIterableCls>(newContents)->toList();
    }
    int removeLength = end - start;
    int insertLength = newContents->length();
    if (removeLength >= insertLength) {
        int insertEnd = start + insertLength;
        this->setRange(start, insertEnd, newContents);
        if (removeLength > insertLength) {
            _closeGap(insertEnd, end);
        }
    } else {
        if (end == this->length()) {
        int i = start;
        for (E element : newContents) {
            if ( < end) {
                this[i] = element;
            } else {
                add(element);
            }
            i++;
        }
    } else {
        int delta = insertLength - removeLength;
        int oldLength = this->length();
        int insertEnd = start + insertLength;
        for (;  < oldLength; ++i) {
            add(this[i > 0? i : 0]);
        }
        if ( < oldLength) {
            this->setRange(insertEnd, oldLength, this, end);
        }
        this->setRange(start, insertEnd, newContents);
    }
;
    }}

template<typename E>
int ListMixinCls<E>::indexOf(Object element, int start) {
    if ( < 0) {
        start = 0;
    }
    for (;  < this->length(); i++) {
        if (this[i] == element) {
            return i;
        }
    }
    return -1;
}

template<typename E>
int ListMixinCls<E>::indexWhere(std::function<bool(E element)> test, int start) {
    if ( < 0) {
        start = 0;
    }
    for (;  < this->length(); i++) {
        if (test(this[i])) {
            return i;
        }
    }
    return -1;
}

template<typename E>
int ListMixinCls<E>::lastIndexOf(Object element, int start) {
    if (start == nullptr || start >= this->length()) {
        start = this->length() - 1;
    }
    if (start == nullptr) {
        throw __s("!");
    }
    for (; i >= 0; i--) {
        if (this[i] == element) {
            return i;
        }
    }
    return -1;
}

template<typename E>
int ListMixinCls<E>::lastIndexWhere(std::function<bool(E element)> test, int start) {
    if (start == nullptr || start >= this->length()) {
        start = this->length() - 1;
    }
    if (start == nullptr) {
        throw __s("!");
    }
    for (; i >= 0; i--) {
        if (test(this[i])) {
            return i;
        }
    }
    return -1;
}

template<typename E>
void ListMixinCls<E>::insert(int index, E element) {
    checkNotNullable(index, __s("index"));
    auto length = this->length();
    RangeErrorCls->checkValueInInterval(index, 0, length, __s("index"));
    add(element);
    if (index != length) {
        setRange(index + 1, length + 1, this, index);
        this[index] = element;
    }
}

template<typename E>
E ListMixinCls<E>::removeAt(int index) {
    E result = this[index];
    _closeGap(index, index + 1);
    return result;
}

template<typename E>
void ListMixinCls<E>::insertAll(int index, Iterable<E> iterable) {
    RangeErrorCls->checkValueInInterval(index, 0, length(), __s("index"));
    if (index == length()) {
        addAll(iterable);
        return;
    }
    if (!is<EfficientLengthIterable<any>>(iterable) || identical(iterable, this)) {
        iterable = iterable->toList();
    }
    int insertionLength = iterable->length();
    if (insertionLength == 0) {
        return;
    }
    int oldLength = length();
    for (;  < oldLength; ++i) {
        add(this[i > 0? i : 0]);
    }
    if (iterable->length() != insertionLength) {
        this->length() -= insertionLength;
        throw make<ConcurrentModificationErrorCls>(iterable);
    }
    int oldCopyStart = index + insertionLength;
    if ( < oldLength) {
        setRange(oldCopyStart, oldLength, this, index);
    }
    setAll(index, iterable);
}

template<typename E>
void ListMixinCls<E>::setAll(int index, Iterable<E> iterable) {
    if (is<List<any>>(iterable)) {
        setRange(index, index + as<ListCls>(iterable)->length(), as<ListCls>(iterable));
    } else {
        for (E element : iterable) {
            this[index++] = element;
        }
    }
}

template<typename E>
Iterable<E> ListMixinCls<E>::reversed() {
    return <E>make<ReversedListIterableCls>(this);
}

template<typename E>
String ListMixinCls<E>::toString() {
    return IterableBaseCls->iterableToFullString(this, __s("["), __s("]"));
}

template<typename E>
void ListMixinCls<E>::_closeGap(int start, int end) {
    int length = this->length();
    assert(0 <= start);
    assert( < end);
    assert(end <= length);
    int size = end - start;
    for (;  < length; i++) {
        this[i - size] = this[i];
    }
    this->length = length - size;
}

template<typename E>
void ListMixinCls<E>::_filter(std::function<bool(E element)> test, bool retainMatching) {
    List<E> retained = makeList();
    int length = this->length();
    for (;  < length; i++) {
        auto element = this[i];
        if (test(element) == retainMatching) {
            retained->add(element);
        }
        if (length != this->length) {
            throw make<ConcurrentModificationErrorCls>(this);
        }
    }
    if (retained->length != this->length) {
        this->setRange(0, retained->length, retained);
        this->length = retained->length;
    }
}

template<typename E>
int ListMixinCls<E>::_compareAny(Object a, Object b) {
    return ComparableCls->compare(as<Comparable<any>>(a), as<Comparable<any>>(b));
}
