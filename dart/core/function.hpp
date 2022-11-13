#ifndef DART_CORE_FUNCTION
#define DART_CORE_FUNCTION
#include <base.hpp>

#include <dart/core/core.hpp>


class FunctionCls : public ObjectCls {
public:

    static void  apply(std::function<void ()> function, List<Object> positionalArguments, Map<Symbol, Object> namedArguments);
    virtual int hashCode();
    virtual bool operator==(Object other);
private:

};
using Function = std::shared_ptr<FunctionCls>;


#endif