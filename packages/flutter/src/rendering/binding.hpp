#ifndef BINDING_H
#define BINDING_H
#include <memory>
#include <flutter/gestures.hpp>

#include <developer/developer.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/semantics.hpp>
#include <flutter/services.hpp>
#include "box.hpp"
#include "debug.hpp"
#include "mouse_tracker.hpp"
#include "object.hpp"
#include "view.hpp"



class RendererBinding {
public:

    void initInstances();

    static RendererBinding instance();

    void initServiceExtensions();

    void initRenderView();

    MouseTracker mouseTracker();

    PipelineOwner pipelineOwner();

    RenderView renderView();

    void  renderView(RenderView value);

    void handleMetricsChanged();

    void handleTextScaleFactorChanged();

    void handlePlatformBrightnessChanged();

    ViewConfiguration createViewConfiguration();

    void initMouseTracker(MouseTracker tracker);

    void dispatchEvent(PointerEvent event, HitTestResult hitTestResult);

    void setSemanticsEnabled(bool enabled);

    bool sendFramesToEngine();

    void deferFirstFrame();

    void allowFirstFrame();

    void resetFirstFrameSent();

    void drawFrame();

    Future<void> performReassemble();

    void hitTest(Offset position, HitTestResult result);

private:
    static RendererBinding _instance;

    bool _debugIsRenderViewInitialized;

    MouseTracker _mouseTracker;

    PipelineOwner _pipelineOwner;

    SemanticsHandle _semanticsHandle;

    bool _debugMouseTrackerUpdateScheduled;

    int _firstFrameDeferredCount;

    bool _firstFrameSent;


    void _handleSemanticsEnabledChanged();

    void _handleWebFirstFrame(Duration _);

    void _handleSemanticsAction(SemanticsAction action, ByteData args, int id);

    void _handleSemanticsOwnerCreated();

    void _handleSemanticsOwnerDisposed();

    void _handlePersistentFrameCallback(Duration timeStamp);

    void _scheduleMouseTrackerUpdate();

    Future<void> _forceRepaint();

};
void debugDumpRenderTree();

void debugDumpLayerTree();

void debugDumpSemanticsTree(DebugSemanticsDumpOrder childOrder);


class RenderingFlutterBinding : BindingBase {
public:

     RenderingFlutterBinding(RenderBox root);

    static RendererBinding ensureInitialized();

private:

};

#endif