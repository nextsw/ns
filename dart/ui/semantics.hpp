#ifndef SEMANTICS_H
#define SEMANTICS_H
#include <memory>




class SemanticsAction {
public:
    int index;

    static const SemanticsAction tap;

    static const SemanticsAction longPress;

    static const SemanticsAction scrollLeft;

    static const SemanticsAction scrollRight;

    static const SemanticsAction scrollUp;

    static const SemanticsAction scrollDown;

    static const SemanticsAction increase;

    static const SemanticsAction decrease;

    static const SemanticsAction showOnScreen;

    static const SemanticsAction moveCursorForwardByCharacter;

    static const SemanticsAction moveCursorBackwardByCharacter;

    static const SemanticsAction setText;

    static const SemanticsAction setSelection;

    static const SemanticsAction copy;

    static const SemanticsAction cut;

    static const SemanticsAction paste;

    static const SemanticsAction didGainAccessibilityFocus;

    static const SemanticsAction didLoseAccessibilityFocus;

    static const SemanticsAction customAction;

    static const SemanticsAction dismiss;

    static const SemanticsAction moveCursorForwardByWord;

    static const SemanticsAction moveCursorBackwardByWord;

    static const Map<int, SemanticsAction> values;


    String toString();

private:
    static const int _kTapIndex;

    static const int _kLongPressIndex;

    static const int _kScrollLeftIndex;

    static const int _kScrollRightIndex;

    static const int _kScrollUpIndex;

    static const int _kScrollDownIndex;

    static const int _kIncreaseIndex;

    static const int _kDecreaseIndex;

    static const int _kShowOnScreenIndex;

    static const int _kMoveCursorForwardByCharacterIndex;

    static const int _kMoveCursorBackwardByCharacterIndex;

    static const int _kSetSelectionIndex;

    static const int _kCopyIndex;

    static const int _kCutIndex;

    static const int _kPasteIndex;

    static const int _kDidGainAccessibilityFocusIndex;

    static const int _kDidLoseAccessibilityFocusIndex;

    static const int _kCustomActionIndex;

    static const int _kDismissIndex;

    static const int _kMoveCursorForwardByWordIndex;

    static const int _kMoveCursorBackwardByWordIndex;

    static const int _kSetTextIndex;


    void  _(int index);

};

class SemanticsFlag {
public:
    int index;

    static const SemanticsFlag hasCheckedState;

    static const SemanticsFlag isChecked;

    static const SemanticsFlag isSelected;

    static const SemanticsFlag isButton;

    static const SemanticsFlag isTextField;

    static const SemanticsFlag isSlider;

    static const SemanticsFlag isKeyboardKey;

    static const SemanticsFlag isReadOnly;

    static const SemanticsFlag isLink;

    static const SemanticsFlag isFocusable;

    static const SemanticsFlag isFocused;

    static const SemanticsFlag hasEnabledState;

    static const SemanticsFlag isEnabled;

    static const SemanticsFlag isInMutuallyExclusiveGroup;

    static const SemanticsFlag isHeader;

    static const SemanticsFlag isObscured;

    static const SemanticsFlag isMultiline;

    static const SemanticsFlag scopesRoute;

    static const SemanticsFlag namesRoute;

    static const SemanticsFlag isHidden;

    static const SemanticsFlag isImage;

    static const SemanticsFlag isLiveRegion;

    static const SemanticsFlag hasToggledState;

    static const SemanticsFlag isToggled;

    static const SemanticsFlag hasImplicitScrolling;

    static const Map<int, SemanticsFlag> values;


    String toString();

private:
    static const int _kHasCheckedStateIndex;

    static const int _kIsCheckedIndex;

    static const int _kIsSelectedIndex;

    static const int _kIsButtonIndex;

    static const int _kIsTextFieldIndex;

    static const int _kIsFocusedIndex;

    static const int _kHasEnabledStateIndex;

    static const int _kIsEnabledIndex;

    static const int _kIsInMutuallyExclusiveGroupIndex;

    static const int _kIsHeaderIndex;

    static const int _kIsObscuredIndex;

    static const int _kScopesRouteIndex;

    static const int _kNamesRouteIndex;

    static const int _kIsHiddenIndex;

    static const int _kIsImageIndex;

    static const int _kIsLiveRegionIndex;

    static const int _kHasToggledStateIndex;

    static const int _kIsToggledIndex;

    static const int _kHasImplicitScrollingIndex;

    static const int _kIsMultilineIndex;

    static const int _kIsReadOnlyIndex;

    static const int _kIsFocusableIndex;

    static const int _kIsLinkIndex;

    static const int _kIsSliderIndex;

    static const int _kIsKeyboardKeyIndex;


    void  _(int index);

};

class StringAttribute : NativeFieldWrapperClass1 {
public:
    TextRange range;


    StringAttribute copy(TextRange range);

private:

    void  _(TextRange range);

};

class SpellOutStringAttribute : StringAttribute {
public:

     SpellOutStringAttribute(TextRange range);

    StringAttribute copy(TextRange range);

    String toString();

private:

    void _initSpellOutStringAttribute(int end, SpellOutStringAttribute instance, int start);

};

class LocaleStringAttribute : StringAttribute {
public:
    Locale locale;


     LocaleStringAttribute(Locale locale, TextRange range);

    StringAttribute copy(TextRange range);

    String toString();

private:

    void _initLocaleStringAttribute(int end, LocaleStringAttribute instance, String locale, int start);

};

class SemanticsUpdateBuilder : NativeFieldWrapperClass1 {
public:

     SemanticsUpdateBuilder();

    void updateNode(int actions, Int32List additionalActions, Int32List childrenInHitTestOrder, Int32List childrenInTraversalOrder, int currentValueLength, String decreasedValue, List<StringAttribute> decreasedValueAttributes, double elevation, int flags, String hint, List<StringAttribute> hintAttributes, int id, String increasedValue, List<StringAttribute> increasedValueAttributes, String label, List<StringAttribute> labelAttributes, int maxValueLength, int platformViewId, Rect rect, int scrollChildren, double scrollExtentMax, double scrollExtentMin, int scrollIndex, double scrollPosition, TextDirection textDirection, int textSelectionBase, int textSelectionExtent, double thickness, String tooltip, Float64List transform, String value, List<StringAttribute> valueAttributes);

    void updateCustomAction(String hint, int id, String label, int overrideId);

    SemanticsUpdate build();

private:

    void _constructor();

    void _updateNode(int actions, Int32List additionalActions, double bottom, Int32List childrenInHitTestOrder, Int32List childrenInTraversalOrder, int currentValueLength, String decreasedValue, List<StringAttribute> decreasedValueAttributes, double elevation, int flags, String hint, List<StringAttribute> hintAttributes, int id, String increasedValue, List<StringAttribute> increasedValueAttributes, String label, List<StringAttribute> labelAttributes, double left, int maxValueLength, int platformViewId, double right, int scrollChildren, double scrollExtentMax, double scrollExtentMin, int scrollIndex, double scrollPosition, int textDirection, int textSelectionBase, int textSelectionExtent, double thickness, String tooltip, double top, Float64List transform, String value, List<StringAttribute> valueAttributes);

    void _updateCustomAction(String hint, int id, String label, int overrideId);

    void _build(SemanticsUpdate outSemanticsUpdate);

};

class SemanticsUpdate : NativeFieldWrapperClass1 {
public:

    void dispose();

private:

    void  _();

};

#endif