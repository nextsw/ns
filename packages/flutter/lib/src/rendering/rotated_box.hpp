#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_ROTATED_BOX
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_ROTATED_BOX
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"

double _kQuarterTurnsInRadians;


class RenderRotatedBoxCls : public RenderBoxCls {
public:

     RenderRotatedBoxCls(RenderBox child, int quarterTurns);

    virtual int quarterTurns();

    virtual void  quarterTurns(int value);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual bool hitTestChildren(Offset position, BoxHitTestResult result);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void dispose();

    virtual void applyPaintTransform(RenderBox child, Matrix4 transform);

private:
    int _quarterTurns;

    Matrix4 _paintTransform;

    LayerHandle<TransformLayer> _transformLayer;


    virtual bool _isVertical();

    virtual void _paintChild(PaintingContext context, Offset offset);

};
using RenderRotatedBox = std::shared_ptr<RenderRotatedBoxCls>;


#endif