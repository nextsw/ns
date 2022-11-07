#ifndef INVOCATION_H
#define INVOCATION_H
#include <memory>




class Invocation {
public:

     Invocation();

    void  method(Symbol memberName, Map<Symbol, Object> namedArguments, Iterable<Object> positionalArguments);

    void  genericMethod(Symbol memberName, Map<Symbol, Object> namedArguments, Iterable<Object> positionalArguments, Iterable<Type> typeArguments);

    void  getter(Symbol name);

    void  setter(Object argument, Symbol memberName);

    Symbol memberName();

    List<Type> typeArguments();

    List<dynamic> positionalArguments();

    Map<Symbol, dynamic> namedArguments();

    bool isMethod();

    bool isGetter();

    bool isSetter();

    bool isAccessor();

private:

};

class _Invocation {
public:
    Symbol memberName;

    List<Type> typeArguments;


    void  method(Symbol memberName, Map<Symbol, Object> named, Iterable<Object> positional, Iterable<Type> types);

    void  getter(Symbol memberName);

    void  setter(Object argument, Symbol memberName);

    List<dynamic> positionalArguments();

    Map<Symbol, dynamic> namedArguments();

    bool isMethod();

    bool isGetter();

    bool isSetter();

    bool isAccessor();

private:
    List<Object> _positional;

    Map<Symbol, Object> _named;


    static List<Type> _ensureNonNullTypes(Iterable<Type> types);

};

#endif