#include "algorithms.hpp"
int binarySearchtemplate<typename E> (int compare(E , E ) , List<E> sortedList, E value) {
    compare = defaultCompare;
    return <E, E>binarySearchBy(sortedList, identity, compare, value);
}

int binarySearchBytemplate<typename E, typename K> (int compare(K , K ) , int end, K keyOf(E element) , List<E> sortedList, int start, E value) {
    end = RangeErrorCls->checkValidRange(start, end, sortedList->length);
    auto min = start;
    auto max = end;
    auto key = keyOf(value);
    while ( < max) {
        auto mid = min + ((max - min) >> 1);
        auto element = sortedList[mid];
        auto comp = compare(keyOf(element), key);
        if (comp == 0)         {
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

int lowerBoundtemplate<typename E> (int compare(E , E ) , List<E> sortedList, E value) {
    compare = defaultCompare;
    return <E, E>lowerBoundBy(sortedList, identity, compare, value);
}

int lowerBoundBytemplate<typename E, typename K> (int compare(K , K ) , int end, K keyOf(E element) , List<E> sortedList, int start, E value) {
    end = RangeErrorCls->checkValidRange(start, end, sortedList->length);
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

void shuffle(List elements, int end, Random random, int start) {
    random = make<RandomCls>();
    end = elements->length;
    auto length = end - start;
    while (length > 1) {
        auto pos = random->nextInt(length);
        length--;
        auto tmp1 = elements[start + pos];
        elements[start + pos] = elements[start + length];
        elements[start + length] = tmp1;
    }
}

void reversetemplate<typename E> (List<E> elements, int end, int start) {
    end = RangeErrorCls->checkValidRange(start, end, elements->length);
    <E>_reverse(elements, start, end);
}

void _reversetemplate<typename E> (List<E> elements, int end, int start) {
    for (;  < j; i++, j--) {
        auto tmp = elements[i];
        elements[i] = elements[j];
        elements[j] = tmp;
    }
}

void insertionSorttemplate<typename E> (int compare(E , E ) , List<E> elements, int end, int start) {
    compare = defaultCompare;
    end = elements->length;
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

void insertionSortBytemplate<typename E, typename K> (int compare(K a, K b) , List<E> elements, int end, K keyOf(E element) , int start) {
    end = RangeErrorCls->checkValidRange(start, end, elements->length);
    _movingInsertionSort(elements, keyOf, compare, start, end, elements, start);
}
