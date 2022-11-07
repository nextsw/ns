#include "view.hpp"
Matrix4 ViewConfiguration::toMatrix() {
    return Matrix4.diagonal3Values(devicePixelRatio, devicePixelRatio, 1.0);
}

bool ViewConfiguration::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is ViewConfiguration && other.size == size && other.devicePixelRatio == devicePixelRatio;
}

int ViewConfiguration::hashCode() {
    return Object.hash(size, devicePixelRatio);
}

String ViewConfiguration::toString() {
    return "$size at ${debugFormatDouble(devicePixelRatio)}x";
}

RenderView::RenderView(RenderBox child, ViewConfiguration configuration, FlutterView window) {
    {
        assert(configuration != nullptr);
        _configuration = configuration;
        _window = window;
    }
    {
        this.child = child;
    }
}

Size RenderView::size() {
    return _size;
}

ViewConfiguration RenderView::configuration() {
    return _configuration;
}

void RenderView::configuration(ViewConfiguration value) {
    assert(value != nullptr);
    if (configuration == value) {
        return;
    }
    ViewConfiguration oldConfiguration = _configuration;
    _configuration = value;
    if (oldConfiguration.toMatrix() != _configuration.toMatrix()) {
        replaceRootLayer(_updateMatricesAndCreateNewRootLayer());
    }
    assert(_rootTransform != nullptr);
    markNeedsLayout();
}

void RenderView::prepareInitialFrame() {
    assert(owner != nullptr);
    assert(_rootTransform == nullptr);
    scheduleInitialLayout();
    scheduleInitialPaint(_updateMatricesAndCreateNewRootLayer());
    assert(_rootTransform != nullptr);
}

void RenderView::debugAssertDoesMeetConstraints() {
    assert(false);
}

void RenderView::performResize() {
    assert(false);
}

void RenderView::performLayout() {
    assert(_rootTransform != nullptr);
    _size = configuration.size;
    assert(_size.isFinite);
    if (child != nullptr) {
        child!.layout(BoxConstraints.tight(_size));
    }
}

bool RenderView::hitTest(Offset position, HitTestResult result) {
    if (child != nullptr) {
        child!.hitTest(BoxHitTestResult.wrap(result)position);
    }
    result.add(HitTestEntry(this));
    return true;
}

HitTestResult RenderView::hitTestMouseTrackers(Offset position) {
    assert(position != nullptr);
    BoxHitTestResult result = BoxHitTestResult();
    hitTest(resultposition);
    return result;
}

bool RenderView::isRepaintBoundary() {
    return true;
}

void RenderView::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        context.paintChild(child!, offset);
    }
}

void RenderView::applyPaintTransform(RenderBox child, Matrix4 transform) {
    assert(_rootTransform != nullptr);
    transform.multiply(_rootTransform!);
    super.applyPaintTransform(child, transform);
}

void RenderView::compositeFrame() {
    if (!kReleaseMode) {
        Timeline.startSync("COMPOSITING");
    }
    ;
}

Rect RenderView::paintBounds() {
    return Offset.zero & (size * configuration.devicePixelRatio);
}

Rect RenderView::semanticBounds() {
    assert(_rootTransform != nullptr);
    return MatrixUtils.transformRect(_rootTransform!, Offset.zero & size);
}

void RenderView::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    assert(());
    properties.add(<Size>DiagnosticsProperty("window size", _window.physicalSize"in physical pixels"));
    properties.add(DoubleProperty("device pixel ratio", _window.devicePixelRatio"physical pixels per logical pixel"));
    properties.add(<ViewConfiguration>DiagnosticsProperty("configuration", configuration"in logical pixels"));
    if (_window.platformDispatcher.semanticsEnabled) {
        properties.add(DiagnosticsNode.message("semantics enabled"));
    }
}

TransformLayer RenderView::_updateMatricesAndCreateNewRootLayer() {
    _rootTransform = configuration.toMatrix();
    TransformLayer rootLayer = TransformLayer(_rootTransform);
    rootLayer.attach(this);
    assert(_rootTransform != nullptr);
    return rootLayer;
}

void RenderView::_updateSystemChrome() {
    Rect bounds = paintBounds;
    Offset top = Offset(bounds.center.dx, _window.padding.top / 2.0);
    Offset bottom = Offset(bounds.center.dx, bounds.bottom - 1.0 - _window.padding.bottom / 2.0);
    SystemUiOverlayStyle upperOverlayStyle = layer!.<SystemUiOverlayStyle>find(top);
    SystemUiOverlayStyle lowerOverlayStyle;
    ;
    if (upperOverlayStyle != nullptr || lowerOverlayStyle != nullptr) {
        SystemUiOverlayStyle overlayStyle = SystemUiOverlayStyle(upperOverlayStyle?.statusBarBrightness, upperOverlayStyle?.statusBarIconBrightness, upperOverlayStyle?.statusBarColor, upperOverlayStyle?.systemStatusBarContrastEnforced, lowerOverlayStyle?.systemNavigationBarColor, lowerOverlayStyle?.systemNavigationBarDividerColor, lowerOverlayStyle?.systemNavigationBarIconBrightness, lowerOverlayStyle?.systemNavigationBarContrastEnforced);
        SystemChrome.setSystemUIOverlayStyle(overlayStyle);
    }
}
