#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_BANNER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_BANNER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"

double _kOffset;

double _kHeight;

double _kBottomOffset;

Rect _kRect;

Color _kColor;

TextStyle _kTextStyle;


enum BannerLocation{
    topStart,
    topEnd,
    bottomStart,
    bottomEnd,
} // end BannerLocation

class BannerPainterCls : public CustomPainterCls {
public:
    String message;

    TextDirection textDirection;

    BannerLocation location;

    TextDirection layoutDirection;

    Color color;

    TextStyle textStyle;


     BannerPainterCls(Color color, TextDirection layoutDirection, BannerLocation location, String message, TextDirection textDirection, TextStyle textStyle);

    virtual void paint(Canvas canvas, Size size);

    virtual bool shouldRepaint(BannerPainter oldDelegate);

    virtual bool hitTest(Offset position);

private:
    static BoxShadow _shadow;

    bool _prepared;

    TextPainter _textPainter;

    Paint _paintShadow;

    Paint _paintBanner;


    virtual void _prepare();

    virtual double _translationX(double width);

    virtual double _translationY(double height);

    virtual double _rotation();

};
using BannerPainter = std::shared_ptr<BannerPainterCls>;

class BannerCls : public StatelessWidgetCls {
public:
    Widget child;

    String message;

    TextDirection textDirection;

    BannerLocation location;

    TextDirection layoutDirection;

    Color color;

    TextStyle textStyle;


     BannerCls(Widget child, Color color, Key key, TextDirection layoutDirection, BannerLocation location, String message, TextDirection textDirection, TextStyle textStyle);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Banner = std::shared_ptr<BannerCls>;

class CheckedModeBannerCls : public StatelessWidgetCls {
public:
    Widget child;


     CheckedModeBannerCls(Widget child, Key key);
    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using CheckedModeBanner = std::shared_ptr<CheckedModeBannerCls>;


#endif