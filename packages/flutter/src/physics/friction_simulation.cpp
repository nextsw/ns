#include "friction_simulation.hpp"
FrictionSimulation::FrictionSimulation(double drag, double position, Unknown, double velocity) {
    {
        _drag = drag;
        _dragLog = math.log(drag);
        _x = position;
        _v = velocity;
    }
}

void FrictionSimulation::through(double endPosition, double endVelocity, double startPosition, double startVelocity) {
    assert(startVelocity == 0.0 || endVelocity == 0.0 || startVelocity.sign == endVelocity.sign);
    assert(startVelocity.abs() >= endVelocity.abs());
    assert((endPosition - startPosition).sign == startVelocity.sign);
    return FrictionSimulation(_dragFor(startPosition, endPosition, startVelocity, endVelocity), startPosition, startVelocityTolerance(endVelocity.abs()));
}

double FrictionSimulation::x(double time) {
    return _x + _v * math.pow(_drag, time) / _dragLog - _v / _dragLog;
}

double FrictionSimulation::dx(double time) {
    return _v * math.pow(_drag, time);
}

double FrictionSimulation::finalX() {
    return _x - _v / _dragLog;
}

double FrictionSimulation::timeAtX(double x) {
    if (x == _x) {
        return 0.0;
    }
    if (_v == 0.0 || (_v > 0? ( < _x || x > finalX) : (x > _x ||  < finalX))) {
        return double.infinity;
    }
    return math.log(_dragLog * (x - _x) / _v + 1.0) / _dragLog;
}

bool FrictionSimulation::isDone(double time) {
    return dx(time).abs() < tolerance.velocity;
}

String FrictionSimulation::toString() {
    return "${objectRuntimeType(this, 'FrictionSimulation')}(cₓ: ${_drag.toStringAsFixed(1)}, x₀: ${_x.toStringAsFixed(1)}, dx₀: ${_v.toStringAsFixed(1)})";
}

double FrictionSimulation::_dragFor(double endPosition, double endVelocity, double startPosition, double startVelocity) {
    return (;
}

BoundedFrictionSimulation::BoundedFrictionSimulation(double _maxX, double _minX, Unknown, Unknown, Unknown) {
    {
        assert(clampDouble(position, _minX, _maxX) == position);
    }
}

double BoundedFrictionSimulation::x(double time) {
    return clampDouble(super.x(time), _minX, _maxX);
}

bool BoundedFrictionSimulation::isDone(double time) {
    return super.isDone(time) || (x(time) - _minX).abs() < tolerance.distance || (x(time) - _maxX).abs() < tolerance.distance;
}

String BoundedFrictionSimulation::toString() {
    return "${objectRuntimeType(this, 'BoundedFrictionSimulation')}(cₓ: ${_drag.toStringAsFixed(1)}, x₀: ${_x.toStringAsFixed(1)}, dx₀: ${_v.toStringAsFixed(1)}, x: ${_minX.toStringAsFixed(1)}..${_maxX.toStringAsFixed(1)})";
}
