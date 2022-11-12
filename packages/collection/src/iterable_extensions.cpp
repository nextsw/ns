#include "iterable_extensions.hpp"
template<typename T>
List<T> IterableExtensionCls<T>::sample(int count, Random random) {
    RangeErrorCls->checkNotNegative(count, __s("count"));
    auto iterator = this->iterator;
    auto chosen = makeList();
    for (;  < count; i++) {
        if (iterator->moveNext()) {
            chosen->add(iterator->current);
        } else {
            return chosen;
        }
    }
    auto index = count;
    random |= make<RandomCls>();
    while (iterator->moveNext()) {
        index++;
        auto position = random->nextInt(index);
        if ( < count) {
            chosen[position] = iterator->current;
        }
    }
    return chosen;
}

template<typename T>
Iterable<T> IterableExtensionCls<T>::whereNot(std::function<bool(T element)> test) {
    return where([=] (Unknown  element) {
        !test(element);
    });
}

template<typename T>
List<T> IterableExtensionCls<T>::sorted(Comparator<T> compare) {
    return _c1;
}

template<typename T>
template<typename K>
List<T> IterableExtensionCls<T>::sortedBy(std::function<K(T element)> keyOf) {
    auto _c1 = for (auto _x2 : this) {{    list2.add(_x2);}list2;_c1.sort(compare);for (auto _x1 : this) {{    list1.add(_x1);}auto elements = list1;
    <T, K>mergeSortBy(elements, keyOf, compareComparable);
    return elements;
}

template<typename T>
template<typename K>
List<T> IterableExtensionCls<T>::sortedByCompare(std::function<K(T element)> keyOf, Comparator<K> compare) {
    for (auto _x1 : this) {{    list1.add(_x1);}auto elements = list1;
    <T, K>mergeSortBy(elements, keyOf, compare);
    return elements;
}

template<typename T>
bool IterableExtensionCls<T>::isSorted(Comparator<T> compare) {
    auto iterator = this->iterator;
    if (!iterator->moveNext()) {
        return true;
    }
    auto previousElement = iterator->current;
    while (iterator->moveNext()) {
        auto element = iterator->current;
        if (compare(previousElement, element) > 0) {
            return false;
        }
        previousElement = element;
    }
    return true;
}

template<typename T>
template<typename K>
bool IterableExtensionCls<T>::isSortedBy(std::function<K(T element)> keyOf) {
    auto iterator = this->iterator;
    if (!iterator->moveNext()) {
        return true;
    }
    auto previousKey = keyOf(iterator->current);
    while (iterator->moveNext()) {
        auto key = keyOf(iterator->current);
        if (previousKey->compareTo(key) > 0) {
            return false;
        }
        previousKey = key;
    }
    return true;
}

template<typename T>
template<typename K>
bool IterableExtensionCls<T>::isSortedByCompare(std::function<K(T element)> keyOf, Comparator<K> compare) {
    auto iterator = this->iterator;
    if (!iterator->moveNext()) {
        return true;
    }
    auto previousKey = keyOf(iterator->current);
    while (iterator->moveNext()) {
        auto key = keyOf(iterator->current);
        if (compare(previousKey, key) > 0) {
            return false;
        }
        previousKey = key;
    }
    return true;
}

template<typename T>
void IterableExtensionCls<T>::forEachIndexed(std::function<void(int index, T element)> action) {
    auto index = 0;
    for (auto element : this) {
        action(index++, element);
    }
}

template<typename T>
void IterableExtensionCls<T>::forEachWhile(std::function<bool(T element)> action) {
    for (auto element : this) {
        if (!action(element)) {
            break;
        }
    }
}

template<typename T>
void IterableExtensionCls<T>::forEachIndexedWhile(std::function<bool(int index, T element)> action) {
    auto index = 0;
    for (auto element : this) {
        if (!action(index++, element)) {
            break;
        }
    }
}

template<typename T>
template<typename R>
Iterable<R> IterableExtensionCls<T>::mapIndexed(std::function<R(int index, T element)> convert) {
    auto index = 0;
    for (auto element : this) {
        yield convert(index++, element);
    }
}

template<typename T>
Iterable<T> IterableExtensionCls<T>::whereIndexed(std::function<bool(int index, T element)> test) {
    auto index = 0;
    for (auto element : this) {
        if (test(index++, element)) {
            yield element;
        }
    }
}

template<typename T>
Iterable<T> IterableExtensionCls<T>::whereNotIndexed(std::function<bool(int index, T element)> test) {
    auto index = 0;
    for (auto element : this) {
        if (!test(index++, element)) {
            yield element;
        }
    }
}

template<typename T>
template<typename R>
Iterable<R> IterableExtensionCls<T>::expandIndexed(std::function<Iterable<R>(int index, T element)> expand) {
    auto index = 0;
    for (auto element : this) {
        yield expand(index++, element);
    }
}

template<typename T>
T IterableExtensionCls<T>::reduceIndexed(std::function<T(int index, T previous, T element)> combine) {
    auto iterator = this->iterator;
    if (!iterator->moveNext()) {
        throw make<StateErrorCls>(__s("no elements"));
    }
    auto index = 1;
    auto result = iterator->current;
    while (iterator->moveNext()) {
        result = combine(index++, result, iterator->current);
    }
    return result;
}

template<typename T>
template<typename R>
R IterableExtensionCls<T>::foldIndexed(R initialValue, std::function<R(int index, R previous, T element)> combine) {
    auto result = initialValue;
    auto index = 0;
    for (auto element : this) {
        result = combine(index++, result, element);
    }
    return result;
}

template<typename T>
T IterableExtensionCls<T>::firstWhereOrNull(std::function<bool(T element)> test) {
    for (auto element : this) {
        if (test(element)) {
            return element;
        }
    }
    return nullptr;
}

template<typename T>
T IterableExtensionCls<T>::firstWhereIndexedOrNull(std::function<bool(int index, T element)> test) {
    auto index = 0;
    for (auto element : this) {
        if (test(index++, element)) {
            return element;
        }
    }
    return nullptr;
}

template<typename T>
T IterableExtensionCls<T>::firstOrNull() {
    auto iterator = this->iterator;
    if (iterator->moveNext()) {
        return iterator->current;
    }
    return nullptr;
}

template<typename T>
T IterableExtensionCls<T>::lastWhereOrNull(std::function<bool(T element)> test) {
    T result;
    for (auto element : this) {
        if (test(element)) {
            result = element;
        }
    }
    return result;
}

template<typename T>
T IterableExtensionCls<T>::lastWhereIndexedOrNull(std::function<bool(int index, T element)> test) {
    T result;
    auto index = 0;
    for (auto element : this) {
        if (test(index++, element)) {
            result = element;
        }
    }
    return result;
}

template<typename T>
T IterableExtensionCls<T>::lastOrNull() {
    if (isEmpty) {
        return nullptr;
    }
    return last;
}

template<typename T>
T IterableExtensionCls<T>::singleWhereOrNull(std::function<bool(T element)> test) {
    T result;
    auto found = false;
    for (auto element : this) {
        if (test(element)) {
            if (!found) {
                result = element;
                found = true;
            } else {
                return nullptr;
            }
        }
    }
    return result;
}

template<typename T>
T IterableExtensionCls<T>::singleWhereIndexedOrNull(std::function<bool(int index, T element)> test) {
    T result;
    auto found = false;
    auto index = 0;
    for (auto element : this) {
        if (test(index++, element)) {
            if (!found) {
                result = element;
                found = true;
            } else {
                return nullptr;
            }
        }
    }
    return result;
}

template<typename T>
T IterableExtensionCls<T>::singleOrNull() {
    auto iterator = this->iterator;
    if (iterator->moveNext()) {
        auto result = iterator->current;
        if (!iterator->moveNext()) {
            return result;
        }
    }
    return nullptr;
}

template<typename T>
template<typename K, typename G>
Map<K, G> IterableExtensionCls<T>::groupFoldBy(std::function<K(T element)> keyOf, std::function<G(G previous, T element)> combine) {
    auto result = makeMap(makeList(), makeList();
    for (auto element : this) {
        auto key = keyOf(element);
        result[key] = combine(result[key], element);
    }
    return result;
}

template<typename T>
template<typename K>
Map<K, Set<T>> IterableExtensionCls<T>::groupSetsBy(std::function<K(T element)> keyOf) {
    auto result = makeMap(makeList(), makeList();
    for (auto element : this) {
        (result[keyOf(element)] ??= makeSet())->add(element);
    }
    return result;
}

template<typename T>
template<typename K>
Map<K, List<T>> IterableExtensionCls<T>::groupListsBy(std::function<K(T element)> keyOf) {
    auto result = makeMap(makeList(), makeList();
    for (auto element : this) {
        (result[keyOf(element)] ??= makeList())->add(element);
    }
    return result;
}

template<typename T>
Iterable<List<T>> IterableExtensionCls<T>::splitBefore(std::function<bool(T element)> test) {
    return splitBeforeIndexed([=] (Unknown  _,Unknown  element) {
        test(element);
    });
}

template<typename T>
Iterable<List<T>> IterableExtensionCls<T>::splitAfter(std::function<bool(T element)> test) {
    return splitAfterIndexed([=] (Unknown  _,Unknown  element) {
        test(element);
    });
}

template<typename T>
Iterable<List<T>> IterableExtensionCls<T>::splitBetween(std::function<bool(T first, T second)> test) {
    return splitBetweenIndexed([=] (Unknown  _,Unknown  first,Unknown  second) {
        test(first, second);
    });
}

template<typename T>
Iterable<List<T>> IterableExtensionCls<T>::splitBeforeIndexed(std::function<bool(int index, T element)> test) {
    auto iterator = this->iterator;
    if (!iterator->moveNext()) {
        return;
    }
    auto index = 1;
    auto chunk = makeList(ArrayItem);
    while (iterator->moveNext()) {
        auto element = iterator->current;
        if (test(index++, element)) {
            yield chunk;
            chunk = makeList();
        }
        chunk->add(element);
    }
    yield chunk;
}

template<typename T>
Iterable<List<T>> IterableExtensionCls<T>::splitAfterIndexed(std::function<bool(int index, T element)> test) {
    auto index = 0;
    List<T> chunk;
    for (auto element : this) {
        (chunk ??= makeList())->add(element);
        if (test(index++, element)) {
            yield chunk;
            chunk = nullptr;
        }
    }
    if (chunk != nullptr) {
        yield chunk;
    }
}

template<typename T>
Iterable<List<T>> IterableExtensionCls<T>::splitBetweenIndexed(std::function<bool(int index, T first, T second)> test) {
    auto iterator = this->iterator;
    if (!iterator->moveNext()) {
        return;
    }
    auto previous = iterator->current;
    auto chunk = makeList(ArrayItem);
    auto index = 1;
    while (iterator->moveNext()) {
        auto element = iterator->current;
        if (test(index++, previous, element)) {
            yield chunk;
            chunk = makeList();
        }
        chunk->add(element);
        previous = element;
    }
    yield chunk;
}

template<typename T>
bool IterableExtensionCls<T>::none(std::function<bool(T )> test) {
    for (auto element : this) {
        if (test(element)) {
            return false;
        }
    }
    return true;
}

template<typename T>
Iterable<List<T>> IterableExtensionCls<T>::slices(int length) {
    if ( < 1) {
        throw RangeErrorCls->range(length, 1, nullptr, __s("length"));
    }
    auto iterator = this->iterator;
    while (iterator->moveNext()) {
        auto slice = makeList(ArrayItem);
        for (;  < length && iterator->moveNext(); i++) {
            slice->add(iterator->current);
        }
        yield slice;
    }
}

template<typename T>
Iterable<T> IterableNullableExtensionCls<T>::whereNotNull() {
    for (auto element : this) {
        if (element != nullptr) {
            yield element;
        }
    }
}

num IterableNumberExtensionCls::minOrNull() {
    auto iterator = this->iterator;
    if (iterator->moveNext()) {
        auto value = iterator->current;
        if (value->isNaN) {
            return value;
        }
        while (iterator->moveNext()) {
            auto newValue = iterator->current;
            if (newValue->isNaN) {
                return newValue;
            }
            if ( < value) {
                value = newValue;
            }
        }
        return value;
    }
    return nullptr;
}

num IterableNumberExtensionCls::min() {
    return minOrNull() | (throw make<StateErrorCls>(__s("No element")));
}

num IterableNumberExtensionCls::maxOrNull() {
    auto iterator = this->iterator;
    if (iterator->moveNext()) {
        auto value = iterator->current;
        if (value->isNaN) {
            return value;
        }
        while (iterator->moveNext()) {
            auto newValue = iterator->current;
            if (newValue->isNaN) {
                return newValue;
            }
            if (newValue > value) {
                value = newValue;
            }
        }
        return value;
    }
    return nullptr;
}

num IterableNumberExtensionCls::max() {
    return maxOrNull() | (throw make<StateErrorCls>(__s("No element")));
}

num IterableNumberExtensionCls::sum() {
    num result = 0;
    for (auto value : this) {
        result += value;
    }
    return result;
}

double IterableNumberExtensionCls::average() {
    auto result = 0.0;
    auto count = 0;
    for (auto value : this) {
        count += 1;
        result += (value - result) / count;
    }
    if (count == 0) {
        throw make<StateErrorCls>(__s("No elements"));
    }
    return result;
}

int IterableIntegerExtensionCls::minOrNull() {
    auto iterator = this->iterator;
    if (iterator->moveNext()) {
        auto value = iterator->current;
        while (iterator->moveNext()) {
            auto newValue = iterator->current;
            if ( < value) {
                value = newValue;
            }
        }
        return value;
    }
    return nullptr;
}

int IterableIntegerExtensionCls::min() {
    return minOrNull() | (throw make<StateErrorCls>(__s("No element")));
}

int IterableIntegerExtensionCls::maxOrNull() {
    auto iterator = this->iterator;
    if (iterator->moveNext()) {
        auto value = iterator->current;
        while (iterator->moveNext()) {
            auto newValue = iterator->current;
            if (newValue > value) {
                value = newValue;
            }
        }
        return value;
    }
    return nullptr;
}

int IterableIntegerExtensionCls::max() {
    return maxOrNull() | (throw make<StateErrorCls>(__s("No element")));
}

int IterableIntegerExtensionCls::sum() {
    auto result = 0;
    for (auto value : this) {
        result += value;
    }
    return result;
}

double IterableIntegerExtensionCls::average() {
    auto average = 0;
    auto remainder = 0;
    auto count = 0;
    for (auto value : this) {
        count += 1;
        auto delta = value - average + remainder;
        average += delta ~/ count;
        remainder = delta->remainder(count);
    }
    if (count == 0) {
        throw make<StateErrorCls>(__s("No elements"));
    }
    return average + remainder / count;
}

double IterableDoubleExtensionCls::minOrNull() {
    auto iterator = this->iterator;
    if (iterator->moveNext()) {
        auto value = iterator->current;
        if (value->isNaN) {
            return value;
        }
        while (iterator->moveNext()) {
            auto newValue = iterator->current;
            if (newValue->isNaN) {
                return newValue;
            }
            if ( < value) {
                value = newValue;
            }
        }
        return value;
    }
    return nullptr;
}

double IterableDoubleExtensionCls::min() {
    return minOrNull() | (throw make<StateErrorCls>(__s("No element")));
}

double IterableDoubleExtensionCls::maxOrNull() {
    auto iterator = this->iterator;
    if (iterator->moveNext()) {
        auto value = iterator->current;
        if (value->isNaN) {
            return value;
        }
        while (iterator->moveNext()) {
            auto newValue = iterator->current;
            if (newValue->isNaN) {
                return newValue;
            }
            if (newValue > value) {
                value = newValue;
            }
        }
        return value;
    }
    return nullptr;
}

double IterableDoubleExtensionCls::max() {
    return maxOrNull() | (throw make<StateErrorCls>(__s("No element")));
}

double IterableDoubleExtensionCls::sum() {
    auto result = 0.0;
    for (auto value : this) {
        result += value;
    }
    return result;
}

template<typename T>
Iterable<T> IterableIterableExtensionCls<T>::flattened() {
    for (auto elements : this) {
        yield elements;
    }
}

template<typename T>
T IterableComparableExtensionCls<T>::minOrNull() {
    auto iterator = this->iterator;
    if (iterator->moveNext()) {
        auto value = iterator->current;
        while (iterator->moveNext()) {
            auto newValue = iterator->current;
            if (value->compareTo(newValue) > 0) {
                value = newValue;
            }
        }
        return value;
    }
    return nullptr;
}

template<typename T>
T IterableComparableExtensionCls<T>::min() {
    return minOrNull() | (throw make<StateErrorCls>(__s("No element")));
}

template<typename T>
T IterableComparableExtensionCls<T>::maxOrNull() {
    auto iterator = this->iterator;
    if (iterator->moveNext()) {
        auto value = iterator->current;
        while (iterator->moveNext()) {
            auto newValue = iterator->current;
            if (value->compareTo(newValue) < 0) {
                value = newValue;
            }
        }
        return value;
    }
    return nullptr;
}

template<typename T>
T IterableComparableExtensionCls<T>::max() {
    return maxOrNull() | (throw make<StateErrorCls>(__s("No element")));
}

template<typename T>
List<T> IterableComparableExtensionCls<T>::sorted(Comparator<T> compare) {
    return _c1;
}

template<typename T>
bool IterableComparableExtensionCls<T>::isSorted(Comparator<T> compare) {
    if (compare != nullptr) {
            auto _c1 = for (auto _x2 : this) {    {        list2.add(_x2);    }list2;    _c1.sort(compare);return make<IterableExtensionCls>(this)->isSorted(compare);
    }
    auto iterator = this->iterator;
    if (!iterator->moveNext()) {
        return true;
    }
    auto previousElement = iterator->current;
    while (iterator->moveNext()) {
        auto element = iterator->current;
        if (previousElement->compareTo(element) > 0) {
            return false;
        }
        previousElement = element;
    }
    return true;
}

template<typename T>
Comparator<T> ComparatorExtensionCls<T>::inverse() {
    return [=] (T a,T b) {
        this(b, a);
    };
}

template<typename T>
template<typename R>
Comparator<R> ComparatorExtensionCls<T>::compareBy(std::function<T(R )> keyOf) {
    return [=] (R a,R b) {
        this(keyOf(a), keyOf(b));
    };
}

template<typename T>
Comparator<T> ComparatorExtensionCls<T>::then(Comparator<T> tieBreaker) {
    return [=] (T a,T b) {
        auto result = this(a, b);
        if (result == 0) {
            result = tieBreaker(a, b);
        }
        return result;
    };
}
