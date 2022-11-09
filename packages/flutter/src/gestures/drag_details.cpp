#include "drag_details.hpp"
DragDownDetailsCls::DragDownDetailsCls(Offset globalPosition, Offset localPosition) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition ?? globalPosition;
    }
}

String DragDownDetailsCls::toString() {
    return "${objectRuntimeType(this, 'DragDownDetails')}($globalPosition)";
}

DragStartDetailsCls::DragStartDetailsCls(Offset globalPosition, PointerDeviceKind kind, Offset localPosition, Duration sourceTimeStamp) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition ?? globalPosition;
    }
}

String DragStartDetailsCls::toString() {
    return "${objectRuntimeType(this, 'DragStartDetails')}($globalPosition)";
}

DragUpdateDetailsCls::DragUpdateDetailsCls(Offset delta, Offset globalPosition, Offset localPosition, double primaryDelta, Duration sourceTimeStamp) {
    {
        assert(delta != nullptr);
        assert(primaryDelta == nullptr || (primaryDelta == delta->dx && delta->dy == 0.0) || (primaryDelta == delta->dy && delta->dx == 0.0));
        localPosition = localPosition ?? globalPosition;
    }
}

String DragUpdateDetailsCls::toString() {
    return "${objectRuntimeType(this, 'DragUpdateDetails')}($delta)";
}

DragEndDetailsCls::DragEndDetailsCls(double primaryVelocity, Velocity velocity) {
    {
        assert(velocity != nullptr);
        assert(primaryVelocity == nullptr || primaryVelocity == velocity->pixelsPerSecond->dx || primaryVelocity == velocity->pixelsPerSecond->dy);
    }
}

String DragEndDetailsCls::toString() {
    return "${objectRuntimeType(this, 'DragEndDetails')}($velocity)";
}
