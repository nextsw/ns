#ifndef SHAPE_DECORATION_H
#define SHAPE_DECORATION_H
#include <memory>

#include <flutter/foundation.hpp>
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



class ShapeDecoration : Decoration {
public:
    Color color;

    Gradient gradient;

    DecorationImage image;

    List<BoxShadow> shadows;

    ShapeBorder shape;


     ShapeDecoration(Color color, Gradient gradient, DecorationImage image, List<BoxShadow> shadows, ShapeBorder shape);

    void  fromBoxDecoration(BoxDecoration source);

    Path getClipPath(Rect rect, TextDirection textDirection);

    EdgeInsetsGeometry padding();

    bool isComplex();

    ShapeDecoration lerpFrom(Decoration a, double t);

    ShapeDecoration lerpTo(Decoration b, double t);

    static ShapeDecoration lerp(ShapeDecoration a, ShapeDecoration b, double t);

    bool ==(Object other);

    int hashCode();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    bool hitTest(Offset position, Size size, TextDirection textDirection);

    BoxPainter createBoxPainter(VoidCallback onChanged);

private:

};

class _ShapeDecorationPainter : BoxPainter {
public:

    VoidCallback onChanged();

    void dispose();

    void paint(Canvas canvas, ImageConfiguration configuration, Offset offset);

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


     _ShapeDecorationPainter(ShapeDecoration _decoration, VoidCallback onChanged);

    void _precache(Rect rect, TextDirection textDirection);

    void _paintShadows(Canvas canvas);

    void _paintInterior(Canvas canvas);

    void _paintImage(Canvas canvas, ImageConfiguration configuration);

};

#endif