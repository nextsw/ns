#ifndef DART_CORE_SYMBOL
#define DART_CORE_SYMBOL
#include <base.hpp>

#include <dart/core/core.hpp>


class SymbolCls : public ObjectCls {
public:
    static Symbol unaryMinus;

    static Symbol empty;


     SymbolCls(String name);
    virtual int hashCode();
    virtual bool operator==(Object other);
private:

};
using Symbol = std::shared_ptr<SymbolCls>;


#endif