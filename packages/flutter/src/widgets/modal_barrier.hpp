#ifndef MODAL_BARRIER_H
#define MODAL_BARRIER_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include <flutter/services.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"
#include "navigator.hpp"
#include "transitions.hpp"



class ModalBarrier : StatelessWidget {
public:
    Color color;

    bool dismissible;

    VoidCallback onDismiss;

    bool barrierSemanticsDismissible;

    String semanticsLabel;


     ModalBarrier(bool barrierSemanticsDismissible, Color color, bool dismissible, Unknown, VoidCallback onDismiss, String semanticsLabel);

    Widget build(BuildContext context);

private:

};

class AnimatedModalBarrier : AnimatedWidget {
public:
    bool dismissible;

    String semanticsLabel;

    bool barrierSemanticsDismissible;

    VoidCallback onDismiss;


     AnimatedModalBarrier(bool barrierSemanticsDismissible, Animation<Color> color, bool dismissible, Unknown, VoidCallback onDismiss, String semanticsLabel);

    Animation<Color> color();

    Widget build(BuildContext context);

private:

};

class _AnyTapGestureRecognizer : BaseTapGestureRecognizer {
public:
    VoidCallback onAnyTapUp;


    bool isPointerAllowed(PointerDownEvent event);

    void handleTapDown(PointerDownEvent down);

    void handleTapUp(PointerDownEvent down, PointerUpEvent up);

    void handleTapCancel(PointerCancelEvent cancel, PointerDownEvent down, String reason);

    String debugDescription();

private:

     _AnyTapGestureRecognizer();

};

class _ModalBarrierSemanticsDelegate : SemanticsGestureDelegate {
public:
    VoidCallback onDismiss;


    void assignSemantics(RenderSemanticsGestureHandler renderObject);

private:

     _ModalBarrierSemanticsDelegate(VoidCallback onDismiss);

};

class _AnyTapGestureRecognizerFactory : GestureRecognizerFactory<_AnyTapGestureRecognizer> {
public:
    VoidCallback onAnyTapUp;


    _AnyTapGestureRecognizer constructor();

    void initializer(_AnyTapGestureRecognizer instance);

private:

     _AnyTapGestureRecognizerFactory(VoidCallback onAnyTapUp);

};

class _ModalBarrierGestureDetector : StatelessWidget {
public:
    Widget child;

    VoidCallback onDismiss;


    Widget build(BuildContext context);

private:

     _ModalBarrierGestureDetector(Widget child, VoidCallback onDismiss);

};

#endif