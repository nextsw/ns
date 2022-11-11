#include "raw_keyboard_linux.hpp"
RawKeyEventDataLinuxCls::RawKeyEventDataLinuxCls(bool isDown, int keyCode, KeyHelper keyHelper, int modifiers, int scanCode, int specifiedLogicalKey, int unicodeScalarValues) {
    {
        assert(scanCode != nullptr);
        assert(unicodeScalarValues != nullptr);
        assert((unicodeScalarValues & ~LogicalKeyboardKeyCls->valueMask) == 0);
        assert(keyCode != nullptr);
        assert(modifiers != nullptr);
        assert(keyHelper != nullptr);
    }
}

String RawKeyEventDataLinuxCls::keyLabel() {
    return unicodeScalarValues == 0? __s("") : StringCls->fromCharCode(unicodeScalarValues);
}

PhysicalKeyboardKey RawKeyEventDataLinuxCls::physicalKey() {
    return kLinuxToPhysicalKey[scanCode] or make<PhysicalKeyboardKeyCls>(LogicalKeyboardKeyCls::webPlane + scanCode);
}

LogicalKeyboardKey RawKeyEventDataLinuxCls::logicalKey() {
    if (specifiedLogicalKey != nullptr) {
        int key = specifiedLogicalKey!;
        return LogicalKeyboardKeyCls->findKeyByKeyId(key) or make<LogicalKeyboardKeyCls>(key);
    }
    LogicalKeyboardKey numPadKey = keyHelper->numpadKey(keyCode);
    if (numPadKey != nullptr) {
        return numPadKey;
    }
    if (keyLabel()->isNotEmpty() && !LogicalKeyboardKeyCls->isControlCharacter(keyLabel())) {
        int keyId = LogicalKeyboardKeyCls::unicodePlane | (unicodeScalarValues & LogicalKeyboardKeyCls::valueMask);
        return LogicalKeyboardKeyCls->findKeyByKeyId(keyId) or make<LogicalKeyboardKeyCls>(keyId);
    }
    LogicalKeyboardKey newKey = keyHelper->logicalKey(keyCode);
    if (newKey != nullptr) {
        return newKey;
    }
    return make<LogicalKeyboardKeyCls>(keyCode | keyHelper->platformPlane());
}

bool RawKeyEventDataLinuxCls::isModifierPressed(ModifierKey key, KeyboardSide side) {
    return keyHelper->isModifierPressed(key, modifiersside, keyCode, isDown);
}

KeyboardSide RawKeyEventDataLinuxCls::getModifierSide(ModifierKey key) {
    return keyHelper->getModifierSide(key);
}

void RawKeyEventDataLinuxCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<String>make<DiagnosticsPropertyCls>(__s("toolkit"), keyHelper->debugToolkit()));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("unicodeScalarValues"), unicodeScalarValues));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("scanCode"), scanCode));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("keyCode"), keyCode));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("modifiers"), modifiers));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("isDown"), isDown));
    properties->add(<int>make<DiagnosticsPropertyCls>(__s("specifiedLogicalKey"), specifiedLogicalKeynullptr));
}

bool RawKeyEventDataLinuxCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<RawKeyEventDataLinux>(other) && other->keyHelper->runtimeType == keyHelper->runtimeType && other->unicodeScalarValues == unicodeScalarValues && other->scanCode == scanCode && other->keyCode == keyCode && other->modifiers == modifiers && other->isDown == isDown;
}

int RawKeyEventDataLinuxCls::hashCode() {
    return ObjectCls->hash(keyHelper->runtimeType, unicodeScalarValues, scanCode, keyCode, modifiers, isDown);
}

KeyHelperCls::KeyHelperCls(String toolkit) {
    {
        if (toolkit == __s("glfw")) {
            return make<GLFWKeyHelperCls>();
        } else         {
            if (toolkit == __s("gtk")) {
            return make<GtkKeyHelperCls>();
        } else {
            throw make<FlutterErrorCls>(__s("Window toolkit not recognized: $toolkit"));
        }
;
        }    }
}

String GLFWKeyHelperCls::debugToolkit() {
    return __s("GLFW");
}

bool GLFWKeyHelperCls::isModifierPressed(bool isDown, ModifierKey key, int keyCode, int modifiers, KeyboardSide side) {
    modifiers = _mergeModifiers(modifiers, keyCode, isDown);
    ;
}

KeyboardSide GLFWKeyHelperCls::getModifierSide(ModifierKey key) {
    return KeyboardSideCls::all;
}

LogicalKeyboardKey GLFWKeyHelperCls::numpadKey(int keyCode) {
    return kGlfwNumpadMap[keyCode];
}

LogicalKeyboardKey GLFWKeyHelperCls::logicalKey(int keyCode) {
    return kGlfwToLogicalKey[keyCode];
}

int GLFWKeyHelperCls::platformPlane() {
    return LogicalKeyboardKeyCls::glfwPlane;
}

int GLFWKeyHelperCls::_mergeModifiers(bool isDown, int keyCode, int modifiers) {
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

String GtkKeyHelperCls::debugToolkit() {
    return __s("GTK");
}

bool GtkKeyHelperCls::isModifierPressed(bool isDown, ModifierKey key, int keyCode, int modifiers, KeyboardSide side) {
    modifiers = _mergeModifiers(modifiers, keyCode, isDown);
    ;
}

KeyboardSide GtkKeyHelperCls::getModifierSide(ModifierKey key) {
    return KeyboardSideCls::all;
}

LogicalKeyboardKey GtkKeyHelperCls::numpadKey(int keyCode) {
    return kGtkNumpadMap[keyCode];
}

LogicalKeyboardKey GtkKeyHelperCls::logicalKey(int keyCode) {
    return kGtkToLogicalKey[keyCode];
}

int GtkKeyHelperCls::platformPlane() {
    return LogicalKeyboardKeyCls::gtkPlane;
}

int GtkKeyHelperCls::_mergeModifiers(bool isDown, int keyCode, int modifiers) {
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
