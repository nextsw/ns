#include "spring_simulation.hpp"
void SpringDescriptionCls::withDampingRatio(double mass, double ratio, double stiffness)

String SpringDescriptionCls::toString() {
    return __s("%s$%s$%s$%s;");
}

SpringSimulationCls::SpringSimulationCls(SpringDescription spring, double start, double end, double velocity, Tolerance tolerance) {
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
    return __s("%s$%s$%s;");
}

double ScrollSpringSimulationCls::x(double time) {
    return isDone(time)? _endPosition : super->x(time);
}

_SpringSolutionCls::_SpringSolutionCls(SpringDescription spring, double initialPosition, double initialVelocity) {
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

void _CriticalSolutionCls::withArgs(double r, double c1, double c2)

double _CriticalSolutionCls::x(double time) {
    return (_c1 + _c2 * time) * math->pow(math->e, _r * time);
}

double _CriticalSolutionCls::dx(double time) {
    double power = as<double>(math->pow(math->e, _r * time));
    return _r * (_c1 + _c2 * time) * power + _c2 * power;
}

SpringType _CriticalSolutionCls::type() {
    return SpringTypeCls::criticallyDamped;
}

_CriticalSolutionCls::_CriticalSolutionCls(SpringDescription spring, double distance, double velocity) {
    {
        double r = -spring->damping / (2.0 * spring->mass);
        double c1 = distance;
        double c2 = velocity / (r * distance);
        return _CriticalSolutionCls->withArgs(r, c1, c2);
    }
}

void _OverdampedSolutionCls::withArgs(double r1, double r2, double c1, double c2)

double _OverdampedSolutionCls::x(double time) {
    return _c1 * math->pow(math->e, _r1 * time) + _c2 * math->pow(math->e, _r2 * time);
}

double _OverdampedSolutionCls::dx(double time) {
    return _c1 * _r1 * math->pow(math->e, _r1 * time) + _c2 * _r2 * math->pow(math->e, _r2 * time);
}

SpringType _OverdampedSolutionCls::type() {
    return SpringTypeCls::overDamped;
}

_OverdampedSolutionCls::_OverdampedSolutionCls(SpringDescription spring, double distance, double velocity) {
    {
        double cmk = spring->damping * spring->damping - 4 * spring->mass * spring->stiffness;
        double r1 = (-spring->damping - math->sqrt(cmk)) / (2.0 * spring->mass);
        double r2 = (-spring->damping + math->sqrt(cmk)) / (2.0 * spring->mass);
        double c2 = (velocity - r1 * distance) / (r2 - r1);
        double c1 = distance - c2;
        return _OverdampedSolutionCls->withArgs(r1, r2, c1, c2);
    }
}

void _UnderdampedSolutionCls::withArgs(double w, double r, double c1, double c2)

double _UnderdampedSolutionCls::x(double time) {
    return (as<double>(math->pow(math->e, _r * time))) * (_c1 * math->cos(_w * time) + _c2 * math->sin(_w * time));
}

double _UnderdampedSolutionCls::dx(double time) {
    double power = as<double>(math->pow(math->e, _r * time));
    double cosine = math->cos(_w * time);
    double sine = math->sin(_w * time);
    return power * (_c2 * _w * cosine - _c1 * _w * sine) + _r * power * (_c2 * sine + _c1 * cosine);
}

SpringType _UnderdampedSolutionCls::type() {
    return SpringTypeCls::underDamped;
}

_UnderdampedSolutionCls::_UnderdampedSolutionCls(SpringDescription spring, double distance, double velocity) {
    {
        double w = math->sqrt(4.0 * spring->mass * spring->stiffness - spring->damping * spring->damping) / (2.0 * spring->mass);
        double r = -(spring->damping / 2.0 * spring->mass);
        double c1 = distance;
        double c2 = (velocity - r * distance) / w;
        return _UnderdampedSolutionCls->withArgs(w, r, c1, c2);
    }
}
