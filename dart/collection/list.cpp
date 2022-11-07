#include "list.hpp"
String ListBase::listToString(List list) {
    return IterableBase.iterableToFullString(list, "[", "]");
}

Iterator<E> ListMixin::iterator() {
    return <E>ListIterator(this);
}

E ListMixin::elementAt(int index) {
    return this[index];
}

Iterable<E> ListMixin::followedBy(Iterable<E> other) {
    return <E>firstEfficient(this, other);
}

void ListMixin::forEach(FunctionType action) {
    int length = this.length;
    for (;  < length; i++) {
        action(this[i]);
        if (length != this.length) {
            ;
        }
    }
}

bool ListMixin::isEmpty() {
    return length == 0;
}

bool ListMixin::isNotEmpty() {
    return !isEmpty;
}

E ListMixin::first() {
    if (length == 0)     {
        ;
    }
    return this[0];
}

void ListMixin::first(E value) {
    if (length == 0)     {
        ;
    }
    this[0] = value;
}

E ListMixin::last() {
    if (length == 0)     {
        ;
    }
    return this[length - 1];
}

void ListMixin::last(E value) {
    if (length == 0)     {
        ;
    }
    this[length - 1] = value;
}

E ListMixin::single() {
    if (length == 0)     {
        ;
    }
    if (length > 1)     {
        ;
    }
    return this[0];
}

bool ListMixin::contains(Object element) {
    int length = this.length;
    for (;  < length; i++) {
        if (this[i] == element)         {
            return true;
        }
        if (length != this.length) {
            ;
        }
    }
    return false;
}

bool ListMixin::every(FunctionType test) {
    int length = this.length;
    for (;  < length; i++) {
        if (!test(this[i]))         {
            return false;
        }
        if (length != this.length) {
            ;
        }
    }
    return true;
}

bool ListMixin::any(FunctionType test) {
    int length = this.length;
    for (;  < length; i++) {
        if (test(this[i]))         {
            return true;
        }
        if (length != this.length) {
            ;
        }
    }
    return false;
}

E ListMixin::firstWhere(FunctionType orElse, FunctionType test) {
    int length = this.length;
    for (;  < length; i++) {
        E element = this[i];
        if (test(element))         {
            return element;
        }
        if (length != this.length) {
            ;
        }
    }
    if (orElse != nullptr)     {
        return orElse();
    }
    ;
}

E ListMixin::lastWhere(FunctionType orElse, FunctionType test) {
    int length = this.length;
    for (; i >= 0; i--) {
        E element = this[i];
        if (test(element))         {
            return element;
        }
        if (length != this.length) {
            ;
        }
    }
    if (orElse != nullptr)     {
        return orElse();
    }
    ;
}

E ListMixin::singleWhere(FunctionType orElse, FunctionType test) {
    int length = this.length;
    E match;
    bool matchFound = false;
    for (;  < length; i++) {
        E element = this[i];
        if (test(element)) {
            if (matchFound) {
                ;
            }
            matchFound = true;
            match = element;
        }
        if (length != this.length) {
            ;
        }
    }
    if (matchFound)     {
        return match;
    }
    if (orElse != nullptr)     {
        return orElse();
    }
    ;
}

String ListMixin::join(String separator) {
    if (length == 0)     {
        return "";
    }
    StringBuffer buffer = ;
    return buffer.toString();
}

Iterable<E> ListMixin::where(FunctionType test) {
    return <E>WhereIterable(this, test);
}

Iterable<T> ListMixin::whereType<T>() {
    return <T>WhereTypeIterable(this);
}

Iterable<T> ListMixin::map<T>(FunctionType f) {
    return <E, T>MappedListIterable(this, f);
}

Iterable<T> ListMixin::expand<T>(FunctionType f) {
    return <E, T>ExpandIterable(this, f);
}

E ListMixin::reduce(FunctionType combine) {
    int length = this.length;
    if (length == 0)     {
        ;
    }
    E value = this[0];
    for (;  < length; i++) {
        value = combine(value, this[i]);
        if (length != this.length) {
            ;
        }
    }
    return value;
}

T ListMixin::fold<T>(FunctionType combine, T initialValue) {
    auto value = initialValue;
    int length = this.length;
    for (;  < length; i++) {
        value = combine(value, this[i]);
        if (length != this.length) {
            ;
        }
    }
    return value;
}

Iterable<E> ListMixin::skip(int count) {
    return <E>SubListIterable(this, count, nullptr);
}

Iterable<E> ListMixin::skipWhile(FunctionType test) {
    return <E>SkipWhileIterable(this, test);
}

Iterable<E> ListMixin::take(int count) {
    return <E>SubListIterable(this, 0, checkNotNullable(count, "count"));
}

Iterable<E> ListMixin::takeWhile(FunctionType test) {
    return <E>TakeWhileIterable(this, test);
}

List<E> ListMixin::toList(bool growable) {
    if (this.isEmpty)     {
        return <E>empty(growable);
    }
    auto first = this[0];
    auto result = <E>filled(this.length, firstgrowable);
    for (;  < this.length; i++) {
        result[i] = this[i];
    }
    return result;
}

Set<E> ListMixin::toSet() {
    Set<E> result = <E>Set();
    for (;  < length; i++) {
        result.add(this[i]);
    }
    return result;
}

void ListMixin::add(E element) {
    this[this.length++] = element;
}

void ListMixin::addAll(Iterable<E> iterable) {
    int i = this.length;
    for (E element : iterable) {
        assert(this.length == i || ());
        add(element);
        i++;
    }
}

bool ListMixin::remove(Object element) {
    for (;  < this.length; i++) {
        if (this[i] == element) {
            this._closeGap(i, i + 1);
            return true;
        }
    }
    return false;
}

void ListMixin::removeWhere(FunctionType test) {
    _filter(test, false);
}

void ListMixin::retainWhere(FunctionType test) {
    _filter(test, true);
}

void ListMixin::clear() {
    this.length = 0;
}

List<R> ListMixin::cast<R>() {
    return List.<E, R>castFrom(this);
}

E ListMixin::removeLast() {
    if (length == 0) {
        ;
    }
    E result = this[length - 1];
    length--;
    return result;
}

void ListMixin::sort(FunctionType compare) {
    Sort.sort(this, compare ?? _compareAny);
}

void ListMixin::shuffle(Random random) {
    random = Random();
    if (random == nullptr)     {
        ;
    }
    int length = this.length;
    while (length > 1) {
        int pos = random.nextInt(length);
        length = 1;
        auto tmp = this[length];
        this[length] = this[pos];
        this[pos] = tmp;
    }
}

Map<int, E> ListMixin::asMap() {
    return <E>ListMapView(this);
}

List<E> ListMixin::+(List<E> other) {
    return ;
}

List<E> ListMixin::sublist(int end, int start) {
    int listLength = this.length;
    end = listLength;
    if (end == nullptr)     {
        ;
    }
    RangeError.checkValidRange(start, end, listLength);
    return List.from(getRange(start, end));
}

Iterable<E> ListMixin::getRange(int end, int start) {
    RangeError.checkValidRange(start, end, this.length);
    return <E>SubListIterable(this, start, end);
}

void ListMixin::removeRange(int end, int start) {
    RangeError.checkValidRange(start, end, this.length);
    if (end > start) {
        _closeGap(start, end);
    }
}

void ListMixin::fillRange(int end, E fill, int start) {
    E value = (;
    RangeError.checkValidRange(start, end, this.length);
    for (;  < end; i++) {
        this[i] = value;
    }
}

void ListMixin::setRange(int end, Iterable<E> iterable, int skipCount, int start) {
    RangeError.checkValidRange(start, end, this.length);
    int length = end - start;
    if (length == 0)     {
        return;
    }
    RangeError.checkNotNegative(skipCount, "skipCount");
    List<E> otherList;
    int otherStart;
    if (iterable is List<E>) {
        otherList = iterable;
        otherStart = skipCount;
    } else {
        otherList = iterable.skip(skipCount).toList(false);
        otherStart = 0;
    }
    if (otherStart + length > otherList.length) {
        ;
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

void ListMixin::replaceRange(int end, Iterable<E> newContents, int start) {
    RangeError.checkValidRange(start, end, this.length);
    if (start == this.length) {
        addAll(newContents);
        return;
    }
    if (newContents is! EfficientLengthIterable) {
        newContents = newContents.toList();
    }
    int removeLength = end - start;
    int insertLength = newContents.length;
    if (removeLength >= insertLength) {
        int insertEnd = start + insertLength;
        this.setRange(start, insertEnd, newContents);
        if (removeLength > insertLength) {
            _closeGap(insertEnd, end);
        }
    } else     {
        if (end == this.length) {
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
        int oldLength = this.length;
        int insertEnd = start + insertLength;
        for (;  < oldLength; ++i) {
            add(this[i > 0? i : 0]);
        }
        if ( < oldLength) {
            this.setRange(insertEnd, oldLength, this, end);
        }
        this.setRange(start, insertEnd, newContents);
    }
;
    }}

int ListMixin::indexOf(Object element, int start) {
    if ( < 0)     {
        start = 0;
    }
    for (;  < this.length; i++) {
        if (this[i] == element)         {
            return i;
        }
    }
    return -1;
}

int ListMixin::indexWhere(int start, FunctionType test) {
    if ( < 0)     {
        start = 0;
    }
    for (;  < this.length; i++) {
        if (test(this[i]))         {
            return i;
        }
    }
    return -1;
}

int ListMixin::lastIndexOf(Object element, int start) {
    if (start == nullptr || start >= this.length)     {
        start = this.length - 1;
    }
    if (start == nullptr)     {
        ;
    }
    for (; i >= 0; i--) {
        if (this[i] == element)         {
            return i;
        }
    }
    return -1;
}

int ListMixin::lastIndexWhere(int start, FunctionType test) {
    if (start == nullptr || start >= this.length)     {
        start = this.length - 1;
    }
    if (start == nullptr)     {
        ;
    }
    for (; i >= 0; i--) {
        if (test(this[i]))         {
            return i;
        }
    }
    return -1;
}

void ListMixin::insert(E element, int index) {
    checkNotNullable(index, "index");
    auto length = this.length;
    RangeError.checkValueInInterval(index, 0, length, "index");
    add(element);
    if (index != length) {
        setRange(index + 1, length + 1, this, index);
        this[index] = element;
    }
}

E ListMixin::removeAt(int index) {
    E result = this[index];
    _closeGap(index, index + 1);
    return result;
}

void ListMixin::insertAll(int index, Iterable<E> iterable) {
    RangeError.checkValueInInterval(index, 0, length, "index");
    if (index == length) {
        addAll(iterable);
        return;
    }
    if (iterable is! EfficientLengthIterable || identical(iterable, this)) {
        iterable = iterable.toList();
    }
    int insertionLength = iterable.length;
    if (insertionLength == 0) {
        return;
    }
    int oldLength = length;
    for (;  < oldLength; ++i) {
        add(this[i > 0? i : 0]);
    }
    if (iterable.length != insertionLength) {
        this.length = insertionLength;
        ;
    }
    int oldCopyStart = index + insertionLength;
    if ( < oldLength) {
        setRange(oldCopyStart, oldLength, this, index);
    }
    setAll(index, iterable);
}

void ListMixin::setAll(int index, Iterable<E> iterable) {
    if (iterable is List) {
        setRange(index, index + iterable.length, iterable);
    } else {
        for (E element : iterable) {
            this[index++] = element;
        }
    }
}

Iterable<E> ListMixin::reversed() {
    return <E>ReversedListIterable(this);
}

String ListMixin::toString() {
    return IterableBase.iterableToFullString(this, "[", "]");
}

void ListMixin::_closeGap(int end, int start) {
    int length = this.length;
    assert(0 <= start);
    assert( < end);
    assert(end <= length);
    int size = end - start;
    for (;  < length; i++) {
        this[i - size] = this[i];
    }
    this.length = length - size;
}

void ListMixin::_filter(bool retainMatching, FunctionType test) {
    List<E> retained = ;
    int length = this.length;
    for (;  < length; i++) {
        auto element = this[i];
        if (test(element) == retainMatching) {
            retained.add(element);
        }
        if (length != this.length) {
            ;
        }
    }
    if (retained.length != this.length) {
        this.setRange(0, retained.length, retained);
        this.length = retained.length;
    }
}

int ListMixin::_compareAny(dynamic a, dynamic b) {
    return Comparable.compare((, ();
}
