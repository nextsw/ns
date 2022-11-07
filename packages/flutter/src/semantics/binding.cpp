#include "binding.hpp"
void SemanticsBinding::initInstances() {
    super.initInstances();
    _instance = this;
    _accessibilityFeatures = platformDispatcher.accessibilityFeatures;
}

SemanticsBinding SemanticsBinding::instance() {
    return BindingBase.checkInstance(_instance);
}

void SemanticsBinding::handleAccessibilityFeaturesChanged() {
    _accessibilityFeatures = platformDispatcher.accessibilityFeatures;
}

SemanticsUpdateBuilder SemanticsBinding::createSemanticsUpdateBuilder() {
    return ui.SemanticsUpdateBuilder();
}

AccessibilityFeatures SemanticsBinding::accessibilityFeatures() {
    return _accessibilityFeatures;
}

bool SemanticsBinding::disableAnimations() {
    bool value = _accessibilityFeatures.disableAnimations;
    assert(());
    return value;
}
