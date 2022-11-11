#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SEMANTICS_DEBUGGER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SEMANTICS_DEBUGGER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"


class SemanticsDebuggerCls : public StatefulWidgetCls {
public:
    Widget child;

    TextStyle labelStyle;


     SemanticsDebuggerCls(Widget child, Key key, TextStyle labelStyle);

    virtual State<SemanticsDebugger> createState();

private:

};
using SemanticsDebugger = std::shared_ptr<SemanticsDebuggerCls>;

class _SemanticsDebuggerStateCls : public StateCls<SemanticsDebugger> {
public:

    virtual void initState();

    virtual void dispose();

    virtual void didChangeMetrics();

    virtual Widget build(BuildContext context);

private:
    _SemanticsClient _client;

    Offset _lastPointerDownLocation;


    virtual void _update();

    virtual void _handlePointerDown(PointerDownEvent event);

    virtual void _handleTap();

    virtual void _handleLongPress();

    virtual void _handlePanEnd(DragEndDetails details);

    virtual void _performAction(Offset position, SemanticsAction action);

    virtual PipelineOwner _pipelineOwner();

};
using _SemanticsDebuggerState = std::shared_ptr<_SemanticsDebuggerStateCls>;

class _SemanticsClientCls : public ChangeNotifierCls {
public:
    int generation;


    virtual void dispose();

private:
    SemanticsHandle _semanticsHandle;


     _SemanticsClientCls(PipelineOwner pipelineOwner);

    virtual void _didUpdateSemantics();

};
using _SemanticsClient = std::shared_ptr<_SemanticsClientCls>;

class _SemanticsDebuggerPainterCls : public CustomPainterCls {
public:
    PipelineOwner owner;

    int generation;

    Offset pointerPosition;

    double devicePixelRatio;

    TextStyle labelStyle;


    virtual void paint(Canvas canvas, Size size);

    virtual bool shouldRepaint(_SemanticsDebuggerPainter oldDelegate);

    virtual String getMessage(SemanticsNode node);

private:

     _SemanticsDebuggerPainterCls(PipelineOwner owner, int generation, Offset pointerPosition, double devicePixelRatio, TextStyle labelStyle);
    virtual SemanticsNode _rootSemanticsNode();

    virtual void _paintMessage(Canvas canvas, SemanticsNode node);

    virtual int _findDepth(SemanticsNode node);

    virtual void _paint(Canvas canvas, SemanticsNode node, int rank);

};
using _SemanticsDebuggerPainter = std::shared_ptr<_SemanticsDebuggerPainterCls>;


#endif