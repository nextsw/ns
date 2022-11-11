#ifndef PACKAGES_FLUTTER_SRC_PAINTING_FLUTTER_LOGO
#define PACKAGES_FLUTTER_SRC_PAINTING_FLUTTER_LOGO
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
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

class FlutterLogoDecorationCls : public DecorationCls {
public:
    Color textColor;

    FlutterLogoStyle style;

    EdgeInsets margin;


     FlutterLogoDecorationCls(EdgeInsets margin, FlutterLogoStyle style, Color textColor);

    virtual bool debugAssertIsValid();

    virtual bool isComplex();

    static FlutterLogoDecoration lerp(FlutterLogoDecoration a, FlutterLogoDecoration b, double t);

    virtual FlutterLogoDecoration lerpFrom(Decoration a, double t);

    virtual FlutterLogoDecoration lerpTo(Decoration b, double t);

    virtual bool hitTest(Size size, Offset position, TextDirection textDirection);

    virtual BoxPainter createBoxPainter(VoidCallback onChanged);

    virtual Path getClipPath(Rect rect, TextDirection textDirection);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _position;

    double _opacity;


    virtual void  _(Color textColor, FlutterLogoStyle style, EdgeInsets margin, double _position, double _opacity);
    virtual bool _inTransition();

};
using FlutterLogoDecoration = std::shared_ptr<FlutterLogoDecorationCls>;

class _FlutterLogoPainterCls : public BoxPainterCls {
public:

    virtual void paint(Canvas canvas, Offset offset, ImageConfiguration configuration);

private:
    FlutterLogoDecoration _config;

    TextPainter _textPainter;

    Rect _textBoundingRect;


     _FlutterLogoPainterCls(FlutterLogoDecoration _config);

    virtual void _prepareText();

    virtual void _paintLogo(Canvas canvas, Rect rect);

};
using _FlutterLogoPainter = std::shared_ptr<_FlutterLogoPainterCls>;


#endif