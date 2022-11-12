#ifndef DART_UI_HOOKS
#define DART_UI_HOOKS
#include <base.hpp>

#include <dart/core/core.hpp>

void _updateWindowMetrics(Object id, double devicePixelRatio, double width, double height, double viewPaddingTop, double viewPaddingRight, double viewPaddingBottom, double viewPaddingLeft, double viewInsetTop, double viewInsetRight, double viewInsetBottom, double viewInsetLeft, double systemGestureInsetTop, double systemGestureInsetRight, double systemGestureInsetBottom, double systemGestureInsetLeft, double physicalTouchSlop, List<double> displayFeaturesBounds, List<int> displayFeaturesType, List<int> displayFeaturesState);

_LocaleClosure _getLocaleClosure();

void _updateLocales(List<String> locales);

void _updateUserSettingsData(String jsonData);

void _updateLifecycleState(String state);

void _updateSemanticsEnabled(bool enabled);

void _updateAccessibilityFeatures(int values);

void _dispatchPlatformMessage(String name, ByteData data, int responseId);

void _dispatchPointerDataPacket(ByteData packet);

void _dispatchSemanticsAction(int id, int action, ByteData args);

void _beginFrame(int microseconds, int frameNumber);

void _reportTimings(List<int> timings);

void _drawFrame();

bool _onError(Object error, StackTrace stackTrace);

void _runMain(std::function<void ()> startMainIsolateFunction, std::function<void ()> userMainFunction, List<String> args);

void _invoke(std::function<void()> callback, Zone zone);

template<typename A>
 void _invoke1(std::function<void(A a)> callback, Zone zone, A arg);

template<typename A1, typename A2>
 void _invoke2(std::function<void(A1 a1, A2 a2)> callback, Zone zone, A1 arg1, A2 arg2);

template<typename A1, typename A2, typename A3>
 void _invoke3(std::function<void(A1 a1, A2 a2, A3 a3)> callback, Zone zone, A1 arg1, A2 arg2, A3 arg3);

bool _isLoopback(String host);

std::function<void(Uri )> _getHttpConnectionHookClosure(bool mayInsecurelyConnectToAllDomains);



#endif