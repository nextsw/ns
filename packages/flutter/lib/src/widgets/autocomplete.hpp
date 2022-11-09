#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_AUTOCOMPLETE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_AUTOCOMPLETE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "actions.hpp"
#include "basic.hpp"
#include "container.hpp"
#include "editable_text.hpp"
#include "focus_manager.hpp"
#include "framework.hpp"
#include "inherited_notifier.hpp"
#include "overlay.hpp"
#include "shortcuts.hpp"


template<typename T : Object> class RawAutocompleteCls : public StatefulWidgetCls {
public:
    AutocompleteFieldViewBuilder fieldViewBuilder;

    FocusNode focusNode;

    AutocompleteOptionsViewBuilder<T> optionsViewBuilder;

    AutocompleteOptionToString<T> displayStringForOption;

    AutocompleteOnSelected<T> onSelected;

    AutocompleteOptionsBuilder<T> optionsBuilder;

    TextEditingController textEditingController;

    TextEditingValue initialValue;


     RawAutocompleteCls(AutocompleteOptionToString<T> displayStringForOption, AutocompleteFieldViewBuilder fieldViewBuilder, FocusNode focusNode, TextEditingValue initialValue, Unknown key, AutocompleteOnSelected<T> onSelected, AutocompleteOptionsBuilder<T> optionsBuilder, AutocompleteOptionsViewBuilder<T> optionsViewBuilder, TextEditingController textEditingController);

    template<typename T : Object>  static void onFieldSubmitted(GlobalKey key);

    static String defaultStringForOption(dynamic option);

    virtual State<RawAutocomplete<T>> createState();

private:

};
template<typename T : Object> using RawAutocomplete = std::shared_ptr<RawAutocompleteCls<T : Object>>;

template<typename T : Object> class _RawAutocompleteStateCls : public StateCls<RawAutocomplete<T>> {
public:

    virtual void initState();

    virtual void didUpdateWidget(RawAutocomplete<T> oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

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

    static Map<ShortcutActivator, Intent> _shortcuts;

    OverlayEntry _floatingOptions;

    bool _floatingOptionsUpdateScheduled;


    virtual bool _shouldShowOptions();

    virtual Future<void> _onChangedField();

    virtual void _onChangedFocus();

    virtual void _onFieldSubmitted();

    virtual void _select(T nextSelection);

    virtual void _updateHighlight(int newIndex);

    virtual void _highlightPreviousOption(AutocompletePreviousOptionIntent intent);

    virtual void _highlightNextOption(AutocompleteNextOptionIntent intent);

    virtual Object _hideOptions(DismissIntent intent);

    virtual void _setActionsEnabled(bool enabled);

    virtual void _updateActions();

    virtual void _updateOverlay();

    virtual void _updateTextEditingController(TextEditingController current, TextEditingController old);

    virtual void _updateFocusNode(FocusNode current, FocusNode old);

};
template<typename T : Object> using _RawAutocompleteState = std::shared_ptr<_RawAutocompleteStateCls<T : Object>>;

template<typename T : Intent> class _AutocompleteCallbackActionCls : public CallbackActionCls<T> {
public:
    bool enabled;


    virtual bool isEnabled(T intent);

    virtual bool consumesKey(T intent);

private:

     _AutocompleteCallbackActionCls(bool enabled, Unknown onInvoke);
};
template<typename T : Intent> using _AutocompleteCallbackAction = std::shared_ptr<_AutocompleteCallbackActionCls<T : Intent>>;

class AutocompletePreviousOptionIntentCls : public IntentCls {
public:

     AutocompletePreviousOptionIntentCls();
private:

};
using AutocompletePreviousOptionIntent = std::shared_ptr<AutocompletePreviousOptionIntentCls>;

class AutocompleteNextOptionIntentCls : public IntentCls {
public:

     AutocompleteNextOptionIntentCls();
private:

};
using AutocompleteNextOptionIntent = std::shared_ptr<AutocompleteNextOptionIntentCls>;

class AutocompleteHighlightedOptionCls : public InheritedNotifierCls<ValueNotifier<int>> {
public:

     AutocompleteHighlightedOptionCls(Unknown child, ValueNotifier<int> highlightIndexNotifier, Unknown key);

    static int of(BuildContext context);

private:

};
using AutocompleteHighlightedOption = std::shared_ptr<AutocompleteHighlightedOptionCls>;


#endif