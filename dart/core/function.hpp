#ifndef DART_CORE_FUNCTION
#define DART_CORE_FUNCTION
#include <base.hpp>

#include <dart/core/core.hpp>


class FunctionCls : public ObjectCls {
public:

    static void  apply(std::function<void ()> function, List<dynamic> positionalArguments, Map<Symbol, dynamic> namedArguments);
    virtual int hashCode();
    virtual bool operator==(Object other);
private:

};
using Function = std::shared_ptr<FunctionCls>;


#endif