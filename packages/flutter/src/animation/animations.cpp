#include "animations.hpp"
void _AlwaysCompleteAnimation::addListener(VoidCallback listener) {
}

void _AlwaysCompleteAnimation::removeListener(VoidCallback listener) {
}

void _AlwaysCompleteAnimation::addStatusListener(AnimationStatusListener listener) {
}

void _AlwaysCompleteAnimation::removeStatusListener(AnimationStatusListener listener) {
}

AnimationStatus _AlwaysCompleteAnimation::status() {
    return AnimationStatus.completed;
}

double _AlwaysCompleteAnimation::value() {
    return 1.0;
}

String _AlwaysCompleteAnimation::toString() {
    return "kAlwaysCompleteAnimation";
}

void _AlwaysDismissedAnimation::addListener(VoidCallback listener) {
}

void _AlwaysDismissedAnimation::removeListener(VoidCallback listener) {
}

void _AlwaysDismissedAnimation::addStatusListener(AnimationStatusListener listener) {
}

void _AlwaysDismissedAnimation::removeStatusListener(AnimationStatusListener listener) {
}

AnimationStatus _AlwaysDismissedAnimation::status() {
    return AnimationStatus.dismissed;
}

double _AlwaysDismissedAnimation::value() {
    return 0.0;
}

String _AlwaysDismissedAnimation::toString() {
    return "kAlwaysDismissedAnimation";
}

void AlwaysStoppedAnimation::addListener(VoidCallback listener) {
}

void AlwaysStoppedAnimation::removeListener(VoidCallback listener) {
}

void AlwaysStoppedAnimation::addStatusListener(AnimationStatusListener listener) {
}

void AlwaysStoppedAnimation::removeStatusListener(AnimationStatusListener listener) {
}

AnimationStatus AlwaysStoppedAnimation::status() {
    return AnimationStatus.forward;
}

String AlwaysStoppedAnimation::toStringDetails() {
    return "${super.toStringDetails()} $value; paused";
}

void AnimationWithParentMixin::addListener(VoidCallback listener) {
    return parent.addListener(listener);
}

void AnimationWithParentMixin::removeListener(VoidCallback listener) {
    return parent.removeListener(listener);
}

void AnimationWithParentMixin::addStatusListener(AnimationStatusListener listener) {
    return parent.addStatusListener(listener);
}

void AnimationWithParentMixin::removeStatusListener(AnimationStatusListener listener) {
    return parent.removeStatusListener(listener);
}

AnimationStatus AnimationWithParentMixin::status() {
    return parent.status;
}

ProxyAnimation::ProxyAnimation(Animation<double> animation) {
    {
        _parent = animation;
        if (_parent == nullptr) {
            _status = AnimationStatus.dismissed;
            _value = 0.0;
        }
    }
}

Animation<double> ProxyAnimation::parent() {
    return _parent;
}

void ProxyAnimation::parent(Animation<double> value) {
    if (value == _parent) {
        return;
    }
    if (_parent != nullptr) {
        _status = _parent!.status;
        _value = _parent!.value;
        if (isListening) {
            didStopListening();
        }
    }
    _parent = value;
    if (_parent != nullptr) {
        if (isListening) {
            didStartListening();
        }
        if (_value != _parent!.value) {
            notifyListeners();
        }
        if (_status != _parent!.status) {
            notifyStatusListeners(_parent!.status);
        }
        _status = nullptr;
        _value = nullptr;
    }
}

void ProxyAnimation::didStartListening() {
    if (_parent != nullptr) {
        _parent!.addListener(notifyListeners);
        _parent!.addStatusListener(notifyStatusListeners);
    }
}

void ProxyAnimation::didStopListening() {
    if (_parent != nullptr) {
        _parent!.removeListener(notifyListeners);
        _parent!.removeStatusListener(notifyStatusListeners);
    }
}

AnimationStatus ProxyAnimation::status() {
    return _parent != nullptr? _parent!.status : _status!;
}

double ProxyAnimation::value() {
    return _parent != nullptr? _parent!.value : _value!;
}

String ProxyAnimation::toString() {
    if (parent == nullptr) {
        return "${objectRuntimeType(this, 'ProxyAnimation')}(null; ${super.toStringDetails()} ${value.toStringAsFixed(3)})";
    }
    return "$parent\u27A9${objectRuntimeType(this, 'ProxyAnimation')}";
}

ReverseAnimation::ReverseAnimation(Animation<double> parent) {
    {
        assert(parent != nullptr);
    }
}

void ReverseAnimation::addListener(VoidCallback listener) {
    didRegisterListener();
    parent.addListener(listener);
}

void ReverseAnimation::removeListener(VoidCallback listener) {
    parent.removeListener(listener);
    didUnregisterListener();
}

void ReverseAnimation::didStartListening() {
    parent.addStatusListener(_statusChangeHandler);
}

void ReverseAnimation::didStopListening() {
    parent.removeStatusListener(_statusChangeHandler);
}

AnimationStatus ReverseAnimation::status() {
    return _reverseStatus(parent.status);
}

double ReverseAnimation::value() {
    return 1.0 - parent.value;
}

String ReverseAnimation::toString() {
    return "$parent\u27AA${objectRuntimeType(this, 'ReverseAnimation')}";
}

void ReverseAnimation::_statusChangeHandler(AnimationStatus status) {
    notifyStatusListeners(_reverseStatus(status));
}

AnimationStatus ReverseAnimation::_reverseStatus(AnimationStatus status) {
    assert(status != nullptr);
    ;
}

CurvedAnimation::CurvedAnimation(Curve curve, Animation<double> parent, Curve reverseCurve) {
    {
        assert(parent != nullptr);
        assert(curve != nullptr);
    }
    {
        _updateCurveDirection(parent.status);
        parent.addStatusListener(_updateCurveDirection);
    }
}

void CurvedAnimation::dispose() {
    isDisposed = true;
    parent.removeStatusListener(_updateCurveDirection);
}

double CurvedAnimation::value() {
    Curve activeCurve = _useForwardCurve? curve : reverseCurve;
    double t = parent.value;
    if (activeCurve == nullptr) {
        return t;
    }
    if (t == 0.0 || t == 1.0) {
        assert(());
        return t;
    }
    return activeCurve.transform(t);
}

String CurvedAnimation::toString() {
    if (reverseCurve == nullptr) {
        return "$parent\u27A9$curve";
    }
    if (_useForwardCurve) {
        return "$parent\u27A9$curve\u2092\u2099/$reverseCurve";
    }
    return "$parent\u27A9$curve/$reverseCurve\u2092\u2099";
}

void CurvedAnimation::_updateCurveDirection(AnimationStatus status) {
    ;
}

bool CurvedAnimation::_useForwardCurve() {
    return reverseCurve == nullptr || (_curveDirection ?? parent.status) != AnimationStatus.reverse;
}

TrainHoppingAnimation::TrainHoppingAnimation(Animation<double> _currentTrain, Animation<double> _nextTrain, VoidCallback onSwitchedTrain) {
    {
        assert(_currentTrain != nullptr);
    }
    {
        if (_nextTrain != nullptr) {
            if (_currentTrain!.value == _nextTrain!.value) {
                _currentTrain = _nextTrain;
                _nextTrain = nullptr;
            } else             {
                if (_currentTrain!.value > _nextTrain!.value) {
                _mode = _TrainHoppingMode.maximize;
            } else {
                assert(_currentTrain!.value < _nextTrain!.value);
                _mode = _TrainHoppingMode.minimize;
            }
;
            }        }
        _currentTrain!.addStatusListener(_statusChangeHandler);
        _currentTrain!.addListener(_valueChangeHandler);
        _nextTrain?.addListener(_valueChangeHandler);
        assert(_mode != nullptr || _nextTrain == nullptr);
    }
}

Animation<double> TrainHoppingAnimation::currentTrain() {
    return _currentTrain;
}

AnimationStatus TrainHoppingAnimation::status() {
    return _currentTrain!.status;
}

double TrainHoppingAnimation::value() {
    return _currentTrain!.value;
}

void TrainHoppingAnimation::dispose() {
    assert(_currentTrain != nullptr);
    _currentTrain!.removeStatusListener(_statusChangeHandler);
    _currentTrain!.removeListener(_valueChangeHandler);
    _currentTrain = nullptr;
    _nextTrain?.removeListener(_valueChangeHandler);
    _nextTrain = nullptr;
    clearListeners();
    clearStatusListeners();
    super.dispose();
}

String TrainHoppingAnimation::toString() {
    if (_nextTrain != nullptr) {
        return "$currentTrain\u27A9${objectRuntimeType(this, 'TrainHoppingAnimation')}(next: $_nextTrain)";
    }
    return "$currentTrain\u27A9${objectRuntimeType(this, 'TrainHoppingAnimation')}(no next)";
}

void TrainHoppingAnimation::_statusChangeHandler(AnimationStatus status) {
    assert(_currentTrain != nullptr);
    if (status != _lastStatus) {
        notifyListeners();
        _lastStatus = status;
    }
    assert(_lastStatus != nullptr);
}

void TrainHoppingAnimation::_valueChangeHandler() {
    assert(_currentTrain != nullptr);
    bool hop = false;
    if (_nextTrain != nullptr) {
        assert(_mode != nullptr);
        ;
        if (hop) {
            ;
            _currentTrain = _nextTrain;
            _nextTrain = nullptr;
            _currentTrain!.addStatusListener(_statusChangeHandler);
            _statusChangeHandler(_currentTrain!.status);
        }
    }
    double newValue = value;
    if (newValue != _lastValue) {
        notifyListeners();
        _lastValue = newValue;
    }
    assert(_lastValue != nullptr);
    if (hop && onSwitchedTrain != nullptr) {
        onSwitchedTrain!();
    }
}

CompoundAnimation::CompoundAnimation(Animation<T> first, Animation<T> next) {
    {
        assert(first != nullptr);
        assert(next != nullptr);
    }
}

void CompoundAnimation::didStartListening() {
    first.addListener(_maybeNotifyListeners);
    first.addStatusListener(_maybeNotifyStatusListeners);
    next.addListener(_maybeNotifyListeners);
    next.addStatusListener(_maybeNotifyStatusListeners);
}

void CompoundAnimation::didStopListening() {
    first.removeListener(_maybeNotifyListeners);
    first.removeStatusListener(_maybeNotifyStatusListeners);
    next.removeListener(_maybeNotifyListeners);
    next.removeStatusListener(_maybeNotifyStatusListeners);
}

AnimationStatus CompoundAnimation::status() {
    if (next.status == AnimationStatus.forward || next.status == AnimationStatus.reverse) {
        return next.status;
    }
    return first.status;
}

String CompoundAnimation::toString() {
    return "${objectRuntimeType(this, 'CompoundAnimation')}($first, $next)";
}

void CompoundAnimation::_maybeNotifyStatusListeners(AnimationStatus _) {
    if (status != _lastStatus) {
        _lastStatus = status;
        notifyStatusListeners(status);
    }
}

void CompoundAnimation::_maybeNotifyListeners() {
    if (value != _lastValue) {
        _lastValue = value;
        notifyListeners();
    }
}

AnimationMean::AnimationMean(Animation<double> left, Animation<double> right) {
    {
        super(left, right);
    }
}

double AnimationMean::value() {
    return (first.value + next.value) / 2.0;
}

AnimationMax::AnimationMax(Animation<T> first, Animation<T> next) {
    {
        super(first, next);
    }
}

T AnimationMax::value() {
    return math.max(first.value, next.value);
}

AnimationMin::AnimationMin(Animation<T> first, Animation<T> next) {
    {
        super(first, next);
    }
}

T AnimationMin::value() {
    return math.min(first.value, next.value);
}
