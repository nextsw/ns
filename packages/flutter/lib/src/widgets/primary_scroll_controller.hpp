#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PRIMARY_SCROLL_CONTROLLER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PRIMARY_SCROLL_CONTROLLER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "framework.hpp"
#include "scroll_configuration.hpp"
#include "scroll_controller.hpp"

Set<TargetPlatform> _kMobilePlatforms;


class PrimaryScrollControllerCls : public InheritedWidgetCls {
public:
    ScrollController controller;

    Axis scrollDirection;

    Set<TargetPlatform> automaticallyInheritForPlatforms;


     PrimaryScrollControllerCls(Set<TargetPlatform> automaticallyInheritForPlatforms, Unknown child, ScrollController controller, Unknown key, Axis scrollDirection);

    virtual void  none(Unknown child, Unknown key);

    static bool shouldInherit(BuildContext context, Axis scrollDirection);

    static ScrollController of(BuildContext context);

    virtual bool updateShouldNotify(PrimaryScrollController oldWidget);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using PrimaryScrollController = std::shared_ptr<PrimaryScrollControllerCls>;


#endif