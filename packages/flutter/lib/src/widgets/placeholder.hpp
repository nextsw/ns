#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PLACEHOLDER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PLACEHOLDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic.hpp"
#include "framework.hpp"


class _PlaceholderPainterCls : public CustomPainterCls {
public:
    Color color;

    double strokeWidth;


    virtual void paint(Canvas canvas, Size size);

    virtual bool shouldRepaint(_PlaceholderPainter oldPainter);

    virtual bool hitTest(Offset position);

private:

     _PlaceholderPainterCls(Color color, double strokeWidth);
};
using _PlaceholderPainter = std::shared_ptr<_PlaceholderPainterCls>;

class PlaceholderCls : public StatelessWidgetCls {
public:
    Color color;

    double strokeWidth;

    double fallbackWidth;

    double fallbackHeight;

    Widget child;


     PlaceholderCls(Widget child, Color color, double fallbackHeight, double fallbackWidth, Key key, double strokeWidth);
    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Placeholder = std::shared_ptr<PlaceholderCls>;


#endif