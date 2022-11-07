#ifndef PLATFORM_VIEW_H
#define PLATFORM_VIEW_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include <flutter/services.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"



class AndroidView : StatefulWidget {
public:
    String viewType;

    PlatformViewCreatedCallback onPlatformViewCreated;

    PlatformViewHitTestBehavior hitTestBehavior;

    TextDirection layoutDirection;

    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers;

    dynamic creationParams;

    MessageCodec<dynamic> creationParamsCodec;

    Clip clipBehavior;


     AndroidView(Clip clipBehavior, dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Unknown, TextDirection layoutDirection, PlatformViewCreatedCallback onPlatformViewCreated, String viewType);

    State<AndroidView> createState();

private:

};

class UiKitView : StatefulWidget {
public:
    String viewType;

    PlatformViewCreatedCallback onPlatformViewCreated;

    PlatformViewHitTestBehavior hitTestBehavior;

    TextDirection layoutDirection;

    dynamic creationParams;

    MessageCodec<dynamic> creationParamsCodec;

    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers;


     UiKitView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Unknown, TextDirection layoutDirection, PlatformViewCreatedCallback onPlatformViewCreated, String viewType);

    State<UiKitView> createState();

private:

};

class HtmlElementView : StatelessWidget {
public:
    String viewType;

    PlatformViewCreatedCallback onPlatformViewCreated;


     HtmlElementView(Unknown, PlatformViewCreatedCallback onPlatformViewCreated, String viewType);

    Widget build(BuildContext context);

private:

    _HtmlElementViewController _createHtmlElementView(PlatformViewCreationParams params);

};

class _HtmlElementViewController : PlatformViewController {
public:
    int viewId;

    String viewType;


    Future<void> clearFocus();

    Future<void> dispatchPointerEvent(PointerEvent event);

    Future<void> dispose();

private:
    bool _initialized;


     _HtmlElementViewController(int viewId, String viewType);

    Future<void> _initialize();

};

class _AndroidViewState : State<AndroidView> {
public:

    Widget build(BuildContext context);

    void didChangeDependencies();

    void didUpdateWidget(AndroidView oldWidget);

    void dispose();

private:
    int _id;

    AndroidViewController _controller;

    TextDirection _layoutDirection;

    bool _initialized;

    FocusNode _focusNode;

    static Set<Factory<OneSequenceGestureRecognizer>> _emptyRecognizersSet;


    void _initializeOnce();

    TextDirection _findLayoutDirection();

    void _createNewAndroidView();

    void _onFocusChange(bool isFocused);

};

class _UiKitViewState : State<UiKitView> {
public:

    Widget build(BuildContext context);

    void didChangeDependencies();

    void didUpdateWidget(UiKitView oldWidget);

    void dispose();

private:
    UiKitViewController _controller;

    TextDirection _layoutDirection;

    bool _initialized;

    FocusNode _focusNode;

    static Set<Factory<OneSequenceGestureRecognizer>> _emptyRecognizersSet;


    void _initializeOnce();

    TextDirection _findLayoutDirection();

    Future<void> _createNewUiKitView();

    void _onFocusChange(UiKitViewController controller, bool isFocused);

};

class _AndroidPlatformView : LeafRenderObjectWidget {
public:
    AndroidViewController controller;

    PlatformViewHitTestBehavior hitTestBehavior;

    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers;

    Clip clipBehavior;


    RenderObject createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderAndroidView renderObject);

private:

     _AndroidPlatformView(Clip clipBehavior, AndroidViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior);

};

class _UiKitPlatformView : LeafRenderObjectWidget {
public:
    UiKitViewController controller;

    PlatformViewHitTestBehavior hitTestBehavior;

    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers;


    RenderObject createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderUiKitView renderObject);

private:

     _UiKitPlatformView(UiKitViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior);

};

class PlatformViewCreationParams {
public:
    int id;

    String viewType;

    PlatformViewCreatedCallback onPlatformViewCreated;

    ValueChanged<bool> onFocusChanged;


private:

    void  _(int id, ValueChanged<bool> onFocusChanged, PlatformViewCreatedCallback onPlatformViewCreated, String viewType);

};

class PlatformViewLink : StatefulWidget {
public:
    String viewType;


     PlatformViewLink(Unknown, CreatePlatformViewCallback onCreatePlatformView, PlatformViewSurfaceFactory surfaceFactory, String viewType);

    State<StatefulWidget> createState();

private:
    PlatformViewSurfaceFactory _surfaceFactory;

    CreatePlatformViewCallback _onCreatePlatformView;


};

class _PlatformViewLinkState : State<PlatformViewLink> {
public:

    Widget build(BuildContext context);

    void initState();

    void didUpdateWidget(PlatformViewLink oldWidget);

    void dispose();

private:
    int _id;

    PlatformViewController _controller;

    bool _platformViewCreated;

    Widget _surface;

    FocusNode _focusNode;


    void _initialize();

    void _onPlatformViewCreated(int id);

    void _handleFrameworkFocusChanged(bool isFocused);

    void _handlePlatformFocusChanged(bool isFocused);

};

class PlatformViewSurface : LeafRenderObjectWidget {
public:
    PlatformViewController controller;

    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers;

    PlatformViewHitTestBehavior hitTestBehavior;


     PlatformViewSurface(PlatformViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Unknown);

    RenderObject createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, PlatformViewRenderBox renderObject);

private:

};

class AndroidViewSurface : PlatformViewSurface {
public:

     AndroidViewSurface(AndroidViewController controller, Unknown, Unknown, Unknown);

    RenderObject createRenderObject(BuildContext context);

private:

};

class _PlatformViewPlaceholderBox : RenderConstrainedBox {
public:
    _OnLayoutCallback onLayout;


    void performLayout();

private:

     _PlatformViewPlaceholderBox(_OnLayoutCallback onLayout);

};

class _PlatformViewPlaceHolder : SingleChildRenderObjectWidget {
public:
    _OnLayoutCallback onLayout;


    _PlatformViewPlaceholderBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, _PlatformViewPlaceholderBox renderObject);

private:

     _PlatformViewPlaceHolder(_OnLayoutCallback onLayout);

};

#endif