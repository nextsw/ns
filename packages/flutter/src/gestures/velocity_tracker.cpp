#include "velocity_tracker.hpp"
VelocityCls::VelocityCls(Offset pixelsPerSecond) {
    {
        assert(pixelsPerSecond != nullptr);
    }
}

Velocity VelocityCls::-() {
    return make<VelocityCls>(-pixelsPerSecond);
}

Velocity VelocityCls::-(Velocity other) {
    return make<VelocityCls>(pixelsPerSecond - other->pixelsPerSecond);
}

Velocity VelocityCls::+(Velocity other) {
    return make<VelocityCls>(pixelsPerSecond + other->pixelsPerSecond);
}

Velocity VelocityCls::clampMagnitude(double maxValue, double minValue) {
    assert(minValue != nullptr && minValue >= 0.0);
    assert(maxValue != nullptr && maxValue >= 0.0 && maxValue >= minValue);
    double valueSquared = pixelsPerSecond->distanceSquared();
    if (valueSquared > maxValue * maxValue) {
        return make<VelocityCls>((pixelsPerSecond / pixelsPerSecond->distance()) * maxValue);
    }
    if ( < minValue * minValue) {
        return make<VelocityCls>((pixelsPerSecond / pixelsPerSecond->distance()) * minValue);
    }
    return this;
}

bool VelocityCls::==(Object other) {
    return is<Velocity>(other) && other->pixelsPerSecond == pixelsPerSecond;
}

int VelocityCls::hashCode() {
    return pixelsPerSecond->hashCode();
}

String VelocityCls::toString() {
    return __s("Velocity(${pixelsPerSecond.dx.toStringAsFixed(1)}, ${pixelsPerSecond.dy.toStringAsFixed(1)})");
}

VelocityEstimateCls::VelocityEstimateCls(double confidence, Duration duration, Offset offset, Offset pixelsPerSecond) {
    {
        assert(pixelsPerSecond != nullptr);
        assert(confidence != nullptr);
        assert(duration != nullptr);
        assert(offset != nullptr);
    }
}

String VelocityEstimateCls::toString() {
    return __s("VelocityEstimate(${pixelsPerSecond.dx.toStringAsFixed(1)}, ${pixelsPerSecond.dy.toStringAsFixed(1)}; offset: $offset, duration: $duration, confidence: ${confidence.toStringAsFixed(1)})");
}

String _PointAtTimeCls::toString() {
    return __s("_PointAtTime($point at $time)");
}

_PointAtTimeCls::_PointAtTimeCls(Offset point, Duration time) {
    {
        assert(point != nullptr);
        assert(time != nullptr);
    }
}

void VelocityTrackerCls::addPosition(Offset position, Duration time) {
    _index = 1;
    if (_index == _historySize) {
        _index = 0;
    }
    _samples[_index] = make<_PointAtTimeCls>(position, time);
}

VelocityEstimate VelocityTrackerCls::getVelocityEstimate() {
    List<double> x = makeList();
    List<double> y = makeList();
    List<double> w = makeList();
    List<double> time = makeList();
    int sampleCount = 0;
    int index = _index;
    _PointAtTime newestSample = _samples[index];
    if (newestSample == nullptr) {
        return nullptr;
    }
    _PointAtTime previousSample = newestSample;
    _PointAtTime oldestSample = newestSample;
    do {
        _PointAtTime sample = _samples[index];
        if (sample == nullptr) {
            break;
        }
        double age = (newestSample->time - sample->time)->inMicroseconds->toDouble() / 1000;
        double delta = (sample->time - previousSample->time)->inMicroseconds->abs()->toDouble() / 1000;
        previousSample = sample;
        if (age > _horizonMilliseconds || delta > _assumePointerMoveStoppedMilliseconds) {
            break;
        }
        oldestSample = sample;
        Offset position = sample->point;
        x->add(position->dx());
        y->add(position->dy());
        w->add(1.0);
        time->add(-age);
        index = (index == 0? _historySize : index) - 1;
        sampleCount = 1;
    } while ( < _historySize);
    if (sampleCount >= _minSampleSize) {
        LeastSquaresSolver xSolver = make<LeastSquaresSolverCls>(time, x, w);
        PolynomialFit xFit = xSolver->solve(2);
        if (xFit != nullptr) {
            LeastSquaresSolver ySolver = make<LeastSquaresSolverCls>(time, y, w);
            PolynomialFit yFit = ySolver->solve(2);
            if (yFit != nullptr) {
                return make<VelocityEstimateCls>(make<OffsetCls>(xFit->coefficients[1] * 1000, yFit->coefficients[1] * 1000), xFit->confidence * yFit->confidence, newestSample->time - oldestSample->time, newestSample->point - oldestSample->point);
            }
        }
    }
    return make<VelocityEstimateCls>(OffsetCls::zero, 1.0, newestSample->time - oldestSample->time, newestSample->point - oldestSample->point);
}

Velocity VelocityTrackerCls::getVelocity() {
    VelocityEstimate estimate = getVelocityEstimate();
    if (estimate == nullptr || estimate->pixelsPerSecond == OffsetCls::zero) {
        return VelocityCls::zero;
    }
    return make<VelocityCls>(estimate->pixelsPerSecond);
}

IOSScrollViewFlingVelocityTrackerCls::IOSScrollViewFlingVelocityTrackerCls(Unknown kind) {
    {
        super->withKind();
    }
}

void IOSScrollViewFlingVelocityTrackerCls::addPosition(Offset position, Duration time) {
    assert([=] () {
        _PointAtTime previousPoint = _touchSamples[_index];
        if (previousPoint == nullptr || previousPoint->time <= time) {
            return true;
        }
        throw make<FlutterErrorCls>(__s("The position being added ($position) has a smaller timestamp ($time) than its predecessor: $previousPoint."));
    }());
    _index = (_index + 1) % _sampleSize;
    _touchSamples[_index] = make<_PointAtTimeCls>(position, time);
}

VelocityEstimate IOSScrollViewFlingVelocityTrackerCls::getVelocityEstimate() {
    Offset estimatedVelocity = _previousVelocityAt(-2) * 0.6 + _previousVelocityAt(-1) * 0.35 + _previousVelocityAt(0) * 0.05;
    _PointAtTime newestSample = _touchSamples[_index];
    _PointAtTime oldestNonNullSample;
    for (; i <= _sampleSize; i = 1) {
        oldestNonNullSample = _touchSamples[(_index + i) % _sampleSize];
        if (oldestNonNullSample != nullptr) {
            break;
        }
    }
    if (oldestNonNullSample == nullptr || newestSample == nullptr) {
        assert(false, __s("There must be at least 1 point in _touchSamples: $_touchSamples"));
        return make<VelocityEstimateCls>(OffsetCls::zero, 0.0, DurationCls::zero, OffsetCls::zero);
    } else {
        return make<VelocityEstimateCls>(estimatedVelocity, 1.0, newestSample->time - oldestNonNullSample->time, newestSample->point - oldestNonNullSample->point);
    }
}

Offset IOSScrollViewFlingVelocityTrackerCls::_previousVelocityAt(int index) {
    int endIndex = (_index + index) % _sampleSize;
    int startIndex = (_index + index - 1) % _sampleSize;
    _PointAtTime end = _touchSamples[endIndex];
    _PointAtTime start = _touchSamples[startIndex];
    if (end == nullptr || start == nullptr) {
        return OffsetCls::zero;
    }
    int dt = (end->time - start->time)->inMicroseconds();
    assert(dt >= 0);
    return dt > 0? (end->point - start->point) * 1000 / (dt->toDouble() / 1000) : OffsetCls::zero;
}
