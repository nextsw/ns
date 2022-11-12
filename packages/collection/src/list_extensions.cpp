#include "list_extensions.hpp"
template<typename E>
int ListExtensionsCls<E>::binarySearch(E element, std::function<int(E , E )> compare) {
    return algorithms-><E, E>binarySearchBy(this, identity, compare, element);
}

template<typename E>
template<typename K>
int ListExtensionsCls<E>::binarySearchByCompare(E element, std::function<K(E element)> keyOf, std::function<int(K , K )> compare, int start, int end) {
    return algorithms-><E, K>binarySearchBy(this, keyOf, compare, element, start, end);
}

template<typename E>
template<typename K>
int ListExtensionsCls<E>::binarySearchBy(E element, std::function<K(E element)> keyOf, int start, int end) {
    return algorithms-><E, K>binarySearchBy(this, keyOf, [=] (Unknown  a,Unknown  b) {
        a->compareTo(b);
    }, element, start, end);
}

template<typename E>
int ListExtensionsCls<E>::lowerBound(E element, std::function<int(E , E )> compare) {
    return algorithms-><E, E>lowerBoundBy(this, identity, compare, element);
}

template<typename E>
template<typename K>
int ListExtensionsCls<E>::lowerBoundByCompare(E element, std::function<K(E )> keyOf, std::function<int(K , K )> compare, int start, int end) {
    return algorithms->lowerBoundBy(this, keyOf, compare, element, start, end);
}

template<typename E>
template<typename K>
int ListExtensionsCls<E>::lowerBoundBy(E element, std::function<K(E )> keyOf, int start, int end) {
    return algorithms-><E, K>lowerBoundBy(this, keyOf, compareComparable, element, start, end);
}

template<typename E>
void ListExtensionsCls<E>::forEachIndexed(std::function<void(int index, E element)> action) {
    for (;  < length; index++) {
        action(index, this[index]);
    }
}

template<typename E>
void ListExtensionsCls<E>::forEachWhile(std::function<bool(E element)> action) {
    for (;  < length; index++) {
        if (!action(this[index])) {
            break;
        }
    }
}

template<typename E>
void ListExtensionsCls<E>::forEachIndexedWhile(std::function<bool(int index, E element)> action) {
    for (;  < length; index++) {
        if (!action(index, this[index])) {
            break;
        }
    }
}

template<typename E>
template<typename R>
Iterable<R> ListExtensionsCls<E>::mapIndexed(std::function<R(int index, E element)> convert) {
    for (;  < length; index++) {
        yield convert(index, this[index]);
    }
}

template<typename E>
Iterable<E> ListExtensionsCls<E>::whereIndexed(std::function<bool(int index, E element)> test) {
    for (;  < length; index++) {
        auto element = this[index];
        if (test(index, element)) {
            yield element;
        }
    }
}

template<typename E>
Iterable<E> ListExtensionsCls<E>::whereNotIndexed(std::function<bool(int index, E element)> test) {
    for (;  < length; index++) {
        auto element = this[index];
        if (!test(index, element)) {
            yield element;
        }
    }
}

template<typename E>
template<typename R>
Iterable<R> ListExtensionsCls<E>::expandIndexed(std::function<Iterable<R>(int index, E element)> expand) {
    for (;  < length; index++) {
        yield expand(index, this[index]);
    }
}

template<typename E>
void ListExtensionsCls<E>::sortRange(int start, int end, std::function<int(E a, E b)> compare) {
    <E, E>quickSortBy(this, identity, compare, start, end);
}

template<typename E>
template<typename K>
void ListExtensionsCls<E>::sortByCompare(std::function<K(E element)> keyOf, std::function<int(K a, K b)> compare, int start, int end) {
    quickSortBy(this, keyOf, compare, start, end);
}

template<typename E>
template<typename K>
void ListExtensionsCls<E>::sortBy(std::function<K(E element)> keyOf, int start, int end) {
    <E, K>quickSortBy(this, keyOf, compareComparable, start, end);
}

template<typename E>
void ListExtensionsCls<E>::shuffleRange(int start, int end, Random random) {
    RangeErrorCls->checkValidRange(start, end, length);
    shuffle(this, start, end, random);
}

template<typename E>
void ListExtensionsCls<E>::reverseRange(int start, int end) {
    RangeErrorCls->checkValidRange(start, end, length);
    while ( < --end) {
        auto tmp = this[start];
        this[start] = this[end];
        this[end] = tmp;
        start += 1;
    }
}

template<typename E>
void ListExtensionsCls<E>::swap(int index1, int index2) {
    RangeErrorCls->checkValidIndex(index1, this, __s("index1"));
    RangeErrorCls->checkValidIndex(index2, this, __s("index2"));
    auto tmp = this[index1];
    this[index1] = this[index2];
    this[index2] = tmp;
}

template<typename E>
ListSlice<E> ListExtensionsCls<E>::slice(int start, int end) {
    end = RangeErrorCls->checkValidRange(start, end, length);
    auto self = this;
    if (is<ListSlice<any>>(self)) {
        return as<ListSliceCls>(self)->slice(start, end);
    }
    return <E>make<ListSliceCls>(this, start, end);
}

template<typename E>
bool ListExtensionsCls<E>::equals(List<E> other, Equality<E> equality) {
    if (length != other->length()) {
        return false;
    }
    for (;  < length; i++) {
        if (!equality->equals(this[i], other[i])) {
            return false;
        }
    }
    return true;
}

template<typename E>
Iterable<List<E>> ListExtensionsCls<E>::slices(int length) {
    if ( < 1) {
        throw RangeErrorCls->range(length, 1, nullptr, __s("length"));
    }
    for (;  < this->length; i += length) {
        yield slice(i, min(i + length, this->length));
    }
}

template<typename E>
int ListComparableExtensionsCls<E>::binarySearch(E element, std::function<int(E , E )> compare) {
    return algorithms-><E, E>binarySearchBy(this, identity, compare | compareComparable, element);
}

template<typename E>
int ListComparableExtensionsCls<E>::lowerBound(E element, std::function<int(E , E )> compare) {
    return algorithms-><E, E>lowerBoundBy(this, identity, compare | compareComparable, element);
}

template<typename E>
void ListComparableExtensionsCls<E>::sortRange(int start, int end, std::function<int(E a, E b)> compare) {
    RangeErrorCls->checkValidRange(start, end, length);
    algorithms-><E, E>quickSortBy(this, identity, compare | compareComparable, start, end);
}

template<typename E>
ListSliceCls<E>::ListSliceCls(List<E> source, int start, int end) {
    {
        length = end - start;
        _initialSize = source->length;
    }
    {
        RangeErrorCls->checkValidRange(start, end, source->length);
    }
}

template<typename E>
int ListSliceCls<E>::end() {
    return start + length;
}

template<typename E>
E ListSliceCls<E>::[](int index) {
    if (source->length != _initialSize) {
        throw make<ConcurrentModificationErrorCls>(source);
    }
    RangeErrorCls->checkValidIndex(index, this, nullptr, length);
    return source[start + index];
}

template<typename E>
void ListSliceCls<E>::[]=(int index, E value) {
    if (source->length != _initialSize) {
        throw make<ConcurrentModificationErrorCls>(source);
    }
    RangeErrorCls->checkValidIndex(index, this, nullptr, length);
    source[start + index] = value;
}

template<typename E>
void ListSliceCls<E>::setRange(int start, int end, Iterable<E> iterable, int skipCount) {
    if (source->length != _initialSize) {
        throw make<ConcurrentModificationErrorCls>(source);
    }
    RangeErrorCls->checkValidRange(start, end, length);
    source->setRange(start + start, start + end, iterable, skipCount);
}

template<typename E>
ListSlice<E> ListSliceCls<E>::slice(int start, int end) {
    end = RangeErrorCls->checkValidRange(start, end, length);
    return ListSliceCls->_(_initialSize, source, start + start, end - start);
}

template<typename E>
void ListSliceCls<E>::shuffle(Random random) {
    if (source->length != _initialSize) {
        throw make<ConcurrentModificationErrorCls>(source);
    }
    algorithms->shuffle(source, start, end(), random);
}

template<typename E>
void ListSliceCls<E>::sort(std::function<int(E a, E b)> compare) {
    if (source->length != _initialSize) {
        throw make<ConcurrentModificationErrorCls>(source);
    }
    compare |= defaultCompare;
    quickSort(source, compare, start, start + length);
}

template<typename E>
void ListSliceCls<E>::sortRange(int start, int end, std::function<int(E a, E b)> compare) {
    if (source->length != _initialSize) {
        throw make<ConcurrentModificationErrorCls>(source);
    }
    source->sortRange(start, end, compare);
}

template<typename E>
void ListSliceCls<E>::shuffleRange(int start, int end, Random random) {
    if (source->length != _initialSize) {
        throw make<ConcurrentModificationErrorCls>(source);
    }
    RangeErrorCls->checkValidRange(start, end, length);
    algorithms->shuffle(source, this->start + start, this->start + end, random);
}

template<typename E>
void ListSliceCls<E>::reverseRange(int start, int end) {
    RangeErrorCls->checkValidRange(start, end, length);
    source->reverseRange(this->start + start, this->start + end);
}

template<typename E>
void ListSliceCls<E>::length(int newLength) {
    throw make<UnsupportedErrorCls>(__s("Cannot change the length of a fixed-length list"));
}

template<typename E>
void ListSliceCls<E>::add(E element) {
    throw make<UnsupportedErrorCls>(__s("Cannot add to a fixed-length list"));
}

template<typename E>
void ListSliceCls<E>::insert(int index, E element) {
    throw make<UnsupportedErrorCls>(__s("Cannot add to a fixed-length list"));
}

template<typename E>
void ListSliceCls<E>::insertAll(int index, Iterable<E> iterable) {
    throw make<UnsupportedErrorCls>(__s("Cannot add to a fixed-length list"));
}

template<typename E>
void ListSliceCls<E>::addAll(Iterable<E> iterable) {
    throw make<UnsupportedErrorCls>(__s("Cannot add to a fixed-length list"));
}

template<typename E>
bool ListSliceCls<E>::remove(Object element) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}

template<typename E>
void ListSliceCls<E>::removeWhere(std::function<bool(E element)> test) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}

template<typename E>
void ListSliceCls<E>::retainWhere(std::function<bool(E element)> test) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}

template<typename E>
void ListSliceCls<E>::clear() {
    throw make<UnsupportedErrorCls>(__s("Cannot clear a fixed-length list"));
}

template<typename E>
E ListSliceCls<E>::removeAt(int index) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}

template<typename E>
E ListSliceCls<E>::removeLast() {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}

template<typename E>
void ListSliceCls<E>::removeRange(int start, int end) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}

template<typename E>
void ListSliceCls<E>::replaceRange(int start, int end, Iterable<E> newContents) {
    throw make<UnsupportedErrorCls>(__s("Cannot remove from a fixed-length list"));
}
