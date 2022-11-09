#include "keyboard_key.g.hpp"
String LogicalKeyboardKeyCls::keyLabel() {
    return _unicodeKeyLabel(keyId) ?? _keyLabels[keyId] ?? "";
}

String LogicalKeyboardKeyCls::debugName() {
    String result;
    assert([=] () {
        result = _keyLabels[keyId];
        if (result == nullptr) {
            String unicodeKeyLabel = _unicodeKeyLabel(keyId);
            if (unicodeKeyLabel != nullptr) {
                result = "Key $unicodeKeyLabel";
            } else {
                result = "Key with ID 0x${keyId.toRadixString(16).padLeft(11, '0')}";
            }
        }
        return true;
    }());
    return result;
}

int LogicalKeyboardKeyCls::hashCode() {
    return keyId->hashCode;
}

bool LogicalKeyboardKeyCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is LogicalKeyboardKey && other->keyId == keyId;
}

LogicalKeyboardKey LogicalKeyboardKeyCls::findKeyByKeyId(int keyId) {
    return _knownLogicalKeys[keyId];
}

bool LogicalKeyboardKeyCls::isControlCharacter(String label) {
    if (label->length != 1) {
        return false;
    }
    int codeUnit = label->codeUnitAt(0);
    return (codeUnit <= 0x1f && codeUnit >= 0x00) || (codeUnit >= 0x7f && codeUnit <= 0x9f);
}

bool LogicalKeyboardKeyCls::isAutogenerated() {
    return (keyId & planeMask) >= startOfPlatformPlanes;
}

Set<LogicalKeyboardKey> LogicalKeyboardKeyCls::synonyms() {
    LogicalKeyboardKey result = _synonyms[this];
    return result == nullptr? makeSet() : makeSet(ArrayItem);
}

Set<LogicalKeyboardKey> LogicalKeyboardKeyCls::collapseSynonyms(Set<LogicalKeyboardKey> input) {
    Set<LogicalKeyboardKey> result = makeSet();
    for (LogicalKeyboardKey key : input) {
        LogicalKeyboardKey synonym = _synonyms[key];
        result->add(synonym ?? key);
    }
    return result;
}

void LogicalKeyboardKeyCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<StringPropertyCls>("keyId", "0x${keyId.toRadixString(16).padLeft(8, '0')}"));
    properties->add(make<StringPropertyCls>("keyLabel", keyLabel));
    properties->add(make<StringPropertyCls>("debugName", debugNamenullptr));
}

Iterable<LogicalKeyboardKey> LogicalKeyboardKeyCls::knownLogicalKeys() {
    return _knownLogicalKeys->values;
}

int LogicalKeyboardKeyCls::_nonValueBits(int n) {
    int divisorForValueMask = valueMask + 1;
    int valueMaskWidth = 32;
    int firstDivisorWidth = 28;
    assert(divisorForValueMask == (1 << firstDivisorWidth) * (1 << (valueMaskWidth - firstDivisorWidth)));
    int maxSafeIntegerWidth = 52;
    int nonValueMask = (1 << (maxSafeIntegerWidth - valueMaskWidth)) - 1;
    if (kIsWeb) {
        return (n / divisorForValueMask)->floor() & nonValueMask;
    } else {
        return (n >> valueMaskWidth) & nonValueMask;
    }
}

String LogicalKeyboardKeyCls::_unicodeKeyLabel(int keyId) {
    if (_nonValueBits(keyId) == 0) {
        return StringCls->fromCharCode(keyId)->toUpperCase();
    }
    return nullptr;
}

String PhysicalKeyboardKeyCls::debugName() {
    String result;
    assert([=] () {
        result = _debugNames[usbHidUsage] ?? "Key with ID 0x${usbHidUsage.toRadixString(16).padLeft(8, '0')}";
        return true;
    }());
    return result;
}

int PhysicalKeyboardKeyCls::hashCode() {
    return usbHidUsage->hashCode;
}

bool PhysicalKeyboardKeyCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType != runtimeType) {
        return false;
    }
    return other is PhysicalKeyboardKey && other->usbHidUsage == usbHidUsage;
}

PhysicalKeyboardKey PhysicalKeyboardKeyCls::findKeyByCode(int usageCode) {
    return _knownPhysicalKeys[usageCode];
}

void PhysicalKeyboardKeyCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<StringPropertyCls>("usbHidUsage", "0x${usbHidUsage.toRadixString(16).padLeft(8, '0')}"));
    properties->add(make<StringPropertyCls>("debugName", debugNamenullptr));
}

Iterable<PhysicalKeyboardKey> PhysicalKeyboardKeyCls::knownPhysicalKeys() {
    return _knownPhysicalKeys->values;
}
