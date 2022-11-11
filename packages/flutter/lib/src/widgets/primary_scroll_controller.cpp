#include "primary_scroll_controller.hpp"
PrimaryScrollControllerCls::PrimaryScrollControllerCls(Set<TargetPlatform> automaticallyInheritForPlatforms, Unknown child, ScrollController controller, Unknown key, Axis scrollDirection) {
    {
        assert(controller != nullptr);
    }
}

void PrimaryScrollControllerCls::none(Unknown child, Unknown key)

bool PrimaryScrollControllerCls::shouldInherit(BuildContext context, Axis scrollDirection) {
    PrimaryScrollController result = context-><PrimaryScrollController>findAncestorWidgetOfExactType();
    if (result == nullptr) {
        return false;
    }
    TargetPlatform platform = ScrollConfigurationCls->of(context)->getPlatform(context);
    if (result->automaticallyInheritForPlatforms->contains(platform)) {
        return result->scrollDirection == scrollDirection;
    }
    return false;
}

ScrollController PrimaryScrollControllerCls::of(BuildContext context) {
    PrimaryScrollController result = context-><PrimaryScrollController>dependOnInheritedWidgetOfExactType();
    return result?->controller;
}

bool PrimaryScrollControllerCls::updateShouldNotify(PrimaryScrollController oldWidget) {
    return controller != oldWidget->controller;
}

void PrimaryScrollControllerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<ScrollController>make<DiagnosticsPropertyCls>(__s("controller"), controller, __s("no controller"), false));
}
