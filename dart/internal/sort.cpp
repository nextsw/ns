#include "sort.hpp"
template<typename E>
void SortCls::sort(List<E> a, std::function<int(E a, E b)> compare) {
    _doSort(a, 0, a->length - 1, compare);
}

template<typename E>
void SortCls::sortRange(List<E> a, std::function<int(E a, E b)> compare, int from, int to) {
    if (( < 0) || (to > a->length) || ( < from)) {
        ;
    }
    _doSort(a, from, to - 1, compare);
}

template<typename E>
void SortCls::_doSort(List<E> a, std::function<int(E a, E b)> compare, int left, int right) {
    if ((right - left) <= _INSERTION_SORT_THRESHOLDCls) {
        _insertionSort(a, left, right, compare);
    } else {
        _dualPivotQuicksort(a, left, right, compare);
    }
}

template<typename E>
void SortCls::_insertionSort(List<E> a, std::function<int(E a, E b)> compare, int left, int right) {
    for (; i <= right; i++) {
        auto el = a[i];
        int j = i;
        while ((j > left) && (compare(a[j - 1], el) > 0)) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = el;
    }
}

template<typename E>
void SortCls::_dualPivotQuicksort(List<E> a, std::function<int(E a, E b)> compare, int left, int right) {
    assert(right - left > _INSERTION_SORT_THRESHOLDCls);
    int sixth = (right - left + 1) ~/ 6;
    int index1 = left + sixth;
    int index5 = right - sixth;
    int index3 = (left + right) ~/ 2;
    int index2 = index3 - sixth;
    int index4 = index3 + sixth;
    auto el1 = a[index1];
    auto el2 = a[index2];
    auto el3 = a[index3];
    auto el4 = a[index4];
    auto el5 = a[index5];
    if (compare(el1, el2) > 0) {
        auto t = el1;
        el1 = el2;
        el2 = t;
    }
    if (compare(el4, el5) > 0) {
        auto t = el4;
        el4 = el5;
        el5 = t;
    }
    if (compare(el1, el3) > 0) {
        auto t = el1;
        el1 = el3;
        el3 = t;
    }
    if (compare(el2, el3) > 0) {
        auto t = el2;
        el2 = el3;
        el3 = t;
    }
    if (compare(el1, el4) > 0) {
        auto t = el1;
        el1 = el4;
        el4 = t;
    }
    if (compare(el3, el4) > 0) {
        auto t = el3;
        el3 = el4;
        el4 = t;
    }
    if (compare(el2, el5) > 0) {
        auto t = el2;
        el2 = el5;
        el5 = t;
    }
    if (compare(el2, el3) > 0) {
        auto t = el2;
        el2 = el3;
        el3 = t;
    }
    if (compare(el4, el5) > 0) {
        auto t = el4;
        el4 = el5;
        el5 = t;
    }
    auto pivot1 = el2;
    auto pivot2 = el4;
    a[index1] = el1;
    a[index3] = el3;
    a[index5] = el5;
    a[index2] = a[left];
    a[index4] = a[right];
    int less = left + 1;
    int great = right - 1;
    bool pivots_are_equal = (compare(pivot1, pivot2) == 0);
    if (pivots_are_equal) {
        auto pivot = pivot1;
        for (; k <= great; k++) {
            auto ak = a[k];
            int comp = compare(ak, pivot);
            if (comp == 0)             {
                continue;
            }
            if ( < 0) {
                if (k != less) {
                    a[k] = a[less];
                    a[less] = ak;
                }
                less++;
            } else {
                while (true) {
                    comp = compare(a[great], pivot);
                    if (comp > 0) {
                        great--;
                        continue;
                    } else                     {
                        if ( < 0) {
                        a[k] = a[less];
                        a[less++] = a[great];
                        a[great--] = ak;
                        break;
                    } else {
                        a[k] = a[great];
                        a[great--] = ak;
                        break;
                    }
;
                    }                }
            }
        }
    } else {
        for (; k <= great; k++) {
            auto ak = a[k];
            int comp_pivot1 = compare(ak, pivot1);
            if ( < 0) {
                if (k != less) {
                    a[k] = a[less];
                    a[less] = ak;
                }
                less++;
            } else {
                int comp_pivot2 = compare(ak, pivot2);
                if (comp_pivot2 > 0) {
                    while (true) {
                        int comp = compare(a[great], pivot2);
                        if (comp > 0) {
                            great--;
                            if ( < k)                             {
                                break;
                            }
                            continue;
                        } else {
                            comp = compare(a[great], pivot1);
                            if ( < 0) {
                                a[k] = a[less];
                                a[less++] = a[great];
                                a[great--] = ak;
                            } else {
                                a[k] = a[great];
                                a[great--] = ak;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    a[left] = a[less - 1];
    a[less - 1] = pivot1;
    a[right] = a[great + 1];
    a[great + 1] = pivot2;
    _doSort(a, left, less - 2, compare);
    _doSort(a, great + 2, right, compare);
    if (pivots_are_equal) {
        return;
    }
    if ( < index1 && great > index5) {
        while (compare(a[less], pivot1) == 0) {
            less++;
        }
        while (compare(a[great], pivot2) == 0) {
            great--;
        }
        for (; k <= great; k++) {
            auto ak = a[k];
            int comp_pivot1 = compare(ak, pivot1);
            if (comp_pivot1 == 0) {
                if (k != less) {
                    a[k] = a[less];
                    a[less] = ak;
                }
                less++;
            } else {
                int comp_pivot2 = compare(ak, pivot2);
                if (comp_pivot2 == 0) {
                    while (true) {
                        int comp = compare(a[great], pivot2);
                        if (comp == 0) {
                            great--;
                            if ( < k)                             {
                                break;
                            }
                            continue;
                        } else {
                            comp = compare(a[great], pivot1);
                            if ( < 0) {
                                a[k] = a[less];
                                a[less++] = a[great];
                                a[great--] = ak;
                            } else {
                                a[k] = a[great];
                                a[great--] = ak;
                            }
                            break;
                        }
                    }
                }
            }
        }
        _doSort(a, less, great, compare);
    } else {
        _doSort(a, less, great, compare);
    }
}
