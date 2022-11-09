#include "weak.hpp"
template<typename T : Object> String ExpandoCls<T>::toString() {
    return "Expando:$name";
}
