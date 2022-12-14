#include "restoration_properties.hpp"
template<typename T>
T RestorableValueCls<T>::value() {
    assert(isRegistered());
    return as<T>(_value);
}

template<typename T>
void RestorableValueCls<T>::value(T newValue) {
    assert(isRegistered());
    if (newValue != _value) {
        T oldValue = _value;
        _value = newValue;
        didUpdateValue(oldValue);
    }
}

template<typename T>
void RestorableValueCls<T>::initWithValue(T value) {
    _value = value;
}

template<typename T>
T _RestorablePrimitiveValueNCls<T>::createDefaultValue() {
    return _defaultValue;
}

template<typename T>
void _RestorablePrimitiveValueNCls<T>::didUpdateValue(T oldValue) {
    assert(debugIsSerializableForRestoration(value()));
    notifyListeners();
}

template<typename T>
T _RestorablePrimitiveValueNCls<T>::fromPrimitives(Object serialized) {
    return as<T>(serialized);
}

template<typename T>
Object _RestorablePrimitiveValueNCls<T>::toPrimitives() {
    return value();
}

template<typename T>
_RestorablePrimitiveValueNCls<T>::_RestorablePrimitiveValueNCls(T _defaultValue) : RestorableValue<T>() {
    {
        assert(debugIsSerializableForRestoration(_defaultValue));
    }
}

template<typename T>
void _RestorablePrimitiveValueCls<T>::value(T value) {
    assert(value != nullptr);
    super->value = value;
}

template<typename T>
T _RestorablePrimitiveValueCls<T>::fromPrimitives(Object serialized) {
    assert(serialized != nullptr);
    return super->fromPrimitives(serialized);
}

template<typename T>
Object _RestorablePrimitiveValueCls<T>::toPrimitives() {
    assert(value != nullptr);
    return super->toPrimitives()!;
}

template<typename T>
_RestorablePrimitiveValueCls<T>::_RestorablePrimitiveValueCls(T defaultValue) {
    {
        assert(defaultValue != nullptr);
        assert(debugIsSerializableForRestoration(defaultValue));
    }
}

template<typename T>
RestorableNumCls<T>::RestorableNumCls(T defaultValue) {
    {
        assert(defaultValue != nullptr);
    }
}

RestorableDoubleCls::RestorableDoubleCls(T defaultValue) {
    {
        assert(defaultValue != nullptr);
    }
}

RestorableIntCls::RestorableIntCls(T defaultValue) {
    {
        assert(defaultValue != nullptr);
    }
}

RestorableStringCls::RestorableStringCls(T defaultValue) {
    {
        assert(defaultValue != nullptr);
    }
}

RestorableBoolCls::RestorableBoolCls(T defaultValue) {
    {
        assert(defaultValue != nullptr);
    }
}

RestorableDateTimeCls::RestorableDateTimeCls(DateTime defaultValue) {
    {
        _defaultValue = defaultValue;
    }
}

DateTime RestorableDateTimeCls::createDefaultValue() {
    return _defaultValue;
}

void RestorableDateTimeCls::didUpdateValue(DateTime oldValue) {
    assert(debugIsSerializableForRestoration(value()->millisecondsSinceEpoch));
    notifyListeners();
}

DateTime RestorableDateTimeCls::fromPrimitives(Object data) {
    return DateTimeCls->fromMillisecondsSinceEpoch(as<int>(data!));
}

Object RestorableDateTimeCls::toPrimitives() {
    return value()->millisecondsSinceEpoch;
}

RestorableDateTimeNCls::RestorableDateTimeNCls(DateTime defaultValue) {
    {
        _defaultValue = defaultValue;
    }
}

DateTime RestorableDateTimeNCls::createDefaultValue() {
    return _defaultValue;
}

void RestorableDateTimeNCls::didUpdateValue(DateTime oldValue) {
    assert(debugIsSerializableForRestoration(value()?->millisecondsSinceEpoch));
    notifyListeners();
}

DateTime RestorableDateTimeNCls::fromPrimitives(Object data) {
    return data != nullptr? DateTimeCls->fromMillisecondsSinceEpoch(as<int>(data)) : nullptr;
}

Object RestorableDateTimeNCls::toPrimitives() {
    return value()?->millisecondsSinceEpoch;
}

template<typename T>
T RestorableListenableCls<T>::value() {
    assert(isRegistered());
    return _value!;
}

template<typename T>
void RestorableListenableCls<T>::initWithValue(T value) {
    assert(value != nullptr);
    _value?->removeListener(notifyListeners);
    _value = value;
    _value!->addListener(notifyListeners);
}

template<typename T>
void RestorableListenableCls<T>::dispose() {
    super->dispose();
    _value?->removeListener(notifyListeners);
}

template<typename T>
void RestorableChangeNotifierCls<T>::initWithValue(T value) {
    _disposeOldValue();
    super->initWithValue(value);
}

template<typename T>
void RestorableChangeNotifierCls<T>::dispose() {
    _disposeOldValue();
    super->dispose();
}

template<typename T>
void RestorableChangeNotifierCls<T>::_disposeOldValue() {
    if (_value != nullptr) {
        scheduleMicrotask(_value!->dispose);
    }
}

RestorableTextEditingControllerCls::RestorableTextEditingControllerCls(String text) {
}

void RestorableTextEditingControllerCls::fromValue(TextEditingValue value)

TextEditingController RestorableTextEditingControllerCls::createDefaultValue() {
    return TextEditingControllerCls->fromValue(_initialValue);
}

TextEditingController RestorableTextEditingControllerCls::fromPrimitives(Object data) {
    return make<TextEditingControllerCls>(as<String>(data!));
}

Object RestorableTextEditingControllerCls::toPrimitives() {
    return value()->text;
}
