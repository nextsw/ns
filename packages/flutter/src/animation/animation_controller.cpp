#include "animation_controller.hpp"
AnimationControllerCls::AnimationControllerCls(AnimationBehavior animationBehavior, String debugLabel, Duration duration, double lowerBound, Duration reverseDuration, double upperBound, double value, TickerProvider vsync) {
    {
        assert(lowerBound != nullptr);
        assert(upperBound != nullptr);
        assert(upperBound >= lowerBound);
        assert(vsync != nullptr);
        _direction = _AnimationDirectionCls::forward;
    }
    {
        _ticker = vsync->createTicker(_tick);
        _internalSetValue(value or lowerBound);
    }
}

void AnimationControllerCls::unbounded(AnimationBehavior animationBehavior, String debugLabel, Duration duration, Duration reverseDuration, double value, TickerProvider vsync) {
    _ticker = vsync->createTicker(_tick);
    _internalSetValue(value);
}

Animation<double> AnimationControllerCls::view() {
    return this;
}

void AnimationControllerCls::resync(TickerProvider vsync) {
    Ticker oldTicker = _ticker!;
    _ticker = vsync->createTicker(_tick);
    _ticker!->absorbTicker(oldTicker);
}

double AnimationControllerCls::value() {
    return _value;
}

void AnimationControllerCls::value(double newValue) {
    assert(newValue != nullptr);
    stop();
    _internalSetValue(newValue);
    notifyListeners();
    _checkStatusChanged();
}

void AnimationControllerCls::reset() {
    value = lowerBound;
}

double AnimationControllerCls::velocity() {
    if (!isAnimating()) {
        return 0.0;
    }
    return _simulation!->dx(lastElapsedDuration()!->inMicroseconds()->toDouble() / DurationCls::microsecondsPerSecond);
}

Duration AnimationControllerCls::lastElapsedDuration() {
    return _lastElapsedDuration;
}

bool AnimationControllerCls::isAnimating() {
    return _ticker != nullptr && _ticker!->isActive();
}

AnimationStatus AnimationControllerCls::status() {
    return _status;
}

TickerFuture AnimationControllerCls::forward(double from) {
    assert([=] () {
        if (duration == nullptr) {
            ;
        }
        return true;
    }());
    assert(_ticker != nullptr, __s("AnimationController.forward() called after AnimationController.dispose()\nAnimationController methods should not be used after calling dispose."));
    _direction = _AnimationDirectionCls::forward;
    if (from != nullptr) {
        value = from;
    }
    return _animateToInternal(upperBound);
}

TickerFuture AnimationControllerCls::reverse(double from) {
    assert([=] () {
        if (duration == nullptr && reverseDuration == nullptr) {
            ;
        }
        return true;
    }());
    assert(_ticker != nullptr, __s("AnimationController.reverse() called after AnimationController.dispose()\nAnimationController methods should not be used after calling dispose."));
    _direction = _AnimationDirectionCls::reverse;
    if (from != nullptr) {
        value = from;
    }
    return _animateToInternal(lowerBound);
}

TickerFuture AnimationControllerCls::animateTo(Curve curve, Duration duration, double target) {
    assert([=] () {
        if (this->duration == nullptr && duration == nullptr) {
            ;
        }
        return true;
    }());
    assert(_ticker != nullptr, __s("AnimationController.animateTo() called after AnimationController.dispose()\nAnimationController methods should not be used after calling dispose."));
    _direction = _AnimationDirectionCls::forward;
    return _animateToInternal(targetduration, curve);
}

TickerFuture AnimationControllerCls::animateBack(Curve curve, Duration duration, double target) {
    assert([=] () {
        if (this->duration == nullptr && reverseDuration == nullptr && duration == nullptr) {
            ;
        }
        return true;
    }());
    assert(_ticker != nullptr, __s("AnimationController.animateBack() called after AnimationController.dispose()\nAnimationController methods should not be used after calling dispose."));
    _direction = _AnimationDirectionCls::reverse;
    return _animateToInternal(targetduration, curve);
}

TickerFuture AnimationControllerCls::repeat(double max, double min, Duration period, bool reverse) {
    min = lowerBound;
    max = upperBound;
    period = duration;
    assert([=] () {
        if (period == nullptr) {
            ;
        }
        return true;
    }());
    assert(max >= min);
    assert(max <= upperBound && min >= lowerBound);
    assert(reverse != nullptr);
    stop();
    return _startSimulation(make<_RepeatingSimulationCls>(_value, min, max, reverse, period!, _directionSetter));
}

TickerFuture AnimationControllerCls::fling(AnimationBehavior animationBehavior, SpringDescription springDescription, double velocity) {
    springDescription = _kFlingSpringDescription;
    _direction =  < 0.0? _AnimationDirectionCls::reverse : _AnimationDirectionCls::forward;
    double target =  < 0.0? lowerBound - _kFlingTolerance->distance : upperBound + _kFlingTolerance->distance;
    double scale = 1.0;
    AnimationBehavior behavior = animationBehavior or this->animationBehavior;
    if (SemanticsBindingCls::instance->disableAnimations) {
        ;
    }
    auto _c1 = make<SpringSimulationCls>(springDescription, value, target, velocity * scale);_c1.tolerance = _kFlingTolerance;SpringSimulation simulation = _c1;
    assert(simulation->type != SpringTypeCls::underDamped, __s("The resulting spring simulation is of type SpringType.underDamped.\nThis can lead to unexpected look of the animation, please adjust the springDescription parameter"));
    stop();
    return _startSimulation(simulation);
}

TickerFuture AnimationControllerCls::animateWith(Simulation simulation) {
    assert(_ticker != nullptr, __s("AnimationController.animateWith() called after AnimationController.dispose()\nAnimationController methods should not be used after calling dispose."));
    stop();
    _direction = _AnimationDirectionCls::forward;
    return _startSimulation(simulation);
}

void AnimationControllerCls::stop(bool canceled) {
    assert(_ticker != nullptr, __s("AnimationController.stop() called after AnimationController.dispose()\nAnimationController methods should not be used after calling dispose."));
    _simulation = nullptr;
    _lastElapsedDuration = nullptr;
    _ticker!->stop(canceled);
}

void AnimationControllerCls::dispose() {
    assert([=] () {
        if (_ticker == nullptr) {
            ;
        }
        return true;
    }());
    _ticker!->dispose();
    _ticker = nullptr;
    clearStatusListeners();
    clearListeners();
    super->dispose();
}

String AnimationControllerCls::toStringDetails() {
    String paused = isAnimating()? __s("") : __s("; paused");
    String ticker = _ticker == nullptr? __s("; DISPOSED") : (_ticker!->muted()? __s("; silenced") : __s(""));
    String label = debugLabel == nullptr? __s("") : __s("; for $debugLabel");
    String more = __s("${super.toStringDetails()} ${value.toStringAsFixed(3)}");
    return __s("$more$paused$ticker$label");
}

void AnimationControllerCls::_internalSetValue(double newValue) {
    _value = clampDouble(newValue, lowerBound, upperBound);
    if (_value == lowerBound) {
        _status = AnimationStatusCls::dismissed;
    } else     {
        if (_value == upperBound) {
        _status = AnimationStatusCls::completed;
    } else {
        _status = (_direction == _AnimationDirectionCls::forward)? AnimationStatusCls::forward : AnimationStatusCls::reverse;
    }
;
    }}

TickerFuture AnimationControllerCls::_animateToInternal(Curve curve, Duration duration, double target) {
    double scale = 1.0;
    if (SemanticsBindingCls::instance->disableAnimations) {
        ;
    }
    Duration simulationDuration = duration;
    if (simulationDuration == nullptr) {
        assert(!(this->duration == nullptr && _direction == _AnimationDirectionCls::forward));
        assert(!(this->duration == nullptr && _direction == _AnimationDirectionCls::reverse && reverseDuration == nullptr));
        double range = upperBound - lowerBound;
        double remainingFraction = range->isFinite? (target - _value)->abs() / range : 1.0;
        Duration directionDuration = (_direction == _AnimationDirectionCls::reverse && reverseDuration != nullptr)? reverseDuration! : this->duration!;
        simulationDuration = directionDuration * remainingFraction;
    } else     {
        if (target == value) {
        simulationDuration = DurationCls::zero;
    }
;
    }    stop();
    if (simulationDuration == DurationCls::zero) {
        if (value != target) {
            _value = clampDouble(target, lowerBound, upperBound);
            notifyListeners();
        }
        _status = (_direction == _AnimationDirectionCls::forward)? AnimationStatusCls::completed : AnimationStatusCls::dismissed;
        _checkStatusChanged();
        return TickerFutureCls->complete();
    }
    assert(simulationDuration > DurationCls::zero);
    assert(!isAnimating());
    return _startSimulation(make<_InterpolationSimulationCls>(_value, target, simulationDuration, curve, scale));
}

void AnimationControllerCls::_directionSetter(_AnimationDirection direction) {
    _direction = direction;
    _status = (_direction == _AnimationDirectionCls::forward)? AnimationStatusCls::forward : AnimationStatusCls::reverse;
    _checkStatusChanged();
}

TickerFuture AnimationControllerCls::_startSimulation(Simulation simulation) {
    assert(simulation != nullptr);
    assert(!isAnimating());
    _simulation = simulation;
    _lastElapsedDuration = DurationCls::zero;
    _value = clampDouble(simulation->x(0.0), lowerBound, upperBound);
    TickerFuture result = _ticker!->start();
    _status = (_direction == _AnimationDirectionCls::forward)? AnimationStatusCls::forward : AnimationStatusCls::reverse;
    _checkStatusChanged();
    return result;
}

void AnimationControllerCls::_checkStatusChanged() {
    AnimationStatus newStatus = status;
    if (_lastReportedStatus != newStatus) {
        _lastReportedStatus = newStatus;
        notifyStatusListeners(newStatus);
    }
}

void AnimationControllerCls::_tick(Duration elapsed) {
    _lastElapsedDuration = elapsed;
    double elapsedInSeconds = elapsed->inMicroseconds()->toDouble() / DurationCls::microsecondsPerSecond;
    assert(elapsedInSeconds >= 0.0);
    _value = clampDouble(_simulation!->x(elapsedInSeconds), lowerBound, upperBound);
    if (_simulation!->isDone(elapsedInSeconds)) {
        _status = (_direction == _AnimationDirectionCls::forward)? AnimationStatusCls::completed : AnimationStatusCls::dismissed;
        stop(false);
    }
    notifyListeners();
    _checkStatusChanged();
}

double _InterpolationSimulationCls::x(double timeInSeconds) {
    double t = clampDouble(timeInSeconds / _durationInSeconds, 0.0, 1.0);
    if (t == 0.0) {
        return _begin;
    } else     {
        if (t == 1.0) {
        return _end;
    } else {
        return _begin + (_end - _begin) * _curve->transform(t);
    }
;
    }}

double _InterpolationSimulationCls::dx(double timeInSeconds) {
    double epsilon = tolerance->time;
    return (x(timeInSeconds + epsilon) - x(timeInSeconds - epsilon)) / (2 * epsilon);
}

bool _InterpolationSimulationCls::isDone(double timeInSeconds) {
    return timeInSeconds > _durationInSeconds;
}

_InterpolationSimulationCls::_InterpolationSimulationCls(double _begin, Curve _curve, double _end, Duration duration, double scale) {
    {
        assert(_begin != nullptr);
        assert(_end != nullptr);
        assert(duration != nullptr && duration->inMicroseconds() > 0);
        _durationInSeconds = (duration->inMicroseconds() * scale) / DurationCls::microsecondsPerSecond;
    }
}

double _RepeatingSimulationCls::x(double timeInSeconds) {
    assert(timeInSeconds >= 0.0);
    double totalTimeInSeconds = timeInSeconds + _initialT;
    double t = (totalTimeInSeconds / _periodInSeconds) % 1.0;
    bool isPlayingReverse = (totalTimeInSeconds ~/ _periodInSeconds)->isOdd;
    if (reverse && isPlayingReverse) {
        directionSetter(_AnimationDirectionCls::reverse);
        return ui->lerpDouble(max, min, t)!;
    } else {
        directionSetter(_AnimationDirectionCls::forward);
        return ui->lerpDouble(min, max, t)!;
    }
}

double _RepeatingSimulationCls::dx(double timeInSeconds) {
    return (max - min) / _periodInSeconds;
}

bool _RepeatingSimulationCls::isDone(double timeInSeconds) {
    return false;
}

_RepeatingSimulationCls::_RepeatingSimulationCls(_DirectionSetter directionSetter, double initialValue, double max, double min, Duration period, bool reverse) {
    {
        _periodInSeconds = period->inMicroseconds() / DurationCls::microsecondsPerSecond;
        _initialT = (max == min)? 0.0 : (initialValue / (max - min)) * (period->inMicroseconds() / DurationCls::microsecondsPerSecond);
    }
    {
        assert(_periodInSeconds > 0.0);
        assert(_initialT >= 0.0);
    }
}
