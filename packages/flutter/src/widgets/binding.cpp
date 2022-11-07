#include "binding.hpp"
Future<bool> WidgetsBindingObserver::didPopRoute() {
    return <bool>value(false);
}

Future<bool> WidgetsBindingObserver::didPushRoute(String route) {
    return <bool>value(false);
}

Future<bool> WidgetsBindingObserver::didPushRouteInformation(RouteInformation routeInformation) {
    return didPushRoute(routeInformation.location!);
}

void WidgetsBindingObserver::didChangeMetrics() {
}

void WidgetsBindingObserver::didChangeTextScaleFactor() {
}

void WidgetsBindingObserver::didChangePlatformBrightness() {
}

void WidgetsBindingObserver::didChangeLocales(List<Locale> locales) {
}

void WidgetsBindingObserver::didChangeAppLifecycleState(AppLifecycleState state) {
}

void WidgetsBindingObserver::didHaveMemoryPressure() {
}

void WidgetsBindingObserver::didChangeAccessibilityFeatures() {
}

void WidgetsBinding::initInstances() {
    super.initInstances();
    _instance = this;
    assert(());
    _buildOwner = BuildOwner();
    buildOwner!.onBuildScheduled = _handleBuildScheduled;
    platformDispatcher.onLocaleChanged = handleLocaleChanged;
    platformDispatcher.onAccessibilityFeaturesChanged = handleAccessibilityFeaturesChanged;
    SystemChannels.navigation.setMethodCallHandler(_handleNavigationInvocation);
    assert(());
    platformMenuDelegate = DefaultPlatformMenuDelegate();
}

WidgetsBinding WidgetsBinding::instance() {
    return BindingBase.checkInstance(_instance);
}

void WidgetsBinding::initServiceExtensions() {
    super.initServiceExtensions();
    if (!kReleaseMode) {
        registerServiceExtension("debugDumpApp", );
        if (!kIsWeb) {
            registerBoolServiceExtension("showPerformanceOverlay", , );
        }
        registerServiceExtension("didSendFirstFrameEvent", );
        registerServiceExtension("didSendFirstFrameRasterizedEvent", );
        registerServiceExtension("fastReassemble", );
        registerBoolServiceExtension("profileWidgetBuilds", , );
        registerBoolServiceExtension("profileUserWidgetBuilds", , );
    }
    assert(());
}

BuildOwner WidgetsBinding::buildOwner() {
    return _buildOwner;
}

FocusManager WidgetsBinding::focusManager() {
    return _buildOwner!.focusManager;
}

void WidgetsBinding::addObserver(WidgetsBindingObserver observer) {
    return _observers.add(observer);
}

bool WidgetsBinding::removeObserver(WidgetsBindingObserver observer) {
    return _observers.remove(observer);
}

void WidgetsBinding::handleMetricsChanged() {
    super.handleMetricsChanged();
    for (WidgetsBindingObserver observer : _observers) {
        observer.didChangeMetrics();
    }
}

void WidgetsBinding::handleTextScaleFactorChanged() {
    super.handleTextScaleFactorChanged();
    for (WidgetsBindingObserver observer : _observers) {
        observer.didChangeTextScaleFactor();
    }
}

void WidgetsBinding::handlePlatformBrightnessChanged() {
    super.handlePlatformBrightnessChanged();
    for (WidgetsBindingObserver observer : _observers) {
        observer.didChangePlatformBrightness();
    }
}

void WidgetsBinding::handleAccessibilityFeaturesChanged() {
    super.handleAccessibilityFeaturesChanged();
    for (WidgetsBindingObserver observer : _observers) {
        observer.didChangeAccessibilityFeatures();
    }
}

void WidgetsBinding::handleLocaleChanged() {
    dispatchLocalesChanged(platformDispatcher.locales);
}

void WidgetsBinding::dispatchLocalesChanged(List<Locale> locales) {
    for (WidgetsBindingObserver observer : _observers) {
        observer.didChangeLocales(locales);
    }
}

void WidgetsBinding::dispatchAccessibilityFeaturesChanged() {
    for (WidgetsBindingObserver observer : _observers) {
        observer.didChangeAccessibilityFeatures();
    }
}

Future<void> WidgetsBinding::handlePopRoute() {
    for (WidgetsBindingObserver observer : <WidgetsBindingObserver>of(_observers)) {
        if (await observer.didPopRoute()) {
            return;
        }
    }
    SystemNavigator.pop();
}

Future<void> WidgetsBinding::handlePushRoute(String route) {
    for (WidgetsBindingObserver observer : <WidgetsBindingObserver>of(_observers)) {
        if (await observer.didPushRoute(route)) {
            return;
        }
    }
}

void WidgetsBinding::handleAppLifecycleStateChanged(AppLifecycleState state) {
    super.handleAppLifecycleStateChanged(state);
    for (WidgetsBindingObserver observer : _observers) {
        observer.didChangeAppLifecycleState(state);
    }
}

void WidgetsBinding::handleMemoryPressure() {
    super.handleMemoryPressure();
    for (WidgetsBindingObserver observer : _observers) {
        observer.didHaveMemoryPressure();
    }
}

bool WidgetsBinding::firstFrameRasterized() {
    return _firstFrameCompleter.isCompleted;
}

Future<void> WidgetsBinding::waitUntilFirstFrameRasterized() {
    return _firstFrameCompleter.future;
}

bool WidgetsBinding::debugDidSendFirstFrameEvent() {
    return !_needToReportFirstFrame;
}

void WidgetsBinding::drawFrame() {
    assert(!debugBuildingDirtyElements);
    assert(());
    TimingsCallback firstFrameCallback;
    if (_needToReportFirstFrame) {
        assert(!_firstFrameCompleter.isCompleted);
        firstFrameCallback = ;
        SchedulerBinding.instance.addTimingsCallback(firstFrameCallback!);
    }
    ;
    if (!kReleaseMode) {
        if (_needToReportFirstFrame && sendFramesToEngine) {
            developer.Timeline.instantSync("Widgets built first useful frame");
        }
    }
    _needToReportFirstFrame = false;
    if (firstFrameCallback != nullptr && !sendFramesToEngine) {
        _needToReportFirstFrame = true;
        SchedulerBinding.instance.removeTimingsCallback(firstFrameCallback!);
    }
}

Element WidgetsBinding::renderViewElement() {
    return _renderViewElement;
}

bool WidgetsBinding::framesEnabled() {
    return super.framesEnabled && _readyToProduceFrames;
}

void WidgetsBinding::scheduleAttachRootWidget(Widget rootWidget) {
    Timer.run();
}

void WidgetsBinding::attachRootWidget(Widget rootWidget) {
    bool isBootstrapFrame = renderViewElement == nullptr;
    _readyToProduceFrames = true;
    _renderViewElement = <RenderBox>RenderObjectToWidgetAdapter(renderView, "[root]", rootWidget).attachToRenderTree(buildOwner!, ();
    if (isBootstrapFrame) {
        SchedulerBinding.instance.ensureVisualUpdate();
    }
}

bool WidgetsBinding::isRootWidgetAttached() {
    return _renderViewElement != nullptr;
}

Future<void> WidgetsBinding::performReassemble() {
    assert(());
    if (renderViewElement != nullptr) {
        buildOwner!.reassemble(renderViewElement!, BindingBase.debugReassembleConfig);
    }
    return super.performReassemble();
}

Locale WidgetsBinding::computePlatformResolvedLocale(List<Locale> supportedLocales) {
    return platformDispatcher.computePlatformResolvedLocale(supportedLocales);
}

void WidgetsBinding::_debugAddStackFilters() {
    PartialStackFrame elementInflateWidget = PartialStackFrame("package:flutter/src/widgets/framework.dart", "Element", "inflateWidget");
    PartialStackFrame elementUpdateChild = PartialStackFrame("package:flutter/src/widgets/framework.dart", "Element", "updateChild");
    PartialStackFrame elementRebuild = PartialStackFrame("package:flutter/src/widgets/framework.dart", "Element", "rebuild");
    PartialStackFrame componentElementPerformRebuild = PartialStackFrame("package:flutter/src/widgets/framework.dart", "ComponentElement", "performRebuild");
    PartialStackFrame componentElementFirstBuild = PartialStackFrame("package:flutter/src/widgets/framework.dart", "ComponentElement", "_firstBuild");
    PartialStackFrame componentElementMount = PartialStackFrame("package:flutter/src/widgets/framework.dart", "ComponentElement", "mount");
    PartialStackFrame statefulElementFirstBuild = PartialStackFrame("package:flutter/src/widgets/framework.dart", "StatefulElement", "_firstBuild");
    PartialStackFrame singleChildMount = PartialStackFrame("package:flutter/src/widgets/framework.dart", "SingleChildRenderObjectElement", "mount");
    PartialStackFrame statefulElementRebuild = PartialStackFrame("package:flutter/src/widgets/framework.dart", "StatefulElement", "performRebuild");
    String replacementString = "...     Normal element mounting";
    FlutterError.addDefaultStackFilter(const RepetitiveStackFrameFilter(, replacementString));
    FlutterError.addDefaultStackFilter(const RepetitiveStackFrameFilter(, replacementString));
    FlutterError.addDefaultStackFilter(const RepetitiveStackFrameFilter(, replacementString));
    FlutterError.addDefaultStackFilter(const RepetitiveStackFrameFilter(, replacementString));
    FlutterError.addDefaultStackFilter(const RepetitiveStackFrameFilter(, replacementString));
    FlutterError.addDefaultStackFilter(const RepetitiveStackFrameFilter(, replacementString));
}

Future<void> WidgetsBinding::_forceRebuild() {
    if (renderViewElement != nullptr) {
        buildOwner!.reassemble(renderViewElement!, nullptr);
        return endOfFrame;
    }
    return <void>value();
}

Future<void> WidgetsBinding::_handlePushRouteInformation(Map<dynamic, dynamic> routeArguments) {
    for (WidgetsBindingObserver observer : <WidgetsBindingObserver>of(_observers)) {
        if (await observer.didPushRouteInformation(RouteInformation((, ())) {
            return;
        }
    }
}

Future<dynamic> WidgetsBinding::_handleNavigationInvocation(MethodCall methodCall) {
    ;
    return <dynamic>value();
}

void WidgetsBinding::_handleBuildScheduled() {
    assert(());
    ensureVisualUpdate();
}

void runApp(Widget app) {
    ;
}

String _debugDumpAppString() {
    String mode = kDebugMode? "DEBUG MODE" : kReleaseMode? "RELEASE MODE" : "PROFILE MODE";
    StringBuffer buffer = StringBuffer();
    buffer.writeln("${WidgetsBinding.instance.runtimeType} - $mode");
    if (WidgetsBinding.instance.renderViewElement != nullptr) {
        buffer.writeln(WidgetsBinding.instance.renderViewElement!.toStringDeep());
    } else {
        buffer.writeln("<no tree currently mounted>");
    }
    return buffer.toString();
}

void debugDumpApp() {
    debugPrint(_debugDumpAppString());
}

RenderObjectToWidgetAdapter::RenderObjectToWidgetAdapter(Widget child, RenderObjectWithChildMixin<T> container, String debugShortDescription) {
    {
        super(GlobalObjectKey(container));
    }
}

RenderObjectToWidgetElement<T> RenderObjectToWidgetAdapter::createElement() {
    return <T>RenderObjectToWidgetElement(this);
}

RenderObjectWithChildMixin<T> RenderObjectToWidgetAdapter::createRenderObject(BuildContext context) {
    return container;
}

void RenderObjectToWidgetAdapter::updateRenderObject(BuildContext context, RenderObject renderObject) {
}

RenderObjectToWidgetElement<T> RenderObjectToWidgetAdapter::attachToRenderTree(RenderObjectToWidgetElement<T> element, BuildOwner owner) {
    if (element == nullptr) {
        owner.lockState();
        owner.buildScope(element!, );
    } else {
        element._newWidget = this;
        element.markNeedsBuild();
    }
    return element!;
}

String RenderObjectToWidgetAdapter::toStringShort() {
    return debugShortDescription ?? super.toStringShort();
}

void RenderObjectToWidgetElement::visitChildren(ElementVisitor visitor) {
    if (_child != nullptr) {
        visitor(_child!);
    }
}

void RenderObjectToWidgetElement::forgetChild(Element child) {
    assert(child == _child);
    _child = nullptr;
    super.forgetChild(child);
}

void RenderObjectToWidgetElement::mount(Object newSlot, Element parent) {
    assert(parent == nullptr);
    super.mount(parent, newSlot);
    _rebuild();
    assert(_child != nullptr);
}

void RenderObjectToWidgetElement::update(RenderObjectToWidgetAdapter<T> newWidget) {
    super.update(newWidget);
    assert(widget == newWidget);
    _rebuild();
}

void RenderObjectToWidgetElement::performRebuild() {
    if (_newWidget != nullptr) {
        Widget newWidget = _newWidget!;
        _newWidget = nullptr;
        update(();
    }
    super.performRebuild();
    assert(_newWidget == nullptr);
}

RenderObjectWithChildMixin<T> RenderObjectToWidgetElement::renderObject() {
    return (;
}

void RenderObjectToWidgetElement::insertRenderObjectChild(RenderObject child, Object slot) {
    assert(slot == _rootChildSlot);
    assert(renderObject.debugValidateChild(child));
    renderObject.child = (;
}

void RenderObjectToWidgetElement::moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot) {
    assert(false);
}

void RenderObjectToWidgetElement::removeRenderObjectChild(RenderObject child, Object slot) {
    assert(renderObject.child == child);
    renderObject.child = nullptr;
}

void RenderObjectToWidgetElement::_rebuild() {
    ;
}

WidgetsBinding WidgetsFlutterBinding::ensureInitialized() {
    if (WidgetsBinding._instance == nullptr) {
        WidgetsFlutterBinding();
    }
    return WidgetsBinding.instance;
}
