#ifndef FLUTTER_LOGO_H
#define FLUTTER_LOGO_H
#include <memory>

#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "alignment.hpp"
#include "basic_types.hpp"
#include "box_fit.hpp"
#include "colors.hpp"
#include "decoration.hpp"
#include "edge_insets.hpp"
#include "image_provider.hpp"
#include "text_painter.hpp"
#include "text_span.hpp"
#include "text_style.hpp"



enum FlutterLogoStyle{
    markOnly,
    horizontal,
    stacked,
} // end FlutterLogoStyle

class FlutterLogoDecoration : Decoration {
public:
    Color textColor;

    FlutterLogoStyle style;

    EdgeInsets margin;


     FlutterLogoDecoration(EdgeInsets margin, FlutterLogoStyle style, Color textColor);

    bool debugAssertIsValid();

    bool isComplex();

    static FlutterLogoDecoration lerp(FlutterLogoDecoration a, FlutterLogoDecoration b, double t);

    FlutterLogoDecoration lerpFrom(Decoration a, double t);

    FlutterLogoDecoration lerpTo(Decoration b, double t);

    bool hitTest(Offset position, Size size, TextDirection textDirection);

    BoxPainter createBoxPainter(VoidCallback onChanged);

    Path getClipPath(Rect rect, TextDirection textDirection);

    bool ==(Object other);

    int hashCode();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _position;

    double _opacity;


    void  _(double _opacity, double _position, EdgeInsets margin, FlutterLogoStyle style, Color textColor);

    bool _inTransition();

};

class _FlutterLogoPainter : BoxPainter {
public:

    void paint(Canvas canvas, ImageConfiguration configuration, Offset offset);

private:
    FlutterLogoDecoration _config;

    TextPainter _textPainter;

    Rect _textBoundingRect;


     _FlutterLogoPainter(FlutterLogoDecoration _config);

    void _prepareText();

    void _paintLogo(Canvas canvas, Rect rect);

};

#endif