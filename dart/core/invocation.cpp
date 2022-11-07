#include "invocation.hpp"
void Invocation::method(Symbol memberName, Map<Symbol, Object> namedArguments, Iterable<Object> positionalArguments) {
    return _Invocation.method(memberName, nullptr, positionalArguments, namedArguments);
}

void Invocation::genericMethod(Symbol memberName, Map<Symbol, Object> namedArguments, Iterable<Object> positionalArguments, Iterable<Type> typeArguments) {
    return _Invocation.method(memberName, typeArguments, positionalArguments, namedArguments);
}

List<Type> Invocation::typeArguments() {
    return const ;
}

bool Invocation::isAccessor() {
    return isGetter || isSetter;
}

void _Invocation::method(Symbol memberName, Map<Symbol, Object> named, Iterable<Object> positional, Iterable<Type> types)

void _Invocation::getter(Symbol memberName)

void _Invocation::setter(Object argument, Symbol memberName)

List<dynamic> _Invocation::positionalArguments() {
    return _positional ?? const ;
}

Map<Symbol, dynamic> _Invocation::namedArguments() {
    return _named ?? const ;
}

bool _Invocation::isMethod() {
    return _named != nullptr;
}

bool _Invocation::isGetter() {
    return _positional == nullptr;
}

bool _Invocation::isSetter() {
    return _positional != nullptr && _named == nullptr;
}

bool _Invocation::isAccessor() {
    return _named == nullptr;
}

List<Type> _Invocation::_ensureNonNullTypes(Iterable<Type> types) {
    if (types == nullptr)     {
        return const ;
    }
    List<Type> typeArguments = <Type>unmodifiable(types);
    for (;  < typeArguments.length; i++) {
        if (typeArguments[i] == nullptr) {
            ;
        }
    }
    return typeArguments;
}
