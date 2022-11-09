#ifndef PACKAGES_FLUTTER_SRC_SEMANTICS_BINDING
#define PACKAGES_FLUTTER_SRC_SEMANTICS_BINDING
#include <base.hpp>
#include <dart/ui/ui.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "debug.hpp"


class SemanticsBindingCls : public ObjectCls {
public:

    virtual void initInstances();

    static SemanticsBinding instance();

    virtual void handleAccessibilityFeaturesChanged();

    virtual SemanticsUpdateBuilder createSemanticsUpdateBuilder();

    virtual AccessibilityFeatures accessibilityFeatures();

    virtual bool disableAnimations();

private:
    static SemanticsBinding _instance;

    AccessibilityFeatures _accessibilityFeatures;


};
using SemanticsBinding = std::shared_ptr<SemanticsBindingCls>;


#endif