#ifndef PACKAGES_FLUTTER_SRC_SERVICES_HAPTIC_FEEDBACK
#define PACKAGES_FLUTTER_SRC_SERVICES_HAPTIC_FEEDBACK
#include <base.hpp>

#include <dart/core/core.hpp>
#include "system_channels.hpp"


class HapticFeedbackCls : public ObjectCls {
public:

    static Future<void> vibrate();

    static Future<void> lightImpact();

    static Future<void> mediumImpact();

    static Future<void> heavyImpact();

    static Future<void> selectionClick();

private:

    virtual void  _();
};
using HapticFeedback = std::shared_ptr<HapticFeedbackCls>;


#endif