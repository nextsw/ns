#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_BINDING
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_BINDING
#include <base.hpp>
#include <dart/ui/ui.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/developer/developer.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "app.hpp"
#include "debug.hpp"
#include "focus_manager.hpp"
#include "framework.hpp"
#include "platform_menu_bar.hpp"
#include "router.hpp"
#include "widget_inspector.hpp"


class WidgetsBindingObserverCls : public ObjectCls {
public:

    virtual Future<bool> didPopRoute();

    virtual Future<bool> didPushRoute(String route);

    virtual Future<bool> didPushRouteInformation(RouteInformation routeInformation);

    virtual void didChangeMetrics();

    virtual void didChangeTextScaleFactor();

    virtual void didChangePlatformBrightness();

    virtual void didChangeLocales(List<Locale> locales);

    virtual void didChangeAppLifecycleState(AppLifecycleState state);

    virtual void didHaveMemoryPressure();

    virtual void didChangeAccessibilityFeatures();

private:

};
using WidgetsBindingObserver = std::shared_ptr<WidgetsBindingObserverCls>;

class WidgetsBindingCls : public ObjectCls {
public:
    PlatformMenuDelegate platformMenuDelegate;

    bool debugBuildingDirtyElements;


    virtual void initInstances();

    static WidgetsBinding instance();

    virtual void initServiceExtensions();

    virtual BuildOwner buildOwner();

    virtual FocusManager focusManager();

    virtual void addObserver(WidgetsBindingObserver observer);

    virtual bool removeObserver(WidgetsBindingObserver observer);

    virtual void handleMetricsChanged();

    virtual void handleTextScaleFactorChanged();

    virtual void handlePlatformBrightnessChanged();

    virtual void handleAccessibilityFeaturesChanged();

    virtual void handleLocaleChanged();

    virtual void dispatchLocalesChanged(List<Locale> locales);

    virtual void dispatchAccessibilityFeaturesChanged();

    virtual Future<void> handlePopRoute();

    virtual Future<void> handlePushRoute(String route);

    virtual void handleAppLifecycleStateChanged(AppLifecycleState state);

    virtual void handleMemoryPressure();

    virtual bool firstFrameRasterized();

    virtual Future<void> waitUntilFirstFrameRasterized();

    virtual bool debugDidSendFirstFrameEvent();

    virtual void drawFrame();

    virtual Element renderViewElement();

    virtual bool framesEnabled();

    virtual void scheduleAttachRootWidget(Widget rootWidget);

    virtual void attachRootWidget(Widget rootWidget);

    virtual bool isRootWidgetAttached();

    virtual Future<void> performReassemble();

    virtual Locale computePlatformResolvedLocale(List<Locale> supportedLocales);

private:
    static WidgetsBinding _instance;

    BuildOwner _buildOwner;

    List<WidgetsBindingObserver> _observers;

    bool _needToReportFirstFrame;

    Completer<void> _firstFrameCompleter;

    Element _renderViewElement;

    bool _readyToProduceFrames;


    virtual void _debugAddStackFilters();

    virtual Future<void> _forceRebuild();

    virtual Future<void> _handlePushRouteInformation(Map<Object, Object> routeArguments);

    virtual Future<Object> _handleNavigationInvocation(MethodCall methodCall);

    virtual void _handleBuildScheduled();

};
using WidgetsBinding = std::shared_ptr<WidgetsBindingCls>;
void runApp(Widget app);

String _debugDumpAppString();

void debugDumpApp();


template<typename T>
class RenderObjectToWidgetAdapterCls : public RenderObjectWidgetCls {
public:
    Widget child;

    RenderObjectWithChildMixin<T> container;

    String debugShortDescription;


     RenderObjectToWidgetAdapterCls(Widget child, RenderObjectWithChildMixin<T> container, String debugShortDescription);

    virtual RenderObjectToWidgetElement<T> createElement();

    virtual RenderObjectWithChildMixin<T> createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderObject renderObject);

    virtual RenderObjectToWidgetElement<T> attachToRenderTree(BuildOwner owner, RenderObjectToWidgetElement<T> element);

    virtual String toStringShort();

private:

};
template<typename T>
using RenderObjectToWidgetAdapter = std::shared_ptr<RenderObjectToWidgetAdapterCls<T>>;

template<typename T>
class RenderObjectToWidgetElementCls : public RootRenderObjectElementCls {
public:

     RenderObjectToWidgetElementCls(Unknown widget);
    virtual void visitChildren(ElementVisitor visitor);

    virtual void forgetChild(Element child);

    virtual void mount(Element parent, Object newSlot);

    virtual void update(RenderObjectToWidgetAdapter<T> newWidget);

    virtual void performRebuild();

    virtual RenderObjectWithChildMixin<T> renderObject();

    virtual void insertRenderObjectChild(RenderObject child, Object slot);

    virtual void moveRenderObjectChild(RenderObject child, Object oldSlot, Object newSlot);

    virtual void removeRenderObjectChild(RenderObject child, Object slot);

private:
    Element _child;

    static Object _rootChildSlot;

    Widget _newWidget;


    virtual void _rebuild();

};
template<typename T>
using RenderObjectToWidgetElement = std::shared_ptr<RenderObjectToWidgetElementCls<T>>;

class WidgetsFlutterBindingCls : public BindingBaseCls {
public:

    static WidgetsBinding ensureInitialized();

private:

};
using WidgetsFlutterBinding = std::shared_ptr<WidgetsFlutterBindingCls>;


#endif