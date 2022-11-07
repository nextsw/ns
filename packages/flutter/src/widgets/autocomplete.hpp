#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H
#include <memory>

#include <async/async.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/services.hpp>
#include "actions.hpp"
#include "basic.hpp"
#include "container.hpp"
#include "editable_text.hpp"
#include "focus_manager.hpp"
#include "framework.hpp"
#include "inherited_notifier.hpp"
#include "overlay.hpp"
#include "shortcuts.hpp"



class RawAutocomplete<T extends Object> : StatefulWidget {
public:
    AutocompleteFieldViewBuilder fieldViewBuilder;

    FocusNode focusNode;

    AutocompleteOptionsViewBuilder<T> optionsViewBuilder;

    AutocompleteOptionToString<T> displayStringForOption;

    AutocompleteOnSelected<T> onSelected;

    AutocompleteOptionsBuilder<T> optionsBuilder;

    TextEditingController textEditingController;

    TextEditingValue initialValue;


     RawAutocomplete(AutocompleteOptionToString<T> displayStringForOption, AutocompleteFieldViewBuilder fieldViewBuilder, FocusNode focusNode, TextEditingValue initialValue, Unknown, AutocompleteOnSelected<T> onSelected, AutocompleteOptionsBuilder<T> optionsBuilder, AutocompleteOptionsViewBuilder<T> optionsViewBuilder, TextEditingController textEditingController);

    static void onFieldSubmitted<T extends Object>(GlobalKey key);

    static String defaultStringForOption(dynamic option);

    State<RawAutocomplete<T>> createState();

private:

};

class _RawAutocompleteState<T extends Object> : State<RawAutocomplete<T>> {
public:

    void initState();

    void didUpdateWidget(RawAutocomplete<T> oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    GlobalKey _fieldKey;

    LayerLink _optionsLayerLink;

    TextEditingController _textEditingController;

    FocusNode _focusNode;

    Map<Type, Action<Intent>> _actionMap;

    _AutocompleteCallbackAction<AutocompletePreviousOptionIntent> _previousOptionAction;

    _AutocompleteCallbackAction<AutocompleteNextOptionIntent> _nextOptionAction;

    _AutocompleteCallbackAction<DismissIntent> _hideOptionsAction;

    Iterable<T> _options;

    T _selection;

    bool _userHidOptions;

    String _lastFieldText;

    ValueNotifier<int> _highlightedOptionIndex;

    static const Map<ShortcutActivator, Intent> _shortcuts;

    OverlayEntry _floatingOptions;

    bool _floatingOptionsUpdateScheduled;


    bool _shouldShowOptions();

    Future<void> _onChangedField();

    void _onChangedFocus();

    void _onFieldSubmitted();

    void _select(T nextSelection);

    void _updateHighlight(int newIndex);

    void _highlightPreviousOption(AutocompletePreviousOptionIntent intent);

    void _highlightNextOption(AutocompleteNextOptionIntent intent);

    Object _hideOptions(DismissIntent intent);

    void _setActionsEnabled(bool enabled);

    void _updateActions();

    void _updateOverlay();

    void _updateTextEditingController(TextEditingController current, TextEditingController old);

    void _updateFocusNode(FocusNode current, FocusNode old);

};

class _AutocompleteCallbackAction<T extends Intent> : CallbackAction<T> {
public:
    bool enabled;


    bool isEnabled(T intent);

    bool consumesKey(T intent);

private:

     _AutocompleteCallbackAction(bool enabled, Unknown);

};

class AutocompletePreviousOptionIntent : Intent {
public:

     AutocompletePreviousOptionIntent();

private:

};

class AutocompleteNextOptionIntent : Intent {
public:

     AutocompleteNextOptionIntent();

private:

};

class AutocompleteHighlightedOption : InheritedNotifier<ValueNotifier<int>> {
public:

     AutocompleteHighlightedOption(Unknown, ValueNotifier<int> highlightIndexNotifier, Unknown);

    static int of(BuildContext context);

private:

};

#endif