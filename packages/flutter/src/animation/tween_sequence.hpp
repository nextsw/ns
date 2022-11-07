#ifndef TWEEN_SEQUENCE_H
#define TWEEN_SEQUENCE_H
#include <memory>
#include "tween.hpp"

#include "tween.hpp"



class TweenSequence<T> : Animatable<T> {
public:

     TweenSequence(List<TweenSequenceItem<T>> items);

    T transform(double t);

    String toString();

private:
    List<TweenSequenceItem<T>> _items;

    List<_Interval> _intervals;


    T _evaluateAt(int index, double t);

};

class FlippedTweenSequence : TweenSequence<double> {
public:

     FlippedTweenSequence(Unknown);

    double transform(double t);

private:

};

class TweenSequenceItem<T> {
public:
    Animatable<T> tween;

    double weight;


     TweenSequenceItem(Animatable<T> tween, double weight);

private:

};

class _Interval {
public:
    double start;

    double end;


    bool contains(double t);

    double value(double t);

    String toString();

private:

     _Interval(double end, double start);

};

#endif