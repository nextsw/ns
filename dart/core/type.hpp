#ifndef DART_CORE_TYPE
#define DART_CORE_TYPE
#include <base.hpp>

#include <dart/core/core.hpp>


class TypeCls : public ObjectCls {
public:

    virtual int hashCode();
    virtual bool operator==(Object other);
    virtual String toString();
private:

};
using Type = std::shared_ptr<TypeCls>;


#endif