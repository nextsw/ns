#ifndef PACKAGES_FLUTTER_SRC_PAINTING_DECORATION
#define PACKAGES_FLUTTER_SRC_PAINTING_DECORATION
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"
#include "edge_insets.hpp"
#include "image_provider.hpp"


class DecorationCls : public ObjectCls {
public:

     DecorationCls();
    virtual String toStringShort();

    virtual bool debugAssertIsValid();

    virtual EdgeInsetsGeometry padding();

    virtual bool isComplex();

    virtual Decoration lerpFrom(Decoration a, double t);

    virtual Decoration lerpTo(Decoration b, double t);

    static Decoration lerp(Decoration a, Decoration b, double t);

    virtual bool hitTest(Offset position, Size size, TextDirection textDirection);

    virtual BoxPainter createBoxPainter(VoidCallback onChanged);
    virtual Path getClipPath(Rect rect, TextDirection textDirection);

private:

};
using Decoration = std::shared_ptr<DecorationCls>;

class BoxPainterCls : public ObjectCls {
public:
    VoidCallback onChanged;


     BoxPainterCls(VoidCallback onChanged);
    virtual void paint(Canvas canvas, ImageConfiguration configuration, Offset offset);
    virtual void dispose();

private:

};
using BoxPainter = std::shared_ptr<BoxPainterCls>;


#endif