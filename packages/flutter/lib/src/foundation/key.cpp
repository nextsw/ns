#include "key.hpp"
LocalKeyCls::LocalKeyCls() {
    {
        super->empty();
    }
}

String UniqueKeyCls::toString() {
    return __sf("[#%s]", shortHash(this));
}

template<typename T>
bool ValueKeyCls<T>::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<ValueKey<T>>(other) && other->value == value;
}

template<typename T>
int ValueKeyCls<T>::hashCode() {
    return ObjectCls->hash(runtimeType, value);
}

template<typename T>
String ValueKeyCls<T>::toString() {
    String valueString = T == StringCls? __sf("<'%s'>", value) : __sf("<%s>", value);
    if (runtimeType == <ValueKey<T>>make<_TypeLiteralCls>()->type) {
        return __sf("[%s]", valueString);
    }
    return __sf("[%s %s]", T, valueString);
}

template<typename T>
Type _TypeLiteralCls<T>::type() {
    return T;
}
