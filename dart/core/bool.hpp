#ifndef DART_CORE_BOOL
#define DART_CORE_BOOL
#include <base.hpp>

#include <dart/core/core.hpp>


class boolCls : public ObjectCls {
public:

    extern void  fromEnvironment(bool defaultValue, String name);
    extern void  hasEnvironment(String name);
    extern int hashCode();
    virtual bool operator&(bool other);

    virtual bool operator|(bool other);

    virtual bool operator^(bool other);

    virtual String toString();

private:

};
using bool = std::shared_ptr<boolCls>;


#endif