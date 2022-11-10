#include "modal_barrier.hpp"
Widget ModalBarrierCls::build(BuildContext context) {
    assert(!dismissible || semanticsLabel == nullptr || debugCheckHasDirectionality(context));
    bool platformSupportsDismissingBarrier;
    ;
    assert(platformSupportsDismissingBarrier != nullptr);
    bool semanticsDismissible = dismissible && platformSupportsDismissingBarrier;
    bool modalBarrierSemanticsDismissible = barrierSemanticsDismissible or semanticsDismissible;
    InlineMethod;
    return make<BlockSemanticsCls>(make<ExcludeSemanticsCls>(!semanticsDismissible || !modalBarrierSemanticsDismissible, make<_ModalBarrierGestureDetectorCls>(handleDismiss, make<SemanticsCls>(semanticsDismissible? semanticsLabel : nullptr, semanticsDismissible? handleDismiss : nullptr, semanticsDismissible && semanticsLabel != nullptr? DirectionalityCls->of(context) : nullptr, make<MouseRegionCls>(SystemMouseCursorsCls::basic, make<ConstrainedBoxCls>(BoxConstraintsCls->expand(), color == nullptr? nullptr : make<ColoredBoxCls>(color!)))))));
}

AnimatedModalBarrierCls::AnimatedModalBarrierCls(bool barrierSemanticsDismissible, Animation<Color> color, bool dismissible, Unknown key, VoidCallback onDismiss, String semanticsLabel) : AnimatedWidget(color()) {
}

Animation<Color> AnimatedModalBarrierCls::color() {
    return as<Animation<Color>>(listenable);
}

Widget AnimatedModalBarrierCls::build(BuildContext context) {
    return make<ModalBarrierCls>(color()->value(), dismissible, semanticsLabel, barrierSemanticsDismissible, onDismiss);
}

bool _AnyTapGestureRecognizerCls::isPointerAllowed(PointerDownEvent event) {
    if (onAnyTapUp == nullptr) {
        return false;
    }
    return super->isPointerAllowed(event);
}

void _AnyTapGestureRecognizerCls::handleTapDown(PointerDownEvent down) {
}

void _AnyTapGestureRecognizerCls::handleTapUp(PointerDownEvent down, PointerUpEvent up) {
    onAnyTapUp?->call();
}

void _AnyTapGestureRecognizerCls::handleTapCancel(PointerCancelEvent cancel, PointerDownEvent down, String reason) {
}

String _AnyTapGestureRecognizerCls::debugDescription() {
    return __s("any tap");
}

void _ModalBarrierSemanticsDelegateCls::assignSemantics(RenderSemanticsGestureHandler renderObject) {
    renderObject->onTap = onDismiss;
}

_AnyTapGestureRecognizer _AnyTapGestureRecognizerFactoryCls::constructor() {
    return make<_AnyTapGestureRecognizerCls>();
}

void _AnyTapGestureRecognizerFactoryCls::initializer(_AnyTapGestureRecognizer instance) {
    instance->onAnyTapUp = onAnyTapUp;
}

Widget _ModalBarrierGestureDetectorCls::build(BuildContext context) {
    Map<Type, GestureRecognizerFactory> map1 = make<MapCls<>>();map1.set(_AnyTapGestureRecognizerCls, make<_AnyTapGestureRecognizerFactoryCls>(onDismiss));Map<Type, GestureRecognizerFactory> gestures = list1;
    return make<RawGestureDetectorCls>(gestures, HitTestBehaviorCls::opaque, make<_ModalBarrierSemanticsDelegateCls>(onDismiss), child);
}

_ModalBarrierGestureDetectorCls::_ModalBarrierGestureDetectorCls(Widget child, VoidCallback onDismiss) {
    {
        assert(child != nullptr);
        assert(onDismiss != nullptr);
    }
}
