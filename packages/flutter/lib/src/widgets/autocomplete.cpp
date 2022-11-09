#include "autocomplete.hpp"
template<typename T : Object> RawAutocompleteCls<T>::RawAutocompleteCls(AutocompleteOptionToString<T> displayStringForOption, AutocompleteFieldViewBuilder fieldViewBuilder, FocusNode focusNode, TextEditingValue initialValue, Unknown key, AutocompleteOnSelected<T> onSelected, AutocompleteOptionsBuilder<T> optionsBuilder, AutocompleteOptionsViewBuilder<T> optionsViewBuilder, TextEditingController textEditingController) {
    {
        assert(displayStringForOption != nullptr);
        assert(fieldViewBuilder != nullptr || (key != nullptr && focusNode != nullptr && textEditingController != nullptr), "Pass in a fieldViewBuilder, or otherwise create a separate field and pass in the FocusNode, TextEditingController, and a key. Use the key with RawAutocomplete.onFieldSubmitted.");
        assert(optionsBuilder != nullptr);
        assert(optionsViewBuilder != nullptr);
        assert((focusNode == nullptr) == (textEditingController == nullptr));
        assert(!(textEditingController != nullptr && initialValue != nullptr), "textEditingController and initialValue cannot be simultaneously defined.");
    }
}

template<typename T : Object> void RawAutocompleteCls<T>::onFieldSubmittedtemplate<typename T : Object> (GlobalKey key) {
    _RawAutocompleteState<T> rawAutocomplete = ((_RawAutocompleteState<T>)key->currentState!);
    rawAutocomplete->_onFieldSubmitted();
}

template<typename T : Object> String RawAutocompleteCls<T>::defaultStringForOption(dynamic option) {
    return option->toString();
}

template<typename T : Object> State<RawAutocomplete<T>> RawAutocompleteCls<T>::createState() {
    return <T>make<_RawAutocompleteStateCls>();
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::initState() {
    super->initState();
    _textEditingController = widget->textEditingController ?? TextEditingControllerCls->fromValue(widget->initialValue);
    _textEditingController->addListener(_onChangedField);
    _focusNode = widget->focusNode ?? make<FocusNodeCls>();
    _focusNode->addListener(_onChangedFocus);
    _previousOptionAction = <AutocompletePreviousOptionIntent>make<_AutocompleteCallbackActionCls>(_highlightPreviousOption);
    _nextOptionAction = <AutocompleteNextOptionIntent>make<_AutocompleteCallbackActionCls>(_highlightNextOption);
    _hideOptionsAction = <DismissIntent>make<_AutocompleteCallbackActionCls>(_hideOptions);
    Map<Type, Action<Intent>> map1 = make<MapCls<>>();map1.set(AutocompletePreviousOptionIntentCls, _previousOptionAction);map1.set(AutocompleteNextOptionIntentCls, _nextOptionAction);map1.set(DismissIntentCls, _hideOptionsAction);_actionMap = list1;
    _updateActions();
    _updateOverlay();
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::didUpdateWidget(RawAutocomplete<T> oldWidget) {
    super->didUpdateWidget(oldWidget);
    _updateTextEditingController(oldWidget->textEditingController, widget->textEditingController);
    _updateFocusNode(oldWidget->focusNode, widget->focusNode);
    _updateActions();
    _updateOverlay();
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::dispose() {
    _textEditingController->removeListener(_onChangedField);
    if (widget->textEditingController == nullptr) {
        _textEditingController->dispose();
    }
    _focusNode->removeListener(_onChangedFocus);
    if (widget->focusNode == nullptr) {
        _focusNode->dispose();
    }
    _floatingOptions?->remove();
    _floatingOptions = nullptr;
    super->dispose();
}

template<typename T : Object> Widget _RawAutocompleteStateCls<T>::build(BuildContext context) {
    return make<ContainerCls>(_fieldKey, make<ShortcutsCls>(_shortcuts, make<ActionsCls>(_actionMap, make<CompositedTransformTargetCls>(_optionsLayerLink, widget->fieldViewBuilder == nullptr? SizedBoxCls->shrink() : widget->fieldViewBuilder!(context, _textEditingController, _focusNode, _onFieldSubmitted)))));
}

template<typename T : Object> bool _RawAutocompleteStateCls<T>::_shouldShowOptions() {
    return !_userHidOptions && _focusNode->hasFocus && _selection == nullptr && _options->isNotEmpty;
}

template<typename T : Object> Future<void> _RawAutocompleteStateCls<T>::_onChangedField() {
    TextEditingValue value = _textEditingController->value;
    Iterable<T> options = await widget->optionsBuilder(value);
    _options = options;
    _updateHighlight(_highlightedOptionIndex->value);
    if (_selection != nullptr && value->text != widget->displayStringForOption(_selection!)) {
        _selection = nullptr;
    }
    if (value->text != _lastFieldText) {
        _userHidOptions = false;
        _lastFieldText = value->text;
    }
    _updateActions();
    _updateOverlay();
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::_onChangedFocus() {
    _userHidOptions = !_focusNode->hasFocus;
    _updateActions();
    _updateOverlay();
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::_onFieldSubmitted() {
    if (_options->isEmpty || _userHidOptions) {
        return;
    }
    _select(_options->elementAt(_highlightedOptionIndex->value));
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::_select(T nextSelection) {
    if (nextSelection == _selection) {
        return;
    }
    _selection = nextSelection;
    String selectionString = widget->displayStringForOption(nextSelection);
    _textEditingController->value = make<TextEditingValueCls>(TextSelectionCls->collapsed(selectionString->length), selectionString);
    _updateActions();
    _updateOverlay();
    widget->onSelected?->call(_selection!);
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::_updateHighlight(int newIndex) {
    _highlightedOptionIndex->value = _options->isEmpty? 0 : newIndex % _options->length;
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::_highlightPreviousOption(AutocompletePreviousOptionIntent intent) {
    if (_userHidOptions) {
        _userHidOptions = false;
        _updateActions();
        _updateOverlay();
        return;
    }
    _updateHighlight(_highlightedOptionIndex->value - 1);
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::_highlightNextOption(AutocompleteNextOptionIntent intent) {
    if (_userHidOptions) {
        _userHidOptions = false;
        _updateActions();
        _updateOverlay();
        return;
    }
    _updateHighlight(_highlightedOptionIndex->value + 1);
}

template<typename T : Object> Object _RawAutocompleteStateCls<T>::_hideOptions(DismissIntent intent) {
    if (!_userHidOptions) {
        _userHidOptions = true;
        _updateActions();
        _updateOverlay();
        return nullptr;
    }
    return ActionsCls->invoke(context, intent);
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::_setActionsEnabled(bool enabled) {
    _previousOptionAction->enabled = enabled;
    _nextOptionAction->enabled = enabled;
    _hideOptionsAction->enabled = enabled;
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::_updateActions() {
    _setActionsEnabled(_focusNode->hasFocus && _selection == nullptr && _options->isNotEmpty);
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::_updateOverlay() {
    if (SchedulerBindingCls::instance->schedulerPhase == SchedulerPhaseCls::persistentCallbacks) {
        if (!_floatingOptionsUpdateScheduled) {
            _floatingOptionsUpdateScheduled = true;
            SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
                _floatingOptionsUpdateScheduled = false;
                _updateOverlay();
            });
        }
        return;
    }
    _floatingOptions?->remove();
    if (_shouldShowOptions) {
        OverlayEntry newFloatingOptions = make<OverlayEntryCls>([=] (BuildContext context) {
    return make<CompositedTransformFollowerCls>(_optionsLayerLink, false, AlignmentCls::bottomLeft, make<AutocompleteHighlightedOptionCls>(_highlightedOptionIndex, make<BuilderCls>([=] (BuildContext context) {
        return widget->optionsViewBuilder(context, _select, _options);
    })));
});
        OverlayCls->of(contexttrue)!->insert(newFloatingOptions);
        _floatingOptions = newFloatingOptions;
    } else {
        _floatingOptions = nullptr;
    }
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::_updateTextEditingController(TextEditingController current, TextEditingController old) {
    if ((old == nullptr && current == nullptr) || old == current) {
        return;
    }
    if (old == nullptr) {
        _textEditingController->removeListener(_onChangedField);
        _textEditingController->dispose();
        _textEditingController = current!;
    } else     {
        if (current == nullptr) {
        _textEditingController->removeListener(_onChangedField);
        _textEditingController = make<TextEditingControllerCls>();
    } else {
        _textEditingController->removeListener(_onChangedField);
        _textEditingController = current;
    }
;
    }    _textEditingController->addListener(_onChangedField);
}

template<typename T : Object> void _RawAutocompleteStateCls<T>::_updateFocusNode(FocusNode current, FocusNode old) {
    if ((old == nullptr && current == nullptr) || old == current) {
        return;
    }
    if (old == nullptr) {
        _focusNode->removeListener(_onChangedFocus);
        _focusNode->dispose();
        _focusNode = current!;
    } else     {
        if (current == nullptr) {
        _focusNode->removeListener(_onChangedFocus);
        _focusNode = make<FocusNodeCls>();
    } else {
        _focusNode->removeListener(_onChangedFocus);
        _focusNode = current;
    }
;
    }    _focusNode->addListener(_onChangedFocus);
}

template<typename T : Intent> bool _AutocompleteCallbackActionCls<T>::isEnabled(T intent) {
    return enabled;
}

template<typename T : Intent> bool _AutocompleteCallbackActionCls<T>::consumesKey(T intent) {
    return enabled;
}

AutocompleteHighlightedOptionCls::AutocompleteHighlightedOptionCls(Unknown child, ValueNotifier<int> highlightIndexNotifier, Unknown key) {
}

int AutocompleteHighlightedOptionCls::of(BuildContext context) {
    return context-><AutocompleteHighlightedOption>dependOnInheritedWidgetOfExactType()?->notifier?->value ?? 0;
}
