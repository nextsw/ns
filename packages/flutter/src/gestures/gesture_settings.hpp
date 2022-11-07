#ifndef GESTURE_SETTINGS_H
#define GESTURE_SETTINGS_H
#include <memory>
#include <ui.hpp>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>



class DeviceGestureSettings {
public:
    double touchSlop;


     DeviceGestureSettings(double touchSlop);

    void  fromWindow(FlutterView window);

    double panSlop();

    int hashCode();

    bool ==(Object other);

    String toString();

private:

};

#endif