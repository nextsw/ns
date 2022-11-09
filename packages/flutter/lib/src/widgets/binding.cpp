#include "binding.hpp"
Future<bool> WidgetsBindingObserverCls::didPopRoute() {
    return <bool>value(false);
}

Future<bool> WidgetsBindingObserverCls::didPushRoute(String route) {
    return <bool>value(false);
}

Future<bool> WidgetsBindingObserverCls::didPushRouteInformation(RouteInformation routeInformation) {
    return didPushRoute(routeInformation->location!);
}

void WidgetsBindingObserverCls::didChangeMetrics() {
}

void WidgetsBindingObserverCls::didChangeTextScaleFactor() {
}

void WidgetsBindingObserverCls::didChangePlatformBrightness() {
}

void WidgetsBindingObserverCls::didChangeLocales(List<Locale> locales) {
}

void WidgetsBindingObserverCls::didChangeAppLifecycleState(AppLifecycleState state) {
}

void WidgetsBindingObserverCls::didHaveMemoryPressure() {
}

void WidgetsBindingObserverCls::didChangeAccessibilityFeatures() {
}

void WidgetsBindingCls::initInstances() {
    super->initInstances();
    _instance = this;
    assert([=] () {
        _debugAddStackFilters();
        return true;
    }());
    _buildOwner = make<BuildOwnerCls>();
    buildOwner!->onBuildScheduled = _handleBuildScheduled;
    platformDispatcher->onLocaleChanged = handleLocaleChanged;
    platformDispatcher->onAccessibilityFeaturesChanged = handleAccessibilityFeaturesChanged;
    SystemChannelsCls::navigation->setMethodCallHandler(_handleNavigationInvocation);
    assert([=] () {
        FlutterErrorDetailsCls::propertiesTransformers->add(debugTransformDebugCreator);
        return true;
    }());
    platformMenuDelegate = make<DefaultPlatformMenuDelegateCls>();
}

WidgetsBinding WidgetsBindingCls::instance() {
    return BindingBaseCls->checkInstance(_instance);
}

void WidgetsBindingCls::initServiceExtensions() {
    super->initServiceExtensions();
    if (!kReleaseMode) {
        registerServiceExtension("debugDumpApp", [=] (Map<String, String> parameters) {
            String data = _debugDumpAppString();
                    Map<String, Object> map1 = make<MapCls<>>();        map1.set("data", data);return list1;
        });
        if (!kIsWeb) {
            registerBoolServiceExtension("showPerformanceOverlay", [=] ()             {
                <bool>value(WidgetsAppCls::showPerformanceOverlayOverride);
            }, [=] (bool value) {
                if (WidgetsAppCls::showPerformanceOverlayOverride == value) {
                    return <void>value();
                }
                WidgetsAppCls::showPerformanceOverlayOverride = value;
                return _forceRebuild();
            });
        }
        registerServiceExtension("didSendFirstFrameEvent", [=] () {
                    Map<String, dynamic> map2 = make<MapCls<>>();        map2.set("enabled", _needToReportFirstFrame? "false" : "true");return list2;
        });
        registerServiceExtension("didSendFirstFrameRasterizedEvent", [=] () {
                    Map<String, dynamic> map3 = make<MapCls<>>();        map3.set("enabled", firstFrameRasterized? "true" : "false");return list3;
        });
        registerServiceExtension("fastReassemble", [=] (Map<String, Object> params) {
            String className = ((String)params["className"]);
            BindingBaseCls::debugReassembleConfig = make<DebugReassembleConfigCls>(className);
            try {
                await await reassembleApplication();
            } finally {
                BindingBaseCls::debugReassembleConfig = nullptr;
            };
                    Map<String, String> map4 = make<MapCls<>>();        map4.set("type", "Success");return list4;
        });
        registerBoolServiceExtension("profileWidgetBuilds", [=] ()         {
            debugProfileBuildsEnabled;
        }, [=] (bool value) {
            if (debugProfileBuildsEnabled != value) {
                debugProfileBuildsEnabled = value;
            }
        });
        registerBoolServiceExtension("profileUserWidgetBuilds", [=] ()         {
            debugProfileBuildsEnabledUserWidgets;
        }, [=] (bool value) {
            if (debugProfileBuildsEnabledUserWidgets != value) {
                debugProfileBuildsEnabledUserWidgets = value;
            }
        });
    }
    assert([=] () {
        registerBoolServiceExtension("debugAllowBanner", [=] ()         {
            <bool>value(WidgetsAppCls::debugAllowBannerOverride);
        }, [=] (bool value) {
            if (WidgetsAppCls::debugAllowBannerOverride == value) {
                return <void>value();
            }
            WidgetsAppCls::debugAllowBannerOverride = value;
            return _forceRebuild();
        });
        registerBoolServiceExtension("debugWidgetInspector", [=] ()         {
            WidgetsAppCls::debugShowWidgetInspectorOverride;
        }, [=] (bool value) {
            if (WidgetsAppCls::debugShowWidgetInspectorOverride == value) {
                return <void>value();
            }
            WidgetsAppCls::debugShowWidgetInspectorOverride = value;
            return _forceRebuild();
        });
        WidgetInspectorServiceCls::instance->initServiceExtensions(registerServiceExtension);
        return true;
    }());
}

BuildOwner WidgetsBindingCls::buildOwner() {
    return _buildOwner;
}

FocusManager WidgetsBindingCls::focusManager() {
    return _buildOwner!->focusManager;
}

void WidgetsBindingCls::addObserver(WidgetsBindingObserver observer) {
    return _observers->add(observer);
}

bool WidgetsBindingCls::removeObserver(WidgetsBindingObserver observer) {
    return _observers->remove(observer);
}

void WidgetsBindingCls::handleMetricsChanged() {
    super->handleMetricsChanged();
    for (WidgetsBindingObserver observer : _observers) {
        observer->didChangeMetrics();
    }
}

void WidgetsBindingCls::handleTextScaleFactorChanged() {
    super->handleTextScaleFactorChanged();
    for (WidgetsBindingObserver observer : _observers) {
        observer->didChangeTextScaleFactor();
    }
}

void WidgetsBindingCls::handlePlatformBrightnessChanged() {
    super->handlePlatformBrightnessChanged();
    for (WidgetsBindingObserver observer : _observers) {
        observer->didChangePlatformBrightness();
    }
}

void WidgetsBindingCls::handleAccessibilityFeaturesChanged() {
    super->handleAccessibilityFeaturesChanged();
    for (WidgetsBindingObserver observer : _observers) {
        observer->didChangeAccessibilityFeatures();
    }
}

void WidgetsBindingCls::handleLocaleChanged() {
    dispatchLocalesChanged(platformDispatcher->locales);
}

void WidgetsBindingCls::dispatchLocalesChanged(List<Locale> locales) {
    for (WidgetsBindingObserver observer : _observers) {
        observer->didChangeLocales(locales);
    }
}

void WidgetsBindingCls::dispatchAccessibilityFeaturesChanged() {
    for (WidgetsBindingObserver observer : _observers) {
        observer->didChangeAccessibilityFeatures();
    }
}

Future<void> WidgetsBindingCls::handlePopRoute() {
    for (WidgetsBindingObserver observer : <WidgetsBindingObserver>of(_observers)) {
        if (await observer->didPopRoute()) {
            return;
        }
    }
    SystemNavigatorCls->pop();
}

Future<void> WidgetsBindingCls::handlePushRoute(String route) {
    for (WidgetsBindingObserver observer : <WidgetsBindingObserver>of(_observers)) {
        if (await observer->didPushRoute(route)) {
            return;
        }
    }
}

void WidgetsBindingCls::handleAppLifecycleStateChanged(AppLifecycleState state) {
    super->handleAppLifecycleStateChanged(state);
    for (WidgetsBindingObserver observer : _observers) {
        observer->didChangeAppLifecycleState(state);
    }
}

void WidgetsBindingCls::handleMemoryPressure() {
    super->handleMemoryPressure();
    for (WidgetsBindingObserver observer : _observers) {
        observer->didHaveMemoryPressure();
    }
}

bool WidgetsBindingCls::firstFrameRasterized() {
    return _firstFrameCompleter->isCompleted;
}

Future<void> WidgetsBindingCls::waitUntilFirstFrameRasterized() {
    return _firstFrameCompleter->future;
}

bool WidgetsBindingCls::debugDidSendFirstFrameEvent() {
    return !_needToReportFirstFrame;
}

void WidgetsBindingCls::drawFrame() {
    assert(!debugBuildingDirtyElements);
    assert([=] () {
        debugBuildingDirtyElements = true;
        return true;
    }());
    TimingsCallback firstFrameCallback;
    if (_needToReportFirstFrame) {
        assert(!_firstFrameCompleter->isCompleted);
        firstFrameCallback = [=] (List<FrameTiming> timings) {
            assert(sendFramesToEngine);
            if (!kReleaseMode) {
                developer->UserTagCls::defaultTag->makeCurrent();
                developer->TimelineCls->instantSync("Rasterized first useful frame");
                developer->postEvent("Flutter.FirstFrame", makeMap(makeList(), makeList());
            }
            SchedulerBindingCls::instance->removeTimingsCallback(firstFrameCallback!);
            firstFrameCallback = nullptr;
            _firstFrameCompleter->complete();
        };
        SchedulerBindingCls::instance->addTimingsCallback(firstFrameCallback!);
    }
    try {
        if (renderViewElement != nullptr) {
            buildOwner!->buildScope(renderViewElement!);
        }
        super->drawFrame();
        buildOwner!->finalizeTree();
    } finally {
        assert([=] () {
            debugBuildingDirtyElements = false;
            return true;
        }());
    };
    if (!kReleaseMode) {
        if (_needToReportFirstFrame && sendFramesToEngine) {
            developer->TimelineCls->instantSync("Widgets built first useful frame");
        }
    }
    _needToReportFirstFrame = false;
    if (firstFrameCallback != nullptr && !sendFramesToEngine) {
        _needToReportFirstFrame = true;
        SchedulerBindingCls::instance->removeTimingsCallback(firstFrameCallback!);
    }
}

Element WidgetsBindingCls::renderViewElement() {
    return _renderViewElement;
}

bool WidgetsBindingCls::framesEnabled() {
    return super->framesEnabled && _readyToProduceFrames;
}

void WidgetsBindingCls::scheduleAttachRootWidget(Widget rootWidget) {
    TimerCls->run([=] () {
        attachRootWidget(rootWidget);
    });
}

void WidgetsBindingCls::attachRootWidget(Widget rootWidget) {
    bool isBootstrapFrame = renderViewElement == nullptr;
    _readyToProduceFrames = true;
    _renderViewElement = <RenderBox>make<RenderObjectToWidgetAdapterCls>(renderView, "[root]", rootWidget)->attachToRenderTree(buildOwner!, ((RenderObjectToWidgetElement<RenderBox>)renderViewElement));
    if (isBootstrapFrame) {
        SchedulerBindingCls::instance->ensureVisualUpdate();
    }
}

bool WidgetsBindingCls::isRootWidgetAttached() {
    return _renderViewElement != nullptr;
}

Future<void> WidgetsBindingCls::performReassemble() {
    assert([=] () {
        WidgetInspectorServiceCls::instance->performReassemble();
        return true;
    }());
    if (renderViewElement != nullptr) {
        buildOwner!->reassemble(renderViewElement!, BindingBaseCls::debugReassembleConfig);
    }
    return super->performReassemble();
}

Locale WidgetsBindingCls::computePlatformResolvedLocale(List<Locale> supportedLocales) {
    return platformDispatcher->computePlatformResolvedLocale(supportedLocales);
}

void WidgetsBindingCls::_debugAddStackFilters() {
    PartialStackFrame elementInflateWidget = make<PartialStackFrameCls>("package:flutter/src/widgets/framework.dart", "Element", "inflateWidget");
    PartialStackFrame elementUpdateChild = make<PartialStackFrameCls>("package:flutter/src/widgets/framework.dart", "Element", "updateChild");
    PartialStackFrame elementRebuild = make<PartialStackFrameCls>("package:flutter/src/widgets/framework.dart", "Element", "rebuild");
    PartialStackFrame componentElementPerformRebuild = make<PartialStackFrameCls>("package:flutter/src/widgets/framework.dart", "ComponentElement", "performRebuild");
    PartialStackFrame componentElementFirstBuild = make<PartialStackFrameCls>("package:flutter/src/widgets/framework.dart", "ComponentElement", "_firstBuild");
    PartialStackFrame componentElementMount = make<PartialStackFrameCls>("package:flutter/src/widgets/framework.dart", "ComponentElement", "mount");
    PartialStackFrame statefulElementFirstBuild = make<PartialStackFrameCls>("package:flutter/src/widgets/framework.dart", "StatefulElement", "_firstBuild");
    PartialStackFrame singleChildMount = make<PartialStackFrameCls>("package:flutter/src/widgets/framework.dart", "SingleChildRenderObjectElement", "mount");
    PartialStackFrame statefulElementRebuild = make<PartialStackFrameCls>("package:flutter/src/widgets/framework.dart", "StatefulElement", "performRebuild");
    String replacementString = "...     Normal element mounting";
    FlutterErrorCls->addDefaultStackFilter(make<RepetitiveStackFrameFilterCls>(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem), replacementString));
    FlutterErrorCls->addDefaultStackFilter(make<RepetitiveStackFrameFilterCls>(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem), replacementString));
    FlutterErrorCls->addDefaultStackFilter(make<RepetitiveStackFrameFilterCls>(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem), replacementString));
    FlutterErrorCls->addDefaultStackFilter(make<RepetitiveStackFrameFilterCls>(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem), replacementString));
    FlutterErrorCls->addDefaultStackFilter(make<RepetitiveStackFrameFilterCls>(makeList(ArrayItem, ArrayItem, ArrayItem), replacementString));
    FlutterErrorCls->addDefaultStackFilter(make<RepetitiveStackFrameFilterCls>(makeList(ArrayItem, ArrayItem), replacementString));
}

Future<void> WidgetsBindingCls::_forceRebuild() {
    if (renderViewElement != nullptr) {
        buildOwner!->reassemble(renderViewElement!, nullptr);
        return endOfFrame;
    }
    return <void>value();
}

Future<void> WidgetsBindingCls::_handlePushRouteInformation(Map<dynamic, dynamic> routeArguments) {
    for (WidgetsBindingObserver observer : <WidgetsBindingObserver>of(_observers)) {
        if (await observer->didPushRouteInformation(make<RouteInformationCls>(((String)routeArguments["location"]), ((Object)routeArguments["state"])))) {
            return;
        }
    }
}

Future<dynamic> WidgetsBindingCls::_handleNavigationInvocation(MethodCall methodCall) {
    ;
    return <dynamic>value();
}

void WidgetsBindingCls::_handleBuildScheduled() {
    assert([=] () {
        if (debugBuildingDirtyElements) {
            ;
        }
        return true;
    }());
    ensureVisualUpdate();
}

void runApp(Widget app) {
    auto _c1 = WidgetsFlutterBindingCls->ensureInitialized();_c1.auto _c2 = scheduleAttachRootWidget(app);_c2.scheduleWarmUpFrame();_c2;_c1;
}

String _debugDumpAppString() {
    String mode = kDebugMode? "DEBUG MODE" : kReleaseMode? "RELEASE MODE" : "PROFILE MODE";
    StringBuffer buffer = make<StringBufferCls>();
    buffer->writeln("${WidgetsBinding.instance.runtimeType} - $mode");
    if (WidgetsBindingCls::instance->renderViewElement != nullptr) {
        buffer->writeln(WidgetsBindingCls::instance->renderViewElement!->toStringDeep());
    } else {
        buffer->writeln("<no tree currently mounted>");
    }
    return buffer->toString();
}

void debugDumpApp() {
    debugPrint(_debugDumpAppString());
}

template<typename T : RenderObject> RenderObjectToWidgetAdapterCls<T>::RenderObjectToWidgetAdapterCls(Widget child, RenderObjectWithChildMixin<T> container, String debugShortDescription) {
}

template<typename T : RenderObject> RenderObjectToWidgetElement<T> RenderObjectToWidgetAdapterCls<T>::createElement() {
    return <T>make<RenderObjectToWidgetElementCls>(this);
}

template<typename T : RenderObject> RenderObjectWithChildMixin<T> RenderObjectToWidgetAdapterCls<T>::createRenderObject(BuildContext context) {
    return container;
}

template<typename T : RenderObject> void RenderObjectToWidgetAdapterCls<T>::updateRenderObject(BuildContext context, RenderObject renderObject) {
}

template<typename T : RenderObject> RenderObjectToWidgetElement<T> RenderObjectToWidgetAdapterCls<T>::attachToRenderTree(RenderObjectToWidgetElement<T> element, BuildOwner owner) {
    if (element == nullptr) {
        owner->lockState([=] () {
            element = createElement();
            assert(element != nullptr);
            element!->assignOwner(owner);
        });
        owner->buildScope(element!, [=] () {
            element!->mount(nullptr, nullptr);
        });
    } else {
        element->_newWidget = this;
        element->markNeedsBuild();
    }
    return element!;
}

template<typename T : RenderObject> String RenderObjectToWidgetAdapterCls<T>::toStringShort() {
    return debugShortDescription ?? super->toStringShort();
}

template<typename T : RenderObject> void RenderObjectToWidgetElementCls<T>::visitChildren(ElementVisitor visitor) {
    if (_child != nullptr) {
        visitor(_child!);
    }
}

template<typename T : RenderObject> void RenderObjectToWidgetElementCls<T>::forgetChild(Element child) {
    assert(child == _child);
    _child = nullptr;
    super->forgetChild(child);
}

template<typename T : RenderObject> void RenderObjectToWidgetElementCls<T>::mount(Object newSlot, Element parent) {
    assert(parent == nullptr);
    super->mount(parent, newSlot);
    _rebuild();
    assert(_child != nullptr);
}

template<typename T : RenderObject> void RenderObjectToWidgetElementCls<T>::update(RenderObjectToWidgetAdapter<T> newWidget) {
    super->update(newWidget);
    assert(widget == newWidget);
    _rebuild();
}

template<typename T : RenderObject> void RenderObjectToWidgetElementCls<T>::performRebuild() {
    if (_newWidget != nullptr) {
        Widget newWidget = _newWidget!;
        _newWidget = nullptr;
        update(((RenderObjectToWidgetAdapter<T>)newWidget));
    }
    super->performRebuild();
    assert(_newWidget == nullptr);
}

template<typename T : RenderObject> RenderObjectWithChildMixin<T> RenderObjectToWidgetElementCls<T>::renderObject() {
    return ((RenderObjectWithChildMixin<T>)super->renderObject);
}

template<typename T : RenderObject> void RenderObjectToWidgetElementCls<T>::insertRenderObjectChild(RenderObject child, Object slot) {
    assert(slot == _rootChildSlot);
    assert(renderObject->debugValidateChild(child));
    renderObject->child = ((T)child);
}

template<typename T : RenderObject> void RenderObjectToWidgetElementCls<T>::moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot) {
    assert(false);
}

template<typename T : RenderObject> void RenderObjectToWidgetElementCls<T>::removeRenderObjectChild(RenderObject child, Object slot) {
    assert(renderObject->child == child);
    renderObject->child = nullptr;
}

template<typename T : RenderObject> void RenderObjectToWidgetElementCls<T>::_rebuild() {
    try {
        _child = updateChild(_child, (((RenderObjectToWidgetAdapter<T>)widget))->child, _rootChildSlot);
    } catch (Unknown exception) {
        FlutterErrorDetails details = make<FlutterErrorDetailsCls>(exception, stack, "widgets library", make<ErrorDescriptionCls>("attaching to the render tree"));
        FlutterErrorCls->reportError(details);
        Widget error = ErrorWidgetCls->builder(details);
        _child = updateChild(nullptr, error, _rootChildSlot);
    };
}

WidgetsBinding WidgetsFlutterBindingCls::ensureInitialized() {
    if (WidgetsBindingCls::_instance == nullptr) {
        make<WidgetsFlutterBindingCls>();
    }
    return WidgetsBindingCls::instance;
}
