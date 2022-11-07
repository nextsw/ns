#include "key.hpp"
LocalKey::LocalKey() {
    {
        super.empty();
    }
}

String UniqueKey::toString() {
    return "[#${shortHash(this)}]";
}

bool ValueKey::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is ValueKey<T> && other.value == value;
}

int ValueKey::hashCode() {
    return Object.hash(runtimeType, value);
}

String ValueKey::toString() {
    String valueString = T == String? "<'$value'>" : "<$value>";
    if (runtimeType == <ValueKey<T>>_TypeLiteral().type) {
        return "[$valueString]";
    }
    return "[$T $valueString]";
}

Type _TypeLiteral::type() {
    return T;
}
