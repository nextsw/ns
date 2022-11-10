#include "spring_simulation.hpp"
void SpringDescriptionCls::withDampingRatio(double mass, double ratio, double stiffness)

String SpringDescriptionCls::toString() {
    return __s("${objectRuntimeType(this, 'SpringDescription')}(mass: ${mass.toStringAsFixed(1)}, stiffness: ${stiffness.toStringAsFixed(1)}, damping: ${damping.toStringAsFixed(1)})");
}

SpringSimulationCls::SpringSimulationCls(double end, SpringDescription spring, double start, Unknown tolerance, double velocity) {
    {
        _endPosition = end;
        _solution = make<_SpringSolutionCls>(spring, start - end, velocity);
    }
}

SpringType SpringSimulationCls::type() {
    return _solution->type();
}

double SpringSimulationCls::x(double time) {
    return _endPosition + _solution->x(time);
}

double SpringSimulationCls::dx(double time) {
    return _solution->dx(time);
}

bool SpringSimulationCls::isDone(double time) {
    return nearZero(_solution->x(time), tolerance->distance) && nearZero(_solution->dx(time), tolerance->velocity);
}

String SpringSimulationCls::toString() {
    return __s("${objectRuntimeType(this, 'SpringSimulation')}(end: ${_endPosition.toStringAsFixed(1)}, $type)");
}

double ScrollSpringSimulationCls::x(double time) {
    return isDone(time)? _endPosition : super->x(time);
}

_SpringSolutionCls::_SpringSolutionCls(double initialPosition, double initialVelocity, SpringDescription spring) {
    {
        assert(spring != nullptr);
        assert(spring->mass != nullptr);
        assert(spring->stiffness != nullptr);
        assert(spring->damping != nullptr);
        assert(initialPosition != nullptr);
        assert(initialVelocity != nullptr);
        double cmk = spring->damping * spring->damping - 4 * spring->mass * spring->stiffness;
        if (cmk == 0.0) {
            return make<_CriticalSolutionCls>(spring, initialPosition, initialVelocity);
        }
        if (cmk > 0.0) {
            return make<_OverdampedSolutionCls>(spring, initialPosition, initialVelocity);
        }
        return make<_UnderdampedSolutionCls>(spring, initialPosition, initialVelocity);
    }
}
