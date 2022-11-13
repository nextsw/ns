#include "clamped_simulation.hpp"
ClampedSimulationCls::ClampedSimulationCls(Simulation simulation, double dxMax, double dxMin, double xMax, double xMin) {
    {
        assert(simulation != nullptr);
        assert(xMax >= xMin);
        assert(dxMax >= dxMin);
    }
}

double ClampedSimulationCls::x(double time) {
    return clampDouble(simulation->x(time), xMin, xMax);
}

double ClampedSimulationCls::dx(double time) {
    return clampDouble(simulation->dx(time), dxMin, dxMax);
}

bool ClampedSimulationCls::isDone(double time) {
    return simulation->isDone(time);
}

String ClampedSimulationCls::toString() {
    return __sf("%s(simulation: %s, x: %s..%s, dx: %s..%s)", objectRuntimeType(this, __s("ClampedSimulation")), simulation, xMin->toStringAsFixed(1), xMax->toStringAsFixed(1), dxMin->toStringAsFixed(1), dxMax->toStringAsFixed(1));
}
