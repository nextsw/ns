#include "scroll_simulation.hpp"
BouncingScrollSimulationCls::BouncingScrollSimulationCls(double leadingExtent, double position, SpringDescription spring, Unknown tolerance, double trailingExtent, double velocity) {
    {
        assert(position != nullptr);
        assert(velocity != nullptr);
        assert(leadingExtent != nullptr);
        assert(trailingExtent != nullptr);
        assert(leadingExtent <= trailingExtent);
        assert(spring != nullptr);
    }
    {
        if ( < leadingExtent) {
            _springSimulation = _underscrollSimulation(position, velocity);
            _springTime = double->negativeInfinity;
        } else         {
            if (position > trailingExtent) {
            _springSimulation = _overscrollSimulation(position, velocity);
            _springTime = double->negativeInfinity;
        } else {
            _frictionSimulation = make<FrictionSimulationCls>(0.135, position, velocity);
            double finalX = _frictionSimulation->finalX();
            if (velocity > 0.0 && finalX > trailingExtent) {
                _springTime = _frictionSimulation->timeAtX(trailingExtent);
                _springSimulation = _overscrollSimulation(trailingExtent, math->min(_frictionSimulation->dx(_springTime), maxSpringTransferVelocity));
                assert(_springTime->isFinite);
            } else             {
                if ( < 0.0 &&  < leadingExtent) {
                _springTime = _frictionSimulation->timeAtX(leadingExtent);
                _springSimulation = _underscrollSimulation(leadingExtent, math->min(_frictionSimulation->dx(_springTime), maxSpringTransferVelocity));
                assert(_springTime->isFinite);
            } else {
                _springTime = double->infinity;
            }
;
            }        }
;
        }        assert(_springTime != nullptr);
    }
}

double BouncingScrollSimulationCls::x(double time) {
    return _simulation(time)->x(time - _timeOffset);
}

double BouncingScrollSimulationCls::dx(double time) {
    return _simulation(time)->dx(time - _timeOffset);
}

bool BouncingScrollSimulationCls::isDone(double time) {
    return _simulation(time)->isDone(time - _timeOffset);
}

String BouncingScrollSimulationCls::toString() {
    return __s("${objectRuntimeType(this, 'BouncingScrollSimulation')}(leadingExtent: $leadingExtent, trailingExtent: $trailingExtent)");
}

Simulation BouncingScrollSimulationCls::_underscrollSimulation(double x, double dx) {
    return make<ScrollSpringSimulationCls>(spring, x, leadingExtent, dx);
}

Simulation BouncingScrollSimulationCls::_overscrollSimulation(double x, double dx) {
    return make<ScrollSpringSimulationCls>(spring, x, trailingExtent, dx);
}

Simulation BouncingScrollSimulationCls::_simulation(double time) {
    Simulation simulation;
    if (time > _springTime) {
        _timeOffset = _springTime->isFinite? _springTime : 0.0;
        simulation = _springSimulation;
    } else {
        _timeOffset = 0.0;
        simulation = _frictionSimulation;
    }
    auto _c1 = simulation;_c1.tolerance = tolerance;return _c1;
}

ClampingScrollSimulationCls::ClampingScrollSimulationCls(double friction, double position, Unknown tolerance, double velocity) {
    {
        assert(_flingVelocityPenetration(0.0) == _initialVelocityPenetration);
    }
    {
        _duration = _flingDuration(velocity);
        _distance = (velocity * _duration / _initialVelocityPenetration)->abs();
    }
}

double ClampingScrollSimulationCls::x(double time) {
    double t = clampDouble(time / _duration, 0.0, 1.0);
    return position + _distance * _flingDistancePenetration(t) * velocity->sign();
}

double ClampingScrollSimulationCls::dx(double time) {
    double t = clampDouble(time / _duration, 0.0, 1.0);
    return _distance * _flingVelocityPenetration(t) * velocity->sign() / _duration;
}

bool ClampingScrollSimulationCls::isDone(double time) {
    return time >= _duration;
}

double ClampingScrollSimulationCls::_decelerationForFriction(double friction) {
    return friction * 61774.04968;
}

double ClampingScrollSimulationCls::_flingDuration(double velocity) {
    double scaledFriction = friction * _decelerationForFriction(0.84);
    double deceleration = math->log(0.35 * velocity->abs() / scaledFriction);
    return math->exp(deceleration / (_kDecelerationRate - 1.0));
}

double ClampingScrollSimulationCls::_flingDistancePenetration(double t) {
    return (1.2 * t * t * t) - (3.27 * t * t) + (_initialVelocityPenetration * t);
}

double ClampingScrollSimulationCls::_flingVelocityPenetration(double t) {
    return (3.6 * t * t) - (6.54 * t) + _initialVelocityPenetration;
}
