#include "key.hpp"
String KeyDataCls::toString() {
    return __sf("KeyData(key %s, physical: 0x%s, logical: %s, character: %s%s%s", _typeToString(type), physical->toRadixString(16), _logicalToString(), _escapeCharacter(), _quotedCharCode(), synthesized? __s(", synthesized") : __s(")"));
}

String KeyDataCls::toStringFull() {
    return __sf("%s(type: %s, timeStamp: %s, physical: 0x%s, logical: 0x%s, character: %s, synthesized: %s)", runtimeType, _typeToString(type), timeStamp, physical->toRadixString(16), logical->toRadixString(16), _escapeCharacter(), synthesized);
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
    String result = __sf("0x%s", logical->toRadixString(16));
    int planeNum = _nonValueBits(logical) & 0x0FF;
    String planeDescription = ([=] () {
    ;
    return __s("");
})();
    return __sf("%s%s", result, planeDescription);
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
    return __sf(" (0x%s)", hexChars->join(__s(" ")));
}

String KeyDataCls::_typeToString(KeyEventType type) {
    ;
}
