#include "comparable.hpp"
template<typename T>
int ComparableCls<T>::compare(Comparable a, Comparable b) {
    return a->compareTo(b);
}
