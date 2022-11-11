#ifndef PACKAGES_FLUTTER_SRC_SERVICES_PLATFORM_VIEWS
#define PACKAGES_FLUTTER_SRC_SERVICES_PLATFORM_VIEWS
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/flutter.hpp>
#include "message_codec.hpp"

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "message_codec.hpp"
#include "system_channels.hpp"

PlatformViewsRegistry platformViewsRegistry;


class PlatformViewsRegistryCls : public ObjectCls {
public:

    virtual int getNextPlatformViewId();

private:
    int _nextPlatformViewId;


    virtual void  _instance();
};
using PlatformViewsRegistry = std::shared_ptr<PlatformViewsRegistryCls>;

class PlatformViewsServiceCls : public ObjectCls {
public:

    static AndroidViewController initAndroidView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType);

    static SurfaceAndroidViewController initSurfaceAndroidView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType);

    static ExpensiveAndroidViewController initExpensiveAndroidView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType);

    static Future<void> synchronizeToNativeViewHierarchy(bool yes);

    static Future<UiKitViewController> initUiKitView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, int id, TextDirection layoutDirection, VoidCallback onFocus, String viewType);

private:
    static PlatformViewsService _instance;

    Map<int, VoidCallback> _focusCallbacks;


    virtual void  _();

    virtual Future<void> _onMethodCall(MethodCall call);

};
using PlatformViewsService = std::shared_ptr<PlatformViewsServiceCls>;

class AndroidPointerPropertiesCls : public ObjectCls {
public:
    int id;

    int toolType;

    static int kToolTypeUnknown;

    static int kToolTypeFinger;

    static int kToolTypeStylus;

    static int kToolTypeMouse;

    static int kToolTypeEraser;


     AndroidPointerPropertiesCls(int id, int toolType);

    virtual String toString();

private:

    virtual List<int> _asList();

};
using AndroidPointerProperties = std::shared_ptr<AndroidPointerPropertiesCls>;

class AndroidPointerCoordsCls : public ObjectCls {
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


     AndroidPointerCoordsCls(double orientation, double pressure, double size, double toolMajor, double toolMinor, double touchMajor, double touchMinor, double x, double y);

    virtual String toString();

private:

    virtual List<double> _asList();

};
using AndroidPointerCoords = std::shared_ptr<AndroidPointerCoordsCls>;

class AndroidMotionEventCls : public ObjectCls {
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


     AndroidMotionEventCls(int action, int buttonState, int deviceId, int downTime, int edgeFlags, int eventTime, int flags, int metaState, int motionEventId, List<AndroidPointerCoords> pointerCoords, int pointerCount, List<AndroidPointerProperties> pointerProperties, int source, double xPrecision, double yPrecision);

    virtual String toString();

private:

    virtual List<dynamic> _asList(int viewId);

};
using AndroidMotionEvent = std::shared_ptr<AndroidMotionEventCls>;

enum _AndroidViewState{
    waitingForSize,
    creating,
    created,
    disposed,
} // end _AndroidViewState

class _AndroidMotionEventConverterCls : public ObjectCls {
public:
    Map<int, AndroidPointerCoords> pointerPositions;

    Map<int, AndroidPointerProperties> pointerProperties;

    Set<int> usedAndroidPointerIds;

    int downTimeMillis;


    virtual PointTransformer pointTransformer();

    virtual void  pointTransformer(PointTransformer transformer);

    virtual void handlePointerDownEvent(PointerDownEvent event);

    virtual void updatePointerPositions(PointerEvent event);

    virtual void handlePointerUpEvent(PointerUpEvent event);

    virtual void handlePointerCancelEvent(PointerCancelEvent event);

    virtual AndroidMotionEvent toAndroidMotionEvent(PointerEvent event);

    virtual AndroidPointerProperties propertiesFor(PointerEvent event, int pointerId);

    virtual bool isSinglePointerAction(PointerEvent event);

private:
    PointTransformer _pointTransformer;


     _AndroidMotionEventConverterCls();
    virtual void _remove(int pointer);

};
using _AndroidMotionEventConverter = std::shared_ptr<_AndroidMotionEventConverterCls>;

class AndroidViewControllerCls : public PlatformViewControllerCls {
public:
    static int kActionDown;

    static int kActionUp;

    static int kActionMove;

    static int kActionCancel;

    static int kActionPointerDown;

    static int kActionPointerUp;

    static int kAndroidLayoutDirectionLtr;

    static int kAndroidLayoutDirectionRtl;

    int viewId;


    static int pointerAction(int pointerId, int action);

    virtual bool awaitingCreation();

    virtual Future<void> create(Size size);

    virtual Future<Size> setSize(Size size);

    virtual Future<void> setOffset(Offset off);
    virtual int textureId();
    virtual Future<void> sendMotionEvent(AndroidMotionEvent event);

    virtual PointTransformer pointTransformer();

    virtual void  pointTransformer(PointTransformer transformer);

    virtual bool isCreated();

    virtual void addOnPlatformViewCreatedListener(PlatformViewCreatedCallback listener);

    virtual void removeOnPlatformViewCreatedListener(PlatformViewCreatedCallback listener);

    virtual List<PlatformViewCreatedCallback> createdCallbacks();

    virtual Future<void> setLayoutDirection(TextDirection layoutDirection);

    virtual Future<void> dispatchPointerEvent(PointerEvent event);

    virtual Future<void> clearFocus();

    virtual Future<void> dispose();

private:
    String _viewType;

    _AndroidMotionEventConverter _motionEventConverter;

    TextDirection _layoutDirection;

    _AndroidViewState _state;

    dynamic _creationParams;

    MessageCodec<dynamic> _creationParamsCodec;

    List<PlatformViewCreatedCallback> _platformViewCreatedCallbacks;


    virtual void  _(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, TextDirection layoutDirection, int viewId, String viewType);

    static int _getAndroidDirection(TextDirection direction);

    virtual Future<void> _sendDisposeMessage();
    virtual bool _createRequiresSize();
    virtual Future<void> _sendCreateMessage(Size size);
    virtual Future<Size> _sendResizeMessage(Size size);
};
using AndroidViewController = std::shared_ptr<AndroidViewControllerCls>;

class SurfaceAndroidViewControllerCls : public TextureAndroidViewControllerCls {
public:

private:

    virtual void  _(Unknown creationParams, Unknown creationParamsCodec, Unknown layoutDirection, Unknown viewId, Unknown viewType);

};
using SurfaceAndroidViewController = std::shared_ptr<SurfaceAndroidViewControllerCls>;

class ExpensiveAndroidViewControllerCls : public AndroidViewControllerCls {
public:

    virtual int textureId();

    virtual Future<void> setOffset(Offset off);

private:

    virtual void  _(Unknown creationParams, Unknown creationParamsCodec, Unknown layoutDirection, Unknown viewId, Unknown viewType);

    virtual bool _createRequiresSize();

    virtual Future<void> _sendCreateMessage(Size size);

    virtual Future<void> _sendDisposeMessage();

    virtual Future<Size> _sendResizeMessage(Size size);

};
using ExpensiveAndroidViewController = std::shared_ptr<ExpensiveAndroidViewControllerCls>;

class TextureAndroidViewControllerCls : public AndroidViewControllerCls {
public:

    virtual int textureId();

    virtual Future<void> setOffset(Offset off);

private:
    int _textureId;

    Offset _off;


    virtual void  _(Unknown creationParams, Unknown creationParamsCodec, Unknown layoutDirection, Unknown viewId, Unknown viewType);

    virtual Future<Size> _sendResizeMessage(Size size);

    virtual bool _createRequiresSize();

    virtual Future<void> _sendCreateMessage(Size size);

    virtual Future<void> _sendDisposeMessage();

};
using TextureAndroidViewController = std::shared_ptr<TextureAndroidViewControllerCls>;

class UiKitViewControllerCls : public ObjectCls {
public:
    int id;


    virtual Future<void> setLayoutDirection(TextDirection layoutDirection);

    virtual Future<void> acceptGesture();

    virtual Future<void> rejectGesture();

    virtual Future<void> dispose();

private:
    bool _debugDisposed;

    TextDirection _layoutDirection;


    virtual void  _(int id, TextDirection layoutDirection);

};
using UiKitViewController = std::shared_ptr<UiKitViewControllerCls>;

class PlatformViewControllerCls : public ObjectCls {
public:

    virtual int viewId();
    virtual bool awaitingCreation();

    virtual Future<void> dispatchPointerEvent(PointerEvent event);
    virtual Future<void> create(Size size);

    virtual Future<void> dispose();
    virtual Future<void> clearFocus();
private:

};
using PlatformViewController = std::shared_ptr<PlatformViewControllerCls>;


#endif