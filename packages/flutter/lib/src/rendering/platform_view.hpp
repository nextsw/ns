#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_PLATFORM_VIEW
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_PLATFORM_VIEW
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
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
template<typename T>
 bool _factoryTypesSetEquals(Set<Factory<T>> a, Set<Factory<T>> b);

template<typename T>
 Set<Type> _factoriesTypeSet(Set<Factory<T>> factories);


class RenderAndroidViewCls : public PlatformViewRenderBoxCls {
public:

     RenderAndroidViewCls(Clip clipBehavior, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, AndroidViewController viewController);

    virtual AndroidViewController controller();

    virtual void  controller(AndroidViewController controller);

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual bool sizedByParent();

    virtual bool alwaysNeedsCompositing();

    virtual bool isRepaintBoundary();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performResize();

    virtual void paint(PaintingContext context, Offset offset);

    virtual void dispose();

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

private:
    _PlatformViewState _state;

    Size _currentTextureSize;

    bool _isDisposed;

    AndroidViewController _viewController;

    Clip _clipBehavior;

    LayerHandle<ClipRectLayer> _clipRectLayer;


    virtual void _onPlatformViewCreated(int id);

    virtual Future<void> _sizePlatformView();

    virtual void _setOffset();

    virtual void _paintTexture(PaintingContext context, Offset offset);

};
using RenderAndroidView = std::shared_ptr<RenderAndroidViewCls>;

class RenderUiKitViewCls : public RenderBoxCls {
public:
    PlatformViewHitTestBehavior hitTestBehavior;


     RenderUiKitViewCls(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, UiKitViewController viewController);

    virtual UiKitViewController viewController();

    virtual void  viewController(UiKitViewController viewController);

    virtual void updateGestureRecognizers(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers);

    virtual bool sizedByParent();

    virtual bool alwaysNeedsCompositing();

    virtual bool isRepaintBoundary();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void paint(PaintingContext context, Offset offset);

    virtual bool hitTest(Offset position, BoxHitTestResult result);

    virtual bool hitTestSelf(Offset position);

    virtual void handleEvent(HitTestEntry entry, PointerEvent event);

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

private:
    UiKitViewController _viewController;

    _UiKitViewGestureRecognizer _gestureRecognizer;

    PointerEvent _lastPointerDownEvent;


    virtual void _handleGlobalPointerEvent(PointerEvent event);

};
using RenderUiKitView = std::shared_ptr<RenderUiKitViewCls>;

class _UiKitViewGestureRecognizerCls : public OneSequenceGestureRecognizerCls {
public:
    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizerFactories;

    UiKitViewController controller;


    virtual void addAllowedPointer(PointerDownEvent event);

    virtual String debugDescription();

    virtual void didStopTrackingLastPointer(int pointer);

    virtual void handleEvent(PointerEvent event);

    virtual void acceptGesture(int pointer);

    virtual void rejectGesture(int pointer);

    virtual void reset();

private:
    Set<OneSequenceGestureRecognizer> _gestureRecognizers;


     _UiKitViewGestureRecognizerCls(UiKitViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizerFactories);

};
using _UiKitViewGestureRecognizer = std::shared_ptr<_UiKitViewGestureRecognizerCls>;

class _PlatformViewGestureRecognizerCls : public OneSequenceGestureRecognizerCls {
public:
    Map<int, List<PointerEvent>> cachedEvents;

    Set<int> forwardedPointers;

    Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizerFactories;


    virtual void addAllowedPointer(PointerDownEvent event);

    virtual String debugDescription();

    virtual void didStopTrackingLastPointer(int pointer);

    virtual void handleEvent(PointerEvent event);

    virtual void acceptGesture(int pointer);

    virtual void rejectGesture(int pointer);

    virtual void stopTrackingPointer(int pointer);

    virtual void reset();

private:
    _HandlePointerEvent _handlePointerEvent;

    Set<OneSequenceGestureRecognizer> _gestureRecognizers;


     _PlatformViewGestureRecognizerCls(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizerFactories, _HandlePointerEvent handlePointerEvent);

    virtual void _cacheEvent(PointerEvent event);

    virtual void _flushPointerCache(int pointer);

};
using _PlatformViewGestureRecognizer = std::shared_ptr<_PlatformViewGestureRecognizerCls>;

class PlatformViewRenderBoxCls : public RenderBoxCls {
public:

     PlatformViewRenderBoxCls(PlatformViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior);

    virtual PlatformViewController controller();

    virtual void  controller(PlatformViewController controller);

    virtual void updateGestureRecognizers(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers);

    virtual bool sizedByParent();

    virtual bool alwaysNeedsCompositing();

    virtual bool isRepaintBoundary();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

private:
    PlatformViewController _controller;


};
using PlatformViewRenderBox = std::shared_ptr<PlatformViewRenderBoxCls>;

class _PlatformViewGestureMixinCls : public ObjectCls {
public:

    virtual void  hitTestBehavior(PlatformViewHitTestBehavior value);

    virtual bool hitTest(Offset position, BoxHitTestResult result);

    virtual bool hitTestSelf(Offset position);

    virtual PointerEnterEventListener onEnter();

    virtual PointerExitEventListener onExit();

    virtual MouseCursor cursor();

    virtual bool validForMouseTracker();

    virtual void handleEvent(HitTestEntry entry, PointerEvent event);

    virtual void detach();

private:
    PlatformViewHitTestBehavior _hitTestBehavior;

    _HandlePointerEvent _handlePointerEvent;

    _PlatformViewGestureRecognizer _gestureRecognizer;


    virtual void _updateGestureRecognizersWithCallBack(Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, _HandlePointerEvent handlePointerEvent);

};
using _PlatformViewGestureMixin = std::shared_ptr<_PlatformViewGestureMixinCls>;


#endif