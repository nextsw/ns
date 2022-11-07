#ifndef PRIMARY_SCROLL_CONTROLLER_H
#define PRIMARY_SCROLL_CONTROLLER_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/painting.hpp>
#include "framework.hpp"
#include "scroll_configuration.hpp"
#include "scroll_controller.hpp"


const Set<TargetPlatform> _kMobilePlatforms;


class PrimaryScrollController : InheritedWidget {
public:
    ScrollController controller;

    Axis scrollDirection;

    Set<TargetPlatform> automaticallyInheritForPlatforms;


     PrimaryScrollController(Set<TargetPlatform> automaticallyInheritForPlatforms, Unknown, ScrollController controller, Unknown, Axis scrollDirection);

    void  none(Unknown, Unknown);

    static bool shouldInherit(BuildContext context, Axis scrollDirection);

    static ScrollController of(BuildContext context);

    bool updateShouldNotify(PrimaryScrollController oldWidget);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif