#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_MODAL_BARRIER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_MODAL_BARRIER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"
#include "navigator.hpp"
#include "transitions.hpp"


class ModalBarrierCls : public StatelessWidgetCls {
public:
    Color color;

    bool dismissible;

    VoidCallback onDismiss;

    bool barrierSemanticsDismissible;

    String semanticsLabel;


     ModalBarrierCls(bool barrierSemanticsDismissible, Color color, bool dismissible, Key key, VoidCallback onDismiss, String semanticsLabel);
    virtual Widget build(BuildContext context);

private:

};
using ModalBarrier = std::shared_ptr<ModalBarrierCls>;

class AnimatedModalBarrierCls : public AnimatedWidgetCls {
public:
    bool dismissible;

    String semanticsLabel;

    bool barrierSemanticsDismissible;

    VoidCallback onDismiss;


     AnimatedModalBarrierCls(bool barrierSemanticsDismissible, Animation<Color> color, bool dismissible, Key key, VoidCallback onDismiss, String semanticsLabel);

    virtual Animation<Color> color();

    virtual Widget build(BuildContext context);

private:

};
using AnimatedModalBarrier = std::shared_ptr<AnimatedModalBarrierCls>;

class _AnyTapGestureRecognizerCls : public BaseTapGestureRecognizerCls {
public:
    VoidCallback onAnyTapUp;


    virtual bool isPointerAllowed(PointerDownEvent event);

    virtual void handleTapDown(PointerDownEvent down);

    virtual void handleTapUp(PointerDownEvent down, PointerUpEvent up);

    virtual void handleTapCancel(PointerCancelEvent cancel, PointerDownEvent down, String reason);

    virtual String debugDescription();

private:

     _AnyTapGestureRecognizerCls();
};
using _AnyTapGestureRecognizer = std::shared_ptr<_AnyTapGestureRecognizerCls>;

class _ModalBarrierSemanticsDelegateCls : public SemanticsGestureDelegateCls {
public:
    VoidCallback onDismiss;


    virtual void assignSemantics(RenderSemanticsGestureHandler renderObject);

private:

     _ModalBarrierSemanticsDelegateCls(VoidCallback onDismiss);
};
using _ModalBarrierSemanticsDelegate = std::shared_ptr<_ModalBarrierSemanticsDelegateCls>;

class _AnyTapGestureRecognizerFactoryCls : public GestureRecognizerFactoryCls<_AnyTapGestureRecognizer> {
public:
    VoidCallback onAnyTapUp;


    virtual _AnyTapGestureRecognizer constructor();

    virtual void initializer(_AnyTapGestureRecognizer instance);

private:

     _AnyTapGestureRecognizerFactoryCls(VoidCallback onAnyTapUp);
};
using _AnyTapGestureRecognizerFactory = std::shared_ptr<_AnyTapGestureRecognizerFactoryCls>;

class _ModalBarrierGestureDetectorCls : public StatelessWidgetCls {
public:
    Widget child;

    VoidCallback onDismiss;


    virtual Widget build(BuildContext context);

private:

     _ModalBarrierGestureDetectorCls(Widget child, VoidCallback onDismiss);

};
using _ModalBarrierGestureDetector = std::shared_ptr<_ModalBarrierGestureDetectorCls>;


#endif