#include "gesture_detector.hpp"
template<typename T>
bool GestureRecognizerFactoryCls<T>::_debugAssertTypeMatches(Type type) {
    assert(type == T, __s("GestureRecognizerFactory of type $T was used where type $type was specified."));
    return true;
}

template<typename T>
GestureRecognizerFactoryWithHandlersCls<T>::GestureRecognizerFactoryWithHandlersCls(GestureRecognizerFactoryConstructor<T> _constructor, GestureRecognizerFactoryInitializer<T> _initializer) {
    {
        assert(_constructor != nullptr);
        assert(_initializer != nullptr);
    }
}

template<typename T>
T GestureRecognizerFactoryWithHandlersCls<T>::constructor() {
    return _constructor();
}

template<typename T>
void GestureRecognizerFactoryWithHandlersCls<T>::initializer(T instance) {
    return _initializer(instance);
}

GestureDetectorCls::GestureDetectorCls(HitTestBehavior behavior, Widget child, DragStartBehavior dragStartBehavior, bool excludeFromSemantics, Unknown key, GestureTapCallback onDoubleTap, GestureTapCancelCallback onDoubleTapCancel, GestureTapDownCallback onDoubleTapDown, GestureForcePressEndCallback onForcePressEnd, GestureForcePressPeakCallback onForcePressPeak, GestureForcePressStartCallback onForcePressStart, GestureForcePressUpdateCallback onForcePressUpdate, GestureDragCancelCallback onHorizontalDragCancel, GestureDragDownCallback onHorizontalDragDown, GestureDragEndCallback onHorizontalDragEnd, GestureDragStartCallback onHorizontalDragStart, GestureDragUpdateCallback onHorizontalDragUpdate, GestureLongPressCallback onLongPress, GestureLongPressCancelCallback onLongPressCancel, GestureLongPressDownCallback onLongPressDown, GestureLongPressEndCallback onLongPressEnd, GestureLongPressMoveUpdateCallback onLongPressMoveUpdate, GestureLongPressStartCallback onLongPressStart, GestureLongPressUpCallback onLongPressUp, GestureDragCancelCallback onPanCancel, GestureDragDownCallback onPanDown, GestureDragEndCallback onPanEnd, GestureDragStartCallback onPanStart, GestureDragUpdateCallback onPanUpdate, GestureScaleEndCallback onScaleEnd, GestureScaleStartCallback onScaleStart, GestureScaleUpdateCallback onScaleUpdate, GestureLongPressCallback onSecondaryLongPress, GestureLongPressCancelCallback onSecondaryLongPressCancel, GestureLongPressDownCallback onSecondaryLongPressDown, GestureLongPressEndCallback onSecondaryLongPressEnd, GestureLongPressMoveUpdateCallback onSecondaryLongPressMoveUpdate, GestureLongPressStartCallback onSecondaryLongPressStart, GestureLongPressUpCallback onSecondaryLongPressUp, GestureTapCallback onSecondaryTap, GestureTapCancelCallback onSecondaryTapCancel, GestureTapDownCallback onSecondaryTapDown, GestureTapUpCallback onSecondaryTapUp, GestureTapCallback onTap, GestureTapCancelCallback onTapCancel, GestureTapDownCallback onTapDown, GestureTapUpCallback onTapUp, GestureLongPressCallback onTertiaryLongPress, GestureLongPressCancelCallback onTertiaryLongPressCancel, GestureLongPressDownCallback onTertiaryLongPressDown, GestureLongPressEndCallback onTertiaryLongPressEnd, GestureLongPressMoveUpdateCallback onTertiaryLongPressMoveUpdate, GestureLongPressStartCallback onTertiaryLongPressStart, GestureLongPressUpCallback onTertiaryLongPressUp, GestureTapCancelCallback onTertiaryTapCancel, GestureTapDownCallback onTertiaryTapDown, GestureTapUpCallback onTertiaryTapUp, GestureDragCancelCallback onVerticalDragCancel, GestureDragDownCallback onVerticalDragDown, GestureDragEndCallback onVerticalDragEnd, GestureDragStartCallback onVerticalDragStart, GestureDragUpdateCallback onVerticalDragUpdate) {
    {
        assert(excludeFromSemantics != nullptr);
        assert(dragStartBehavior != nullptr);
        assert([=] () {
            bool haveVerticalDrag = onVerticalDragStart != nullptr || onVerticalDragUpdate != nullptr || onVerticalDragEnd != nullptr;
            bool haveHorizontalDrag = onHorizontalDragStart != nullptr || onHorizontalDragUpdate != nullptr || onHorizontalDragEnd != nullptr;
            bool havePan = onPanStart != nullptr || onPanUpdate != nullptr || onPanEnd != nullptr;
            bool haveScale = onScaleStart != nullptr || onScaleUpdate != nullptr || onScaleEnd != nullptr;
            if (havePan || haveScale) {
                if (havePan && haveScale) {
                    throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
                }
                String recognizer = havePan? __s("pan") : __s("scale");
                if (haveVerticalDrag && haveHorizontalDrag) {
                    throw make<FlutterErrorCls>(__s("Incorrect GestureDetector arguments.\nSimultaneously having a vertical drag gesture recognizer, a horizontal drag gesture recognizer, and a $recognizer gesture recognizer will result in the $recognizer gesture recognizer being ignored, since the other two will catch all drags."));
                }
            }
            return true;
        }());
    }
}

Widget GestureDetectorCls::build(BuildContext context) {
    Map<Type, GestureRecognizerFactory> gestures = makeMap(makeList(), makeList();
    DeviceGestureSettings gestureSettings = MediaQueryCls->maybeOf(context)?->gestureSettings;
    if (onTapDown != nullptr || onTapUp != nullptr || onTap != nullptr || onTapCancel != nullptr || onSecondaryTap != nullptr || onSecondaryTapDown != nullptr || onSecondaryTapUp != nullptr || onSecondaryTapCancel != nullptr || onTertiaryTapDown != nullptr || onTertiaryTapUp != nullptr || onTertiaryTapCancel != nullptr) {
        gestures[TapGestureRecognizerCls] = <TapGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] () {
            make<TapGestureRecognizerCls>(this);
        }, [=] (TapGestureRecognizer instance) {
                    auto _c1 = instance;        _c1.onTapDown = auto _c2 = onTapDown;        _c2.onTapUp = auto _c3 = onTapUp;        _c3.onTap = auto _c4 = onTap;        _c4.onTapCancel = auto _c5 = onTapCancel;        _c5.onSecondaryTap = auto _c6 = onSecondaryTap;        _c6.onSecondaryTapDown = auto _c7 = onSecondaryTapDown;        _c7.onSecondaryTapUp = auto _c8 = onSecondaryTapUp;        _c8.onSecondaryTapCancel = auto _c9 = onSecondaryTapCancel;        _c9.onTertiaryTapDown = auto _c10 = onTertiaryTapDown;        _c10.onTertiaryTapUp = auto _c11 = onTertiaryTapUp;        _c11.onTertiaryTapCancel = auto _c12 = onTertiaryTapCancel;        _c12.gestureSettings = gestureSettings;        _c12;        _c11;        _c10;        _c9;        _c8;        _c7;        _c6;        _c5;        _c4;        _c3;        _c2;_c1;
        });
    }
    if (onDoubleTap != nullptr) {
        gestures[DoubleTapGestureRecognizerCls] = <DoubleTapGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] () {
            make<DoubleTapGestureRecognizerCls>(this);
        }, [=] (DoubleTapGestureRecognizer instance) {
                    auto _c13 = instance;        _c13.onDoubleTapDown = auto _c14 = onDoubleTapDown;        _c14.onDoubleTap = auto _c15 = onDoubleTap;        _c15.onDoubleTapCancel = auto _c16 = onDoubleTapCancel;        _c16.gestureSettings = gestureSettings;        _c16;        _c15;        _c14;_c13;
        });
    }
    if (onLongPressDown != nullptr || onLongPressCancel != nullptr || onLongPress != nullptr || onLongPressStart != nullptr || onLongPressMoveUpdate != nullptr || onLongPressUp != nullptr || onLongPressEnd != nullptr || onSecondaryLongPressDown != nullptr || onSecondaryLongPressCancel != nullptr || onSecondaryLongPress != nullptr || onSecondaryLongPressStart != nullptr || onSecondaryLongPressMoveUpdate != nullptr || onSecondaryLongPressUp != nullptr || onSecondaryLongPressEnd != nullptr || onTertiaryLongPressDown != nullptr || onTertiaryLongPressCancel != nullptr || onTertiaryLongPress != nullptr || onTertiaryLongPressStart != nullptr || onTertiaryLongPressMoveUpdate != nullptr || onTertiaryLongPressUp != nullptr || onTertiaryLongPressEnd != nullptr) {
        gestures[LongPressGestureRecognizerCls] = <LongPressGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] () {
            make<LongPressGestureRecognizerCls>(this);
        }, [=] (LongPressGestureRecognizer instance) {
                    auto _c17 = instance;        _c17.onLongPressDown = auto _c18 = onLongPressDown;        _c18.onLongPressCancel = auto _c19 = onLongPressCancel;        _c19.onLongPress = auto _c20 = onLongPress;        _c20.onLongPressStart = auto _c21 = onLongPressStart;        _c21.onLongPressMoveUpdate = auto _c22 = onLongPressMoveUpdate;        _c22.onLongPressUp = auto _c23 = onLongPressUp;        _c23.onLongPressEnd = auto _c24 = onLongPressEnd;        _c24.onSecondaryLongPressDown = auto _c25 = onSecondaryLongPressDown;        _c25.onSecondaryLongPressCancel = auto _c26 = onSecondaryLongPressCancel;        _c26.onSecondaryLongPress = auto _c27 = onSecondaryLongPress;        _c27.onSecondaryLongPressStart = auto _c28 = onSecondaryLongPressStart;        _c28.onSecondaryLongPressMoveUpdate = auto _c29 = onSecondaryLongPressMoveUpdate;        _c29.onSecondaryLongPressUp = auto _c30 = onSecondaryLongPressUp;        _c30.onSecondaryLongPressEnd = auto _c31 = onSecondaryLongPressEnd;        _c31.onTertiaryLongPressDown = auto _c32 = onTertiaryLongPressDown;        _c32.onTertiaryLongPressCancel = auto _c33 = onTertiaryLongPressCancel;        _c33.onTertiaryLongPress = auto _c34 = onTertiaryLongPress;        _c34.onTertiaryLongPressStart = auto _c35 = onTertiaryLongPressStart;        _c35.onTertiaryLongPressMoveUpdate = auto _c36 = onTertiaryLongPressMoveUpdate;        _c36.onTertiaryLongPressUp = auto _c37 = onTertiaryLongPressUp;        _c37.onTertiaryLongPressEnd = auto _c38 = onTertiaryLongPressEnd;        _c38.gestureSettings = gestureSettings;        _c38;        _c37;        _c36;        _c35;        _c34;        _c33;        _c32;        _c31;        _c30;        _c29;        _c28;        _c27;        _c26;        _c25;        _c24;        _c23;        _c22;        _c21;        _c20;        _c19;        _c18;_c17;
        });
    }
    if (onVerticalDragDown != nullptr || onVerticalDragStart != nullptr || onVerticalDragUpdate != nullptr || onVerticalDragEnd != nullptr || onVerticalDragCancel != nullptr) {
        gestures[VerticalDragGestureRecognizerCls] = <VerticalDragGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] () {
            make<VerticalDragGestureRecognizerCls>(this);
        }, [=] (VerticalDragGestureRecognizer instance) {
                    auto _c39 = instance;        _c39.onDown = auto _c40 = onVerticalDragDown;        _c40.onStart = auto _c41 = onVerticalDragStart;        _c41.onUpdate = auto _c42 = onVerticalDragUpdate;        _c42.onEnd = auto _c43 = onVerticalDragEnd;        _c43.onCancel = auto _c44 = onVerticalDragCancel;        _c44.dragStartBehavior = auto _c45 = dragStartBehavior;        _c45.gestureSettings = gestureSettings;        _c45;        _c44;        _c43;        _c42;        _c41;        _c40;_c39;
        });
    }
    if (onHorizontalDragDown != nullptr || onHorizontalDragStart != nullptr || onHorizontalDragUpdate != nullptr || onHorizontalDragEnd != nullptr || onHorizontalDragCancel != nullptr) {
        gestures[HorizontalDragGestureRecognizerCls] = <HorizontalDragGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] () {
            make<HorizontalDragGestureRecognizerCls>(this);
        }, [=] (HorizontalDragGestureRecognizer instance) {
                    auto _c46 = instance;        _c46.onDown = auto _c47 = onHorizontalDragDown;        _c47.onStart = auto _c48 = onHorizontalDragStart;        _c48.onUpdate = auto _c49 = onHorizontalDragUpdate;        _c49.onEnd = auto _c50 = onHorizontalDragEnd;        _c50.onCancel = auto _c51 = onHorizontalDragCancel;        _c51.dragStartBehavior = auto _c52 = dragStartBehavior;        _c52.gestureSettings = gestureSettings;        _c52;        _c51;        _c50;        _c49;        _c48;        _c47;_c46;
        });
    }
    if (onPanDown != nullptr || onPanStart != nullptr || onPanUpdate != nullptr || onPanEnd != nullptr || onPanCancel != nullptr) {
        gestures[PanGestureRecognizerCls] = <PanGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] () {
            make<PanGestureRecognizerCls>(this);
        }, [=] (PanGestureRecognizer instance) {
                    auto _c53 = instance;        _c53.onDown = auto _c54 = onPanDown;        _c54.onStart = auto _c55 = onPanStart;        _c55.onUpdate = auto _c56 = onPanUpdate;        _c56.onEnd = auto _c57 = onPanEnd;        _c57.onCancel = auto _c58 = onPanCancel;        _c58.dragStartBehavior = auto _c59 = dragStartBehavior;        _c59.gestureSettings = gestureSettings;        _c59;        _c58;        _c57;        _c56;        _c55;        _c54;_c53;
        });
    }
    if (onScaleStart != nullptr || onScaleUpdate != nullptr || onScaleEnd != nullptr) {
        gestures[ScaleGestureRecognizerCls] = <ScaleGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] () {
            make<ScaleGestureRecognizerCls>(this);
        }, [=] (ScaleGestureRecognizer instance) {
                    auto _c60 = instance;        _c60.onStart = auto _c61 = onScaleStart;        _c61.onUpdate = auto _c62 = onScaleUpdate;        _c62.onEnd = auto _c63 = onScaleEnd;        _c63.dragStartBehavior = auto _c64 = dragStartBehavior;        _c64.gestureSettings = gestureSettings;        _c64;        _c63;        _c62;        _c61;_c60;
        });
    }
    if (onForcePressStart != nullptr || onForcePressPeak != nullptr || onForcePressUpdate != nullptr || onForcePressEnd != nullptr) {
        gestures[ForcePressGestureRecognizerCls] = <ForcePressGestureRecognizer>make<GestureRecognizerFactoryWithHandlersCls>([=] () {
            make<ForcePressGestureRecognizerCls>(this);
        }, [=] (ForcePressGestureRecognizer instance) {
                    auto _c65 = instance;        _c65.onStart = auto _c66 = onForcePressStart;        _c66.onPeak = auto _c67 = onForcePressPeak;        _c67.onUpdate = auto _c68 = onForcePressUpdate;        _c68.onEnd = auto _c69 = onForcePressEnd;        _c69.gestureSettings = gestureSettings;        _c69;        _c68;        _c67;        _c66;_c65;
        });
    }
    return make<RawGestureDetectorCls>(gestures, behavior, excludeFromSemantics, child);
}

void GestureDetectorCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<DragStartBehavior>make<EnumPropertyCls>(__s("startBehavior"), dragStartBehavior));
}

RawGestureDetectorCls::RawGestureDetectorCls(HitTestBehavior behavior, Widget child, bool excludeFromSemantics, Map<Type, GestureRecognizerFactory> gestures, Unknown key, SemanticsGestureDelegate semantics) {
    {
        assert(gestures != nullptr);
        assert(excludeFromSemantics != nullptr);
    }
}

RawGestureDetectorState RawGestureDetectorCls::createState() {
    return make<RawGestureDetectorStateCls>();
}

void RawGestureDetectorStateCls::initState() {
    super->initState();
    _semantics = widget()->semantics | make<_DefaultSemanticsGestureDelegateCls>(this);
    _syncAll(widget()->gestures);
}

void RawGestureDetectorStateCls::didUpdateWidget(RawGestureDetector oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (!(oldWidget->semantics == nullptr && widget()->semantics == nullptr)) {
        _semantics = widget()->semantics | make<_DefaultSemanticsGestureDelegateCls>(this);
    }
    _syncAll(widget()->gestures);
}

void RawGestureDetectorStateCls::replaceGestureRecognizers(Map<Type, GestureRecognizerFactory> gestures) {
    assert([=] () {
        if (!context()->findRenderObject()!->owner()!->debugDoingLayout()) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
        }
        return true;
    }());
    _syncAll(gestures);
    if (!widget()->excludeFromSemantics) {
        RenderSemanticsGestureHandler semanticsGestureHandler = as<RenderSemanticsGestureHandler>(context()->findRenderObject()!);
        _updateSemanticsForRenderObject(semanticsGestureHandler);
    }
}

void RawGestureDetectorStateCls::replaceSemanticsActions(Set<SemanticsAction> actions) {
    if (widget()->excludeFromSemantics) {
        return;
    }
    RenderSemanticsGestureHandler semanticsGestureHandler = as<RenderSemanticsGestureHandler>(context()->findRenderObject());
    assert([=] () {
        if (semanticsGestureHandler == nullptr) {
            throw make<FlutterErrorCls>(__s("Unexpected call to replaceSemanticsActions() method of RawGestureDetectorState.\nThe replaceSemanticsActions() method can only be called after the RenderSemanticsGestureHandler has been created."));
        }
        return true;
    }());
    semanticsGestureHandler!->validActions() = actions;
}

void RawGestureDetectorStateCls::dispose() {
    for (GestureRecognizer recognizer : _recognizers!->values()) {
        recognizer->dispose();
    }
    _recognizers = nullptr;
    super->dispose();
}

Widget RawGestureDetectorStateCls::build(BuildContext context) {
    Widget result = make<ListenerCls>(_handlePointerDown, _handlePointerPanZoomStart, widget()->behavior | _defaultBehavior(), widget()->child);
    if (!widget()->excludeFromSemantics) {
        result = make<_GestureSemanticsCls>(widget()->behavior | _defaultBehavior(), _updateSemanticsForRenderObject, result);
    }
    return result;
}

void RawGestureDetectorStateCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    if (_recognizers == nullptr) {
        properties->add(DiagnosticsNodeCls->message(__s("DISPOSED")));
    } else {
        List<String> gestures = _recognizers!->values()-><String>map([=] (GestureRecognizer recognizer) {
    recognizer->debugDescription;
})->toList();
        properties->add(<String>make<IterablePropertyCls>(__s("gestures"), gestures, __s("<none>")));
        properties->add(<GestureRecognizer>make<IterablePropertyCls>(__s("recognizers"), _recognizers!->values(), DiagnosticLevelCls::fine));
        properties->add(<bool>make<DiagnosticsPropertyCls>(__s("excludeFromSemantics"), widget()->excludeFromSemantics, false));
        if (!widget()->excludeFromSemantics) {
            properties->add(<SemanticsGestureDelegate>make<DiagnosticsPropertyCls>(__s("semantics"), widget()->semantics, nullptr));
        }
    }
    properties->add(<HitTestBehavior>make<EnumPropertyCls>(__s("behavior"), widget()->behavior, nullptr));
}

void RawGestureDetectorStateCls::_syncAll(Map<Type, GestureRecognizerFactory> gestures) {
    assert(_recognizers != nullptr);
    Map<Type, GestureRecognizer> oldRecognizers = _recognizers!;
    _recognizers = makeMap(makeList(), makeList();
    for (Type type : gestures->keys()) {
        assert(gestures[type] != nullptr);
        assert(gestures[type]!->_debugAssertTypeMatches(type));
        assert(!_recognizers!->containsKey(type));
        _recognizers![type] = oldRecognizers[type] | gestures[type]!->constructor();
        assert(_recognizers![type]->runtimeType == type, __s("GestureRecognizerFactory of type $type created a GestureRecognizer of type ${_recognizers![type].runtimeType}. The GestureRecognizerFactory must be specialized with the type of the class that it returns from its constructor method."));
        gestures[type]!->initializer(_recognizers![type]!);
    }
    for (Type type : oldRecognizers->keys()) {
        if (!_recognizers!->containsKey(type)) {
            oldRecognizers[type]!->dispose();
        }
    }
}

void RawGestureDetectorStateCls::_handlePointerDown(PointerDownEvent event) {
    assert(_recognizers != nullptr);
    for (GestureRecognizer recognizer : _recognizers!->values()) {
        recognizer->addPointer(event);
    }
}

void RawGestureDetectorStateCls::_handlePointerPanZoomStart(PointerPanZoomStartEvent event) {
    assert(_recognizers != nullptr);
    for (GestureRecognizer recognizer : _recognizers!->values()) {
        recognizer->addPointerPanZoom(event);
    }
}

HitTestBehavior RawGestureDetectorStateCls::_defaultBehavior() {
    return widget()->child == nullptr? HitTestBehaviorCls::translucent : HitTestBehaviorCls::deferToChild;
}

void RawGestureDetectorStateCls::_updateSemanticsForRenderObject(RenderSemanticsGestureHandler renderObject) {
    assert(!widget()->excludeFromSemantics);
    assert(_semantics != nullptr);
    _semantics!->assignSemantics(renderObject);
}

RenderSemanticsGestureHandler _GestureSemanticsCls::createRenderObject(BuildContext context) {
    auto _c1 = make<RenderSemanticsGestureHandlerCls>();_c1.behavior = behavior;RenderSemanticsGestureHandler renderObject = _c1;
    assignSemantics(renderObject);
    return renderObject;
}

void _GestureSemanticsCls::updateRenderObject(BuildContext context, RenderSemanticsGestureHandler renderObject) {
    renderObject->behavior = behavior;
    assignSemantics(renderObject);
}

_GestureSemanticsCls::_GestureSemanticsCls(_AssignSemantics assignSemantics, HitTestBehavior behavior, Unknown child) {
    {
        assert(assignSemantics != nullptr);
    }
}

String SemanticsGestureDelegateCls::toString() {
    return __s("${objectRuntimeType(this, 'SemanticsGestureDelegate')}()");
}

void _DefaultSemanticsGestureDelegateCls::assignSemantics(RenderSemanticsGestureHandler renderObject) {
    assert(!detectorState->widget()->excludeFromSemantics);
    Map<Type, GestureRecognizer> recognizers = detectorState->_recognizers!;
    auto _c1 = renderObject;_c1.onTap = auto _c2 = _getTapHandler(recognizers);_c2.onLongPress = auto _c3 = _getLongPressHandler(recognizers);_c3.onHorizontalDragUpdate = auto _c4 = _getHorizontalDragUpdateHandler(recognizers);_c4.onVerticalDragUpdate = _getVerticalDragUpdateHandler(recognizers);_c4;_c3;_c2;_c1;
}

GestureTapCallback _DefaultSemanticsGestureDelegateCls::_getTapHandler(Map<Type, GestureRecognizer> recognizers) {
    TapGestureRecognizer tap = as<TapGestureRecognizer>(recognizers[TapGestureRecognizerCls]);
    if (tap == nullptr) {
        return nullptr;
    }
    return [=] () {
        assert(tap != nullptr);
        tap->onTapDown?->call(make<TapDownDetailsCls>());
        tap->onTapUp?->call(make<TapUpDetailsCls>(PointerDeviceKindCls::unknown));
        tap->onTap?->call();
    };
}

GestureLongPressCallback _DefaultSemanticsGestureDelegateCls::_getLongPressHandler(Map<Type, GestureRecognizer> recognizers) {
    LongPressGestureRecognizer longPress = as<LongPressGestureRecognizer>(recognizers[LongPressGestureRecognizerCls]);
    if (longPress == nullptr) {
        return nullptr;
    }
    return [=] () {
        longPress->onLongPressDown?->call(make<LongPressDownDetailsCls>());
        longPress->onLongPressStart?->call(make<LongPressStartDetailsCls>());
        longPress->onLongPress?->call();
        longPress->onLongPressEnd?->call(make<LongPressEndDetailsCls>());
        longPress->onLongPressUp?->call();
    };
}

GestureDragUpdateCallback _DefaultSemanticsGestureDelegateCls::_getHorizontalDragUpdateHandler(Map<Type, GestureRecognizer> recognizers) {
    HorizontalDragGestureRecognizer horizontal = as<HorizontalDragGestureRecognizer>(recognizers[HorizontalDragGestureRecognizerCls]);
    PanGestureRecognizer pan = as<PanGestureRecognizer>(recognizers[PanGestureRecognizerCls]);
    GestureDragUpdateCallback horizontalHandler = horizontal == nullptr? nullptr : [=] (DragUpdateDetails details) {
    horizontal->onDown?->call(make<DragDownDetailsCls>());
    horizontal->onStart?->call(make<DragStartDetailsCls>());
    horizontal->onUpdate?->call(details);
    horizontal->onEnd?->call(make<DragEndDetailsCls>(0.0));
};
    GestureDragUpdateCallback panHandler = pan == nullptr? nullptr : [=] (DragUpdateDetails details) {
    pan->onDown?->call(make<DragDownDetailsCls>());
    pan->onStart?->call(make<DragStartDetailsCls>());
    pan->onUpdate?->call(details);
    pan->onEnd?->call(make<DragEndDetailsCls>());
};
    if (horizontalHandler == nullptr && panHandler == nullptr) {
        return nullptr;
    }
    return [=] (DragUpdateDetails details) {
        if (horizontalHandler != nullptr) {
            horizontalHandler(details);
        }
        if (panHandler != nullptr) {
            panHandler(details);
        }
    };
}

GestureDragUpdateCallback _DefaultSemanticsGestureDelegateCls::_getVerticalDragUpdateHandler(Map<Type, GestureRecognizer> recognizers) {
    VerticalDragGestureRecognizer vertical = as<VerticalDragGestureRecognizer>(recognizers[VerticalDragGestureRecognizerCls]);
    PanGestureRecognizer pan = as<PanGestureRecognizer>(recognizers[PanGestureRecognizerCls]);
    GestureDragUpdateCallback verticalHandler = vertical == nullptr? nullptr : [=] (DragUpdateDetails details) {
    vertical->onDown?->call(make<DragDownDetailsCls>());
    vertical->onStart?->call(make<DragStartDetailsCls>());
    vertical->onUpdate?->call(details);
    vertical->onEnd?->call(make<DragEndDetailsCls>(0.0));
};
    GestureDragUpdateCallback panHandler = pan == nullptr? nullptr : [=] (DragUpdateDetails details) {
    pan->onDown?->call(make<DragDownDetailsCls>());
    pan->onStart?->call(make<DragStartDetailsCls>());
    pan->onUpdate?->call(details);
    pan->onEnd?->call(make<DragEndDetailsCls>());
};
    if (verticalHandler == nullptr && panHandler == nullptr) {
        return nullptr;
    }
    return [=] (DragUpdateDetails details) {
        if (verticalHandler != nullptr) {
            verticalHandler(details);
        }
        if (panHandler != nullptr) {
            panHandler(details);
        }
    };
}
