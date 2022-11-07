#include "clamped_simulation.hpp"
ClampedSimulation::ClampedSimulation(double dxMax, double dxMin, Simulation simulation, double xMax, double xMin) {
    {
        assert(simulation != nullptr);
        assert(xMax >= xMin);
        assert(dxMax >= dxMin);
    }
}

double ClampedSimulation::x(double time) {
    return clampDouble(simulation.x(time), xMin, xMax);
}

double ClampedSimulation::dx(double time) {
    return clampDouble(simulation.dx(time), dxMin, dxMax);
}

bool ClampedSimulation::isDone(double time) {
    return simulation.isDone(time);
}

String ClampedSimulation::toString() {
    return "${objectRuntimeType(this, 'ClampedSimulation')}(simulation: $simulation, x: ${xMin.toStringAsFixed(1)}..${xMax.toStringAsFixed(1)}, dx: ${dxMin.toStringAsFixed(1)}..${dxMax.toStringAsFixed(1)})";
}
