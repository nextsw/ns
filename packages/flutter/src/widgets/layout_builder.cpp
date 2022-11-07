#include "layout_builder.hpp"
ConstrainedLayoutBuilder::ConstrainedLayoutBuilder(FunctionType builder, Unknown) {
    {
        assert(builder != nullptr);
    }
}

RenderObjectElement ConstrainedLayoutBuilder::createElement() {
    return <ConstraintType>_LayoutBuilderElement(this);
}

RenderConstrainedLayoutBuilder<ConstraintType, RenderObject> _LayoutBuilderElement::renderObject() {
    return (;
}

void _LayoutBuilderElement::visitChildren(ElementVisitor visitor) {
    if (_child != nullptr) {
        visitor(_child!);
    }
}

void _LayoutBuilderElement::forgetChild(Element child) {
    assert(child == _child);
    _child = nullptr;
    super.forgetChild(child);
}

void _LayoutBuilderElement::mount(Object newSlot, Element parent) {
    super.mount(parent, newSlot);
    renderObject.updateCallback(_layout);
}

void _LayoutBuilderElement::update(ConstrainedLayoutBuilder<ConstraintType> newWidget) {
    assert(widget != newWidget);
    super.update(newWidget);
    assert(widget == newWidget);
    renderObject.updateCallback(_layout);
    renderObject.markNeedsBuild();
}

void _LayoutBuilderElement::performRebuild() {
    renderObject.markNeedsBuild();
    super.performRebuild();
}

void _LayoutBuilderElement::unmount() {
    renderObject.updateCallback(nullptr);
    super.unmount();
}

void _LayoutBuilderElement::insertRenderObjectChild(RenderObject child, Object slot) {
    RenderObjectWithChildMixin<RenderObject> renderObject = this.renderObject;
    assert(slot == nullptr);
    assert(renderObject.debugValidateChild(child));
    renderObject.child = child;
    assert(renderObject == this.renderObject);
}

void _LayoutBuilderElement::moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot) {
    assert(false);
}

void _LayoutBuilderElement::removeRenderObjectChild(RenderObject child, Object slot) {
    RenderConstrainedLayoutBuilder<ConstraintType, RenderObject> renderObject = this.renderObject;
    assert(renderObject.child == child);
    renderObject.child = nullptr;
    assert(renderObject == this.renderObject);
}

void _LayoutBuilderElement::_layout(ConstraintType constraints) {
    ;
    owner!.buildScope(this, layoutCallback);
}

void RenderConstrainedLayoutBuilder::updateCallback(LayoutCallback<ConstraintType> value) {
    if (value == _callback) {
        return;
    }
    _callback = value;
    markNeedsLayout();
}

void RenderConstrainedLayoutBuilder::markNeedsBuild() {
    _needsBuild = true;
    markNeedsLayout();
}

void RenderConstrainedLayoutBuilder::rebuildIfNecessary() {
    assert(_callback != nullptr);
    if (_needsBuild || constraints != _previousConstraints) {
        _previousConstraints = constraints;
        _needsBuild = false;
        invokeLayoutCallback(_callback!);
    }
}

LayoutBuilder::LayoutBuilder(Unknown, Unknown) {
    {
        assert(builder != nullptr);
    }
}

LayoutWidgetBuilder LayoutBuilder::builder() {
    return super.builder;
}

RenderObject LayoutBuilder::createRenderObject(BuildContext context) {
    return _RenderLayoutBuilder();
}

double _RenderLayoutBuilder::computeMinIntrinsicWidth(double height) {
    assert(_debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

double _RenderLayoutBuilder::computeMaxIntrinsicWidth(double height) {
    assert(_debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

double _RenderLayoutBuilder::computeMinIntrinsicHeight(double width) {
    assert(_debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

double _RenderLayoutBuilder::computeMaxIntrinsicHeight(double width) {
    assert(_debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

Size _RenderLayoutBuilder::computeDryLayout(BoxConstraints constraints) {
    assert(debugCannotComputeDryLayout("Calculating the dry layout would require running the layout callback speculatively, which might mutate the live render object tree."));
    return Size.zero;
}

void _RenderLayoutBuilder::performLayout() {
    BoxConstraints constraints = this.constraints;
    rebuildIfNecessary();
    if (child != nullptr) {
        child!.layout(constraintstrue);
        size = constraints.constrain(child!.size);
    } else {
        size = constraints.biggest;
    }
}

double _RenderLayoutBuilder::computeDistanceToActualBaseline(TextBaseline baseline) {
    if (child != nullptr) {
        return child!.getDistanceToActualBaseline(baseline);
    }
    return super.computeDistanceToActualBaseline(baseline);
}

bool _RenderLayoutBuilder::hitTestChildren(Offset position, BoxHitTestResult result) {
    return child?.hitTest(resultposition) ?? false;
}

void _RenderLayoutBuilder::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        context.paintChild(child!, offset);
    }
}

bool _RenderLayoutBuilder::_debugThrowIfNotCheckingIntrinsics() {
    assert(());
    return true;
}

FlutterErrorDetails _debugReportException(DiagnosticsNode context, Object exception, InformationCollector informationCollector, StackTrace stack) {
    FlutterErrorDetails details = FlutterErrorDetails(exception, stack, "widgets library", context, informationCollector);
    FlutterError.reportError(details);
    return details;
}
