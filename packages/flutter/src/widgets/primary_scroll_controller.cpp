#include "primary_scroll_controller.hpp"
PrimaryScrollController::PrimaryScrollController(Set<TargetPlatform> automaticallyInheritForPlatforms, Unknown, ScrollController controller, Unknown, Axis scrollDirection) {
    {
        assert(controller != nullptr);
    }
}

void PrimaryScrollController::none(Unknown, Unknown)

bool PrimaryScrollController::shouldInherit(BuildContext context, Axis scrollDirection) {
    PrimaryScrollController result = context.<PrimaryScrollController>findAncestorWidgetOfExactType();
    if (result == nullptr) {
        return false;
    }
    TargetPlatform platform = ScrollConfiguration.of(context).getPlatform(context);
    if (result.automaticallyInheritForPlatforms.contains(platform)) {
        return result.scrollDirection == scrollDirection;
    }
    return false;
}

ScrollController PrimaryScrollController::of(BuildContext context) {
    PrimaryScrollController result = context.<PrimaryScrollController>dependOnInheritedWidgetOfExactType();
    return result?.controller;
}

bool PrimaryScrollController::updateShouldNotify(PrimaryScrollController oldWidget) {
    return controller != oldWidget.controller;
}

void PrimaryScrollController::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<ScrollController>DiagnosticsProperty("controller", controller"no controller", false));
}
