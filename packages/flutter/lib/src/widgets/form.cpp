#include "form.hpp"
FormCls::FormCls(AutovalidateMode autovalidateMode, Widget child, Unknown key, VoidCallback onChanged, WillPopCallback onWillPop) {
    {
        assert(child != nullptr);
        autovalidateMode = autovalidateMode or AutovalidateModeCls::disabled;
    }
}

FormState FormCls::of(BuildContext context) {
    _FormScope scope = context-><_FormScope>dependOnInheritedWidgetOfExactType();
    return scope?->_formState;
}

FormState FormCls::createState() {
    return make<FormStateCls>();
}

Widget FormStateCls::build(BuildContext context) {
    ;
    return make<WillPopScopeCls>(widget->onWillPop, make<_FormScopeCls>(this, _generation, widget->child));
}

void FormStateCls::save() {
    for (FormFieldState<dynamic> field : _fields) {
        field->save();
    }
}

void FormStateCls::reset() {
    for (FormFieldState<dynamic> field : _fields) {
        field->reset();
    }
    _hasInteractedByUser = false;
    _fieldDidChange();
}

bool FormStateCls::validate() {
    _hasInteractedByUser = true;
    _forceRebuild();
    return _validate();
}

void FormStateCls::_fieldDidChange() {
    widget->onChanged?->call();
    _hasInteractedByUser = _fields->any([=] (FormFieldState<dynamic> field)     {
        field->_hasInteractedByUser->value;
    });
    _forceRebuild();
}

void FormStateCls::_forceRebuild() {
    setState([=] () {
        ++_generation;
    });
}

void FormStateCls::_register(FormFieldState<dynamic> field) {
    _fields->add(field);
}

void FormStateCls::_unregister(FormFieldState<dynamic> field) {
    _fields->remove(field);
}

bool FormStateCls::_validate() {
    bool hasError = false;
    for (FormFieldState<dynamic> field : _fields) {
        hasError = !field->validate() || hasError;
    }
    return !hasError;
}

Form _FormScopeCls::form() {
    return _formState->widget;
}

bool _FormScopeCls::updateShouldNotify(_FormScope old) {
    return _generation != old->_generation;
}

_FormScopeCls::_FormScopeCls(Unknown child, FormState formState, int generation) {
    {
        _formState = formState;
        _generation = generation;
    }
}

template<typename T> FormFieldCls<T>::FormFieldCls(AutovalidateMode autovalidateMode, FormFieldBuilder<T> builder, bool enabled, T initialValue, Unknown key, FormFieldSetter<T> onSaved, String restorationId, FormFieldValidator<T> validator) {
    {
        assert(builder != nullptr);
        autovalidateMode = autovalidateMode or AutovalidateModeCls::disabled;
    }
}

template<typename T> FormFieldState<T> FormFieldCls<T>::createState() {
    return <T>make<FormFieldStateCls>();
}

template<typename T> T FormFieldStateCls<T>::value() {
    return _value;
}

template<typename T> String FormFieldStateCls<T>::errorText() {
    return _errorText->value;
}

template<typename T> bool FormFieldStateCls<T>::hasError() {
    return _errorText->value != nullptr;
}

template<typename T> bool FormFieldStateCls<T>::isValid() {
    return widget->validator?->call(_value) == nullptr;
}

template<typename T> void FormFieldStateCls<T>::save() {
    widget->onSaved?->call(value());
}

template<typename T> void FormFieldStateCls<T>::reset() {
    setState([=] () {
        _value = widget->initialValue;
        _hasInteractedByUser->value = false;
        _errorText->value = nullptr;
    });
    FormCls->of(context)?->_fieldDidChange();
}

template<typename T> bool FormFieldStateCls<T>::validate() {
    setState([=] () {
        _validate();
    });
    return !hasError();
}

template<typename T> void FormFieldStateCls<T>::didChange(T value) {
    setState([=] () {
        _value = value();
        _hasInteractedByUser->value = true;
    });
    FormCls->of(context)?->_fieldDidChange();
}

template<typename T> void FormFieldStateCls<T>::setValue(T value) {
    _value = value();
}

template<typename T> String FormFieldStateCls<T>::restorationId() {
    return widget->restorationId;
}

template<typename T> void FormFieldStateCls<T>::restoreState(bool initialRestore, RestorationBucket oldBucket) {
    registerForRestoration(_errorText, __s("error_text"));
    registerForRestoration(_hasInteractedByUser, __s("has_interacted_by_user"));
}

template<typename T> void FormFieldStateCls<T>::deactivate() {
    FormCls->of(context)?->_unregister(this);
    super->deactivate();
}

template<typename T> Widget FormFieldStateCls<T>::build(BuildContext context) {
    if (widget->enabled) {
        ;
    }
    FormCls->of(context)?->_register(this);
    return widget->builder(this);
}

template<typename T> void FormFieldStateCls<T>::_validate() {
    if (widget->validator != nullptr) {
        _errorText->value = widget->validator!(_value);
    }
}
