#include "algorithms.hpp"
template<typename E>
int binarySearch(std::function<int(E , E )> compare, List<E> sortedList, E value) {
    compare = defaultCompare;
    return <E, E>binarySearchBy(sortedList, identity, compare, value);
}

template<typename E, typename K>
int binarySearchBy(std::function<int(K , K )> compare, int end, std::function<K(E element)> keyOf, List<E> sortedList, int start, E value) {
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
int lowerBound(std::function<int(E , E )> compare, List<E> sortedList, E value) {
    compare = defaultCompare;
    return <E, E>lowerBoundBy(sortedList, identity, compare, value);
}

template<typename E, typename K>
int lowerBoundBy(std::function<int(K , K )> compare, int end, std::function<K(E element)> keyOf, List<E> sortedList, int start, E value) {
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
void insertionSort(std::function<int(E , E )> compare, List<E> elements, int end, int start) {
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
void insertionSortBy(std::function<int(K a, K b)> compare, List<E> elements, int end, std::function<K(E element)> keyOf, int start) {
    end = RangeErrorCls->checkValidRange(start, end, elements->length());
    _movingInsertionSort(elements, keyOf, compare, start, end, elements, start);
}
