#ifndef PLATFORM_VIEW_H
#define PLATFORM_VIEW_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/semantics.hpp>
#include <flutter/services.hpp>
#include "box.hpp"
#include "layer.hpp"
#include "object.hpp"



enum PlatformViewHitTestBehavior{
    opaque,
    translucent,
    transparent,
} // end PlatformViewHitTestBehavior

enum _PlatformViewState{
    uninitialized,
    resizing,
    ready,
} // end _PlatformViewState
bool _factoryTypesSetEquals<T>(Set<Factory<T>> a, Set<Factory<T>> b);

Set<Type> _factoriesTypeSet<T>(Set<Factory<T>> factories);


class RenderAndroidView : PlatformViewRenderBox {
public:

     RenderAndroidView(Clip clipBehavior, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, AndroidViewController viewController);

    AndroidViewController controller();

    void  controller(AndroidViewController controller);

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    bool sizedByParent();

    bool alwaysNeedsCompositing();

    bool isRepaintBoundary();

    Size computeDryLayout(BoxConstraints constraints);

    void performResize();

    void paint(PaintingContext context, Offset offset);

    void dispose();

    void describeSemanticsConfiguration(SemanticsConfiguration config);

private:
    _PlatformViewState _state;

    Size _currentTextureSize;

    bool _isDisposed;

    AndroidViewController _viewController;

    Clip _clipBehavior;

    LayerHandle<ClipRectLayer> _clipRectLayer;


    void _onPlatformViewCreated(int id);

    Future<void> _sizePlatformView();

    void _setOffset();

    void _paintTexture(PaintingContext context, Offset offset);

};

class RenderUiKitView : RenderBox {
public:
    PlatformViewHitTestBehavior hitTestBehavior;


     RenderUiKitView(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, UiKitViewController viewController);

    UiKitViewController viewController();

    void  viewController(UiKitViewController viewController);

    void updateGestureRecognizers(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers);

    bool sizedByParent();

    bool alwaysNeedsCompositing();

    bool isRepaintBoundary();

    Size computeDryLayout(BoxConstraints constraints);

    void paint(PaintingContext context, Offset offset);

    bool hitTest(Offset position, BoxHitTestResult result);

    bool hitTestSelf(Offset position);

    void handleEvent(HitTestEntry entry, PointerEvent event);

    void describeSemanticsConfiguration(SemanticsConfiguration config);

    void attach(PipelineOwner owner);

    void detach();

private:
    UiKitViewController _viewController;

    _UiKitViewGestureRecognizer _gestureRecognizer;

    PointerEvent _lastPointerDownEvent;


    void _handleGlobalPointerEvent(PointerEvent event);

};

class _UiKitViewGestureRecognizer : OneSequenceGestureRecognizer {
public:
    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizerFactories;

    UiKitViewController controller;


    void addAllowedPointer(PointerDownEvent event);

    String debugDescription();

    void didStopTrackingLastPointer(int pointer);

    void handleEvent(PointerEvent event);

    void acceptGesture(int pointer);

    void rejectGesture(int pointer);

    void reset();

private:
    Set<OneSequenceGestureRecognizer> _gestureRecognizers;


     _UiKitViewGestureRecognizer(UiKitViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizerFactories);

};

class _PlatformViewGestureRecognizer : OneSequenceGestureRecognizer {
public:
    Map<int, List<PointerEvent>> cachedEvents;

    Set<int> forwardedPointers;

    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizerFactories;


    void addAllowedPointer(PointerDownEvent event);

    String debugDescription();

    void didStopTrackingLastPointer(int pointer);

    void handleEvent(PointerEvent event);

    void acceptGesture(int pointer);

    void rejectGesture(int pointer);

    void stopTrackingPointer(int pointer);

    void reset();

private:
    _HandlePointerEvent _handlePointerEvent;

    Set<OneSequenceGestureRecognizer> _gestureRecognizers;


     _PlatformViewGestureRecognizer(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizerFactories, _HandlePointerEvent handlePointerEvent);

    void _cacheEvent(PointerEvent event);

    void _flushPointerCache(int pointer);

};

class PlatformViewRenderBox : RenderBox {
public:

     PlatformViewRenderBox(PlatformViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior);

    PlatformViewController controller();

    void  controller(PlatformViewController controller);

    void updateGestureRecognizers(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers);

    bool sizedByParent();

    bool alwaysNeedsCompositing();

    bool isRepaintBoundary();

    Size computeDryLayout(BoxConstraints constraints);

    void paint(PaintingContext context, Offset offset);

    void describeSemanticsConfiguration(SemanticsConfiguration config);

private:
    PlatformViewController _controller;


};

class _PlatformViewGestureMixin {
public:

    void  hitTestBehavior(PlatformViewHitTestBehavior value);

    bool hitTest(Offset position, BoxHitTestResult result);

    bool hitTestSelf(Offset position);

    PointerEnterEventListener onEnter();

    PointerExitEventListener onExit();

    MouseCursor cursor();

    bool validForMouseTracker();

    void handleEvent(HitTestEntry entry, PointerEvent event);

    void detach();

private:
    PlatformViewHitTestBehavior _hitTestBehavior;

    _HandlePointerEvent _handlePointerEvent;

    _PlatformViewGestureRecognizer _gestureRecognizer;


    void _updateGestureRecognizersWithCallBack(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, _HandlePointerEvent handlePointerEvent);

};

#endif