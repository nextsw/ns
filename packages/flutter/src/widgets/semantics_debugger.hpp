#ifndef SEMANTICS_DEBUGGER_H
#define SEMANTICS_DEBUGGER_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"



class SemanticsDebugger : StatefulWidget {
public:
    Widget child;

    TextStyle labelStyle;


     SemanticsDebugger(Widget child, Unknown, TextStyle labelStyle);

    State<SemanticsDebugger> createState();

private:

};

class _SemanticsDebuggerState : State<SemanticsDebugger> {
public:

    void initState();

    void dispose();

    void didChangeMetrics();

    Widget build(BuildContext context);

private:
    _SemanticsClient _client;

    Offset _lastPointerDownLocation;


    void _update();

    void _handlePointerDown(PointerDownEvent event);

    void _handleTap();

    void _handleLongPress();

    void _handlePanEnd(DragEndDetails details);

    void _performAction(SemanticsAction action, Offset position);

    PipelineOwner _pipelineOwner();

};

class _SemanticsClient : ChangeNotifier {
public:
    int generation;


    void dispose();

private:
    SemanticsHandle _semanticsHandle;


     _SemanticsClient(PipelineOwner pipelineOwner);

    void _didUpdateSemantics();

};

class _SemanticsDebuggerPainter : CustomPainter {
public:
    PipelineOwner owner;

    int generation;

    Offset pointerPosition;

    double devicePixelRatio;

    TextStyle labelStyle;


    void paint(Canvas canvas, Size size);

    bool shouldRepaint(_SemanticsDebuggerPainter oldDelegate);

    String getMessage(SemanticsNode node);

private:

     _SemanticsDebuggerPainter(double devicePixelRatio, int generation, TextStyle labelStyle, PipelineOwner owner, Offset pointerPosition);

    SemanticsNode _rootSemanticsNode();

    void _paintMessage(Canvas canvas, SemanticsNode node);

    int _findDepth(SemanticsNode node);

    void _paint(Canvas canvas, SemanticsNode node, int rank);

};

#endif