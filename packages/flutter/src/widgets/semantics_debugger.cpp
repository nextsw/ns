#include "semantics_debugger.hpp"
SemanticsDebugger::SemanticsDebugger(Widget child, Unknown, TextStyle labelStyle) {
    {
        assert(child != nullptr);
        assert(labelStyle != nullptr);
    }
}

State<SemanticsDebugger> SemanticsDebugger::createState() {
    return _SemanticsDebuggerState();
}

void _SemanticsDebuggerState::initState() {
    super.initState();
    _client = ;
    WidgetsBinding.instance.addObserver(this);
}

void _SemanticsDebuggerState::dispose() {
    ;
    WidgetsBinding.instance.removeObserver(this);
    super.dispose();
}

void _SemanticsDebuggerState::didChangeMetrics() {
    setState();
}

Widget _SemanticsDebuggerState::build(BuildContext context) {
    return CustomPaint(_SemanticsDebuggerPainter(_pipelineOwner, _client.generation, _lastPointerDownLocation, WidgetsBinding.instance.window.devicePixelRatio, widget.labelStyle), GestureDetector(HitTestBehavior.opaque, _handleTap, _handleLongPress, _handlePanEnd, true, Listener(_handlePointerDown, HitTestBehavior.opaque, IgnorePointer(false, widget.child))));
}

void _SemanticsDebuggerState::_update() {
    SchedulerBinding.instance.addPostFrameCallback();
}

void _SemanticsDebuggerState::_handlePointerDown(PointerDownEvent event) {
    setState();
}

void _SemanticsDebuggerState::_handleTap() {
    assert(_lastPointerDownLocation != nullptr);
    _performAction(_lastPointerDownLocation!, SemanticsAction.tap);
    setState();
}

void _SemanticsDebuggerState::_handleLongPress() {
    assert(_lastPointerDownLocation != nullptr);
    _performAction(_lastPointerDownLocation!, SemanticsAction.longPress);
    setState();
}

void _SemanticsDebuggerState::_handlePanEnd(DragEndDetails details) {
    double vx = details.velocity.pixelsPerSecond.dx;
    double vy = details.velocity.pixelsPerSecond.dy;
    if (vx.abs() == vy.abs()) {
        return;
    }
    if (vx.abs() > vy.abs()) {
        if (vx.sign < 0) {
            _performAction(_lastPointerDownLocation!, SemanticsAction.decrease);
            _performAction(_lastPointerDownLocation!, SemanticsAction.scrollLeft);
        } else {
            _performAction(_lastPointerDownLocation!, SemanticsAction.increase);
            _performAction(_lastPointerDownLocation!, SemanticsAction.scrollRight);
        }
    } else {
        if (vy.sign < 0) {
            _performAction(_lastPointerDownLocation!, SemanticsAction.scrollUp);
        } else {
            _performAction(_lastPointerDownLocation!, SemanticsAction.scrollDown);
        }
    }
    setState();
}

void _SemanticsDebuggerState::_performAction(SemanticsAction action, Offset position) {
    _pipelineOwner.semanticsOwner?.performActionAt(position, action);
}

PipelineOwner _SemanticsDebuggerState::_pipelineOwner() {
    return WidgetsBinding.instance.pipelineOwner;
}

void _SemanticsClient::dispose() {
    _semanticsHandle!.dispose();
    _semanticsHandle = nullptr;
    super.dispose();
}

_SemanticsClient::_SemanticsClient(PipelineOwner pipelineOwner) {
    {
        _semanticsHandle = pipelineOwner.ensureSemantics(_didUpdateSemantics);
    }
}

void _SemanticsClient::_didUpdateSemantics() {
    generation = 1;
    notifyListeners();
}

void _SemanticsDebuggerPainter::paint(Canvas canvas, Size size) {
    SemanticsNode rootNode = _rootSemanticsNode;
    canvas.save();
    canvas.scale(1.0 / devicePixelRatio, 1.0 / devicePixelRatio);
    if (rootNode != nullptr) {
        _paint(canvas, rootNode, _findDepth(rootNode));
    }
    if (pointerPosition != nullptr) {
        Paint paint = Paint();
        paint.color = const Color(0x7F0090FF);
        canvas.drawCircle(pointerPosition!, 10.0 * devicePixelRatio, paint);
    }
    canvas.restore();
}

bool _SemanticsDebuggerPainter::shouldRepaint(_SemanticsDebuggerPainter oldDelegate) {
    return owner != oldDelegate.owner || generation != oldDelegate.generation || pointerPosition != oldDelegate.pointerPosition;
}

String _SemanticsDebuggerPainter::getMessage(SemanticsNode node) {
    SemanticsData data = node.getSemanticsData();
    List<String> annotations = ;
    bool wantsTap = false;
    if (data.hasFlag(SemanticsFlag.hasCheckedState)) {
        annotations.add(data.hasFlag(SemanticsFlag.isChecked)? "checked" : "unchecked");
        wantsTap = true;
    }
    if (data.hasFlag(SemanticsFlag.isTextField)) {
        annotations.add("textfield");
        wantsTap = true;
    }
    if (data.hasAction(SemanticsAction.tap)) {
        if (!wantsTap) {
            annotations.add("button");
        }
    } else {
        if (wantsTap) {
            annotations.add("disabled");
        }
    }
    if (data.hasAction(SemanticsAction.longPress)) {
        annotations.add("long-pressable");
    }
    bool isScrollable = data.hasAction(SemanticsAction.scrollLeft) || data.hasAction(SemanticsAction.scrollRight) || data.hasAction(SemanticsAction.scrollUp) || data.hasAction(SemanticsAction.scrollDown);
    bool isAdjustable = data.hasAction(SemanticsAction.increase) || data.hasAction(SemanticsAction.decrease);
    if (isScrollable) {
        annotations.add("scrollable");
    }
    if (isAdjustable) {
        annotations.add("adjustable");
    }
    assert(data.attributedLabel != nullptr);
    String message;
    String tooltipAndLabel = .join("\n");
    if (tooltipAndLabel.isEmpty) {
        message = annotations.join("; ");
    } else {
        String effectivelabel;
        if (data.textDirection == nullptr) {
            effectivelabel = "${Unicode.FSI}$tooltipAndLabel${Unicode.PDI}";
            annotations.insert(0, "MISSING TEXT DIRECTION");
        } else {
            ;
        }
        if (annotations.isEmpty) {
            message = effectivelabel;
        } else {
            message = "$effectivelabel (${annotations.join('; ')})";
        }
    }
    return message.trim();
}

SemanticsNode _SemanticsDebuggerPainter::_rootSemanticsNode() {
    return owner.semanticsOwner?.rootSemanticsNode;
}

void _SemanticsDebuggerPainter::_paintMessage(Canvas canvas, SemanticsNode node) {
    String message = getMessage(node);
    if (message.isEmpty) {
        return;
    }
    Rect rect = node.rect;
    canvas.save();
    canvas.clipRect(rect);
    TextPainter textPainter = ;
    textPainter.paint(canvas, Alignment.center.inscribe(textPainter.size, rect).topLeft);
    canvas.restore();
}

int _SemanticsDebuggerPainter::_findDepth(SemanticsNode node) {
    if (!node.hasChildren || node.mergeAllDescendantsIntoThisNode) {
        return 1;
    }
    int childrenDepth = 0;
    node.visitChildren();
    return childrenDepth + 1;
}

void _SemanticsDebuggerPainter::_paint(Canvas canvas, SemanticsNode node, int rank) {
    canvas.save();
    if (node.transform != nullptr) {
        canvas.transform(node.transform!.storage);
    }
    Rect rect = node.rect;
    if (!rect.isEmpty) {
        Color lineColor = Color(0xFF000000 + math.Random(node.id).nextInt(0xFFFFFF));
        Rect innerRect = rect.deflate(rank * 1.0);
        if (innerRect.isEmpty) {
            Paint fill = ;
            canvas.drawRect(rect, fill);
        } else {
            Paint fill = ;
            canvas.drawRect(rect, fill);
            Paint line = ;
            canvas.drawRect(innerRect, line);
        }
        _paintMessage(canvas, node);
    }
    if (!node.mergeAllDescendantsIntoThisNode) {
        int childRank = rank - 1;
        node.visitChildren();
    }
    canvas.restore();
}
