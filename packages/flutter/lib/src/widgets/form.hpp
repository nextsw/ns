#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_FORM
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_FORM
#include <base.hpp>

#include <dart/core/core.hpp>
#include "framework.hpp"
#include "navigator.hpp"
#include "restoration.hpp"
#include "restoration_properties.hpp"
#include "will_pop_scope.hpp"


class FormCls : public StatefulWidgetCls {
public:
    Widget child;

    WillPopCallback onWillPop;

    VoidCallback onChanged;

    AutovalidateMode autovalidateMode;


     FormCls(AutovalidateMode autovalidateMode, Widget child, Unknown key, VoidCallback onChanged, WillPopCallback onWillPop);

    static FormState of(BuildContext context);

    virtual FormState createState();

private:

};
using Form = std::shared_ptr<FormCls>;

class FormStateCls : public StateCls<Form> {
public:

    virtual Widget build(BuildContext context);

    virtual void save();

    virtual void reset();

    virtual bool validate();

private:
    int _generation;

    bool _hasInteractedByUser;

    Set<FormFieldState<dynamic>> _fields;


    virtual void _fieldDidChange();

    virtual void _forceRebuild();

    virtual void _register(FormFieldState<dynamic> field);

    virtual void _unregister(FormFieldState<dynamic> field);

    virtual bool _validate();

};
using FormState = std::shared_ptr<FormStateCls>;

class _FormScopeCls : public InheritedWidgetCls {
public:

    virtual Form form();

    virtual bool updateShouldNotify(_FormScope old);

private:
    FormState _formState;

    int _generation;


     _FormScopeCls(Unknown child, FormState formState, int generation);

};
using _FormScope = std::shared_ptr<_FormScopeCls>;

template<typename T>
class FormFieldCls : public StatefulWidgetCls {
public:
    FormFieldSetter<T> onSaved;

    FormFieldValidator<T> validator;

    FormFieldBuilder<T> builder;

    T initialValue;

    bool enabled;

    AutovalidateMode autovalidateMode;

    String restorationId;


     FormFieldCls(AutovalidateMode autovalidateMode, FormFieldBuilder<T> builder, bool enabled, T initialValue, Unknown key, FormFieldSetter<T> onSaved, String restorationId, FormFieldValidator<T> validator);

    virtual FormFieldState<T> createState();

private:

};
template<typename T>
using FormField = std::shared_ptr<FormFieldCls<T>>;

template<typename T>
class FormFieldStateCls : public StateCls<FormField<T>> {
public:

    virtual T value();

    virtual String errorText();

    virtual bool hasError();

    virtual bool isValid();

    virtual void save();

    virtual void reset();

    virtual bool validate();

    virtual void didChange(T value);

    virtual void setValue(T value);

    virtual String restorationId();

    virtual void restoreState(RestorationBucket oldBucket, bool initialRestore);

    virtual void deactivate();

    virtual Widget build(BuildContext context);

private:
    T _value;

    RestorableStringN _errorText;

    RestorableBool _hasInteractedByUser;


    virtual void _validate();

};
template<typename T>
using FormFieldState = std::shared_ptr<FormFieldStateCls<T>>;

enum AutovalidateMode{
    disabled,
    always,
    onUserInteraction,
} // end AutovalidateMode


#endif