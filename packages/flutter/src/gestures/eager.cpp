#include "eager.hpp"
void EagerGestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
    super->addAllowedPointer(event);
    resolve(GestureDispositionCls::accepted);
    stopTrackingPointer(event->pointer);
}

String EagerGestureRecognizerCls::debugDescription() {
    return "eager";
}

void EagerGestureRecognizerCls::didStopTrackingLastPointer(int pointer) {
}

void EagerGestureRecognizerCls::handleEvent(PointerEvent event) {
}
