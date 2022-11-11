#include "collections.hpp"
template<typename T>
bool setEquals(Set<T> a, Set<T> b) {
    if (a == nullptr) {
        return b == nullptr;
    }
    if (b == nullptr || a->length != b->length) {
        return false;
    }
    if (identical(a, b)) {
        return true;
    }
    for (T value : a) {
        if (!b->contains(value)) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool listEquals(List<T> a, List<T> b) {
    if (a == nullptr) {
        return b == nullptr;
    }
    if (b == nullptr || a->length() != b->length()) {
        return false;
    }
    if (identical(a, b)) {
        return true;
    }
    for (;  < a->length(); index += 1) {
        if (a[index] != b[index]) {
            return false;
        }
    }
    return true;
}

template<typename T, typename U>
bool mapEquals(Map<T, U> a, Map<T, U> b) {
    if (a == nullptr) {
        return b == nullptr;
    }
    if (b == nullptr || a->length() != b->length()) {
        return false;
    }
    if (identical(a, b)) {
        return true;
    }
    for (T key : a->keys()) {
        if (!b->containsKey(key) || b[key] != a[key]) {
            return false;
        }
    }
    return true;
}

template<typename T>
int binarySearch(List<T> sortedList, T value) {
    int min = 0;
    int max = sortedList->length();
    while ( < max) {
        int mid = min + ((max - min) >> 1);
        T element = sortedList[mid];
        int comp = element->compareTo(value);
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

template<typename T>
void mergeSort(List<T> list, std::function<int(T , T )> compare, int end, int start) {
    end |= list->length();
    compare |= <T>_defaultCompare();
    int length = end - start;
    if ( < 2) {
        return;
    }
    if ( < _kMergeSortLimit) {
        <T>_insertionSort(list, compare, start, end);
        return;
    }
    int middle = start + ((end - start) >> 1);
    int firstLength = middle - start;
    int secondLength = end - middle;
    List<T> scratchSpace = <T>filled(secondLength, list[start]);
    <T>_mergeSort(list, compare, middle, end, scratchSpace, 0);
    int firstTarget = end - firstLength;
    <T>_mergeSort(list, compare, start, middle, list, firstTarget);
    <T>_merge(compare, list, firstTarget, end, scratchSpace, 0, secondLength, list, start);
}

template<typename T>
Comparator<T> _defaultCompare() {
    return [=] (T value1,T value2)     {
        (as<Comparable<dynamic>>(value1))->compareTo(value2);
    };
}

template<typename T>
void _insertionSort(List<T> list, std::function<int(T , T )> compare, int end, int start) {
    compare |= <T>_defaultCompare();
    end |= list->length();
    for (;  < end; pos++) {
        int min = start;
        int max = pos;
        T element = list[pos];
        while ( < max) {
            int mid = min + ((max - min) >> 1);
            int comparison = compare(element, list[mid]);
            if ( < 0) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        list->setRange(min + 1, pos + 1, list, min);
        list[min] = element;
    }
}

template<typename T>
void _movingInsertionSort(List<T> list, std::function<int(T , T )> compare, int start, int end, List<T> target, int targetOffset) {
    int length = end - start;
    if (length == 0) {
        return;
    }
    target[targetOffset] = list[start];
    for (;  < length; i++) {
        T element = list[start + i];
        int min = targetOffset;
        int max = targetOffset + i;
        while ( < max) {
            int mid = min + ((max - min) >> 1);
            if (compare(element, target[mid]) < 0) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        target->setRange(min + 1, targetOffset + i + 1, target, min);
        target[min] = element;
    }
}

template<typename T>
void _mergeSort(List<T> list, std::function<int(T , T )> compare, int start, int end, List<T> target, int targetOffset) {
    int length = end - start;
    if ( < _kMergeSortLimit) {
        <T>_movingInsertionSort(list, compare, start, end, target, targetOffset);
        return;
    }
    int middle = start + (length >> 1);
    int firstLength = middle - start;
    int secondLength = end - middle;
    int targetMiddle = targetOffset + firstLength;
    <T>_mergeSort(list, compare, middle, end, target, targetMiddle);
    <T>_mergeSort(list, compare, start, middle, list, middle);
    <T>_merge(compare, list, middle, middle + firstLength, target, targetMiddle, targetMiddle + secondLength, target, targetOffset);
}

template<typename T>
void _merge(std::function<int(T , T )> compare, List<T> firstList, int firstStart, int firstEnd, List<T> secondList, int secondStart, int secondEnd, List<T> target, int targetOffset) {
    assert( < firstEnd);
    assert( < secondEnd);
    int cursor1 = firstStart;
    int cursor2 = secondStart;
    T firstElement = firstList[cursor1++];
    T secondElement = secondList[cursor2++];
    while (true) {
        if (compare(firstElement, secondElement) <= 0) {
            target[targetOffset++] = firstElement;
            if (cursor1 == firstEnd) {
                break;
            }
            firstElement = firstList[cursor1++];
        } else {
            target[targetOffset++] = secondElement;
            if (cursor2 != secondEnd) {
                secondElement = secondList[cursor2++];
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
