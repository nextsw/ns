#ifndef PACKAGES_FLUTTER_SRC_ANIMATION_TWEEN_SEQUENCE
#define PACKAGES_FLUTTER_SRC_ANIMATION_TWEEN_SEQUENCE
#include <base.hpp>
#include "tween.hpp"

#include <dart/core/core.hpp>
#include "tween.hpp"


template<typename T>
class TweenSequenceCls : public AnimatableCls<T> {
public:

     TweenSequenceCls(List<TweenSequenceItem<T>> items);

    virtual T transform(double t);

    virtual String toString();

private:
    List<TweenSequenceItem<T>> _items;

    List<_Interval> _intervals;


    virtual T _evaluateAt(double t, int index);

};
template<typename T>
using TweenSequence = std::shared_ptr<TweenSequenceCls<T>>;

class FlippedTweenSequenceCls : public TweenSequenceCls<double> {
public:

     FlippedTweenSequenceCls(List<TweenSequenceItem<T>> items);

    virtual double transform(double t);

private:

};
using FlippedTweenSequence = std::shared_ptr<FlippedTweenSequenceCls>;

template<typename T>
class TweenSequenceItemCls : public ObjectCls {
public:
    Animatable<T> tween;

    double weight;


     TweenSequenceItemCls(Animatable<T> tween, double weight);

private:

};
template<typename T>
using TweenSequenceItem = std::shared_ptr<TweenSequenceItemCls<T>>;

class _IntervalCls : public ObjectCls {
public:
    double start;

    double end;


    virtual bool contains(double t);

    virtual double value(double t);

    virtual String toString();

private:

     _IntervalCls(double start, double end);

};
using _Interval = std::shared_ptr<_IntervalCls>;


#endif