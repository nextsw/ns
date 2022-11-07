#ifndef SLIVER_LAYOUT_BUILDER_H
#define SLIVER_LAYOUT_BUILDER_H
#include <memory>

#include <flutter/rendering.hpp>
#include "framework.hpp"
#include "layout_builder.hpp"



class SliverLayoutBuilder : ConstrainedLayoutBuilder<SliverConstraints> {
public:

     SliverLayoutBuilder(Unknown, Unknown);

    SliverLayoutWidgetBuilder builder();

    RenderObject createRenderObject(BuildContext context);

private:

};

class _RenderSliverLayoutBuilder : RenderSliver {
public:

    double childMainAxisPosition(RenderObject child);

    void performLayout();

    void applyPaintTransform(RenderObject child, Matrix4 transform);

    void paint(PaintingContext context, Offset offset);

    bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

private:

};

#endif