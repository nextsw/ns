#include "invocation.hpp"
void InvocationCls::method(Symbol memberName, Iterable<Object> positionalArguments, Map<Symbol, Object> namedArguments) {
    return _InvocationCls->method(memberName, nullptr, positionalArguments, namedArguments);
}

void InvocationCls::genericMethod(Symbol memberName, Iterable<Type> typeArguments, Iterable<Object> positionalArguments, Map<Symbol, Object> namedArguments) {
    return _InvocationCls->method(memberName, typeArguments, positionalArguments, namedArguments);
}

List<Type> InvocationCls::typeArguments() {
    return makeList();
}

bool InvocationCls::isAccessor() {
    return isGetter() || isSetter();
}

void _InvocationCls::method(Symbol memberName, Iterable<Type> types, Iterable<Object> positional, Map<Symbol, Object> named)

void _InvocationCls::getter(Symbol memberName)

void _InvocationCls::setter(Symbol memberName, Object argument)

List<dynamic> _InvocationCls::positionalArguments() {
    return _positional | makeList();
}

Map<Symbol, dynamic> _InvocationCls::namedArguments() {
    return _named | makeMap(makeList(), makeList();
}

bool _InvocationCls::isMethod() {
    return _named != nullptr;
}

bool _InvocationCls::isGetter() {
    return _positional == nullptr;
}

bool _InvocationCls::isSetter() {
    return _positional != nullptr && _named == nullptr;
}

bool _InvocationCls::isAccessor() {
    return _named == nullptr;
}

List<Type> _InvocationCls::_ensureNonNullTypes(Iterable<Type> types) {
    if (types == nullptr) {
        return makeList();
    }
    List<Type> typeArguments = <Type>unmodifiable(types);
    for (;  < typeArguments->length(); i++) {
        if (typeArguments[i] == nullptr) {
            throw ArgumentErrorCls->value(types, __s("types"), __s("Type arguments must be non-null, was null at index $i."));
        }
    }
    return typeArguments;
}
