#include "layout_builder.hpp"
template<typename ConstraintType> ConstrainedLayoutBuilderCls<ConstraintType>::ConstrainedLayoutBuilderCls(Widget Function(BuildContext , ConstraintType ) builder, Unknown key) {
    {
        assert(builder != nullptr);
    }
}

template<typename ConstraintType> RenderObjectElement ConstrainedLayoutBuilderCls<ConstraintType>::createElement() {
    return <ConstraintType>make<_LayoutBuilderElementCls>(this);
}

template<typename ConstraintType> RenderConstrainedLayoutBuilder<ConstraintType, RenderObject> _LayoutBuilderElementCls<ConstraintType>::renderObject() {
    return as<RenderConstrainedLayoutBuilder<ConstraintType, RenderObject>>(super->renderObject);
}

template<typename ConstraintType> void _LayoutBuilderElementCls<ConstraintType>::visitChildren(ElementVisitor visitor) {
    if (_child != nullptr) {
        visitor(_child!);
    }
}

template<typename ConstraintType> void _LayoutBuilderElementCls<ConstraintType>::forgetChild(Element child) {
    assert(child == _child);
    _child = nullptr;
    super->forgetChild(child);
}

template<typename ConstraintType> void _LayoutBuilderElementCls<ConstraintType>::mount(Object newSlot, Element parent) {
    super->mount(parent, newSlot);
    renderObject()->updateCallback(_layout);
}

template<typename ConstraintType> void _LayoutBuilderElementCls<ConstraintType>::update(ConstrainedLayoutBuilder<ConstraintType> newWidget) {
    assert(widget != newWidget);
    super->update(newWidget);
    assert(widget == newWidget);
    renderObject()->updateCallback(_layout);
    renderObject()->markNeedsBuild();
}

template<typename ConstraintType> void _LayoutBuilderElementCls<ConstraintType>::performRebuild() {
    renderObject()->markNeedsBuild();
    super->performRebuild();
}

template<typename ConstraintType> void _LayoutBuilderElementCls<ConstraintType>::unmount() {
    renderObject()->updateCallback(nullptr);
    super->unmount();
}

template<typename ConstraintType> void _LayoutBuilderElementCls<ConstraintType>::insertRenderObjectChild(RenderObject child, Object slot) {
    RenderObjectWithChildMixin<RenderObject> renderObject = this->renderObject();
    assert(slot == nullptr);
    assert(renderObject->debugValidateChild(child));
    renderObject->child = child;
    assert(renderObject == this->renderObject);
}

template<typename ConstraintType> void _LayoutBuilderElementCls<ConstraintType>::moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot) {
    assert(false);
}

template<typename ConstraintType> void _LayoutBuilderElementCls<ConstraintType>::removeRenderObjectChild(RenderObject child, Object slot) {
    RenderConstrainedLayoutBuilder<ConstraintType, RenderObject> renderObject = this->renderObject();
    assert(renderObject->child == child);
    renderObject->child = nullptr;
    assert(renderObject == this->renderObject);
}

template<typename ConstraintType> void _LayoutBuilderElementCls<ConstraintType>::_layout(ConstraintType constraints) {
    InlineMethod;
    owner!->buildScope(this, layoutCallback);
}

template<typename ConstraintType, typename ChildType> void RenderConstrainedLayoutBuilderCls<ConstraintType, ChildType>::updateCallback(LayoutCallback<ConstraintType> value) {
    if (value == _callback) {
        return;
    }
    _callback = value;
    markNeedsLayout();
}

template<typename ConstraintType, typename ChildType> void RenderConstrainedLayoutBuilderCls<ConstraintType, ChildType>::markNeedsBuild() {
    _needsBuild = true;
    markNeedsLayout();
}

template<typename ConstraintType, typename ChildType> void RenderConstrainedLayoutBuilderCls<ConstraintType, ChildType>::rebuildIfNecessary() {
    assert(_callback != nullptr);
    if (_needsBuild || constraints != _previousConstraints) {
        _previousConstraints = constraints;
        _needsBuild = false;
        invokeLayoutCallback(_callback!);
    }
}

LayoutBuilderCls::LayoutBuilderCls(Unknown builder, Unknown key) {
    {
        assert(builder != nullptr);
    }
}

LayoutWidgetBuilder LayoutBuilderCls::builder() {
    return super->builder;
}

RenderObject LayoutBuilderCls::createRenderObject(BuildContext context) {
    return make<_RenderLayoutBuilderCls>();
}

double _RenderLayoutBuilderCls::computeMinIntrinsicWidth(double height) {
    assert(_debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

double _RenderLayoutBuilderCls::computeMaxIntrinsicWidth(double height) {
    assert(_debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

double _RenderLayoutBuilderCls::computeMinIntrinsicHeight(double width) {
    assert(_debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

double _RenderLayoutBuilderCls::computeMaxIntrinsicHeight(double width) {
    assert(_debugThrowIfNotCheckingIntrinsics());
    return 0.0;
}

Size _RenderLayoutBuilderCls::computeDryLayout(BoxConstraints constraints) {
    assert(debugCannotComputeDryLayout(__s("Calculating the dry layout would require running the layout callback speculatively, which might mutate the live render object tree.")));
    return SizeCls::zero;
}

void _RenderLayoutBuilderCls::performLayout() {
    BoxConstraints constraints = this->constraints;
    rebuildIfNecessary();
    if (child != nullptr) {
        child!->layout(constraintstrue);
        size = constraints->constrain(child!->size);
    } else {
        size = constraints->biggest();
    }
}

double _RenderLayoutBuilderCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    if (child != nullptr) {
        return child!->getDistanceToActualBaseline(baseline);
    }
    return super->computeDistanceToActualBaseline(baseline);
}

bool _RenderLayoutBuilderCls::hitTestChildren(Offset position, BoxHitTestResult result) {
    return child?->hitTest(resultposition) or false;
}

void _RenderLayoutBuilderCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        context->paintChild(child!, offset);
    }
}

bool _RenderLayoutBuilderCls::_debugThrowIfNotCheckingIntrinsics() {
    assert([=] () {
        if (!RenderObjectCls->debugCheckingIntrinsics) {
            ;
        }
        return true;
    }());
    return true;
}

FlutterErrorDetails _debugReportException(DiagnosticsNode context, Object exception, InformationCollector informationCollector, StackTrace stack) {
    FlutterErrorDetails details = make<FlutterErrorDetailsCls>(exception, stack, __s("widgets library"), context, informationCollector);
    FlutterErrorCls->reportError(details);
    return details;
}
