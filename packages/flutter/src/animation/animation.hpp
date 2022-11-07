#ifndef ANIMATION_H
#define ANIMATION_H
#include <memory>
#include <ui.hpp>
#include "tween.hpp"

#include <flutter/foundation.hpp>
#include "tween.hpp"



enum AnimationStatus{
    dismissed,
    forward,
    reverse,
    completed,
} // end AnimationStatus

class Animation<T> : Listenable {
public:

     Animation();

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void addStatusListener(AnimationStatusListener listener);

    void removeStatusListener(AnimationStatusListener listener);

    AnimationStatus status();

    T value();

    bool isDismissed();

    bool isCompleted();

    Animation<U> drive<U>(Animatable<U> child);

    String toString();

    String toStringDetails();

private:

};

#endif