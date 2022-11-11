#include "binding.hpp"
void RendererBindingCls::initInstances() {
    super->initInstances();
    _instance = this;
    _pipelineOwner = make<PipelineOwnerCls>(ensureVisualUpdate, _handleSemanticsOwnerCreated, _handleSemanticsOwnerDisposed);
    auto _c1 = platformDispatcher;_c1.onMetricsChanged = auto _c2 = handleMetricsChanged;_c2.onTextScaleFactorChanged = auto _c3 = handleTextScaleFactorChanged;_c3.onPlatformBrightnessChanged = auto _c4 = handlePlatformBrightnessChanged;_c4.onSemanticsEnabledChanged = auto _c5 = _handleSemanticsEnabledChanged;_c5.onSemanticsAction = _handleSemanticsAction;_c5;_c4;_c3;_c2;_c1;
    initRenderView();
    _handleSemanticsEnabledChanged();
    assert(renderView() != nullptr);
    addPersistentFrameCallback(_handlePersistentFrameCallback);
    initMouseTracker();
    if (kIsWeb) {
        addPostFrameCallback(_handleWebFirstFrame);
    }
}

RendererBinding RendererBindingCls::instance() {
    return BindingBaseCls->checkInstance(_instance);
}

void RendererBindingCls::initServiceExtensions() {
    super->initServiceExtensions();
    assert([=] () {
        registerBoolServiceExtension(__s("invertOversizedImages"), [=] () {
            debugInvertOversizedImages;
        }, [=] (bool value) {
            if (debugInvertOversizedImages != value) {
                debugInvertOversizedImages = value;
                return _forceRepaint();
            }
            return <void>value();
        });
        registerBoolServiceExtension(__s("debugPaint"), [=] () {
            debugPaintSizeEnabled;
        }, [=] (bool value) {
            if (debugPaintSizeEnabled == value) {
                return <void>value();
            }
            debugPaintSizeEnabled = value;
            return _forceRepaint();
        });
        registerBoolServiceExtension(__s("debugPaintBaselinesEnabled"), [=] () {
            debugPaintBaselinesEnabled;
        }, [=] (bool value) {
            if (debugPaintBaselinesEnabled == value) {
                return <void>value();
            }
            debugPaintBaselinesEnabled = value;
            return _forceRepaint();
        });
        registerBoolServiceExtension(__s("repaintRainbow"), [=] () {
            debugRepaintRainbowEnabled;
        }, [=] (bool value) {
            bool repaint = debugRepaintRainbowEnabled && !value;
            debugRepaintRainbowEnabled = value;
            if (repaint) {
                return _forceRepaint();
            }
            return <void>value();
        });
        registerServiceExtension(__s("debugDumpLayerTree"), [=] (Map<String, String> parameters) {
            String data = RendererBindingCls::instance->renderView->debugLayer?->toStringDeep() | __s("Layer tree unavailable.");
                    Map<String, Object> map1 = make<MapCls<>>();        map1.set(__s("data"), data);return list1;
        });
        registerBoolServiceExtension(__s("debugDisableClipLayers"), [=] () {
            debugDisableClipLayers;
        }, [=] (bool value) {
            if (debugDisableClipLayers == value) {
                return <void>value();
            }
            debugDisableClipLayers = value;
            return _forceRepaint();
        });
        registerBoolServiceExtension(__s("debugDisablePhysicalShapeLayers"), [=] () {
            debugDisablePhysicalShapeLayers;
        }, [=] (bool value) {
            if (debugDisablePhysicalShapeLayers == value) {
                return <void>value();
            }
            debugDisablePhysicalShapeLayers = value;
            return _forceRepaint();
        });
        registerBoolServiceExtension(__s("debugDisableOpacityLayers"), [=] () {
            debugDisableOpacityLayers;
        }, [=] (bool value) {
            if (debugDisableOpacityLayers == value) {
                return <void>value();
            }
            debugDisableOpacityLayers = value;
            return _forceRepaint();
        });
        return true;
    }());
    if (!kReleaseMode) {
        registerServiceExtension(__s("debugDumpRenderTree"), [=] (Map<String, String> parameters) {
            String data = RendererBindingCls::instance->renderView->toStringDeep();
                    Map<String, Object> map2 = make<MapCls<>>();        map2.set(__s("data"), data);return list2;
        });
        registerServiceExtension(__s("debugDumpSemanticsTreeInTraversalOrder"), [=] (Map<String, String> parameters) {
            String data = RendererBindingCls::instance->renderView->debugSemantics?->toStringDeep() | __s("Semantics not collected.");
                    Map<String, Object> map3 = make<MapCls<>>();        map3.set(__s("data"), data);return list3;
        });
        registerServiceExtension(__s("debugDumpSemanticsTreeInInverseHitTestOrder"), [=] (Map<String, String> parameters) {
            String data = RendererBindingCls::instance->renderView->debugSemantics?->toStringDeep(DebugSemanticsDumpOrderCls::inverseHitTest) | __s("Semantics not collected.");
                    Map<String, Object> map4 = make<MapCls<>>();        map4.set(__s("data"), data);return list4;
        });
        registerBoolServiceExtension(__s("profileRenderObjectPaints"), [=] () {
            debugProfilePaintsEnabled;
        }, [=] (bool value) {
            if (debugProfilePaintsEnabled != value) {
                debugProfilePaintsEnabled = value;
            }
        });
        registerBoolServiceExtension(__s("profileRenderObjectLayouts"), [=] () {
            debugProfileLayoutsEnabled;
        }, [=] (bool value) {
            if (debugProfileLayoutsEnabled != value) {
                debugProfileLayoutsEnabled = value;
            }
        });
    }
}

void RendererBindingCls::initRenderView() {
    assert(!_debugIsRenderViewInitialized);
    assert([=] () {
        _debugIsRenderViewInitialized = true;
        return true;
    }());
    renderView() = make<RenderViewCls>(createViewConfiguration(), window);
    renderView()->prepareInitialFrame();
}

MouseTracker RendererBindingCls::mouseTracker() {
    return _mouseTracker!;
}

PipelineOwner RendererBindingCls::pipelineOwner() {
    return _pipelineOwner;
}

RenderView RendererBindingCls::renderView() {
    return as<RenderView>(_pipelineOwner->rootNode()!);
}

void RendererBindingCls::renderView(RenderView value) {
    assert(value != nullptr);
    _pipelineOwner->rootNode() = value;
}

void RendererBindingCls::handleMetricsChanged() {
    assert(renderView() != nullptr);
    renderView()->configuration() = createViewConfiguration();
    if (renderView()->child != nullptr) {
        scheduleForcedFrame();
    }
}

void RendererBindingCls::handleTextScaleFactorChanged() {
}

void RendererBindingCls::handlePlatformBrightnessChanged() {
}

ViewConfiguration RendererBindingCls::createViewConfiguration() {
    double devicePixelRatio = window->devicePixelRatio;
    return make<ViewConfigurationCls>(window->physicalSize / devicePixelRatio, devicePixelRatio);
}

void RendererBindingCls::initMouseTracker(MouseTracker tracker) {
    _mouseTracker?->dispose();
    _mouseTracker = tracker | make<MouseTrackerCls>();
}

void RendererBindingCls::dispatchEvent(PointerEvent event, HitTestResult hitTestResult) {
    _mouseTracker!->updateWithEvent(event, [=] () {
        (hitTestResult == nullptr || is<PointerMoveEvent>(event))? renderView()->hitTestMouseTrackers(event->position) : hitTestResult;
    });
    super->dispatchEvent(event, hitTestResult);
}

void RendererBindingCls::setSemanticsEnabled(bool enabled) {
    if (enabled) {
        _semanticsHandle |= _pipelineOwner->ensureSemantics();
    } else {
        _semanticsHandle?->dispose();
        _semanticsHandle = nullptr;
    }
}

bool RendererBindingCls::sendFramesToEngine() {
    return _firstFrameSent || _firstFrameDeferredCount == 0;
}

void RendererBindingCls::deferFirstFrame() {
    assert(_firstFrameDeferredCount >= 0);
    _firstFrameDeferredCount += 1;
}

void RendererBindingCls::allowFirstFrame() {
    assert(_firstFrameDeferredCount > 0);
    _firstFrameDeferredCount -= 1;
    if (!_firstFrameSent) {
        scheduleWarmUpFrame();
    }
}

void RendererBindingCls::resetFirstFrameSent() {
    _firstFrameSent = false;
}

void RendererBindingCls::drawFrame() {
    assert(renderView() != nullptr);
    pipelineOwner()->flushLayout();
    pipelineOwner()->flushCompositingBits();
    pipelineOwner()->flushPaint();
    if (sendFramesToEngine()) {
        renderView()->compositeFrame();
        pipelineOwner()->flushSemantics();
        _firstFrameSent = true;
    }
}

Future<void> RendererBindingCls::performReassemble() {
    await await super->performReassemble();
    if (BindingBaseCls::debugReassembleConfig?->widgetName == nullptr) {
        if (!kReleaseMode) {
            TimelineCls->startSync(__s("Preparing Hot Reload (layout)"));
        }
        try {
            renderView()->reassemble();
        } finally {
            if (!kReleaseMode) {
                TimelineCls->finishSync();
            }
        };
    }
    scheduleWarmUpFrame();
    await await endOfFrame;
}

void RendererBindingCls::hitTest(HitTestResult result, Offset position) {
    assert(renderView() != nullptr);
    assert(result != nullptr);
    assert(position != nullptr);
    renderView()->hitTest(result, position);
    super->hitTest(result, position);
}

void RendererBindingCls::_handleSemanticsEnabledChanged() {
    setSemanticsEnabled(platformDispatcher->semanticsEnabled);
}

void RendererBindingCls::_handleWebFirstFrame(Duration _) {
    assert(kIsWeb);
    MethodChannel methodChannel = make<MethodChannelCls>(__s("flutter/service_worker"));
    methodChannel-><void>invokeMethod(__s("first-frame"));
}

void RendererBindingCls::_handleSemanticsAction(int id, SemanticsAction action, ByteData args) {
    _pipelineOwner->semanticsOwner()?->performAction(id, action, args != nullptr? make<StandardMessageCodecCls>()->decodeMessage(args) : nullptr);
}

void RendererBindingCls::_handleSemanticsOwnerCreated() {
    renderView()->scheduleInitialSemantics();
}

void RendererBindingCls::_handleSemanticsOwnerDisposed() {
    renderView()->clearSemantics();
}

void RendererBindingCls::_handlePersistentFrameCallback(Duration timeStamp) {
    drawFrame();
    _scheduleMouseTrackerUpdate();
}

void RendererBindingCls::_scheduleMouseTrackerUpdate() {
    assert(!_debugMouseTrackerUpdateScheduled);
    assert([=] () {
        _debugMouseTrackerUpdateScheduled = true;
        return true;
    }());
    SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration duration) {
        assert(_debugMouseTrackerUpdateScheduled);
        assert([=] () {
            _debugMouseTrackerUpdateScheduled = false;
            return true;
        }());
        _mouseTracker!->updateAllDevices(renderView()->hitTestMouseTrackers);
    });
}

Future<void> RendererBindingCls::_forceRepaint() {
    RenderObjectVisitor visitor;
    visitor = [=] (RenderObject child) {
        child->markNeedsPaint();
        child->visitChildren(visitor);
    };
    instance()->renderView()->visitChildren(visitor);
    return endOfFrame;
}

void debugDumpRenderTree() {
    debugPrint(RendererBindingCls::instance->renderView->toStringDeep());
}

void debugDumpLayerTree() {
    debugPrint(RendererBindingCls::instance->renderView->debugLayer?->toStringDeep());
}

void debugDumpSemanticsTree(DebugSemanticsDumpOrder childOrder) {
    debugPrint(RendererBindingCls::instance->renderView->debugSemantics?->toStringDeep(childOrder) | __s("Semantics not collected."));
}

RenderingFlutterBindingCls::RenderingFlutterBindingCls(RenderBox root) {
    {
        assert(renderView != nullptr);
        renderView->child = root;
    }
}

RendererBinding RenderingFlutterBindingCls::ensureInitialized() {
    if (RendererBindingCls::_instance == nullptr) {
        make<RenderingFlutterBindingCls>();
    }
    return RendererBindingCls::instance;
}
