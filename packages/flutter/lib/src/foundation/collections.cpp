#include "collections.hpp"
bool setEqualstemplate<typename T> (Set<T> a, Set<T> b) {
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

bool listEqualstemplate<typename T> (List<T> a, List<T> b) {
    if (a == nullptr) {
        return b == nullptr;
    }
    if (b == nullptr || a->length != b->length) {
        return false;
    }
    if (identical(a, b)) {
        return true;
    }
    for (;  < a->length; index = 1) {
        if (a[index] != b[index]) {
            return false;
        }
    }
    return true;
}

bool mapEqualstemplate<typename T, typename U> (Map<T, U> a, Map<T, U> b) {
    if (a == nullptr) {
        return b == nullptr;
    }
    if (b == nullptr || a->length != b->length) {
        return false;
    }
    if (identical(a, b)) {
        return true;
    }
    for (T key : a->keys) {
        if (!b->containsKey(key) || b[key] != a[key]) {
            return false;
        }
    }
    return true;
}

int binarySearchtemplate<typename T : Comparable<Object>> (List<T> sortedList, T value) {
    int min = 0;
    int max = sortedList->length;
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

void mergeSorttemplate<typename T> (int compare(T , T ) , int end, List<T> list, int start) {
    end = list->length;
    compare = <T>_defaultCompare();
    int length = end - start;
    if ( < 2) {
        return;
    }
    if ( < _kMergeSortLimit) {
        <T>_insertionSort(listcompare, start, end);
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

Comparator<T> _defaultComparetemplate<typename T> () {
    return [=] (T value1,T value2)     {
        (((Comparable<dynamic>)value1))->compareTo(value2);
    };
}

void _insertionSorttemplate<typename T> (int compare(T , T ) , int end, List<T> list, int start) {
    compare = <T>_defaultCompare();
    end = list->length;
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

void _movingInsertionSorttemplate<typename T> (int compare(T , T ) , int end, List<T> list, int start, List<T> target, int targetOffset) {
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

void _mergeSorttemplate<typename T> (int compare(T , T ) , int end, List<T> list, int start, List<T> target, int targetOffset) {
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

void _mergetemplate<typename T> (int compare(T , T ) , int firstEnd, List<T> firstList, int firstStart, int secondEnd, List<T> secondList, int secondStart, List<T> target, int targetOffset) {
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
