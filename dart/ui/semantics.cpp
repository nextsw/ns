#include "semantics.hpp"
String SemanticsActionCls::toString() {
    ;
    assert(false, __sf("Unhandled index: %s (0x%s)", index, index->toRadixString(8)->padLeft(4, __s("0"))));
    return __s("");
}

void SemanticsActionCls::_(int index)

String SemanticsFlagCls::toString() {
    ;
    assert(false, __sf("Unhandled index: %s (0x%s)", index, index->toRadixString(8)->padLeft(4, __s("0"))));
    return __s("");
}

void SemanticsFlagCls::_(int index)

SpellOutStringAttributeCls::SpellOutStringAttributeCls(TextRange range) {
    {
        super->_(range);
    }
    {
        _initSpellOutStringAttribute(this, range->start, range->end);
    }
}

StringAttribute SpellOutStringAttributeCls::copy(TextRange range) {
    return make<SpellOutStringAttributeCls>(range);
}

String SpellOutStringAttributeCls::toString() {
    return __sf("SpellOutStringAttribute(%s)", range);
}

LocaleStringAttributeCls::LocaleStringAttributeCls(Locale locale, TextRange range) {
    {
        super->_(range);
    }
    {
        _initLocaleStringAttribute(this, range->start, range->end, locale->toLanguageTag());
    }
}

StringAttribute LocaleStringAttributeCls::copy(TextRange range) {
    return make<LocaleStringAttributeCls>(range, locale);
}

String LocaleStringAttributeCls::toString() {
    return __sf("LocaleStringAttribute(%s, %s)", range, locale->toLanguageTag());
}

SemanticsUpdateBuilderCls::SemanticsUpdateBuilderCls() {
    {
        _constructor();
    }
}

void SemanticsUpdateBuilderCls::updateNode(int actions, Int32List additionalActions, Int32List childrenInHitTestOrder, Int32List childrenInTraversalOrder, int currentValueLength, String decreasedValue, List<StringAttribute> decreasedValueAttributes, double elevation, int flags, String hint, List<StringAttribute> hintAttributes, int id, String increasedValue, List<StringAttribute> increasedValueAttributes, String label, List<StringAttribute> labelAttributes, int maxValueLength, int platformViewId, Rect rect, int scrollChildren, double scrollExtentMax, double scrollExtentMin, int scrollIndex, double scrollPosition, TextDirection textDirection, int textSelectionBase, int textSelectionExtent, double thickness, String tooltip, Float64List transform, String value, List<StringAttribute> valueAttributes) {
    assert(_matrix4IsValid(transform));
    assert(scrollChildren == 0 || scrollChildren == nullptr || (scrollChildren > 0 && childrenInHitTestOrder != nullptr), __s("If a node has scrollChildren, it must have childrenInHitTestOrder"));
    _updateNode(id, flags, actions, maxValueLength, currentValueLength, textSelectionBase, textSelectionExtent, platformViewId, scrollChildren, scrollIndex, scrollPosition, scrollExtentMax, scrollExtentMin, rect->left, rect->top, rect->right, rect->bottom, elevation, thickness, label, labelAttributes, value, valueAttributes, increasedValue, increasedValueAttributes, decreasedValue, decreasedValueAttributes, hint, hintAttributes, tooltip | __s(""), textDirection != nullptr? textDirection->index + 1 : 0, transform, childrenInTraversalOrder, childrenInHitTestOrder, additionalActions);
}

void SemanticsUpdateBuilderCls::updateCustomAction(String hint, int id, String label, int overrideId) {
    assert(id != nullptr);
    assert(overrideId != nullptr);
    _updateCustomAction(id, label | __s(""), hint | __s(""), overrideId);
}

SemanticsUpdate SemanticsUpdateBuilderCls::build() {
    SemanticsUpdate semanticsUpdate = SemanticsUpdateCls->_();
    _build(semanticsUpdate);
    return semanticsUpdate;
}
