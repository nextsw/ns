#ifndef TWEEN_H
#define TWEEN_H
#include <memory>
#include <ui.hpp>
#include "animation.hpp"
#include "curves.hpp"

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "animations.hpp"



class Animatable<T> {
public:

     Animatable();

    T transform(double t);

    T evaluate(Animation<double> animation);

    Animation<T> animate(Animation<double> parent);

    Animatable<T> chain(Animatable<double> parent);

private:

};

class _AnimatedEvaluation<T> : Animation<T> {
public:
    Animation<double> parent;


    T value();

    String toString();

    String toStringDetails();

private:
    Animatable<T> _evaluatable;


     _AnimatedEvaluation(Animatable<T> _evaluatable, Animation<double> parent);

};

class _ChainedEvaluation<T> : Animatable<T> {
public:

    T transform(double t);

    String toString();

private:
    Animatable<double> _parent;

    Animatable<T> _evaluatable;


     _ChainedEvaluation(Animatable<T> _evaluatable, Animatable<double> _parent);

};

class Tween<T extends Object> : Animatable<T> {
public:
    T begin;

    T end;


     Tween(T begin, T end);

    T lerp(double t);

    T transform(double t);

    String toString();

private:

};

class ReverseTween<T extends Object> : Tween<T> {
public:
    Tween<T> parent;


     ReverseTween(Tween<T> parent);

    T lerp(double t);

private:

};

class ColorTween : Tween<Color> {
public:

     ColorTween(Unknown, Unknown);

    Color lerp(double t);

private:

};

class SizeTween : Tween<Size> {
public:

     SizeTween(Unknown, Unknown);

    Size lerp(double t);

private:

};

class RectTween : Tween<Rect> {
public:

     RectTween(Unknown, Unknown);

    Rect lerp(double t);

private:

};

class IntTween : Tween<int> {
public:

     IntTween(Unknown, Unknown);

    int lerp(double t);

private:

};

class StepTween : Tween<int> {
public:

     StepTween(Unknown, Unknown);

    int lerp(double t);

private:

};

class ConstantTween<T> : Tween<T> {
public:

     ConstantTween(T value);

    T lerp(double t);

    String toString();

private:

};

class CurveTween : Animatable<double> {
public:
    Curve curve;


     CurveTween(Curve curve);

    double transform(double t);

    String toString();

private:

};

#endif