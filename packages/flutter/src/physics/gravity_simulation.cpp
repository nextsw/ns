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
    return __sf("%s(g: %s, x₀: %s, dx₀: %s, xₘₐₓ: ±%s)", objectRuntimeType(this, __s("GravitySimulation")), _a->toStringAsFixed(1), _x->toStringAsFixed(1), _v->toStringAsFixed(1), _end->toStringAsFixed(1));
}
