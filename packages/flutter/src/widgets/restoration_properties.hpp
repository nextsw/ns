#ifndef RESTORATION_PROPERTIES_H
#define RESTORATION_PROPERTIES_H
#include <memory>

#include <async/async.hpp>
#include <flutter/foundation.hpp>
#include <flutter/services.hpp>
#include "editable_text.hpp"
#include "restoration.hpp"



class RestorableValue<T> : RestorableProperty<T> {
public:

    T value();

    void  value(T newValue);

    void initWithValue(T value);

    void didUpdateValue(T oldValue);

private:
    T _value;


};

class _RestorablePrimitiveValueN<T extends Object> : RestorableValue<T> {
public:

    T createDefaultValue();

    void didUpdateValue(T oldValue);

    T fromPrimitives(Object serialized);

    Object toPrimitives();

private:
    T _defaultValue;


     _RestorablePrimitiveValueN(T _defaultValue);

};

class _RestorablePrimitiveValue<T extends Object> : _RestorablePrimitiveValueN<T> {
public:

    void  value(T value);

    T fromPrimitives(Object serialized);

    Object toPrimitives();

private:

     _RestorablePrimitiveValue(Unknown);

};

class RestorableNum<T extends num> : _RestorablePrimitiveValue<T> {
public:

     RestorableNum(Unknown);

private:

};

class RestorableDouble : RestorableNum<double> {
public:

     RestorableDouble(Unknown);

private:

};

class RestorableInt : RestorableNum<int> {
public:

     RestorableInt(Unknown);

private:

};

class RestorableString : _RestorablePrimitiveValue<String> {
public:

     RestorableString(Unknown);

private:

};

class RestorableBool : _RestorablePrimitiveValue<bool> {
public:

     RestorableBool(Unknown);

private:

};

class RestorableBoolN : _RestorablePrimitiveValueN<bool> {
public:

     RestorableBoolN(Unknown);

private:

};

class RestorableNumN<T extends num> : _RestorablePrimitiveValueN<T> {
public:

     RestorableNumN(Unknown);

private:

};

class RestorableDoubleN : RestorableNumN<double> {
public:

     RestorableDoubleN(Unknown);

private:

};

class RestorableIntN : RestorableNumN<int> {
public:

     RestorableIntN(Unknown);

private:

};

class RestorableStringN : _RestorablePrimitiveValueN<String> {
public:

     RestorableStringN(Unknown);

private:

};

class RestorableDateTime : RestorableValue<DateTime> {
public:

     RestorableDateTime(DateTime defaultValue);

    DateTime createDefaultValue();

    void didUpdateValue(DateTime oldValue);

    DateTime fromPrimitives(Object data);

    Object toPrimitives();

private:
    DateTime _defaultValue;


};

class RestorableDateTimeN : RestorableValue<DateTime> {
public:

     RestorableDateTimeN(DateTime defaultValue);

    DateTime createDefaultValue();

    void didUpdateValue(DateTime oldValue);

    DateTime fromPrimitives(Object data);

    Object toPrimitives();

private:
    DateTime _defaultValue;


};

class RestorableListenable<T extends Listenable> : RestorableProperty<T> {
public:

    T value();

    void initWithValue(T value);

    void dispose();

private:
    T _value;


};

class RestorableChangeNotifier<T extends ChangeNotifier> : RestorableListenable<T> {
public:

    void initWithValue(T value);

    void dispose();

private:

    void _disposeOldValue();

};

class RestorableTextEditingController : RestorableChangeNotifier<TextEditingController> {
public:

     RestorableTextEditingController(String text);

    void  fromValue(TextEditingValue value);

    TextEditingController createDefaultValue();

    TextEditingController fromPrimitives(Object data);

    Object toPrimitives();

private:
    TextEditingValue _initialValue;


};

#endif