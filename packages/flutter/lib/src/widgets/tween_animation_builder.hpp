#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TWEEN_ANIMATION_BUILDER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TWEEN_ANIMATION_BUILDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/flutter.hpp>
#include "framework.hpp"
#include "implicit_animations.hpp"
#include "value_listenable_builder.hpp"


template<typename T> class TweenAnimationBuilderCls : public ImplicitlyAnimatedWidgetCls {
public:
    Tween<T> tween;

    ValueWidgetBuilder<T> builder;

    Widget child;


     TweenAnimationBuilderCls(ValueWidgetBuilder<T> builder, Widget child, Unknown curve, Unknown duration, Unknown key, Unknown onEnd, Tween<T> tween);

    virtual ImplicitlyAnimatedWidgetState<ImplicitlyAnimatedWidget> createState();

private:

};
template<typename T> using TweenAnimationBuilder = std::shared_ptr<TweenAnimationBuilderCls<T>>;

template<typename T> class _TweenAnimationBuilderStateCls : public AnimatedWidgetBaseStateCls<TweenAnimationBuilder<T>> {
public:

    virtual void initState();

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual Widget build(BuildContext context);

private:
    Tween<T> _currentTween;


};
template<typename T> using _TweenAnimationBuilderState = std::shared_ptr<_TweenAnimationBuilderStateCls<T>>;


#endif