#include "tween.hpp"
T Animatable::evaluate(Animation<double> animation) {
    return transform(animation.value);
}

Animation<T> Animatable::animate(Animation<double> parent) {
    return <T>_AnimatedEvaluation(parent, this);
}

Animatable<T> Animatable::chain(Animatable<double> parent) {
    return <T>_ChainedEvaluation(parent, this);
}

T _AnimatedEvaluation::value() {
    return _evaluatable.evaluate(parent);
}

String _AnimatedEvaluation::toString() {
    return "$parent\u27A9$_evaluatable\u27A9$value";
}

String _AnimatedEvaluation::toStringDetails() {
    return "${super.toStringDetails()} $_evaluatable";
}

T _ChainedEvaluation::transform(double t) {
    return _evaluatable.transform(_parent.transform(t));
}

String _ChainedEvaluation::toString() {
    return "$_parent\u27A9$_evaluatable";
}

T Tween::lerp(double t) {
    assert(begin != nullptr);
    assert(end != nullptr);
    assert(());
    return (;
}

T Tween::transform(double t) {
    if (t == 0.0) {
        return (;
    }
    if (t == 1.0) {
        return (;
    }
    return lerp(t);
}

String Tween::toString() {
    return "${objectRuntimeType(this, 'Animatable')}($begin \u2192 $end)";
}

ReverseTween::ReverseTween(Tween<T> parent) {
    {
        assert(parent != nullptr);
        super(parent.end, parent.begin);
    }
}

T ReverseTween::lerp(double t) {
    return parent.lerp(1.0 - t);
}

Color ColorTween::lerp(double t) {
    return Color.lerp(begin, end, t);
}

Size SizeTween::lerp(double t) {
    return Size.lerp(begin, end, t);
}

Rect RectTween::lerp(double t) {
    return Rect.lerp(begin, end, t);
}

int IntTween::lerp(double t) {
    return (begin! + (end! - begin!) * t).round();
}

int StepTween::lerp(double t) {
    return (begin! + (end! - begin!) * t).floor();
}

ConstantTween::ConstantTween(T value) {
    {
        super(value, value);
    }
}

T ConstantTween::lerp(double t) {
    return (;
}

String ConstantTween::toString() {
    return "${objectRuntimeType(this, 'ConstantTween')}(value: $begin)";
}

CurveTween::CurveTween(Curve curve) {
    {
        assert(curve != nullptr);
    }
}

double CurveTween::transform(double t) {
    if (t == 0.0 || t == 1.0) {
        assert(curve.transform(t).round() == t);
        return t;
    }
    return curve.transform(t);
}

String CurveTween::toString() {
    return "${objectRuntimeType(this, 'CurveTween')}(curve: $curve)";
}
