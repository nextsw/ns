#ifndef PACKAGES_FLUTTER_SRC_PAINTING_SHAPE_DECORATION
#define PACKAGES_FLUTTER_SRC_PAINTING_SHAPE_DECORATION
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"
#include "borders.hpp"
#include "box_border.hpp"
#include "box_decoration.hpp"
#include "box_shadow.hpp"
#include "circle_border.hpp"
#include "colors.hpp"
#include "decoration.hpp"
#include "decoration_image.hpp"
#include "edge_insets.hpp"
#include "gradient.hpp"
#include "image_provider.hpp"
#include "rounded_rectangle_border.hpp"


class ShapeDecorationCls : public DecorationCls {
public:
    Color color;

    Gradient gradient;

    DecorationImage image;

    List<BoxShadow> shadows;

    ShapeBorder shape;


     ShapeDecorationCls(Color color, Gradient gradient, DecorationImage image, List<BoxShadow> shadows, ShapeBorder shape);

    virtual void  fromBoxDecoration(BoxDecoration source);

    virtual Path getClipPath(Rect rect, TextDirection textDirection);

    virtual EdgeInsetsGeometry padding();

    virtual bool isComplex();

    virtual ShapeDecoration lerpFrom(Decoration a, double t);

    virtual ShapeDecoration lerpTo(Decoration b, double t);

    static ShapeDecoration lerp(ShapeDecoration a, ShapeDecoration b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual bool hitTest(Size size, Offset position, TextDirection textDirection);

    virtual BoxPainter createBoxPainter(VoidCallback onChanged);

private:

};
using ShapeDecoration = std::shared_ptr<ShapeDecorationCls>;

class _ShapeDecorationPainterCls : public BoxPainterCls {
public:

    virtual VoidCallback onChanged();

    virtual void dispose();

    virtual void paint(Canvas canvas, Offset offset, ImageConfiguration configuration);

private:
    ShapeDecoration _decoration;

    Rect _lastRect;

    TextDirection _lastTextDirection;

    Path _outerPath;

    Path _innerPath;

    Paint _interiorPaint;

    int _shadowCount;

    List<Path> _shadowPaths;

    List<Paint> _shadowPaints;

    DecorationImagePainter _imagePainter;


     _ShapeDecorationPainterCls(ShapeDecoration _decoration, VoidCallback onChanged);

    virtual void _precache(Rect rect, TextDirection textDirection);

    virtual void _paintShadows(Canvas canvas);

    virtual void _paintInterior(Canvas canvas);

    virtual void _paintImage(Canvas canvas, ImageConfiguration configuration);

};
using _ShapeDecorationPainter = std::shared_ptr<_ShapeDecorationPainterCls>;


#endif