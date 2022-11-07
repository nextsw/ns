#include "animation.hpp"
bool Animation::isDismissed() {
    return status == AnimationStatus.dismissed;
}

bool Animation::isCompleted() {
    return status == AnimationStatus.completed;
}

Animation<U> Animation::drive<U>(Animatable<U> child) {
    assert(this is Animation<double>);
    return child.animate(();
}

String Animation::toString() {
    return "${describeIdentity(this)}(${toStringDetails()})";
}

String Animation::toStringDetails() {
    assert(status != nullptr);
    ;
}
