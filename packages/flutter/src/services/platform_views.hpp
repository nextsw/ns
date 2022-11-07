#ifndef PLATFORM_VIEWS_H
#define PLATFORM_VIEWS_H
#include <memory>
#include <ui.hpp>
#include <flutter/gestures.hpp>
#include "message_codec.hpp"

#include <async/async.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include "message_codec.hpp"
#include "system_channels.hpp"


PlatformViewsRegistry platformViewsRegistry;


class PlatformViewsRegistry {
public:

    int getNextPlatformViewId();

private:
    int _nextPlatformViewId;


    void  _instance();

};

class PlatformViewsService {
public:

    static AndroidViewController initAndroidView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType);

    static SurfaceAndroidViewController initSurfaceAndroidView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType);

    static ExpensiveAndroidViewController initExpensiveAndroidView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType);

    static Future<void> synchronizeToNativeViewHierarchy(bool yes);

    static Future<UiKitViewController> initUiKitView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType);

private:
    static PlatformViewsService _instance;

    Map<int, VoidCallback> _focusCallbacks;


    void  _();

    Future<void> _onMethodCall(MethodCall call);

};

class AndroidPointerProperties {
public:
    int id;

    int toolType;

    static const int kToolTypeUnknown;

    static const int kToolTypeFinger;

    static const int kToolTypeStylus;

    static const int kToolTypeMouse;

    static const int kToolTypeEraser;


     AndroidPointerProperties(int id, int toolType);

    String toString();

private:

    List<int> _asList();

};

class AndroidPointerCoords {
public:
    double orientation;

    double pressure;

    double size;

    double toolMajor;

    double toolMinor;

    double touchMajor;

    double touchMinor;

    double x;

    double y;


     AndroidPointerCoords(double orientation, double pressure, double size, double toolMajor, double toolMinor, double touchMajor, double touchMinor, double x, double y);

    String toString();

private:

    List<double> _asList();

};

class AndroidMotionEvent {
public:
    int downTime;

    int eventTime;

    int action;

    int pointerCount;

    List<AndroidPointerProperties> pointerProperties;

    List<AndroidPointerCoords> pointerCoords;

    int metaState;

    int buttonState;

    double xPrecision;

    double yPrecision;

    int deviceId;

    int edgeFlags;

    int source;

    int flags;

    int motionEventId;


     AndroidMotionEvent(int action, int buttonState, int deviceId, int downTime, int edgeFlags, int eventTime, int flags, int metaState, int motionEventId, List<AndroidPointerCoords> pointerCoords, int pointerCount, List<AndroidPointerProperties> pointerProperties, int source, double xPrecision, double yPrecision);

    String toString();

private:

    List<dynamic> _asList(int viewId);

};

enum _AndroidViewState{
    waitingForSize,
    creating,
    created,
    disposed,
} // end _AndroidViewState

class _AndroidMotionEventConverter {
public:
    Map<int, AndroidPointerCoords> pointerPositions;

    Map<int, AndroidPointerProperties> pointerProperties;

    Set<int> usedAndroidPointerIds;

    int downTimeMillis;


    PointTransformer pointTransformer();

    void  pointTransformer(PointTransformer transformer);

    void handlePointerDownEvent(PointerDownEvent event);

    void updatePointerPositions(PointerEvent event);

    void handlePointerUpEvent(PointerUpEvent event);

    void handlePointerCancelEvent(PointerCancelEvent event);

    AndroidMotionEvent toAndroidMotionEvent(PointerEvent event);

    AndroidPointerProperties propertiesFor(PointerEvent event, int pointerId);

    bool isSinglePointerAction(PointerEvent event);

private:
    PointTransformer _pointTransformer;


     _AndroidMotionEventConverter();

    void _remove(int pointer);

};

class AndroidViewController : PlatformViewController {
public:
    static const int kActionDown;

    static const int kActionUp;

    static const int kActionMove;

    static const int kActionCancel;

    static const int kActionPointerDown;

    static const int kActionPointerUp;

    static const int kAndroidLayoutDirectionLtr;

    static const int kAndroidLayoutDirectionRtl;

    int viewId;


    static int pointerAction(int action, int pointerId);

    bool awaitingCreation();

    Future<void> create(Size size);

    Future<Size> setSize(Size size);

    Future<void> setOffset(Offset off);

    int textureId();

    Future<void> sendMotionEvent(AndroidMotionEvent event);

    PointTransformer pointTransformer();

    void  pointTransformer(PointTransformer transformer);

    bool isCreated();

    void addOnPlatformViewCreatedListener(PlatformViewCreatedCallback listener);

    void removeOnPlatformViewCreatedListener(PlatformViewCreatedCallback listener);

    List<PlatformViewCreatedCallback> createdCallbacks();

    Future<void> setLayoutDirection(TextDirection layoutDirection);

    Future<void> dispatchPointerEvent(PointerEvent event);

    Future<void> clearFocus();

    Future<void> dispose();

private:
    String _viewType;

    _AndroidMotionEventConverter _motionEventConverter;

    TextDirection _layoutDirection;

    _AndroidViewState _state;

    dynamic _creationParams;

    MessageCodec<dynamic> _creationParamsCodec;

    List<PlatformViewCreatedCallback> _platformViewCreatedCallbacks;


    void  _(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, TextDirection layoutDirection, int viewId, String viewType);

    static int _getAndroidDirection(TextDirection direction);

    Future<void> _sendDisposeMessage();

    bool _createRequiresSize();

    Future<void> _sendCreateMessage(Size size);

    Future<Size> _sendResizeMessage(Size size);

};

class SurfaceAndroidViewController : TextureAndroidViewController {
public:

private:

    void  _(Unknown, Unknown, Unknown, Unknown, Unknown);

};

class ExpensiveAndroidViewController : AndroidViewController {
public:

    int textureId();

    Future<void> setOffset(Offset off);

private:

    void  _(Unknown, Unknown, Unknown, Unknown, Unknown);

    bool _createRequiresSize();

    Future<void> _sendCreateMessage(Size size);

    Future<void> _sendDisposeMessage();

    Future<Size> _sendResizeMessage(Size size);

};

class TextureAndroidViewController : AndroidViewController {
public:

    int textureId();

    Future<void> setOffset(Offset off);

private:
    int _textureId;

    Offset _off;


    void  _(Unknown, Unknown, Unknown, Unknown, Unknown);

    Future<Size> _sendResizeMessage(Size size);

    bool _createRequiresSize();

    Future<void> _sendCreateMessage(Size size);

    Future<void> _sendDisposeMessage();

};

class UiKitViewController {
public:
    int id;


    Future<void> setLayoutDirection(TextDirection layoutDirection);

    Future<void> acceptGesture();

    Future<void> rejectGesture();

    Future<void> dispose();

private:
    bool _debugDisposed;

    TextDirection _layoutDirection;


    void  _(int id, TextDirection layoutDirection);

};

class PlatformViewController {
public:

    int viewId();

    bool awaitingCreation();

    Future<void> dispatchPointerEvent(PointerEvent event);

    Future<void> create(Size size);

    Future<void> dispose();

    Future<void> clearFocus();

private:

};

#endif