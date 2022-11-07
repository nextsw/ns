#include "tween_animation_builder.hpp"
TweenAnimationBuilder::TweenAnimationBuilder(ValueWidgetBuilder<T> builder, Widget child, Unknown, Unknown, Unknown, Unknown, Tween<T> tween) {
    {
        assert(tween != nullptr);
        assert(curve != nullptr);
        assert(builder != nullptr);
    }
}

ImplicitlyAnimatedWidgetState<ImplicitlyAnimatedWidget> TweenAnimationBuilder::createState() {
    return <T>_TweenAnimationBuilderState();
}

void _TweenAnimationBuilderState::initState() {
    _currentTween = widget.tween;
    _currentTween!.begin = _currentTween!.end;
    super.initState();
    if (_currentTween!.begin != _currentTween!.end) {
        controller.forward();
    }
}

void _TweenAnimationBuilderState::forEachTween(TweenVisitor<dynamic> visitor) {
    assert(widget.tween.end != nullptr, "Tween provided to TweenAnimationBuilder must have non-null Tween.end value.");
    _currentTween = (;
}

Widget _TweenAnimationBuilderState::build(BuildContext context) {
    return widget.builder(context, _currentTween!.evaluate(animation), widget.child);
}
