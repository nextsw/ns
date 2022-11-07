#include "raw_keyboard_linux.hpp"
RawKeyEventDataLinux::RawKeyEventDataLinux(bool isDown, int keyCode, KeyHelper keyHelper, int modifiers, int scanCode, int specifiedLogicalKey, int unicodeScalarValues) {
    {
        assert(scanCode != nullptr);
        assert(unicodeScalarValues != nullptr);
        assert((unicodeScalarValues & ~LogicalKeyboardKey.valueMask) == 0);
        assert(keyCode != nullptr);
        assert(modifiers != nullptr);
        assert(keyHelper != nullptr);
    }
}

String RawKeyEventDataLinux::keyLabel() {
    return unicodeScalarValues == 0? "" : String.fromCharCode(unicodeScalarValues);
}

PhysicalKeyboardKey RawKeyEventDataLinux::physicalKey() {
    return kLinuxToPhysicalKey[scanCode] ?? PhysicalKeyboardKey(LogicalKeyboardKey.webPlane + scanCode);
}

LogicalKeyboardKey RawKeyEventDataLinux::logicalKey() {
    if (specifiedLogicalKey != nullptr) {
        int key = specifiedLogicalKey!;
        return LogicalKeyboardKey.findKeyByKeyId(key) ?? LogicalKeyboardKey(key);
    }
    LogicalKeyboardKey numPadKey = keyHelper.numpadKey(keyCode);
    if (numPadKey != nullptr) {
        return numPadKey;
    }
    if (keyLabel.isNotEmpty && !LogicalKeyboardKey.isControlCharacter(keyLabel)) {
        int keyId = LogicalKeyboardKey.unicodePlane | (unicodeScalarValues & LogicalKeyboardKey.valueMask);
        return LogicalKeyboardKey.findKeyByKeyId(keyId) ?? LogicalKeyboardKey(keyId);
    }
    LogicalKeyboardKey newKey = keyHelper.logicalKey(keyCode);
    if (newKey != nullptr) {
        return newKey;
    }
    return LogicalKeyboardKey(keyCode | keyHelper.platformPlane);
}

bool RawKeyEventDataLinux::isModifierPressed(ModifierKey key, KeyboardSide side) {
    return keyHelper.isModifierPressed(key, modifiersside, keyCode, isDown);
}

KeyboardSide RawKeyEventDataLinux::getModifierSide(ModifierKey key) {
    return keyHelper.getModifierSide(key);
}

void RawKeyEventDataLinux::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<String>DiagnosticsProperty("toolkit", keyHelper.debugToolkit));
    properties.add(<int>DiagnosticsProperty("unicodeScalarValues", unicodeScalarValues));
    properties.add(<int>DiagnosticsProperty("scanCode", scanCode));
    properties.add(<int>DiagnosticsProperty("keyCode", keyCode));
    properties.add(<int>DiagnosticsProperty("modifiers", modifiers));
    properties.add(<bool>DiagnosticsProperty("isDown", isDown));
    properties.add(<int>DiagnosticsProperty("specifiedLogicalKey", specifiedLogicalKeynullptr));
}

bool RawKeyEventDataLinux::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is RawKeyEventDataLinux && other.keyHelper.runtimeType == keyHelper.runtimeType && other.unicodeScalarValues == unicodeScalarValues && other.scanCode == scanCode && other.keyCode == keyCode && other.modifiers == modifiers && other.isDown == isDown;
}

int RawKeyEventDataLinux::hashCode() {
    return Object.hash(keyHelper.runtimeType, unicodeScalarValues, scanCode, keyCode, modifiers, isDown);
}

KeyHelper::KeyHelper(String toolkit) {
    {
        if (toolkit == "glfw") {
            return GLFWKeyHelper();
        } else         {
            if (toolkit == "gtk") {
            return GtkKeyHelper();
        } else {
            ;
        }
;
        }    }
}

String GLFWKeyHelper::debugToolkit() {
    return "GLFW";
}

bool GLFWKeyHelper::isModifierPressed(bool isDown, ModifierKey key, int keyCode, int modifiers, KeyboardSide side) {
    modifiers = _mergeModifiers(modifiers, keyCode, isDown);
    ;
}

KeyboardSide GLFWKeyHelper::getModifierSide(ModifierKey key) {
    return KeyboardSide.all;
}

LogicalKeyboardKey GLFWKeyHelper::numpadKey(int keyCode) {
    return kGlfwNumpadMap[keyCode];
}

LogicalKeyboardKey GLFWKeyHelper::logicalKey(int keyCode) {
    return kGlfwToLogicalKey[keyCode];
}

int GLFWKeyHelper::platformPlane() {
    return LogicalKeyboardKey.glfwPlane;
}

int GLFWKeyHelper::_mergeModifiers(bool isDown, int keyCode, int modifiers) {
    int shiftLeftKeyCode = 340;
    int shiftRightKeyCode = 344;
    int controlLeftKeyCode = 341;
    int controlRightKeyCode = 345;
    int altLeftKeyCode = 342;
    int altRightKeyCode = 346;
    int metaLeftKeyCode = 343;
    int metaRightKeyCode = 347;
    int capsLockKeyCode = 280;
    int numLockKeyCode = 282;
    int modifierChange = 0;
    ;
    return isDown? modifiers | modifierChange : modifiers & ~modifierChange;
}

String GtkKeyHelper::debugToolkit() {
    return "GTK";
}

bool GtkKeyHelper::isModifierPressed(bool isDown, ModifierKey key, int keyCode, int modifiers, KeyboardSide side) {
    modifiers = _mergeModifiers(modifiers, keyCode, isDown);
    ;
}

KeyboardSide GtkKeyHelper::getModifierSide(ModifierKey key) {
    return KeyboardSide.all;
}

LogicalKeyboardKey GtkKeyHelper::numpadKey(int keyCode) {
    return kGtkNumpadMap[keyCode];
}

LogicalKeyboardKey GtkKeyHelper::logicalKey(int keyCode) {
    return kGtkToLogicalKey[keyCode];
}

int GtkKeyHelper::platformPlane() {
    return LogicalKeyboardKey.gtkPlane;
}

int GtkKeyHelper::_mergeModifiers(bool isDown, int keyCode, int modifiers) {
    int shiftLeftKeyCode = 0xffe1;
    int shiftRightKeyCode = 0xffe2;
    int controlLeftKeyCode = 0xffe3;
    int controlRightKeyCode = 0xffe4;
    int capsLockKeyCode = 0xffe5;
    int shiftLockKeyCode = 0xffe6;
    int altLeftKeyCode = 0xffe9;
    int altRightKeyCode = 0xffea;
    int metaLeftKeyCode = 0xffeb;
    int metaRightKeyCode = 0xffec;
    int numLockKeyCode = 0xff7f;
    int modifierChange = 0;
    ;
    return isDown? modifiers | modifierChange : modifiers & ~modifierChange;
}
