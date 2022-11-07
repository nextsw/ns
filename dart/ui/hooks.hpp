#ifndef HOOKS_H
#define HOOKS_H
#include <memory>



void _updateWindowMetrics(double devicePixelRatio, List<double> displayFeaturesBounds, List<int> displayFeaturesState, List<int> displayFeaturesType, double height, Object id, double physicalTouchSlop, double systemGestureInsetBottom, double systemGestureInsetLeft, double systemGestureInsetRight, double systemGestureInsetTop, double viewInsetBottom, double viewInsetLeft, double viewInsetRight, double viewInsetTop, double viewPaddingBottom, double viewPaddingLeft, double viewPaddingRight, double viewPaddingTop, double width);

_LocaleClosure _getLocaleClosure();

void _updateLocales(List<String> locales);

void _updateUserSettingsData(String jsonData);

void _updateLifecycleState(String state);

void _updateSemanticsEnabled(bool enabled);

void _updateAccessibilityFeatures(int values);

void _dispatchPlatformMessage(ByteData data, String name, int responseId);

void _dispatchPointerDataPacket(ByteData packet);

void _dispatchSemanticsAction(int action, ByteData args, int id);

void _beginFrame(int frameNumber, int microseconds);

void _reportTimings(List<int> timings);

void _drawFrame();

bool _onError(Object error, StackTrace stackTrace);

void _runMain(List<String> args, FunctionType startMainIsolateFunction, FunctionType userMainFunction);

void _invoke(FunctionType callback, Zone zone);

void _invoke1<A>(A arg, FunctionType callback, Zone zone);

void _invoke2<A1, A2>(A1 arg1, A2 arg2, FunctionType callback, Zone zone);

void _invoke3<A1, A2, A3>(A1 arg1, A2 arg2, A3 arg3, FunctionType callback, Zone zone);

bool _isLoopback(String host);


#endif