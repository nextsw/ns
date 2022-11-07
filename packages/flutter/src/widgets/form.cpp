#include "form.hpp"
Form::Form(AutovalidateMode autovalidateMode, Widget child, Unknown, VoidCallback onChanged, WillPopCallback onWillPop) {
    {
        assert(child != nullptr);
        autovalidateMode = autovalidateMode ?? AutovalidateMode.disabled;
    }
}

FormState Form::of(BuildContext context) {
    _FormScope scope = context.<_FormScope>dependOnInheritedWidgetOfExactType();
    return scope?._formState;
}

FormState Form::createState() {
    return FormState();
}

Widget FormState::build(BuildContext context) {
    ;
    return WillPopScope(widget.onWillPop, _FormScope(this, _generation, widget.child));
}

void FormState::save() {
    for (FormFieldState<dynamic> field : _fields) {
        field.save();
    }
}

void FormState::reset() {
    for (FormFieldState<dynamic> field : _fields) {
        field.reset();
    }
    _hasInteractedByUser = false;
    _fieldDidChange();
}

bool FormState::validate() {
    _hasInteractedByUser = true;
    _forceRebuild();
    return _validate();
}

void FormState::_fieldDidChange() {
    widget.onChanged?.call();
    _hasInteractedByUser = _fields.any();
    _forceRebuild();
}

void FormState::_forceRebuild() {
    setState();
}

void FormState::_register(FormFieldState<dynamic> field) {
    _fields.add(field);
}

void FormState::_unregister(FormFieldState<dynamic> field) {
    _fields.remove(field);
}

bool FormState::_validate() {
    bool hasError = false;
    for (FormFieldState<dynamic> field : _fields) {
        hasError = !field.validate() || hasError;
    }
    return !hasError;
}

Form _FormScope::form() {
    return _formState.widget;
}

bool _FormScope::updateShouldNotify(_FormScope old) {
    return _generation != old._generation;
}

_FormScope::_FormScope(Unknown, FormState formState, int generation) {
    {
        _formState = formState;
        _generation = generation;
    }
}

FormField::FormField(AutovalidateMode autovalidateMode, FormFieldBuilder<T> builder, bool enabled, T initialValue, Unknown, FormFieldSetter<T> onSaved, String restorationId, FormFieldValidator<T> validator) {
    {
        assert(builder != nullptr);
        autovalidateMode = autovalidateMode ?? AutovalidateMode.disabled;
    }
}

FormFieldState<T> FormField::createState() {
    return <T>FormFieldState();
}

T FormFieldState::value() {
    return _value;
}

String FormFieldState::errorText() {
    return _errorText.value;
}

bool FormFieldState::hasError() {
    return _errorText.value != nullptr;
}

bool FormFieldState::isValid() {
    return widget.validator?.call(_value) == nullptr;
}

void FormFieldState::save() {
    widget.onSaved?.call(value);
}

void FormFieldState::reset() {
    setState();
    Form.of(context)?._fieldDidChange();
}

bool FormFieldState::validate() {
    setState();
    return !hasError;
}

void FormFieldState::didChange(T value) {
    setState();
    Form.of(context)?._fieldDidChange();
}

void FormFieldState::setValue(T value) {
    _value = value;
}

String FormFieldState::restorationId() {
    return widget.restorationId;
}

void FormFieldState::restoreState(bool initialRestore, RestorationBucket oldBucket) {
    registerForRestoration(_errorText, "error_text");
    registerForRestoration(_hasInteractedByUser, "has_interacted_by_user");
}

void FormFieldState::deactivate() {
    Form.of(context)?._unregister(this);
    super.deactivate();
}

Widget FormFieldState::build(BuildContext context) {
    if (widget.enabled) {
        ;
    }
    Form.of(context)?._register(this);
    return widget.builder(this);
}

void FormFieldState::_validate() {
    if (widget.validator != nullptr) {
        _errorText.value = widget.validator!(_value);
    }
}
