#include "modal_barrier.hpp"
Widget ModalBarrier::build(BuildContext context) {
    assert(!dismissible || semanticsLabel == nullptr || debugCheckHasDirectionality(context));
    bool platformSupportsDismissingBarrier;
    ;
    assert(platformSupportsDismissingBarrier != nullptr);
    bool semanticsDismissible = dismissible && platformSupportsDismissingBarrier;
    bool modalBarrierSemanticsDismissible = barrierSemanticsDismissible ?? semanticsDismissible;
    ;
    return BlockSemantics(ExcludeSemantics(!semanticsDismissible || !modalBarrierSemanticsDismissible, _ModalBarrierGestureDetector(handleDismiss, Semantics(semanticsDismissible? semanticsLabel : nullptr, semanticsDismissible? handleDismiss : nullptr, semanticsDismissible && semanticsLabel != nullptr? Directionality.of(context) : nullptr, MouseRegion(SystemMouseCursors.basic, ConstrainedBox(const BoxConstraints.expand(), color == nullptr? nullptr : ColoredBox(color!)))))));
}

AnimatedModalBarrier::AnimatedModalBarrier(bool barrierSemanticsDismissible, Animation<Color> color, bool dismissible, Unknown, VoidCallback onDismiss, String semanticsLabel) {
    {
        super(color);
    }
}

Animation<Color> AnimatedModalBarrier::color() {
    return (;
}

Widget AnimatedModalBarrier::build(BuildContext context) {
    return ModalBarrier(color.value, dismissible, semanticsLabel, barrierSemanticsDismissible, onDismiss);
}

bool _AnyTapGestureRecognizer::isPointerAllowed(PointerDownEvent event) {
    if (onAnyTapUp == nullptr) {
        return false;
    }
    return super.isPointerAllowed(event);
}

void _AnyTapGestureRecognizer::handleTapDown(PointerDownEvent down) {
}

void _AnyTapGestureRecognizer::handleTapUp(PointerDownEvent down, PointerUpEvent up) {
    onAnyTapUp?.call();
}

void _AnyTapGestureRecognizer::handleTapCancel(PointerCancelEvent cancel, PointerDownEvent down, String reason) {
}

String _AnyTapGestureRecognizer::debugDescription() {
    return "any tap";
}

void _ModalBarrierSemanticsDelegate::assignSemantics(RenderSemanticsGestureHandler renderObject) {
    renderObject.onTap = onDismiss;
}

_AnyTapGestureRecognizer _AnyTapGestureRecognizerFactory::constructor() {
    return _AnyTapGestureRecognizer();
}

void _AnyTapGestureRecognizerFactory::initializer(_AnyTapGestureRecognizer instance) {
    instance.onAnyTapUp = onAnyTapUp;
}

Widget _ModalBarrierGestureDetector::build(BuildContext context) {
    Map<Type, GestureRecognizerFactory> gestures = ;
    return RawGestureDetector(gestures, HitTestBehavior.opaque, _ModalBarrierSemanticsDelegate(onDismiss), child);
}

_ModalBarrierGestureDetector::_ModalBarrierGestureDetector(Widget child, VoidCallback onDismiss) {
    {
        assert(child != nullptr);
        assert(onDismiss != nullptr);
    }
}
