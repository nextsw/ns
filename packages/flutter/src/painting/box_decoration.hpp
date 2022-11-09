#ifndef PACKAGES_FLUTTER_SRC_PAINTING_BOX_DECORATION
#define PACKAGES_FLUTTER_SRC_PAINTING_BOX_DECORATION
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"
#include "border_radius.hpp"
#include "box_border.hpp"
#include "box_shadow.hpp"
#include "colors.hpp"
#include "decoration.hpp"
#include "decoration_image.hpp"
#include "edge_insets.hpp"
#include "gradient.hpp"
#include "image_provider.hpp"


class BoxDecorationCls : public DecorationCls {
public:
    Color color;

    DecorationImage image;

    BoxBorder border;

    BorderRadiusGeometry borderRadius;

    List<BoxShadow> boxShadow;

    Gradient gradient;

    BlendMode backgroundBlendMode;

    BoxShape shape;


     BoxDecorationCls(BlendMode backgroundBlendMode, BoxBorder border, BorderRadiusGeometry borderRadius, List<BoxShadow> boxShadow, Color color, Gradient gradient, DecorationImage image, BoxShape shape);

    virtual BoxDecoration copyWith(BlendMode backgroundBlendMode, BoxBorder border, BorderRadiusGeometry borderRadius, List<BoxShadow> boxShadow, Color color, Gradient gradient, DecorationImage image, BoxShape shape);

    virtual bool debugAssertIsValid();

    virtual EdgeInsetsGeometry padding();

    virtual Path getClipPath(Rect rect, TextDirection textDirection);

    virtual BoxDecoration scale(double factor);

    virtual bool isComplex();

    virtual BoxDecoration lerpFrom(Decoration a, double t);

    virtual BoxDecoration lerpTo(Decoration b, double t);

    static BoxDecoration lerp(BoxDecoration a, BoxDecoration b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual bool hitTest(Offset position, Size size, TextDirection textDirection);

    virtual BoxPainter createBoxPainter(VoidCallback onChanged);

private:

};
using BoxDecoration = std::shared_ptr<BoxDecorationCls>;

class _BoxDecorationPainterCls : public BoxPainterCls {
public:

    virtual void dispose();

    virtual void paint(Canvas canvas, ImageConfiguration configuration, Offset offset);

    virtual String toString();

private:
    BoxDecoration _decoration;

    Paint _cachedBackgroundPaint;

    Rect _rectForCachedBackgroundPaint;

    DecorationImagePainter _imagePainter;


     _BoxDecorationPainterCls(BoxDecoration _decoration, VoidCallback onChanged);

    virtual Paint _getBackgroundPaint(Rect rect, TextDirection textDirection);

    virtual void _paintBox(Canvas canvas, Paint paint, Rect rect, TextDirection textDirection);

    virtual void _paintShadows(Canvas canvas, Rect rect, TextDirection textDirection);

    virtual void _paintBackgroundColor(Canvas canvas, Rect rect, TextDirection textDirection);

    virtual void _paintBackgroundImage(Canvas canvas, ImageConfiguration configuration, Rect rect);

};
using _BoxDecorationPainter = std::shared_ptr<_BoxDecorationPainterCls>;


#endif