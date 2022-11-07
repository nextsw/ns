#include "semantics.hpp"
String SemanticsTag::toString() {
    return "${objectRuntimeType(this, 'SemanticsTag')}($name)";
}

CustomSemanticsAction::CustomSemanticsAction(String label) {
    {
        assert(label != nullptr);
        assert(label != "");
        hint = nullptr;
        action = nullptr;
    }
}

void CustomSemanticsAction::overridingAction(SemanticsAction action, String hint)

int CustomSemanticsAction::hashCode() {
    return Object.hash(label, hint, action);
}

bool CustomSemanticsAction::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is CustomSemanticsAction && other.label == label && other.hint == hint && other.action == action;
}

String CustomSemanticsAction::toString() {
    return "CustomSemanticsAction(${_ids[this]}, label:$label, hint:$hint, action:$action)";
}

int CustomSemanticsAction::getIdentifier(CustomSemanticsAction action) {
    int result = _ids[action];
    if (result == nullptr) {
        result = _nextId++;
        _ids[action] = result;
        _actions[result] = action;
    }
    return result;
}

CustomSemanticsAction CustomSemanticsAction::getAction(int id) {
    return _actions[id];
}

AttributedString::AttributedString(List<StringAttribute> attributes, String string) {
    {
        assert(string.isNotEmpty || attributes.isEmpty);
        assert(());
    }
}

AttributedString AttributedString::+(AttributedString other) {
    if (string.isEmpty) {
        return other;
    }
    if (other.string.isEmpty) {
        return this;
    }
    String newString = string + other.string;
    List<StringAttribute> newAttributes = <StringAttribute>of(attributes);
    if (other.attributes.isNotEmpty) {
        int offset = string.length;
        for (StringAttribute attribute : other.attributes) {
            TextRange newRange = TextRange(attribute.range.start + offset, attribute.range.end + offset);
            StringAttribute adjustedAttribute = attribute.copy(newRange);
            newAttributes.add(adjustedAttribute);
        }
    }
    return AttributedString(newStringnewAttributes);
}

bool AttributedString::==(Object other) {
    return other.runtimeType == runtimeType && other is AttributedString && other.string == string && <StringAttribute>listEquals(other.attributes, attributes);
}

int AttributedString::hashCode() {
    return Object.hash(string, attributes);
}

String AttributedString::toString() {
    return "${objectRuntimeType(this, 'AttributedString')}('$string', attributes: $attributes)";
}

AttributedStringProperty::AttributedStringProperty(Unknown, Unknown, Unknown, String name, Unknown, bool showWhenEmpty, Unknown) {
    {
        assert(showName != nullptr);
        assert(level != nullptr);
    }
}

bool AttributedStringProperty::isInteresting() {
    return super.isInteresting && (showWhenEmpty || (value != nullptr && value!.string.isNotEmpty));
}

String AttributedStringProperty::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value == nullptr) {
        return "null";
    }
    String text = value!.string;
    if (parentConfiguration != nullptr && !parentConfiguration.lineBreakProperties) {
        text = text.replaceAll("\n", "\n");
    }
    if (value!.attributes.isEmpty) {
        return ""$text"";
    }
    return ""$text" ${value!.attributes}";
}

SemanticsData::SemanticsData(int actions, AttributedString attributedDecreasedValue, AttributedString attributedHint, AttributedString attributedIncreasedValue, AttributedString attributedLabel, AttributedString attributedValue, int currentValueLength, List<int> customSemanticsActionIds, double elevation, int flags, int maxValueLength, int platformViewId, Rect rect, int scrollChildCount, double scrollExtentMax, double scrollExtentMin, int scrollIndex, double scrollPosition, Set<SemanticsTag> tags, TextDirection textDirection, TextSelection textSelection, double thickness, String tooltip, Matrix4 transform) {
    {
        assert(flags != nullptr);
        assert(actions != nullptr);
        assert(attributedLabel != nullptr);
        assert(attributedValue != nullptr);
        assert(attributedDecreasedValue != nullptr);
        assert(attributedIncreasedValue != nullptr);
        assert(attributedHint != nullptr);
        assert(tooltip == "" || textDirection != nullptr, "A SemanticsData object with tooltip "$tooltip" had a null textDirection.");
        assert(attributedLabel.string == "" || textDirection != nullptr, "A SemanticsData object with label "${attributedLabel.string}" had a null textDirection.");
        assert(attributedValue.string == "" || textDirection != nullptr, "A SemanticsData object with value "${attributedValue.string}" had a null textDirection.");
        assert(attributedDecreasedValue.string == "" || textDirection != nullptr, "A SemanticsData object with decreasedValue "${attributedDecreasedValue.string}" had a null textDirection.");
        assert(attributedIncreasedValue.string == "" || textDirection != nullptr, "A SemanticsData object with increasedValue "${attributedIncreasedValue.string}" had a null textDirection.");
        assert(attributedHint.string == "" || textDirection != nullptr, "A SemanticsData object with hint "${attributedHint.string}" had a null textDirection.");
        assert(rect != nullptr);
    }
}

String SemanticsData::label() {
    return attributedLabel.string;
}

String SemanticsData::value() {
    return attributedValue.string;
}

String SemanticsData::increasedValue() {
    return attributedIncreasedValue.string;
}

String SemanticsData::decreasedValue() {
    return attributedDecreasedValue.string;
}

String SemanticsData::hint() {
    return attributedHint.string;
}

bool SemanticsData::hasFlag(SemanticsFlag flag) {
    return (flags & flag.index) != 0;
}

bool SemanticsData::hasAction(SemanticsAction action) {
    return (actions & action.index) != 0;
}

String SemanticsData::toStringShort() {
    return objectRuntimeType(this, "SemanticsData");
}

void SemanticsData::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Rect>DiagnosticsProperty("rect", rectfalse));
    properties.add(TransformProperty("transform", transformfalse, nullptr));
    properties.add(DoubleProperty("elevation", elevation0.0));
    properties.add(DoubleProperty("thickness", thickness0.0));
    List<String> actionSummary = ;
    List<String> customSemanticsActionSummary = customSemanticsActionIds!.<String>map().toList();
    properties.add(<String>IterableProperty("actions", actionSummarynullptr));
    properties.add(<String>IterableProperty("customActions", customSemanticsActionSummarynullptr));
    List<String> flagSummary = ;
    properties.add(<String>IterableProperty("flags", flagSummarynullptr));
    properties.add(AttributedStringProperty("label", attributedLabel));
    properties.add(AttributedStringProperty("value", attributedValue));
    properties.add(AttributedStringProperty("increasedValue", attributedIncreasedValue));
    properties.add(AttributedStringProperty("decreasedValue", attributedDecreasedValue));
    properties.add(AttributedStringProperty("hint", attributedHint));
    properties.add(StringProperty("tooltip", tooltip""));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
    if (textSelection?.isValid ?? false) {
        properties.add(MessageProperty("textSelection", "[${textSelection!.start}, ${textSelection!.end}]"));
    }
    properties.add(IntProperty("platformViewId", platformViewIdnullptr));
    properties.add(IntProperty("maxValueLength", maxValueLengthnullptr));
    properties.add(IntProperty("currentValueLength", currentValueLengthnullptr));
    properties.add(IntProperty("scrollChildren", scrollChildCountnullptr));
    properties.add(IntProperty("scrollIndex", scrollIndexnullptr));
    properties.add(DoubleProperty("scrollExtentMin", scrollExtentMinnullptr));
    properties.add(DoubleProperty("scrollPosition", scrollPositionnullptr));
    properties.add(DoubleProperty("scrollExtentMax", scrollExtentMaxnullptr));
}

bool SemanticsData::==(Object other) {
    return other is SemanticsData && other.flags == flags && other.actions == actions && other.attributedLabel == attributedLabel && other.attributedValue == attributedValue && other.attributedIncreasedValue == attributedIncreasedValue && other.attributedDecreasedValue == attributedDecreasedValue && other.attributedHint == attributedHint && other.tooltip == tooltip && other.textDirection == textDirection && other.rect == rect && setEquals(other.tags, tags) && other.scrollChildCount == scrollChildCount && other.scrollIndex == scrollIndex && other.textSelection == textSelection && other.scrollPosition == scrollPosition && other.scrollExtentMax == scrollExtentMax && other.scrollExtentMin == scrollExtentMin && other.platformViewId == platformViewId && other.maxValueLength == maxValueLength && other.currentValueLength == currentValueLength && other.transform == transform && other.elevation == elevation && other.thickness == thickness && _sortedListsEqual(other.customSemanticsActionIds, customSemanticsActionIds);
}

int SemanticsData::hashCode() {
    return Object.hash(flags, actions, attributedLabel, attributedValue, attributedIncreasedValue, attributedDecreasedValue, attributedHint, tooltip, textDirection, rect, tags, textSelection, scrollChildCount, scrollIndex, scrollPosition, scrollExtentMax, scrollExtentMin, platformViewId, maxValueLength, Object.hash(currentValueLength, transform, elevation, thickness, customSemanticsActionIds == nullptr? nullptr : Object.hashAll(customSemanticsActionIds!)));
}

bool SemanticsData::_sortedListsEqual(List<int> left, List<int> right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }
    if (left != nullptr && right != nullptr) {
        if (left.length != right.length) {
            return false;
        }
        for (;  < left.length; i++) {
            if (left[i] != right[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

List<DiagnosticsNode> _SemanticsDiagnosticableNode::getChildren() {
    return value.debugDescribeChildren(childOrder);
}

SemanticsHintOverrides::SemanticsHintOverrides(String onLongPressHint, String onTapHint) {
    {
        assert(onTapHint != "");
        assert(onLongPressHint != "");
    }
}

bool SemanticsHintOverrides::isNotEmpty() {
    return onTapHint != nullptr || onLongPressHint != nullptr;
}

int SemanticsHintOverrides::hashCode() {
    return Object.hash(onTapHint, onLongPressHint);
}

bool SemanticsHintOverrides::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is SemanticsHintOverrides && other.onTapHint == onTapHint && other.onLongPressHint == onLongPressHint;
}

void SemanticsHintOverrides::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(StringProperty("onTapHint", onTapHintnullptr));
    properties.add(StringProperty("onLongPressHint", onLongPressHintnullptr));
}

SemanticsProperties::SemanticsProperties(AttributedString attributedDecreasedValue, AttributedString attributedHint, AttributedString attributedIncreasedValue, AttributedString attributedLabel, AttributedString attributedValue, bool button, bool checked, int currentValueLength, Map<CustomSemanticsAction, VoidCallback> customSemanticsActions, String decreasedValue, bool enabled, bool focusable, bool focused, bool header, bool hidden, String hint, SemanticsHintOverrides hintOverrides, bool image, bool inMutuallyExclusiveGroup, String increasedValue, bool keyboardKey, String label, bool link, bool liveRegion, int maxValueLength, bool multiline, bool namesRoute, bool obscured, VoidCallback onCopy, VoidCallback onCut, VoidCallback onDecrease, VoidCallback onDidGainAccessibilityFocus, VoidCallback onDidLoseAccessibilityFocus, VoidCallback onDismiss, VoidCallback onIncrease, VoidCallback onLongPress, MoveCursorHandler onMoveCursorBackwardByCharacter, MoveCursorHandler onMoveCursorBackwardByWord, MoveCursorHandler onMoveCursorForwardByCharacter, MoveCursorHandler onMoveCursorForwardByWord, VoidCallback onPaste, VoidCallback onScrollDown, VoidCallback onScrollLeft, VoidCallback onScrollRight, VoidCallback onScrollUp, SetSelectionHandler onSetSelection, SetTextHandler onSetText, VoidCallback onTap, bool readOnly, bool scopesRoute, bool selected, bool slider, SemanticsSortKey sortKey, SemanticsTag tagForChildren, TextDirection textDirection, bool textField, bool toggled, String tooltip, String value) {
    {
        assert(label == nullptr || attributedLabel == nullptr, "Only one of label or attributedLabel should be provided");
        assert(value == nullptr || attributedValue == nullptr, "Only one of value or attributedValue should be provided");
        assert(increasedValue == nullptr || attributedIncreasedValue == nullptr, "Only one of increasedValue or attributedIncreasedValue should be provided");
        assert(decreasedValue == nullptr || attributedDecreasedValue == nullptr, "Only one of decreasedValue or attributedDecreasedValue should be provided");
        assert(hint == nullptr || attributedHint == nullptr, "Only one of hint or attributedHint should be provided");
    }
}

void SemanticsProperties::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<bool>DiagnosticsProperty("checked", checkednullptr));
    properties.add(<bool>DiagnosticsProperty("selected", selectednullptr));
    properties.add(StringProperty("label", labelnullptr));
    properties.add(AttributedStringProperty("attributedLabel", attributedLabelnullptr));
    properties.add(StringProperty("value", valuenullptr));
    properties.add(AttributedStringProperty("attributedValue", attributedValuenullptr));
    properties.add(StringProperty("increasedValue", valuenullptr));
    properties.add(AttributedStringProperty("attributedIncreasedValue", attributedIncreasedValuenullptr));
    properties.add(StringProperty("decreasedValue", valuenullptr));
    properties.add(AttributedStringProperty("attributedDecreasedValue", attributedDecreasedValuenullptr));
    properties.add(StringProperty("hint", hintnullptr));
    properties.add(AttributedStringProperty("attributedHint", attributedHintnullptr));
    properties.add(StringProperty("tooltip", tooltip));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
    properties.add(<SemanticsSortKey>DiagnosticsProperty("sortKey", sortKeynullptr));
    properties.add(<SemanticsHintOverrides>DiagnosticsProperty("hintOverrides", hintOverridesnullptr));
}

String SemanticsProperties::toStringShort() {
    return objectRuntimeType(this, "SemanticsProperties");
}

void debugResetSemanticsIdCounter() {
    SemanticsNode._lastIdentifier = 0;
}

SemanticsNode::SemanticsNode(Key key, VoidCallback showOnScreen) {
    {
        _id = _generateNewId();
        _showOnScreen = showOnScreen;
    }
}

void SemanticsNode::root(Key key, SemanticsOwner owner, VoidCallback showOnScreen) {
    attach(owner);
}

int SemanticsNode::id() {
    return _id;
}

Matrix4 SemanticsNode::transform() {
    return _transform;
}

void SemanticsNode::transform(Matrix4 value) {
    if (!MatrixUtils.matrixEquals(_transform, value)) {
        _transform = value == nullptr || MatrixUtils.isIdentity(value)? nullptr : value;
        _markDirty();
    }
}

Rect SemanticsNode::rect() {
    return _rect;
}

void SemanticsNode::rect(Rect value) {
    assert(value != nullptr);
    assert(value.isFinite, "$this (with $owner) tried to set a non-finite rect.");
    if (_rect != value) {
        _rect = value;
        _markDirty();
    }
}

bool SemanticsNode::isInvisible() {
    return !isMergedIntoParent && rect.isEmpty;
}

bool SemanticsNode::isMergedIntoParent() {
    return _isMergedIntoParent;
}

void SemanticsNode::isMergedIntoParent(bool value) {
    assert(value != nullptr);
    if (_isMergedIntoParent == value) {
        return;
    }
    _isMergedIntoParent = value;
    _markDirty();
}

bool SemanticsNode::isPartOfNodeMerging() {
    return mergeAllDescendantsIntoThisNode || isMergedIntoParent;
}

bool SemanticsNode::mergeAllDescendantsIntoThisNode() {
    return _mergeAllDescendantsIntoThisNode;
}

bool SemanticsNode::hasChildren() {
    return _children?.isNotEmpty ?? false;
}

int SemanticsNode::childrenCount() {
    return hasChildren? _children!.length : 0;
}

void SemanticsNode::visitChildren(SemanticsNodeVisitor visitor) {
    if (_children != nullptr) {
        for (SemanticsNode child : _children!) {
            if (!visitor(child)) {
                return;
            }
        }
    }
}

SemanticsOwner SemanticsNode::owner() {
    return (;
}

SemanticsNode SemanticsNode::parent() {
    return (;
}

void SemanticsNode::redepthChildren() {
    _children?.forEach(redepthChild);
}

void SemanticsNode::attach(SemanticsOwner owner) {
    super.attach(owner);
    while (owner._nodes.containsKey(id)) {
        _id = _generateNewId();
    }
    owner._nodes[id] = this;
    owner._detachedNodes.remove(this);
    if (_dirty) {
        _dirty = false;
        _markDirty();
    }
    if (_children != nullptr) {
        for (SemanticsNode child : _children!) {
            child.attach(owner);
        }
    }
}

void SemanticsNode::detach() {
    assert(owner!._nodes.containsKey(id));
    assert(!owner!._detachedNodes.contains(this));
    owner!._nodes.remove(id);
    owner!._detachedNodes.add(this);
    super.detach();
    assert(owner == nullptr);
    if (_children != nullptr) {
        for (SemanticsNode child : _children!) {
            if (child.parent == this) {
                child.detach();
            }
        }
    }
    _markDirty();
}

bool SemanticsNode::isTagged(SemanticsTag tag) {
    return tags != nullptr && tags!.contains(tag);
}

bool SemanticsNode::hasFlag(SemanticsFlag flag) {
    return _flags & flag.index != 0;
}

String SemanticsNode::label() {
    return _attributedLabel.string;
}

AttributedString SemanticsNode::attributedLabel() {
    return _attributedLabel;
}

String SemanticsNode::value() {
    return _attributedValue.string;
}

AttributedString SemanticsNode::attributedValue() {
    return _attributedValue;
}

String SemanticsNode::increasedValue() {
    return _attributedIncreasedValue.string;
}

AttributedString SemanticsNode::attributedIncreasedValue() {
    return _attributedIncreasedValue;
}

String SemanticsNode::decreasedValue() {
    return _attributedDecreasedValue.string;
}

AttributedString SemanticsNode::attributedDecreasedValue() {
    return _attributedDecreasedValue;
}

String SemanticsNode::hint() {
    return _attributedHint.string;
}

AttributedString SemanticsNode::attributedHint() {
    return _attributedHint;
}

String SemanticsNode::tooltip() {
    return _tooltip;
}

double SemanticsNode::elevation() {
    return _elevation;
}

double SemanticsNode::thickness() {
    return _thickness;
}

SemanticsHintOverrides SemanticsNode::hintOverrides() {
    return _hintOverrides;
}

TextDirection SemanticsNode::textDirection() {
    return _textDirection;
}

SemanticsSortKey SemanticsNode::sortKey() {
    return _sortKey;
}

TextSelection SemanticsNode::textSelection() {
    return _textSelection;
}

bool SemanticsNode::isMultiline() {
    return _isMultiline;
}

int SemanticsNode::scrollChildCount() {
    return _scrollChildCount;
}

int SemanticsNode::scrollIndex() {
    return _scrollIndex;
}

double SemanticsNode::scrollPosition() {
    return _scrollPosition;
}

double SemanticsNode::scrollExtentMax() {
    return _scrollExtentMax;
}

double SemanticsNode::scrollExtentMin() {
    return _scrollExtentMin;
}

int SemanticsNode::platformViewId() {
    return _platformViewId;
}

int SemanticsNode::maxValueLength() {
    return _maxValueLength;
}

int SemanticsNode::currentValueLength() {
    return _currentValueLength;
}

void SemanticsNode::updateWith(List<SemanticsNode> childrenInInversePaintOrder, SemanticsConfiguration config) {
    config = _kEmptyConfig;
    if (_isDifferentFromCurrentSemanticAnnotation(config)) {
        _markDirty();
    }
    assert(config.platformViewId == nullptr || childrenInInversePaintOrder == nullptr || childrenInInversePaintOrder.isEmpty, "SemanticsNodes with children must not specify a platformViewId.");
    _attributedLabel = config.attributedLabel;
    _attributedValue = config.attributedValue;
    _attributedIncreasedValue = config.attributedIncreasedValue;
    _attributedDecreasedValue = config.attributedDecreasedValue;
    _attributedHint = config.attributedHint;
    _tooltip = config.tooltip;
    _hintOverrides = config.hintOverrides;
    _elevation = config.elevation;
    _thickness = config.thickness;
    _flags = config._flags;
    _textDirection = config.textDirection;
    _sortKey = config.sortKey;
    _actions = <SemanticsAction, SemanticsActionHandler>of(config._actions);
    _customSemanticsActions = <CustomSemanticsAction, VoidCallback>of(config._customSemanticsActions);
    _actionsAsBits = config._actionsAsBits;
    _textSelection = config._textSelection;
    _isMultiline = config.isMultiline;
    _scrollPosition = config._scrollPosition;
    _scrollExtentMax = config._scrollExtentMax;
    _scrollExtentMin = config._scrollExtentMin;
    _mergeAllDescendantsIntoThisNode = config.isMergingSemanticsOfDescendants;
    _scrollChildCount = config.scrollChildCount;
    _scrollIndex = config.scrollIndex;
    indexInParent = config.indexInParent;
    _platformViewId = config._platformViewId;
    _maxValueLength = config._maxValueLength;
    _currentValueLength = config._currentValueLength;
    _replaceChildren(childrenInInversePaintOrder ?? const );
    assert(!_canPerformAction(SemanticsAction.increase) || (value == "") == (increasedValue == ""), "A SemanticsNode with action "increase" needs to be annotated with either both "value" and "increasedValue" or neither");
    assert(!_canPerformAction(SemanticsAction.decrease) || (value == "") == (decreasedValue == ""), "A SemanticsNode with action "increase" needs to be annotated with either both "value" and "decreasedValue" or neither");
}

SemanticsData SemanticsNode::getSemanticsData() {
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
    Set<int> customSemanticsActionIds = ;
    for (CustomSemanticsAction action : _customSemanticsActions.keys) {
        customSemanticsActionIds.add(CustomSemanticsAction.getIdentifier(action));
    }
    if (hintOverrides != nullptr) {
        if (hintOverrides!.onTapHint != nullptr) {
            CustomSemanticsAction action = CustomSemanticsAction.overridingAction(hintOverrides!.onTapHint!, SemanticsAction.tap);
            customSemanticsActionIds.add(CustomSemanticsAction.getIdentifier(action));
        }
        if (hintOverrides!.onLongPressHint != nullptr) {
            CustomSemanticsAction action = CustomSemanticsAction.overridingAction(hintOverrides!.onLongPressHint!, SemanticsAction.longPress);
            customSemanticsActionIds.add(CustomSemanticsAction.getIdentifier(action));
        }
    }
    if (mergeAllDescendantsIntoThisNode) {
        _visitDescendants();
    }
    return SemanticsData(flags, actions, attributedLabel, attributedValue, attributedIncreasedValue, attributedDecreasedValue, attributedHint, tooltip, textDirection, rect, transform, elevation, thickness, mergedTags, textSelection, scrollChildCount, scrollIndex, scrollPosition, scrollExtentMax, scrollExtentMin, platformViewId, maxValueLength, currentValueLength, );
}

void SemanticsNode::sendEvent(SemanticsEvent event) {
    if (!attached) {
        return;
    }
    SystemChannels.accessibility.send(event.toMap(id));
}

String SemanticsNode::toStringShort() {
    return "${objectRuntimeType(this, 'SemanticsNode')}#$id";
}

void SemanticsNode::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    bool hideOwner = true;
    if (_dirty) {
        bool inDirtyNodes = owner != nullptr && owner!._dirtyNodes.contains(this);
        properties.add(FlagProperty("inDirtyNodes"inDirtyNodes, "dirty", "STALE"));
        hideOwner = inDirtyNodes;
    }
    properties.add(<SemanticsOwner>DiagnosticsProperty("owner", ownerhideOwner? DiagnosticLevel.hidden : DiagnosticLevel.info));
    properties.add(FlagProperty("isMergedIntoParent"isMergedIntoParent, "merged up ⬆️"));
    properties.add(FlagProperty("mergeAllDescendantsIntoThisNode"mergeAllDescendantsIntoThisNode, "merge boundary ⛔️"));
    Offset offset = transform != nullptr? MatrixUtils.getAsTranslation(transform!) : nullptr;
    if (offset != nullptr) {
        properties.add(<Rect>DiagnosticsProperty("rect", rect.shift(offset)false));
    } else {
        double scale = transform != nullptr? MatrixUtils.getAsScale(transform!) : nullptr;
        String description;
        if (scale != nullptr) {
            description = "$rect scaled by ${scale.toStringAsFixed(1)}x";
        } else         {
            if (transform != nullptr && !MatrixUtils.isIdentity(transform!)) {
            String matrix = transform.toString().split("\n").take(4).<String>map().join("; ");
            description = "$rect with transform [$matrix]";
        }
;
        }        properties.add(<Rect>DiagnosticsProperty("rect", rectdescription, false));
    }
    properties.add(<String>IterableProperty("tags", tags?.map()nullptr));
    List<String> actions = ;
    List<String> customSemanticsActions = _customSemanticsActions.keys.<String>map().toList();
    properties.add(<String>IterableProperty("actions", actionsnullptr));
    properties.add(<String>IterableProperty("customActions", customSemanticsActionsnullptr));
    List<String> flags = SemanticsFlag.values.values.where().map().toList();
    properties.add(<String>IterableProperty("flags", flagsnullptr));
    properties.add(FlagProperty("isInvisible"isInvisible, "invisible"));
    properties.add(FlagProperty("isHidden"hasFlag(SemanticsFlag.isHidden), "HIDDEN"));
    properties.add(AttributedStringProperty("label", _attributedLabel));
    properties.add(AttributedStringProperty("value", _attributedValue));
    properties.add(AttributedStringProperty("increasedValue", _attributedIncreasedValue));
    properties.add(AttributedStringProperty("decreasedValue", _attributedDecreasedValue));
    properties.add(AttributedStringProperty("hint", _attributedHint));
    properties.add(StringProperty("tooltip", _tooltip""));
    properties.add(<TextDirection>EnumProperty("textDirection", _textDirectionnullptr));
    properties.add(<SemanticsSortKey>DiagnosticsProperty("sortKey", sortKeynullptr));
    if (_textSelection?.isValid ?? false) {
        properties.add(MessageProperty("text selection", "[${_textSelection!.start}, ${_textSelection!.end}]"));
    }
    properties.add(IntProperty("platformViewId", platformViewIdnullptr));
    properties.add(IntProperty("maxValueLength", maxValueLengthnullptr));
    properties.add(IntProperty("currentValueLength", currentValueLengthnullptr));
    properties.add(IntProperty("scrollChildren", scrollChildCountnullptr));
    properties.add(IntProperty("scrollIndex", scrollIndexnullptr));
    properties.add(DoubleProperty("scrollExtentMin", scrollExtentMinnullptr));
    properties.add(DoubleProperty("scrollPosition", scrollPositionnullptr));
    properties.add(DoubleProperty("scrollExtentMax", scrollExtentMaxnullptr));
    properties.add(DoubleProperty("elevation", elevation0.0));
    properties.add(DoubleProperty("thickness", thickness0.0));
}

String SemanticsNode::toStringDeep(DebugSemanticsDumpOrder childOrder, DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines) {
    assert(childOrder != nullptr);
    return toDiagnosticsNode(childOrder).toStringDeep(prefixLineOne, prefixOtherLines, minLevel);
}

DiagnosticsNode SemanticsNode::toDiagnosticsNode(DebugSemanticsDumpOrder childOrder, String name, DiagnosticsTreeStyle style) {
    return _SemanticsDiagnosticableNode(name, this, style, childOrder);
}

List<DiagnosticsNode> SemanticsNode::debugDescribeChildren(DebugSemanticsDumpOrder childOrder) {
    return debugListChildrenInOrder(childOrder).<DiagnosticsNode>map().toList();
}

List<SemanticsNode> SemanticsNode::debugListChildrenInOrder(DebugSemanticsDumpOrder childOrder) {
    assert(childOrder != nullptr);
    if (_children == nullptr) {
        return const ;
    }
    ;
}

int SemanticsNode::_generateNewId() {
    _lastIdentifier = (_lastIdentifier + 1) % _maxFrameworkAccessibilityIdentifier;
    return _lastIdentifier;
}

void SemanticsNode::_replaceChildren(List<SemanticsNode> newChildren) {
    assert(!newChildren.any());
    assert(());
    assert(());
    if (_children != nullptr) {
        for (SemanticsNode child : _children!) {
            child._dead = true;
        }
    }
    for (SemanticsNode child : newChildren) {
        assert(!child.isInvisible, "Child $child is invisible and should not be added as a child of $this.");
        child._dead = false;
    }
    bool sawChange = false;
    if (_children != nullptr) {
        for (SemanticsNode child : _children!) {
            if (child._dead) {
                if (child.parent == this) {
                    dropChild(child);
                }
                sawChange = true;
            }
        }
    }
    for (SemanticsNode child : newChildren) {
        if (child.parent != this) {
            if (child.parent != nullptr) {
                child.parent?.dropChild(child);
            }
            assert(!child.attached);
            adoptChild(child);
            sawChange = true;
        }
    }
    if (!sawChange && _children != nullptr) {
        assert(newChildren != nullptr);
        assert(newChildren.length == _children!.length);
        for (;  < _children!.length; i++) {
            if (_children![i].id != newChildren[i].id) {
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

bool SemanticsNode::_visitDescendants(SemanticsNodeVisitor visitor) {
    if (_children != nullptr) {
        for (SemanticsNode child : _children!) {
            if (!visitor(child) || !child._visitDescendants(visitor)) {
                return false;
            }
        }
    }
    return true;
}

void SemanticsNode::_markDirty() {
    if (_dirty) {
        return;
    }
    _dirty = true;
    if (attached) {
        assert(!owner!._detachedNodes.contains(this));
        owner!._dirtyNodes.add(this);
    }
}

bool SemanticsNode::_isDifferentFromCurrentSemanticAnnotation(SemanticsConfiguration config) {
    return _attributedLabel != config.attributedLabel || _attributedHint != config.attributedHint || _elevation != config.elevation || _thickness != config.thickness || _attributedValue != config.attributedValue || _attributedIncreasedValue != config.attributedIncreasedValue || _attributedDecreasedValue != config.attributedDecreasedValue || _tooltip != config.tooltip || _flags != config._flags || _textDirection != config.textDirection || _sortKey != config._sortKey || _textSelection != config._textSelection || _scrollPosition != config._scrollPosition || _scrollExtentMax != config._scrollExtentMax || _scrollExtentMin != config._scrollExtentMin || _actionsAsBits != config._actionsAsBits || indexInParent != config.indexInParent || platformViewId != config.platformViewId || _maxValueLength != config._maxValueLength || _currentValueLength != config._currentValueLength || _mergeAllDescendantsIntoThisNode != config.isMergingSemanticsOfDescendants;
}

bool SemanticsNode::_canPerformAction(SemanticsAction action) {
    return _actions.containsKey(action);
}

Float64List SemanticsNode::_initIdentityTransform() {
    return Matrix4.identity().storage;
}

void SemanticsNode::_addToUpdate(SemanticsUpdateBuilder builder, Set<int> customSemanticsActionIdsUpdate) {
    assert(_dirty);
    SemanticsData data = getSemanticsData();
    Int32List childrenInTraversalOrder;
    Int32List childrenInHitTestOrder;
    if (!hasChildren || mergeAllDescendantsIntoThisNode) {
        childrenInTraversalOrder = _kEmptyChildList;
        childrenInHitTestOrder = _kEmptyChildList;
    } else {
        int childCount = _children!.length;
        List<SemanticsNode> sortedChildren = _childrenInTraversalOrder();
        childrenInTraversalOrder = Int32List(childCount);
        for (;  < childCount; i = 1) {
            childrenInTraversalOrder[i] = sortedChildren[i].id;
        }
        childrenInHitTestOrder = Int32List(childCount);
        for (; i >= 0; i = 1) {
            childrenInHitTestOrder[i] = _children![childCount - i - 1].id;
        }
    }
    Int32List customSemanticsActionIds;
    if (data.customSemanticsActionIds?.isNotEmpty ?? false) {
        customSemanticsActionIds = Int32List(data.customSemanticsActionIds!.length);
        for (;  < data.customSemanticsActionIds!.length; i++) {
            customSemanticsActionIds[i] = data.customSemanticsActionIds![i];
            customSemanticsActionIdsUpdate.add(data.customSemanticsActionIds![i]);
        }
    }
    builder.updateNode(id, data.flags, data.actions, data.rect, data.attributedLabel.string, data.attributedLabel.attributes, data.attributedValue.string, data.attributedValue.attributes, data.attributedIncreasedValue.string, data.attributedIncreasedValue.attributes, data.attributedDecreasedValue.string, data.attributedDecreasedValue.attributes, data.attributedHint.string, data.attributedHint.attributes, data.tooltip, data.textDirection, data.textSelection != nullptr? data.textSelection!.baseOffset : -1, data.textSelection != nullptr? data.textSelection!.extentOffset : -1, data.platformViewId ?? -1, data.maxValueLength ?? -1, data.currentValueLength ?? -1, data.scrollChildCount ?? 0, data.scrollIndex ?? 0, data.scrollPosition ?? double.nan, data.scrollExtentMax ?? double.nan, data.scrollExtentMin ?? double.nan, data.transform?.storage ?? _kIdentityTransform, data.elevation, data.thickness, childrenInTraversalOrder, childrenInHitTestOrder, customSemanticsActionIds ?? _kEmptyCustomSemanticsActionsList);
    _dirty = false;
}

List<SemanticsNode> SemanticsNode::_childrenInTraversalOrder() {
    TextDirection inheritedTextDirection = textDirection;
    SemanticsNode ancestor = parent;
    while (inheritedTextDirection == nullptr && ancestor != nullptr) {
        inheritedTextDirection = ancestor.textDirection;
        ancestor = ancestor.parent;
    }
    List<SemanticsNode> childrenInDefaultOrder;
    if (inheritedTextDirection != nullptr) {
        childrenInDefaultOrder = _childrenInDefaultOrder(_children!, inheritedTextDirection);
    } else {
        childrenInDefaultOrder = _children;
    }
    List<_TraversalSortNode> everythingSorted = ;
    List<_TraversalSortNode> sortNodes = ;
    SemanticsSortKey lastSortKey;
    for (;  < childrenInDefaultOrder!.length; position = 1) {
        SemanticsNode child = childrenInDefaultOrder[position];
        SemanticsSortKey sortKey = child.sortKey;
        lastSortKey = position > 0? childrenInDefaultOrder[position - 1].sortKey : nullptr;
        bool isCompatibleWithPreviousSortKey = position == 0 || sortKey.runtimeType == lastSortKey.runtimeType && (sortKey == nullptr || sortKey.name == lastSortKey!.name);
        if (!isCompatibleWithPreviousSortKey && sortNodes.isNotEmpty) {
            if (lastSortKey != nullptr) {
                sortNodes.sort();
            }
            everythingSorted.addAll(sortNodes);
            sortNodes.clear();
        }
        sortNodes.add(_TraversalSortNode(child, sortKey, position));
    }
    if (lastSortKey != nullptr) {
        sortNodes.sort();
    }
    everythingSorted.addAll(sortNodes);
    return everythingSorted.<SemanticsNode>map().toList();
}

int _BoxEdge::compareTo(_BoxEdge other) {
    return offset.compareTo(other.offset);
}

_BoxEdge::_BoxEdge(bool isLeadingEdge, SemanticsNode node, double offset) {
    {
        assert(isLeadingEdge != nullptr);
        assert(offset != nullptr);
        assert(offset.isFinite);
        assert(node != nullptr);
    }
}

int _SemanticsSortGroup::compareTo(_SemanticsSortGroup other) {
    return startOffset.compareTo(other.startOffset);
}

List<SemanticsNode> _SemanticsSortGroup::sortedWithinVerticalGroup() {
    List<_BoxEdge> edges = ;
    for (SemanticsNode child : nodes) {
        Rect childRect = child.rect.deflate(0.1);
        edges.add(_BoxEdge(true, _pointInParentCoordinates(child, childRect.topLeft).dx, child));
        edges.add(_BoxEdge(false, _pointInParentCoordinates(child, childRect.bottomRight).dx, child));
    }
    edges.sort();
    List<_SemanticsSortGroup> horizontalGroups = ;
    _SemanticsSortGroup group;
    int depth = 0;
    for (_BoxEdge edge : edges) {
        if (edge.isLeadingEdge) {
            depth = 1;
            group = _SemanticsSortGroup(edge.offset, textDirection);
            group.nodes.add(edge.node);
        } else {
            depth = 1;
        }
        if (depth == 0) {
            horizontalGroups.add(group!);
            group = nullptr;
        }
    }
    horizontalGroups.sort();
    if (textDirection == TextDirection.rtl) {
        horizontalGroups = horizontalGroups.reversed.toList();
    }
    return horizontalGroups.expand().toList();
}

List<SemanticsNode> _SemanticsSortGroup::sortedWithinKnot() {
    if (nodes.length <= 1) {
        return nodes;
    }
    Map<int, SemanticsNode> nodeMap = ;
    Map<int, int> edges = ;
    for (SemanticsNode node : nodes) {
        nodeMap[node.id] = node;
        Offset center = _pointInParentCoordinates(node, node.rect.center);
        for (SemanticsNode nextNode : nodes) {
            if (identical(node, nextNode) || edges[nextNode.id] == node.id) {
                continue;
            }
            Offset nextCenter = _pointInParentCoordinates(nextNode, nextNode.rect.center);
            Offset centerDelta = nextCenter - center;
            double direction = centerDelta.direction;
            bool isLtrAndForward = textDirection == TextDirection.ltr && -math.pi / 4 < direction &&  < 3 * math.pi / 4;
            bool isRtlAndForward = textDirection == TextDirection.rtl && ( < -3 * math.pi / 4 || direction > 3 * math.pi / 4);
            if (isLtrAndForward || isRtlAndForward) {
                edges[node.id] = nextNode.id;
            }
        }
    }
    List<int> sortedIds = ;
    Set<int> visitedIds = ;
    List<SemanticsNode> startNodes = ;
    ;
    startNodes.<int>map().forEach(search);
    return sortedIds.<SemanticsNode>map().toList().reversed.toList();
}

_SemanticsSortGroup::_SemanticsSortGroup(double startOffset, TextDirection textDirection) {
    {
        assert(startOffset != nullptr);
    }
}

Offset _pointInParentCoordinates(SemanticsNode node, Offset point) {
    if (node.transform == nullptr) {
        return point;
    }
    Vector3 vector = Vector3(point.dx, point.dy, 0.0);
    node.transform!.transform3(vector);
    return Offset(vector.x, vector.y);
}

List<SemanticsNode> _childrenInDefaultOrder(List<SemanticsNode> children, TextDirection textDirection) {
    List<_BoxEdge> edges = ;
    for (SemanticsNode child : children) {
        assert(child.rect.isFinite);
        Rect childRect = child.rect.deflate(0.1);
        edges.add(_BoxEdge(true, _pointInParentCoordinates(child, childRect.topLeft).dy, child));
        edges.add(_BoxEdge(false, _pointInParentCoordinates(child, childRect.bottomRight).dy, child));
    }
    edges.sort();
    List<_SemanticsSortGroup> verticalGroups = ;
    _SemanticsSortGroup group;
    int depth = 0;
    for (_BoxEdge edge : edges) {
        if (edge.isLeadingEdge) {
            depth = 1;
            group = _SemanticsSortGroup(edge.offset, textDirection);
            group.nodes.add(edge.node);
        } else {
            depth = 1;
        }
        if (depth == 0) {
            verticalGroups.add(group!);
            group = nullptr;
        }
    }
    verticalGroups.sort();
    return verticalGroups.expand().toList();
}

int _TraversalSortNode::compareTo(_TraversalSortNode other) {
    if (sortKey == nullptr || other.sortKey == nullptr) {
        return position - other.position;
    }
    return sortKey!.compareTo(other.sortKey!);
}

_TraversalSortNode::_TraversalSortNode(SemanticsNode node, int position, SemanticsSortKey sortKey) {
    {
        assert(node != nullptr);
        assert(position != nullptr);
    }
}

SemanticsNode SemanticsOwner::rootSemanticsNode() {
    return _nodes[0];
}

void SemanticsOwner::dispose() {
    _dirtyNodes.clear();
    _nodes.clear();
    _detachedNodes.clear();
    super.dispose();
}

void SemanticsOwner::sendSemanticsUpdate() {
    if (_dirtyNodes.isEmpty) {
        return;
    }
    Set<int> customSemanticsActionIds = ;
    List<SemanticsNode> visitedNodes = ;
    while (_dirtyNodes.isNotEmpty) {
        List<SemanticsNode> localDirtyNodes = _dirtyNodes.where().toList();
        _dirtyNodes.clear();
        _detachedNodes.clear();
        localDirtyNodes.sort();
        visitedNodes.addAll(localDirtyNodes);
        for (SemanticsNode node : localDirtyNodes) {
            assert(node._dirty);
            assert(node.parent == nullptr || !node.parent!.isPartOfNodeMerging || node.isMergedIntoParent);
            if (node.isPartOfNodeMerging) {
                assert(node.mergeAllDescendantsIntoThisNode || node.parent != nullptr);
                if (node.parent != nullptr && node.parent!.isPartOfNodeMerging) {
                    node.parent!._markDirty();
                    node._dirty = false;
                }
            }
        }
    }
    visitedNodes.sort();
    SemanticsUpdateBuilder builder = SemanticsBinding.instance.createSemanticsUpdateBuilder();
    for (SemanticsNode node : visitedNodes) {
        assert(node.parent?._dirty != true);
        if (node._dirty && node.attached) {
            node._addToUpdate(builder, customSemanticsActionIds);
        }
    }
    _dirtyNodes.clear();
    for (int actionId : customSemanticsActionIds) {
        CustomSemanticsAction action = CustomSemanticsAction.getAction(actionId)!;
        builder.updateCustomAction(actionId, action.label, action.hint, action.action?.index ?? -1);
    }
    SemanticsBinding.instance.platformDispatcher.updateSemantics(builder.build());
    notifyListeners();
}

void SemanticsOwner::performAction(SemanticsAction action, Object args, int id) {
    assert(action != nullptr);
    SemanticsActionHandler handler = _getSemanticsActionHandlerForId(id, action);
    if (handler != nullptr) {
        handler(args);
        return;
    }
    if (action == SemanticsAction.showOnScreen && _nodes[id]!._showOnScreen != nullptr) {
        _nodes[id]!._showOnScreen!();
    }
}

void SemanticsOwner::performActionAt(SemanticsAction action, Object args, Offset position) {
    assert(action != nullptr);
    SemanticsNode node = rootSemanticsNode;
    if (node == nullptr) {
        return;
    }
    SemanticsActionHandler handler = _getSemanticsActionHandlerForPosition(node, position, action);
    if (handler != nullptr) {
        handler(args);
    }
}

String SemanticsOwner::toString() {
    return describeIdentity(this);
}

SemanticsActionHandler SemanticsOwner::_getSemanticsActionHandlerForId(SemanticsAction action, int id) {
    SemanticsNode result = _nodes[id];
    if (result != nullptr && result.isPartOfNodeMerging && !result._canPerformAction(action)) {
        result._visitDescendants();
    }
    if (result == nullptr || !result!._canPerformAction(action)) {
        return nullptr;
    }
    return result!._actions[action];
}

SemanticsActionHandler SemanticsOwner::_getSemanticsActionHandlerForPosition(SemanticsAction action, SemanticsNode node, Offset position) {
    if (node.transform != nullptr) {
        Matrix4 inverse = Matrix4.identity();
        if (inverse.copyInverse(node.transform!) == 0.0) {
            return nullptr;
        }
        position = MatrixUtils.transformPoint(inverse, position);
    }
    if (!node.rect.contains(position)) {
        return nullptr;
    }
    if (node.mergeAllDescendantsIntoThisNode) {
        SemanticsNode result;
        node._visitDescendants();
        return result?._actions[action];
    }
    if (node.hasChildren) {
        for (SemanticsNode child : node._children!.reversed) {
            SemanticsActionHandler handler = _getSemanticsActionHandlerForPosition(child, position, action);
            if (handler != nullptr) {
                return handler;
            }
        }
    }
    return node._actions[action];
}

bool SemanticsConfiguration::isSemanticBoundary() {
    return _isSemanticBoundary;
}

void SemanticsConfiguration::isSemanticBoundary(bool value) {
    assert(!isMergingSemanticsOfDescendants || value);
    _isSemanticBoundary = value;
}

bool SemanticsConfiguration::hasBeenAnnotated() {
    return _hasBeenAnnotated;
}

VoidCallback SemanticsConfiguration::onTap() {
    return _onTap;
}

void SemanticsConfiguration::onTap(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.tap, value!);
    _onTap = value;
}

VoidCallback SemanticsConfiguration::onLongPress() {
    return _onLongPress;
}

void SemanticsConfiguration::onLongPress(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.longPress, value!);
    _onLongPress = value;
}

VoidCallback SemanticsConfiguration::onScrollLeft() {
    return _onScrollLeft;
}

void SemanticsConfiguration::onScrollLeft(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.scrollLeft, value!);
    _onScrollLeft = value;
}

VoidCallback SemanticsConfiguration::onDismiss() {
    return _onDismiss;
}

void SemanticsConfiguration::onDismiss(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.dismiss, value!);
    _onDismiss = value;
}

VoidCallback SemanticsConfiguration::onScrollRight() {
    return _onScrollRight;
}

void SemanticsConfiguration::onScrollRight(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.scrollRight, value!);
    _onScrollRight = value;
}

VoidCallback SemanticsConfiguration::onScrollUp() {
    return _onScrollUp;
}

void SemanticsConfiguration::onScrollUp(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.scrollUp, value!);
    _onScrollUp = value;
}

VoidCallback SemanticsConfiguration::onScrollDown() {
    return _onScrollDown;
}

void SemanticsConfiguration::onScrollDown(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.scrollDown, value!);
    _onScrollDown = value;
}

VoidCallback SemanticsConfiguration::onIncrease() {
    return _onIncrease;
}

void SemanticsConfiguration::onIncrease(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.increase, value!);
    _onIncrease = value;
}

VoidCallback SemanticsConfiguration::onDecrease() {
    return _onDecrease;
}

void SemanticsConfiguration::onDecrease(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.decrease, value!);
    _onDecrease = value;
}

VoidCallback SemanticsConfiguration::onCopy() {
    return _onCopy;
}

void SemanticsConfiguration::onCopy(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.copy, value!);
    _onCopy = value;
}

VoidCallback SemanticsConfiguration::onCut() {
    return _onCut;
}

void SemanticsConfiguration::onCut(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.cut, value!);
    _onCut = value;
}

VoidCallback SemanticsConfiguration::onPaste() {
    return _onPaste;
}

void SemanticsConfiguration::onPaste(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.paste, value!);
    _onPaste = value;
}

VoidCallback SemanticsConfiguration::onShowOnScreen() {
    return _onShowOnScreen;
}

void SemanticsConfiguration::onShowOnScreen(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.showOnScreen, value!);
    _onShowOnScreen = value;
}

MoveCursorHandler SemanticsConfiguration::onMoveCursorForwardByCharacter() {
    return _onMoveCursorForwardByCharacter;
}

void SemanticsConfiguration::onMoveCursorForwardByCharacter(MoveCursorHandler value) {
    assert(value != nullptr);
    _addAction(SemanticsAction.moveCursorForwardByCharacter, );
    _onMoveCursorForwardByCharacter = value;
}

MoveCursorHandler SemanticsConfiguration::onMoveCursorBackwardByCharacter() {
    return _onMoveCursorBackwardByCharacter;
}

void SemanticsConfiguration::onMoveCursorBackwardByCharacter(MoveCursorHandler value) {
    assert(value != nullptr);
    _addAction(SemanticsAction.moveCursorBackwardByCharacter, );
    _onMoveCursorBackwardByCharacter = value;
}

MoveCursorHandler SemanticsConfiguration::onMoveCursorForwardByWord() {
    return _onMoveCursorForwardByWord;
}

void SemanticsConfiguration::onMoveCursorForwardByWord(MoveCursorHandler value) {
    assert(value != nullptr);
    _addAction(SemanticsAction.moveCursorForwardByWord, );
    _onMoveCursorForwardByCharacter = value;
}

MoveCursorHandler SemanticsConfiguration::onMoveCursorBackwardByWord() {
    return _onMoveCursorBackwardByWord;
}

void SemanticsConfiguration::onMoveCursorBackwardByWord(MoveCursorHandler value) {
    assert(value != nullptr);
    _addAction(SemanticsAction.moveCursorBackwardByWord, );
    _onMoveCursorBackwardByCharacter = value;
}

SetSelectionHandler SemanticsConfiguration::onSetSelection() {
    return _onSetSelection;
}

void SemanticsConfiguration::onSetSelection(SetSelectionHandler value) {
    assert(value != nullptr);
    _addAction(SemanticsAction.setSelection, );
    _onSetSelection = value;
}

SetTextHandler SemanticsConfiguration::onSetText() {
    return _onSetText;
}

void SemanticsConfiguration::onSetText(SetTextHandler value) {
    assert(value != nullptr);
    _addAction(SemanticsAction.setText, );
    _onSetText = value;
}

VoidCallback SemanticsConfiguration::onDidGainAccessibilityFocus() {
    return _onDidGainAccessibilityFocus;
}

void SemanticsConfiguration::onDidGainAccessibilityFocus(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.didGainAccessibilityFocus, value!);
    _onDidGainAccessibilityFocus = value;
}

VoidCallback SemanticsConfiguration::onDidLoseAccessibilityFocus() {
    return _onDidLoseAccessibilityFocus;
}

void SemanticsConfiguration::onDidLoseAccessibilityFocus(VoidCallback value) {
    _addArgumentlessAction(SemanticsAction.didLoseAccessibilityFocus, value!);
    _onDidLoseAccessibilityFocus = value;
}

SemanticsActionHandler SemanticsConfiguration::getActionHandler(SemanticsAction action) {
    return _actions[action];
}

SemanticsSortKey SemanticsConfiguration::sortKey() {
    return _sortKey;
}

void SemanticsConfiguration::sortKey(SemanticsSortKey value) {
    assert(value != nullptr);
    _sortKey = value;
    _hasBeenAnnotated = true;
}

int SemanticsConfiguration::indexInParent() {
    return _indexInParent;
}

void SemanticsConfiguration::indexInParent(int value) {
    _indexInParent = value;
    _hasBeenAnnotated = true;
}

int SemanticsConfiguration::scrollChildCount() {
    return _scrollChildCount;
}

void SemanticsConfiguration::scrollChildCount(int value) {
    if (value == scrollChildCount) {
        return;
    }
    _scrollChildCount = value;
    _hasBeenAnnotated = true;
}

int SemanticsConfiguration::scrollIndex() {
    return _scrollIndex;
}

void SemanticsConfiguration::scrollIndex(int value) {
    if (value == scrollIndex) {
        return;
    }
    _scrollIndex = value;
    _hasBeenAnnotated = true;
}

int SemanticsConfiguration::platformViewId() {
    return _platformViewId;
}

void SemanticsConfiguration::platformViewId(int value) {
    if (value == platformViewId) {
        return;
    }
    _platformViewId = value;
    _hasBeenAnnotated = true;
}

int SemanticsConfiguration::maxValueLength() {
    return _maxValueLength;
}

void SemanticsConfiguration::maxValueLength(int value) {
    if (value == maxValueLength) {
        return;
    }
    _maxValueLength = value;
    _hasBeenAnnotated = true;
}

int SemanticsConfiguration::currentValueLength() {
    return _currentValueLength;
}

void SemanticsConfiguration::currentValueLength(int value) {
    if (value == currentValueLength) {
        return;
    }
    _currentValueLength = value;
    _hasBeenAnnotated = true;
}

bool SemanticsConfiguration::isMergingSemanticsOfDescendants() {
    return _isMergingSemanticsOfDescendants;
}

void SemanticsConfiguration::isMergingSemanticsOfDescendants(bool value) {
    assert(isSemanticBoundary);
    _isMergingSemanticsOfDescendants = value;
    _hasBeenAnnotated = true;
}

Map<CustomSemanticsAction, VoidCallback> SemanticsConfiguration::customSemanticsActions() {
    return _customSemanticsActions;
}

void SemanticsConfiguration::customSemanticsActions(Map<CustomSemanticsAction, VoidCallback> value) {
    _hasBeenAnnotated = true;
    _actionsAsBits = SemanticsAction.customAction.index;
    _customSemanticsActions = value;
    _actions[SemanticsAction.customAction] = _onCustomSemanticsAction;
}

String SemanticsConfiguration::label() {
    return _attributedLabel.string;
}

void SemanticsConfiguration::label(String label) {
    assert(label != nullptr);
    _attributedLabel = AttributedString(label);
    _hasBeenAnnotated = true;
}

AttributedString SemanticsConfiguration::attributedLabel() {
    return _attributedLabel;
}

void SemanticsConfiguration::attributedLabel(AttributedString attributedLabel) {
    _attributedLabel = attributedLabel;
    _hasBeenAnnotated = true;
}

String SemanticsConfiguration::value() {
    return _attributedValue.string;
}

void SemanticsConfiguration::value(String value) {
    assert(value != nullptr);
    _attributedValue = AttributedString(value);
    _hasBeenAnnotated = true;
}

AttributedString SemanticsConfiguration::attributedValue() {
    return _attributedValue;
}

void SemanticsConfiguration::attributedValue(AttributedString attributedValue) {
    _attributedValue = attributedValue;
    _hasBeenAnnotated = true;
}

String SemanticsConfiguration::increasedValue() {
    return _attributedIncreasedValue.string;
}

void SemanticsConfiguration::increasedValue(String increasedValue) {
    assert(increasedValue != nullptr);
    _attributedIncreasedValue = AttributedString(increasedValue);
    _hasBeenAnnotated = true;
}

AttributedString SemanticsConfiguration::attributedIncreasedValue() {
    return _attributedIncreasedValue;
}

void SemanticsConfiguration::attributedIncreasedValue(AttributedString attributedIncreasedValue) {
    _attributedIncreasedValue = attributedIncreasedValue;
    _hasBeenAnnotated = true;
}

String SemanticsConfiguration::decreasedValue() {
    return _attributedDecreasedValue.string;
}

void SemanticsConfiguration::decreasedValue(String decreasedValue) {
    assert(decreasedValue != nullptr);
    _attributedDecreasedValue = AttributedString(decreasedValue);
    _hasBeenAnnotated = true;
}

AttributedString SemanticsConfiguration::attributedDecreasedValue() {
    return _attributedDecreasedValue;
}

void SemanticsConfiguration::attributedDecreasedValue(AttributedString attributedDecreasedValue) {
    _attributedDecreasedValue = attributedDecreasedValue;
    _hasBeenAnnotated = true;
}

String SemanticsConfiguration::hint() {
    return _attributedHint.string;
}

void SemanticsConfiguration::hint(String hint) {
    assert(hint != nullptr);
    _attributedHint = AttributedString(hint);
    _hasBeenAnnotated = true;
}

AttributedString SemanticsConfiguration::attributedHint() {
    return _attributedHint;
}

void SemanticsConfiguration::attributedHint(AttributedString attributedHint) {
    _attributedHint = attributedHint;
    _hasBeenAnnotated = true;
}

String SemanticsConfiguration::tooltip() {
    return _tooltip;
}

void SemanticsConfiguration::tooltip(String tooltip) {
    _tooltip = tooltip;
    _hasBeenAnnotated = true;
}

SemanticsHintOverrides SemanticsConfiguration::hintOverrides() {
    return _hintOverrides;
}

void SemanticsConfiguration::hintOverrides(SemanticsHintOverrides value) {
    if (value == nullptr) {
        return;
    }
    _hintOverrides = value;
    _hasBeenAnnotated = true;
}

double SemanticsConfiguration::elevation() {
    return _elevation;
}

void SemanticsConfiguration::elevation(double value) {
    assert(value != nullptr && value >= 0.0);
    if (value == _elevation) {
        return;
    }
    _elevation = value;
    _hasBeenAnnotated = true;
}

double SemanticsConfiguration::thickness() {
    return _thickness;
}

void SemanticsConfiguration::thickness(double value) {
    assert(value != nullptr && value >= 0.0);
    if (value == _thickness) {
        return;
    }
    _thickness = value;
    _hasBeenAnnotated = true;
}

bool SemanticsConfiguration::scopesRoute() {
    return _hasFlag(SemanticsFlag.scopesRoute);
}

void SemanticsConfiguration::scopesRoute(bool value) {
    _setFlag(SemanticsFlag.scopesRoute, value);
}

bool SemanticsConfiguration::namesRoute() {
    return _hasFlag(SemanticsFlag.namesRoute);
}

void SemanticsConfiguration::namesRoute(bool value) {
    _setFlag(SemanticsFlag.namesRoute, value);
}

bool SemanticsConfiguration::isImage() {
    return _hasFlag(SemanticsFlag.isImage);
}

void SemanticsConfiguration::isImage(bool value) {
    _setFlag(SemanticsFlag.isImage, value);
}

bool SemanticsConfiguration::liveRegion() {
    return _hasFlag(SemanticsFlag.isLiveRegion);
}

void SemanticsConfiguration::liveRegion(bool value) {
    _setFlag(SemanticsFlag.isLiveRegion, value);
}

TextDirection SemanticsConfiguration::textDirection() {
    return _textDirection;
}

void SemanticsConfiguration::textDirection(TextDirection textDirection) {
    _textDirection = textDirection;
    _hasBeenAnnotated = true;
}

bool SemanticsConfiguration::isSelected() {
    return _hasFlag(SemanticsFlag.isSelected);
}

void SemanticsConfiguration::isSelected(bool value) {
    _setFlag(SemanticsFlag.isSelected, value);
}

bool SemanticsConfiguration::isEnabled() {
    return _hasFlag(SemanticsFlag.hasEnabledState)? _hasFlag(SemanticsFlag.isEnabled) : nullptr;
}

void SemanticsConfiguration::isEnabled(bool value) {
    _setFlag(SemanticsFlag.hasEnabledState, true);
    _setFlag(SemanticsFlag.isEnabled, value!);
}

bool SemanticsConfiguration::isChecked() {
    return _hasFlag(SemanticsFlag.hasCheckedState)? _hasFlag(SemanticsFlag.isChecked) : nullptr;
}

void SemanticsConfiguration::isChecked(bool value) {
    _setFlag(SemanticsFlag.hasCheckedState, true);
    _setFlag(SemanticsFlag.isChecked, value!);
}

bool SemanticsConfiguration::isToggled() {
    return _hasFlag(SemanticsFlag.hasToggledState)? _hasFlag(SemanticsFlag.isToggled) : nullptr;
}

void SemanticsConfiguration::isToggled(bool value) {
    _setFlag(SemanticsFlag.hasToggledState, true);
    _setFlag(SemanticsFlag.isToggled, value!);
}

bool SemanticsConfiguration::isInMutuallyExclusiveGroup() {
    return _hasFlag(SemanticsFlag.isInMutuallyExclusiveGroup);
}

void SemanticsConfiguration::isInMutuallyExclusiveGroup(bool value) {
    _setFlag(SemanticsFlag.isInMutuallyExclusiveGroup, value);
}

bool SemanticsConfiguration::isFocusable() {
    return _hasFlag(SemanticsFlag.isFocusable);
}

void SemanticsConfiguration::isFocusable(bool value) {
    _setFlag(SemanticsFlag.isFocusable, value);
}

bool SemanticsConfiguration::isFocused() {
    return _hasFlag(SemanticsFlag.isFocused);
}

void SemanticsConfiguration::isFocused(bool value) {
    _setFlag(SemanticsFlag.isFocused, value);
}

bool SemanticsConfiguration::isButton() {
    return _hasFlag(SemanticsFlag.isButton);
}

void SemanticsConfiguration::isButton(bool value) {
    _setFlag(SemanticsFlag.isButton, value);
}

bool SemanticsConfiguration::isLink() {
    return _hasFlag(SemanticsFlag.isLink);
}

void SemanticsConfiguration::isLink(bool value) {
    _setFlag(SemanticsFlag.isLink, value);
}

bool SemanticsConfiguration::isHeader() {
    return _hasFlag(SemanticsFlag.isHeader);
}

void SemanticsConfiguration::isHeader(bool value) {
    _setFlag(SemanticsFlag.isHeader, value);
}

bool SemanticsConfiguration::isSlider() {
    return _hasFlag(SemanticsFlag.isSlider);
}

void SemanticsConfiguration::isSlider(bool value) {
    _setFlag(SemanticsFlag.isSlider, value);
}

bool SemanticsConfiguration::isKeyboardKey() {
    return _hasFlag(SemanticsFlag.isKeyboardKey);
}

void SemanticsConfiguration::isKeyboardKey(bool value) {
    _setFlag(SemanticsFlag.isKeyboardKey, value);
}

bool SemanticsConfiguration::isHidden() {
    return _hasFlag(SemanticsFlag.isHidden);
}

void SemanticsConfiguration::isHidden(bool value) {
    _setFlag(SemanticsFlag.isHidden, value);
}

bool SemanticsConfiguration::isTextField() {
    return _hasFlag(SemanticsFlag.isTextField);
}

void SemanticsConfiguration::isTextField(bool value) {
    _setFlag(SemanticsFlag.isTextField, value);
}

bool SemanticsConfiguration::isReadOnly() {
    return _hasFlag(SemanticsFlag.isReadOnly);
}

void SemanticsConfiguration::isReadOnly(bool value) {
    _setFlag(SemanticsFlag.isReadOnly, value);
}

bool SemanticsConfiguration::isObscured() {
    return _hasFlag(SemanticsFlag.isObscured);
}

void SemanticsConfiguration::isObscured(bool value) {
    _setFlag(SemanticsFlag.isObscured, value);
}

bool SemanticsConfiguration::isMultiline() {
    return _hasFlag(SemanticsFlag.isMultiline);
}

void SemanticsConfiguration::isMultiline(bool value) {
    _setFlag(SemanticsFlag.isMultiline, value);
}

bool SemanticsConfiguration::hasImplicitScrolling() {
    return _hasFlag(SemanticsFlag.hasImplicitScrolling);
}

void SemanticsConfiguration::hasImplicitScrolling(bool value) {
    _setFlag(SemanticsFlag.hasImplicitScrolling, value);
}

TextSelection SemanticsConfiguration::textSelection() {
    return _textSelection;
}

void SemanticsConfiguration::textSelection(TextSelection value) {
    assert(value != nullptr);
    _textSelection = value;
    _hasBeenAnnotated = true;
}

double SemanticsConfiguration::scrollPosition() {
    return _scrollPosition;
}

void SemanticsConfiguration::scrollPosition(double value) {
    assert(value != nullptr);
    _scrollPosition = value;
    _hasBeenAnnotated = true;
}

double SemanticsConfiguration::scrollExtentMax() {
    return _scrollExtentMax;
}

void SemanticsConfiguration::scrollExtentMax(double value) {
    assert(value != nullptr);
    _scrollExtentMax = value;
    _hasBeenAnnotated = true;
}

double SemanticsConfiguration::scrollExtentMin() {
    return _scrollExtentMin;
}

void SemanticsConfiguration::scrollExtentMin(double value) {
    assert(value != nullptr);
    _scrollExtentMin = value;
    _hasBeenAnnotated = true;
}

Iterable<SemanticsTag> SemanticsConfiguration::tagsForChildren() {
    return _tagsForChildren;
}

void SemanticsConfiguration::addTagForChildren(SemanticsTag tag) {
    _tagsForChildren = ;
    _tagsForChildren!.add(tag);
}

bool SemanticsConfiguration::isCompatibleWith(SemanticsConfiguration other) {
    if (other == nullptr || !other.hasBeenAnnotated || !hasBeenAnnotated) {
        return true;
    }
    if (_actionsAsBits & other._actionsAsBits != 0) {
        return false;
    }
    if ((_flags & other._flags) != 0) {
        return false;
    }
    if (_platformViewId != nullptr && other._platformViewId != nullptr) {
        return false;
    }
    if (_maxValueLength != nullptr && other._maxValueLength != nullptr) {
        return false;
    }
    if (_currentValueLength != nullptr && other._currentValueLength != nullptr) {
        return false;
    }
    if (_attributedValue != nullptr && _attributedValue.string.isNotEmpty && other._attributedValue != nullptr && other._attributedValue.string.isNotEmpty) {
        return false;
    }
    return true;
}

void SemanticsConfiguration::absorb(SemanticsConfiguration child) {
    assert(!explicitChildNodes);
    if (!child.hasBeenAnnotated) {
        return;
    }
    _actions.addAll(child._actions);
    _customSemanticsActions.addAll(child._customSemanticsActions);
    _actionsAsBits = child._actionsAsBits;
    _flags = child._flags;
    _textSelection = child._textSelection;
    _scrollPosition = child._scrollPosition;
    _scrollExtentMax = child._scrollExtentMax;
    _scrollExtentMin = child._scrollExtentMin;
    _hintOverrides = child._hintOverrides;
    _indexInParent = child.indexInParent;
    _scrollIndex = child._scrollIndex;
    _scrollChildCount = child._scrollChildCount;
    _platformViewId = child._platformViewId;
    _maxValueLength = child._maxValueLength;
    _currentValueLength = child._currentValueLength;
    textDirection = child.textDirection;
    _sortKey = child._sortKey;
    _attributedLabel = _concatAttributedString(_attributedLabel, textDirection, child._attributedLabel, child.textDirection);
    if (_attributedValue == nullptr || _attributedValue.string == "") {
        _attributedValue = child._attributedValue;
    }
    if (_attributedIncreasedValue == nullptr || _attributedIncreasedValue.string == "") {
        _attributedIncreasedValue = child._attributedIncreasedValue;
    }
    if (_attributedDecreasedValue == nullptr || _attributedDecreasedValue.string == "") {
        _attributedDecreasedValue = child._attributedDecreasedValue;
    }
    _attributedHint = _concatAttributedString(_attributedHint, textDirection, child._attributedHint, child.textDirection);
    if (_tooltip == "") {
        _tooltip = child._tooltip;
    }
    _thickness = math.max(_thickness, child._thickness + child._elevation);
    _hasBeenAnnotated = _hasBeenAnnotated || child._hasBeenAnnotated;
}

SemanticsConfiguration SemanticsConfiguration::copy() {
    return ;
}

void SemanticsConfiguration::_addAction(SemanticsAction action, SemanticsActionHandler handler) {
    assert(handler != nullptr);
    _actions[action] = handler;
    _actionsAsBits = action.index;
    _hasBeenAnnotated = true;
}

void SemanticsConfiguration::_addArgumentlessAction(SemanticsAction action, VoidCallback handler) {
    assert(handler != nullptr);
    _addAction(action, );
}

void SemanticsConfiguration::_onCustomSemanticsAction(Object args) {
    CustomSemanticsAction action = CustomSemanticsAction.getAction(();
    if (action == nullptr) {
        return;
    }
    VoidCallback callback = _customSemanticsActions[action];
    if (callback != nullptr) {
        callback();
    }
}

void SemanticsConfiguration::_setFlag(SemanticsFlag flag, bool value) {
    if (value) {
        _flags = flag.index;
    } else {
        _flags = ~flag.index;
    }
    _hasBeenAnnotated = true;
}

bool SemanticsConfiguration::_hasFlag(SemanticsFlag flag) {
    return (_flags & flag.index) != 0;
}

AttributedString _concatAttributedString(AttributedString otherAttributedString, TextDirection otherTextDirection, AttributedString thisAttributedString, TextDirection thisTextDirection) {
    if (otherAttributedString.string.isEmpty) {
        return thisAttributedString;
    }
    if (thisTextDirection != otherTextDirection && otherTextDirection != nullptr) {
        ;
    }
    if (thisAttributedString.string.isEmpty) {
        return otherAttributedString;
    }
    return thisAttributedString + AttributedString("\n") + otherAttributedString;
}

int SemanticsSortKey::compareTo(SemanticsSortKey other) {
    assert(runtimeType == other.runtimeType, "Semantics sort keys can only be compared to other sort keys of the same type.");
    if (name == other.name) {
        return doCompare(other);
    }
    if (name == nullptr && other.name != nullptr) {
        return -1;
    } else     {
        if (name != nullptr && other.name == nullptr) {
        return 1;
    }
;
    }    return name!.compareTo(other.name!);
}

void SemanticsSortKey::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(StringProperty("name", namenullptr));
}

OrdinalSortKey::OrdinalSortKey(Unknown, double order) {
    {
        assert(order != nullptr);
        assert(order != double.nan);
        assert(order > double.negativeInfinity);
        assert( < double.infinity);
    }
}

int OrdinalSortKey::doCompare(OrdinalSortKey other) {
    if (other.order == nullptr || order == nullptr || other.order == order) {
        return 0;
    }
    return order.compareTo(other.order);
}

void OrdinalSortKey::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(DoubleProperty("order", ordernullptr));
}
