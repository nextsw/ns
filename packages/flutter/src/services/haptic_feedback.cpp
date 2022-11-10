#include "haptic_feedback.hpp"
Future<void> HapticFeedbackCls::vibrate() {
    await await SystemChannelsCls::platform-><void>invokeMethod(__s("HapticFeedback.vibrate"));
}

Future<void> HapticFeedbackCls::lightImpact() {
    await await SystemChannelsCls::platform-><void>invokeMethod(__s("HapticFeedback.vibrate"), __s("HapticFeedbackType.lightImpact"));
}

Future<void> HapticFeedbackCls::mediumImpact() {
    await await SystemChannelsCls::platform-><void>invokeMethod(__s("HapticFeedback.vibrate"), __s("HapticFeedbackType.mediumImpact"));
}

Future<void> HapticFeedbackCls::heavyImpact() {
    await await SystemChannelsCls::platform-><void>invokeMethod(__s("HapticFeedback.vibrate"), __s("HapticFeedbackType.heavyImpact"));
}

Future<void> HapticFeedbackCls::selectionClick() {
    await await SystemChannelsCls::platform-><void>invokeMethod(__s("HapticFeedback.vibrate"), __s("HapticFeedbackType.selectionClick"));
}
