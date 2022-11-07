#include "spring_simulation.hpp"
void SpringDescription::withDampingRatio(double mass, double ratio, double stiffness)

String SpringDescription::toString() {
    return "${objectRuntimeType(this, 'SpringDescription')}(mass: ${mass.toStringAsFixed(1)}, stiffness: ${stiffness.toStringAsFixed(1)}, damping: ${damping.toStringAsFixed(1)})";
}

SpringSimulation::SpringSimulation(double end, SpringDescription spring, double start, Unknown, double velocity) {
    {
        _endPosition = end;
        _solution = _SpringSolution(spring, start - end, velocity);
    }
}

SpringType SpringSimulation::type() {
    return _solution.type;
}

double SpringSimulation::x(double time) {
    return _endPosition + _solution.x(time);
}

double SpringSimulation::dx(double time) {
    return _solution.dx(time);
}

bool SpringSimulation::isDone(double time) {
    return nearZero(_solution.x(time), tolerance.distance) && nearZero(_solution.dx(time), tolerance.velocity);
}

String SpringSimulation::toString() {
    return "${objectRuntimeType(this, 'SpringSimulation')}(end: ${_endPosition.toStringAsFixed(1)}, $type)";
}

double ScrollSpringSimulation::x(double time) {
    return isDone(time)? _endPosition : super.x(time);
}

_SpringSolution::_SpringSolution(double initialPosition, double initialVelocity, SpringDescription spring) {
    {
        assert(spring != nullptr);
        assert(spring.mass != nullptr);
        assert(spring.stiffness != nullptr);
        assert(spring.damping != nullptr);
        assert(initialPosition != nullptr);
        assert(initialVelocity != nullptr);
        double cmk = spring.damping * spring.damping - 4 * spring.mass * spring.stiffness;
        if (cmk == 0.0) {
            return _CriticalSolution(spring, initialPosition, initialVelocity);
        }
        if (cmk > 0.0) {
            return _OverdampedSolution(spring, initialPosition, initialVelocity);
        }
        return _UnderdampedSolution(spring, initialPosition, initialVelocity);
    }
}
