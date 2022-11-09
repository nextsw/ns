#include "semantics_debugger.hpp"
SemanticsDebuggerCls::SemanticsDebuggerCls(Widget child, Unknown key, TextStyle labelStyle) {
    {
        assert(child != nullptr);
        assert(labelStyle != nullptr);
    }
}

State<SemanticsDebugger> SemanticsDebuggerCls::createState() {
    return make<_SemanticsDebuggerStateCls>();
}

void _SemanticsDebuggerStateCls::initState() {
    super->initState();
    auto _c1 = make<_SemanticsClientCls>(WidgetsBindingCls::instance->pipelineOwner);_c1.addListener(_update);_client = _c1;
    WidgetsBindingCls::instance->addObserver(this);
}

void _SemanticsDebuggerStateCls::dispose() {
    auto _c1 = _client;_c1.auto _c2 = removeListener(_update);_c2.dispose();_c2;_c1;
    WidgetsBindingCls::instance->removeObserver(this);
    super->dispose();
}

void _SemanticsDebuggerStateCls::didChangeMetrics() {
    setState([=] () {
    });
}

Widget _SemanticsDebuggerStateCls::build(BuildContext context) {
    return make<CustomPaintCls>(make<_SemanticsDebuggerPainterCls>(_pipelineOwner, _client->generation, _lastPointerDownLocation, WidgetsBindingCls::instance->window->devicePixelRatio, widget->labelStyle), make<GestureDetectorCls>(HitTestBehaviorCls::opaque, _handleTap, _handleLongPress, _handlePanEnd, true, make<ListenerCls>(_handlePointerDown, HitTestBehaviorCls::opaque, make<IgnorePointerCls>(false, widget->child))));
}

void _SemanticsDebuggerStateCls::_update() {
    SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
        if (mounted) {
            setState([=] () {
            });
        }
    });
}

void _SemanticsDebuggerStateCls::_handlePointerDown(PointerDownEvent event) {
    setState([=] () {
        _lastPointerDownLocation = event->position * WidgetsBindingCls::instance->window->devicePixelRatio;
    });
}

void _SemanticsDebuggerStateCls::_handleTap() {
    assert(_lastPointerDownLocation != nullptr);
    _performAction(_lastPointerDownLocation!, SemanticsActionCls::tap);
    setState([=] () {
        _lastPointerDownLocation = nullptr;
    });
}

void _SemanticsDebuggerStateCls::_handleLongPress() {
    assert(_lastPointerDownLocation != nullptr);
    _performAction(_lastPointerDownLocation!, SemanticsActionCls::longPress);
    setState([=] () {
        _lastPointerDownLocation = nullptr;
    });
}

void _SemanticsDebuggerStateCls::_handlePanEnd(DragEndDetails details) {
    double vx = details->velocity->pixelsPerSecond->dx;
    double vy = details->velocity->pixelsPerSecond->dy;
    if (vx->abs() == vy->abs()) {
        return;
    }
    if (vx->abs() > vy->abs()) {
        if (vx->sign < 0) {
            _performAction(_lastPointerDownLocation!, SemanticsActionCls::decrease);
            _performAction(_lastPointerDownLocation!, SemanticsActionCls::scrollLeft);
        } else {
            _performAction(_lastPointerDownLocation!, SemanticsActionCls::increase);
            _performAction(_lastPointerDownLocation!, SemanticsActionCls::scrollRight);
        }
    } else {
        if (vy->sign < 0) {
            _performAction(_lastPointerDownLocation!, SemanticsActionCls::scrollUp);
        } else {
            _performAction(_lastPointerDownLocation!, SemanticsActionCls::scrollDown);
        }
    }
    setState([=] () {
        _lastPointerDownLocation = nullptr;
    });
}

void _SemanticsDebuggerStateCls::_performAction(SemanticsAction action, Offset position) {
    _pipelineOwner->semanticsOwner?->performActionAt(position, action);
}

PipelineOwner _SemanticsDebuggerStateCls::_pipelineOwner() {
    return WidgetsBindingCls::instance->pipelineOwner;
}

void _SemanticsClientCls::dispose() {
    _semanticsHandle!->dispose();
    _semanticsHandle = nullptr;
    super->dispose();
}

_SemanticsClientCls::_SemanticsClientCls(PipelineOwner pipelineOwner) {
    {
        _semanticsHandle = pipelineOwner->ensureSemantics(_didUpdateSemantics);
    }
}

void _SemanticsClientCls::_didUpdateSemantics() {
    generation = 1;
    notifyListeners();
}

void _SemanticsDebuggerPainterCls::paint(Canvas canvas, Size size) {
    SemanticsNode rootNode = _rootSemanticsNode;
    canvas->save();
    canvas->scale(1.0 / devicePixelRatio, 1.0 / devicePixelRatio);
    if (rootNode != nullptr) {
        _paint(canvas, rootNode, _findDepth(rootNode));
    }
    if (pointerPosition != nullptr) {
        Paint paint = make<PaintCls>();
        paint->color = make<ColorCls>(0x7F0090FF);
        canvas->drawCircle(pointerPosition!, 10.0 * devicePixelRatio, paint);
    }
    canvas->restore();
}

bool _SemanticsDebuggerPainterCls::shouldRepaint(_SemanticsDebuggerPainter oldDelegate) {
    return owner != oldDelegate->owner || generation != oldDelegate->generation || pointerPosition != oldDelegate->pointerPosition;
}

String _SemanticsDebuggerPainterCls::getMessage(SemanticsNode node) {
    SemanticsData data = node->getSemanticsData();
    List<String> annotations = makeList();
    bool wantsTap = false;
    if (data->hasFlag(SemanticsFlagCls::hasCheckedState)) {
        annotations->add(data->hasFlag(SemanticsFlagCls::isChecked)? "checked" : "unchecked");
        wantsTap = true;
    }
    if (data->hasFlag(SemanticsFlagCls::isTextField)) {
        annotations->add("textfield");
        wantsTap = true;
    }
    if (data->hasAction(SemanticsActionCls::tap)) {
        if (!wantsTap) {
            annotations->add("button");
        }
    } else {
        if (wantsTap) {
            annotations->add("disabled");
        }
    }
    if (data->hasAction(SemanticsActionCls::longPress)) {
        annotations->add("long-pressable");
    }
    bool isScrollable = data->hasAction(SemanticsActionCls::scrollLeft) || data->hasAction(SemanticsActionCls::scrollRight) || data->hasAction(SemanticsActionCls::scrollUp) || data->hasAction(SemanticsActionCls::scrollDown);
    bool isAdjustable = data->hasAction(SemanticsActionCls::increase) || data->hasAction(SemanticsActionCls::decrease);
    if (isScrollable) {
        annotations->add("scrollable");
    }
    if (isAdjustable) {
        annotations->add("adjustable");
    }
    assert(data->attributedLabel != nullptr);
    String message;
    List<String> list1 = make<ListCls<>>();if (data->tooltip->isNotEmpty) {    list1.add(ArrayItem);}if (data->attributedLabel->stringValue->isNotEmpty) {    list1.add(ArrayItem);}String tooltipAndLabel = list1->join("\n");
    if (tooltipAndLabel->isEmpty) {
        message = annotations->join("; ");
    } else {
        String effectivelabel;
        if (data->textDirection == nullptr) {
            effectivelabel = "${Unicode.FSI}$tooltipAndLabel${Unicode.PDI}";
            annotations->insert(0, "MISSING TEXT DIRECTION");
        } else {
            ;
        }
        if (annotations->isEmpty) {
            message = effectivelabel;
        } else {
            message = "$effectivelabel (${annotations.join('; ')})";
        }
    }
    return message->trim();
}

SemanticsNode _SemanticsDebuggerPainterCls::_rootSemanticsNode() {
    return owner->semanticsOwner?->rootSemanticsNode;
}

void _SemanticsDebuggerPainterCls::_paintMessage(Canvas canvas, SemanticsNode node) {
    String message = getMessage(node);
    if (message->isEmpty) {
        return;
    }
    Rect rect = node->rect;
    canvas->save();
    canvas->clipRect(rect);
    auto _c1 = make<TextPainterCls>();_c1.text = auto _c2 = make<TextSpanCls>(labelStyle, message);_c2.textDirection = auto _c3 = TextDirectionCls::ltr;_c3.textAlign = auto _c4 = TextAlignCls::center;_c4.layout(rect->width);_c4;_c3;_c2;TextPainter textPainter = _c1;
    textPainter->paint(canvas, AlignmentCls::center->inscribe(textPainter->size, rect)->topLeft);
    canvas->restore();
}

int _SemanticsDebuggerPainterCls::_findDepth(SemanticsNode node) {
    if (!node->hasChildren || node->mergeAllDescendantsIntoThisNode) {
        return 1;
    }
    int childrenDepth = 0;
    node->visitChildren([=] (SemanticsNode child) {
        childrenDepth = math->max(childrenDepth, _findDepth(child));
        return true;
    });
    return childrenDepth + 1;
}

void _SemanticsDebuggerPainterCls::_paint(Canvas canvas, SemanticsNode node, int rank) {
    canvas->save();
    if (node->transform != nullptr) {
        canvas->transform(node->transform!->storage);
    }
    Rect rect = node->rect;
    if (!rect->isEmpty) {
        Color lineColor = make<ColorCls>(0xFF000000 + math->make<RandomCls>(node->id)->nextInt(0xFFFFFF));
        Rect innerRect = rect->deflate(rank * 1.0);
        if (innerRect->isEmpty) {
                    auto _c1 = make<PaintCls>();        _c1.color = auto _c2 = lineColor;        _c2.style = PaintingStyleCls::fill;        _c2;Paint fill = _c1;
            canvas->drawRect(rect, fill);
        } else {
                    auto _c3 = make<PaintCls>();        _c3.color = auto _c4 = make<ColorCls>(0xFFFFFFFF);        _c4.style = PaintingStyleCls::fill;        _c4;Paint fill = _c3;
            canvas->drawRect(rect, fill);
                    auto _c5 = make<PaintCls>();        _c5.strokeWidth = auto _c6 = rank * 2.0;        _c6.color = auto _c7 = lineColor;        _c7.style = PaintingStyleCls::stroke;        _c7;        _c6;Paint line = _c5;
            canvas->drawRect(innerRect, line);
        }
        _paintMessage(canvas, node);
    }
    if (!node->mergeAllDescendantsIntoThisNode) {
        int childRank = rank - 1;
        node->visitChildren([=] (SemanticsNode child) {
            _paint(canvas, child, childRank);
            return true;
        });
    }
    canvas->restore();
}
