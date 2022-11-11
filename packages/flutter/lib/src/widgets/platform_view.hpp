#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PLATFORM_VIEW
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PLATFORM_VIEW
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"


class AndroidViewCls : public StatefulWidgetCls {
public:
    String viewType;

    PlatformViewCreatedCallback onPlatformViewCreated;

    PlatformViewHitTestBehavior hitTestBehavior;

    TextDirection layoutDirection;

    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers;

    dynamic creationParams;

    MessageCodec<dynamic> creationParamsCodec;

    Clip clipBehavior;


     AndroidViewCls(Clip clipBehavior, dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Key key, TextDirection layoutDirection, PlatformViewCreatedCallback onPlatformViewCreated, String viewType);

    virtual State<AndroidView> createState();

private:

};
using AndroidView = std::shared_ptr<AndroidViewCls>;

class UiKitViewCls : public StatefulWidgetCls {
public:
    String viewType;

    PlatformViewCreatedCallback onPlatformViewCreated;

    PlatformViewHitTestBehavior hitTestBehavior;

    TextDirection layoutDirection;

    dynamic creationParams;

    MessageCodec<dynamic> creationParamsCodec;

    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers;


     UiKitViewCls(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Key key, TextDirection layoutDirection, PlatformViewCreatedCallback onPlatformViewCreated, String viewType);

    virtual State<UiKitView> createState();

private:

};
using UiKitView = std::shared_ptr<UiKitViewCls>;

class HtmlElementViewCls : public StatelessWidgetCls {
public:
    String viewType;

    PlatformViewCreatedCallback onPlatformViewCreated;


     HtmlElementViewCls(Key key, PlatformViewCreatedCallback onPlatformViewCreated, String viewType);

    virtual Widget build(BuildContext context);

private:

    virtual _HtmlElementViewController _createHtmlElementView(PlatformViewCreationParams params);

};
using HtmlElementView = std::shared_ptr<HtmlElementViewCls>;

class _HtmlElementViewControllerCls : public PlatformViewControllerCls {
public:
    int viewId;

    String viewType;


    virtual Future<void> clearFocus();

    virtual Future<void> dispatchPointerEvent(PointerEvent event);

    virtual Future<void> dispose();

private:
    bool _initialized;


     _HtmlElementViewControllerCls(int viewId, String viewType);
    virtual Future<void> _initialize();

};
using _HtmlElementViewController = std::shared_ptr<_HtmlElementViewControllerCls>;

class _AndroidViewStateCls : public StateCls<AndroidView> {
public:

    virtual Widget build(BuildContext context);

    virtual void didChangeDependencies();

    virtual void didUpdateWidget(AndroidView oldWidget);

    virtual void dispose();

private:
    int _id;

    AndroidViewController _controller;

    TextDirection _layoutDirection;

    bool _initialized;

    FocusNode _focusNode;

    static Set<Factory<OneSequenceGestureRecognizer>> _emptyRecognizersSet;


    virtual void _initializeOnce();

    virtual TextDirection _findLayoutDirection();

    virtual void _createNewAndroidView();

    virtual void _onFocusChange(bool isFocused);

};
using _AndroidViewState = std::shared_ptr<_AndroidViewStateCls>;

class _UiKitViewStateCls : public StateCls<UiKitView> {
public:

    virtual Widget build(BuildContext context);

    virtual void didChangeDependencies();

    virtual void didUpdateWidget(UiKitView oldWidget);

    virtual void dispose();

private:
    UiKitViewController _controller;

    TextDirection _layoutDirection;

    bool _initialized;

    FocusNode _focusNode;

    static Set<Factory<OneSequenceGestureRecognizer>> _emptyRecognizersSet;


    virtual void _initializeOnce();

    virtual TextDirection _findLayoutDirection();

    virtual Future<void> _createNewUiKitView();

    virtual void _onFocusChange(bool isFocused, UiKitViewController controller);

};
using _UiKitViewState = std::shared_ptr<_UiKitViewStateCls>;

class _AndroidPlatformViewCls : public LeafRenderObjectWidgetCls {
public:
    AndroidViewController controller;

    PlatformViewHitTestBehavior hitTestBehavior;

    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers;

    Clip clipBehavior;


    virtual RenderObject createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderAndroidView renderObject);

private:

     _AndroidPlatformViewCls(Clip clipBehavior, AndroidViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior);

};
using _AndroidPlatformView = std::shared_ptr<_AndroidPlatformViewCls>;

class _UiKitPlatformViewCls : public LeafRenderObjectWidgetCls {
public:
    UiKitViewController controller;

    PlatformViewHitTestBehavior hitTestBehavior;

    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers;


    virtual RenderObject createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderUiKitView renderObject);

private:

     _UiKitPlatformViewCls(UiKitViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior);

};
using _UiKitPlatformView = std::shared_ptr<_UiKitPlatformViewCls>;

class PlatformViewCreationParamsCls : public ObjectCls {
public:
    int id;

    String viewType;

    PlatformViewCreatedCallback onPlatformViewCreated;

    ValueChanged<bool> onFocusChanged;


private:

    virtual void  _(int id, ValueChanged<bool> onFocusChanged, PlatformViewCreatedCallback onPlatformViewCreated, String viewType);

};
using PlatformViewCreationParams = std::shared_ptr<PlatformViewCreationParamsCls>;

class PlatformViewLinkCls : public StatefulWidgetCls {
public:
    String viewType;


     PlatformViewLinkCls(Key key, CreatePlatformViewCallback onCreatePlatformView, PlatformViewSurfaceFactory surfaceFactory, String viewType);

    virtual State<StatefulWidget> createState();

private:
    PlatformViewSurfaceFactory _surfaceFactory;

    CreatePlatformViewCallback _onCreatePlatformView;


};
using PlatformViewLink = std::shared_ptr<PlatformViewLinkCls>;

class _PlatformViewLinkStateCls : public StateCls<PlatformViewLink> {
public:

    virtual Widget build(BuildContext context);

    virtual void initState();

    virtual void didUpdateWidget(PlatformViewLink oldWidget);

    virtual void dispose();

private:
    int _id;

    PlatformViewController _controller;

    bool _platformViewCreated;

    Widget _surface;

    FocusNode _focusNode;


    virtual void _initialize();

    virtual void _onPlatformViewCreated(int id);

    virtual void _handleFrameworkFocusChanged(bool isFocused);

    virtual void _handlePlatformFocusChanged(bool isFocused);

};
using _PlatformViewLinkState = std::shared_ptr<_PlatformViewLinkStateCls>;

class PlatformViewSurfaceCls : public LeafRenderObjectWidgetCls {
public:
    PlatformViewController controller;

    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers;

    PlatformViewHitTestBehavior hitTestBehavior;


     PlatformViewSurfaceCls(PlatformViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Key key);

    virtual RenderObject createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, PlatformViewRenderBox renderObject);

private:

};
using PlatformViewSurface = std::shared_ptr<PlatformViewSurfaceCls>;

class AndroidViewSurfaceCls : public PlatformViewSurfaceCls {
public:

     AndroidViewSurfaceCls(AndroidViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Key key);

    virtual RenderObject createRenderObject(BuildContext context);

private:

};
using AndroidViewSurface = std::shared_ptr<AndroidViewSurfaceCls>;

class _PlatformViewPlaceholderBoxCls : public RenderConstrainedBoxCls {
public:
    _OnLayoutCallback onLayout;


    virtual void performLayout();

private:

     _PlatformViewPlaceholderBoxCls(_OnLayoutCallback onLayout);

};
using _PlatformViewPlaceholderBox = std::shared_ptr<_PlatformViewPlaceholderBoxCls>;

class _PlatformViewPlaceHolderCls : public SingleChildRenderObjectWidgetCls {
public:
    _OnLayoutCallback onLayout;


    virtual _PlatformViewPlaceholderBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, _PlatformViewPlaceholderBox renderObject);

private:

     _PlatformViewPlaceHolderCls(_OnLayoutCallback onLayout);
};
using _PlatformViewPlaceHolder = std::shared_ptr<_PlatformViewPlaceHolderCls>;


#endif