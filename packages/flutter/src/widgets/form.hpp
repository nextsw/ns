#ifndef FORM_H
#define FORM_H
#include <memory>

#include "framework.hpp"
#include "navigator.hpp"
#include "restoration.hpp"
#include "restoration_properties.hpp"
#include "will_pop_scope.hpp"



class Form : StatefulWidget {
public:
    Widget child;

    WillPopCallback onWillPop;

    VoidCallback onChanged;

    AutovalidateMode autovalidateMode;


     Form(AutovalidateMode autovalidateMode, Widget child, Unknown, VoidCallback onChanged, WillPopCallback onWillPop);

    static FormState of(BuildContext context);

    FormState createState();

private:

};

class FormState : State<Form> {
public:

    Widget build(BuildContext context);

    void save();

    void reset();

    bool validate();

private:
    int _generation;

    bool _hasInteractedByUser;

    Set<FormFieldState<dynamic>> _fields;


    void _fieldDidChange();

    void _forceRebuild();

    void _register(FormFieldState<dynamic> field);

    void _unregister(FormFieldState<dynamic> field);

    bool _validate();

};

class _FormScope : InheritedWidget {
public:

    Form form();

    bool updateShouldNotify(_FormScope old);

private:
    FormState _formState;

    int _generation;


     _FormScope(Unknown, FormState formState, int generation);

};

class FormField<T> : StatefulWidget {
public:
    FormFieldSetter<T> onSaved;

    FormFieldValidator<T> validator;

    FormFieldBuilder<T> builder;

    T initialValue;

    bool enabled;

    AutovalidateMode autovalidateMode;

    String restorationId;


     FormField(AutovalidateMode autovalidateMode, FormFieldBuilder<T> builder, bool enabled, T initialValue, Unknown, FormFieldSetter<T> onSaved, String restorationId, FormFieldValidator<T> validator);

    FormFieldState<T> createState();

private:

};

class FormFieldState<T> : State<FormField<T>> {
public:

    T value();

    String errorText();

    bool hasError();

    bool isValid();

    void save();

    void reset();

    bool validate();

    void didChange(T value);

    void setValue(T value);

    String restorationId();

    void restoreState(bool initialRestore, RestorationBucket oldBucket);

    void deactivate();

    Widget build(BuildContext context);

private:
    T _value;

    RestorableStringN _errorText;

    RestorableBool _hasInteractedByUser;


    void _validate();

};

enum AutovalidateMode{
    disabled,
    always,
    onUserInteraction,
} // end AutovalidateMode

#endif