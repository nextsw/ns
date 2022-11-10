#ifndef DART_CORE_NULL
#define DART_CORE_NULL
#include <base.hpp>

#include <dart/core/core.hpp>


class NullCls : public ObjectCls {
public:

    int hashCode();
    virtual String toString();

private:

    virtual void  _uninstantiable();

};
using Null = std::shared_ptr<NullCls>;


#endif