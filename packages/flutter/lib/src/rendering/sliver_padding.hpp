#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_PADDING
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_PADDING
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "debug.hpp"
#include "object.hpp"
#include "sliver.hpp"


class RenderSliverEdgeInsetsPaddingCls : public RenderSliverCls {
public:

    virtual EdgeInsets resolvedPadding();
    virtual double beforePadding();

    virtual double afterPadding();

    virtual double mainAxisPadding();

    virtual double crossAxisPadding();

    virtual void setupParentData(RenderObject child);

    virtual void performLayout();

    virtual bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    virtual double childMainAxisPosition(RenderSliver child);

    virtual double childCrossAxisPosition(RenderSliver child);

    virtual double childScrollOffset(RenderObject child);

    virtual void applyPaintTransform(RenderObject child, Matrix4 transform);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void debugPaint(PaintingContext context, Offset offset);

private:

};
using RenderSliverEdgeInsetsPadding = std::shared_ptr<RenderSliverEdgeInsetsPaddingCls>;

class RenderSliverPaddingCls : public RenderSliverEdgeInsetsPaddingCls {
public:

     RenderSliverPaddingCls(RenderSliver child, EdgeInsetsGeometry padding, TextDirection textDirection);

    virtual EdgeInsets resolvedPadding();

    virtual EdgeInsetsGeometry padding();

    virtual void  padding(EdgeInsetsGeometry value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual void performLayout();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    EdgeInsets _resolvedPadding;

    EdgeInsetsGeometry _padding;

    TextDirection _textDirection;


    virtual void _resolve();

    virtual void _markNeedsResolution();

};
using RenderSliverPadding = std::shared_ptr<RenderSliverPaddingCls>;


#endif