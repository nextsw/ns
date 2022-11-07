#ifndef BINDING_H
#define BINDING_H
#include <memory>
#include <ui.hpp>

#include <async/async.hpp>
#include <developer/developer.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/services.hpp>
#include "app.hpp"
#include "debug.hpp"
#include "focus_manager.hpp"
#include "framework.hpp"
#include "platform_menu_bar.hpp"
#include "router.hpp"
#include "widget_inspector.hpp"



class WidgetsBindingObserver {
public:

    Future<bool> didPopRoute();

    Future<bool> didPushRoute(String route);

    Future<bool> didPushRouteInformation(RouteInformation routeInformation);

    void didChangeMetrics();

    void didChangeTextScaleFactor();

    void didChangePlatformBrightness();

    void didChangeLocales(List<Locale> locales);

    void didChangeAppLifecycleState(AppLifecycleState state);

    void didHaveMemoryPressure();

    void didChangeAccessibilityFeatures();

private:

};

class WidgetsBinding {
public:
    PlatformMenuDelegate platformMenuDelegate;

    bool debugBuildingDirtyElements;


    void initInstances();

    static WidgetsBinding instance();

    void initServiceExtensions();

    BuildOwner buildOwner();

    FocusManager focusManager();

    void addObserver(WidgetsBindingObserver observer);

    bool removeObserver(WidgetsBindingObserver observer);

    void handleMetricsChanged();

    void handleTextScaleFactorChanged();

    void handlePlatformBrightnessChanged();

    void handleAccessibilityFeaturesChanged();

    void handleLocaleChanged();

    void dispatchLocalesChanged(List<Locale> locales);

    void dispatchAccessibilityFeaturesChanged();

    Future<void> handlePopRoute();

    Future<void> handlePushRoute(String route);

    void handleAppLifecycleStateChanged(AppLifecycleState state);

    void handleMemoryPressure();

    bool firstFrameRasterized();

    Future<void> waitUntilFirstFrameRasterized();

    bool debugDidSendFirstFrameEvent();

    void drawFrame();

    Element renderViewElement();

    bool framesEnabled();

    void scheduleAttachRootWidget(Widget rootWidget);

    void attachRootWidget(Widget rootWidget);

    bool isRootWidgetAttached();

    Future<void> performReassemble();

    Locale computePlatformResolvedLocale(List<Locale> supportedLocales);

private:
    static WidgetsBinding _instance;

    BuildOwner _buildOwner;

    List<WidgetsBindingObserver> _observers;

    bool _needToReportFirstFrame;

    Completer<void> _firstFrameCompleter;

    Element _renderViewElement;

    bool _readyToProduceFrames;


    void _debugAddStackFilters();

    Future<void> _forceRebuild();

    Future<void> _handlePushRouteInformation(Map<dynamic, dynamic> routeArguments);

    Future<dynamic> _handleNavigationInvocation(MethodCall methodCall);

    void _handleBuildScheduled();

};
void runApp(Widget app);

String _debugDumpAppString();

void debugDumpApp();


class RenderObjectToWidgetAdapter<T extends RenderObject> : RenderObjectWidget {
public:
    Widget child;

    RenderObjectWithChildMixin<T> container;

    String debugShortDescription;


     RenderObjectToWidgetAdapter(Widget child, RenderObjectWithChildMixin<T> container, String debugShortDescription);

    RenderObjectToWidgetElement<T> createElement();

    RenderObjectWithChildMixin<T> createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderObject renderObject);

    RenderObjectToWidgetElement<T> attachToRenderTree(RenderObjectToWidgetElement<T> element, BuildOwner owner);

    String toStringShort();

private:

};

class RenderObjectToWidgetElement<T extends RenderObject> : RootRenderObjectElement {
public:

     RenderObjectToWidgetElement(RenderObjectToWidgetAdapter<T> widget);

    void visitChildren(ElementVisitor visitor);

    void forgetChild(Element child);

    void mount(Object newSlot, Element parent);

    void update(RenderObjectToWidgetAdapter<T> newWidget);

    void performRebuild();

    RenderObjectWithChildMixin<T> renderObject();

    void insertRenderObjectChild(RenderObject child, Object slot);

    void moveRenderObjectChild(RenderObject child, Object newSlot, Object oldSlot);

    void removeRenderObjectChild(RenderObject child, Object slot);

private:
    Element _child;

    static const Object _rootChildSlot;

    Widget _newWidget;


    void _rebuild();

};

class WidgetsFlutterBinding : BindingBase {
public:

    static WidgetsBinding ensureInitialized();

private:

};

#endif