#include "sliver_layout_builder.hpp"
SliverLayoutWidgetBuilder SliverLayoutBuilderCls::builder() {
    return super->builder;
}

RenderObject SliverLayoutBuilderCls::createRenderObject(BuildContext context) {
    return make<_RenderSliverLayoutBuilderCls>();
}

double _RenderSliverLayoutBuilderCls::childMainAxisPosition(RenderObject child) {
    assert(child != nullptr);
    assert(child == this->child);
    return 0;
}

void _RenderSliverLayoutBuilderCls::performLayout() {
    rebuildIfNecessary();
    child?->layout(constraintstrue);
    geometry = child?->geometry or SliverGeometryCls::zero;
}

void _RenderSliverLayoutBuilderCls::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    assert(child == this->child);
}

void _RenderSliverLayoutBuilderCls::paint(PaintingContext context, Offset offset) {
    if (child?->geometry?->visible or false) {
        context->paintChild(child!, offset);
    }
}

bool _RenderSliverLayoutBuilderCls::hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result) {
    return child != nullptr && child!->geometry!->hitTestExtent > 0 && child!->hitTest(resultmainAxisPosition, crossAxisPosition);
}
