#include "tween_animation_builder.hpp"
template<typename T>
TweenAnimationBuilderCls<T>::TweenAnimationBuilderCls(ValueWidgetBuilder<T> builder, Widget child, Unknown curve, Unknown duration, Unknown key, Unknown onEnd, Tween<T> tween) {
    {
        assert(tween != nullptr);
        assert(curve != nullptr);
        assert(builder != nullptr);
    }
}

template<typename T>
ImplicitlyAnimatedWidgetState<ImplicitlyAnimatedWidget> TweenAnimationBuilderCls<T>::createState() {
    return <T>make<_TweenAnimationBuilderStateCls>();
}

template<typename T>
void _TweenAnimationBuilderStateCls<T>::initState() {
    _currentTween = widget->tween;
    _currentTween!->begin = _currentTween!->end;
    super->initState();
    if (_currentTween!->begin != _currentTween!->end) {
        controller->forward();
    }
}

template<typename T>
void _TweenAnimationBuilderStateCls<T>::forEachTween(TweenVisitor<dynamic> visitor) {
    assert(widget->tween->end != nullptr, __s("Tween provided to TweenAnimationBuilder must have non-null Tween.end value."));
    _currentTween = as<Tween<T>>(visitor(_currentTween, widget->tween->end, [=] (dynamic value) {
        assert(false);
        ;
    }));
}

template<typename T>
Widget _TweenAnimationBuilderStateCls<T>::build(BuildContext context) {
    return widget->builder(context, _currentTween!->evaluate(animation), widget->child);
}