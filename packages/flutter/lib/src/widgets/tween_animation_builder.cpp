#include "tween_animation_builder.hpp"
template<typename T>
TweenAnimationBuilderCls<T>::TweenAnimationBuilderCls(ValueWidgetBuilder<T> builder, Widget child, Curve curve, Duration duration, Key key, VoidCallback onEnd, Tween<T> tween) {
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
    _currentTween = widget()->tween;
    _currentTween!->begin |= _currentTween!->end;
    super->initState();
    if (_currentTween!->begin != _currentTween!->end) {
        controller()->forward();
    }
}

template<typename T>
void _TweenAnimationBuilderStateCls<T>::forEachTween(TweenVisitor<Object> visitor) {
    assert(widget()->tween->end != nullptr, __s("Tween provided to TweenAnimationBuilder must have non-null Tween.end value."));
    _currentTween = as<Tween<T>>(visitor(_currentTween, widget()->tween->end, [=] (Object value) {
        assert(false);
        throw make<StateErrorCls>(__s("Constructor will never be called because null is never provided as current tween."));
    }));
}

template<typename T>
Widget _TweenAnimationBuilderStateCls<T>::build(BuildContext context) {
    return widget()->builder(context, _currentTween!->evaluate(animation()), widget()->child);
}
