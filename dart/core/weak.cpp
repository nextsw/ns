#include "weak.hpp"
template<typename T>
String ExpandoCls<T>::toString() {
    return __sf("Expando:%s", name);
}
