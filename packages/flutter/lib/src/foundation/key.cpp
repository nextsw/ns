#include "key.hpp"
LocalKeyCls::LocalKeyCls() {
    {
        super->empty();
    }
}

String UniqueKeyCls::toString() {
    return "[#${shortHash(this)}]";
}

template<typename T> bool ValueKeyCls<T>::==(Object other) {
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is ValueKey<T> && other->value == value;
}

template<typename T> int ValueKeyCls<T>::hashCode() {
    return ObjectCls->hash(runtimeType, value);
}

template<typename T> String ValueKeyCls<T>::toString() {
    String valueString = TCls == StringCls? "<'$value'>" : "<$value>";
    if (runtimeType == <ValueKey<T>>make<_TypeLiteralCls>()->type) {
        return "[$valueString]";
    }
    return "[$T $valueString]";
}

template<typename T> Type _TypeLiteralCls<T>::type() {
    return TCls;
}
