#ifndef PACKAGES_FLUTTER_SRC_ANIMATION_ANIMATIONS
#define PACKAGES_FLUTTER_SRC_ANIMATION_ANIMATIONS
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "animation.hpp"
#include "curves.hpp"

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "animation.hpp"
#include "curves.hpp"
#include "listener_helpers.hpp"


class _AlwaysCompleteAnimationCls : public AnimationCls<double> {
public:

    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

    virtual void addStatusListener(AnimationStatusListener listener);

    virtual void removeStatusListener(AnimationStatusListener listener);

    virtual AnimationStatus status();

    virtual double value();

    virtual String toString();

private:

     _AlwaysCompleteAnimationCls();
};
using _AlwaysCompleteAnimation = std::shared_ptr<_AlwaysCompleteAnimationCls>;
Animation<double> kAlwaysCompleteAnimation;


class _AlwaysDismissedAnimationCls : public AnimationCls<double> {
public:

    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

    virtual void addStatusListener(AnimationStatusListener listener);

    virtual void removeStatusListener(AnimationStatusListener listener);

    virtual AnimationStatus status();

    virtual double value();

    virtual String toString();

private:

     _AlwaysDismissedAnimationCls();
};
using _AlwaysDismissedAnimation = std::shared_ptr<_AlwaysDismissedAnimationCls>;
Animation<double> kAlwaysDismissedAnimation;


template<typename T> class AlwaysStoppedAnimationCls : public AnimationCls<T> {
public:
    T value;


     AlwaysStoppedAnimationCls(T value);
    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

    virtual void addStatusListener(AnimationStatusListener listener);

    virtual void removeStatusListener(AnimationStatusListener listener);

    virtual AnimationStatus status();

    virtual String toStringDetails();

private:

};
template<typename T> using AlwaysStoppedAnimation = std::shared_ptr<AlwaysStoppedAnimationCls<T>>;

template<typename T> class AnimationWithParentMixinCls : public ObjectCls {
public:

    virtual Animation<T> parent();
    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

    virtual void addStatusListener(AnimationStatusListener listener);

    virtual void removeStatusListener(AnimationStatusListener listener);

    virtual AnimationStatus status();

private:

};
template<typename T> using AnimationWithParentMixin = std::shared_ptr<AnimationWithParentMixinCls<T>>;

class ProxyAnimationCls : public AnimationCls<double> {
public:

     ProxyAnimationCls(Animation<double> animation);

    virtual Animation<double> parent();

    virtual void  parent(Animation<double> value);

    virtual void didStartListening();

    virtual void didStopListening();

    virtual AnimationStatus status();

    virtual double value();

    virtual String toString();

private:
    AnimationStatus _status;

    double _value;

    Animation<double> _parent;


};
using ProxyAnimation = std::shared_ptr<ProxyAnimationCls>;

class ReverseAnimationCls : public AnimationCls<double> {
public:
    Animation<double> parent;


     ReverseAnimationCls(Animation<double> parent);

    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

    virtual void didStartListening();

    virtual void didStopListening();

    virtual AnimationStatus status();

    virtual double value();

    virtual String toString();

private:

    virtual void _statusChangeHandler(AnimationStatus status);

    virtual AnimationStatus _reverseStatus(AnimationStatus status);

};
using ReverseAnimation = std::shared_ptr<ReverseAnimationCls>;

class CurvedAnimationCls : public AnimationCls<double> {
public:
    Animation<double> parent;

    Curve curve;

    Curve reverseCurve;

    bool isDisposed;


     CurvedAnimationCls(Curve curve, Animation<double> parent, Curve reverseCurve);

    virtual void dispose();

    virtual double value();

    virtual String toString();

private:
    AnimationStatus _curveDirection;


    virtual void _updateCurveDirection(AnimationStatus status);

    virtual bool _useForwardCurve();

};
using CurvedAnimation = std::shared_ptr<CurvedAnimationCls>;

enum _TrainHoppingMode{
    minimize,
    maximize,
} // end _TrainHoppingMode

class TrainHoppingAnimationCls : public AnimationCls<double> {
public:
    VoidCallback onSwitchedTrain;


     TrainHoppingAnimationCls(Animation<double> _currentTrain, Animation<double> _nextTrain, VoidCallback onSwitchedTrain);

    virtual Animation<double> currentTrain();

    virtual AnimationStatus status();

    virtual double value();

    virtual void dispose();

    virtual String toString();

private:
    Animation<double> _currentTrain;

    Animation<double> _nextTrain;

    _TrainHoppingMode _mode;

    AnimationStatus _lastStatus;

    double _lastValue;


    virtual void _statusChangeHandler(AnimationStatus status);

    virtual void _valueChangeHandler();

};
using TrainHoppingAnimation = std::shared_ptr<TrainHoppingAnimationCls>;

template<typename T> class CompoundAnimationCls : public AnimationCls<T> {
public:
    Animation<T> first;

    Animation<T> next;


     CompoundAnimationCls(Animation<T> first, Animation<T> next);

    virtual void didStartListening();

    virtual void didStopListening();

    virtual AnimationStatus status();

    virtual String toString();

private:
    AnimationStatus _lastStatus;

    T _lastValue;


    virtual void _maybeNotifyStatusListeners(AnimationStatus _);

    virtual void _maybeNotifyListeners();

};
template<typename T> using CompoundAnimation = std::shared_ptr<CompoundAnimationCls<T>>;

class AnimationMeanCls : public CompoundAnimationCls<double> {
public:

     AnimationMeanCls(Animation<double> left, Animation<double> right);

    virtual double value();

private:

};
using AnimationMean = std::shared_ptr<AnimationMeanCls>;

template<typename T> class AnimationMaxCls : public CompoundAnimationCls<T> {
public:

     AnimationMaxCls(Animation<T> first, Animation<T> next);

    virtual T value();

private:

};
template<typename T> using AnimationMax = std::shared_ptr<AnimationMaxCls<T>>;

template<typename T> class AnimationMinCls : public CompoundAnimationCls<T> {
public:

     AnimationMinCls(Animation<T> first, Animation<T> next);

    virtual T value();

private:

};
template<typename T> using AnimationMin = std::shared_ptr<AnimationMinCls<T>>;


#endif