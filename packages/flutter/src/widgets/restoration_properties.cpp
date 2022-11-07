#include "restoration_properties.hpp"
T RestorableValue::value() {
    assert(isRegistered);
    return (;
}

void RestorableValue::value(T newValue) {
    assert(isRegistered);
    if (newValue != _value) {
        T oldValue = _value;
        _value = newValue;
        didUpdateValue(oldValue);
    }
}

void RestorableValue::initWithValue(T value) {
    _value = value;
}

T _RestorablePrimitiveValueN::createDefaultValue() {
    return _defaultValue;
}

void _RestorablePrimitiveValueN::didUpdateValue(T oldValue) {
    assert(debugIsSerializableForRestoration(value));
    notifyListeners();
}

T _RestorablePrimitiveValueN::fromPrimitives(Object serialized) {
    return (;
}

Object _RestorablePrimitiveValueN::toPrimitives() {
    return value;
}

_RestorablePrimitiveValueN::_RestorablePrimitiveValueN(T _defaultValue) {
    {
        assert(debugIsSerializableForRestoration(_defaultValue));
        super();
    }
}

void _RestorablePrimitiveValue::value(T value) {
    assert(value != nullptr);
    super.value = value;
}

T _RestorablePrimitiveValue::fromPrimitives(Object serialized) {
    assert(serialized != nullptr);
    return super.fromPrimitives(serialized);
}

Object _RestorablePrimitiveValue::toPrimitives() {
    assert(value != nullptr);
    return super.toPrimitives()!;
}

_RestorablePrimitiveValue::_RestorablePrimitiveValue(Unknown) {
    {
        assert(defaultValue != nullptr);
        assert(debugIsSerializableForRestoration(defaultValue));
    }
}

RestorableNum::RestorableNum(Unknown) {
    {
        assert(defaultValue != nullptr);
    }
}

RestorableDouble::RestorableDouble(Unknown) {
    {
        assert(defaultValue != nullptr);
    }
}

RestorableInt::RestorableInt(Unknown) {
    {
        assert(defaultValue != nullptr);
    }
}

RestorableString::RestorableString(Unknown) {
    {
        assert(defaultValue != nullptr);
    }
}

RestorableBool::RestorableBool(Unknown) {
    {
        assert(defaultValue != nullptr);
    }
}

RestorableDateTime::RestorableDateTime(DateTime defaultValue) {
    {
        _defaultValue = defaultValue;
    }
}

DateTime RestorableDateTime::createDefaultValue() {
    return _defaultValue;
}

void RestorableDateTime::didUpdateValue(DateTime oldValue) {
    assert(debugIsSerializableForRestoration(value.millisecondsSinceEpoch));
    notifyListeners();
}

DateTime RestorableDateTime::fromPrimitives(Object data) {
    return DateTime.fromMillisecondsSinceEpoch(();
}

Object RestorableDateTime::toPrimitives() {
    return value.millisecondsSinceEpoch;
}

RestorableDateTimeN::RestorableDateTimeN(DateTime defaultValue) {
    {
        _defaultValue = defaultValue;
    }
}

DateTime RestorableDateTimeN::createDefaultValue() {
    return _defaultValue;
}

void RestorableDateTimeN::didUpdateValue(DateTime oldValue) {
    assert(debugIsSerializableForRestoration(value?.millisecondsSinceEpoch));
    notifyListeners();
}

DateTime RestorableDateTimeN::fromPrimitives(Object data) {
    return data != nullptr? DateTime.fromMillisecondsSinceEpoch(() : nullptr;
}

Object RestorableDateTimeN::toPrimitives() {
    return value?.millisecondsSinceEpoch;
}

T RestorableListenable::value() {
    assert(isRegistered);
    return _value!;
}

void RestorableListenable::initWithValue(T value) {
    assert(value != nullptr);
    _value?.removeListener(notifyListeners);
    _value = value;
    _value!.addListener(notifyListeners);
}

void RestorableListenable::dispose() {
    super.dispose();
    _value?.removeListener(notifyListeners);
}

void RestorableChangeNotifier::initWithValue(T value) {
    _disposeOldValue();
    super.initWithValue(value);
}

void RestorableChangeNotifier::dispose() {
    _disposeOldValue();
    super.dispose();
}

void RestorableChangeNotifier::_disposeOldValue() {
    if (_value != nullptr) {
        scheduleMicrotask(_value!.dispose);
    }
}

RestorableTextEditingController::RestorableTextEditingController(String text) {
}

void RestorableTextEditingController::fromValue(TextEditingValue value)

TextEditingController RestorableTextEditingController::createDefaultValue() {
    return TextEditingController.fromValue(_initialValue);
}

TextEditingController RestorableTextEditingController::fromPrimitives(Object data) {
    return TextEditingController(();
}

Object RestorableTextEditingController::toPrimitives() {
    return value.text;
}
