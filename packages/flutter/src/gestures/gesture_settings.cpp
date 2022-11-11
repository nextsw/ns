#include "gesture_settings.hpp"
void DeviceGestureSettingsCls::fromWindow(FlutterView window) {
    double physicalTouchSlop = window->viewConfiguration()->gestureSettings->physicalTouchSlop;
    return make<DeviceGestureSettingsCls>(physicalTouchSlop == nullptr? nullptr : physicalTouchSlop / window->devicePixelRatio());
}

double DeviceGestureSettingsCls::panSlop() {
    return touchSlop != nullptr? (touchSlop! * 2) : nullptr;
}

int DeviceGestureSettingsCls::hashCode() {
    return ObjectCls->hash(touchSlop, 23);
}

bool DeviceGestureSettingsCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<DeviceGestureSettings>(other) && other->touchSlop == touchSlop;
}

String DeviceGestureSettingsCls::toString() {
    return __s("DeviceGestureSettings(touchSlop: $touchSlop)");
}
