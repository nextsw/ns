#include "haptic_feedback.hpp"
Future<void> HapticFeedback::vibrate() {
    await await SystemChannels.platform.<void>invokeMethod("HapticFeedback.vibrate");
}

Future<void> HapticFeedback::lightImpact() {
    await await SystemChannels.platform.<void>invokeMethod("HapticFeedback.vibrate", "HapticFeedbackType.lightImpact");
}

Future<void> HapticFeedback::mediumImpact() {
    await await SystemChannels.platform.<void>invokeMethod("HapticFeedback.vibrate", "HapticFeedbackType.mediumImpact");
}

Future<void> HapticFeedback::heavyImpact() {
    await await SystemChannels.platform.<void>invokeMethod("HapticFeedback.vibrate", "HapticFeedbackType.heavyImpact");
}

Future<void> HapticFeedback::selectionClick() {
    await await SystemChannels.platform.<void>invokeMethod("HapticFeedback.vibrate", "HapticFeedbackType.selectionClick");
}
