#include "friction_simulation.hpp"
FrictionSimulationCls::FrictionSimulationCls(double drag, double position, double velocity, Unknown tolerance) {
    {
        _drag = drag;
        _dragLog = math->log(drag);
        _x = position;
        _v = velocity;
    }
}

void FrictionSimulationCls::through(double startPosition, double endPosition, double startVelocity, double endVelocity) {
    assert(startVelocity == 0.0 || endVelocity == 0.0 || startVelocity->sign() == endVelocity->sign());
    assert(startVelocity->abs() >= endVelocity->abs());
    assert((endPosition - startPosition)->sign() == startVelocity->sign());
    return make<FrictionSimulationCls>(_dragFor(startPosition, endPosition, startVelocity, endVelocity), startPosition, startVelocitymake<ToleranceCls>(endVelocity->abs()));
}

double FrictionSimulationCls::x(double time) {
    return _x + _v * math->pow(_drag, time) / _dragLog - _v / _dragLog;
}

double FrictionSimulationCls::dx(double time) {
    return _v * math->pow(_drag, time);
}

double FrictionSimulationCls::finalX() {
    return _x - _v / _dragLog;
}

double FrictionSimulationCls::timeAtX(double x) {
    if (x == _x) {
        return 0.0;
    }
    if (_v == 0.0 || (_v > 0? ( < _x || x > finalX()) : (x > _x ||  < finalX()))) {
        return double->infinity;
    }
    return math->log(_dragLog * (x - _x) / _v + 1.0) / _dragLog;
}

bool FrictionSimulationCls::isDone(double time) {
    return dx(time)->abs() < tolerance->velocity;
}

String FrictionSimulationCls::toString() {
    return __s("${objectRuntimeType(this, 'FrictionSimulation')}(cₓ: ${_drag.toStringAsFixed(1)}, x₀: ${_x.toStringAsFixed(1)}, dx₀: ${_v.toStringAsFixed(1)})");
}

double FrictionSimulationCls::_dragFor(double startPosition, double endPosition, double startVelocity, double endVelocity) {
    return as<double>(math->pow(math->e, (startVelocity - endVelocity) / (startPosition - endPosition)));
}

BoundedFrictionSimulationCls::BoundedFrictionSimulationCls(Unknown drag, Unknown position, Unknown velocity, double _minX, double _maxX) {
    {
        assert(clampDouble(position, _minX, _maxX) == position);
    }
}

double BoundedFrictionSimulationCls::x(double time) {
    return clampDouble(super->x(time), _minX, _maxX);
}

bool BoundedFrictionSimulationCls::isDone(double time) {
    return super->isDone(time) || (x(time) - _minX)->abs() < tolerance->distance || (x(time) - _maxX)->abs() < tolerance->distance;
}

String BoundedFrictionSimulationCls::toString() {
    return __s("${objectRuntimeType(this, 'BoundedFrictionSimulation')}(cₓ: ${_drag.toStringAsFixed(1)}, x₀: ${_x.toStringAsFixed(1)}, dx₀: ${_v.toStringAsFixed(1)}, x: ${_minX.toStringAsFixed(1)}..${_maxX.toStringAsFixed(1)})");
}
