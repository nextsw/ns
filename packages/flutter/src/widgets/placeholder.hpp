#ifndef PLACEHOLDER_H
#define PLACEHOLDER_H
#include <memory>

#include <flutter/foundation.hpp>
#include "basic.hpp"
#include "framework.hpp"



class _PlaceholderPainter : CustomPainter {
public:
    Color color;

    double strokeWidth;


    void paint(Canvas canvas, Size size);

    bool shouldRepaint(_PlaceholderPainter oldPainter);

    bool hitTest(Offset position);

private:

     _PlaceholderPainter(Color color, double strokeWidth);

};

class Placeholder : StatelessWidget {
public:
    Color color;

    double strokeWidth;

    double fallbackWidth;

    double fallbackHeight;

    Widget child;


     Placeholder(Widget child, Color color, double fallbackHeight, double fallbackWidth, Unknown, double strokeWidth);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif