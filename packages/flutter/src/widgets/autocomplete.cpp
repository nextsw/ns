#include "autocomplete.hpp"
RawAutocomplete::RawAutocomplete(AutocompleteOptionToString<T> displayStringForOption, AutocompleteFieldViewBuilder fieldViewBuilder, FocusNode focusNode, TextEditingValue initialValue, Unknown, AutocompleteOnSelected<T> onSelected, AutocompleteOptionsBuilder<T> optionsBuilder, AutocompleteOptionsViewBuilder<T> optionsViewBuilder, TextEditingController textEditingController) {
    {
        assert(displayStringForOption != nullptr);
        assert(fieldViewBuilder != nullptr || (key != nullptr && focusNode != nullptr && textEditingController != nullptr), "Pass in a fieldViewBuilder, or otherwise create a separate field and pass in the FocusNode, TextEditingController, and a key. Use the key with RawAutocomplete.onFieldSubmitted.");
        assert(optionsBuilder != nullptr);
        assert(optionsViewBuilder != nullptr);
        assert((focusNode == nullptr) == (textEditingController == nullptr));
        assert(!(textEditingController != nullptr && initialValue != nullptr), "textEditingController and initialValue cannot be simultaneously defined.");
    }
}

void RawAutocomplete::onFieldSubmitted<T extends Object>(GlobalKey key) {
    _RawAutocompleteState<T> rawAutocomplete = (;
    rawAutocomplete._onFieldSubmitted();
}

String RawAutocomplete::defaultStringForOption(dynamic option) {
    return option.toString();
}

State<RawAutocomplete<T>> RawAutocomplete::createState() {
    return <T>_RawAutocompleteState();
}

void _RawAutocompleteState::initState() {
    super.initState();
    _textEditingController = widget.textEditingController ?? TextEditingController.fromValue(widget.initialValue);
    _textEditingController.addListener(_onChangedField);
    _focusNode = widget.focusNode ?? FocusNode();
    _focusNode.addListener(_onChangedFocus);
    _previousOptionAction = <AutocompletePreviousOptionIntent>_AutocompleteCallbackAction(_highlightPreviousOption);
    _nextOptionAction = <AutocompleteNextOptionIntent>_AutocompleteCallbackAction(_highlightNextOption);
    _hideOptionsAction = <DismissIntent>_AutocompleteCallbackAction(_hideOptions);
    _actionMap = ;
    _updateActions();
    _updateOverlay();
}

void _RawAutocompleteState::didUpdateWidget(RawAutocomplete<T> oldWidget) {
    super.didUpdateWidget(oldWidget);
    _updateTextEditingController(oldWidget.textEditingController, widget.textEditingController);
    _updateFocusNode(oldWidget.focusNode, widget.focusNode);
    _updateActions();
    _updateOverlay();
}

void _RawAutocompleteState::dispose() {
    _textEditingController.removeListener(_onChangedField);
    if (widget.textEditingController == nullptr) {
        _textEditingController.dispose();
    }
    _focusNode.removeListener(_onChangedFocus);
    if (widget.focusNode == nullptr) {
        _focusNode.dispose();
    }
    _floatingOptions?.remove();
    _floatingOptions = nullptr;
    super.dispose();
}

Widget _RawAutocompleteState::build(BuildContext context) {
    return Container(_fieldKey, Shortcuts(_shortcuts, Actions(_actionMap, CompositedTransformTarget(_optionsLayerLink, widget.fieldViewBuilder == nullptr? const SizedBox.shrink() : widget.fieldViewBuilder!(context, _textEditingController, _focusNode, _onFieldSubmitted)))));
}

bool _RawAutocompleteState::_shouldShowOptions() {
    return !_userHidOptions && _focusNode.hasFocus && _selection == nullptr && _options.isNotEmpty;
}

Future<void> _RawAutocompleteState::_onChangedField() {
    TextEditingValue value = _textEditingController.value;
    Iterable<T> options = await widget.optionsBuilder(value);
    _options = options;
    _updateHighlight(_highlightedOptionIndex.value);
    if (_selection != nullptr && value.text != widget.displayStringForOption(_selection!)) {
        _selection = nullptr;
    }
    if (value.text != _lastFieldText) {
        _userHidOptions = false;
        _lastFieldText = value.text;
    }
    _updateActions();
    _updateOverlay();
}

void _RawAutocompleteState::_onChangedFocus() {
    _userHidOptions = !_focusNode.hasFocus;
    _updateActions();
    _updateOverlay();
}

void _RawAutocompleteState::_onFieldSubmitted() {
    if (_options.isEmpty || _userHidOptions) {
        return;
    }
    _select(_options.elementAt(_highlightedOptionIndex.value));
}

void _RawAutocompleteState::_select(T nextSelection) {
    if (nextSelection == _selection) {
        return;
    }
    _selection = nextSelection;
    String selectionString = widget.displayStringForOption(nextSelection);
    _textEditingController.value = TextEditingValue(TextSelection.collapsed(selectionString.length), selectionString);
    _updateActions();
    _updateOverlay();
    widget.onSelected?.call(_selection!);
}

void _RawAutocompleteState::_updateHighlight(int newIndex) {
    _highlightedOptionIndex.value = _options.isEmpty? 0 : newIndex % _options.length;
}

void _RawAutocompleteState::_highlightPreviousOption(AutocompletePreviousOptionIntent intent) {
    if (_userHidOptions) {
        _userHidOptions = false;
        _updateActions();
        _updateOverlay();
        return;
    }
    _updateHighlight(_highlightedOptionIndex.value - 1);
}

void _RawAutocompleteState::_highlightNextOption(AutocompleteNextOptionIntent intent) {
    if (_userHidOptions) {
        _userHidOptions = false;
        _updateActions();
        _updateOverlay();
        return;
    }
    _updateHighlight(_highlightedOptionIndex.value + 1);
}

Object _RawAutocompleteState::_hideOptions(DismissIntent intent) {
    if (!_userHidOptions) {
        _userHidOptions = true;
        _updateActions();
        _updateOverlay();
        return nullptr;
    }
    return Actions.invoke(context, intent);
}

void _RawAutocompleteState::_setActionsEnabled(bool enabled) {
    _previousOptionAction.enabled = enabled;
    _nextOptionAction.enabled = enabled;
    _hideOptionsAction.enabled = enabled;
}

void _RawAutocompleteState::_updateActions() {
    _setActionsEnabled(_focusNode.hasFocus && _selection == nullptr && _options.isNotEmpty);
}

void _RawAutocompleteState::_updateOverlay() {
    if (SchedulerBinding.instance.schedulerPhase == SchedulerPhase.persistentCallbacks) {
        if (!_floatingOptionsUpdateScheduled) {
            _floatingOptionsUpdateScheduled = true;
            SchedulerBinding.instance.addPostFrameCallback();
        }
        return;
    }
    _floatingOptions?.remove();
    if (_shouldShowOptions) {
        OverlayEntry newFloatingOptions = OverlayEntry();
        Overlay.of(contexttrue)!.insert(newFloatingOptions);
        _floatingOptions = newFloatingOptions;
    } else {
        _floatingOptions = nullptr;
    }
}

void _RawAutocompleteState::_updateTextEditingController(TextEditingController current, TextEditingController old) {
    if ((old == nullptr && current == nullptr) || old == current) {
        return;
    }
    if (old == nullptr) {
        _textEditingController.removeListener(_onChangedField);
        _textEditingController.dispose();
        _textEditingController = current!;
    } else     {
        if (current == nullptr) {
        _textEditingController.removeListener(_onChangedField);
        _textEditingController = TextEditingController();
    } else {
        _textEditingController.removeListener(_onChangedField);
        _textEditingController = current;
    }
;
    }    _textEditingController.addListener(_onChangedField);
}

void _RawAutocompleteState::_updateFocusNode(FocusNode current, FocusNode old) {
    if ((old == nullptr && current == nullptr) || old == current) {
        return;
    }
    if (old == nullptr) {
        _focusNode.removeListener(_onChangedFocus);
        _focusNode.dispose();
        _focusNode = current!;
    } else     {
        if (current == nullptr) {
        _focusNode.removeListener(_onChangedFocus);
        _focusNode = FocusNode();
    } else {
        _focusNode.removeListener(_onChangedFocus);
        _focusNode = current;
    }
;
    }    _focusNode.addListener(_onChangedFocus);
}

bool _AutocompleteCallbackAction::isEnabled(T intent) {
    return enabled;
}

bool _AutocompleteCallbackAction::consumesKey(T intent) {
    return enabled;
}

AutocompleteHighlightedOption::AutocompleteHighlightedOption(Unknown, ValueNotifier<int> highlightIndexNotifier, Unknown) {
    {
        super(highlightIndexNotifier);
    }
}

int AutocompleteHighlightedOption::of(BuildContext context) {
    return context.<AutocompleteHighlightedOption>dependOnInheritedWidgetOfExactType()?.notifier?.value ?? 0;
}
