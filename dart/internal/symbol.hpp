#ifndef DART_INTERNAL_SYMBOL
#define DART_INTERNAL_SYMBOL
#include <base.hpp>

#include <dart/core/core.hpp>


class SymbolCls : public ObjectCls {
public:

    extern  SymbolCls(String name);
    virtual void  unvalidated(String _name);
    virtual bool operator==(Object other);

    extern int hashCode();
    extern void  toString();
    static String getName(Symbol symbol);

    extern static String computeUnmangledName(Symbol symbol);
private:
    String _name;


};
using Symbol = std::shared_ptr<SymbolCls>;


#endif