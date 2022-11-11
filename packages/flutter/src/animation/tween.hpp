#ifndef PACKAGES_FLUTTER_SRC_ANIMATION_TWEEN
#define PACKAGES_FLUTTER_SRC_ANIMATION_TWEEN
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "animation.hpp"
#include "curves.hpp"

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "animations.hpp"


template<typename T>
class AnimatableCls : public ObjectCls {
public:

     AnimatableCls();
    virtual T transform(double t);
    virtual T evaluate(Animation<double> animation);

    virtual Animation<T> animate(Animation<double> parent);

    virtual Animatable<T> chain(Animatable<double> parent);

private:

};
template<typename T>
using Animatable = std::shared_ptr<AnimatableCls<T>>;

template<typename T>
class _AnimatedEvaluationCls : public AnimationCls<T> {
public:
    Animation<double> parent;


    virtual T value();

    virtual String toString();

    virtual String toStringDetails();

private:
    Animatable<T> _evaluatable;


     _AnimatedEvaluationCls(Animatable<T> _evaluatable, Animation<double> parent);
};
template<typename T>
using _AnimatedEvaluation = std::shared_ptr<_AnimatedEvaluationCls<T>>;

template<typename T>
class _ChainedEvaluationCls : public AnimatableCls<T> {
public:

    virtual T transform(double t);

    virtual String toString();

private:
    Animatable<double> _parent;

    Animatable<T> _evaluatable;


     _ChainedEvaluationCls(Animatable<T> _evaluatable, Animatable<double> _parent);
};
template<typename T>
using _ChainedEvaluation = std::shared_ptr<_ChainedEvaluationCls<T>>;

template<typename T>
class TweenCls : public AnimatableCls<T> {
public:
    T begin;

    T end;


     TweenCls(T begin, T end);
    virtual T lerp(double t);

    virtual T transform(double t);

    virtual String toString();

private:

};
template<typename T>
using Tween = std::shared_ptr<TweenCls<T>>;

template<typename T>
class ReverseTweenCls : public TweenCls<T> {
public:
    Tween<T> parent;


     ReverseTweenCls(Tween<T> parent);

    virtual T lerp(double t);

private:

};
template<typename T>
using ReverseTween = std::shared_ptr<ReverseTweenCls<T>>;

class ColorTweenCls : public TweenCls<Color> {
public:

     ColorTweenCls(Unknown begin, Unknown end);
    virtual Color lerp(double t);

private:

};
using ColorTween = std::shared_ptr<ColorTweenCls>;

class SizeTweenCls : public TweenCls<Size> {
public:

     SizeTweenCls(Unknown begin, Unknown end);
    virtual Size lerp(double t);

private:

};
using SizeTween = std::shared_ptr<SizeTweenCls>;

class RectTweenCls : public TweenCls<Rect> {
public:

     RectTweenCls(Unknown begin, Unknown end);
    virtual Rect lerp(double t);

private:

};
using RectTween = std::shared_ptr<RectTweenCls>;

class IntTweenCls : public TweenCls<int> {
public:

     IntTweenCls(Unknown begin, Unknown end);
    virtual int lerp(double t);

private:

};
using IntTween = std::shared_ptr<IntTweenCls>;

class StepTweenCls : public TweenCls<int> {
public:

     StepTweenCls(Unknown begin, Unknown end);
    virtual int lerp(double t);

private:

};
using StepTween = std::shared_ptr<StepTweenCls>;

template<typename T>
class ConstantTweenCls : public TweenCls<T> {
public:

     ConstantTweenCls(T value);

    virtual T lerp(double t);

    virtual String toString();

private:

};
template<typename T>
using ConstantTween = std::shared_ptr<ConstantTweenCls<T>>;

class CurveTweenCls : public AnimatableCls<double> {
public:
    Curve curve;


     CurveTweenCls(Curve curve);

    virtual double transform(double t);

    virtual String toString();

private:

};
using CurveTween = std::shared_ptr<CurveTweenCls>;


#endif