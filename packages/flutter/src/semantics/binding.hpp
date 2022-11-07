#ifndef BINDING_H
#define BINDING_H
#include <memory>
#include <ui.hpp>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "debug.hpp"



class SemanticsBinding {
public:

    void initInstances();

    static SemanticsBinding instance();

    void handleAccessibilityFeaturesChanged();

    SemanticsUpdateBuilder createSemanticsUpdateBuilder();

    AccessibilityFeatures accessibilityFeatures();

    bool disableAnimations();

private:
    static SemanticsBinding _instance;

    AccessibilityFeatures _accessibilityFeatures;


};

#endif