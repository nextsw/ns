#include "animations.hpp"
void _AlwaysCompleteAnimationCls::addListener(VoidCallback listener) {
}

void _AlwaysCompleteAnimationCls::removeListener(VoidCallback listener) {
}

void _AlwaysCompleteAnimationCls::addStatusListener(AnimationStatusListener listener) {
}

void _AlwaysCompleteAnimationCls::removeStatusListener(AnimationStatusListener listener) {
}

AnimationStatus _AlwaysCompleteAnimationCls::status() {
    return AnimationStatusCls::completed;
}

double _AlwaysCompleteAnimationCls::value() {
    return 1.0;
}

String _AlwaysCompleteAnimationCls::toString() {
    return __s("kAlwaysCompleteAnimation");
}

void _AlwaysDismissedAnimationCls::addListener(VoidCallback listener) {
}

void _AlwaysDismissedAnimationCls::removeListener(VoidCallback listener) {
}

void _AlwaysDismissedAnimationCls::addStatusListener(AnimationStatusListener listener) {
}

void _AlwaysDismissedAnimationCls::removeStatusListener(AnimationStatusListener listener) {
}

AnimationStatus _AlwaysDismissedAnimationCls::status() {
    return AnimationStatusCls::dismissed;
}

double _AlwaysDismissedAnimationCls::value() {
    return 0.0;
}

String _AlwaysDismissedAnimationCls::toString() {
    return __s("kAlwaysDismissedAnimation");
}

template<typename T>
void AlwaysStoppedAnimationCls<T>::addListener(VoidCallback listener) {
}

template<typename T>
void AlwaysStoppedAnimationCls<T>::removeListener(VoidCallback listener) {
}

template<typename T>
void AlwaysStoppedAnimationCls<T>::addStatusListener(AnimationStatusListener listener) {
}

template<typename T>
void AlwaysStoppedAnimationCls<T>::removeStatusListener(AnimationStatusListener listener) {
}

template<typename T>
AnimationStatus AlwaysStoppedAnimationCls<T>::status() {
    return AnimationStatusCls::forward;
}

template<typename T>
String AlwaysStoppedAnimationCls<T>::toStringDetails() {
    return __sf("%s %s; paused", super->toStringDetails(), value);
}

template<typename T>
void AnimationWithParentMixinCls<T>::addListener(VoidCallback listener) {
    return parent()->addListener(listener);
}

template<typename T>
void AnimationWithParentMixinCls<T>::removeListener(VoidCallback listener) {
    return parent()->removeListener(listener);
}

template<typename T>
void AnimationWithParentMixinCls<T>::addStatusListener(AnimationStatusListener listener) {
    return parent()->addStatusListener(listener);
}

template<typename T>
void AnimationWithParentMixinCls<T>::removeStatusListener(AnimationStatusListener listener) {
    return parent()->removeStatusListener(listener);
}

template<typename T>
AnimationStatus AnimationWithParentMixinCls<T>::status() {
    return parent()->status();
}

ProxyAnimationCls::ProxyAnimationCls(Animation<double> animation) {
    {
        _parent = animation;
        if (_parent == nullptr) {
            _status = AnimationStatusCls::dismissed;
            _value = 0.0;
        }
    }
}

Animation<double> ProxyAnimationCls::parent() {
    return _parent;
}

void ProxyAnimationCls::parent(Animation<double> value) {
    if (value == _parent) {
        return;
    }
    if (_parent != nullptr) {
        _status = _parent!->status();
        _value = _parent!->value;
        if (isListening) {
            didStopListening();
        }
    }
    _parent = value;
    if (_parent != nullptr) {
        if (isListening) {
            didStartListening();
        }
        if (_value != _parent!->value) {
            notifyListeners();
        }
        if (_status != _parent!->status()) {
            notifyStatusListeners(_parent!->status());
        }
        _status = nullptr;
        _value = nullptr;
    }
}

void ProxyAnimationCls::didStartListening() {
    if (_parent != nullptr) {
        _parent!->addListener(notifyListeners);
        _parent!->addStatusListener(notifyStatusListeners);
    }
}

void ProxyAnimationCls::didStopListening() {
    if (_parent != nullptr) {
        _parent!->removeListener(notifyListeners);
        _parent!->removeStatusListener(notifyStatusListeners);
    }
}

AnimationStatus ProxyAnimationCls::status() {
    return _parent != nullptr? _parent!->status() : _status!;
}

double ProxyAnimationCls::value() {
    return _parent != nullptr? _parent!->value() : _value!;
}

String ProxyAnimationCls::toString() {
    if (parent() == nullptr) {
        return __sf("%s(null; %s %s)", objectRuntimeType(this, __s("ProxyAnimation")), super->toStringDetails(), value()->toStringAsFixed(3));
    }
    return __sf("%s\u27A9%s", parent(), objectRuntimeType(this, __s("ProxyAnimation")));
}

ReverseAnimationCls::ReverseAnimationCls(Animation<double> parent) {
    {
        assert(parent != nullptr);
    }
}

void ReverseAnimationCls::addListener(VoidCallback listener) {
    didRegisterListener();
    parent->addListener(listener);
}

void ReverseAnimationCls::removeListener(VoidCallback listener) {
    parent->removeListener(listener);
    didUnregisterListener();
}

void ReverseAnimationCls::didStartListening() {
    parent->addStatusListener(_statusChangeHandler);
}

void ReverseAnimationCls::didStopListening() {
    parent->removeStatusListener(_statusChangeHandler);
}

AnimationStatus ReverseAnimationCls::status() {
    return _reverseStatus(parent->status());
}

double ReverseAnimationCls::value() {
    return 1.0 - parent->value();
}

String ReverseAnimationCls::toString() {
    return __sf("%s\u27AA%s", parent, objectRuntimeType(this, __s("ReverseAnimation")));
}

void ReverseAnimationCls::_statusChangeHandler(AnimationStatus status) {
    notifyStatusListeners(_reverseStatus(status));
}

AnimationStatus ReverseAnimationCls::_reverseStatus(AnimationStatus status) {
    assert(status != nullptr);
    ;
}

CurvedAnimationCls::CurvedAnimationCls(Curve curve, Animation<double> parent, Curve reverseCurve) {
    {
        assert(parent != nullptr);
        assert(curve != nullptr);
    }
    {
        _updateCurveDirection(parent->status());
        parent->addStatusListener(_updateCurveDirection);
    }
}

void CurvedAnimationCls::dispose() {
    isDisposed = true;
    parent->removeStatusListener(_updateCurveDirection);
}

double CurvedAnimationCls::value() {
    Curve activeCurve = _useForwardCurve()? curve : reverseCurve;
    double t = parent->value();
    if (activeCurve == nullptr) {
        return t;
    }
    if (t == 0.0 || t == 1.0) {
        assert([=] () {
            double transformedValue = activeCurve->transform(t);
            double roundedTransformedValue = transformedValue->round()->toDouble();
            if (roundedTransformedValue != t) {
                throw make<FlutterErrorCls>(__sf("Invalid curve endpoint at %s.\nCurves must map 0.0 to near zero and 1.0 to near one but %s mapped %s to %s, which is near %s.", t, activeCurve->runtimeType, t, transformedValue, roundedTransformedValue));
            }
            return true;
        }());
        return t;
    }
    return activeCurve->transform(t);
}

String CurvedAnimationCls::toString() {
    if (reverseCurve == nullptr) {
        return __sf("%s\u27A9%s", parent, curve);
    }
    if (_useForwardCurve()) {
        return __sf("%s\u27A9%s\u2092\u2099/%s", parent, curve, reverseCurve);
    }
    return __sf("%s\u27A9%s/%s\u2092\u2099", parent, curve, reverseCurve);
}

void CurvedAnimationCls::_updateCurveDirection(AnimationStatus status) {
    ;
}

bool CurvedAnimationCls::_useForwardCurve() {
    return reverseCurve == nullptr || (_curveDirection | parent->status()) != AnimationStatusCls::reverse;
}

TrainHoppingAnimationCls::TrainHoppingAnimationCls(Animation<double> _currentTrain, Animation<double> _nextTrain, VoidCallback onSwitchedTrain) {
    {
        assert(_currentTrain != nullptr);
    }
    {
        if (_nextTrain != nullptr) {
            if (_currentTrain!->value() == _nextTrain!->value()) {
                _currentTrain = _nextTrain;
                _nextTrain = nullptr;
            } else {
                if (_currentTrain!->value() > _nextTrain!->value()) {
                _mode = _TrainHoppingModeCls::maximize;
            } else {
                assert(_currentTrain!->value() < _nextTrain!->value());
                _mode = _TrainHoppingModeCls::minimize;
            }
;
            }        }
        _currentTrain!->addStatusListener(_statusChangeHandler);
        _currentTrain!->addListener(_valueChangeHandler);
        _nextTrain?->addListener(_valueChangeHandler);
        assert(_mode != nullptr || _nextTrain == nullptr);
    }
}

Animation<double> TrainHoppingAnimationCls::currentTrain() {
    return _currentTrain;
}

AnimationStatus TrainHoppingAnimationCls::status() {
    return _currentTrain!->status();
}

double TrainHoppingAnimationCls::value() {
    return _currentTrain!->value();
}

void TrainHoppingAnimationCls::dispose() {
    assert(_currentTrain != nullptr);
    _currentTrain!->removeStatusListener(_statusChangeHandler);
    _currentTrain!->removeListener(_valueChangeHandler);
    _currentTrain = nullptr;
    _nextTrain?->removeListener(_valueChangeHandler);
    _nextTrain = nullptr;
    clearListeners();
    clearStatusListeners();
    super->dispose();
}

String TrainHoppingAnimationCls::toString() {
    if (_nextTrain != nullptr) {
        return __sf("%s\u27A9%s(next: %s)", currentTrain(), objectRuntimeType(this, __s("TrainHoppingAnimation")), _nextTrain);
    }
    return __sf("%s\u27A9%s(no next)", currentTrain(), objectRuntimeType(this, __s("TrainHoppingAnimation")));
}

void TrainHoppingAnimationCls::_statusChangeHandler(AnimationStatus status) {
    assert(_currentTrain != nullptr);
    if (status != _lastStatus) {
        notifyListeners();
        _lastStatus = status;
    }
    assert(_lastStatus != nullptr);
}

void TrainHoppingAnimationCls::_valueChangeHandler() {
    assert(_currentTrain != nullptr);
    bool hop = false;
    if (_nextTrain != nullptr) {
        assert(_mode != nullptr);
        ;
        if (hop) {
                    auto _c1 = _currentTrain!;        _c1.auto _c2 = removeStatusListener(_statusChangeHandler);        _c2.removeListener(_valueChangeHandler);        _c2;_c1;
            _currentTrain = _nextTrain;
            _nextTrain = nullptr;
            _currentTrain!->addStatusListener(_statusChangeHandler);
            _statusChangeHandler(_currentTrain!->status());
        }
    }
    double newValue = value();
    if (newValue != _lastValue) {
        notifyListeners();
        _lastValue = newValue;
    }
    assert(_lastValue != nullptr);
    if (hop && onSwitchedTrain != nullptr) {
        onSwitchedTrain!();
    }
}

template<typename T>
CompoundAnimationCls<T>::CompoundAnimationCls(Animation<T> first, Animation<T> next) {
    {
        assert(first != nullptr);
        assert(next != nullptr);
    }
}

template<typename T>
void CompoundAnimationCls<T>::didStartListening() {
    first->addListener(_maybeNotifyListeners);
    first->addStatusListener(_maybeNotifyStatusListeners);
    next->addListener(_maybeNotifyListeners);
    next->addStatusListener(_maybeNotifyStatusListeners);
}

template<typename T>
void CompoundAnimationCls<T>::didStopListening() {
    first->removeListener(_maybeNotifyListeners);
    first->removeStatusListener(_maybeNotifyStatusListeners);
    next->removeListener(_maybeNotifyListeners);
    next->removeStatusListener(_maybeNotifyStatusListeners);
}

template<typename T>
AnimationStatus CompoundAnimationCls<T>::status() {
    if (next->status() == AnimationStatusCls::forward || next->status() == AnimationStatusCls::reverse) {
        return next->status();
    }
    return first->status();
}

template<typename T>
String CompoundAnimationCls<T>::toString() {
    return __sf("%s(%s, %s)", objectRuntimeType(this, __s("CompoundAnimation")), first, next);
}

template<typename T>
void CompoundAnimationCls<T>::_maybeNotifyStatusListeners(AnimationStatus _) {
    if (status() != _lastStatus) {
        _lastStatus = status();
        notifyStatusListeners(status());
    }
}

template<typename T>
void CompoundAnimationCls<T>::_maybeNotifyListeners() {
    if (value() != _lastValue) {
        _lastValue = value();
        notifyListeners();
    }
}

AnimationMeanCls::AnimationMeanCls(Animation<double> left, Animation<double> right) : CompoundAnimation<double>(left, right) {
}

double AnimationMeanCls::value() {
    return (first->value() + next->value()) / 2.0;
}

template<typename T>
AnimationMaxCls<T>::AnimationMaxCls(Animation<T> first, Animation<T> next) : CompoundAnimation<T>(first, next) {
}

template<typename T>
T AnimationMaxCls<T>::value() {
    return math->max(first->value(), next->value());
}

template<typename T>
AnimationMinCls<T>::AnimationMinCls(Animation<T> first, Animation<T> next) : CompoundAnimation<T>(first, next) {
}

template<typename T>
T AnimationMinCls<T>::value() {
    return math->min(first->value(), next->value());
}
