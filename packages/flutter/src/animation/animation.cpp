#include "animation.hpp"
template<typename T> bool AnimationCls<T>::isDismissed() {
    return status == AnimationStatusCls::dismissed;
}

template<typename T> bool AnimationCls<T>::isCompleted() {
    return status == AnimationStatusCls::completed;
}

template<typename T> Animation<U> AnimationCls<T>::drivetemplate<typename U> (Animatable<U> child) {
    assert(this is Animation<double>);
    return child->animate(((Animation<double>)this));
}

template<typename T> String AnimationCls<T>::toString() {
    return "${describeIdentity(this)}(${toStringDetails()})";
}

template<typename T> String AnimationCls<T>::toStringDetails() {
    assert(status != nullptr);
    ;
}
