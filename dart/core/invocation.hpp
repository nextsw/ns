#ifndef DART_CORE_INVOCATION
#define DART_CORE_INVOCATION
#include <base.hpp>

#include <dart/core/core.hpp>


class InvocationCls : public ObjectCls {
public:

     InvocationCls();
    virtual void  method(Symbol memberName, Iterable<Object> positionalArguments, Map<Symbol, Object> namedArguments);

    virtual void  genericMethod(Symbol memberName, Iterable<Type> typeArguments, Iterable<Object> positionalArguments, Map<Symbol, Object> namedArguments);

    virtual void  getter(Symbol name);
    virtual void  setter(Symbol memberName, Object argument);
    virtual Symbol memberName();
    virtual List<Type> typeArguments();

    virtual List<Object> positionalArguments();
    virtual Map<Symbol, Object> namedArguments();
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


    virtual void  method(Symbol memberName, Iterable<Type> types, Iterable<Object> positional, Map<Symbol, Object> named);

    virtual void  getter(Symbol memberName);

    virtual void  setter(Symbol memberName, Object argument);

    virtual List<Object> positionalArguments();

    virtual Map<Symbol, Object> namedArguments();

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