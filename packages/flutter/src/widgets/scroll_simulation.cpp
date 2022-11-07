#include "scroll_simulation.hpp"
BouncingScrollSimulation::BouncingScrollSimulation(double leadingExtent, double position, SpringDescription spring, Unknown, double trailingExtent, double velocity) {
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
            _springTime = double.negativeInfinity;
        } else         {
            if (position > trailingExtent) {
            _springSimulation = _overscrollSimulation(position, velocity);
            _springTime = double.negativeInfinity;
        } else {
            _frictionSimulation = FrictionSimulation(0.135, position, velocity);
            double finalX = _frictionSimulation.finalX;
            if (velocity > 0.0 && finalX > trailingExtent) {
                _springTime = _frictionSimulation.timeAtX(trailingExtent);
                _springSimulation = _overscrollSimulation(trailingExtent, math.min(_frictionSimulation.dx(_springTime), maxSpringTransferVelocity));
                assert(_springTime.isFinite);
            } else             {
                if ( < 0.0 &&  < leadingExtent) {
                _springTime = _frictionSimulation.timeAtX(leadingExtent);
                _springSimulation = _underscrollSimulation(leadingExtent, math.min(_frictionSimulation.dx(_springTime), maxSpringTransferVelocity));
                assert(_springTime.isFinite);
            } else {
                _springTime = double.infinity;
            }
;
            }        }
;
        }        assert(_springTime != nullptr);
    }
}

double BouncingScrollSimulation::x(double time) {
    return _simulation(time).x(time - _timeOffset);
}

double BouncingScrollSimulation::dx(double time) {
    return _simulation(time).dx(time - _timeOffset);
}

bool BouncingScrollSimulation::isDone(double time) {
    return _simulation(time).isDone(time - _timeOffset);
}

String BouncingScrollSimulation::toString() {
    return "${objectRuntimeType(this, 'BouncingScrollSimulation')}(leadingExtent: $leadingExtent, trailingExtent: $trailingExtent)";
}

Simulation BouncingScrollSimulation::_underscrollSimulation(double dx, double x) {
    return ScrollSpringSimulation(spring, x, leadingExtent, dx);
}

Simulation BouncingScrollSimulation::_overscrollSimulation(double dx, double x) {
    return ScrollSpringSimulation(spring, x, trailingExtent, dx);
}

Simulation BouncingScrollSimulation::_simulation(double time) {
    Simulation simulation;
    if (time > _springTime) {
        _timeOffset = _springTime.isFinite? _springTime : 0.0;
        simulation = _springSimulation;
    } else {
        _timeOffset = 0.0;
        simulation = _frictionSimulation;
    }
    return ;
}

ClampingScrollSimulation::ClampingScrollSimulation(double friction, double position, Unknown, double velocity) {
    {
        assert(_flingVelocityPenetration(0.0) == _initialVelocityPenetration);
    }
    {
        _duration = _flingDuration(velocity);
        _distance = (velocity * _duration / _initialVelocityPenetration).abs();
    }
}

double ClampingScrollSimulation::x(double time) {
    double t = clampDouble(time / _duration, 0.0, 1.0);
    return position + _distance * _flingDistancePenetration(t) * velocity.sign;
}

double ClampingScrollSimulation::dx(double time) {
    double t = clampDouble(time / _duration, 0.0, 1.0);
    return _distance * _flingVelocityPenetration(t) * velocity.sign / _duration;
}

bool ClampingScrollSimulation::isDone(double time) {
    return time >= _duration;
}

double ClampingScrollSimulation::_decelerationForFriction(double friction) {
    return friction * 61774.04968;
}

double ClampingScrollSimulation::_flingDuration(double velocity) {
    double scaledFriction = friction * _decelerationForFriction(0.84);
    double deceleration = math.log(0.35 * velocity.abs() / scaledFriction);
    return math.exp(deceleration / (_kDecelerationRate - 1.0));
}

double ClampingScrollSimulation::_flingDistancePenetration(double t) {
    return (1.2 * t * t * t) - (3.27 * t * t) + (_initialVelocityPenetration * t);
}

double ClampingScrollSimulation::_flingVelocityPenetration(double t) {
    return (3.6 * t * t) - (6.54 * t) + _initialVelocityPenetration;
}
