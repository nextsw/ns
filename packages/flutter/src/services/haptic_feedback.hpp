#ifndef HAPTIC_FEEDBACK_H
#define HAPTIC_FEEDBACK_H
#include <memory>

#include "system_channels.hpp"



class HapticFeedback {
public:

    static Future<void> vibrate();

    static Future<void> lightImpact();

    static Future<void> mediumImpact();

    static Future<void> heavyImpact();

    static Future<void> selectionClick();

private:

    void  _();

};

#endif