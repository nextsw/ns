#ifndef BANNER_H
#define BANNER_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"


const double _kOffset;

const double _kHeight;

const double _kBottomOffset;

const Rect _kRect;

const Color _kColor;

const TextStyle _kTextStyle;


enum BannerLocation{
    topStart,
    topEnd,
    bottomStart,
    bottomEnd,
} // end BannerLocation

class BannerPainter : CustomPainter {
public:
    String message;

    TextDirection textDirection;

    BannerLocation location;

    TextDirection layoutDirection;

    Color color;

    TextStyle textStyle;


     BannerPainter(Color color, TextDirection layoutDirection, BannerLocation location, String message, TextDirection textDirection, TextStyle textStyle);

    void paint(Canvas canvas, Size size);

    bool shouldRepaint(BannerPainter oldDelegate);

    bool hitTest(Offset position);

private:
    static const BoxShadow _shadow;

    bool _prepared;

    TextPainter _textPainter;

    Paint _paintShadow;

    Paint _paintBanner;


    void _prepare();

    double _translationX(double width);

    double _translationY(double height);

    double _rotation();

};

class Banner : StatelessWidget {
public:
    Widget child;

    String message;

    TextDirection textDirection;

    BannerLocation location;

    TextDirection layoutDirection;

    Color color;

    TextStyle textStyle;


     Banner(Widget child, Color color, Unknown, TextDirection layoutDirection, BannerLocation location, String message, TextDirection textDirection, TextStyle textStyle);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class CheckedModeBanner : StatelessWidget {
public:
    Widget child;


     CheckedModeBanner(Widget child, Unknown);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif