#include "animation.hpp"
template<typename T>
bool AnimationCls<T>::isDismissed() {
    return status() == AnimationStatusCls::dismissed;
}

template<typename T>
bool AnimationCls<T>::isCompleted() {
    return status() == AnimationStatusCls::completed;
}

template<typename T>
template<typename U>
Animation<U> AnimationCls<T>::drive(Animatable<U> child) {
    assert(is<Animation<double>>(this));
    return child->animate(as<Animation<double>>(this));
}

template<typename T>
String AnimationCls<T>::toString() {
    return __s("%s$%s;");
}

template<typename T>
String AnimationCls<T>::toStringDetails() {
    assert(status() != nullptr);
    ;
}
