#include "tap.hpp"
TapDownDetailsCls::TapDownDetailsCls(Offset globalPosition, PointerDeviceKind kind, Offset localPosition) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition | globalPosition;
    }
}

TapUpDetailsCls::TapUpDetailsCls(Offset globalPosition, PointerDeviceKind kind, Offset localPosition) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition | globalPosition;
    }
}

BaseTapGestureRecognizerCls::BaseTapGestureRecognizerCls(Object debugOwner, Unknown supportedDevices) : PrimaryPointerGestureRecognizer(kPressTimeout) {
}

void BaseTapGestureRecognizerCls::addAllowedPointer(PointerDownEvent event) {
    assert(event != nullptr);
    if (state() == GestureRecognizerStateCls::ready) {
        if (_down != nullptr && _up != nullptr) {
            assert(_down!->pointer == _up!->pointer);
            _reset();
        }
        assert(_down == nullptr && _up == nullptr);
        _down = event;
    }
    if (_down != nullptr) {
        super->addAllowedPointer(event);
    }
}

void BaseTapGestureRecognizerCls::startTrackingPointer(int pointer, Matrix4 transform) {
    assert(_down != nullptr);
    super->startTrackingPointer(pointer, transform);
}

void BaseTapGestureRecognizerCls::handlePrimaryPointer(PointerEvent event) {
    if (is<PointerUpEvent>(event)) {
        _up = as<PointerUpEventCls>(event);
        _checkUp();
    } else {
        if (is<PointerCancelEvent>(event)) {
        resolve(GestureDispositionCls::rejected);
        if (_sentTapDown) {
            _checkCancel(event, __s(""));
        }
        _reset();
    } else {
        if (event->buttons != _down!->buttons) {
        resolve(GestureDispositionCls::rejected);
        stopTrackingPointer(primaryPointer()!);
    }
;
    };
    }}

void BaseTapGestureRecognizerCls::resolve(GestureDisposition disposition) {
    if (_wonArenaForPrimaryPointer && disposition == GestureDispositionCls::rejected) {
        assert(_sentTapDown);
        _checkCancel(nullptr, __s("spontaneous"));
        _reset();
    }
    super->resolve(disposition);
}

void BaseTapGestureRecognizerCls::didExceedDeadline() {
    _checkDown();
}

void BaseTapGestureRecognizerCls::acceptGesture(int pointer) {
    super->acceptGesture(pointer);
    if (pointer == primaryPointer()) {
        _checkDown();
        _wonArenaForPrimaryPointer = true;
        _checkUp();
    }
}

void BaseTapGestureRecognizerCls::rejectGesture(int pointer) {
    super->rejectGesture(pointer);
    if (pointer == primaryPointer()) {
        assert(state() != GestureRecognizerStateCls::possible);
        if (_sentTapDown) {
            _checkCancel(nullptr, __s("forced"));
        }
        _reset();
    }
}

String BaseTapGestureRecognizerCls::debugDescription() {
    return __s("base tap");
}

void BaseTapGestureRecognizerCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>(__s("wonArenaForPrimaryPointer"), _wonArenaForPrimaryPointer, __s("won arena")));
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("finalPosition"), _up?->position, nullptr));
    properties->add(<Offset>make<DiagnosticsPropertyCls>(__s("finalLocalPosition"), _up?->localPosition(), _up?->position));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("button"), _down?->buttons, nullptr));
    properties->add(make<FlagPropertyCls>(__s("sentTapDown"), _sentTapDown, __s("sent tap down")));
}

void BaseTapGestureRecognizerCls::_checkDown() {
    if (_sentTapDown) {
        return;
    }
    handleTapDown(_down!);
    _sentTapDown = true;
}

void BaseTapGestureRecognizerCls::_checkUp() {
    if (!_wonArenaForPrimaryPointer || _up == nullptr) {
        return;
    }
    assert(_up!->pointer == _down!->pointer);
    handleTapUp(_down!, _up!);
    _reset();
}

void BaseTapGestureRecognizerCls::_checkCancel(PointerCancelEvent event, String note) {
    handleTapCancel(_down!, event, note);
}

void BaseTapGestureRecognizerCls::_reset() {
    _sentTapDown = false;
    _wonArenaForPrimaryPointer = false;
    _up = nullptr;
    _down = nullptr;
}

bool TapGestureRecognizerCls::isPointerAllowed(PointerDownEvent event) {
    ;
    return super->isPointerAllowed(event);
}

void TapGestureRecognizerCls::handleTapDown(PointerDownEvent down) {
    TapDownDetails details = make<TapDownDetailsCls>(down->position, down->localPosition(), getKindForPointer(down->pointer));
    ;
}

void TapGestureRecognizerCls::handleTapUp(PointerDownEvent down, PointerUpEvent up) {
    TapUpDetails details = make<TapUpDetailsCls>(up->kind, up->position, up->localPosition());
    ;
}

void TapGestureRecognizerCls::handleTapCancel(PointerCancelEvent cancel, PointerDownEvent down, String reason) {
    String note = reason == __s("")? reason : __s("$reason ");
    ;
}

String TapGestureRecognizerCls::debugDescription() {
    return __s("tap");
}
