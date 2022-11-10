#include "clamped_simulation.hpp"
ClampedSimulationCls::ClampedSimulationCls(double dxMax, double dxMin, Simulation simulation, double xMax, double xMin) {
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
    return __s("${objectRuntimeType(this, 'ClampedSimulation')}(simulation: $simulation, x: ${xMin.toStringAsFixed(1)}..${xMax.toStringAsFixed(1)}, dx: ${dxMin.toStringAsFixed(1)}..${dxMax.toStringAsFixed(1)})");
}
