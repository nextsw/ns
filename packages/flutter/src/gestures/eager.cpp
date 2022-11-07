#include "eager.hpp"
void EagerGestureRecognizer::addAllowedPointer(PointerDownEvent event) {
    super.addAllowedPointer(event);
    resolve(GestureDisposition.accepted);
    stopTrackingPointer(event.pointer);
}

String EagerGestureRecognizer::debugDescription() {
    return "eager";
}

void EagerGestureRecognizer::didStopTrackingLastPointer(int pointer) {
}

void EagerGestureRecognizer::handleEvent(PointerEvent event) {
}
