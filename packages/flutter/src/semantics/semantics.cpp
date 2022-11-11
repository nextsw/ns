#include "semantics.hpp"
String SemanticsTagCls::toString() {
    return __s("${objectRuntimeType(this, 'SemanticsTag')}($name)");
}

CustomSemanticsActionCls::CustomSemanticsActionCls(String label) {
    {
        assert(label != nullptr);
        assert(label != __s(""));
        hint = nullptr;
        action = nullptr;
    }
}

void CustomSemanticsActionCls::overridingAction(SemanticsAction action, String hint)

int CustomSemanticsActionCls::hashCode() {
    return ObjectCls->hash(label, hint, action);
}

bool CustomSemanticsActionCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<CustomSemanticsAction>(other) && other->label == label && other->hint == hint && other->action == action;
}

String CustomSemanticsActionCls::toString() {
    return __s("CustomSemanticsAction(${_ids[this]}, label:$label, hint:$hint, action:$action)");
}

int CustomSemanticsActionCls::getIdentifier(CustomSemanticsAction action) {
    int result = _ids[action];
    if (result == nullptr) {
        result = _nextId++;
        _ids[action] = result;
        _actions[result] = action;
    }
    return result;
}

CustomSemanticsAction CustomSemanticsActionCls::getAction(int id) {
    return _actions[id];
}

AttributedStringCls::AttributedStringCls(String string, List<StringAttribute> attributes) {
    {
        assert(stringValue->isNotEmpty() || attributes->isEmpty());
        assert([=] () {
            for (StringAttribute attribute : attributes) {
                assert(stringValue->length() >= attribute->range->start && stringValue->length() >= attribute->range->end, __s("The range in $attribute is outside of the string $string"));
            }
            return true;
        }());
    }
}

AttributedString AttributedStringCls::+(AttributedString other) {
    if (stringValue->isEmpty()) {
        return other;
    }
    if (other->stringValue->isEmpty()) {
        return this;
    }
    String newString = stringValue + other->stringValue;
    List<StringAttribute> newAttributes = <StringAttribute>of(attributes);
    if (other->attributes->isNotEmpty()) {
        int offset = stringValue->length();
        for (StringAttribute attribute : other->attributes) {
            TextRange newRange = make<TextRangeCls>(attribute->range->start + offset, attribute->range->end + offset);
            StringAttribute adjustedAttribute = attribute->copy(newRange);
            newAttributes->add(adjustedAttribute);
        }
    }
    return make<AttributedStringCls>(newString, newAttributes);
}

bool AttributedStringCls::==(Object other) {
    return other->runtimeType() == runtimeType && is<AttributedString>(other) && other->stringValue == stringValue && <StringAttribute>listEquals(other->attributes, attributes);
}

int AttributedStringCls::hashCode() {
    return ObjectCls->hash(stringValue, attributes);
}

String AttributedStringCls::toString() {
    return __s("${objectRuntimeType(this, 'AttributedString')}('$string', attributes: $attributes)");
}

AttributedStringPropertyCls::AttributedStringPropertyCls(String name, Unknown value, Object defaultValue, Unknown description, Unknown level, bool showName, bool showWhenEmpty) {
    {
        assert(showName != nullptr);
        assert(level() != nullptr);
    }
}

bool AttributedStringPropertyCls::isInteresting() {
    return super->isInteresting && (showWhenEmpty || (value() != nullptr && value()!->stringValue->isNotEmpty));
}

String AttributedStringPropertyCls::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value() == nullptr) {
        return __s("null");
    }
    String text = value()!->stringValue;
    if (parentConfiguration != nullptr && !parentConfiguration->lineBreakProperties) {
        text = text->replaceAll(__s("\n"), __s("\n"));
    }
    if (value()!->attributes->isEmpty) {
        return __s(""$text"");
    }
    return __s(""$text" ${value!.attributes}");
}

SemanticsDataCls::SemanticsDataCls(int actions, AttributedString attributedDecreasedValue, AttributedString attributedHint, AttributedString attributedIncreasedValue, AttributedString attributedLabel, AttributedString attributedValue, int currentValueLength, List<int> customSemanticsActionIds, double elevation, int flags, int maxValueLength, int platformViewId, Rect rect, int scrollChildCount, double scrollExtentMax, double scrollExtentMin, int scrollIndex, double scrollPosition, Set<SemanticsTag> tags, TextDirection textDirection, TextSelection textSelection, double thickness, String tooltip, Matrix4 transform) {
    {
        assert(flags != nullptr);
        assert(actions != nullptr);
        assert(attributedLabel != nullptr);
        assert(attributedValue != nullptr);
        assert(attributedDecreasedValue != nullptr);
        assert(attributedIncreasedValue != nullptr);
        assert(attributedHint != nullptr);
        assert(tooltip == __s("") || textDirection != nullptr, __s("A SemanticsData object with tooltip "$tooltip" had a null textDirection."));
        assert(attributedLabel->stringValue == __s("") || textDirection != nullptr, __s("A SemanticsData object with label "${attributedLabel.string}" had a null textDirection."));
        assert(attributedValue->stringValue == __s("") || textDirection != nullptr, __s("A SemanticsData object with value "${attributedValue.string}" had a null textDirection."));
        assert(attributedDecreasedValue->stringValue == __s("") || textDirection != nullptr, __s("A SemanticsData object with decreasedValue "${attributedDecreasedValue.string}" had a null textDirection."));
        assert(attributedIncreasedValue->stringValue == __s("") || textDirection != nullptr, __s("A SemanticsData object with increasedValue "${attributedIncreasedValue.string}" had a null textDirection."));
        assert(attributedHint->stringValue == __s("") || textDirection != nullptr, __s("A SemanticsData object with hint "${attributedHint.string}" had a null textDirection."));
        assert(rect != nullptr);
    }
}

String SemanticsDataCls::label() {
    return attributedLabel->stringValue;
}

String SemanticsDataCls::value() {
    return attributedValue->stringValue;
}

String SemanticsDataCls::increasedValue() {
    return attributedIncreasedValue->stringValue;
}

String SemanticsDataCls::decreasedValue() {
    return attributedDecreasedValue->stringValue;
}

String SemanticsDataCls::hint() {
    return attributedHint->stringValue;
}

bool SemanticsDataCls::hasFlag(SemanticsFlag flag) {
    return (flags & flag->index) != 0;
}

bool SemanticsDataCls::hasAction(SemanticsAction action) {
    return (actions & action->index) != 0;
}

String SemanticsDataCls::toStringShort() {
    return objectRuntimeType(this, __s("SemanticsData"));
}

void SemanticsDataCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Rect>make<DiagnosticsPropertyCls>(__s("rect"), rect, false));
    properties->add(make<TransformPropertyCls>(__s("transform"), transform, false, nullptr));
    properties->add(make<DoublePropertyCls>(__s("elevation"), elevation, 0.0));
    properties->add(make<DoublePropertyCls>(__s("thickness"), thickness, 0.0));
    List<String> list1 = make<ListCls<>>();for (SemanticsAction action : SemanticsActionCls::values->values) {    ;}{    list1.add(ArrayItem);}List<String> actionSummary = list1;
    List<String> customSemanticsActionSummary = customSemanticsActionIds!-><String>map([=] (int actionId) {
    CustomSemanticsActionCls->getAction(actionId)!->label;
})->toList();
    properties->add(<String>make<IterablePropertyCls>(__s("actions"), actionSummary, nullptr));
    properties->add(<String>make<IterablePropertyCls>(__s("customActions"), customSemanticsActionSummary, nullptr));
    List<String> list2 = make<ListCls<>>();for (SemanticsFlag flag : SemanticsFlagCls::values->values) {    ;}{    list2.add(ArrayItem);}List<String> flagSummary = list2;
    properties->add(<String>make<IterablePropertyCls>(__s("flags"), flagSummary, nullptr));
    properties->add(make<AttributedStringPropertyCls>(__s("label"), attributedLabel));
    properties->add(make<AttributedStringPropertyCls>(__s("value"), attributedValue));
    properties->add(make<AttributedStringPropertyCls>(__s("increasedValue"), attributedIncreasedValue));
    properties->add(make<AttributedStringPropertyCls>(__s("decreasedValue"), attributedDecreasedValue));
    properties->add(make<AttributedStringPropertyCls>(__s("hint"), attributedHint));
    properties->add(make<StringPropertyCls>(__s("tooltip"), tooltip, __s("")));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection, nullptr));
    if (textSelection?->isValid() | false) {
        properties->add(make<MessagePropertyCls>(__s("textSelection"), __s("[${textSelection!.start}, ${textSelection!.end}]")));
    }
    properties->add(make<IntPropertyCls>(__s("platformViewId"), platformViewId, nullptr));
    properties->add(make<IntPropertyCls>(__s("maxValueLength"), maxValueLength, nullptr));
    properties->add(make<IntPropertyCls>(__s("currentValueLength"), currentValueLength, nullptr));
    properties->add(make<IntPropertyCls>(__s("scrollChildren"), scrollChildCount, nullptr));
    properties->add(make<IntPropertyCls>(__s("scrollIndex"), scrollIndex, nullptr));
    properties->add(make<DoublePropertyCls>(__s("scrollExtentMin"), scrollExtentMin, nullptr));
    properties->add(make<DoublePropertyCls>(__s("scrollPosition"), scrollPosition, nullptr));
    properties->add(make<DoublePropertyCls>(__s("scrollExtentMax"), scrollExtentMax, nullptr));
}

bool SemanticsDataCls::==(Object other) {
    return is<SemanticsData>(other) && other->flags == flags && other->actions == actions && other->attributedLabel == attributedLabel && other->attributedValue == attributedValue && other->attributedIncreasedValue == attributedIncreasedValue && other->attributedDecreasedValue == attributedDecreasedValue && other->attributedHint == attributedHint && other->tooltip == tooltip && other->textDirection == textDirection && other->rect == rect && setEquals(other->tags, tags) && other->scrollChildCount == scrollChildCount && other->scrollIndex == scrollIndex && other->textSelection == textSelection && other->scrollPosition == scrollPosition && other->scrollExtentMax == scrollExtentMax && other->scrollExtentMin == scrollExtentMin && other->platformViewId == platformViewId && other->maxValueLength == maxValueLength && other->currentValueLength == currentValueLength && other->transform == transform && other->elevation == elevation && other->thickness == thickness && _sortedListsEqual(other->customSemanticsActionIds, customSemanticsActionIds);
}

int SemanticsDataCls::hashCode() {
    return ObjectCls->hash(flags, actions, attributedLabel, attributedValue, attributedIncreasedValue, attributedDecreasedValue, attributedHint, tooltip, textDirection, rect, tags, textSelection, scrollChildCount, scrollIndex, scrollPosition, scrollExtentMax, scrollExtentMin, platformViewId, maxValueLength, ObjectCls->hash(currentValueLength, transform, elevation, thickness, customSemanticsActionIds == nullptr? nullptr : ObjectCls->hashAll(customSemanticsActionIds!)));
}

bool SemanticsDataCls::_sortedListsEqual(List<int> left, List<int> right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }
    if (left != nullptr && right != nullptr) {
        if (left->length() != right->length()) {
            return false;
        }
        for (;  < left->length(); i++) {
            if (left[i] != right[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

List<DiagnosticsNode> _SemanticsDiagnosticableNodeCls::getChildren() {
    return value->debugDescribeChildren(childOrder);
}

SemanticsHintOverridesCls::SemanticsHintOverridesCls(String onLongPressHint, String onTapHint) {
    {
        assert(onTapHint != __s(""));
        assert(onLongPressHint != __s(""));
    }
}

bool SemanticsHintOverridesCls::isNotEmpty() {
    return onTapHint != nullptr || onLongPressHint != nullptr;
}

int SemanticsHintOverridesCls::hashCode() {
    return ObjectCls->hash(onTapHint, onLongPressHint);
}

bool SemanticsHintOverridesCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<SemanticsHintOverrides>(other) && other->onTapHint == onTapHint && other->onLongPressHint == onLongPressHint;
}

void SemanticsHintOverridesCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<StringPropertyCls>(__s("onTapHint"), onTapHint, nullptr));
    properties->add(make<StringPropertyCls>(__s("onLongPressHint"), onLongPressHint, nullptr));
}

SemanticsPropertiesCls::SemanticsPropertiesCls(AttributedString attributedDecreasedValue, AttributedString attributedHint, AttributedString attributedIncreasedValue, AttributedString attributedLabel, AttributedString attributedValue, bool button, bool checked, int currentValueLength, Map<CustomSemanticsAction, VoidCallback> customSemanticsActions, String decreasedValue, bool enabled, bool focusable, bool focused, bool header, bool hidden, String hint, SemanticsHintOverrides hintOverrides, bool image, bool inMutuallyExclusiveGroup, String increasedValue, bool keyboardKey, String label, bool link, bool liveRegion, int maxValueLength, bool multiline, bool namesRoute, bool obscured, VoidCallback onCopy, VoidCallback onCut, VoidCallback onDecrease, VoidCallback onDidGainAccessibilityFocus, VoidCallback onDidLoseAccessibilityFocus, VoidCallback onDismiss, VoidCallback onIncrease, VoidCallback onLongPress, MoveCursorHandler onMoveCursorBackwardByCharacter, MoveCursorHandler onMoveCursorBackwardByWord, MoveCursorHandler onMoveCursorForwardByCharacter, MoveCursorHandler onMoveCursorForwardByWord, VoidCallback onPaste, VoidCallback onScrollDown, VoidCallback onScrollLeft, VoidCallback onScrollRight, VoidCallback onScrollUp, SetSelectionHandler onSetSelection, SetTextHandler onSetText, VoidCallback onTap, bool readOnly, bool scopesRoute, bool selected, bool slider, SemanticsSortKey sortKey, SemanticsTag tagForChildren, TextDirection textDirection, bool textField, bool toggled, String tooltip, String value) {
    {
        assert(label == nullptr || attributedLabel == nullptr, __s("Only one of label or attributedLabel should be provided"));
        assert(value == nullptr || attributedValue == nullptr, __s("Only one of value or attributedValue should be provided"));
        assert(increasedValue == nullptr || attributedIncreasedValue == nullptr, __s("Only one of increasedValue or attributedIncreasedValue should be provided"));
        assert(decreasedValue == nullptr || attributedDecreasedValue == nullptr, __s("Only one of decreasedValue or attributedDecreasedValue should be provided"));
        assert(hint == nullptr || attributedHint == nullptr, __s("Only one of hint or attributedHint should be provided"));
    }
}

void SemanticsPropertiesCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("checked"), checked, nullptr));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("selected"), selected, nullptr));
    properties->add(make<StringPropertyCls>(__s("label"), label, nullptr));
    properties->add(make<AttributedStringPropertyCls>(__s("attributedLabel"), attributedLabel, nullptr));
    properties->add(make<StringPropertyCls>(__s("value"), value, nullptr));
    properties->add(make<AttributedStringPropertyCls>(__s("attributedValue"), attributedValue, nullptr));
    properties->add(make<StringPropertyCls>(__s("increasedValue"), value, nullptr));
    properties->add(make<AttributedStringPropertyCls>(__s("attributedIncreasedValue"), attributedIncreasedValue, nullptr));
    properties->add(make<StringPropertyCls>(__s("decreasedValue"), value, nullptr));
    properties->add(make<AttributedStringPropertyCls>(__s("attributedDecreasedValue"), attributedDecreasedValue, nullptr));
    properties->add(make<StringPropertyCls>(__s("hint"), hint, nullptr));
    properties->add(make<AttributedStringPropertyCls>(__s("attributedHint"), attributedHint, nullptr));
    properties->add(make<StringPropertyCls>(__s("tooltip"), tooltip));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection, nullptr));
    properties->add(<SemanticsSortKey>make<DiagnosticsPropertyCls>(__s("sortKey"), sortKey, nullptr));
    properties->add(<SemanticsHintOverrides>make<DiagnosticsPropertyCls>(__s("hintOverrides"), hintOverrides, nullptr));
}

String SemanticsPropertiesCls::toStringShort() {
    return objectRuntimeType(this, __s("SemanticsProperties"));
}

void debugResetSemanticsIdCounter() {
    SemanticsNodeCls::_lastIdentifier = 0;
}

SemanticsNodeCls::SemanticsNodeCls(Key key, VoidCallback showOnScreen) {
    {
        _id = _generateNewId();
        _showOnScreen = showOnScreen;
    }
}

void SemanticsNodeCls::root(Key key, SemanticsOwner owner, VoidCallback showOnScreen) {
    attach(owner);
}

int SemanticsNodeCls::id() {
    return _id;
}

Matrix4 SemanticsNodeCls::transform() {
    return _transform;
}

void SemanticsNodeCls::transform(Matrix4 value) {
    if (!MatrixUtilsCls->matrixEquals(_transform, value)) {
        _transform = value == nullptr || MatrixUtilsCls->isIdentity(value)? nullptr : value;
        _markDirty();
    }
}

Rect SemanticsNodeCls::rect() {
    return _rect;
}

void SemanticsNodeCls::rect(Rect value) {
    assert(value != nullptr);
    assert(value->isFinite(), __s("$this (with $owner) tried to set a non-finite rect."));
    if (_rect != value) {
        _rect = value;
        _markDirty();
    }
}

bool SemanticsNodeCls::isInvisible() {
    return !isMergedIntoParent() && rect()->isEmpty();
}

bool SemanticsNodeCls::isMergedIntoParent() {
    return _isMergedIntoParent;
}

void SemanticsNodeCls::isMergedIntoParent(bool value) {
    assert(value != nullptr);
    if (_isMergedIntoParent == value) {
        return;
    }
    _isMergedIntoParent = value;
    _markDirty();
}

bool SemanticsNodeCls::isPartOfNodeMerging() {
    return mergeAllDescendantsIntoThisNode() || isMergedIntoParent();
}

bool SemanticsNodeCls::mergeAllDescendantsIntoThisNode() {
    return _mergeAllDescendantsIntoThisNode;
}

bool SemanticsNodeCls::hasChildren() {
    return _children?->isNotEmpty() | false;
}

int SemanticsNodeCls::childrenCount() {
    return hasChildren()? _children!->length() : 0;
}

void SemanticsNodeCls::visitChildren(SemanticsNodeVisitor visitor) {
    if (_children != nullptr) {
        for (SemanticsNode child : _children!) {
            if (!visitor(child)) {
                return;
            }
        }
    }
}

SemanticsOwner SemanticsNodeCls::owner() {
    return as<SemanticsOwner>(super->owner);
}

SemanticsNode SemanticsNodeCls::parent() {
    return as<SemanticsNode>(super->parent);
}

void SemanticsNodeCls::redepthChildren() {
    _children?->forEach(redepthChild);
}

void SemanticsNodeCls::attach(SemanticsOwner owner) {
    super->attach(owner);
    while (owner->_nodes->containsKey(id())) {
        _id = _generateNewId();
    }
    owner->_nodes[id()] = this;
    owner->_detachedNodes->remove(this);
    if (_dirty) {
        _dirty = false;
        _markDirty();
    }
    if (_children != nullptr) {
        for (SemanticsNode child : _children!) {
            child->attach(owner);
        }
    }
}

void SemanticsNodeCls::detach() {
    assert(owner()!->_nodes->containsKey(id()));
    assert(!owner()!->_detachedNodes->contains(this));
    owner()!->_nodes->remove(id());
    owner()!->_detachedNodes->add(this);
    super->detach();
    assert(owner() == nullptr);
    if (_children != nullptr) {
        for (SemanticsNode child : _children!) {
            if (child->parent == this) {
                child->detach();
            }
        }
    }
    _markDirty();
}

bool SemanticsNodeCls::isTagged(SemanticsTag tag) {
    return tags != nullptr && tags!->contains(tag);
}

bool SemanticsNodeCls::hasFlag(SemanticsFlag flag) {
    return _flags & flag->index != 0;
}

String SemanticsNodeCls::label() {
    return _attributedLabel->stringValue;
}

AttributedString SemanticsNodeCls::attributedLabel() {
    return _attributedLabel;
}

String SemanticsNodeCls::value() {
    return _attributedValue->stringValue;
}

AttributedString SemanticsNodeCls::attributedValue() {
    return _attributedValue;
}

String SemanticsNodeCls::increasedValue() {
    return _attributedIncreasedValue->stringValue;
}

AttributedString SemanticsNodeCls::attributedIncreasedValue() {
    return _attributedIncreasedValue;
}

String SemanticsNodeCls::decreasedValue() {
    return _attributedDecreasedValue->stringValue;
}

AttributedString SemanticsNodeCls::attributedDecreasedValue() {
    return _attributedDecreasedValue;
}

String SemanticsNodeCls::hint() {
    return _attributedHint->stringValue;
}

AttributedString SemanticsNodeCls::attributedHint() {
    return _attributedHint;
}

String SemanticsNodeCls::tooltip() {
    return _tooltip;
}

double SemanticsNodeCls::elevation() {
    return _elevation;
}

double SemanticsNodeCls::thickness() {
    return _thickness;
}

SemanticsHintOverrides SemanticsNodeCls::hintOverrides() {
    return _hintOverrides;
}

TextDirection SemanticsNodeCls::textDirection() {
    return _textDirection;
}

SemanticsSortKey SemanticsNodeCls::sortKey() {
    return _sortKey;
}

TextSelection SemanticsNodeCls::textSelection() {
    return _textSelection;
}

bool SemanticsNodeCls::isMultiline() {
    return _isMultiline;
}

int SemanticsNodeCls::scrollChildCount() {
    return _scrollChildCount;
}

int SemanticsNodeCls::scrollIndex() {
    return _scrollIndex;
}

double SemanticsNodeCls::scrollPosition() {
    return _scrollPosition;
}

double SemanticsNodeCls::scrollExtentMax() {
    return _scrollExtentMax;
}

double SemanticsNodeCls::scrollExtentMin() {
    return _scrollExtentMin;
}

int SemanticsNodeCls::platformViewId() {
    return _platformViewId;
}

int SemanticsNodeCls::maxValueLength() {
    return _maxValueLength;
}

int SemanticsNodeCls::currentValueLength() {
    return _currentValueLength;
}

void SemanticsNodeCls::updateWith(List<SemanticsNode> childrenInInversePaintOrder, SemanticsConfiguration config) {
    config |= _kEmptyConfig;
    if (_isDifferentFromCurrentSemanticAnnotation(config)) {
        _markDirty();
    }
    assert(config->platformViewId() == nullptr || childrenInInversePaintOrder == nullptr || childrenInInversePaintOrder->isEmpty(), __s("SemanticsNodes with children must not specify a platformViewId."));
    _attributedLabel = config->attributedLabel();
    _attributedValue = config->attributedValue();
    _attributedIncreasedValue = config->attributedIncreasedValue();
    _attributedDecreasedValue = config->attributedDecreasedValue();
    _attributedHint = config->attributedHint();
    _tooltip = config->tooltip();
    _hintOverrides = config->hintOverrides();
    _elevation = config->elevation();
    _thickness = config->thickness();
    _flags = config->_flags;
    _textDirection = config->textDirection();
    _sortKey = config->sortKey();
    _actions = <SemanticsAction, SemanticsActionHandler>of(config->_actions);
    _customSemanticsActions = <CustomSemanticsAction, VoidCallback>of(config->_customSemanticsActions);
    _actionsAsBits = config->_actionsAsBits;
    _textSelection = config->_textSelection;
    _isMultiline = config->isMultiline();
    _scrollPosition = config->_scrollPosition;
    _scrollExtentMax = config->_scrollExtentMax;
    _scrollExtentMin = config->_scrollExtentMin;
    _mergeAllDescendantsIntoThisNode = config->isMergingSemanticsOfDescendants();
    _scrollChildCount = config->scrollChildCount();
    _scrollIndex = config->scrollIndex();
    indexInParent = config->indexInParent;
    _platformViewId = config->_platformViewId;
    _maxValueLength = config->_maxValueLength;
    _currentValueLength = config->_currentValueLength;
    _replaceChildren(childrenInInversePaintOrder | makeList());
    assert(!_canPerformAction(SemanticsActionCls::increase) || (value() == __s("")) == (increasedValue() == __s("")), __s("A SemanticsNode with action "increase" needs to be annotated with either both "value" and "increasedValue" or neither"));
    assert(!_canPerformAction(SemanticsActionCls::decrease) || (value() == __s("")) == (decreasedValue() == __s("")), __s("A SemanticsNode with action "increase" needs to be annotated with either both "value" and "decreasedValue" or neither"));
}

SemanticsData SemanticsNodeCls::getSemanticsData() {
    int flags = _flags;
    int actions = _actionsAsBits;
    AttributedString attributedLabel = _attributedLabel;
    AttributedString attributedValue = _attributedValue;
    AttributedString attributedIncreasedValue = _attributedIncreasedValue;
    AttributedString attributedDecreasedValue = _attributedDecreasedValue;
    AttributedString attributedHint = _attributedHint;
    String tooltip = _tooltip;
    TextDirection textDirection = _textDirection;
    Set<SemanticsTag> mergedTags = tags == nullptr? nullptr : <SemanticsTag>of(tags!);
    TextSelection textSelection = _textSelection;
    int scrollChildCount = _scrollChildCount;
    int scrollIndex = _scrollIndex;
    double scrollPosition = _scrollPosition;
    double scrollExtentMax = _scrollExtentMax;
    double scrollExtentMin = _scrollExtentMin;
    int platformViewId = _platformViewId;
    int maxValueLength = _maxValueLength;
    int currentValueLength = _currentValueLength;
    double elevation = _elevation;
    double thickness = _thickness;
    Set<int> customSemanticsActionIds = makeSet();
    for (CustomSemanticsAction action : _customSemanticsActions->keys()) {
        customSemanticsActionIds->add(CustomSemanticsActionCls->getIdentifier(action));
    }
    if (hintOverrides() != nullptr) {
        if (hintOverrides()!->onTapHint != nullptr) {
            CustomSemanticsAction action = CustomSemanticsActionCls->overridingAction(hintOverrides()!->onTapHint!, SemanticsActionCls::tap);
            customSemanticsActionIds->add(CustomSemanticsActionCls->getIdentifier(action));
        }
        if (hintOverrides()!->onLongPressHint != nullptr) {
            CustomSemanticsAction action = CustomSemanticsActionCls->overridingAction(hintOverrides()!->onLongPressHint!, SemanticsActionCls::longPress);
            customSemanticsActionIds->add(CustomSemanticsActionCls->getIdentifier(action));
        }
    }
    if (mergeAllDescendantsIntoThisNode()) {
        _visitDescendants([=] (SemanticsNode node) {
            assert(node->isMergedIntoParent);
            flags |= node->_flags;
            actions |= node->_actionsAsBits;
            textDirection |= node->_textDirection;
            textSelection |= node->_textSelection;
            scrollChildCount |= node->_scrollChildCount;
            scrollIndex |= node->_scrollIndex;
            scrollPosition |= node->_scrollPosition;
            scrollExtentMax |= node->_scrollExtentMax;
            scrollExtentMin |= node->_scrollExtentMin;
            platformViewId |= node->_platformViewId;
            maxValueLength |= node->_maxValueLength;
            currentValueLength |= node->_currentValueLength;
            if (attributedValue == nullptr || attributedValue->stringValue == __s("")) {
                attributedValue = node->_attributedValue;
            }
            if (attributedIncreasedValue == nullptr || attributedIncreasedValue->stringValue == __s("")) {
                attributedIncreasedValue = node->_attributedIncreasedValue;
            }
            if (attributedDecreasedValue == nullptr || attributedDecreasedValue->stringValue == __s("")) {
                attributedDecreasedValue = node->_attributedDecreasedValue;
            }
            if (tooltip == __s("")) {
                tooltip = node->_tooltip;
            }
            if (node->tags != nullptr) {
                mergedTags |= makeSet();
                mergedTags!->addAll(node->tags!);
            }
            for (CustomSemanticsAction action : _customSemanticsActions->keys()) {
                customSemanticsActionIds->add(CustomSemanticsActionCls->getIdentifier(action));
            }
            if (node->hintOverrides != nullptr) {
                if (node->hintOverrides!->onTapHint != nullptr) {
                    CustomSemanticsAction action = CustomSemanticsActionCls->overridingAction(node->hintOverrides!->onTapHint!, SemanticsActionCls::tap);
                    customSemanticsActionIds->add(CustomSemanticsActionCls->getIdentifier(action));
                }
                if (node->hintOverrides!->onLongPressHint != nullptr) {
                    CustomSemanticsAction action = CustomSemanticsActionCls->overridingAction(node->hintOverrides!->onLongPressHint!, SemanticsActionCls::longPress);
                    customSemanticsActionIds->add(CustomSemanticsActionCls->getIdentifier(action));
                }
            }
            attributedLabel = _concatAttributedString(attributedLabel, textDirection, node->_attributedLabel, node->_textDirection);
            attributedHint = _concatAttributedString(attributedHint, textDirection, node->_attributedHint, node->_textDirection);
            thickness = math->max(thickness, node->_thickness + node->_elevation);
            return true;
        });
    }
    auto _c1 = customSemanticsActionIds->toList();_c1.sort();return make<SemanticsDataCls>(flags, actions, attributedLabel, attributedValue, attributedIncreasedValue, attributedDecreasedValue, attributedHint, tooltip, textDirection, rect(), transform(), elevation, thickness, mergedTags, textSelection, scrollChildCount, scrollIndex, scrollPosition, scrollExtentMax, scrollExtentMin, platformViewId, maxValueLength, currentValueLength, _c1);
}

void SemanticsNodeCls::sendEvent(SemanticsEvent event) {
    if (!attached()) {
        return;
    }
    SystemChannelsCls::accessibility->send(event->toMap(id()));
}

String SemanticsNodeCls::toStringShort() {
    return __s("${objectRuntimeType(this, 'SemanticsNode')}#$id");
}

void SemanticsNodeCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    bool hideOwner = true;
    if (_dirty) {
        bool inDirtyNodes = owner() != nullptr && owner()!->_dirtyNodes->contains(this);
        properties->add(make<FlagPropertyCls>(__s("inDirtyNodes"), inDirtyNodes, __s("dirty"), __s("STALE")));
        hideOwner = inDirtyNodes;
    }
    properties->add(<SemanticsOwner>make<DiagnosticsPropertyCls>(__s("owner"), owner(), hideOwner? DiagnosticLevelCls::hidden : DiagnosticLevelCls::info));
    properties->add(make<FlagPropertyCls>(__s("isMergedIntoParent"), isMergedIntoParent(), __s("merged up ⬆️")));
    properties->add(make<FlagPropertyCls>(__s("mergeAllDescendantsIntoThisNode"), mergeAllDescendantsIntoThisNode(), __s("merge boundary ⛔️")));
    Offset offset = transform() != nullptr? MatrixUtilsCls->getAsTranslation(transform()!) : nullptr;
    if (offset != nullptr) {
        properties->add(<Rect>make<DiagnosticsPropertyCls>(__s("rect"), rect()->shift(offset), false));
    } else {
        double scale = transform() != nullptr? MatrixUtilsCls->getAsScale(transform()!) : nullptr;
        String description;
        if (scale != nullptr) {
            description = __s("$rect scaled by ${scale.toStringAsFixed(1)}x");
        } else {
            if (transform() != nullptr && !MatrixUtilsCls->isIdentity(transform()!)) {
            String matrix = transform()->toString()->split(__s("\n"))->take(4)-><String>map([=] (String line) {
    line->substring(4);
})->join(__s("; "));
            description = __s("$rect with transform [$matrix]");
        }
;
        }        properties->add(<Rect>make<DiagnosticsPropertyCls>(__s("rect"), rect(), description, false));
    }
    properties->add(<String>make<IterablePropertyCls>(__s("tags"), tags?->map([=] (SemanticsTag tag) {
        tag->name;
    }), nullptr));
    auto _c1 = _actions->keys()-><String>map([=] (SemanticsAction action) {    describeEnum(action);})->toList();_c1.sort();List<String> actions = _c1;
    List<String> customSemanticsActions = _customSemanticsActions->keys()-><String>map([=] (CustomSemanticsAction action) {
    action->label;
})->toList();
    properties->add(<String>make<IterablePropertyCls>(__s("actions"), actions, nullptr));
    properties->add(<String>make<IterablePropertyCls>(__s("customActions"), customSemanticsActions, nullptr));
    List<String> flags = SemanticsFlagCls::values->values->where([=] (SemanticsFlag flag) {
    hasFlag(flag);
})->map([=] (SemanticsFlag flag) {
    flag->toString()->substring(__s("SemanticsFlag.")->length());
})->toList();
    properties->add(<String>make<IterablePropertyCls>(__s("flags"), flags, nullptr));
    properties->add(make<FlagPropertyCls>(__s("isInvisible"), isInvisible(), __s("invisible")));
    properties->add(make<FlagPropertyCls>(__s("isHidden"), hasFlag(SemanticsFlagCls::isHidden), __s("HIDDEN")));
    properties->add(make<AttributedStringPropertyCls>(__s("label"), _attributedLabel));
    properties->add(make<AttributedStringPropertyCls>(__s("value"), _attributedValue));
    properties->add(make<AttributedStringPropertyCls>(__s("increasedValue"), _attributedIncreasedValue));
    properties->add(make<AttributedStringPropertyCls>(__s("decreasedValue"), _attributedDecreasedValue));
    properties->add(make<AttributedStringPropertyCls>(__s("hint"), _attributedHint));
    properties->add(make<StringPropertyCls>(__s("tooltip"), _tooltip, __s("")));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), _textDirection, nullptr));
    properties->add(<SemanticsSortKey>make<DiagnosticsPropertyCls>(__s("sortKey"), sortKey(), nullptr));
    if (_textSelection?->isValid() | false) {
        properties->add(make<MessagePropertyCls>(__s("text selection"), __s("[${_textSelection!.start}, ${_textSelection!.end}]")));
    }
    properties->add(make<IntPropertyCls>(__s("platformViewId"), platformViewId(), nullptr));
    properties->add(make<IntPropertyCls>(__s("maxValueLength"), maxValueLength(), nullptr));
    properties->add(make<IntPropertyCls>(__s("currentValueLength"), currentValueLength(), nullptr));
    properties->add(make<IntPropertyCls>(__s("scrollChildren"), scrollChildCount(), nullptr));
    properties->add(make<IntPropertyCls>(__s("scrollIndex"), scrollIndex(), nullptr));
    properties->add(make<DoublePropertyCls>(__s("scrollExtentMin"), scrollExtentMin(), nullptr));
    properties->add(make<DoublePropertyCls>(__s("scrollPosition"), scrollPosition(), nullptr));
    properties->add(make<DoublePropertyCls>(__s("scrollExtentMax"), scrollExtentMax(), nullptr));
    properties->add(make<DoublePropertyCls>(__s("elevation"), elevation(), 0.0));
    properties->add(make<DoublePropertyCls>(__s("thickness"), thickness(), 0.0));
}

String SemanticsNodeCls::toStringDeep(DebugSemanticsDumpOrder childOrder, DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines) {
    assert(childOrder != nullptr);
    return toDiagnosticsNode(childOrder)->toStringDeep(prefixLineOne, prefixOtherLines, minLevel);
}

DiagnosticsNode SemanticsNodeCls::toDiagnosticsNode(DebugSemanticsDumpOrder childOrder, String name, DiagnosticsTreeStyle style) {
    return make<_SemanticsDiagnosticableNodeCls>(name, this, style, childOrder);
}

List<DiagnosticsNode> SemanticsNodeCls::debugDescribeChildren(DebugSemanticsDumpOrder childOrder) {
    return debugListChildrenInOrder(childOrder)-><DiagnosticsNode>map([=] (SemanticsNode node) {
        node->toDiagnosticsNode(childOrder);
    })->toList();
}

List<SemanticsNode> SemanticsNodeCls::debugListChildrenInOrder(DebugSemanticsDumpOrder childOrder) {
    assert(childOrder != nullptr);
    if (_children == nullptr) {
        return makeList();
    }
    ;
}

int SemanticsNodeCls::_generateNewId() {
    _lastIdentifier = (_lastIdentifier + 1) % _maxFrameworkAccessibilityIdentifier;
    return _lastIdentifier;
}

void SemanticsNodeCls::_replaceChildren(List<SemanticsNode> newChildren) {
    assert(!newChildren->any([=] (SemanticsNode child) {
        child == this;
    }));
    assert([=] () {
        if (identical(newChildren, _children)) {
            List<DiagnosticsNode> mutationErrors = makeList();
            if (newChildren->length() != _debugPreviousSnapshot->length()) {
                mutationErrors->add(make<ErrorDescriptionCls>(__s("The list's length has changed from ${_debugPreviousSnapshot.length} to ${newChildren.length}.")));
            } else {
                for (;  < newChildren->length(); i++) {
                    if (!identical(newChildren[i], _debugPreviousSnapshot[i])) {
                        if (mutationErrors->isNotEmpty()) {
                            mutationErrors->add(make<ErrorSpacerCls>());
                        }
                        mutationErrors->add(make<ErrorDescriptionCls>(__s("Child node at position $i was replaced:")));
                        mutationErrors->add(newChildren[i]->toDiagnosticsNode(__s("Previous child"), DiagnosticsTreeStyleCls::singleLine));
                        mutationErrors->add(_debugPreviousSnapshot[i]->toDiagnosticsNode(__s("New child"), DiagnosticsTreeStyleCls::singleLine));
                    }
                }
            }
            if (mutationErrors->isNotEmpty()) {
                            List<DiagnosticsNode> list1 = make<ListCls<>>();            list1.add(ArrayItem);            list1.add(ArrayItem);            list1.add(ArrayItem);            for (auto _x1 : mutationErrors) {            {                list1.add(_x1);            }throw FlutterErrorCls->fromParts(list1);
            }
        }
        assert(!newChildren->any([=] (SemanticsNode node) {
            node->isMergedIntoParent;
        }) || isPartOfNodeMerging());
        _debugPreviousSnapshot = <SemanticsNode>of(newChildren);
        SemanticsNode ancestor = this;
        while (is<SemanticsNode>(ancestor->parent())) {
            ancestor = ancestor->parent()!;
        }
        assert(!newChildren->any([=] (SemanticsNode child) {
            child == ancestor;
        }));
        return true;
    }());
    assert([=] () {
        Set<SemanticsNode> seenChildren = makeSet();
        for (SemanticsNode child : newChildren) {
            assert(seenChildren->add(child));
        }
        return true;
    }());
    if (_children != nullptr) {
        for (SemanticsNode child : _children!) {
            child->_dead = true;
        }
    }
    for (SemanticsNode child : newChildren) {
        assert(!child->isInvisible, __s("Child $child is invisible and should not be added as a child of $this."));
        child->_dead = false;
    }
    bool sawChange = false;
    if (_children != nullptr) {
        for (SemanticsNode child : _children!) {
            if (child->_dead) {
                if (child->parent == this) {
                    dropChild(child);
                }
                sawChange = true;
            }
        }
    }
    for (SemanticsNode child : newChildren) {
        if (child->parent != this) {
            if (child->parent != nullptr) {
                child->parent?->dropChild(child);
            }
            assert(!child->attached);
            adoptChild(child);
            sawChange = true;
        }
    }
    if (!sawChange && _children != nullptr) {
        assert(newChildren != nullptr);
        assert(newChildren->length() == _children!->length());
        for (;  < _children!->length(); i++) {
            if (_children![i]->id() != newChildren[i]->id()) {
                sawChange = true;
                break;
            }
        }
    }
    _children = newChildren;
    if (sawChange) {
        _markDirty();
    }
}

bool SemanticsNodeCls::_visitDescendants(SemanticsNodeVisitor visitor) {
    if (_children != nullptr) {
        for (SemanticsNode child : _children!) {
            if (!visitor(child) || !child->_visitDescendants(visitor)) {
                return false;
            }
        }
    }
    return true;
}

void SemanticsNodeCls::_markDirty() {
    if (_dirty) {
        return;
    }
    _dirty = true;
    if (attached()) {
        assert(!owner()!->_detachedNodes->contains(this));
        owner()!->_dirtyNodes->add(this);
    }
}

bool SemanticsNodeCls::_isDifferentFromCurrentSemanticAnnotation(SemanticsConfiguration config) {
    return _attributedLabel != config->attributedLabel() || _attributedHint != config->attributedHint() || _elevation != config->elevation() || _thickness != config->thickness() || _attributedValue != config->attributedValue() || _attributedIncreasedValue != config->attributedIncreasedValue() || _attributedDecreasedValue != config->attributedDecreasedValue() || _tooltip != config->tooltip() || _flags != config->_flags || _textDirection != config->textDirection() || _sortKey != config->_sortKey || _textSelection != config->_textSelection || _scrollPosition != config->_scrollPosition || _scrollExtentMax != config->_scrollExtentMax || _scrollExtentMin != config->_scrollExtentMin || _actionsAsBits != config->_actionsAsBits || indexInParent != config->indexInParent || platformViewId() != config->platformViewId() || _maxValueLength != config->_maxValueLength || _currentValueLength != config->_currentValueLength || _mergeAllDescendantsIntoThisNode != config->isMergingSemanticsOfDescendants();
}

bool SemanticsNodeCls::_canPerformAction(SemanticsAction action) {
    return _actions->containsKey(action);
}

Float64List SemanticsNodeCls::_initIdentityTransform() {
    return Matrix4Cls->identity()->storage;
}

void SemanticsNodeCls::_addToUpdate(SemanticsUpdateBuilder builder, Set<int> customSemanticsActionIdsUpdate) {
    assert(_dirty);
    SemanticsData data = getSemanticsData();
    Int32List childrenInTraversalOrder;
    Int32List childrenInHitTestOrder;
    if (!hasChildren() || mergeAllDescendantsIntoThisNode()) {
        childrenInTraversalOrder = _kEmptyChildList;
        childrenInHitTestOrder = _kEmptyChildList;
    } else {
        int childCount = _children!->length();
        List<SemanticsNode> sortedChildren = _childrenInTraversalOrder();
        childrenInTraversalOrder = make<Int32ListCls>(childCount);
        for (;  < childCount; i += 1) {
            childrenInTraversalOrder[i] = sortedChildren[i]->id();
        }
        childrenInHitTestOrder = make<Int32ListCls>(childCount);
        for (; i >= 0; i -= 1) {
            childrenInHitTestOrder[i] = _children![childCount - i - 1]->id();
        }
    }
    Int32List customSemanticsActionIds;
    if (data->customSemanticsActionIds?->isNotEmpty() | false) {
        customSemanticsActionIds = make<Int32ListCls>(data->customSemanticsActionIds!->length());
        for (;  < data->customSemanticsActionIds!->length(); i++) {
            customSemanticsActionIds[i] = data->customSemanticsActionIds![i];
            customSemanticsActionIdsUpdate->add(data->customSemanticsActionIds![i]);
        }
    }
    builder->updateNode(id(), data->flags, data->actions, data->rect, data->attributedLabel->stringValue, data->attributedLabel->attributes, data->attributedValue->stringValue, data->attributedValue->attributes, data->attributedIncreasedValue->stringValue, data->attributedIncreasedValue->attributes, data->attributedDecreasedValue->stringValue, data->attributedDecreasedValue->attributes, data->attributedHint->stringValue, data->attributedHint->attributes, data->tooltip, data->textDirection, data->textSelection != nullptr? data->textSelection!->baseOffset : -1, data->textSelection != nullptr? data->textSelection!->extentOffset : -1, data->platformViewId | -1, data->maxValueLength | -1, data->currentValueLength | -1, data->scrollChildCount | 0, data->scrollIndex | 0, data->scrollPosition | double->nan, data->scrollExtentMax | double->nan, data->scrollExtentMin | double->nan, data->transform?->storage() | _kIdentityTransform, data->elevation, data->thickness, childrenInTraversalOrder, childrenInHitTestOrder, customSemanticsActionIds | _kEmptyCustomSemanticsActionsList);
    _dirty = false;
}

List<SemanticsNode> SemanticsNodeCls::_childrenInTraversalOrder() {
    TextDirection inheritedTextDirection = textDirection();
    SemanticsNode ancestor = parent();
    while (inheritedTextDirection == nullptr && ancestor != nullptr) {
        inheritedTextDirection = ancestor->textDirection();
        ancestor = ancestor->parent();
    }
    List<SemanticsNode> childrenInDefaultOrder;
    if (inheritedTextDirection != nullptr) {
        childrenInDefaultOrder = _childrenInDefaultOrder(_children!, inheritedTextDirection);
    } else {
        childrenInDefaultOrder = _children;
    }
    List<_TraversalSortNode> everythingSorted = makeList();
    List<_TraversalSortNode> sortNodes = makeList();
    SemanticsSortKey lastSortKey;
    for (;  < childrenInDefaultOrder!->length(); position += 1) {
        SemanticsNode child = childrenInDefaultOrder[position];
        SemanticsSortKey sortKey = child->sortKey();
        lastSortKey = position > 0? childrenInDefaultOrder[position - 1]->sortKey : nullptr;
        bool isCompatibleWithPreviousSortKey = position == 0 || sortKey->runtimeType == lastSortKey->runtimeType && (sortKey == nullptr || sortKey->name == lastSortKey!->name);
        if (!isCompatibleWithPreviousSortKey && sortNodes->isNotEmpty()) {
            if (lastSortKey != nullptr) {
                sortNodes->sort();
            }
            everythingSorted->addAll(sortNodes);
            sortNodes->clear();
        }
        sortNodes->add(make<_TraversalSortNodeCls>(child, sortKey, position));
    }
    if (lastSortKey != nullptr) {
        sortNodes->sort();
    }
    everythingSorted->addAll(sortNodes);
    return everythingSorted-><SemanticsNode>map([=] (_TraversalSortNode sortNode) {
        sortNode->node;
    })->toList();
}

int _BoxEdgeCls::compareTo(_BoxEdge other) {
    return offset->compareTo(other->offset);
}

_BoxEdgeCls::_BoxEdgeCls(bool isLeadingEdge, SemanticsNode node, double offset) {
    {
        assert(isLeadingEdge != nullptr);
        assert(offset != nullptr);
        assert(offset->isFinite());
        assert(node != nullptr);
    }
}

int _SemanticsSortGroupCls::compareTo(_SemanticsSortGroup other) {
    return startOffset->compareTo(other->startOffset);
}

List<SemanticsNode> _SemanticsSortGroupCls::sortedWithinVerticalGroup() {
    List<_BoxEdge> edges = makeList();
    for (SemanticsNode child : nodes) {
        Rect childRect = child->rect->deflate(0.1);
        edges->add(make<_BoxEdgeCls>(true, _pointInParentCoordinates(child, childRect->topLeft())->dx(), child));
        edges->add(make<_BoxEdgeCls>(false, _pointInParentCoordinates(child, childRect->bottomRight())->dx(), child));
    }
    edges->sort();
    List<_SemanticsSortGroup> horizontalGroups = makeList();
    _SemanticsSortGroup group;
    int depth = 0;
    for (_BoxEdge edge : edges) {
        if (edge->isLeadingEdge) {
            depth += 1;
            group |= make<_SemanticsSortGroupCls>(edge->offset, textDirection);
            group->nodes->add(edge->node);
        } else {
            depth -= 1;
        }
        if (depth == 0) {
            horizontalGroups->add(group!);
            group = nullptr;
        }
    }
    horizontalGroups->sort();
    if (textDirection == TextDirectionCls::rtl) {
        horizontalGroups = horizontalGroups->reversed()->toList();
    }
    return horizontalGroups->expand([=] (_SemanticsSortGroup group) {
        group->sortedWithinKnot();
    })->toList();
}

List<SemanticsNode> _SemanticsSortGroupCls::sortedWithinKnot() {
    if (nodes->length() <= 1) {
        return nodes;
    }
    Map<int, SemanticsNode> nodeMap = makeMap(makeList(), makeList();
    Map<int, int> edges = makeMap(makeList(), makeList();
    for (SemanticsNode node : nodes) {
        nodeMap[node->id] = node;
        Offset center = _pointInParentCoordinates(node, node->rect->center);
        for (SemanticsNode nextNode : nodes) {
            if (identical(node, nextNode) || edges[nextNode->id] == node->id) {
                continue;
            }
            Offset nextCenter = _pointInParentCoordinates(nextNode, nextNode->rect->center);
            Offset centerDelta = nextCenter - center;
            double direction = centerDelta->direction();
            bool isLtrAndForward = textDirection == TextDirectionCls::ltr && -math->pi / 4 < direction &&  < 3 * math->pi / 4;
            bool isRtlAndForward = textDirection == TextDirectionCls::rtl && ( < -3 * math->pi / 4 || direction > 3 * math->pi / 4);
            if (isLtrAndForward || isRtlAndForward) {
                edges[node->id] = nextNode->id;
            }
        }
    }
    List<int> sortedIds = makeList();
    Set<int> visitedIds = makeSet();
    });List<SemanticsNode> startNodes = auto _c1 = nodes->toList();_c1.sort([=] (SemanticsNode a,SemanticsNode b) {    Offset aTopLeft = _pointInParentCoordinates(a, a->rect->topLeft);    Offset bTopLeft = _pointInParentCoordinates(b, b->rect->topLeft);    int verticalDiff = aTopLeft->dy()->compareTo(bTopLeft->dy());    }        if (verticalDiff != 0) {            return -verticalDiff;    return -aTopLeft->dx()->compareTo(bTopLeft->dx());_c1;
    InlineMethod;
    startNodes-><int>map([=] (SemanticsNode node) {
        node->id;
    })->forEach(search);
    return sortedIds-><SemanticsNode>map([=] (int id) {
        nodeMap[id]!;
    })->toList()->reversed->toList();
}

_SemanticsSortGroupCls::_SemanticsSortGroupCls(double startOffset, TextDirection textDirection) {
    {
        assert(startOffset != nullptr);
    }
}

Offset _pointInParentCoordinates(SemanticsNode node, Offset point) {
    if (node->transform() == nullptr) {
        return point;
    }
    Vector3 vector = make<Vector3Cls>(point->dx(), point->dy(), 0.0);
    node->transform()!->transform3(vector);
    return make<OffsetCls>(vector->x, vector->y);
}

List<SemanticsNode> _childrenInDefaultOrder(List<SemanticsNode> children, TextDirection textDirection) {
    List<_BoxEdge> edges = makeList();
    for (SemanticsNode child : children) {
        assert(child->rect->isFinite);
        Rect childRect = child->rect->deflate(0.1);
        edges->add(make<_BoxEdgeCls>(true, _pointInParentCoordinates(child, childRect->topLeft())->dy(), child));
        edges->add(make<_BoxEdgeCls>(false, _pointInParentCoordinates(child, childRect->bottomRight())->dy(), child));
    }
    edges->sort();
    List<_SemanticsSortGroup> verticalGroups = makeList();
    _SemanticsSortGroup group;
    int depth = 0;
    for (_BoxEdge edge : edges) {
        if (edge->isLeadingEdge) {
            depth += 1;
            group |= make<_SemanticsSortGroupCls>(edge->offset, textDirection);
            group->nodes->add(edge->node);
        } else {
            depth -= 1;
        }
        if (depth == 0) {
            verticalGroups->add(group!);
            group = nullptr;
        }
    }
    verticalGroups->sort();
    return verticalGroups->expand([=] (_SemanticsSortGroup group) {
        group->sortedWithinVerticalGroup();
    })->toList();
}

int _TraversalSortNodeCls::compareTo(_TraversalSortNode other) {
    if (sortKey == nullptr || other->sortKey == nullptr) {
        return position - other->position;
    }
    return sortKey!->compareTo(other->sortKey!);
}

_TraversalSortNodeCls::_TraversalSortNodeCls(SemanticsNode node, int position, SemanticsSortKey sortKey) {
    {
        assert(node != nullptr);
        assert(position != nullptr);
    }
}

SemanticsNode SemanticsOwnerCls::rootSemanticsNode() {
    return _nodes[0];
}

void SemanticsOwnerCls::dispose() {
    _dirtyNodes->clear();
    _nodes->clear();
    _detachedNodes->clear();
    super->dispose();
}

void SemanticsOwnerCls::sendSemanticsUpdate() {
    if (_dirtyNodes->isEmpty()) {
        return;
    }
    Set<int> customSemanticsActionIds = makeSet();
    List<SemanticsNode> visitedNodes = makeList();
    while (_dirtyNodes->isNotEmpty()) {
        List<SemanticsNode> localDirtyNodes = _dirtyNodes->where([=] (SemanticsNode node) {
    !_detachedNodes->contains(node);
})->toList();
        _dirtyNodes->clear();
        _detachedNodes->clear();
        localDirtyNodes->sort([=] (SemanticsNode a,SemanticsNode b) {
            a->depth - b->depth;
        });
        visitedNodes->addAll(localDirtyNodes);
        for (SemanticsNode node : localDirtyNodes) {
            assert(node->_dirty);
            assert(node->parent == nullptr || !node->parent!->isPartOfNodeMerging || node->isMergedIntoParent);
            if (node->isPartOfNodeMerging) {
                assert(node->mergeAllDescendantsIntoThisNode || node->parent != nullptr);
                if (node->parent != nullptr && node->parent!->isPartOfNodeMerging) {
                    node->parent!->_markDirty();
                    node->_dirty = false;
                }
            }
        }
    }
    visitedNodes->sort([=] (SemanticsNode a,SemanticsNode b) {
        a->depth - b->depth;
    });
    SemanticsUpdateBuilder builder = SemanticsBindingCls::instance->createSemanticsUpdateBuilder();
    for (SemanticsNode node : visitedNodes) {
        assert(node->parent?->_dirty != true);
        if (node->_dirty && node->attached) {
            node->_addToUpdate(builder, customSemanticsActionIds);
        }
    }
    _dirtyNodes->clear();
    for (int actionId : customSemanticsActionIds) {
        CustomSemanticsAction action = CustomSemanticsActionCls->getAction(actionId)!;
        builder->updateCustomAction(actionId, action->label, action->hint, action->action?->index | -1);
    }
    SemanticsBindingCls::instance->platformDispatcher->updateSemantics(builder->build());
    notifyListeners();
}

void SemanticsOwnerCls::performAction(int id, SemanticsAction action, Object args) {
    assert(action != nullptr);
    SemanticsActionHandler handler = _getSemanticsActionHandlerForId(id, action);
    if (handler != nullptr) {
        handler(args);
        return;
    }
    if (action == SemanticsActionCls::showOnScreen && _nodes[id]!->_showOnScreen != nullptr) {
        _nodes[id]!->_showOnScreen!();
    }
}

void SemanticsOwnerCls::performActionAt(Offset position, SemanticsAction action, Object args) {
    assert(action != nullptr);
    SemanticsNode node = rootSemanticsNode();
    if (node == nullptr) {
        return;
    }
    SemanticsActionHandler handler = _getSemanticsActionHandlerForPosition(node, position, action);
    if (handler != nullptr) {
        handler(args);
    }
}

String SemanticsOwnerCls::toString() {
    return describeIdentity(this);
}

SemanticsActionHandler SemanticsOwnerCls::_getSemanticsActionHandlerForId(int id, SemanticsAction action) {
    SemanticsNode result = _nodes[id];
    if (result != nullptr && result->isPartOfNodeMerging() && !result->_canPerformAction(action)) {
        result->_visitDescendants([=] (SemanticsNode node) {
            if (node->_canPerformAction(action)) {
                result = node;
                return false;
            }
            return true;
        });
    }
    if (result == nullptr || !result!->_canPerformAction(action)) {
        return nullptr;
    }
    return result!->_actions[action];
}

SemanticsActionHandler SemanticsOwnerCls::_getSemanticsActionHandlerForPosition(SemanticsNode node, Offset position, SemanticsAction action) {
    if (node->transform() != nullptr) {
        Matrix4 inverse = Matrix4Cls->identity();
        if (inverse->copyInverse(node->transform()!) == 0.0) {
            return nullptr;
        }
        position = MatrixUtilsCls->transformPoint(inverse, position);
    }
    if (!node->rect()->contains(position)) {
        return nullptr;
    }
    if (node->mergeAllDescendantsIntoThisNode()) {
        SemanticsNode result;
        node->_visitDescendants([=] (SemanticsNode child) {
            if (child->_canPerformAction(action)) {
                result = child;
                return false;
            }
            return true;
        });
        return result?->_actions[action];
    }
    if (node->hasChildren()) {
        for (SemanticsNode child : node->_children!->reversed()) {
            SemanticsActionHandler handler = _getSemanticsActionHandlerForPosition(child, position, action);
            if (handler != nullptr) {
                return handler;
            }
        }
    }
    return node->_actions[action];
}

bool SemanticsConfigurationCls::isSemanticBoundary() {
    return _isSemanticBoundary;
}

void SemanticsConfigurationCls::isSemanticBoundary(bool value) {
    assert(!isMergingSemanticsOfDescendants() || value);
    _isSemanticBoundary = value;
}

bool SemanticsConfigurationCls::hasBeenAnnotated() {
    return _hasBeenAnnotated;
}

VoidCallback SemanticsConfigurationCls::onTap() {
    return _onTap;
}

void SemanticsConfigurationCls::onTap(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::tap, value!);
    _onTap = value;
}

VoidCallback SemanticsConfigurationCls::onLongPress() {
    return _onLongPress;
}

void SemanticsConfigurationCls::onLongPress(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::longPress, value!);
    _onLongPress = value;
}

VoidCallback SemanticsConfigurationCls::onScrollLeft() {
    return _onScrollLeft;
}

void SemanticsConfigurationCls::onScrollLeft(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::scrollLeft, value!);
    _onScrollLeft = value;
}

VoidCallback SemanticsConfigurationCls::onDismiss() {
    return _onDismiss;
}

void SemanticsConfigurationCls::onDismiss(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::dismiss, value!);
    _onDismiss = value;
}

VoidCallback SemanticsConfigurationCls::onScrollRight() {
    return _onScrollRight;
}

void SemanticsConfigurationCls::onScrollRight(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::scrollRight, value!);
    _onScrollRight = value;
}

VoidCallback SemanticsConfigurationCls::onScrollUp() {
    return _onScrollUp;
}

void SemanticsConfigurationCls::onScrollUp(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::scrollUp, value!);
    _onScrollUp = value;
}

VoidCallback SemanticsConfigurationCls::onScrollDown() {
    return _onScrollDown;
}

void SemanticsConfigurationCls::onScrollDown(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::scrollDown, value!);
    _onScrollDown = value;
}

VoidCallback SemanticsConfigurationCls::onIncrease() {
    return _onIncrease;
}

void SemanticsConfigurationCls::onIncrease(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::increase, value!);
    _onIncrease = value;
}

VoidCallback SemanticsConfigurationCls::onDecrease() {
    return _onDecrease;
}

void SemanticsConfigurationCls::onDecrease(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::decrease, value!);
    _onDecrease = value;
}

VoidCallback SemanticsConfigurationCls::onCopy() {
    return _onCopy;
}

void SemanticsConfigurationCls::onCopy(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::copy, value!);
    _onCopy = value;
}

VoidCallback SemanticsConfigurationCls::onCut() {
    return _onCut;
}

void SemanticsConfigurationCls::onCut(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::cut, value!);
    _onCut = value;
}

VoidCallback SemanticsConfigurationCls::onPaste() {
    return _onPaste;
}

void SemanticsConfigurationCls::onPaste(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::paste, value!);
    _onPaste = value;
}

VoidCallback SemanticsConfigurationCls::onShowOnScreen() {
    return _onShowOnScreen;
}

void SemanticsConfigurationCls::onShowOnScreen(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::showOnScreen, value!);
    _onShowOnScreen = value;
}

MoveCursorHandler SemanticsConfigurationCls::onMoveCursorForwardByCharacter() {
    return _onMoveCursorForwardByCharacter;
}

void SemanticsConfigurationCls::onMoveCursorForwardByCharacter(MoveCursorHandler value) {
    assert(value != nullptr);
    _addAction(SemanticsActionCls::moveCursorForwardByCharacter, [=] (Object args) {
        bool extendSelection = as<bool>(args!);
        value!(extendSelection);
    });
    _onMoveCursorForwardByCharacter = value;
}

MoveCursorHandler SemanticsConfigurationCls::onMoveCursorBackwardByCharacter() {
    return _onMoveCursorBackwardByCharacter;
}

void SemanticsConfigurationCls::onMoveCursorBackwardByCharacter(MoveCursorHandler value) {
    assert(value != nullptr);
    _addAction(SemanticsActionCls::moveCursorBackwardByCharacter, [=] (Object args) {
        bool extendSelection = as<bool>(args!);
        value!(extendSelection);
    });
    _onMoveCursorBackwardByCharacter = value;
}

MoveCursorHandler SemanticsConfigurationCls::onMoveCursorForwardByWord() {
    return _onMoveCursorForwardByWord;
}

void SemanticsConfigurationCls::onMoveCursorForwardByWord(MoveCursorHandler value) {
    assert(value != nullptr);
    _addAction(SemanticsActionCls::moveCursorForwardByWord, [=] (Object args) {
        bool extendSelection = as<bool>(args!);
        value!(extendSelection);
    });
    _onMoveCursorForwardByCharacter = value;
}

MoveCursorHandler SemanticsConfigurationCls::onMoveCursorBackwardByWord() {
    return _onMoveCursorBackwardByWord;
}

void SemanticsConfigurationCls::onMoveCursorBackwardByWord(MoveCursorHandler value) {
    assert(value != nullptr);
    _addAction(SemanticsActionCls::moveCursorBackwardByWord, [=] (Object args) {
        bool extendSelection = as<bool>(args!);
        value!(extendSelection);
    });
    _onMoveCursorBackwardByCharacter = value;
}

SetSelectionHandler SemanticsConfigurationCls::onSetSelection() {
    return _onSetSelection;
}

void SemanticsConfigurationCls::onSetSelection(SetSelectionHandler value) {
    assert(value != nullptr);
    _addAction(SemanticsActionCls::setSelection, [=] (Object args) {
        assert(args != nullptr && is<Map<any, any>>(args));
        Map<String, int> selection = (as<Map<dynamic, dynamic>>(args!))-><String, int>cast();
        assert(selection != nullptr && selection[__s("base")] != nullptr && selection[__s("extent")] != nullptr);
        value!(make<TextSelectionCls>(selection[__s("base")]!, selection[__s("extent")]!));
    });
    _onSetSelection = value;
}

SetTextHandler SemanticsConfigurationCls::onSetText() {
    return _onSetText;
}

void SemanticsConfigurationCls::onSetText(SetTextHandler value) {
    assert(value != nullptr);
    _addAction(SemanticsActionCls::setText, [=] (Object args) {
        assert(args != nullptr && is<String>(args));
        String text = as<String>(args!);
        value!(text);
    });
    _onSetText = value;
}

VoidCallback SemanticsConfigurationCls::onDidGainAccessibilityFocus() {
    return _onDidGainAccessibilityFocus;
}

void SemanticsConfigurationCls::onDidGainAccessibilityFocus(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::didGainAccessibilityFocus, value!);
    _onDidGainAccessibilityFocus = value;
}

VoidCallback SemanticsConfigurationCls::onDidLoseAccessibilityFocus() {
    return _onDidLoseAccessibilityFocus;
}

void SemanticsConfigurationCls::onDidLoseAccessibilityFocus(VoidCallback value) {
    _addArgumentlessAction(SemanticsActionCls::didLoseAccessibilityFocus, value!);
    _onDidLoseAccessibilityFocus = value;
}

SemanticsActionHandler SemanticsConfigurationCls::getActionHandler(SemanticsAction action) {
    return _actions[action];
}

SemanticsSortKey SemanticsConfigurationCls::sortKey() {
    return _sortKey;
}

void SemanticsConfigurationCls::sortKey(SemanticsSortKey value) {
    assert(value != nullptr);
    _sortKey = value;
    _hasBeenAnnotated = true;
}

int SemanticsConfigurationCls::indexInParent() {
    return _indexInParent;
}

void SemanticsConfigurationCls::indexInParent(int value) {
    _indexInParent = value;
    _hasBeenAnnotated = true;
}

int SemanticsConfigurationCls::scrollChildCount() {
    return _scrollChildCount;
}

void SemanticsConfigurationCls::scrollChildCount(int value) {
    if (value == scrollChildCount()) {
        return;
    }
    _scrollChildCount = value;
    _hasBeenAnnotated = true;
}

int SemanticsConfigurationCls::scrollIndex() {
    return _scrollIndex;
}

void SemanticsConfigurationCls::scrollIndex(int value) {
    if (value == scrollIndex()) {
        return;
    }
    _scrollIndex = value;
    _hasBeenAnnotated = true;
}

int SemanticsConfigurationCls::platformViewId() {
    return _platformViewId;
}

void SemanticsConfigurationCls::platformViewId(int value) {
    if (value == platformViewId()) {
        return;
    }
    _platformViewId = value;
    _hasBeenAnnotated = true;
}

int SemanticsConfigurationCls::maxValueLength() {
    return _maxValueLength;
}

void SemanticsConfigurationCls::maxValueLength(int value) {
    if (value == maxValueLength()) {
        return;
    }
    _maxValueLength = value;
    _hasBeenAnnotated = true;
}

int SemanticsConfigurationCls::currentValueLength() {
    return _currentValueLength;
}

void SemanticsConfigurationCls::currentValueLength(int value) {
    if (value == currentValueLength()) {
        return;
    }
    _currentValueLength = value;
    _hasBeenAnnotated = true;
}

bool SemanticsConfigurationCls::isMergingSemanticsOfDescendants() {
    return _isMergingSemanticsOfDescendants;
}

void SemanticsConfigurationCls::isMergingSemanticsOfDescendants(bool value) {
    assert(isSemanticBoundary());
    _isMergingSemanticsOfDescendants = value;
    _hasBeenAnnotated = true;
}

Map<CustomSemanticsAction, VoidCallback> SemanticsConfigurationCls::customSemanticsActions() {
    return _customSemanticsActions;
}

void SemanticsConfigurationCls::customSemanticsActions(Map<CustomSemanticsAction, VoidCallback> value) {
    _hasBeenAnnotated = true;
    _actionsAsBits |= SemanticsActionCls::customAction->index;
    _customSemanticsActions = value;
    _actions[SemanticsActionCls::customAction] = _onCustomSemanticsAction;
}

String SemanticsConfigurationCls::label() {
    return _attributedLabel->stringValue;
}

void SemanticsConfigurationCls::label(String label) {
    assert(label != nullptr);
    _attributedLabel = make<AttributedStringCls>(label);
    _hasBeenAnnotated = true;
}

AttributedString SemanticsConfigurationCls::attributedLabel() {
    return _attributedLabel;
}

void SemanticsConfigurationCls::attributedLabel(AttributedString attributedLabel) {
    _attributedLabel = attributedLabel;
    _hasBeenAnnotated = true;
}

String SemanticsConfigurationCls::value() {
    return _attributedValue->stringValue;
}

void SemanticsConfigurationCls::value(String value) {
    assert(value != nullptr);
    _attributedValue = make<AttributedStringCls>(value);
    _hasBeenAnnotated = true;
}

AttributedString SemanticsConfigurationCls::attributedValue() {
    return _attributedValue;
}

void SemanticsConfigurationCls::attributedValue(AttributedString attributedValue) {
    _attributedValue = attributedValue;
    _hasBeenAnnotated = true;
}

String SemanticsConfigurationCls::increasedValue() {
    return _attributedIncreasedValue->stringValue;
}

void SemanticsConfigurationCls::increasedValue(String increasedValue) {
    assert(increasedValue != nullptr);
    _attributedIncreasedValue = make<AttributedStringCls>(increasedValue);
    _hasBeenAnnotated = true;
}

AttributedString SemanticsConfigurationCls::attributedIncreasedValue() {
    return _attributedIncreasedValue;
}

void SemanticsConfigurationCls::attributedIncreasedValue(AttributedString attributedIncreasedValue) {
    _attributedIncreasedValue = attributedIncreasedValue;
    _hasBeenAnnotated = true;
}

String SemanticsConfigurationCls::decreasedValue() {
    return _attributedDecreasedValue->stringValue;
}

void SemanticsConfigurationCls::decreasedValue(String decreasedValue) {
    assert(decreasedValue != nullptr);
    _attributedDecreasedValue = make<AttributedStringCls>(decreasedValue);
    _hasBeenAnnotated = true;
}

AttributedString SemanticsConfigurationCls::attributedDecreasedValue() {
    return _attributedDecreasedValue;
}

void SemanticsConfigurationCls::attributedDecreasedValue(AttributedString attributedDecreasedValue) {
    _attributedDecreasedValue = attributedDecreasedValue;
    _hasBeenAnnotated = true;
}

String SemanticsConfigurationCls::hint() {
    return _attributedHint->stringValue;
}

void SemanticsConfigurationCls::hint(String hint) {
    assert(hint != nullptr);
    _attributedHint = make<AttributedStringCls>(hint);
    _hasBeenAnnotated = true;
}

AttributedString SemanticsConfigurationCls::attributedHint() {
    return _attributedHint;
}

void SemanticsConfigurationCls::attributedHint(AttributedString attributedHint) {
    _attributedHint = attributedHint;
    _hasBeenAnnotated = true;
}

String SemanticsConfigurationCls::tooltip() {
    return _tooltip;
}

void SemanticsConfigurationCls::tooltip(String tooltip) {
    _tooltip = tooltip;
    _hasBeenAnnotated = true;
}

SemanticsHintOverrides SemanticsConfigurationCls::hintOverrides() {
    return _hintOverrides;
}

void SemanticsConfigurationCls::hintOverrides(SemanticsHintOverrides value) {
    if (value == nullptr) {
        return;
    }
    _hintOverrides = value;
    _hasBeenAnnotated = true;
}

double SemanticsConfigurationCls::elevation() {
    return _elevation;
}

void SemanticsConfigurationCls::elevation(double value) {
    assert(value != nullptr && value >= 0.0);
    if (value == _elevation) {
        return;
    }
    _elevation = value;
    _hasBeenAnnotated = true;
}

double SemanticsConfigurationCls::thickness() {
    return _thickness;
}

void SemanticsConfigurationCls::thickness(double value) {
    assert(value != nullptr && value >= 0.0);
    if (value == _thickness) {
        return;
    }
    _thickness = value;
    _hasBeenAnnotated = true;
}

bool SemanticsConfigurationCls::scopesRoute() {
    return _hasFlag(SemanticsFlagCls::scopesRoute);
}

void SemanticsConfigurationCls::scopesRoute(bool value) {
    _setFlag(SemanticsFlagCls::scopesRoute, value);
}

bool SemanticsConfigurationCls::namesRoute() {
    return _hasFlag(SemanticsFlagCls::namesRoute);
}

void SemanticsConfigurationCls::namesRoute(bool value) {
    _setFlag(SemanticsFlagCls::namesRoute, value);
}

bool SemanticsConfigurationCls::isImage() {
    return _hasFlag(SemanticsFlagCls::isImage);
}

void SemanticsConfigurationCls::isImage(bool value) {
    _setFlag(SemanticsFlagCls::isImage, value);
}

bool SemanticsConfigurationCls::liveRegion() {
    return _hasFlag(SemanticsFlagCls::isLiveRegion);
}

void SemanticsConfigurationCls::liveRegion(bool value) {
    _setFlag(SemanticsFlagCls::isLiveRegion, value);
}

TextDirection SemanticsConfigurationCls::textDirection() {
    return _textDirection;
}

void SemanticsConfigurationCls::textDirection(TextDirection textDirection) {
    _textDirection = textDirection;
    _hasBeenAnnotated = true;
}

bool SemanticsConfigurationCls::isSelected() {
    return _hasFlag(SemanticsFlagCls::isSelected);
}

void SemanticsConfigurationCls::isSelected(bool value) {
    _setFlag(SemanticsFlagCls::isSelected, value);
}

bool SemanticsConfigurationCls::isEnabled() {
    return _hasFlag(SemanticsFlagCls::hasEnabledState)? _hasFlag(SemanticsFlagCls::isEnabled) : nullptr;
}

void SemanticsConfigurationCls::isEnabled(bool value) {
    _setFlag(SemanticsFlagCls::hasEnabledState, true);
    _setFlag(SemanticsFlagCls::isEnabled, value!);
}

bool SemanticsConfigurationCls::isChecked() {
    return _hasFlag(SemanticsFlagCls::hasCheckedState)? _hasFlag(SemanticsFlagCls::isChecked) : nullptr;
}

void SemanticsConfigurationCls::isChecked(bool value) {
    _setFlag(SemanticsFlagCls::hasCheckedState, true);
    _setFlag(SemanticsFlagCls::isChecked, value!);
}

bool SemanticsConfigurationCls::isToggled() {
    return _hasFlag(SemanticsFlagCls::hasToggledState)? _hasFlag(SemanticsFlagCls::isToggled) : nullptr;
}

void SemanticsConfigurationCls::isToggled(bool value) {
    _setFlag(SemanticsFlagCls::hasToggledState, true);
    _setFlag(SemanticsFlagCls::isToggled, value!);
}

bool SemanticsConfigurationCls::isInMutuallyExclusiveGroup() {
    return _hasFlag(SemanticsFlagCls::isInMutuallyExclusiveGroup);
}

void SemanticsConfigurationCls::isInMutuallyExclusiveGroup(bool value) {
    _setFlag(SemanticsFlagCls::isInMutuallyExclusiveGroup, value);
}

bool SemanticsConfigurationCls::isFocusable() {
    return _hasFlag(SemanticsFlagCls::isFocusable);
}

void SemanticsConfigurationCls::isFocusable(bool value) {
    _setFlag(SemanticsFlagCls::isFocusable, value);
}

bool SemanticsConfigurationCls::isFocused() {
    return _hasFlag(SemanticsFlagCls::isFocused);
}

void SemanticsConfigurationCls::isFocused(bool value) {
    _setFlag(SemanticsFlagCls::isFocused, value);
}

bool SemanticsConfigurationCls::isButton() {
    return _hasFlag(SemanticsFlagCls::isButton);
}

void SemanticsConfigurationCls::isButton(bool value) {
    _setFlag(SemanticsFlagCls::isButton, value);
}

bool SemanticsConfigurationCls::isLink() {
    return _hasFlag(SemanticsFlagCls::isLink);
}

void SemanticsConfigurationCls::isLink(bool value) {
    _setFlag(SemanticsFlagCls::isLink, value);
}

bool SemanticsConfigurationCls::isHeader() {
    return _hasFlag(SemanticsFlagCls::isHeader);
}

void SemanticsConfigurationCls::isHeader(bool value) {
    _setFlag(SemanticsFlagCls::isHeader, value);
}

bool SemanticsConfigurationCls::isSlider() {
    return _hasFlag(SemanticsFlagCls::isSlider);
}

void SemanticsConfigurationCls::isSlider(bool value) {
    _setFlag(SemanticsFlagCls::isSlider, value);
}

bool SemanticsConfigurationCls::isKeyboardKey() {
    return _hasFlag(SemanticsFlagCls::isKeyboardKey);
}

void SemanticsConfigurationCls::isKeyboardKey(bool value) {
    _setFlag(SemanticsFlagCls::isKeyboardKey, value);
}

bool SemanticsConfigurationCls::isHidden() {
    return _hasFlag(SemanticsFlagCls::isHidden);
}

void SemanticsConfigurationCls::isHidden(bool value) {
    _setFlag(SemanticsFlagCls::isHidden, value);
}

bool SemanticsConfigurationCls::isTextField() {
    return _hasFlag(SemanticsFlagCls::isTextField);
}

void SemanticsConfigurationCls::isTextField(bool value) {
    _setFlag(SemanticsFlagCls::isTextField, value);
}

bool SemanticsConfigurationCls::isReadOnly() {
    return _hasFlag(SemanticsFlagCls::isReadOnly);
}

void SemanticsConfigurationCls::isReadOnly(bool value) {
    _setFlag(SemanticsFlagCls::isReadOnly, value);
}

bool SemanticsConfigurationCls::isObscured() {
    return _hasFlag(SemanticsFlagCls::isObscured);
}

void SemanticsConfigurationCls::isObscured(bool value) {
    _setFlag(SemanticsFlagCls::isObscured, value);
}

bool SemanticsConfigurationCls::isMultiline() {
    return _hasFlag(SemanticsFlagCls::isMultiline);
}

void SemanticsConfigurationCls::isMultiline(bool value) {
    _setFlag(SemanticsFlagCls::isMultiline, value);
}

bool SemanticsConfigurationCls::hasImplicitScrolling() {
    return _hasFlag(SemanticsFlagCls::hasImplicitScrolling);
}

void SemanticsConfigurationCls::hasImplicitScrolling(bool value) {
    _setFlag(SemanticsFlagCls::hasImplicitScrolling, value);
}

TextSelection SemanticsConfigurationCls::textSelection() {
    return _textSelection;
}

void SemanticsConfigurationCls::textSelection(TextSelection value) {
    assert(value != nullptr);
    _textSelection = value;
    _hasBeenAnnotated = true;
}

double SemanticsConfigurationCls::scrollPosition() {
    return _scrollPosition;
}

void SemanticsConfigurationCls::scrollPosition(double value) {
    assert(value != nullptr);
    _scrollPosition = value;
    _hasBeenAnnotated = true;
}

double SemanticsConfigurationCls::scrollExtentMax() {
    return _scrollExtentMax;
}

void SemanticsConfigurationCls::scrollExtentMax(double value) {
    assert(value != nullptr);
    _scrollExtentMax = value;
    _hasBeenAnnotated = true;
}

double SemanticsConfigurationCls::scrollExtentMin() {
    return _scrollExtentMin;
}

void SemanticsConfigurationCls::scrollExtentMin(double value) {
    assert(value != nullptr);
    _scrollExtentMin = value;
    _hasBeenAnnotated = true;
}

Iterable<SemanticsTag> SemanticsConfigurationCls::tagsForChildren() {
    return _tagsForChildren;
}

void SemanticsConfigurationCls::addTagForChildren(SemanticsTag tag) {
    _tagsForChildren |= makeSet();
    _tagsForChildren!->add(tag);
}

bool SemanticsConfigurationCls::isCompatibleWith(SemanticsConfiguration other) {
    if (other == nullptr || !other->hasBeenAnnotated() || !hasBeenAnnotated()) {
        return true;
    }
    if (_actionsAsBits & other->_actionsAsBits != 0) {
        return false;
    }
    if ((_flags & other->_flags) != 0) {
        return false;
    }
    if (_platformViewId != nullptr && other->_platformViewId != nullptr) {
        return false;
    }
    if (_maxValueLength != nullptr && other->_maxValueLength != nullptr) {
        return false;
    }
    if (_currentValueLength != nullptr && other->_currentValueLength != nullptr) {
        return false;
    }
    if (_attributedValue != nullptr && _attributedValue->stringValue->isNotEmpty() && other->_attributedValue != nullptr && other->_attributedValue->stringValue->isNotEmpty()) {
        return false;
    }
    return true;
}

void SemanticsConfigurationCls::absorb(SemanticsConfiguration child) {
    assert(!explicitChildNodes);
    if (!child->hasBeenAnnotated()) {
        return;
    }
    _actions->addAll(child->_actions);
    _customSemanticsActions->addAll(child->_customSemanticsActions);
    _actionsAsBits |= child->_actionsAsBits;
    _flags |= child->_flags;
    _textSelection |= child->_textSelection;
    _scrollPosition |= child->_scrollPosition;
    _scrollExtentMax |= child->_scrollExtentMax;
    _scrollExtentMin |= child->_scrollExtentMin;
    _hintOverrides |= child->_hintOverrides;
    _indexInParent |= child->indexInParent();
    _scrollIndex |= child->_scrollIndex;
    _scrollChildCount |= child->_scrollChildCount;
    _platformViewId |= child->_platformViewId;
    _maxValueLength |= child->_maxValueLength;
    _currentValueLength |= child->_currentValueLength;
    textDirection() |= child->textDirection();
    _sortKey |= child->_sortKey;
    _attributedLabel = _concatAttributedString(_attributedLabel, textDirection(), child->_attributedLabel, child->textDirection());
    if (_attributedValue == nullptr || _attributedValue->stringValue == __s("")) {
        _attributedValue = child->_attributedValue;
    }
    if (_attributedIncreasedValue == nullptr || _attributedIncreasedValue->stringValue == __s("")) {
        _attributedIncreasedValue = child->_attributedIncreasedValue;
    }
    if (_attributedDecreasedValue == nullptr || _attributedDecreasedValue->stringValue == __s("")) {
        _attributedDecreasedValue = child->_attributedDecreasedValue;
    }
    _attributedHint = _concatAttributedString(_attributedHint, textDirection(), child->_attributedHint, child->textDirection());
    if (_tooltip == __s("")) {
        _tooltip = child->_tooltip;
    }
    _thickness = math->max(_thickness, child->_thickness + child->_elevation);
    _hasBeenAnnotated = _hasBeenAnnotated || child->_hasBeenAnnotated;
}

SemanticsConfiguration SemanticsConfigurationCls::copy() {
    auto _c1 = make<SemanticsConfigurationCls>();_c1._isSemanticBoundary = auto _c2 = _isSemanticBoundary;_c2.explicitChildNodes = auto _c3 = explicitChildNodes;_c3.isBlockingSemanticsOfPreviouslyPaintedNodes = auto _c4 = isBlockingSemanticsOfPreviouslyPaintedNodes;_c4._hasBeenAnnotated = auto _c5 = _hasBeenAnnotated;_c5._isMergingSemanticsOfDescendants = auto _c6 = _isMergingSemanticsOfDescendants;_c6._textDirection = auto _c7 = _textDirection;_c7._sortKey = auto _c8 = _sortKey;_c8._attributedLabel = auto _c9 = _attributedLabel;_c9._attributedIncreasedValue = auto _c10 = _attributedIncreasedValue;_c10._attributedValue = auto _c11 = _attributedValue;_c11._attributedDecreasedValue = auto _c12 = _attributedDecreasedValue;_c12._attributedHint = auto _c13 = _attributedHint;_c13._hintOverrides = auto _c14 = _hintOverrides;_c14._tooltip = auto _c15 = _tooltip;_c15._elevation = auto _c16 = _elevation;_c16._thickness = auto _c17 = _thickness;_c17._flags = auto _c18 = _flags;_c18._tagsForChildren = auto _c19 = _tagsForChildren;_c19._textSelection = auto _c20 = _textSelection;_c20._scrollPosition = auto _c21 = _scrollPosition;_c21._scrollExtentMax = auto _c22 = _scrollExtentMax;_c22._scrollExtentMin = auto _c23 = _scrollExtentMin;_c23._actionsAsBits = auto _c24 = _actionsAsBits;_c24._indexInParent = auto _c25 = indexInParent();_c25._scrollIndex = auto _c26 = _scrollIndex;_c26._scrollChildCount = auto _c27 = _scrollChildCount;_c27._platformViewId = auto _c28 = _platformViewId;_c28._maxValueLength = auto _c29 = _maxValueLength;_c29._currentValueLength = auto _c30 = _currentValueLength;_c30.auto _c31 = _actions->addAll(_actions);_c31._customSemanticsActions->addAll(_customSemanticsActions);_c31;_c30;_c29;_c28;_c27;_c26;_c25;_c24;_c23;_c22;_c21;_c20;_c19;_c18;_c17;_c16;_c15;_c14;_c13;_c12;_c11;_c10;_c9;_c8;_c7;_c6;_c5;_c4;_c3;_c2;return _c1;
}

void SemanticsConfigurationCls::_addAction(SemanticsAction action, SemanticsActionHandler handler) {
    assert(handler != nullptr);
    _actions[action] = handler;
    _actionsAsBits |= action->index;
    _hasBeenAnnotated = true;
}

void SemanticsConfigurationCls::_addArgumentlessAction(SemanticsAction action, VoidCallback handler) {
    assert(handler != nullptr);
    _addAction(action, [=] (Object args) {
        assert(args == nullptr);
        handler();
    });
}

void SemanticsConfigurationCls::_onCustomSemanticsAction(Object args) {
    CustomSemanticsAction action = CustomSemanticsActionCls->getAction(as<int>(args!));
    if (action == nullptr) {
        return;
    }
    VoidCallback callback = _customSemanticsActions[action];
    if (callback != nullptr) {
        callback();
    }
}

void SemanticsConfigurationCls::_setFlag(SemanticsFlag flag, bool value) {
    if (value) {
        _flags |= flag->index;
    } else {
        _flags &= ~flag->index;
    }
    _hasBeenAnnotated = true;
}

bool SemanticsConfigurationCls::_hasFlag(SemanticsFlag flag) {
    return (_flags & flag->index) != 0;
}

AttributedString _concatAttributedString(AttributedString otherAttributedString, TextDirection otherTextDirection, AttributedString thisAttributedString, TextDirection thisTextDirection) {
    if (otherAttributedString->stringValue->isEmpty()) {
        return thisAttributedString;
    }
    if (thisTextDirection != otherTextDirection && otherTextDirection != nullptr) {
        ;
    }
    if (thisAttributedString->stringValue->isEmpty()) {
        return otherAttributedString;
    }
    return thisAttributedString + make<AttributedStringCls>(__s("\n")) + otherAttributedString;
}

int SemanticsSortKeyCls::compareTo(SemanticsSortKey other) {
    assert(runtimeType == other->runtimeType, __s("Semantics sort keys can only be compared to other sort keys of the same type."));
    if (name == other->name) {
        return doCompare(other);
    }
    if (name == nullptr && other->name != nullptr) {
        return -1;
    } else {
        if (name != nullptr && other->name == nullptr) {
        return 1;
    }
;
    }    return name!->compareTo(other->name!);
}

void SemanticsSortKeyCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<StringPropertyCls>(__s("name"), name, nullptr));
}

OrdinalSortKeyCls::OrdinalSortKeyCls(double order, String name) {
    {
        assert(order != nullptr);
        assert(order != double->nan);
        assert(order > double->negativeInfinity);
        assert( < double->infinity);
    }
}

int OrdinalSortKeyCls::doCompare(OrdinalSortKey other) {
    if (other->order == nullptr || order == nullptr || other->order == order) {
        return 0;
    }
    return order->compareTo(other->order);
}

void OrdinalSortKeyCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<DoublePropertyCls>(__s("order"), order, nullptr));
}
