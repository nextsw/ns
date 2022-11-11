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
    child?->layout(constraints(), true);
    geometry() = child?->geometry | SliverGeometryCls::zero;
}

void _RenderSliverLayoutBuilderCls::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    assert(child == this->child);
}

void _RenderSliverLayoutBuilderCls::paint(PaintingContext context, Offset offset) {
    if (child?->geometry?->visible | false) {
        context->paintChild(child!, offset);
    }
}

bool _RenderSliverLayoutBuilderCls::hitTestChildren(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition) {
    return child != nullptr && child!->geometry!->hitTestExtent > 0 && child!->hitTest(result, mainAxisPosition, crossAxisPosition);
}
