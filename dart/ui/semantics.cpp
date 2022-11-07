#include "semantics.hpp"
String SemanticsAction::toString() {
    ;
    assert(false, "Unhandled index: $index (0x${index.toRadixString(8).padLeft(4, "0")})");
    return "";
}

void SemanticsAction::_(int index)

String SemanticsFlag::toString() {
    ;
    assert(false, "Unhandled index: $index (0x${index.toRadixString(8).padLeft(4, "0")})");
    return "";
}

void SemanticsFlag::_(int index)

SpellOutStringAttribute::SpellOutStringAttribute(TextRange range) {
    {
        super._(range);
    }
    {
        _initSpellOutStringAttribute(this, range.start, range.end);
    }
}

StringAttribute SpellOutStringAttribute::copy(TextRange range) {
    return SpellOutStringAttribute(range);
}

String SpellOutStringAttribute::toString() {
    return "SpellOutStringAttribute($range)";
}

LocaleStringAttribute::LocaleStringAttribute(Locale locale, TextRange range) {
    {
        super._(range);
    }
    {
        _initLocaleStringAttribute(this, range.start, range.end, locale.toLanguageTag());
    }
}

StringAttribute LocaleStringAttribute::copy(TextRange range) {
    return LocaleStringAttribute(range, locale);
}

String LocaleStringAttribute::toString() {
    return "LocaleStringAttribute($range, ${locale.toLanguageTag()})";
}

SemanticsUpdateBuilder::SemanticsUpdateBuilder() {
    {
        _constructor();
    }
}

void SemanticsUpdateBuilder::updateNode(int actions, Int32List additionalActions, Int32List childrenInHitTestOrder, Int32List childrenInTraversalOrder, int currentValueLength, String decreasedValue, List<StringAttribute> decreasedValueAttributes, double elevation, int flags, String hint, List<StringAttribute> hintAttributes, int id, String increasedValue, List<StringAttribute> increasedValueAttributes, String label, List<StringAttribute> labelAttributes, int maxValueLength, int platformViewId, Rect rect, int scrollChildren, double scrollExtentMax, double scrollExtentMin, int scrollIndex, double scrollPosition, TextDirection textDirection, int textSelectionBase, int textSelectionExtent, double thickness, String tooltip, Float64List transform, String value, List<StringAttribute> valueAttributes) {
    assert(_matrix4IsValid(transform));
    assert(scrollChildren == 0 || scrollChildren == nullptr || (scrollChildren > 0 && childrenInHitTestOrder != nullptr), "If a node has scrollChildren, it must have childrenInHitTestOrder");
    _updateNode(id, flags, actions, maxValueLength, currentValueLength, textSelectionBase, textSelectionExtent, platformViewId, scrollChildren, scrollIndex, scrollPosition, scrollExtentMax, scrollExtentMin, rect.left, rect.top, rect.right, rect.bottom, elevation, thickness, label, labelAttributes, value, valueAttributes, increasedValue, increasedValueAttributes, decreasedValue, decreasedValueAttributes, hint, hintAttributes, tooltip ?? "", textDirection != nullptr? textDirection.index + 1 : 0, transform, childrenInTraversalOrder, childrenInHitTestOrder, additionalActions);
}

void SemanticsUpdateBuilder::updateCustomAction(String hint, int id, String label, int overrideId) {
    assert(id != nullptr);
    assert(overrideId != nullptr);
    _updateCustomAction(id, label ?? "", hint ?? "", overrideId);
}

SemanticsUpdate SemanticsUpdateBuilder::build() {
    SemanticsUpdate semanticsUpdate = SemanticsUpdate._();
    _build(semanticsUpdate);
    return semanticsUpdate;
}
