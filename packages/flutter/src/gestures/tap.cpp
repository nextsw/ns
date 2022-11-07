#include "tap.hpp"
TapDownDetails::TapDownDetails(Offset globalPosition, PointerDeviceKind kind, Offset localPosition) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition ?? globalPosition;
    }
}

TapUpDetails::TapUpDetails(Offset globalPosition, PointerDeviceKind kind, Offset localPosition) {
    {
        assert(globalPosition != nullptr);
        localPosition = localPosition ?? globalPosition;
    }
}

BaseTapGestureRecognizer::BaseTapGestureRecognizer(Unknown, Unknown) {
    {
        super(kPressTimeout);
    }
}

void BaseTapGestureRecognizer::addAllowedPointer(PointerDownEvent event) {
    assert(event != nullptr);
    if (state == GestureRecognizerState.ready) {
        if (_down != nullptr && _up != nullptr) {
            assert(_down!.pointer == _up!.pointer);
            _reset();
        }
        assert(_down == nullptr && _up == nullptr);
        _down = event;
    }
    if (_down != nullptr) {
        super.addAllowedPointer(event);
    }
}

void BaseTapGestureRecognizer::startTrackingPointer(int pointer, Matrix4 transform) {
    assert(_down != nullptr);
    super.startTrackingPointer(pointer, transform);
}

void BaseTapGestureRecognizer::handlePrimaryPointer(PointerEvent event) {
    if (event is PointerUpEvent) {
        _up = event;
        _checkUp();
    } else     {
        if (event is PointerCancelEvent) {
        resolve(GestureDisposition.rejected);
        if (_sentTapDown) {
            _checkCancel(event, "");
        }
        _reset();
    } else     {
        if (event.buttons != _down!.buttons) {
        resolve(GestureDisposition.rejected);
        stopTrackingPointer(primaryPointer!);
    }
;
    };
    }}

void BaseTapGestureRecognizer::resolve(GestureDisposition disposition) {
    if (_wonArenaForPrimaryPointer && disposition == GestureDisposition.rejected) {
        assert(_sentTapDown);
        _checkCancel(nullptr, "spontaneous");
        _reset();
    }
    super.resolve(disposition);
}

void BaseTapGestureRecognizer::didExceedDeadline() {
    _checkDown();
}

void BaseTapGestureRecognizer::acceptGesture(int pointer) {
    super.acceptGesture(pointer);
    if (pointer == primaryPointer) {
        _checkDown();
        _wonArenaForPrimaryPointer = true;
        _checkUp();
    }
}

void BaseTapGestureRecognizer::rejectGesture(int pointer) {
    super.rejectGesture(pointer);
    if (pointer == primaryPointer) {
        assert(state != GestureRecognizerState.possible);
        if (_sentTapDown) {
            _checkCancel(nullptr, "forced");
        }
        _reset();
    }
}

String BaseTapGestureRecognizer::debugDescription() {
    return "base tap";
}

void BaseTapGestureRecognizer::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(FlagProperty("wonArenaForPrimaryPointer"_wonArenaForPrimaryPointer, "won arena"));
    properties.add(<Offset>DiagnosticsProperty("finalPosition", _up?.positionnullptr));
    properties.add(<Offset>DiagnosticsProperty("finalLocalPosition", _up?.localPosition_up?.position));
    properties.add(<int>DiagnosticsProperty("button", _down?.buttonsnullptr));
    properties.add(FlagProperty("sentTapDown"_sentTapDown, "sent tap down"));
}

void BaseTapGestureRecognizer::_checkDown() {
    if (_sentTapDown) {
        return;
    }
    handleTapDown(_down!);
    _sentTapDown = true;
}

void BaseTapGestureRecognizer::_checkUp() {
    if (!_wonArenaForPrimaryPointer || _up == nullptr) {
        return;
    }
    assert(_up!.pointer == _down!.pointer);
    handleTapUp(_down!, _up!);
    _reset();
}

void BaseTapGestureRecognizer::_checkCancel(PointerCancelEvent event, String note) {
    handleTapCancel(_down!, event, note);
}

void BaseTapGestureRecognizer::_reset() {
    _sentTapDown = false;
    _wonArenaForPrimaryPointer = false;
    _up = nullptr;
    _down = nullptr;
}

bool TapGestureRecognizer::isPointerAllowed(PointerDownEvent event) {
    ;
    return super.isPointerAllowed(event);
}

void TapGestureRecognizer::handleTapDown(PointerDownEvent down) {
    TapDownDetails details = TapDownDetails(down.position, down.localPosition, getKindForPointer(down.pointer));
    ;
}

void TapGestureRecognizer::handleTapUp(PointerDownEvent down, PointerUpEvent up) {
    TapUpDetails details = TapUpDetails(up.kind, up.position, up.localPosition);
    ;
}

void TapGestureRecognizer::handleTapCancel(PointerCancelEvent cancel, PointerDownEvent down, String reason) {
    String note = reason == ""? reason : "$reason ";
    ;
}

String TapGestureRecognizer::debugDescription() {
    return "tap";
}
