#ifndef ANIMATIONS_H
#define ANIMATIONS_H
#include <memory>
#include <ui.hpp>
#include "animation.hpp"
#include "curves.hpp"

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "animation.hpp"
#include "curves.hpp"
#include "listener_helpers.hpp"



class _AlwaysCompleteAnimation : Animation<double> {
public:

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void addStatusListener(AnimationStatusListener listener);

    void removeStatusListener(AnimationStatusListener listener);

    AnimationStatus status();

    double value();

    String toString();

private:

     _AlwaysCompleteAnimation();

};
const Animation<double> kAlwaysCompleteAnimation;


class _AlwaysDismissedAnimation : Animation<double> {
public:

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void addStatusListener(AnimationStatusListener listener);

    void removeStatusListener(AnimationStatusListener listener);

    AnimationStatus status();

    double value();

    String toString();

private:

     _AlwaysDismissedAnimation();

};
const Animation<double> kAlwaysDismissedAnimation;


class AlwaysStoppedAnimation<T> : Animation<T> {
public:
    T value;


     AlwaysStoppedAnimation(T value);

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void addStatusListener(AnimationStatusListener listener);

    void removeStatusListener(AnimationStatusListener listener);

    AnimationStatus status();

    String toStringDetails();

private:

};

class AnimationWithParentMixin<T> {
public:

    Animation<T> parent();

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void addStatusListener(AnimationStatusListener listener);

    void removeStatusListener(AnimationStatusListener listener);

    AnimationStatus status();

private:

};

class ProxyAnimation : Animation<double> {
public:

     ProxyAnimation(Animation<double> animation);

    Animation<double> parent();

    void  parent(Animation<double> value);

    void didStartListening();

    void didStopListening();

    AnimationStatus status();

    double value();

    String toString();

private:
    AnimationStatus _status;

    double _value;

    Animation<double> _parent;


};

class ReverseAnimation : Animation<double> {
public:
    Animation<double> parent;


     ReverseAnimation(Animation<double> parent);

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void didStartListening();

    void didStopListening();

    AnimationStatus status();

    double value();

    String toString();

private:

    void _statusChangeHandler(AnimationStatus status);

    AnimationStatus _reverseStatus(AnimationStatus status);

};

class CurvedAnimation : Animation<double> {
public:
    Animation<double> parent;

    Curve curve;

    Curve reverseCurve;

    bool isDisposed;


     CurvedAnimation(Curve curve, Animation<double> parent, Curve reverseCurve);

    void dispose();

    double value();

    String toString();

private:
    AnimationStatus _curveDirection;


    void _updateCurveDirection(AnimationStatus status);

    bool _useForwardCurve();

};

enum _TrainHoppingMode{
    minimize,
    maximize,
} // end _TrainHoppingMode

class TrainHoppingAnimation : Animation<double> {
public:
    VoidCallback onSwitchedTrain;


     TrainHoppingAnimation(Animation<double> _currentTrain, Animation<double> _nextTrain, VoidCallback onSwitchedTrain);

    Animation<double> currentTrain();

    AnimationStatus status();

    double value();

    void dispose();

    String toString();

private:
    Animation<double> _currentTrain;

    Animation<double> _nextTrain;

    _TrainHoppingMode _mode;

    AnimationStatus _lastStatus;

    double _lastValue;


    void _statusChangeHandler(AnimationStatus status);

    void _valueChangeHandler();

};

class CompoundAnimation<T> : Animation<T> {
public:
    Animation<T> first;

    Animation<T> next;


     CompoundAnimation(Animation<T> first, Animation<T> next);

    void didStartListening();

    void didStopListening();

    AnimationStatus status();

    String toString();

private:
    AnimationStatus _lastStatus;

    T _lastValue;


    void _maybeNotifyStatusListeners(AnimationStatus _);

    void _maybeNotifyListeners();

};

class AnimationMean : CompoundAnimation<double> {
public:

     AnimationMean(Animation<double> left, Animation<double> right);

    double value();

private:

};

class AnimationMax<T extends num> : CompoundAnimation<T> {
public:

     AnimationMax(Animation<T> first, Animation<T> next);

    T value();

private:

};

class AnimationMin<T extends num> : CompoundAnimation<T> {
public:

     AnimationMin(Animation<T> first, Animation<T> next);

    T value();

private:

};

#endif