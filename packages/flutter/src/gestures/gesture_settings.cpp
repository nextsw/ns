#include "gesture_settings.hpp"
void DeviceGestureSettings::fromWindow(FlutterView window) {
    double physicalTouchSlop = window.viewConfiguration.gestureSettings.physicalTouchSlop;
    return DeviceGestureSettings(physicalTouchSlop == nullptr? nullptr : physicalTouchSlop / window.devicePixelRatio);
}

double DeviceGestureSettings::panSlop() {
    return touchSlop != nullptr? (touchSlop! * 2) : nullptr;
}

int DeviceGestureSettings::hashCode() {
    return Object.hash(touchSlop, 23);
}

bool DeviceGestureSettings::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is DeviceGestureSettings && other.touchSlop == touchSlop;
}

String DeviceGestureSettings::toString() {
    return "DeviceGestureSettings(touchSlop: $touchSlop)";
}
