#ifndef SLIVER_PADDING_H
#define SLIVER_PADDING_H
#include <memory>

#include <math/math.hpp>
#include <vector_math/vector_math_64.hpp>
#include "debug.hpp"
#include "object.hpp"
#include "sliver.hpp"



class RenderSliverEdgeInsetsPadding : RenderSliver {
public:

    EdgeInsets resolvedPadding();

    double beforePadding();

    double afterPadding();

    double mainAxisPadding();

    double crossAxisPadding();

    void setupParentData(RenderObject child);

    void performLayout();

    bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    double childMainAxisPosition(RenderSliver child);

    double childCrossAxisPosition(RenderSliver child);

    double childScrollOffset(RenderObject child);

    void applyPaintTransform(RenderObject child, Matrix4 transform);

    void paint(PaintingContext context, Offset offset);

    void debugPaint(PaintingContext context, Offset offset);

private:

};

class RenderSliverPadding : RenderSliverEdgeInsetsPadding {
public:

     RenderSliverPadding(RenderSliver child, EdgeInsetsGeometry padding, TextDirection textDirection);

    EdgeInsets resolvedPadding();

    EdgeInsetsGeometry padding();

    void  padding(EdgeInsetsGeometry value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    void performLayout();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    EdgeInsets _resolvedPadding;

    EdgeInsetsGeometry _padding;

    TextDirection _textDirection;


    void _resolve();

    void _markNeedsResolution();

};

#endif