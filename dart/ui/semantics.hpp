#ifndef DART_UI_SEMANTICS
#define DART_UI_SEMANTICS
#include <base.hpp>

#include <dart/core/core.hpp>


class SemanticsActionCls : public ObjectCls {
public:
    int index;

    static SemanticsAction tap;

    static SemanticsAction longPress;

    static SemanticsAction scrollLeft;

    static SemanticsAction scrollRight;

    static SemanticsAction scrollUp;

    static SemanticsAction scrollDown;

    static SemanticsAction increase;

    static SemanticsAction decrease;

    static SemanticsAction showOnScreen;

    static SemanticsAction moveCursorForwardByCharacter;

    static SemanticsAction moveCursorBackwardByCharacter;

    static SemanticsAction setText;

    static SemanticsAction setSelection;

    static SemanticsAction copy;

    static SemanticsAction cut;

    static SemanticsAction paste;

    static SemanticsAction didGainAccessibilityFocus;

    static SemanticsAction didLoseAccessibilityFocus;

    static SemanticsAction customAction;

    static SemanticsAction dismiss;

    static SemanticsAction moveCursorForwardByWord;

    static SemanticsAction moveCursorBackwardByWord;

    static Map<int, SemanticsAction> values;


    virtual String toString();

private:
    static int _kTapIndex;

    static int _kLongPressIndex;

    static int _kScrollLeftIndex;

    static int _kScrollRightIndex;

    static int _kScrollUpIndex;

    static int _kScrollDownIndex;

    static int _kIncreaseIndex;

    static int _kDecreaseIndex;

    static int _kShowOnScreenIndex;

    static int _kMoveCursorForwardByCharacterIndex;

    static int _kMoveCursorBackwardByCharacterIndex;

    static int _kSetSelectionIndex;

    static int _kCopyIndex;

    static int _kCutIndex;

    static int _kPasteIndex;

    static int _kDidGainAccessibilityFocusIndex;

    static int _kDidLoseAccessibilityFocusIndex;

    static int _kCustomActionIndex;

    static int _kDismissIndex;

    static int _kMoveCursorForwardByWordIndex;

    static int _kMoveCursorBackwardByWordIndex;

    static int _kSetTextIndex;


    virtual void  _(int index);

};
using SemanticsAction = std::shared_ptr<SemanticsActionCls>;

class SemanticsFlagCls : public ObjectCls {
public:
    int index;

    static SemanticsFlag hasCheckedState;

    static SemanticsFlag isChecked;

    static SemanticsFlag isSelected;

    static SemanticsFlag isButton;

    static SemanticsFlag isTextField;

    static SemanticsFlag isSlider;

    static SemanticsFlag isKeyboardKey;

    static SemanticsFlag isReadOnly;

    static SemanticsFlag isLink;

    static SemanticsFlag isFocusable;

    static SemanticsFlag isFocused;

    static SemanticsFlag hasEnabledState;

    static SemanticsFlag isEnabled;

    static SemanticsFlag isInMutuallyExclusiveGroup;

    static SemanticsFlag isHeader;

    static SemanticsFlag isObscured;

    static SemanticsFlag isMultiline;

    static SemanticsFlag scopesRoute;

    static SemanticsFlag namesRoute;

    static SemanticsFlag isHidden;

    static SemanticsFlag isImage;

    static SemanticsFlag isLiveRegion;

    static SemanticsFlag hasToggledState;

    static SemanticsFlag isToggled;

    static SemanticsFlag hasImplicitScrolling;

    static Map<int, SemanticsFlag> values;


    virtual String toString();

private:
    static int _kHasCheckedStateIndex;

    static int _kIsCheckedIndex;

    static int _kIsSelectedIndex;

    static int _kIsButtonIndex;

    static int _kIsTextFieldIndex;

    static int _kIsFocusedIndex;

    static int _kHasEnabledStateIndex;

    static int _kIsEnabledIndex;

    static int _kIsInMutuallyExclusiveGroupIndex;

    static int _kIsHeaderIndex;

    static int _kIsObscuredIndex;

    static int _kScopesRouteIndex;

    static int _kNamesRouteIndex;

    static int _kIsHiddenIndex;

    static int _kIsImageIndex;

    static int _kIsLiveRegionIndex;

    static int _kHasToggledStateIndex;

    static int _kIsToggledIndex;

    static int _kHasImplicitScrollingIndex;

    static int _kIsMultilineIndex;

    static int _kIsReadOnlyIndex;

    static int _kIsFocusableIndex;

    static int _kIsLinkIndex;

    static int _kIsSliderIndex;

    static int _kIsKeyboardKeyIndex;


    virtual void  _(int index);

};
using SemanticsFlag = std::shared_ptr<SemanticsFlagCls>;

class StringAttributeCls : public NativeFieldWrapperClass1Cls {
public:
    TextRange range;


    virtual StringAttribute copy(TextRange range);
private:

    virtual void  _(TextRange range);
};
using StringAttribute = std::shared_ptr<StringAttributeCls>;

class SpellOutStringAttributeCls : public StringAttributeCls {
public:

     SpellOutStringAttributeCls(TextRange range);

    virtual StringAttribute copy(TextRange range);

    virtual String toString();

private:

    virtual void _initSpellOutStringAttribute(SpellOutStringAttribute instance, int start, int end);
};
using SpellOutStringAttribute = std::shared_ptr<SpellOutStringAttributeCls>;

class LocaleStringAttributeCls : public StringAttributeCls {
public:
    Locale locale;


     LocaleStringAttributeCls(Locale locale, TextRange range);

    virtual StringAttribute copy(TextRange range);

    virtual String toString();

private:

    virtual void _initLocaleStringAttribute(LocaleStringAttribute instance, int start, int end, String locale);
};
using LocaleStringAttribute = std::shared_ptr<LocaleStringAttributeCls>;

class SemanticsUpdateBuilderCls : public NativeFieldWrapperClass1Cls {
public:

     SemanticsUpdateBuilderCls();

    virtual void updateNode(int actions, Int32List additionalActions, Int32List childrenInHitTestOrder, Int32List childrenInTraversalOrder, int currentValueLength, String decreasedValue, List<StringAttribute> decreasedValueAttributes, double elevation, int flags, String hint, List<StringAttribute> hintAttributes, int id, String increasedValue, List<StringAttribute> increasedValueAttributes, String label, List<StringAttribute> labelAttributes, int maxValueLength, int platformViewId, Rect rect, int scrollChildren, double scrollExtentMax, double scrollExtentMin, int scrollIndex, double scrollPosition, TextDirection textDirection, int textSelectionBase, int textSelectionExtent, double thickness, String tooltip, Float64List transform, String value, List<StringAttribute> valueAttributes);

    virtual void updateCustomAction(String hint, int id, String label, int overrideId);

    virtual SemanticsUpdate build();

private:

    virtual void _constructor();
    virtual void _updateNode(int id, int flags, int actions, int maxValueLength, int currentValueLength, int textSelectionBase, int textSelectionExtent, int platformViewId, int scrollChildren, int scrollIndex, double scrollPosition, double scrollExtentMax, double scrollExtentMin, double left, double top, double right, double bottom, double elevation, double thickness, String label, List<StringAttribute> labelAttributes, String value, List<StringAttribute> valueAttributes, String increasedValue, List<StringAttribute> increasedValueAttributes, String decreasedValue, List<StringAttribute> decreasedValueAttributes, String hint, List<StringAttribute> hintAttributes, String tooltip, int textDirection, Float64List transform, Int32List childrenInTraversalOrder, Int32List childrenInHitTestOrder, Int32List additionalActions);
    virtual void _updateCustomAction(int id, String label, String hint, int overrideId);
    virtual void _build(SemanticsUpdate outSemanticsUpdate);
};
using SemanticsUpdateBuilder = std::shared_ptr<SemanticsUpdateBuilderCls>;

class SemanticsUpdateCls : public NativeFieldWrapperClass1Cls {
public:

    virtual void dispose();
private:

    virtual void  _();
};
using SemanticsUpdate = std::shared_ptr<SemanticsUpdateCls>;


#endif