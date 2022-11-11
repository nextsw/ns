#include "view.hpp"
Matrix4 ViewConfigurationCls::toMatrix() {
    return Matrix4Cls->diagonal3Values(devicePixelRatio, devicePixelRatio, 1.0);
}

bool ViewConfigurationCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<ViewConfiguration>(other) && other->size == size && other->devicePixelRatio == devicePixelRatio;
}

int ViewConfigurationCls::hashCode() {
    return ObjectCls->hash(size, devicePixelRatio);
}

String ViewConfigurationCls::toString() {
    return __s("$size at ${debugFormatDouble(devicePixelRatio)}x");
}

RenderViewCls::RenderViewCls(RenderBox child, ViewConfiguration configuration, FlutterView window) {
    {
        assert(configuration != nullptr);
        _configuration = configuration;
        _window = window;
    }
    {
        this->child = child;
    }
}

Size RenderViewCls::size() {
    return _size;
}

ViewConfiguration RenderViewCls::configuration() {
    return _configuration;
}

void RenderViewCls::configuration(ViewConfiguration value) {
    assert(value != nullptr);
    if (configuration == value) {
        return;
    }
    ViewConfiguration oldConfiguration = _configuration;
    _configuration = value;
    if (oldConfiguration->toMatrix() != _configuration->toMatrix()) {
        replaceRootLayer(_updateMatricesAndCreateNewRootLayer());
    }
    assert(_rootTransform != nullptr);
    markNeedsLayout();
}

void RenderViewCls::prepareInitialFrame() {
    assert(owner != nullptr);
    assert(_rootTransform == nullptr);
    scheduleInitialLayout();
    scheduleInitialPaint(_updateMatricesAndCreateNewRootLayer());
    assert(_rootTransform != nullptr);
}

void RenderViewCls::debugAssertDoesMeetConstraints() {
    assert(false);
}

void RenderViewCls::performResize() {
    assert(false);
}

void RenderViewCls::performLayout() {
    assert(_rootTransform != nullptr);
    _size = configuration->size;
    assert(_size->isFinite);
    if (child != nullptr) {
        child!->layout(BoxConstraintsCls->tight(_size));
    }
}

bool RenderViewCls::hitTest(Offset position, HitTestResult result) {
    if (child != nullptr) {
        child!->hitTest(BoxHitTestResultCls->wrap(result)position);
    }
    result->add(make<HitTestEntryCls>(this));
    return true;
}

HitTestResult RenderViewCls::hitTestMouseTrackers(Offset position) {
    assert(position != nullptr);
    BoxHitTestResult result = make<BoxHitTestResultCls>();
    hitTest(resultposition);
    return result;
}

bool RenderViewCls::isRepaintBoundary() {
    return true;
}

void RenderViewCls::paint(PaintingContext context, Offset offset) {
    if (child != nullptr) {
        context->paintChild(child!, offset);
    }
}

void RenderViewCls::applyPaintTransform(RenderBox child, Matrix4 transform) {
    assert(_rootTransform != nullptr);
    transform->multiply(_rootTransform!);
    super->applyPaintTransform(child, transform);
}

void RenderViewCls::compositeFrame() {
    if (!kReleaseMode) {
        TimelineCls->startSync(__s("COMPOSITING"));
    }
    try {
        SceneBuilder builder = ui->make<SceneBuilderCls>();
        Scene scene = layer!->buildScene(builder);
        if (automaticSystemUiAdjustment) {
            _updateSystemChrome();
        }
        _window->render(scene);
        scene->dispose();
        assert([=] () {
            if (debugRepaintRainbowEnabled || debugRepaintTextRainbowEnabled) {
                debugCurrentRepaintColor = debugCurrentRepaintColor->withHue((debugCurrentRepaintColor->hue + 2.0) % 360.0);
            }
            return true;
        }());
    } finally {
        if (!kReleaseMode) {
            TimelineCls->finishSync();
        }
    };
}

Rect RenderViewCls::paintBounds() {
    return OffsetCls::zero & (size * configuration->devicePixelRatio);
}

Rect RenderViewCls::semanticBounds() {
    assert(_rootTransform != nullptr);
    return MatrixUtilsCls->transformRect(_rootTransform!, OffsetCls::zero & size);
}

void RenderViewCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    assert([=] () {
        properties->add(DiagnosticsNodeCls->message(__s("debug mode enabled - ${kIsWeb ? 'Web' :  Platform.operatingSystem}")));
        return true;
    }());
    properties->add(<Size>make<DiagnosticsPropertyCls>(__s("window size"), _window->physicalSize()__s("in physical pixels")));
    properties->add(make<DoublePropertyCls>(__s("device pixel ratio"), _window->devicePixelRatio__s("physical pixels per logical pixel")));
    properties->add(<ViewConfiguration>make<DiagnosticsPropertyCls>(__s("configuration"), configuration__s("in logical pixels")));
    if (_window->platformDispatcher->semanticsEnabled) {
        properties->add(DiagnosticsNodeCls->message(__s("semantics enabled")));
    }
}

TransformLayer RenderViewCls::_updateMatricesAndCreateNewRootLayer() {
    _rootTransform = configuration->toMatrix();
    TransformLayer rootLayer = make<TransformLayerCls>(_rootTransform);
    rootLayer->attach(this);
    assert(_rootTransform != nullptr);
    return rootLayer;
}

void RenderViewCls::_updateSystemChrome() {
    Rect bounds = paintBounds();
    Offset top = make<OffsetCls>(bounds->center->dx, _window->padding->top / 2.0);
    Offset bottom = make<OffsetCls>(bounds->center->dx, bounds->bottom - 1.0 - _window->padding->bottom / 2.0);
    SystemUiOverlayStyle upperOverlayStyle = layer!-><SystemUiOverlayStyle>find(top);
    SystemUiOverlayStyle lowerOverlayStyle;
    ;
    if (upperOverlayStyle != nullptr || lowerOverlayStyle != nullptr) {
        SystemUiOverlayStyle overlayStyle = make<SystemUiOverlayStyleCls>(upperOverlayStyle?->statusBarBrightness, upperOverlayStyle?->statusBarIconBrightness, upperOverlayStyle?->statusBarColor, upperOverlayStyle?->systemStatusBarContrastEnforced, lowerOverlayStyle?->systemNavigationBarColor, lowerOverlayStyle?->systemNavigationBarDividerColor, lowerOverlayStyle?->systemNavigationBarIconBrightness, lowerOverlayStyle?->systemNavigationBarContrastEnforced);
        SystemChromeCls->setSystemUIOverlayStyle(overlayStyle);
    }
}
