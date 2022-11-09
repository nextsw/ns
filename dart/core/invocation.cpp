#include "invocation.hpp"
void InvocationCls::method(Symbol memberName, Map<Symbol, Object> namedArguments, Iterable<Object> positionalArguments) {
    return _InvocationCls->method(memberName, nullptr, positionalArguments, namedArguments);
}

void InvocationCls::genericMethod(Symbol memberName, Map<Symbol, Object> namedArguments, Iterable<Object> positionalArguments, Iterable<Type> typeArguments) {
    return _InvocationCls->method(memberName, typeArguments, positionalArguments, namedArguments);
}

List<Type> InvocationCls::typeArguments() {
    return makeList();
}

bool InvocationCls::isAccessor() {
    return isGetter || isSetter;
}

void _InvocationCls::method(Symbol memberName, Map<Symbol, Object> named, Iterable<Object> positional, Iterable<Type> types)

void _InvocationCls::getter(Symbol memberName)

void _InvocationCls::setter(Object argument, Symbol memberName)

List<dynamic> _InvocationCls::positionalArguments() {
    return _positional ?? makeList();
}

Map<Symbol, dynamic> _InvocationCls::namedArguments() {
    return _named ?? makeMap(makeList(), makeList();
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
    if (types == nullptr)     {
        return makeList();
    }
    List<Type> typeArguments = <Type>unmodifiable(types);
    for (;  < typeArguments->length; i++) {
        if (typeArguments[i] == nullptr) {
            ;
        }
    }
    return typeArguments;
}
