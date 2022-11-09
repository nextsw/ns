#ifndef DART_CORE_INVOCATION
#define DART_CORE_INVOCATION
#include <base.hpp>

#include <dart/core/core.hpp>


class InvocationCls : public ObjectCls {
public:

     InvocationCls();
    virtual void  method(Symbol memberName, Map<Symbol, Object> namedArguments, Iterable<Object> positionalArguments);

    virtual void  genericMethod(Symbol memberName, Map<Symbol, Object> namedArguments, Iterable<Object> positionalArguments, Iterable<Type> typeArguments);

    virtual void  getter(Symbol name);
    virtual void  setter(Object argument, Symbol memberName);
    virtual Symbol memberName();
    virtual List<Type> typeArguments();

    virtual List<dynamic> positionalArguments();
    virtual Map<Symbol, dynamic> namedArguments();
    virtual bool isMethod();
    virtual bool isGetter();
    virtual bool isSetter();
    virtual bool isAccessor();

private:

};
using Invocation = std::shared_ptr<InvocationCls>;

class _InvocationCls : public ObjectCls {
public:
    Symbol memberName;

    List<Type> typeArguments;


    virtual void  method(Symbol memberName, Map<Symbol, Object> named, Iterable<Object> positional, Iterable<Type> types);

    virtual void  getter(Symbol memberName);

    virtual void  setter(Object argument, Symbol memberName);

    virtual List<dynamic> positionalArguments();

    virtual Map<Symbol, dynamic> namedArguments();

    virtual bool isMethod();

    virtual bool isGetter();

    virtual bool isSetter();

    virtual bool isAccessor();

private:
    List<Object> _positional;

    Map<Symbol, Object> _named;


    static List<Type> _ensureNonNullTypes(Iterable<Type> types);

};
using _Invocation = std::shared_ptr<_InvocationCls>;


#endif