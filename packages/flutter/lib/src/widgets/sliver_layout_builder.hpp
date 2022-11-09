#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SLIVER_LAYOUT_BUILDER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SLIVER_LAYOUT_BUILDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "framework.hpp"
#include "layout_builder.hpp"


class SliverLayoutBuilderCls : public ConstrainedLayoutBuilderCls<SliverConstraints> {
public:

     SliverLayoutBuilderCls(Unknown builder, Unknown key);
    virtual SliverLayoutWidgetBuilder builder();

    virtual RenderObject createRenderObject(BuildContext context);

private:

};
using SliverLayoutBuilder = std::shared_ptr<SliverLayoutBuilderCls>;

class _RenderSliverLayoutBuilderCls : public RenderSliverCls {
public:

    virtual double childMainAxisPosition(RenderObject child);

    virtual void performLayout();

    virtual void applyPaintTransform(RenderObject child, Matrix4 transform);

    virtual void paint(PaintingContext context, Offset offset);

    virtual bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

private:

};
using _RenderSliverLayoutBuilder = std::shared_ptr<_RenderSliverLayoutBuilderCls>;


#endif