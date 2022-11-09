#ifndef PACKAGES_FLUTTER_SRC_GESTURES_GESTURE_SETTINGS
#define PACKAGES_FLUTTER_SRC_GESTURES_GESTURE_SETTINGS
#include <base.hpp>
#include <dart/ui/ui.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>


class DeviceGestureSettingsCls : public ObjectCls {
public:
    double touchSlop;


     DeviceGestureSettingsCls(double touchSlop);
    virtual void  fromWindow(FlutterView window);

    virtual double panSlop();

    virtual int hashCode();

    virtual bool operator==(Object other);

    virtual String toString();

private:

};
using DeviceGestureSettings = std::shared_ptr<DeviceGestureSettingsCls>;


#endif