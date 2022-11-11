#include "future.hpp"
template<typename T>
void FutureOrCls<T>::_() {
    throw make<UnsupportedErrorCls>(__s("FutureOr can't be instantiated"));
}
