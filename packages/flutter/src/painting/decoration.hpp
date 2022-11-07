#ifndef DECORATION_H
#define DECORATION_H
#include <memory>

#include <flutter/foundation.hpp>
#include "basic_types.hpp"
#include "edge_insets.hpp"
#include "image_provider.hpp"



class Decoration {
public:

     Decoration();

    String toStringShort();

    bool debugAssertIsValid();

    EdgeInsetsGeometry padding();

    bool isComplex();

    Decoration lerpFrom(Decoration a, double t);

    Decoration lerpTo(Decoration b, double t);

    static Decoration lerp(Decoration a, Decoration b, double t);

    bool hitTest(Offset position, Size size, TextDirection textDirection);

    BoxPainter createBoxPainter(VoidCallback onChanged);

    Path getClipPath(Rect rect, TextDirection textDirection);

private:

};

class BoxPainter {
public:
    VoidCallback onChanged;


     BoxPainter(VoidCallback onChanged);

    void paint(Canvas canvas, ImageConfiguration configuration, Offset offset);

    void dispose();

private:

};

#endif