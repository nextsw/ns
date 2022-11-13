#include "tween.hpp"
template<typename T>
T AnimatableCls<T>::evaluate(Animation<double> animation) {
    return transform(animation->value());
}

template<typename T>
Animation<T> AnimatableCls<T>::animate(Animation<double> parent) {
    return <T>make<_AnimatedEvaluationCls>(parent, this);
}

template<typename T>
Animatable<T> AnimatableCls<T>::chain(Animatable<double> parent) {
    return <T>make<_ChainedEvaluationCls>(parent, this);
}

template<typename T>
T _AnimatedEvaluationCls<T>::value() {
    return _evaluatable->evaluate(parent);
}

template<typename T>
String _AnimatedEvaluationCls<T>::toString() {
    return __sf("%s\u27A9%s\u27A9%s", parent, _evaluatable, value());
}

template<typename T>
String _AnimatedEvaluationCls<T>::toStringDetails() {
    return __sf("%s %s", super->toStringDetails(), _evaluatable);
}

template<typename T>
T _ChainedEvaluationCls<T>::transform(double t) {
    return _evaluatable->transform(_parent->transform(t));
}

template<typename T>
String _ChainedEvaluationCls<T>::toString() {
    return __sf("%s\u27A9%s", _parent, _evaluatable);
}

template<typename T>
T TweenCls<T>::lerp(double t) {
    assert(begin != nullptr);
    assert(end != nullptr);
    assert([=] () {
        dynamic result;
        try {
            result = (as<dynamic>(begin)) + ((as<dynamic>(end)) - (as<dynamic>(begin))) * t;
            as<T>(result);
            return true;
        } catch (NoSuchMethodError null) {
                    List<DiagnosticsNode> list1 = make<ListCls<>>();        list1.add(ArrayItem);        list1.add(ArrayItem);        if (is<Color>(begin) || is<Color>(end)) {            list1.add(ArrayItem);        } else {            list1.add(ArrayItem);        }throw FlutterErrorCls->fromParts(list1);
        } catch (TypeError null) {
                    List<DiagnosticsNode> list2 = make<ListCls<>>();        list2.add(ArrayItem);        list2.add(ArrayItem);        if (is<int>(begin) || is<int>(end)) {            list2.add(ArrayItem);        } else {            list2.add(ArrayItem);        }throw FlutterErrorCls->fromParts(list2);
        };
    }());
    return as<T>((as<dynamic>(begin)) + ((as<dynamic>(end)) - (as<dynamic>(begin))) * t);
}

template<typename T>
T TweenCls<T>::transform(double t) {
    if (t == 0.0) {
        return as<T>(begin);
    }
    if (t == 1.0) {
        return as<T>(end);
    }
    return lerp(t);
}

template<typename T>
String TweenCls<T>::toString() {
    return __sf("%s(%s \u2192 %s)", objectRuntimeType(this, __s("Animatable")), begin, end);
}

template<typename T>
ReverseTweenCls<T>::ReverseTweenCls(Tween<T> parent) : Tween<T>(parent->end, parent->begin) {
    {
        assert(parent != nullptr);
    }
}

template<typename T>
T ReverseTweenCls<T>::lerp(double t) {
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

template<typename T>
ConstantTweenCls<T>::ConstantTweenCls(T value) : Tween<T>(value, value) {
}

template<typename T>
T ConstantTweenCls<T>::lerp(double t) {
    return as<T>(begin);
}

template<typename T>
String ConstantTweenCls<T>::toString() {
    return __sf("%s(value: %s)", objectRuntimeType(this, __s("ConstantTween")), begin);
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
    return __sf("%s(curve: %s)", objectRuntimeType(this, __s("CurveTween")), curve);
}
