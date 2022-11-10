#include "gravity_simulation.hpp"
GravitySimulationCls::GravitySimulationCls(double acceleration, double distance, double endDistance, double velocity) {
    {
        assert(acceleration != nullptr);
        assert(distance != nullptr);
        assert(velocity != nullptr);
        assert(endDistance != nullptr);
        assert(endDistance >= 0);
        _a = acceleration;
        _x = distance;
        _v = velocity;
        _end = endDistance;
    }
}

double GravitySimulationCls::x(double time) {
    return _x + _v * time + 0.5 * _a * time * time;
}

double GravitySimulationCls::dx(double time) {
    return _v + time * _a;
}

bool GravitySimulationCls::isDone(double time) {
    return x(time)->abs() >= _end;
}

String GravitySimulationCls::toString() {
    return __s("${objectRuntimeType(this, 'GravitySimulation')}(g: ${_a.toStringAsFixed(1)}, x₀: ${_x.toStringAsFixed(1)}, dx₀: ${_v.toStringAsFixed(1)}, xₘₐₓ: ±${_end.toStringAsFixed(1)})");
}
