#ifndef PACKAGES_FLUTTER_SRC_SEMANTICS_SEMANTICS
#define PACKAGES_FLUTTER_SRC_SEMANTICS_SEMANTICS
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "semantics_event.hpp"

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "binding.hpp"
#include "semantics_event.hpp"


class SemanticsTagCls : public ObjectCls {
public:
    String name;


     SemanticsTagCls(String name);
    virtual String toString();

private:

};
using SemanticsTag = std::shared_ptr<SemanticsTagCls>;

class CustomSemanticsActionCls : public ObjectCls {
public:
    String label;

    String hint;

    SemanticsAction action;


     CustomSemanticsActionCls(String label);

    virtual void  overridingAction(SemanticsAction action, String hint);

    virtual int hashCode();

    virtual bool operator==(Object other);

    virtual String toString();

    static int getIdentifier(CustomSemanticsAction action);

    static CustomSemanticsAction getAction(int id);

private:
    static int _nextId;

    static Map<int, CustomSemanticsAction> _actions;

    static Map<CustomSemanticsAction, int> _ids;


};
using CustomSemanticsAction = std::shared_ptr<CustomSemanticsActionCls>;

class AttributedStringCls : public ObjectCls {
public:
    String string;

    List<StringAttribute> attributes;


     AttributedStringCls(List<StringAttribute> attributes, String string);

    virtual AttributedString operator+(AttributedString other);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using AttributedString = std::shared_ptr<AttributedStringCls>;

class AttributedStringPropertyCls : public DiagnosticsPropertyCls<AttributedString> {
public:
    bool showWhenEmpty;


     AttributedStringPropertyCls(Unknown defaultValue, Unknown description, Unknown level, String name, Unknown showName, bool showWhenEmpty, Unknown value);

    virtual bool isInteresting();

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

private:

};
using AttributedStringProperty = std::shared_ptr<AttributedStringPropertyCls>;

class SemanticsDataCls : public ObjectCls {
public:
    int flags;

    int actions;

    AttributedString attributedLabel;

    AttributedString attributedValue;

    AttributedString attributedIncreasedValue;

    AttributedString attributedDecreasedValue;

    AttributedString attributedHint;

    String tooltip;

    TextDirection textDirection;

    TextSelection textSelection;

    int scrollChildCount;

    int scrollIndex;

    double scrollPosition;

    double scrollExtentMax;

    double scrollExtentMin;

    int platformViewId;

    int maxValueLength;

    int currentValueLength;

    Rect rect;

    Set<SemanticsTag> tags;

    Matrix4 transform;

    double elevation;

    double thickness;

    List<int> customSemanticsActionIds;


     SemanticsDataCls(int actions, AttributedString attributedDecreasedValue, AttributedString attributedHint, AttributedString attributedIncreasedValue, AttributedString attributedLabel, AttributedString attributedValue, int currentValueLength, List<int> customSemanticsActionIds, double elevation, int flags, int maxValueLength, int platformViewId, Rect rect, int scrollChildCount, double scrollExtentMax, double scrollExtentMin, int scrollIndex, double scrollPosition, Set<SemanticsTag> tags, TextDirection textDirection, TextSelection textSelection, double thickness, String tooltip, Matrix4 transform);

    virtual String label();

    virtual String value();

    virtual String increasedValue();

    virtual String decreasedValue();

    virtual String hint();

    virtual bool hasFlag(SemanticsFlag flag);

    virtual bool hasAction(SemanticsAction action);

    virtual String toStringShort();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

    static bool _sortedListsEqual(List<int> left, List<int> right);

};
using SemanticsData = std::shared_ptr<SemanticsDataCls>;

class _SemanticsDiagnosticableNodeCls : public DiagnosticableNodeCls<SemanticsNode> {
public:
    DebugSemanticsDumpOrder childOrder;


    virtual List<DiagnosticsNode> getChildren();

private:

     _SemanticsDiagnosticableNodeCls(DebugSemanticsDumpOrder childOrder, Unknown name, Unknown style, Unknown value);
};
using _SemanticsDiagnosticableNode = std::shared_ptr<_SemanticsDiagnosticableNodeCls>;

class SemanticsHintOverridesCls : public DiagnosticableTreeCls {
public:
    String onTapHint;

    String onLongPressHint;


     SemanticsHintOverridesCls(String onLongPressHint, String onTapHint);

    virtual bool isNotEmpty();

    virtual int hashCode();

    virtual bool operator==(Object other);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SemanticsHintOverrides = std::shared_ptr<SemanticsHintOverridesCls>;

class SemanticsPropertiesCls : public DiagnosticableTreeCls {
public:
    bool enabled;

    bool checked;

    bool toggled;

    bool selected;

    bool button;

    bool link;

    bool header;

    bool textField;

    bool slider;

    bool keyboardKey;

    bool readOnly;

    bool focusable;

    bool focused;

    bool inMutuallyExclusiveGroup;

    bool hidden;

    bool obscured;

    bool multiline;

    bool scopesRoute;

    bool namesRoute;

    bool image;

    bool liveRegion;

    int maxValueLength;

    int currentValueLength;

    String label;

    AttributedString attributedLabel;

    String value;

    AttributedString attributedValue;

    String increasedValue;

    AttributedString attributedIncreasedValue;

    String decreasedValue;

    AttributedString attributedDecreasedValue;

    String hint;

    AttributedString attributedHint;

    String tooltip;

    SemanticsHintOverrides hintOverrides;

    TextDirection textDirection;

    SemanticsSortKey sortKey;

    SemanticsTag tagForChildren;

    VoidCallback onTap;

    VoidCallback onLongPress;

    VoidCallback onScrollLeft;

    VoidCallback onScrollRight;

    VoidCallback onScrollUp;

    VoidCallback onScrollDown;

    VoidCallback onIncrease;

    VoidCallback onDecrease;

    VoidCallback onCopy;

    VoidCallback onCut;

    VoidCallback onPaste;

    MoveCursorHandler onMoveCursorForwardByCharacter;

    MoveCursorHandler onMoveCursorBackwardByCharacter;

    MoveCursorHandler onMoveCursorForwardByWord;

    MoveCursorHandler onMoveCursorBackwardByWord;

    SetSelectionHandler onSetSelection;

    SetTextHandler onSetText;

    VoidCallback onDidGainAccessibilityFocus;

    VoidCallback onDidLoseAccessibilityFocus;

    VoidCallback onDismiss;

    Map<CustomSemanticsAction, VoidCallback> customSemanticsActions;


     SemanticsPropertiesCls(AttributedString attributedDecreasedValue, AttributedString attributedHint, AttributedString attributedIncreasedValue, AttributedString attributedLabel, AttributedString attributedValue, bool button, bool checked, int currentValueLength, Map<CustomSemanticsAction, VoidCallback> customSemanticsActions, String decreasedValue, bool enabled, bool focusable, bool focused, bool header, bool hidden, String hint, SemanticsHintOverrides hintOverrides, bool image, bool inMutuallyExclusiveGroup, String increasedValue, bool keyboardKey, String label, bool link, bool liveRegion, int maxValueLength, bool multiline, bool namesRoute, bool obscured, VoidCallback onCopy, VoidCallback onCut, VoidCallback onDecrease, VoidCallback onDidGainAccessibilityFocus, VoidCallback onDidLoseAccessibilityFocus, VoidCallback onDismiss, VoidCallback onIncrease, VoidCallback onLongPress, MoveCursorHandler onMoveCursorBackwardByCharacter, MoveCursorHandler onMoveCursorBackwardByWord, MoveCursorHandler onMoveCursorForwardByCharacter, MoveCursorHandler onMoveCursorForwardByWord, VoidCallback onPaste, VoidCallback onScrollDown, VoidCallback onScrollLeft, VoidCallback onScrollRight, VoidCallback onScrollUp, SetSelectionHandler onSetSelection, SetTextHandler onSetText, VoidCallback onTap, bool readOnly, bool scopesRoute, bool selected, bool slider, SemanticsSortKey sortKey, SemanticsTag tagForChildren, TextDirection textDirection, bool textField, bool toggled, String tooltip, String value);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual String toStringShort();

private:

};
using SemanticsProperties = std::shared_ptr<SemanticsPropertiesCls>;
void debugResetSemanticsIdCounter();


class SemanticsNodeCls : public AbstractNodeCls {
public:
    Key key;

    Rect parentSemanticsClipRect;

    Rect parentPaintClipRect;

    double elevationAdjustment;

    int indexInParent;

    Set<SemanticsTag> tags;


     SemanticsNodeCls(Key key, VoidCallback showOnScreen);

    virtual void  root(Key key, SemanticsOwner owner, VoidCallback showOnScreen);

    virtual int id();

    virtual Matrix4 transform();

    virtual void  transform(Matrix4 value);

    virtual Rect rect();

    virtual void  rect(Rect value);

    virtual bool isInvisible();

    virtual bool isMergedIntoParent();

    virtual void  isMergedIntoParent(bool value);

    virtual bool isPartOfNodeMerging();

    virtual bool mergeAllDescendantsIntoThisNode();

    virtual bool hasChildren();

    virtual int childrenCount();

    virtual void visitChildren(SemanticsNodeVisitor visitor);

    virtual SemanticsOwner owner();

    virtual SemanticsNode parent();

    virtual void redepthChildren();

    virtual void attach(SemanticsOwner owner);

    virtual void detach();

    virtual bool isTagged(SemanticsTag tag);

    virtual bool hasFlag(SemanticsFlag flag);

    virtual String label();

    virtual AttributedString attributedLabel();

    virtual String value();

    virtual AttributedString attributedValue();

    virtual String increasedValue();

    virtual AttributedString attributedIncreasedValue();

    virtual String decreasedValue();

    virtual AttributedString attributedDecreasedValue();

    virtual String hint();

    virtual AttributedString attributedHint();

    virtual String tooltip();

    virtual double elevation();

    virtual double thickness();

    virtual SemanticsHintOverrides hintOverrides();

    virtual TextDirection textDirection();

    virtual SemanticsSortKey sortKey();

    virtual TextSelection textSelection();

    virtual bool isMultiline();

    virtual int scrollChildCount();

    virtual int scrollIndex();

    virtual double scrollPosition();

    virtual double scrollExtentMax();

    virtual double scrollExtentMin();

    virtual int platformViewId();

    virtual int maxValueLength();

    virtual int currentValueLength();

    virtual void updateWith(List<SemanticsNode> childrenInInversePaintOrder, SemanticsConfiguration config);

    virtual SemanticsData getSemanticsData();

    virtual void sendEvent(SemanticsEvent event);

    virtual String toStringShort();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual String toStringDeep(DebugSemanticsDumpOrder childOrder, DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines);

    virtual DiagnosticsNode toDiagnosticsNode(DebugSemanticsDumpOrder childOrder, String name, DiagnosticsTreeStyle style);

    virtual List<DiagnosticsNode> debugDescribeChildren(DebugSemanticsDumpOrder childOrder);

    virtual List<SemanticsNode> debugListChildrenInOrder(DebugSemanticsDumpOrder childOrder);

private:
    static int _maxFrameworkAccessibilityIdentifier;

    static int _lastIdentifier;

    int _id;

    VoidCallback _showOnScreen;

    Matrix4 _transform;

    Rect _rect;

    bool _isMergedIntoParent;

    bool _mergeAllDescendantsIntoThisNode;

    List<SemanticsNode> _children;

    List<SemanticsNode> _debugPreviousSnapshot;

    bool _dead;

    bool _dirty;

    Map<SemanticsAction, SemanticsActionHandler> _actions;

    Map<CustomSemanticsAction, VoidCallback> _customSemanticsActions;

    int _actionsAsBits;

    int _flags;

    AttributedString _attributedLabel;

    AttributedString _attributedValue;

    AttributedString _attributedIncreasedValue;

    AttributedString _attributedDecreasedValue;

    AttributedString _attributedHint;

    String _tooltip;

    double _elevation;

    double _thickness;

    SemanticsHintOverrides _hintOverrides;

    TextDirection _textDirection;

    SemanticsSortKey _sortKey;

    TextSelection _textSelection;

    bool _isMultiline;

    int _scrollChildCount;

    int _scrollIndex;

    double _scrollPosition;

    double _scrollExtentMax;

    double _scrollExtentMin;

    int _platformViewId;

    int _maxValueLength;

    int _currentValueLength;

    static SemanticsConfiguration _kEmptyConfig;

    static Int32List _kEmptyChildList;

    static Int32List _kEmptyCustomSemanticsActionsList;

    static Float64List _kIdentityTransform;


    static int _generateNewId();

    virtual void _replaceChildren(List<SemanticsNode> newChildren);

    virtual bool _visitDescendants(SemanticsNodeVisitor visitor);

    virtual void _markDirty();

    virtual bool _isDifferentFromCurrentSemanticAnnotation(SemanticsConfiguration config);

    virtual bool _canPerformAction(SemanticsAction action);

    static Float64List _initIdentityTransform();

    virtual void _addToUpdate(SemanticsUpdateBuilder builder, Set<int> customSemanticsActionIdsUpdate);

    virtual List<SemanticsNode> _childrenInTraversalOrder();

};
using SemanticsNode = std::shared_ptr<SemanticsNodeCls>;

class _BoxEdgeCls : public ObjectCls {
public:
    bool isLeadingEdge;

    double offset;

    SemanticsNode node;


    virtual int compareTo(_BoxEdge other);

private:

     _BoxEdgeCls(bool isLeadingEdge, SemanticsNode node, double offset);

};
using _BoxEdge = std::shared_ptr<_BoxEdgeCls>;

class _SemanticsSortGroupCls : public ComparableCls<_SemanticsSortGroup> {
public:
    double startOffset;

    TextDirection textDirection;

    List<SemanticsNode> nodes;


    virtual int compareTo(_SemanticsSortGroup other);

    virtual List<SemanticsNode> sortedWithinVerticalGroup();

    virtual List<SemanticsNode> sortedWithinKnot();

private:

     _SemanticsSortGroupCls(double startOffset, TextDirection textDirection);

};
using _SemanticsSortGroup = std::shared_ptr<_SemanticsSortGroupCls>;
Offset _pointInParentCoordinates(SemanticsNode node, Offset point);

List<SemanticsNode> _childrenInDefaultOrder(List<SemanticsNode> children, TextDirection textDirection);


class _TraversalSortNodeCls : public ObjectCls {
public:
    SemanticsNode node;

    SemanticsSortKey sortKey;

    int position;


    virtual int compareTo(_TraversalSortNode other);

private:

     _TraversalSortNodeCls(SemanticsNode node, int position, SemanticsSortKey sortKey);

};
using _TraversalSortNode = std::shared_ptr<_TraversalSortNodeCls>;

class SemanticsOwnerCls : public ChangeNotifierCls {
public:

    virtual SemanticsNode rootSemanticsNode();

    virtual void dispose();

    virtual void sendSemanticsUpdate();

    virtual void performAction(SemanticsAction action, Object args, int id);

    virtual void performActionAt(SemanticsAction action, Object args, Offset position);

    virtual String toString();

private:
    Set<SemanticsNode> _dirtyNodes;

    Map<int, SemanticsNode> _nodes;

    Set<SemanticsNode> _detachedNodes;


    virtual SemanticsActionHandler _getSemanticsActionHandlerForId(SemanticsAction action, int id);

    virtual SemanticsActionHandler _getSemanticsActionHandlerForPosition(SemanticsAction action, SemanticsNode node, Offset position);

};
using SemanticsOwner = std::shared_ptr<SemanticsOwnerCls>;

class SemanticsConfigurationCls : public ObjectCls {
public:
    bool explicitChildNodes;

    bool isBlockingSemanticsOfPreviouslyPaintedNodes;


    virtual bool isSemanticBoundary();

    virtual void  isSemanticBoundary(bool value);

    virtual bool hasBeenAnnotated();

    virtual VoidCallback onTap();

    virtual void  onTap(VoidCallback value);

    virtual VoidCallback onLongPress();

    virtual void  onLongPress(VoidCallback value);

    virtual VoidCallback onScrollLeft();

    virtual void  onScrollLeft(VoidCallback value);

    virtual VoidCallback onDismiss();

    virtual void  onDismiss(VoidCallback value);

    virtual VoidCallback onScrollRight();

    virtual void  onScrollRight(VoidCallback value);

    virtual VoidCallback onScrollUp();

    virtual void  onScrollUp(VoidCallback value);

    virtual VoidCallback onScrollDown();

    virtual void  onScrollDown(VoidCallback value);

    virtual VoidCallback onIncrease();

    virtual void  onIncrease(VoidCallback value);

    virtual VoidCallback onDecrease();

    virtual void  onDecrease(VoidCallback value);

    virtual VoidCallback onCopy();

    virtual void  onCopy(VoidCallback value);

    virtual VoidCallback onCut();

    virtual void  onCut(VoidCallback value);

    virtual VoidCallback onPaste();

    virtual void  onPaste(VoidCallback value);

    virtual VoidCallback onShowOnScreen();

    virtual void  onShowOnScreen(VoidCallback value);

    virtual MoveCursorHandler onMoveCursorForwardByCharacter();

    virtual void  onMoveCursorForwardByCharacter(MoveCursorHandler value);

    virtual MoveCursorHandler onMoveCursorBackwardByCharacter();

    virtual void  onMoveCursorBackwardByCharacter(MoveCursorHandler value);

    virtual MoveCursorHandler onMoveCursorForwardByWord();

    virtual void  onMoveCursorForwardByWord(MoveCursorHandler value);

    virtual MoveCursorHandler onMoveCursorBackwardByWord();

    virtual void  onMoveCursorBackwardByWord(MoveCursorHandler value);

    virtual SetSelectionHandler onSetSelection();

    virtual void  onSetSelection(SetSelectionHandler value);

    virtual SetTextHandler onSetText();

    virtual void  onSetText(SetTextHandler value);

    virtual VoidCallback onDidGainAccessibilityFocus();

    virtual void  onDidGainAccessibilityFocus(VoidCallback value);

    virtual VoidCallback onDidLoseAccessibilityFocus();

    virtual void  onDidLoseAccessibilityFocus(VoidCallback value);

    virtual SemanticsActionHandler getActionHandler(SemanticsAction action);

    virtual SemanticsSortKey sortKey();

    virtual void  sortKey(SemanticsSortKey value);

    virtual int indexInParent();

    virtual void  indexInParent(int value);

    virtual int scrollChildCount();

    virtual void  scrollChildCount(int value);

    virtual int scrollIndex();

    virtual void  scrollIndex(int value);

    virtual int platformViewId();

    virtual void  platformViewId(int value);

    virtual int maxValueLength();

    virtual void  maxValueLength(int value);

    virtual int currentValueLength();

    virtual void  currentValueLength(int value);

    virtual bool isMergingSemanticsOfDescendants();

    virtual void  isMergingSemanticsOfDescendants(bool value);

    virtual Map<CustomSemanticsAction, VoidCallback> customSemanticsActions();

    virtual void  customSemanticsActions(Map<CustomSemanticsAction, VoidCallback> value);

    virtual String label();

    virtual void  label(String label);

    virtual AttributedString attributedLabel();

    virtual void  attributedLabel(AttributedString attributedLabel);

    virtual String value();

    virtual void  value(String value);

    virtual AttributedString attributedValue();

    virtual void  attributedValue(AttributedString attributedValue);

    virtual String increasedValue();

    virtual void  increasedValue(String increasedValue);

    virtual AttributedString attributedIncreasedValue();

    virtual void  attributedIncreasedValue(AttributedString attributedIncreasedValue);

    virtual String decreasedValue();

    virtual void  decreasedValue(String decreasedValue);

    virtual AttributedString attributedDecreasedValue();

    virtual void  attributedDecreasedValue(AttributedString attributedDecreasedValue);

    virtual String hint();

    virtual void  hint(String hint);

    virtual AttributedString attributedHint();

    virtual void  attributedHint(AttributedString attributedHint);

    virtual String tooltip();

    virtual void  tooltip(String tooltip);

    virtual SemanticsHintOverrides hintOverrides();

    virtual void  hintOverrides(SemanticsHintOverrides value);

    virtual double elevation();

    virtual void  elevation(double value);

    virtual double thickness();

    virtual void  thickness(double value);

    virtual bool scopesRoute();

    virtual void  scopesRoute(bool value);

    virtual bool namesRoute();

    virtual void  namesRoute(bool value);

    virtual bool isImage();

    virtual void  isImage(bool value);

    virtual bool liveRegion();

    virtual void  liveRegion(bool value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection textDirection);

    virtual bool isSelected();

    virtual void  isSelected(bool value);

    virtual bool isEnabled();

    virtual void  isEnabled(bool value);

    virtual bool isChecked();

    virtual void  isChecked(bool value);

    virtual bool isToggled();

    virtual void  isToggled(bool value);

    virtual bool isInMutuallyExclusiveGroup();

    virtual void  isInMutuallyExclusiveGroup(bool value);

    virtual bool isFocusable();

    virtual void  isFocusable(bool value);

    virtual bool isFocused();

    virtual void  isFocused(bool value);

    virtual bool isButton();

    virtual void  isButton(bool value);

    virtual bool isLink();

    virtual void  isLink(bool value);

    virtual bool isHeader();

    virtual void  isHeader(bool value);

    virtual bool isSlider();

    virtual void  isSlider(bool value);

    virtual bool isKeyboardKey();

    virtual void  isKeyboardKey(bool value);

    virtual bool isHidden();

    virtual void  isHidden(bool value);

    virtual bool isTextField();

    virtual void  isTextField(bool value);

    virtual bool isReadOnly();

    virtual void  isReadOnly(bool value);

    virtual bool isObscured();

    virtual void  isObscured(bool value);

    virtual bool isMultiline();

    virtual void  isMultiline(bool value);

    virtual bool hasImplicitScrolling();

    virtual void  hasImplicitScrolling(bool value);

    virtual TextSelection textSelection();

    virtual void  textSelection(TextSelection value);

    virtual double scrollPosition();

    virtual void  scrollPosition(double value);

    virtual double scrollExtentMax();

    virtual void  scrollExtentMax(double value);

    virtual double scrollExtentMin();

    virtual void  scrollExtentMin(double value);

    virtual Iterable<SemanticsTag> tagsForChildren();

    virtual void addTagForChildren(SemanticsTag tag);

    virtual bool isCompatibleWith(SemanticsConfiguration other);

    virtual void absorb(SemanticsConfiguration child);

    virtual SemanticsConfiguration copy();

private:
    bool _isSemanticBoundary;

    bool _hasBeenAnnotated;

    Map<SemanticsAction, SemanticsActionHandler> _actions;

    int _actionsAsBits;

    VoidCallback _onTap;

    VoidCallback _onLongPress;

    VoidCallback _onScrollLeft;

    VoidCallback _onDismiss;

    VoidCallback _onScrollRight;

    VoidCallback _onScrollUp;

    VoidCallback _onScrollDown;

    VoidCallback _onIncrease;

    VoidCallback _onDecrease;

    VoidCallback _onCopy;

    VoidCallback _onCut;

    VoidCallback _onPaste;

    VoidCallback _onShowOnScreen;

    MoveCursorHandler _onMoveCursorForwardByCharacter;

    MoveCursorHandler _onMoveCursorBackwardByCharacter;

    MoveCursorHandler _onMoveCursorForwardByWord;

    MoveCursorHandler _onMoveCursorBackwardByWord;

    SetSelectionHandler _onSetSelection;

    SetTextHandler _onSetText;

    VoidCallback _onDidGainAccessibilityFocus;

    VoidCallback _onDidLoseAccessibilityFocus;

    SemanticsSortKey _sortKey;

    int _indexInParent;

    int _scrollChildCount;

    int _scrollIndex;

    int _platformViewId;

    int _maxValueLength;

    int _currentValueLength;

    bool _isMergingSemanticsOfDescendants;

    Map<CustomSemanticsAction, VoidCallback> _customSemanticsActions;

    AttributedString _attributedLabel;

    AttributedString _attributedValue;

    AttributedString _attributedIncreasedValue;

    AttributedString _attributedDecreasedValue;

    AttributedString _attributedHint;

    String _tooltip;

    SemanticsHintOverrides _hintOverrides;

    double _elevation;

    double _thickness;

    TextDirection _textDirection;

    TextSelection _textSelection;

    double _scrollPosition;

    double _scrollExtentMax;

    double _scrollExtentMin;

    Set<SemanticsTag> _tagsForChildren;

    int _flags;


    virtual void _addAction(SemanticsAction action, SemanticsActionHandler handler);

    virtual void _addArgumentlessAction(SemanticsAction action, VoidCallback handler);

    virtual void _onCustomSemanticsAction(Object args);

    virtual void _setFlag(SemanticsFlag flag, bool value);

    virtual bool _hasFlag(SemanticsFlag flag);

};
using SemanticsConfiguration = std::shared_ptr<SemanticsConfigurationCls>;

enum DebugSemanticsDumpOrder{
    inverseHitTest,
    traversalOrder,
} // end DebugSemanticsDumpOrder
AttributedString _concatAttributedString(AttributedString otherAttributedString, TextDirection otherTextDirection, AttributedString thisAttributedString, TextDirection thisTextDirection);


class SemanticsSortKeyCls : public ObjectCls {
public:
    String name;


     SemanticsSortKeyCls(String name);
    virtual int compareTo(SemanticsSortKey other);

    virtual int doCompare(SemanticsSortKey other);
    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SemanticsSortKey = std::shared_ptr<SemanticsSortKeyCls>;

class OrdinalSortKeyCls : public SemanticsSortKeyCls {
public:
    double order;


     OrdinalSortKeyCls(Unknown name, double order);

    virtual int doCompare(OrdinalSortKey other);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using OrdinalSortKey = std::shared_ptr<OrdinalSortKeyCls>;


#endif