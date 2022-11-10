#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_RESTORATION_PROPERTIES
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_RESTORATION_PROPERTIES
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "editable_text.hpp"
#include "restoration.hpp"


template<typename T> class RestorableValueCls : public RestorablePropertyCls<T> {
public:

    virtual T value();

    virtual void  value(T newValue);

    virtual void initWithValue(T value);

    virtual void didUpdateValue(T oldValue);
private:
    T _value;


};
template<typename T> using RestorableValue = std::shared_ptr<RestorableValueCls<T>>;

template<typename T> class _RestorablePrimitiveValueNCls : public RestorableValueCls<T> {
public:

    virtual T createDefaultValue();

    virtual void didUpdateValue(T oldValue);

    virtual T fromPrimitives(Object serialized);

    virtual Object toPrimitives();

private:
    T _defaultValue;


     _RestorablePrimitiveValueNCls(T _defaultValue);

};
template<typename T> using _RestorablePrimitiveValueN = std::shared_ptr<_RestorablePrimitiveValueNCls<T>>;

template<typename T> class _RestorablePrimitiveValueCls : public _RestorablePrimitiveValueNCls<T> {
public:

    virtual void  value(T value);

    virtual T fromPrimitives(Object serialized);

    virtual Object toPrimitives();

private:

     _RestorablePrimitiveValueCls(Unknown defaultValue);

};
template<typename T> using _RestorablePrimitiveValue = std::shared_ptr<_RestorablePrimitiveValueCls<T>>;

template<typename T> class RestorableNumCls : public _RestorablePrimitiveValueCls<T> {
public:

     RestorableNumCls(Unknown defaultValue);

private:

};
template<typename T> using RestorableNum = std::shared_ptr<RestorableNumCls<T>>;

class RestorableDoubleCls : public RestorableNumCls<double> {
public:

     RestorableDoubleCls(Unknown defaultValue);

private:

};
using RestorableDouble = std::shared_ptr<RestorableDoubleCls>;

class RestorableIntCls : public RestorableNumCls<int> {
public:

     RestorableIntCls(Unknown defaultValue);

private:

};
using RestorableInt = std::shared_ptr<RestorableIntCls>;

class RestorableStringCls : public _RestorablePrimitiveValueCls<String> {
public:

     RestorableStringCls(Unknown defaultValue);

private:

};
using RestorableString = std::shared_ptr<RestorableStringCls>;

class RestorableBoolCls : public _RestorablePrimitiveValueCls<bool> {
public:

     RestorableBoolCls(Unknown defaultValue);

private:

};
using RestorableBool = std::shared_ptr<RestorableBoolCls>;

class RestorableBoolNCls : public _RestorablePrimitiveValueNCls<bool> {
public:

     RestorableBoolNCls(Unknown defaultValue);
private:

};
using RestorableBoolN = std::shared_ptr<RestorableBoolNCls>;

template<typename T> class RestorableNumNCls : public _RestorablePrimitiveValueNCls<T> {
public:

     RestorableNumNCls(Unknown defaultValue);
private:

};
template<typename T> using RestorableNumN = std::shared_ptr<RestorableNumNCls<T>>;

class RestorableDoubleNCls : public RestorableNumNCls<double> {
public:

     RestorableDoubleNCls(Unknown defaultValue);
private:

};
using RestorableDoubleN = std::shared_ptr<RestorableDoubleNCls>;

class RestorableIntNCls : public RestorableNumNCls<int> {
public:

     RestorableIntNCls(Unknown defaultValue);
private:

};
using RestorableIntN = std::shared_ptr<RestorableIntNCls>;

class RestorableStringNCls : public _RestorablePrimitiveValueNCls<String> {
public:

     RestorableStringNCls(Unknown defaultValue);
private:

};
using RestorableStringN = std::shared_ptr<RestorableStringNCls>;

class RestorableDateTimeCls : public RestorableValueCls<DateTime> {
public:

     RestorableDateTimeCls(DateTime defaultValue);

    virtual DateTime createDefaultValue();

    virtual void didUpdateValue(DateTime oldValue);

    virtual DateTime fromPrimitives(Object data);

    virtual Object toPrimitives();

private:
    DateTime _defaultValue;


};
using RestorableDateTime = std::shared_ptr<RestorableDateTimeCls>;

class RestorableDateTimeNCls : public RestorableValueCls<DateTime> {
public:

     RestorableDateTimeNCls(DateTime defaultValue);

    virtual DateTime createDefaultValue();

    virtual void didUpdateValue(DateTime oldValue);

    virtual DateTime fromPrimitives(Object data);

    virtual Object toPrimitives();

private:
    DateTime _defaultValue;


};
using RestorableDateTimeN = std::shared_ptr<RestorableDateTimeNCls>;

template<typename T> class RestorableListenableCls : public RestorablePropertyCls<T> {
public:

    virtual T value();

    virtual void initWithValue(T value);

    virtual void dispose();

private:
    T _value;


};
template<typename T> using RestorableListenable = std::shared_ptr<RestorableListenableCls<T>>;

template<typename T> class RestorableChangeNotifierCls : public RestorableListenableCls<T> {
public:

    virtual void initWithValue(T value);

    virtual void dispose();

private:

    virtual void _disposeOldValue();

};
template<typename T> using RestorableChangeNotifier = std::shared_ptr<RestorableChangeNotifierCls<T>>;

class RestorableTextEditingControllerCls : public RestorableChangeNotifierCls<TextEditingController> {
public:

     RestorableTextEditingControllerCls(String text);

    virtual void  fromValue(TextEditingValue value);

    virtual TextEditingController createDefaultValue();

    virtual TextEditingController fromPrimitives(Object data);

    virtual Object toPrimitives();

private:
    TextEditingValue _initialValue;


};
using RestorableTextEditingController = std::shared_ptr<RestorableTextEditingControllerCls>;


#endif