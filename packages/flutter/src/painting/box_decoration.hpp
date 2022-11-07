#ifndef BOX_DECORATION_H
#define BOX_DECORATION_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
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



class BoxDecoration : Decoration {
public:
    Color color;

    DecorationImage image;

    BoxBorder border;

    BorderRadiusGeometry borderRadius;

    List<BoxShadow> boxShadow;

    Gradient gradient;

    BlendMode backgroundBlendMode;

    BoxShape shape;


     BoxDecoration(BlendMode backgroundBlendMode, BoxBorder border, BorderRadiusGeometry borderRadius, List<BoxShadow> boxShadow, Color color, Gradient gradient, DecorationImage image, BoxShape shape);

    BoxDecoration copyWith(BlendMode backgroundBlendMode, BoxBorder border, BorderRadiusGeometry borderRadius, List<BoxShadow> boxShadow, Color color, Gradient gradient, DecorationImage image, BoxShape shape);

    bool debugAssertIsValid();

    EdgeInsetsGeometry padding();

    Path getClipPath(Rect rect, TextDirection textDirection);

    BoxDecoration scale(double factor);

    bool isComplex();

    BoxDecoration lerpFrom(Decoration a, double t);

    BoxDecoration lerpTo(Decoration b, double t);

    static BoxDecoration lerp(BoxDecoration a, BoxDecoration b, double t);

    bool ==(Object other);

    int hashCode();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    bool hitTest(Offset position, Size size, TextDirection textDirection);

    BoxPainter createBoxPainter(VoidCallback onChanged);

private:

};

class _BoxDecorationPainter : BoxPainter {
public:

    void dispose();

    void paint(Canvas canvas, ImageConfiguration configuration, Offset offset);

    String toString();

private:
    BoxDecoration _decoration;

    Paint _cachedBackgroundPaint;

    Rect _rectForCachedBackgroundPaint;

    DecorationImagePainter _imagePainter;


     _BoxDecorationPainter(BoxDecoration _decoration, VoidCallback onChanged);

    Paint _getBackgroundPaint(Rect rect, TextDirection textDirection);

    void _paintBox(Canvas canvas, Paint paint, Rect rect, TextDirection textDirection);

    void _paintShadows(Canvas canvas, Rect rect, TextDirection textDirection);

    void _paintBackgroundColor(Canvas canvas, Rect rect, TextDirection textDirection);

    void _paintBackgroundImage(Canvas canvas, ImageConfiguration configuration, Rect rect);

};

#endif