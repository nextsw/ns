#ifndef DART_UI_HOOKS
#define DART_UI_HOOKS
#include <base.hpp>

#include <dart/core/core.hpp>

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

void _runMain(List<String> args, void  startMainIsolateFunction() , void  userMainFunction() );

void _invoke(void callback() , Zone zone);

template<typename A>
 void _invoke1(A arg, void callback(A a) , Zone zone);

template<typename A1, typename A2>
 void _invoke2(A1 arg1, A2 arg2, void callback(A1 a1, A2 a2) , Zone zone);

template<typename A1, typename A2, typename A3>
 void _invoke3(A1 arg1, A2 arg2, A3 arg3, void callback(A1 a1, A2 a2, A3 a3) , Zone zone);

bool _isLoopback(String host);



#endif