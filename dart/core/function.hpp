#ifndef DART_CORE_FUNCTION
#define DART_CORE_FUNCTION
#include <base.hpp>

#include <dart/core/core.hpp>


class FunctionCls : public ObjectCls {
public:

    extern static void  apply(void  function() , Map<Symbol, dynamic> namedArguments, List<dynamic> positionalArguments);
    virtual int hashCode();
    virtual bool operator==(Object other);
private:

};
using Function = std::shared_ptr<FunctionCls>;


#endif