#include "animation_controller.hpp"
AnimationController::AnimationController(AnimationBehavior animationBehavior, String debugLabel, Duration duration, double lowerBound, Duration reverseDuration, double upperBound, double value, TickerProvider vsync) {
    {
        assert(lowerBound != nullptr);
        assert(upperBound != nullptr);
        assert(upperBound >= lowerBound);
        assert(vsync != nullptr);
        _direction = _AnimationDirection.forward;
    }
    {
        _ticker = vsync.createTicker(_tick);
        _internalSetValue(value ?? lowerBound);
    }
}

void AnimationController::unbounded(AnimationBehavior animationBehavior, String debugLabel, Duration duration, Duration reverseDuration, double value, TickerProvider vsync) {
    _ticker = vsync.createTicker(_tick);
    _internalSetValue(value);
}

Animation<double> AnimationController::view() {
    return this;
}

void AnimationController::resync(TickerProvider vsync) {
    Ticker oldTicker = _ticker!;
    _ticker = vsync.createTicker(_tick);
    _ticker!.absorbTicker(oldTicker);
}

double AnimationController::value() {
    return _value;
}

void AnimationController::value(double newValue) {
    assert(newValue != nullptr);
    stop();
    _internalSetValue(newValue);
    notifyListeners();
    _checkStatusChanged();
}

void AnimationController::reset() {
    value = lowerBound;
}

double AnimationController::velocity() {
    if (!isAnimating) {
        return 0.0;
    }
    return _simulation!.dx(lastElapsedDuration!.inMicroseconds.toDouble() / Duration.microsecondsPerSecond);
}

Duration AnimationController::lastElapsedDuration() {
    return _lastElapsedDuration;
}

bool AnimationController::isAnimating() {
    return _ticker != nullptr && _ticker!.isActive;
}

AnimationStatus AnimationController::status() {
    return _status;
}

TickerFuture AnimationController::forward(double from) {
    assert(());
    assert(_ticker != nullptr, "AnimationController.forward() called after AnimationController.dispose()\nAnimationController methods should not be used after calling dispose.");
    _direction = _AnimationDirection.forward;
    if (from != nullptr) {
        value = from;
    }
    return _animateToInternal(upperBound);
}

TickerFuture AnimationController::reverse(double from) {
    assert(());
    assert(_ticker != nullptr, "AnimationController.reverse() called after AnimationController.dispose()\nAnimationController methods should not be used after calling dispose.");
    _direction = _AnimationDirection.reverse;
    if (from != nullptr) {
        value = from;
    }
    return _animateToInternal(lowerBound);
}

TickerFuture AnimationController::animateTo(Curve curve, Duration duration, double target) {
    assert(());
    assert(_ticker != nullptr, "AnimationController.animateTo() called after AnimationController.dispose()\nAnimationController methods should not be used after calling dispose.");
    _direction = _AnimationDirection.forward;
    return _animateToInternal(targetduration, curve);
}

TickerFuture AnimationController::animateBack(Curve curve, Duration duration, double target) {
    assert(());
    assert(_ticker != nullptr, "AnimationController.animateBack() called after AnimationController.dispose()\nAnimationController methods should not be used after calling dispose.");
    _direction = _AnimationDirection.reverse;
    return _animateToInternal(targetduration, curve);
}

TickerFuture AnimationController::repeat(double max, double min, Duration period, bool reverse) {
    min = lowerBound;
    max = upperBound;
    period = duration;
    assert(());
    assert(max >= min);
    assert(max <= upperBound && min >= lowerBound);
    assert(reverse != nullptr);
    stop();
    return _startSimulation(_RepeatingSimulation(_value, min, max, reverse, period!, _directionSetter));
}

TickerFuture AnimationController::fling(AnimationBehavior animationBehavior, SpringDescription springDescription, double velocity) {
    springDescription = _kFlingSpringDescription;
    _direction =  < 0.0? _AnimationDirection.reverse : _AnimationDirection.forward;
    double target =  < 0.0? lowerBound - _kFlingTolerance.distance : upperBound + _kFlingTolerance.distance;
    double scale = 1.0;
    AnimationBehavior behavior = animationBehavior ?? this.animationBehavior;
    if (SemanticsBinding.instance.disableAnimations) {
        ;
    }
    SpringSimulation simulation = ;
    assert(simulation.type != SpringType.underDamped, "The resulting spring simulation is of type SpringType.underDamped.\nThis can lead to unexpected look of the animation, please adjust the springDescription parameter");
    stop();
    return _startSimulation(simulation);
}

TickerFuture AnimationController::animateWith(Simulation simulation) {
    assert(_ticker != nullptr, "AnimationController.animateWith() called after AnimationController.dispose()\nAnimationController methods should not be used after calling dispose.");
    stop();
    _direction = _AnimationDirection.forward;
    return _startSimulation(simulation);
}

void AnimationController::stop(bool canceled) {
    assert(_ticker != nullptr, "AnimationController.stop() called after AnimationController.dispose()\nAnimationController methods should not be used after calling dispose.");
    _simulation = nullptr;
    _lastElapsedDuration = nullptr;
    _ticker!.stop(canceled);
}

void AnimationController::dispose() {
    assert(());
    _ticker!.dispose();
    _ticker = nullptr;
    clearStatusListeners();
    clearListeners();
    super.dispose();
}

String AnimationController::toStringDetails() {
    String paused = isAnimating? "" : "; paused";
    String ticker = _ticker == nullptr? "; DISPOSED" : (_ticker!.muted? "; silenced" : "");
    String label = debugLabel == nullptr? "" : "; for $debugLabel";
    String more = "${super.toStringDetails()} ${value.toStringAsFixed(3)}";
    return "$more$paused$ticker$label";
}

void AnimationController::_internalSetValue(double newValue) {
    _value = clampDouble(newValue, lowerBound, upperBound);
    if (_value == lowerBound) {
        _status = AnimationStatus.dismissed;
    } else     {
        if (_value == upperBound) {
        _status = AnimationStatus.completed;
    } else {
        _status = (_direction == _AnimationDirection.forward)? AnimationStatus.forward : AnimationStatus.reverse;
    }
;
    }}

TickerFuture AnimationController::_animateToInternal(Curve curve, Duration duration, double target) {
    double scale = 1.0;
    if (SemanticsBinding.instance.disableAnimations) {
        ;
    }
    Duration simulationDuration = duration;
    if (simulationDuration == nullptr) {
        assert(!(this.duration == nullptr && _direction == _AnimationDirection.forward));
        assert(!(this.duration == nullptr && _direction == _AnimationDirection.reverse && reverseDuration == nullptr));
        double range = upperBound - lowerBound;
        double remainingFraction = range.isFinite? (target - _value).abs() / range : 1.0;
        Duration directionDuration = (_direction == _AnimationDirection.reverse && reverseDuration != nullptr)? reverseDuration! : this.duration!;
        simulationDuration = directionDuration * remainingFraction;
    } else     {
        if (target == value) {
        simulationDuration = Duration.zero;
    }
;
    }    stop();
    if (simulationDuration == Duration.zero) {
        if (value != target) {
            _value = clampDouble(target, lowerBound, upperBound);
            notifyListeners();
        }
        _status = (_direction == _AnimationDirection.forward)? AnimationStatus.completed : AnimationStatus.dismissed;
        _checkStatusChanged();
        return TickerFuture.complete();
    }
    assert(simulationDuration > Duration.zero);
    assert(!isAnimating);
    return _startSimulation(_InterpolationSimulation(_value, target, simulationDuration, curve, scale));
}

void AnimationController::_directionSetter(_AnimationDirection direction) {
    _direction = direction;
    _status = (_direction == _AnimationDirection.forward)? AnimationStatus.forward : AnimationStatus.reverse;
    _checkStatusChanged();
}

TickerFuture AnimationController::_startSimulation(Simulation simulation) {
    assert(simulation != nullptr);
    assert(!isAnimating);
    _simulation = simulation;
    _lastElapsedDuration = Duration.zero;
    _value = clampDouble(simulation.x(0.0), lowerBound, upperBound);
    TickerFuture result = _ticker!.start();
    _status = (_direction == _AnimationDirection.forward)? AnimationStatus.forward : AnimationStatus.reverse;
    _checkStatusChanged();
    return result;
}

void AnimationController::_checkStatusChanged() {
    AnimationStatus newStatus = status;
    if (_lastReportedStatus != newStatus) {
        _lastReportedStatus = newStatus;
        notifyStatusListeners(newStatus);
    }
}

void AnimationController::_tick(Duration elapsed) {
    _lastElapsedDuration = elapsed;
    double elapsedInSeconds = elapsed.inMicroseconds.toDouble() / Duration.microsecondsPerSecond;
    assert(elapsedInSeconds >= 0.0);
    _value = clampDouble(_simulation!.x(elapsedInSeconds), lowerBound, upperBound);
    if (_simulation!.isDone(elapsedInSeconds)) {
        _status = (_direction == _AnimationDirection.forward)? AnimationStatus.completed : AnimationStatus.dismissed;
        stop(false);
    }
    notifyListeners();
    _checkStatusChanged();
}

double _InterpolationSimulation::x(double timeInSeconds) {
    double t = clampDouble(timeInSeconds / _durationInSeconds, 0.0, 1.0);
    if (t == 0.0) {
        return _begin;
    } else     {
        if (t == 1.0) {
        return _end;
    } else {
        return _begin + (_end - _begin) * _curve.transform(t);
    }
;
    }}

double _InterpolationSimulation::dx(double timeInSeconds) {
    double epsilon = tolerance.time;
    return (x(timeInSeconds + epsilon) - x(timeInSeconds - epsilon)) / (2 * epsilon);
}

bool _InterpolationSimulation::isDone(double timeInSeconds) {
    return timeInSeconds > _durationInSeconds;
}

_InterpolationSimulation::_InterpolationSimulation(double _begin, Curve _curve, double _end, Duration duration, double scale) {
    {
        assert(_begin != nullptr);
        assert(_end != nullptr);
        assert(duration != nullptr && duration.inMicroseconds > 0);
        _durationInSeconds = (duration.inMicroseconds * scale) / Duration.microsecondsPerSecond;
    }
}

double _RepeatingSimulation::x(double timeInSeconds) {
    assert(timeInSeconds >= 0.0);
    double totalTimeInSeconds = timeInSeconds + _initialT;
    double t = (totalTimeInSeconds / _periodInSeconds) % 1.0;
    bool isPlayingReverse = (totalTimeInSeconds ~/ _periodInSeconds).isOdd;
    if (reverse && isPlayingReverse) {
        directionSetter(_AnimationDirection.reverse);
        return ui.lerpDouble(max, min, t)!;
    } else {
        directionSetter(_AnimationDirection.forward);
        return ui.lerpDouble(min, max, t)!;
    }
}

double _RepeatingSimulation::dx(double timeInSeconds) {
    return (max - min) / _periodInSeconds;
}

bool _RepeatingSimulation::isDone(double timeInSeconds) {
    return false;
}

_RepeatingSimulation::_RepeatingSimulation(_DirectionSetter directionSetter, double initialValue, double max, double min, Duration period, bool reverse) {
    {
        _periodInSeconds = period.inMicroseconds / Duration.microsecondsPerSecond;
        _initialT = (max == min)? 0.0 : (initialValue / (max - min)) * (period.inMicroseconds / Duration.microsecondsPerSecond);
    }
    {
        assert(_periodInSeconds > 0.0);
        assert(_initialT >= 0.0);
    }
}
