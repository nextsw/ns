#ifndef PACKAGES_FLUTTER_SRC_PAINTING_BOX_SHADOW
#define PACKAGES_FLUTTER_SRC_PAINTING_BOX_SHADOW
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"
#include "debug.hpp"


class BoxShadowCls : public ShadowCls {
public:
    double spreadRadius;

    BlurStyle blurStyle;


     BoxShadowCls(double blurRadius, BlurStyle blurStyle, Color color, Offset offset, double spreadRadius);
    virtual Paint toPaint();

    virtual BoxShadow scale(double factor);

    static BoxShadow lerp(BoxShadow a, BoxShadow b, double t);

    static List<BoxShadow> lerpList(List<BoxShadow> a, List<BoxShadow> b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using BoxShadow = std::shared_ptr<BoxShadowCls>;


#endif