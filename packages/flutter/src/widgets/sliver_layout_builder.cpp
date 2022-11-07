#include "sliver_layout_builder.hpp"
SliverLayoutWidgetBuilder SliverLayoutBuilder::builder() {
    return super.builder;
}

RenderObject SliverLayoutBuilder::createRenderObject(BuildContext context) {
    return _RenderSliverLayoutBuilder();
}

double _RenderSliverLayoutBuilder::childMainAxisPosition(RenderObject child) {
    assert(child != nullptr);
    assert(child == this.child);
    return 0;
}

void _RenderSliverLayoutBuilder::performLayout() {
    rebuildIfNecessary();
    child?.layout(constraintstrue);
    geometry = child?.geometry ?? SliverGeometry.zero;
}

void _RenderSliverLayoutBuilder::applyPaintTransform(RenderObject child, Matrix4 transform) {
    assert(child != nullptr);
    assert(child == this.child);
}

void _RenderSliverLayoutBuilder::paint(PaintingContext context, Offset offset) {
    if (child?.geometry?.visible ?? false) {
        context.paintChild(child!, offset);
    }
}

bool _RenderSliverLayoutBuilder::hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result) {
    return child != nullptr && child!.geometry!.hitTestExtent > 0 && child!.hitTest(resultmainAxisPosition, crossAxisPosition);
}
