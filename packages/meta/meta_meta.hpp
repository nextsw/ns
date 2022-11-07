#ifndef META_META_H
#define META_META_H
#include <memory>




class Target {
public:
    Set<TargetKind> kinds;


     Target(Set<TargetKind> kinds);

private:

};

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

class TargetKindExtension {
public:

    String displayString();

private:

};

#endif