#ifndef TWEEN_ANIMATION_BUILDER_H
#define TWEEN_ANIMATION_BUILDER_H
#include <memory>

#include <flutter/animation.hpp>
#include "framework.hpp"
#include "implicit_animations.hpp"
#include "value_listenable_builder.hpp"



class TweenAnimationBuilder<T extends Object> : ImplicitlyAnimatedWidget {
public:
    Tween<T> tween;

    ValueWidgetBuilder<T> builder;

    Widget child;


     TweenAnimationBuilder(ValueWidgetBuilder<T> builder, Widget child, Unknown, Unknown, Unknown, Unknown, Tween<T> tween);

    ImplicitlyAnimatedWidgetState<ImplicitlyAnimatedWidget> createState();

private:

};

class _TweenAnimationBuilderState<T extends Object> : AnimatedWidgetBaseState<TweenAnimationBuilder<T>> {
public:

    void initState();

    void forEachTween(TweenVisitor<dynamic> visitor);

    Widget build(BuildContext context);

private:
    Tween<T> _currentTween;


};

#endif