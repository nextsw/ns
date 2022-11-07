#include "key.hpp"
String KeyData::toString() {
    return "KeyData(key ${_typeToString(type)}, physical: 0x${physical.toRadixString(16)}, logical: ${_logicalToString()}, character: ${_escapeCharacter()}${_quotedCharCode()}${synthesized ? ', synthesized' : ''})";
}

String KeyData::toStringFull() {
    return "$runtimeType(type: ${_typeToString(type)}, timeStamp: $timeStamp, physical: 0x${physical.toRadixString(16)}, logical: 0x${logical.toRadixString(16)}, character: ${_escapeCharacter()}, synthesized: $synthesized)";
}

int KeyData::_nonValueBits(int n) {
    int valueMask = 0x000FFFFFFFF;
    int divisorForValueMask = valueMask + 1;
    int valueMaskWidth = 32;
    int _firstDivisorWidth = 28;
    assert(divisorForValueMask == (1 << _firstDivisorWidth) * (1 << (valueMaskWidth - _firstDivisorWidth)));
    int maxSafeIntegerWidth = 52;
    int nonValueMask = (1 << (maxSafeIntegerWidth - valueMaskWidth)) - 1;
    if (identical(0, 0.0)) {
        return (n / divisorForValueMask).floor() & nonValueMask;
    } else {
        return (n >> valueMaskWidth) & nonValueMask;
    }
}

String KeyData::_logicalToString() {
    String result = "0x${logical.toRadixString(16)}";
    int planeNum = _nonValueBits(logical) & 0x0FF;
    String planeDescription = ()();
    return "$result$planeDescription";
}

String KeyData::_escapeCharacter() {
    if (character == nullptr) {
        return "<none>";
    }
    ;
}

String KeyData::_quotedCharCode() {
    if (character == nullptr)     {
        return "";
    }
    Iterable<String> hexChars = character!.codeUnits.map();
    return " (0x${hexChars.join(' ')})";
}

String KeyData::_typeToString(KeyEventType type) {
    ;
}
