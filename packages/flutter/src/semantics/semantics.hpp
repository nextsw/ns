#ifndef SEMANTICS_H
#define SEMANTICS_H
#include <memory>
#include <ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/services.hpp>
#include <vector_math/vector_math_64.hpp>
#include "semantics_event.hpp"

#include <math/math.hpp>
#include <ui/ui.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/painting.hpp>
#include <flutter/services.hpp>
#include <vector_math/vector_math_64.hpp>
#include "binding.hpp"
#include "semantics_event.hpp"



class SemanticsTag {
public:
    String name;


     SemanticsTag(String name);

    String toString();

private:

};

class CustomSemanticsAction {
public:
    String label;

    String hint;

    SemanticsAction action;


     CustomSemanticsAction(String label);

    void  overridingAction(SemanticsAction action, String hint);

    int hashCode();

    bool ==(Object other);

    String toString();

    static int getIdentifier(CustomSemanticsAction action);

    static CustomSemanticsAction getAction(int id);

private:
    static int _nextId;

    static Map<int, CustomSemanticsAction> _actions;

    static Map<CustomSemanticsAction, int> _ids;


};

class AttributedString {
public:
    String string;

    List<StringAttribute> attributes;


     AttributedString(List<StringAttribute> attributes, String string);

    AttributedString +(AttributedString other);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class AttributedStringProperty : DiagnosticsProperty<AttributedString> {
public:
    bool showWhenEmpty;


     AttributedStringProperty(Unknown, Unknown, Unknown, String name, Unknown, bool showWhenEmpty, Unknown);

    bool isInteresting();

    String valueToString(TextTreeConfiguration parentConfiguration);

private:

};

class SemanticsData {
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


     SemanticsData(int actions, AttributedString attributedDecreasedValue, AttributedString attributedHint, AttributedString attributedIncreasedValue, AttributedString attributedLabel, AttributedString attributedValue, int currentValueLength, List<int> customSemanticsActionIds, double elevation, int flags, int maxValueLength, int platformViewId, Rect rect, int scrollChildCount, double scrollExtentMax, double scrollExtentMin, int scrollIndex, double scrollPosition, Set<SemanticsTag> tags, TextDirection textDirection, TextSelection textSelection, double thickness, String tooltip, Matrix4 transform);

    String label();

    String value();

    String increasedValue();

    String decreasedValue();

    String hint();

    bool hasFlag(SemanticsFlag flag);

    bool hasAction(SemanticsAction action);

    String toStringShort();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    bool ==(Object other);

    int hashCode();

private:

    static bool _sortedListsEqual(List<int> left, List<int> right);

};

class _SemanticsDiagnosticableNode : DiagnosticableNode<SemanticsNode> {
public:
    DebugSemanticsDumpOrder childOrder;


    List<DiagnosticsNode> getChildren();

private:

     _SemanticsDiagnosticableNode(DebugSemanticsDumpOrder childOrder, Unknown, Unknown, Unknown);

};

class SemanticsHintOverrides : DiagnosticableTree {
public:
    String onTapHint;

    String onLongPressHint;


     SemanticsHintOverrides(String onLongPressHint, String onTapHint);

    bool isNotEmpty();

    int hashCode();

    bool ==(Object other);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class SemanticsProperties : DiagnosticableTree {
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


     SemanticsProperties(AttributedString attributedDecreasedValue, AttributedString attributedHint, AttributedString attributedIncreasedValue, AttributedString attributedLabel, AttributedString attributedValue, bool button, bool checked, int currentValueLength, Map<CustomSemanticsAction, VoidCallback> customSemanticsActions, String decreasedValue, bool enabled, bool focusable, bool focused, bool header, bool hidden, String hint, SemanticsHintOverrides hintOverrides, bool image, bool inMutuallyExclusiveGroup, String increasedValue, bool keyboardKey, String label, bool link, bool liveRegion, int maxValueLength, bool multiline, bool namesRoute, bool obscured, VoidCallback onCopy, VoidCallback onCut, VoidCallback onDecrease, VoidCallback onDidGainAccessibilityFocus, VoidCallback onDidLoseAccessibilityFocus, VoidCallback onDismiss, VoidCallback onIncrease, VoidCallback onLongPress, MoveCursorHandler onMoveCursorBackwardByCharacter, MoveCursorHandler onMoveCursorBackwardByWord, MoveCursorHandler onMoveCursorForwardByCharacter, MoveCursorHandler onMoveCursorForwardByWord, VoidCallback onPaste, VoidCallback onScrollDown, VoidCallback onScrollLeft, VoidCallback onScrollRight, VoidCallback onScrollUp, SetSelectionHandler onSetSelection, SetTextHandler onSetText, VoidCallback onTap, bool readOnly, bool scopesRoute, bool selected, bool slider, SemanticsSortKey sortKey, SemanticsTag tagForChildren, TextDirection textDirection, bool textField, bool toggled, String tooltip, String value);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    String toStringShort();

private:

};
void debugResetSemanticsIdCounter();


class SemanticsNode : AbstractNode {
public:
    Key key;

    Rect parentSemanticsClipRect;

    Rect parentPaintClipRect;

    double elevationAdjustment;

    int indexInParent;

    Set<SemanticsTag> tags;


     SemanticsNode(Key key, VoidCallback showOnScreen);

    void  root(Key key, SemanticsOwner owner, VoidCallback showOnScreen);

    int id();

    Matrix4 transform();

    void  transform(Matrix4 value);

    Rect rect();

    void  rect(Rect value);

    bool isInvisible();

    bool isMergedIntoParent();

    void  isMergedIntoParent(bool value);

    bool isPartOfNodeMerging();

    bool mergeAllDescendantsIntoThisNode();

    bool hasChildren();

    int childrenCount();

    void visitChildren(SemanticsNodeVisitor visitor);

    SemanticsOwner owner();

    SemanticsNode parent();

    void redepthChildren();

    void attach(SemanticsOwner owner);

    void detach();

    bool isTagged(SemanticsTag tag);

    bool hasFlag(SemanticsFlag flag);

    String label();

    AttributedString attributedLabel();

    String value();

    AttributedString attributedValue();

    String increasedValue();

    AttributedString attributedIncreasedValue();

    String decreasedValue();

    AttributedString attributedDecreasedValue();

    String hint();

    AttributedString attributedHint();

    String tooltip();

    double elevation();

    double thickness();

    SemanticsHintOverrides hintOverrides();

    TextDirection textDirection();

    SemanticsSortKey sortKey();

    TextSelection textSelection();

    bool isMultiline();

    int scrollChildCount();

    int scrollIndex();

    double scrollPosition();

    double scrollExtentMax();

    double scrollExtentMin();

    int platformViewId();

    int maxValueLength();

    int currentValueLength();

    void updateWith(List<SemanticsNode> childrenInInversePaintOrder, SemanticsConfiguration config);

    SemanticsData getSemanticsData();

    void sendEvent(SemanticsEvent event);

    String toStringShort();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    String toStringDeep(DebugSemanticsDumpOrder childOrder, DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines);

    DiagnosticsNode toDiagnosticsNode(DebugSemanticsDumpOrder childOrder, String name, DiagnosticsTreeStyle style);

    List<DiagnosticsNode> debugDescribeChildren(DebugSemanticsDumpOrder childOrder);

    List<SemanticsNode> debugListChildrenInOrder(DebugSemanticsDumpOrder childOrder);

private:
    static const int _maxFrameworkAccessibilityIdentifier;

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

    void _replaceChildren(List<SemanticsNode> newChildren);

    bool _visitDescendants(SemanticsNodeVisitor visitor);

    void _markDirty();

    bool _isDifferentFromCurrentSemanticAnnotation(SemanticsConfiguration config);

    bool _canPerformAction(SemanticsAction action);

    static Float64List _initIdentityTransform();

    void _addToUpdate(SemanticsUpdateBuilder builder, Set<int> customSemanticsActionIdsUpdate);

    List<SemanticsNode> _childrenInTraversalOrder();

};

class _BoxEdge {
public:
    bool isLeadingEdge;

    double offset;

    SemanticsNode node;


    int compareTo(_BoxEdge other);

private:

     _BoxEdge(bool isLeadingEdge, SemanticsNode node, double offset);

};

class _SemanticsSortGroup : Comparable<_SemanticsSortGroup> {
public:
    double startOffset;

    TextDirection textDirection;

    List<SemanticsNode> nodes;


    int compareTo(_SemanticsSortGroup other);

    List<SemanticsNode> sortedWithinVerticalGroup();

    List<SemanticsNode> sortedWithinKnot();

private:

     _SemanticsSortGroup(double startOffset, TextDirection textDirection);

};
Offset _pointInParentCoordinates(SemanticsNode node, Offset point);

List<SemanticsNode> _childrenInDefaultOrder(List<SemanticsNode> children, TextDirection textDirection);


class _TraversalSortNode {
public:
    SemanticsNode node;

    SemanticsSortKey sortKey;

    int position;


    int compareTo(_TraversalSortNode other);

private:

     _TraversalSortNode(SemanticsNode node, int position, SemanticsSortKey sortKey);

};

class SemanticsOwner : ChangeNotifier {
public:

    SemanticsNode rootSemanticsNode();

    void dispose();

    void sendSemanticsUpdate();

    void performAction(SemanticsAction action, Object args, int id);

    void performActionAt(SemanticsAction action, Object args, Offset position);

    String toString();

private:
    Set<SemanticsNode> _dirtyNodes;

    Map<int, SemanticsNode> _nodes;

    Set<SemanticsNode> _detachedNodes;


    SemanticsActionHandler _getSemanticsActionHandlerForId(SemanticsAction action, int id);

    SemanticsActionHandler _getSemanticsActionHandlerForPosition(SemanticsAction action, SemanticsNode node, Offset position);

};

class SemanticsConfiguration {
public:
    bool explicitChildNodes;

    bool isBlockingSemanticsOfPreviouslyPaintedNodes;


    bool isSemanticBoundary();

    void  isSemanticBoundary(bool value);

    bool hasBeenAnnotated();

    VoidCallback onTap();

    void  onTap(VoidCallback value);

    VoidCallback onLongPress();

    void  onLongPress(VoidCallback value);

    VoidCallback onScrollLeft();

    void  onScrollLeft(VoidCallback value);

    VoidCallback onDismiss();

    void  onDismiss(VoidCallback value);

    VoidCallback onScrollRight();

    void  onScrollRight(VoidCallback value);

    VoidCallback onScrollUp();

    void  onScrollUp(VoidCallback value);

    VoidCallback onScrollDown();

    void  onScrollDown(VoidCallback value);

    VoidCallback onIncrease();

    void  onIncrease(VoidCallback value);

    VoidCallback onDecrease();

    void  onDecrease(VoidCallback value);

    VoidCallback onCopy();

    void  onCopy(VoidCallback value);

    VoidCallback onCut();

    void  onCut(VoidCallback value);

    VoidCallback onPaste();

    void  onPaste(VoidCallback value);

    VoidCallback onShowOnScreen();

    void  onShowOnScreen(VoidCallback value);

    MoveCursorHandler onMoveCursorForwardByCharacter();

    void  onMoveCursorForwardByCharacter(MoveCursorHandler value);

    MoveCursorHandler onMoveCursorBackwardByCharacter();

    void  onMoveCursorBackwardByCharacter(MoveCursorHandler value);

    MoveCursorHandler onMoveCursorForwardByWord();

    void  onMoveCursorForwardByWord(MoveCursorHandler value);

    MoveCursorHandler onMoveCursorBackwardByWord();

    void  onMoveCursorBackwardByWord(MoveCursorHandler value);

    SetSelectionHandler onSetSelection();

    void  onSetSelection(SetSelectionHandler value);

    SetTextHandler onSetText();

    void  onSetText(SetTextHandler value);

    VoidCallback onDidGainAccessibilityFocus();

    void  onDidGainAccessibilityFocus(VoidCallback value);

    VoidCallback onDidLoseAccessibilityFocus();

    void  onDidLoseAccessibilityFocus(VoidCallback value);

    SemanticsActionHandler getActionHandler(SemanticsAction action);

    SemanticsSortKey sortKey();

    void  sortKey(SemanticsSortKey value);

    int indexInParent();

    void  indexInParent(int value);

    int scrollChildCount();

    void  scrollChildCount(int value);

    int scrollIndex();

    void  scrollIndex(int value);

    int platformViewId();

    void  platformViewId(int value);

    int maxValueLength();

    void  maxValueLength(int value);

    int currentValueLength();

    void  currentValueLength(int value);

    bool isMergingSemanticsOfDescendants();

    void  isMergingSemanticsOfDescendants(bool value);

    Map<CustomSemanticsAction, VoidCallback> customSemanticsActions();

    void  customSemanticsActions(Map<CustomSemanticsAction, VoidCallback> value);

    String label();

    void  label(String label);

    AttributedString attributedLabel();

    void  attributedLabel(AttributedString attributedLabel);

    String value();

    void  value(String value);

    AttributedString attributedValue();

    void  attributedValue(AttributedString attributedValue);

    String increasedValue();

    void  increasedValue(String increasedValue);

    AttributedString attributedIncreasedValue();

    void  attributedIncreasedValue(AttributedString attributedIncreasedValue);

    String decreasedValue();

    void  decreasedValue(String decreasedValue);

    AttributedString attributedDecreasedValue();

    void  attributedDecreasedValue(AttributedString attributedDecreasedValue);

    String hint();

    void  hint(String hint);

    AttributedString attributedHint();

    void  attributedHint(AttributedString attributedHint);

    String tooltip();

    void  tooltip(String tooltip);

    SemanticsHintOverrides hintOverrides();

    void  hintOverrides(SemanticsHintOverrides value);

    double elevation();

    void  elevation(double value);

    double thickness();

    void  thickness(double value);

    bool scopesRoute();

    void  scopesRoute(bool value);

    bool namesRoute();

    void  namesRoute(bool value);

    bool isImage();

    void  isImage(bool value);

    bool liveRegion();

    void  liveRegion(bool value);

    TextDirection textDirection();

    void  textDirection(TextDirection textDirection);

    bool isSelected();

    void  isSelected(bool value);

    bool isEnabled();

    void  isEnabled(bool value);

    bool isChecked();

    void  isChecked(bool value);

    bool isToggled();

    void  isToggled(bool value);

    bool isInMutuallyExclusiveGroup();

    void  isInMutuallyExclusiveGroup(bool value);

    bool isFocusable();

    void  isFocusable(bool value);

    bool isFocused();

    void  isFocused(bool value);

    bool isButton();

    void  isButton(bool value);

    bool isLink();

    void  isLink(bool value);

    bool isHeader();

    void  isHeader(bool value);

    bool isSlider();

    void  isSlider(bool value);

    bool isKeyboardKey();

    void  isKeyboardKey(bool value);

    bool isHidden();

    void  isHidden(bool value);

    bool isTextField();

    void  isTextField(bool value);

    bool isReadOnly();

    void  isReadOnly(bool value);

    bool isObscured();

    void  isObscured(bool value);

    bool isMultiline();

    void  isMultiline(bool value);

    bool hasImplicitScrolling();

    void  hasImplicitScrolling(bool value);

    TextSelection textSelection();

    void  textSelection(TextSelection value);

    double scrollPosition();

    void  scrollPosition(double value);

    double scrollExtentMax();

    void  scrollExtentMax(double value);

    double scrollExtentMin();

    void  scrollExtentMin(double value);

    Iterable<SemanticsTag> tagsForChildren();

    void addTagForChildren(SemanticsTag tag);

    bool isCompatibleWith(SemanticsConfiguration other);

    void absorb(SemanticsConfiguration child);

    SemanticsConfiguration copy();

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


    void _addAction(SemanticsAction action, SemanticsActionHandler handler);

    void _addArgumentlessAction(SemanticsAction action, VoidCallback handler);

    void _onCustomSemanticsAction(Object args);

    void _setFlag(SemanticsFlag flag, bool value);

    bool _hasFlag(SemanticsFlag flag);

};

enum DebugSemanticsDumpOrder{
    inverseHitTest,
    traversalOrder,
} // end DebugSemanticsDumpOrder
AttributedString _concatAttributedString(AttributedString otherAttributedString, TextDirection otherTextDirection, AttributedString thisAttributedString, TextDirection thisTextDirection);


class SemanticsSortKey {
public:
    String name;


     SemanticsSortKey(String name);

    int compareTo(SemanticsSortKey other);

    int doCompare(SemanticsSortKey other);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class OrdinalSortKey : SemanticsSortKey {
public:
    double order;


     OrdinalSortKey(Unknown, double order);

    int doCompare(OrdinalSortKey other);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif