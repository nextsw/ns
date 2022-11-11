#include "algorithms.hpp"
template<typename E>
int binarySearch(int compare(E , E ) , List<E> sortedList, E value) {
    compare = defaultCompare;
    return <E, E>binarySearchBy(sortedList, identity, compare, value);
}

template<typename E, typename K>
int binarySearchBy(int compare(K , K ) , int end, K keyOf(E element) , List<E> sortedList, int start, E value) {
    end = RangeErrorCls->checkValidRange(start, end, sortedList->length());
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

template<typename E>
int lowerBound(int compare(E , E ) , List<E> sortedList, E value) {
    compare = defaultCompare;
    return <E, E>lowerBoundBy(sortedList, identity, compare, value);
}

template<typename E, typename K>
int lowerBoundBy(int compare(K , K ) , int end, K keyOf(E element) , List<E> sortedList, int start, E value) {
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

void shuffle(List elements, int end, Random random, int start) {
    random = make<RandomCls>();
    end = elements->length();
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
void reverse(List<E> elements, int end, int start) {
    end = RangeErrorCls->checkValidRange(start, end, elements->length());
    <E>_reverse(elements, start, end);
}

template<typename E>
void _reverse(List<E> elements, int end, int start) {
    for (;  < j; i++, j--) {
        auto tmp = elements[i];
        elements[i] = elements[j];
        elements[j] = tmp;
    }
}

template<typename E>
void insertionSort(int compare(E , E ) , List<E> elements, int end, int start) {
    compare = defaultCompare;
    end = elements->length();
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
void insertionSortBy(int compare(K a, K b) , List<E> elements, int end, K keyOf(E element) , int start) {
    end = RangeErrorCls->checkValidRange(start, end, elements->length());
    _movingInsertionSort(elements, keyOf, compare, start, end, elements, start);
}
