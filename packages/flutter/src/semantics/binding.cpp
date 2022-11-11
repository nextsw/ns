#include "binding.hpp"
void SemanticsBindingCls::initInstances() {
    super->initInstances();
    _instance = this;
    _accessibilityFeatures = platformDispatcher->accessibilityFeatures();
}

SemanticsBinding SemanticsBindingCls::instance() {
    return BindingBaseCls->checkInstance(_instance);
}

void SemanticsBindingCls::handleAccessibilityFeaturesChanged() {
    _accessibilityFeatures = platformDispatcher->accessibilityFeatures();
}

SemanticsUpdateBuilder SemanticsBindingCls::createSemanticsUpdateBuilder() {
    return ui->make<SemanticsUpdateBuilderCls>();
}

AccessibilityFeatures SemanticsBindingCls::accessibilityFeatures() {
    return _accessibilityFeatures;
}

bool SemanticsBindingCls::disableAnimations() {
    bool value = _accessibilityFeatures->disableAnimations();
    assert([=] () {
        if (debugSemanticsDisableAnimations != nullptr) {
            value = debugSemanticsDisableAnimations!;
        }
        return true;
    }());
    return value;
}
