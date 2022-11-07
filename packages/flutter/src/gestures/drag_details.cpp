#include "drag_details.hpp"
DragDownDetails::DragDownDetails(Offset globalPosition, Offset localPosition) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition ?? globalPosition;
    }
}

String DragDownDetails::toString() {
    return "${objectRuntimeType(this, 'DragDownDetails')}($globalPosition)";
}

DragStartDetails::DragStartDetails(Offset globalPosition, PointerDeviceKind kind, Offset localPosition, Duration sourceTimeStamp) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition ?? globalPosition;
    }
}

String DragStartDetails::toString() {
    return "${objectRuntimeType(this, 'DragStartDetails')}($globalPosition)";
}

DragUpdateDetails::DragUpdateDetails(Offset delta, Offset globalPosition, Offset localPosition, double primaryDelta, Duration sourceTimeStamp) {
    {
        assert(delta != nullptr);
        assert(primaryDelta == nullptr || (primaryDelta == delta.dx && delta.dy == 0.0) || (primaryDelta == delta.dy && delta.dx == 0.0));
        localPosition = localPosition ?? globalPosition;
    }
}

String DragUpdateDetails::toString() {
    return "${objectRuntimeType(this, 'DragUpdateDetails')}($delta)";
}

DragEndDetails::DragEndDetails(double primaryVelocity, Velocity velocity) {
    {
        assert(velocity != nullptr);
        assert(primaryVelocity == nullptr || primaryVelocity == velocity.pixelsPerSecond.dx || primaryVelocity == velocity.pixelsPerSecond.dy);
    }
}

String DragEndDetails::toString() {
    return "${objectRuntimeType(this, 'DragEndDetails')}($velocity)";
}
