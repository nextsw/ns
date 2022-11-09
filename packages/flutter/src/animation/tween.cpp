#include "tween.hpp"
template<typename T> T AnimatableCls<T>::evaluate(Animation<double> animation) {
    return transform(animation->value);
}

template<typename T> Animation<T> AnimatableCls<T>::animate(Animation<double> parent) {
    return <T>make<_AnimatedEvaluationCls>(parent, this);
}

template<typename T> Animatable<T> AnimatableCls<T>::chain(Animatable<double> parent) {
    return <T>make<_ChainedEvaluationCls>(parent, this);
}

template<typename T> T _AnimatedEvaluationCls<T>::value() {
    return _evaluatable->evaluate(parent);
}

template<typename T> String _AnimatedEvaluationCls<T>::toString() {
    return "$parent\u27A9$_evaluatable\u27A9$value";
}

template<typename T> String _AnimatedEvaluationCls<T>::toStringDetails() {
    return "${super.toStringDetails()} $_evaluatable";
}

template<typename T> T _ChainedEvaluationCls<T>::transform(double t) {
    return _evaluatable->transform(_parent->transform(t));
}

template<typename T> String _ChainedEvaluationCls<T>::toString() {
    return "$_parent\u27A9$_evaluatable";
}

template<typename T : Object> T TweenCls<T>::lerp(double t) {
    assert(begin != nullptr);
    assert(end != nullptr);
    assert([=] () {
        dynamic result;
        try {
            result = (((dynamic)begin)) + ((((dynamic)end)) - (((dynamic)begin))) * t;
            ((T)result);
            return true;
        } catch (NoSuchMethodError null) {
            ;
        } catch (TypeError null) {
            ;
        };
    }());
    return ((T)(((dynamic)begin)) + ((((dynamic)end)) - (((dynamic)begin))) * t);
}

template<typename T : Object> T TweenCls<T>::transform(double t) {
    if (t == 0.0) {
        return ((T)begin);
    }
    if (t == 1.0) {
        return ((T)end);
    }
    return lerp(t);
}

template<typename T : Object> String TweenCls<T>::toString() {
    return "${objectRuntimeType(this, 'Animatable')}($begin \u2192 $end)";
}

template<typename T : Object> ReverseTweenCls<T>::ReverseTweenCls(Tween<T> parent) {
    {
        assert(parent != nullptr);
    }
}

template<typename T : Object> T ReverseTweenCls<T>::lerp(double t) {
    return parent->lerp(1.0 - t);
}

Color ColorTweenCls::lerp(double t) {
    return ColorCls->lerp(begin, end, t);
}

Size SizeTweenCls::lerp(double t) {
    return SizeCls->lerp(begin, end, t);
}

Rect RectTweenCls::lerp(double t) {
    return RectCls->lerp(begin, end, t);
}

int IntTweenCls::lerp(double t) {
    return (begin! + (end! - begin!) * t)->round();
}

int StepTweenCls::lerp(double t) {
    return (begin! + (end! - begin!) * t)->floor();
}

template<typename T> ConstantTweenCls<T>::ConstantTweenCls(T value) {
}

template<typename T> T ConstantTweenCls<T>::lerp(double t) {
    return ((T)begin);
}

template<typename T> String ConstantTweenCls<T>::toString() {
    return "${objectRuntimeType(this, 'ConstantTween')}(value: $begin)";
}

CurveTweenCls::CurveTweenCls(Curve curve) {
    {
        assert(curve != nullptr);
    }
}

double CurveTweenCls::transform(double t) {
    if (t == 0.0 || t == 1.0) {
        assert(curve->transform(t)->round() == t);
        return t;
    }
    return curve->transform(t);
}

String CurveTweenCls::toString() {
    return "${objectRuntimeType(this, 'CurveTween')}(curve: $curve)";
}
