#ifndef PACKAGES_FLUTTER_SRC_ANIMATION_ANIMATION
#define PACKAGES_FLUTTER_SRC_ANIMATION_ANIMATION
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "tween.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "tween.hpp"


enum AnimationStatus{
    dismissed,
    forward,
    reverse,
    completed,
} // end AnimationStatus

template<typename T> class AnimationCls : public ListenableCls {
public:

     AnimationCls();
    virtual void addListener(VoidCallback listener) override;
    virtual void removeListener(VoidCallback listener) override;
    virtual void addStatusListener(AnimationStatusListener listener);
    virtual void removeStatusListener(AnimationStatusListener listener);
    virtual AnimationStatus status();
    virtual T value();
    virtual bool isDismissed();

    virtual bool isCompleted();

    template<typename U>  virtual Animation<U> drive(Animatable<U> child);

    virtual String toString();

    virtual String toStringDetails();

private:

};
template<typename T> using Animation = std::shared_ptr<AnimationCls<T>>;


#endif