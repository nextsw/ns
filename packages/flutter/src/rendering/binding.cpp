#include "binding.hpp"
void RendererBinding::initInstances() {
    super.initInstances();
    _instance = this;
    _pipelineOwner = PipelineOwner(ensureVisualUpdate, _handleSemanticsOwnerCreated, _handleSemanticsOwnerDisposed);
    ;
    initRenderView();
    _handleSemanticsEnabledChanged();
    assert(renderView != nullptr);
    addPersistentFrameCallback(_handlePersistentFrameCallback);
    initMouseTracker();
    if (kIsWeb) {
        addPostFrameCallback(_handleWebFirstFrame);
    }
}

RendererBinding RendererBinding::instance() {
    return BindingBase.checkInstance(_instance);
}

void RendererBinding::initServiceExtensions() {
    super.initServiceExtensions();
    assert(());
    if (!kReleaseMode) {
        registerServiceExtension("debugDumpRenderTree", );
        registerServiceExtension("debugDumpSemanticsTreeInTraversalOrder", );
        registerServiceExtension("debugDumpSemanticsTreeInInverseHitTestOrder", );
        registerBoolServiceExtension("profileRenderObjectPaints", , );
        registerBoolServiceExtension("profileRenderObjectLayouts", , );
    }
}

void RendererBinding::initRenderView() {
    assert(!_debugIsRenderViewInitialized);
    assert(());
    renderView = RenderView(createViewConfiguration(), window);
    renderView.prepareInitialFrame();
}

MouseTracker RendererBinding::mouseTracker() {
    return _mouseTracker!;
}

PipelineOwner RendererBinding::pipelineOwner() {
    return _pipelineOwner;
}

RenderView RendererBinding::renderView() {
    return (;
}

void RendererBinding::renderView(RenderView value) {
    assert(value != nullptr);
    _pipelineOwner.rootNode = value;
}

void RendererBinding::handleMetricsChanged() {
    assert(renderView != nullptr);
    renderView.configuration = createViewConfiguration();
    if (renderView.child != nullptr) {
        scheduleForcedFrame();
    }
}

void RendererBinding::handleTextScaleFactorChanged() {
}

void RendererBinding::handlePlatformBrightnessChanged() {
}

ViewConfiguration RendererBinding::createViewConfiguration() {
    double devicePixelRatio = window.devicePixelRatio;
    return ViewConfiguration(window.physicalSize / devicePixelRatio, devicePixelRatio);
}

void RendererBinding::initMouseTracker(MouseTracker tracker) {
    _mouseTracker?.dispose();
    _mouseTracker = tracker ?? MouseTracker();
}

void RendererBinding::dispatchEvent(PointerEvent event, HitTestResult hitTestResult) {
    _mouseTracker!.updateWithEvent(event, );
    super.dispatchEvent(event, hitTestResult);
}

void RendererBinding::setSemanticsEnabled(bool enabled) {
    if (enabled) {
        _semanticsHandle = _pipelineOwner.ensureSemantics();
    } else {
        _semanticsHandle?.dispose();
        _semanticsHandle = nullptr;
    }
}

bool RendererBinding::sendFramesToEngine() {
    return _firstFrameSent || _firstFrameDeferredCount == 0;
}

void RendererBinding::deferFirstFrame() {
    assert(_firstFrameDeferredCount >= 0);
    _firstFrameDeferredCount = 1;
}

void RendererBinding::allowFirstFrame() {
    assert(_firstFrameDeferredCount > 0);
    _firstFrameDeferredCount = 1;
    if (!_firstFrameSent) {
        scheduleWarmUpFrame();
    }
}

void RendererBinding::resetFirstFrameSent() {
    _firstFrameSent = false;
}

void RendererBinding::drawFrame() {
    assert(renderView != nullptr);
    pipelineOwner.flushLayout();
    pipelineOwner.flushCompositingBits();
    pipelineOwner.flushPaint();
    if (sendFramesToEngine) {
        renderView.compositeFrame();
        pipelineOwner.flushSemantics();
        _firstFrameSent = true;
    }
}

Future<void> RendererBinding::performReassemble() {
    await await super.performReassemble();
    if (BindingBase.debugReassembleConfig?.widgetName == nullptr) {
        if (!kReleaseMode) {
            Timeline.startSync("Preparing Hot Reload (layout)");
        }
        ;
    }
    scheduleWarmUpFrame();
    await await endOfFrame;
}

void RendererBinding::hitTest(Offset position, HitTestResult result) {
    assert(renderView != nullptr);
    assert(result != nullptr);
    assert(position != nullptr);
    renderView.hitTest(resultposition);
    super.hitTest(result, position);
}

void RendererBinding::_handleSemanticsEnabledChanged() {
    setSemanticsEnabled(platformDispatcher.semanticsEnabled);
}

void RendererBinding::_handleWebFirstFrame(Duration _) {
    assert(kIsWeb);
    MethodChannel methodChannel = MethodChannel("flutter/service_worker");
    methodChannel.<void>invokeMethod("first-frame");
}

void RendererBinding::_handleSemanticsAction(SemanticsAction action, ByteData args, int id) {
    _pipelineOwner.semanticsOwner?.performAction(id, action, args != nullptr? const StandardMessageCodec().decodeMessage(args) : nullptr);
}

void RendererBinding::_handleSemanticsOwnerCreated() {
    renderView.scheduleInitialSemantics();
}

void RendererBinding::_handleSemanticsOwnerDisposed() {
    renderView.clearSemantics();
}

void RendererBinding::_handlePersistentFrameCallback(Duration timeStamp) {
    drawFrame();
    _scheduleMouseTrackerUpdate();
}

void RendererBinding::_scheduleMouseTrackerUpdate() {
    assert(!_debugMouseTrackerUpdateScheduled);
    assert(());
    SchedulerBinding.instance.addPostFrameCallback();
}

Future<void> RendererBinding::_forceRepaint() {
    RenderObjectVisitor visitor;
    visitor = ;
    instance.renderView.visitChildren(visitor);
    return endOfFrame;
}

void debugDumpRenderTree() {
    debugPrint(RendererBinding.instance.renderView.toStringDeep());
}

void debugDumpLayerTree() {
    debugPrint(RendererBinding.instance.renderView.debugLayer?.toStringDeep());
}

void debugDumpSemanticsTree(DebugSemanticsDumpOrder childOrder) {
    debugPrint(RendererBinding.instance.renderView.debugSemantics?.toStringDeep(childOrder) ?? "Semantics not collected.");
}

RenderingFlutterBinding::RenderingFlutterBinding(RenderBox root) {
    {
        assert(renderView != nullptr);
        renderView.child = root;
    }
}

RendererBinding RenderingFlutterBinding::ensureInitialized() {
    if (RendererBinding._instance == nullptr) {
        RenderingFlutterBinding();
    }
    return RendererBinding.instance;
}
