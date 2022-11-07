#include "gesture_detector.hpp"
bool GestureRecognizerFactory::_debugAssertTypeMatches(Type type) {
    assert(type == T, "GestureRecognizerFactory of type $T was used where type $type was specified.");
    return true;
}

GestureRecognizerFactoryWithHandlers::GestureRecognizerFactoryWithHandlers(GestureRecognizerFactoryConstructor<T> _constructor, GestureRecognizerFactoryInitializer<T> _initializer) {
    {
        assert(_constructor != nullptr);
        assert(_initializer != nullptr);
    }
}

T GestureRecognizerFactoryWithHandlers::constructor() {
    return _constructor();
}

void GestureRecognizerFactoryWithHandlers::initializer(T instance) {
    return _initializer(instance);
}

GestureDetector::GestureDetector(HitTestBehavior behavior, Widget child, DragStartBehavior dragStartBehavior, bool excludeFromSemantics, Unknown, GestureTapCallback onDoubleTap, GestureTapCancelCallback onDoubleTapCancel, GestureTapDownCallback onDoubleTapDown, GestureForcePressEndCallback onForcePressEnd, GestureForcePressPeakCallback onForcePressPeak, GestureForcePressStartCallback onForcePressStart, GestureForcePressUpdateCallback onForcePressUpdate, GestureDragCancelCallback onHorizontalDragCancel, GestureDragDownCallback onHorizontalDragDown, GestureDragEndCallback onHorizontalDragEnd, GestureDragStartCallback onHorizontalDragStart, GestureDragUpdateCallback onHorizontalDragUpdate, GestureLongPressCallback onLongPress, GestureLongPressCancelCallback onLongPressCancel, GestureLongPressDownCallback onLongPressDown, GestureLongPressEndCallback onLongPressEnd, GestureLongPressMoveUpdateCallback onLongPressMoveUpdate, GestureLongPressStartCallback onLongPressStart, GestureLongPressUpCallback onLongPressUp, GestureDragCancelCallback onPanCancel, GestureDragDownCallback onPanDown, GestureDragEndCallback onPanEnd, GestureDragStartCallback onPanStart, GestureDragUpdateCallback onPanUpdate, GestureScaleEndCallback onScaleEnd, GestureScaleStartCallback onScaleStart, GestureScaleUpdateCallback onScaleUpdate, GestureLongPressCallback onSecondaryLongPress, GestureLongPressCancelCallback onSecondaryLongPressCancel, GestureLongPressDownCallback onSecondaryLongPressDown, GestureLongPressEndCallback onSecondaryLongPressEnd, GestureLongPressMoveUpdateCallback onSecondaryLongPressMoveUpdate, GestureLongPressStartCallback onSecondaryLongPressStart, GestureLongPressUpCallback onSecondaryLongPressUp, GestureTapCallback onSecondaryTap, GestureTapCancelCallback onSecondaryTapCancel, GestureTapDownCallback onSecondaryTapDown, GestureTapUpCallback onSecondaryTapUp, GestureTapCallback onTap, GestureTapCancelCallback onTapCancel, GestureTapDownCallback onTapDown, GestureTapUpCallback onTapUp, GestureLongPressCallback onTertiaryLongPress, GestureLongPressCancelCallback onTertiaryLongPressCancel, GestureLongPressDownCallback onTertiaryLongPressDown, GestureLongPressEndCallback onTertiaryLongPressEnd, GestureLongPressMoveUpdateCallback onTertiaryLongPressMoveUpdate, GestureLongPressStartCallback onTertiaryLongPressStart, GestureLongPressUpCallback onTertiaryLongPressUp, GestureTapCancelCallback onTertiaryTapCancel, GestureTapDownCallback onTertiaryTapDown, GestureTapUpCallback onTertiaryTapUp, GestureDragCancelCallback onVerticalDragCancel, GestureDragDownCallback onVerticalDragDown, GestureDragEndCallback onVerticalDragEnd, GestureDragStartCallback onVerticalDragStart, GestureDragUpdateCallback onVerticalDragUpdate) {
    {
        assert(excludeFromSemantics != nullptr);
        assert(dragStartBehavior != nullptr);
        assert(());
    }
}

Widget GestureDetector::build(BuildContext context) {
    Map<Type, GestureRecognizerFactory> gestures = ;
    DeviceGestureSettings gestureSettings = MediaQuery.maybeOf(context)?.gestureSettings;
    if (onTapDown != nullptr || onTapUp != nullptr || onTap != nullptr || onTapCancel != nullptr || onSecondaryTap != nullptr || onSecondaryTapDown != nullptr || onSecondaryTapUp != nullptr || onSecondaryTapCancel != nullptr || onTertiaryTapDown != nullptr || onTertiaryTapUp != nullptr || onTertiaryTapCancel != nullptr) {
        gestures[TapGestureRecognizer] = <TapGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    }
    if (onDoubleTap != nullptr) {
        gestures[DoubleTapGestureRecognizer] = <DoubleTapGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    }
    if (onLongPressDown != nullptr || onLongPressCancel != nullptr || onLongPress != nullptr || onLongPressStart != nullptr || onLongPressMoveUpdate != nullptr || onLongPressUp != nullptr || onLongPressEnd != nullptr || onSecondaryLongPressDown != nullptr || onSecondaryLongPressCancel != nullptr || onSecondaryLongPress != nullptr || onSecondaryLongPressStart != nullptr || onSecondaryLongPressMoveUpdate != nullptr || onSecondaryLongPressUp != nullptr || onSecondaryLongPressEnd != nullptr || onTertiaryLongPressDown != nullptr || onTertiaryLongPressCancel != nullptr || onTertiaryLongPress != nullptr || onTertiaryLongPressStart != nullptr || onTertiaryLongPressMoveUpdate != nullptr || onTertiaryLongPressUp != nullptr || onTertiaryLongPressEnd != nullptr) {
        gestures[LongPressGestureRecognizer] = <LongPressGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    }
    if (onVerticalDragDown != nullptr || onVerticalDragStart != nullptr || onVerticalDragUpdate != nullptr || onVerticalDragEnd != nullptr || onVerticalDragCancel != nullptr) {
        gestures[VerticalDragGestureRecognizer] = <VerticalDragGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    }
    if (onHorizontalDragDown != nullptr || onHorizontalDragStart != nullptr || onHorizontalDragUpdate != nullptr || onHorizontalDragEnd != nullptr || onHorizontalDragCancel != nullptr) {
        gestures[HorizontalDragGestureRecognizer] = <HorizontalDragGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    }
    if (onPanDown != nullptr || onPanStart != nullptr || onPanUpdate != nullptr || onPanEnd != nullptr || onPanCancel != nullptr) {
        gestures[PanGestureRecognizer] = <PanGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    }
    if (onScaleStart != nullptr || onScaleUpdate != nullptr || onScaleEnd != nullptr) {
        gestures[ScaleGestureRecognizer] = <ScaleGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    }
    if (onForcePressStart != nullptr || onForcePressPeak != nullptr || onForcePressUpdate != nullptr || onForcePressEnd != nullptr) {
        gestures[ForcePressGestureRecognizer] = <ForcePressGestureRecognizer>GestureRecognizerFactoryWithHandlers(, );
    }
    return RawGestureDetector(gestures, behavior, excludeFromSemantics, child);
}

void GestureDetector::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<DragStartBehavior>EnumProperty("startBehavior", dragStartBehavior));
}

RawGestureDetector::RawGestureDetector(HitTestBehavior behavior, Widget child, bool excludeFromSemantics, Map<Type, GestureRecognizerFactory> gestures, Unknown, SemanticsGestureDelegate semantics) {
    {
        assert(gestures != nullptr);
        assert(excludeFromSemantics != nullptr);
    }
}

RawGestureDetectorState RawGestureDetector::createState() {
    return RawGestureDetectorState();
}

void RawGestureDetectorState::initState() {
    super.initState();
    _semantics = widget.semantics ?? _DefaultSemanticsGestureDelegate(this);
    _syncAll(widget.gestures);
}

void RawGestureDetectorState::didUpdateWidget(RawGestureDetector oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (!(oldWidget.semantics == nullptr && widget.semantics == nullptr)) {
        _semantics = widget.semantics ?? _DefaultSemanticsGestureDelegate(this);
    }
    _syncAll(widget.gestures);
}

void RawGestureDetectorState::replaceGestureRecognizers(Map<Type, GestureRecognizerFactory> gestures) {
    assert(());
    _syncAll(gestures);
    if (!widget.excludeFromSemantics) {
        RenderSemanticsGestureHandler semanticsGestureHandler = (;
        _updateSemanticsForRenderObject(semanticsGestureHandler);
    }
}

void RawGestureDetectorState::replaceSemanticsActions(Set<SemanticsAction> actions) {
    if (widget.excludeFromSemantics) {
        return;
    }
    RenderSemanticsGestureHandler semanticsGestureHandler = (;
    assert(());
    semanticsGestureHandler!.validActions = actions;
}

void RawGestureDetectorState::dispose() {
    for (GestureRecognizer recognizer : _recognizers!.values) {
        recognizer.dispose();
    }
    _recognizers = nullptr;
    super.dispose();
}

Widget RawGestureDetectorState::build(BuildContext context) {
    Widget result = Listener(_handlePointerDown, _handlePointerPanZoomStart, widget.behavior ?? _defaultBehavior, widget.child);
    if (!widget.excludeFromSemantics) {
        result = _GestureSemantics(widget.behavior ?? _defaultBehavior, _updateSemanticsForRenderObject, result);
    }
    return result;
}

void RawGestureDetectorState::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    if (_recognizers == nullptr) {
        properties.add(DiagnosticsNode.message("DISPOSED"));
    } else {
        List<String> gestures = _recognizers!.values.<String>map().toList();
        properties.add(<String>IterableProperty("gestures", gestures"<none>"));
        properties.add(<GestureRecognizer>IterableProperty("recognizers", _recognizers!.valuesDiagnosticLevel.fine));
        properties.add(<bool>DiagnosticsProperty("excludeFromSemantics", widget.excludeFromSemanticsfalse));
        if (!widget.excludeFromSemantics) {
            properties.add(<SemanticsGestureDelegate>DiagnosticsProperty("semantics", widget.semanticsnullptr));
        }
    }
    properties.add(<HitTestBehavior>EnumProperty("behavior", widget.behaviornullptr));
}

void RawGestureDetectorState::_syncAll(Map<Type, GestureRecognizerFactory> gestures) {
    assert(_recognizers != nullptr);
    Map<Type, GestureRecognizer> oldRecognizers = _recognizers!;
    _recognizers = ;
    for (Type type : gestures.keys) {
        assert(gestures[type] != nullptr);
        assert(gestures[type]!._debugAssertTypeMatches(type));
        assert(!_recognizers!.containsKey(type));
        _recognizers![type] = oldRecognizers[type] ?? gestures[type]!.constructor();
        assert(_recognizers![type].runtimeType == type, "GestureRecognizerFactory of type $type created a GestureRecognizer of type ${_recognizers![type].runtimeType}. The GestureRecognizerFactory must be specialized with the type of the class that it returns from its constructor method.");
        gestures[type]!.initializer(_recognizers![type]!);
    }
    for (Type type : oldRecognizers.keys) {
        if (!_recognizers!.containsKey(type)) {
            oldRecognizers[type]!.dispose();
        }
    }
}

void RawGestureDetectorState::_handlePointerDown(PointerDownEvent event) {
    assert(_recognizers != nullptr);
    for (GestureRecognizer recognizer : _recognizers!.values) {
        recognizer.addPointer(event);
    }
}

void RawGestureDetectorState::_handlePointerPanZoomStart(PointerPanZoomStartEvent event) {
    assert(_recognizers != nullptr);
    for (GestureRecognizer recognizer : _recognizers!.values) {
        recognizer.addPointerPanZoom(event);
    }
}

HitTestBehavior RawGestureDetectorState::_defaultBehavior() {
    return widget.child == nullptr? HitTestBehavior.translucent : HitTestBehavior.deferToChild;
}

void RawGestureDetectorState::_updateSemanticsForRenderObject(RenderSemanticsGestureHandler renderObject) {
    assert(!widget.excludeFromSemantics);
    assert(_semantics != nullptr);
    _semantics!.assignSemantics(renderObject);
}

RenderSemanticsGestureHandler _GestureSemantics::createRenderObject(BuildContext context) {
    RenderSemanticsGestureHandler renderObject = ;
    assignSemantics(renderObject);
    return renderObject;
}

void _GestureSemantics::updateRenderObject(BuildContext context, RenderSemanticsGestureHandler renderObject) {
    renderObject.behavior = behavior;
    assignSemantics(renderObject);
}

_GestureSemantics::_GestureSemantics(_AssignSemantics assignSemantics, HitTestBehavior behavior, Unknown) {
    {
        assert(assignSemantics != nullptr);
    }
}

String SemanticsGestureDelegate::toString() {
    return "${objectRuntimeType(this, 'SemanticsGestureDelegate')}()";
}

void _DefaultSemanticsGestureDelegate::assignSemantics(RenderSemanticsGestureHandler renderObject) {
    assert(!detectorState.widget.excludeFromSemantics);
    Map<Type, GestureRecognizer> recognizers = detectorState._recognizers!;
    ;
}

GestureTapCallback _DefaultSemanticsGestureDelegate::_getTapHandler(Map<Type, GestureRecognizer> recognizers) {
    TapGestureRecognizer tap = (;
    if (tap == nullptr) {
        return nullptr;
    }
    return ;
}

GestureLongPressCallback _DefaultSemanticsGestureDelegate::_getLongPressHandler(Map<Type, GestureRecognizer> recognizers) {
    LongPressGestureRecognizer longPress = (;
    if (longPress == nullptr) {
        return nullptr;
    }
    return ;
}

GestureDragUpdateCallback _DefaultSemanticsGestureDelegate::_getHorizontalDragUpdateHandler(Map<Type, GestureRecognizer> recognizers) {
    HorizontalDragGestureRecognizer horizontal = (;
    PanGestureRecognizer pan = (;
    GestureDragUpdateCallback horizontalHandler = horizontal == nullptr? nullptr : ;
    GestureDragUpdateCallback panHandler = pan == nullptr? nullptr : ;
    if (horizontalHandler == nullptr && panHandler == nullptr) {
        return nullptr;
    }
    return ;
}

GestureDragUpdateCallback _DefaultSemanticsGestureDelegate::_getVerticalDragUpdateHandler(Map<Type, GestureRecognizer> recognizers) {
    VerticalDragGestureRecognizer vertical = (;
    PanGestureRecognizer pan = (;
    GestureDragUpdateCallback verticalHandler = vertical == nullptr? nullptr : ;
    GestureDragUpdateCallback panHandler = pan == nullptr? nullptr : ;
    if (verticalHandler == nullptr && panHandler == nullptr) {
        return nullptr;
    }
    return ;
}
