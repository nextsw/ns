#ifndef ROTATED_BOX_H
#define ROTATED_BOX_H
#include <memory>

#include <math/math.hpp>
#include <vector_math/vector_math_64.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"


const double _kQuarterTurnsInRadians;


class RenderRotatedBox : RenderBox {
public:

     RenderRotatedBox(RenderBox child, int quarterTurns);

    int quarterTurns();

    void  quarterTurns(int value);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void dispose();

    void applyPaintTransform(RenderBox child, Matrix4 transform);

private:
    int _quarterTurns;

    Matrix4 _paintTransform;

    LayerHandle<TransformLayer> _transformLayer;


    bool _isVertical();

    void _paintChild(PaintingContext context, Offset offset);

};

#endif