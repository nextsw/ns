#ifndef BOX_SHADOW_H
#define BOX_SHADOW_H
#include <memory>

#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"
#include "debug.hpp"



class BoxShadow : Shadow {
public:
    double spreadRadius;

    BlurStyle blurStyle;


     BoxShadow(Unknown, BlurStyle blurStyle, Unknown, Unknown, double spreadRadius);

    Paint toPaint();

    BoxShadow scale(double factor);

    static BoxShadow lerp(BoxShadow a, BoxShadow b, double t);

    static List<BoxShadow> lerpList(List<BoxShadow> a, List<BoxShadow> b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

#endif