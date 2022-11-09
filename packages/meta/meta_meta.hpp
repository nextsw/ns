#ifndef PACKAGES_META_META_META
#define PACKAGES_META_META_META
#include <base.hpp>

#include <dart/core/core.hpp>


class TargetCls : public ObjectCls {
public:
    Set<TargetKind> kinds;


     TargetCls(Set<TargetKind> kinds);
private:

};
using Target = std::shared_ptr<TargetCls>;

enum TargetKind{
    classType,
    enumType,
    extension,
    field,
    function,
    library,
    getter,
    method,
    mixinType,
    parameter,
    setter,
    topLevelVariable,
    type,
    typedefType,
} // end TargetKind

class TargetKindExtensionCls : public ObjectCls {
public:

    virtual String displayString();

private:

};
using TargetKindExtension = std::shared_ptr<TargetKindExtensionCls>;


#endif