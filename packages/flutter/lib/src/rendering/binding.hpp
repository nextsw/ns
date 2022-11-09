#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_BINDING
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_BINDING
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <dart/developer/developer.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "box.hpp"
#include "debug.hpp"
#include "mouse_tracker.hpp"
#include "object.hpp"
#include "view.hpp"


class RendererBindingCls : public ObjectCls {
public:

    virtual void initInstances();

    static RendererBinding instance();

    virtual void initServiceExtensions();

    virtual void initRenderView();

    virtual MouseTracker mouseTracker();

    virtual PipelineOwner pipelineOwner();

    virtual RenderView renderView();

    virtual void  renderView(RenderView value);

    virtual void handleMetricsChanged();

    virtual void handleTextScaleFactorChanged();

    virtual void handlePlatformBrightnessChanged();

    virtual ViewConfiguration createViewConfiguration();

    virtual void initMouseTracker(MouseTracker tracker);

    virtual void dispatchEvent(PointerEvent event, HitTestResult hitTestResult);

    virtual void setSemanticsEnabled(bool enabled);

    virtual bool sendFramesToEngine();

    virtual void deferFirstFrame();

    virtual void allowFirstFrame();

    virtual void resetFirstFrameSent();

    virtual void drawFrame();

    virtual Future<void> performReassemble();

    virtual void hitTest(Offset position, HitTestResult result);

private:
    static RendererBinding _instance;

    bool _debugIsRenderViewInitialized;

    MouseTracker _mouseTracker;

    PipelineOwner _pipelineOwner;

    SemanticsHandle _semanticsHandle;

    bool _debugMouseTrackerUpdateScheduled;

    int _firstFrameDeferredCount;

    bool _firstFrameSent;


    virtual void _handleSemanticsEnabledChanged();

    virtual void _handleWebFirstFrame(Duration _);

    virtual void _handleSemanticsAction(SemanticsAction action, ByteData args, int id);

    virtual void _handleSemanticsOwnerCreated();

    virtual void _handleSemanticsOwnerDisposed();

    virtual void _handlePersistentFrameCallback(Duration timeStamp);

    virtual void _scheduleMouseTrackerUpdate();

    virtual Future<void> _forceRepaint();

};
using RendererBinding = std::shared_ptr<RendererBindingCls>;
void debugDumpRenderTree();

void debugDumpLayerTree();

void debugDumpSemanticsTree(DebugSemanticsDumpOrder childOrder);


class RenderingFlutterBindingCls : public BindingBaseCls {
public:

     RenderingFlutterBindingCls(RenderBox root);

    static RendererBinding ensureInitialized();

private:

};
using RenderingFlutterBinding = std::shared_ptr<RenderingFlutterBindingCls>;


#endif