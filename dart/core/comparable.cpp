#include "comparable.hpp"
template<typename T>
int ComparableCls<T>::compare(Comparable<any> a, Comparable<any> b) {
    return a->compareTo(b);
}
