#include "velocity_tracker.hpp"
Velocity::Velocity(Offset pixelsPerSecond) {
    {
        assert(pixelsPerSecond != nullptr);
    }
}

Velocity Velocity::-() {
    return Velocity(-pixelsPerSecond);
}

Velocity Velocity::-(Velocity other) {
    return Velocity(pixelsPerSecond - other.pixelsPerSecond);
}

Velocity Velocity::+(Velocity other) {
    return Velocity(pixelsPerSecond + other.pixelsPerSecond);
}

Velocity Velocity::clampMagnitude(double maxValue, double minValue) {
    assert(minValue != nullptr && minValue >= 0.0);
    assert(maxValue != nullptr && maxValue >= 0.0 && maxValue >= minValue);
    double valueSquared = pixelsPerSecond.distanceSquared;
    if (valueSquared > maxValue * maxValue) {
        return Velocity((pixelsPerSecond / pixelsPerSecond.distance) * maxValue);
    }
    if ( < minValue * minValue) {
        return Velocity((pixelsPerSecond / pixelsPerSecond.distance) * minValue);
    }
    return this;
}

bool Velocity::==(Object other) {
    return other is Velocity && other.pixelsPerSecond == pixelsPerSecond;
}

int Velocity::hashCode() {
    return pixelsPerSecond.hashCode;
}

String Velocity::toString() {
    return "Velocity(${pixelsPerSecond.dx.toStringAsFixed(1)}, ${pixelsPerSecond.dy.toStringAsFixed(1)})";
}

VelocityEstimate::VelocityEstimate(double confidence, Duration duration, Offset offset, Offset pixelsPerSecond) {
    {
        assert(pixelsPerSecond != nullptr);
        assert(confidence != nullptr);
        assert(duration != nullptr);
        assert(offset != nullptr);
    }
}

String VelocityEstimate::toString() {
    return "VelocityEstimate(${pixelsPerSecond.dx.toStringAsFixed(1)}, ${pixelsPerSecond.dy.toStringAsFixed(1)}; offset: $offset, duration: $duration, confidence: ${confidence.toStringAsFixed(1)})";
}

String _PointAtTime::toString() {
    return "_PointAtTime($point at $time)";
}

_PointAtTime::_PointAtTime(Offset point, Duration time) {
    {
        assert(point != nullptr);
        assert(time != nullptr);
    }
}

void VelocityTracker::addPosition(Offset position, Duration time) {
    _index = 1;
    if (_index == _historySize) {
        _index = 0;
    }
    _samples[_index] = _PointAtTime(position, time);
}

VelocityEstimate VelocityTracker::getVelocityEstimate() {
    List<double> x = ;
    List<double> y = ;
    List<double> w = ;
    List<double> time = ;
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
        double age = (newestSample.time - sample.time).inMicroseconds.toDouble() / 1000;
        double delta = (sample.time - previousSample.time).inMicroseconds.abs().toDouble() / 1000;
        previousSample = sample;
        if (age > _horizonMilliseconds || delta > _assumePointerMoveStoppedMilliseconds) {
                        break;
        }
        oldestSample = sample;
        Offset position = sample.point;
        x.add(position.dx);
        y.add(position.dy);
        w.add(1.0);
        time.add(-age);
        index = (index == 0? _historySize : index) - 1;
        sampleCount = 1;
    } while ( < _historySize);
    if (sampleCount >= _minSampleSize) {
        LeastSquaresSolver xSolver = LeastSquaresSolver(time, x, w);
        PolynomialFit xFit = xSolver.solve(2);
        if (xFit != nullptr) {
            LeastSquaresSolver ySolver = LeastSquaresSolver(time, y, w);
            PolynomialFit yFit = ySolver.solve(2);
            if (yFit != nullptr) {
                return VelocityEstimate(Offset(xFit.coefficients[1] * 1000, yFit.coefficients[1] * 1000), xFit.confidence * yFit.confidence, newestSample.time - oldestSample.time, newestSample.point - oldestSample.point);
            }
        }
    }
    return VelocityEstimate(Offset.zero, 1.0, newestSample.time - oldestSample.time, newestSample.point - oldestSample.point);
}

Velocity VelocityTracker::getVelocity() {
    VelocityEstimate estimate = getVelocityEstimate();
    if (estimate == nullptr || estimate.pixelsPerSecond == Offset.zero) {
        return Velocity.zero;
    }
    return Velocity(estimate.pixelsPerSecond);
}

IOSScrollViewFlingVelocityTracker::IOSScrollViewFlingVelocityTracker(Unknown) {
    {
        super.withKind();
    }
}

void IOSScrollViewFlingVelocityTracker::addPosition(Offset position, Duration time) {
    assert(());
    _index = (_index + 1) % _sampleSize;
    _touchSamples[_index] = _PointAtTime(position, time);
}

VelocityEstimate IOSScrollViewFlingVelocityTracker::getVelocityEstimate() {
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
        assert(false, "There must be at least 1 point in _touchSamples: $_touchSamples");
        return const VelocityEstimate(Offset.zero, 0.0, Duration.zero, Offset.zero);
    } else {
        return VelocityEstimate(estimatedVelocity, 1.0, newestSample.time - oldestNonNullSample.time, newestSample.point - oldestNonNullSample.point);
    }
}

Offset IOSScrollViewFlingVelocityTracker::_previousVelocityAt(int index) {
    int endIndex = (_index + index) % _sampleSize;
    int startIndex = (_index + index - 1) % _sampleSize;
    _PointAtTime end = _touchSamples[endIndex];
    _PointAtTime start = _touchSamples[startIndex];
    if (end == nullptr || start == nullptr) {
        return Offset.zero;
    }
    int dt = (end.time - start.time).inMicroseconds;
    assert(dt >= 0);
    return dt > 0? (end.point - start.point) * 1000 / (dt.toDouble() / 1000) : Offset.zero;
}
