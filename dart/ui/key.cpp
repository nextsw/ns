#include "key.hpp"
String KeyDataCls::toString() {
    return __s("KeyData(key ${_typeToString(type)}, physical: 0x${physical.toRadixString(16)}, logical: ${_logicalToString()}, character: ${_escapeCharacter()}${_quotedCharCode()}${synthesized ? ', synthesized' : ''})");
}

String KeyDataCls::toStringFull() {
    return __s("$runtimeType(type: ${_typeToString(type)}, timeStamp: $timeStamp, physical: 0x${physical.toRadixString(16)}, logical: 0x${logical.toRadixString(16)}, character: ${_escapeCharacter()}, synthesized: $synthesized)");
}

int KeyDataCls::_nonValueBits(int n) {
    int valueMask = 0x000FFFFFFFF;
    int divisorForValueMask = valueMask + 1;
    int valueMaskWidth = 32;
    int _firstDivisorWidth = 28;
    assert(divisorForValueMask == (1 << _firstDivisorWidth) * (1 << (valueMaskWidth - _firstDivisorWidth)));
    int maxSafeIntegerWidth = 52;
    int nonValueMask = (1 << (maxSafeIntegerWidth - valueMaskWidth)) - 1;
    if (identical(0, 0.0)) {
        return (n / divisorForValueMask)->floor() & nonValueMask;
    } else {
        return (n >> valueMaskWidth) & nonValueMask;
    }
}

String KeyDataCls::_logicalToString() {
    String result = __s("0x${logical.toRadixString(16)}");
    int planeNum = _nonValueBits(logical) & 0x0FF;
    String planeDescription = ([=] () {
    ;
    return __s("");
})();
    return __s("$result$planeDescription");
}

String KeyDataCls::_escapeCharacter() {
    if (character == nullptr) {
        return __s("<none>");
    }
    ;
}

String KeyDataCls::_quotedCharCode() {
    if (character == nullptr) {
        return __s("");
    }
    Iterable<String> hexChars = character!->codeUnits()->map([=] (int code) {
    code->toRadixString(16)->padLeft(2, __s("0"));
});
    return __s(" (0x${hexChars.join(' ')})");
}

String KeyDataCls::_typeToString(KeyEventType type) {
    ;
}
