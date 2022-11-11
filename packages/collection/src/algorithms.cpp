#include "algorithms.hpp"
template<typename E>
int binarySearch(List<E> sortedList, E value, std::function<int(E , E )> compare) {
    compare |= defaultCompare;
    return <E, E>binarySearchBy(sortedList, identity, compare, value);
}

template<typename E, typename K>
int binarySearchBy(List<E> sortedList, std::function<K(E element)> keyOf, std::function<int(K , K )> compare, E value, int start, int end) {
    end = RangeErrorCls->checkValidRange(start, end, sortedList->length());
    auto min = start;
    auto max = end;
    auto key = keyOf(value);
    while ( < max) {
        auto mid = min + ((max - min) >> 1);
        auto element = sortedList[mid];
        auto comp = compare(keyOf(element), key);
        if (comp == 0) {
            return mid;
        }
        if ( < 0) {
            min = mid + 1;
        } else {
            max = mid;
        }
    }
    return -1;
}

template<typename E>
int lowerBound(List<E> sortedList, E value, std::function<int(E , E )> compare) {
    compare |= defaultCompare;
    return <E, E>lowerBoundBy(sortedList, identity, compare, value);
}

template<typename E, typename K>
int lowerBoundBy(List<E> sortedList, std::function<K(E element)> keyOf, std::function<int(K , K )> compare, E value, int start, int end) {
    end = RangeErrorCls->checkValidRange(start, end, sortedList->length());
    auto min = start;
    auto max = end;
    auto key = keyOf(value);
    while ( < max) {
        auto mid = min + ((max - min) >> 1);
        auto element = sortedList[mid];
        auto comp = compare(keyOf(element), key);
        if ( < 0) {
            min = mid + 1;
        } else {
            max = mid;
        }
    }
    return min;
}

void shuffle(List<any> elements, int start, int end, Random random) {
    random |= make<RandomCls>();
    end |= elements->length();
    auto length = end - start;
    while (length > 1) {
        auto pos = random->nextInt(length);
        length--;
        auto tmp1 = elements[start + pos];
        elements[start + pos] = elements[start + length];
        elements[start + length] = tmp1;
    }
}

template<typename E>
void reverse(List<E> elements, int start, int end) {
    end = RangeErrorCls->checkValidRange(start, end, elements->length());
    <E>_reverse(elements, start, end);
}

template<typename E>
void _reverse(List<E> elements, int start, int end) {
    for (;  < j; i++, j--) {
        auto tmp = elements[i];
        elements[i] = elements[j];
        elements[j] = tmp;
    }
}

template<typename E>
void insertionSort(List<E> elements, std::function<int(E , E )> compare, int end, int start) {
    compare |= defaultCompare;
    end |= elements->length();
    for (;  < end; pos++) {
        auto min = start;
        auto max = pos;
        auto element = elements[pos];
        while ( < max) {
            auto mid = min + ((max - min) >> 1);
            auto comparison = compare(element, elements[mid]);
            if ( < 0) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        elements->setRange(min + 1, pos + 1, elements, min);
        elements[min] = element;
    }
}

template<typename E, typename K>
void insertionSortBy(List<E> elements, std::function<K(E element)> keyOf, std::function<int(K a, K b)> compare, int start, int end) {
    end = RangeErrorCls->checkValidRange(start, end, elements->length());
    _movingInsertionSort(elements, keyOf, compare, start, end, elements, start);
}

template<typename E>
void mergeSort(List<E> elements, std::function<int(E , E )> compare, int end, int start) {
    end = RangeErrorCls->checkValidRange(start, end, elements->length());
    compare |= defaultCompare;
    auto length = end - start;
    if ( < 2) {
        return;
    }
    if ( < _mergeSortLimit) {
        insertionSort(elements, compare, start, end);
        return;
    }
    auto firstLength = (end - start) >> 1;
    auto middle = start + firstLength;
    auto secondLength = end - middle;
    auto scratchSpace = <E>filled(secondLength, elements[start]);
    std::function<E(E )> id = identity;
    _mergeSort(elements, id, compare, middle, end, scratchSpace, 0);
    auto firstTarget = end - firstLength;
    _mergeSort(elements, id, compare, start, middle, elements, firstTarget);
    _merge(id, compare, elements, firstTarget, end, scratchSpace, 0, secondLength, elements, start);
}

template<typename E, typename K>
void mergeSortBy(List<E> elements, std::function<K(E element)> keyOf, std::function<int(K a, K b)> compare, int start, int end) {
    end = RangeErrorCls->checkValidRange(start, end, elements->length());
    auto length = end - start;
    if ( < 2) {
        return;
    }
    if ( < _mergeSortLimit) {
        _movingInsertionSort(elements, keyOf, compare, start, end, elements, start);
        return;
    }
    auto middle = start + (length >> 1);
    auto firstLength = middle - start;
    auto secondLength = end - middle;
    auto scratchSpace = <E>filled(secondLength, elements[start]);
    _mergeSort(elements, keyOf, compare, middle, end, scratchSpace, 0);
    auto firstTarget = end - firstLength;
    _mergeSort(elements, keyOf, compare, start, middle, elements, firstTarget);
    _merge(keyOf, compare, elements, firstTarget, end, scratchSpace, 0, secondLength, elements, start);
}

template<typename E, typename K>
void _movingInsertionSort(List<E> list, std::function<K(E element)> keyOf, std::function<int(K , K )> compare, int start, int end, List<E> target, int targetOffset) {
    auto length = end - start;
    if (length == 0) {
        return;
    }
    target[targetOffset] = list[start];
    for (;  < length; i++) {
        auto element = list[start + i];
        auto elementKey = keyOf(element);
        auto min = targetOffset;
        auto max = targetOffset + i;
        while ( < max) {
            auto mid = min + ((max - min) >> 1);
            if (compare(elementKey, keyOf(target[mid])) < 0) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        target->setRange(min + 1, targetOffset + i + 1, target, min);
        target[min] = element;
    }
}

template<typename E, typename K>
void _mergeSort(List<E> elements, std::function<K(E element)> keyOf, std::function<int(K , K )> compare, int start, int end, List<E> target, int targetOffset) {
    auto length = end - start;
    if ( < _mergeSortLimit) {
        <E, K>_movingInsertionSort(elements, keyOf, compare, start, end, target, targetOffset);
        return;
    }
    auto middle = start + (length >> 1);
    auto firstLength = middle - start;
    auto secondLength = end - middle;
    auto targetMiddle = targetOffset + firstLength;
    _mergeSort(elements, keyOf, compare, middle, end, target, targetMiddle);
    _mergeSort(elements, keyOf, compare, start, middle, elements, middle);
    _merge(keyOf, compare, elements, middle, middle + firstLength, target, targetMiddle, targetMiddle + secondLength, target, targetOffset);
}

template<typename E, typename K>
void _merge(std::function<K(E element)> keyOf, std::function<int(K , K )> compare, List<E> firstList, int firstStart, int firstEnd, List<E> secondList, int secondStart, int secondEnd, List<E> target, int targetOffset) {
    assert( < firstEnd);
    assert( < secondEnd);
    auto cursor1 = firstStart;
    auto cursor2 = secondStart;
    auto firstElement = firstList[cursor1++];
    auto firstKey = keyOf(firstElement);
    auto secondElement = secondList[cursor2++];
    auto secondKey = keyOf(secondElement);
    while (true) {
        if (compare(firstKey, secondKey) <= 0) {
            target[targetOffset++] = firstElement;
            if (cursor1 == firstEnd) {
                break;
            }
            firstElement = firstList[cursor1++];
            firstKey = keyOf(firstElement);
        } else {
            target[targetOffset++] = secondElement;
            if (cursor2 != secondEnd) {
                secondElement = secondList[cursor2++];
                secondKey = keyOf(secondElement);
                continue;
            }
            target[targetOffset++] = firstElement;
            target->setRange(targetOffset, targetOffset + (firstEnd - cursor1), firstList, cursor1);
            return;
        }
    }
    target[targetOffset++] = secondElement;
    target->setRange(targetOffset, targetOffset + (secondEnd - cursor2), secondList, cursor2);
}

template<typename E>
void quickSort(List<E> elements, std::function<int(E a, E b)> compare, int start, int end) {
    end = RangeErrorCls->checkValidRange(start, end, elements->length());
    <E, E>_quickSort(elements, identity, compare, make<RandomCls>(), start, end);
}

template<typename E, typename K>
void quickSortBy(List<E> list, std::function<K(E element)> keyOf, std::function<int(K a, K b)> compare, int start, int end) {
    end = RangeErrorCls->checkValidRange(start, end, list->length());
    _quickSort(list, keyOf, compare, make<RandomCls>(), start, end);
}

template<typename E, typename K>
void _quickSort(List<E> list, std::function<K(E element)> keyOf, std::function<int(K a, K b)> compare, Random random, int start, int end) {
    minQuickSortLength = 24;
    auto length = end - start;
    while (length >= minQuickSortLength) {
        auto pivotIndex = random->nextInt(length) + start;
        auto pivot = list[pivotIndex];
        auto pivotKey = keyOf(pivot);
        auto endSmaller = start;
        auto startGreater = end;
        auto startPivots = end - 1;
        list[pivotIndex] = list[startPivots];
        list[startPivots] = pivot;
        while ( < startPivots) {
            auto current = list[endSmaller];
            auto relation = compare(keyOf(current), pivotKey);
            if ( < 0) {
                endSmaller++;
            } else {
                startPivots--;
                auto currentTarget = startPivots;
                list[endSmaller] = list[startPivots];
                if (relation > 0) {
                    startGreater--;
                    currentTarget = startGreater;
                    list[startPivots] = list[startGreater];
                }
                list[currentTarget] = current;
            }
        }
        if (endSmaller -  < end - startGreater) {
            _quickSort(list, keyOf, compare, random, start, endSmaller);
            start = startGreater;
        } else {
            _quickSort(list, keyOf, compare, random, startGreater, end);
            end = endSmaller;
        }
        length = end - start;
    }
    <E, K>_movingInsertionSort(list, keyOf, compare, start, end, list, start);
}
