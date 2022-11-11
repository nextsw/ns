#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_EDITABLE_TEXT
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_EDITABLE_TEXT
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/characters/characters.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "actions.hpp"
#include "autofill.hpp"
#include "automatic_keep_alive.hpp"
#include "basic.hpp"
#include "binding.hpp"
#include "constants.hpp"
#include "debug.hpp"
#include "default_selection_style.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "focus_traversal.hpp"
#include "framework.hpp"
#include "localizations.hpp"
#include "media_query.hpp"
#include "scroll_configuration.hpp"
#include "scroll_controller.hpp"
#include "scroll_physics.hpp"
#include "scrollable.hpp"
#include "shortcuts.hpp"
#include "text.hpp"
#include "text_editing_intents.hpp"
#include "text_selection.hpp"
#include "ticker_provider.hpp"
#include "widget_span.hpp"

Duration _kCursorBlinkHalfPeriod;

int _kObscureShowLatestCharCursorTicks;

double _kIPadWidth;


class TextEditingControllerCls : public ValueNotifierCls<TextEditingValue> {
public:

     TextEditingControllerCls(String text);

    virtual void  fromValue(TextEditingValue value);

    virtual String text();

    virtual void  text(String newText);

    virtual void  value(TextEditingValue newValue);

    virtual TextSpan buildTextSpan(BuildContext context, TextStyle style, bool withComposing);

    virtual TextSelection selection();

    virtual void  selection(TextSelection newSelection);

    virtual void clear();

    virtual void clearComposing();

    virtual bool isSelectionWithinTextBounds(TextSelection selection);

private:

    virtual bool _isSelectionWithinComposingRange(TextSelection selection);

};
using TextEditingController = std::shared_ptr<TextEditingControllerCls>;

class ToolbarOptionsCls : public ObjectCls {
public:
    bool copy;

    bool cut;

    bool paste;

    bool selectAll;


     ToolbarOptionsCls(bool copy, bool cut, bool paste, bool selectAll);

private:

};
using ToolbarOptions = std::shared_ptr<ToolbarOptionsCls>;

class _KeyFrameCls : public ObjectCls {
public:
    static List<_KeyFrame> iOSBlinkingCaretKeyFrames;

    double time;

    double value;


private:

     _KeyFrameCls(double time, double value);
};
using _KeyFrame = std::shared_ptr<_KeyFrameCls>;

class _DiscreteKeyFrameSimulationCls : public SimulationCls {
public:
    double maxDuration;


    virtual void  iOSBlinkingCaret();

    virtual double dx(double time);

    virtual bool isDone(double time);

    virtual double x(double time);

private:
    List<_KeyFrame> _keyFrames;

    int _lastKeyFrameIndex;


    virtual void  _(List<_KeyFrame> _keyFrames, double maxDuration);

};
using _DiscreteKeyFrameSimulation = std::shared_ptr<_DiscreteKeyFrameSimulationCls>;

class EditableTextCls : public StatefulWidgetCls {
public:
    TextEditingController controller;

    FocusNode focusNode;

    String obscuringCharacter;

    bool obscureText;

    TextHeightBehavior textHeightBehavior;

    TextWidthBasis textWidthBasis;

    bool readOnly;

    bool forceLine;

    ToolbarOptions toolbarOptions;

    bool showSelectionHandles;

    bool showCursor;

    bool autocorrect;

    SmartDashesType smartDashesType;

    SmartQuotesType smartQuotesType;

    bool enableSuggestions;

    TextStyle style;

    TextAlign textAlign;

    TextDirection textDirection;

    TextCapitalization textCapitalization;

    Locale locale;

    double textScaleFactor;

    Color cursorColor;

    Color autocorrectionTextRectColor;

    Color backgroundCursorColor;

    int maxLines;

    int minLines;

    bool expands;

    bool autofocus;

    Color selectionColor;

    TextSelectionControls selectionControls;

    TextInputType keyboardType;

    TextInputAction textInputAction;

    ValueChanged<String> onChanged;

    VoidCallback onEditingComplete;

    ValueChanged<String> onSubmitted;

    AppPrivateCommandCallback onAppPrivateCommand;

    SelectionChangedCallback onSelectionChanged;

    VoidCallback onSelectionHandleTapped;

    List<TextInputFormatter> inputFormatters;

    MouseCursor mouseCursor;

    bool rendererIgnoresPointer;

    double cursorWidth;

    double cursorHeight;

    Radius cursorRadius;

    bool cursorOpacityAnimates;

    Offset cursorOffset;

    bool paintCursorAboveText;

    BoxHeightStyle selectionHeightStyle;

    BoxWidthStyle selectionWidthStyle;

    Brightness keyboardAppearance;

    EdgeInsets scrollPadding;

    bool enableInteractiveSelection;

    static bool debugDeterministicCursor;

    DragStartBehavior dragStartBehavior;

    ScrollController scrollController;

    ScrollPhysics scrollPhysics;

    bool scribbleEnabled;

    Iterable<String> autofillHints;

    AutofillClient autofillClient;

    Clip clipBehavior;

    String restorationId;

    ScrollBehavior scrollBehavior;

    bool enableIMEPersonalizedLearning;


     EditableTextCls(bool autocorrect, Color autocorrectionTextRectColor, AutofillClient autofillClient, Iterable<String> autofillHints, bool autofocus, Color backgroundCursorColor, Clip clipBehavior, TextEditingController controller, Color cursorColor, double cursorHeight, Offset cursorOffset, bool cursorOpacityAnimates, Radius cursorRadius, double cursorWidth, DragStartBehavior dragStartBehavior, bool enableIMEPersonalizedLearning, bool enableInteractiveSelection, bool enableSuggestions, bool expands, FocusNode focusNode, bool forceLine, List<TextInputFormatter> inputFormatters, Unknown key, Brightness keyboardAppearance, TextInputType keyboardType, Locale locale, int maxLines, int minLines, MouseCursor mouseCursor, bool obscureText, String obscuringCharacter, AppPrivateCommandCallback onAppPrivateCommand, ValueChanged<String> onChanged, VoidCallback onEditingComplete, SelectionChangedCallback onSelectionChanged, VoidCallback onSelectionHandleTapped, ValueChanged<String> onSubmitted, bool paintCursorAboveText, bool readOnly, bool rendererIgnoresPointer, String restorationId, bool scribbleEnabled, ScrollBehavior scrollBehavior, ScrollController scrollController, EdgeInsets scrollPadding, ScrollPhysics scrollPhysics, Color selectionColor, TextSelectionControls selectionControls, BoxHeightStyle selectionHeightStyle, BoxWidthStyle selectionWidthStyle, bool showCursor, bool showSelectionHandles, SmartDashesType smartDashesType, SmartQuotesType smartQuotesType, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextCapitalization textCapitalization, TextDirection textDirection, TextHeightBehavior textHeightBehavior, TextInputAction textInputAction, double textScaleFactor, TextWidthBasis textWidthBasis, ToolbarOptions toolbarOptions);

    virtual StrutStyle strutStyle();

    virtual bool selectionEnabled();

    virtual EditableTextState createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    StrutStyle _strutStyle;


    virtual bool _userSelectionEnabled();

    static TextInputType _inferKeyboardType(Iterable<String> autofillHints, int maxLines);

};
using EditableText = std::shared_ptr<EditableTextCls>;

class EditableTextStateCls : public StateCls<EditableText> {
public:

    virtual AutofillScope currentAutofillScope();

    virtual bool wantKeepAlive();

    virtual bool cutEnabled();

    virtual bool copyEnabled();

    virtual bool pasteEnabled();

    virtual bool selectAllEnabled();

    virtual void copySelection(SelectionChangedCause cause);

    virtual void cutSelection(SelectionChangedCause cause);

    virtual Future<void> pasteText(SelectionChangedCause cause);

    virtual void selectAll(SelectionChangedCause cause);

    virtual void initState();

    virtual void didChangeDependencies();

    virtual void didUpdateWidget(EditableText oldWidget);

    virtual void dispose();

    virtual TextEditingValue currentTextEditingValue();

    virtual void updateEditingValue(TextEditingValue value);

    virtual void performAction(TextInputAction action);

    virtual void performPrivateCommand(String action, Map<String, dynamic> data);

    virtual void updateFloatingCursor(RawFloatingCursorPoint point);

    virtual void beginBatchEdit();

    virtual void endBatchEdit();

    virtual void connectionClosed();

    virtual void requestKeyboard();

    virtual void didChangeMetrics();

    virtual bool cursorCurrentlyVisible();

    virtual Duration cursorBlinkInterval();

    virtual TextSelectionOverlay selectionOverlay();

    virtual RenderEditable renderEditable();

    virtual TextEditingValue textEditingValue();

    virtual void userUpdateTextEditingValue(TextEditingValue value, SelectionChangedCause cause);

    virtual void bringIntoView(TextPosition position);

    virtual bool showToolbar();

    virtual void hideToolbar(bool hideHandles);

    virtual void toggleToolbar();

    virtual void insertTextPlaceholder(Size size);

    virtual void removeTextPlaceholder();

    virtual String autofillId();

    virtual TextInputConfiguration textInputConfiguration();

    virtual void autofill(TextEditingValue value);

    virtual void showAutocorrectionPromptRect(int start, int end);

    virtual Widget build(BuildContext context);

    virtual TextSpan buildTextSpan();

private:
    Timer _cursorTimer;

    AnimationController _backingCursorBlinkOpacityController;

    Simulation _iosBlinkCursorSimulation;

    ValueNotifier<bool> _cursorVisibilityNotifier;

    GlobalKey _editableKey;

    ClipboardStatusNotifier _clipboardStatus;

    TextInputConnection _textInputConnection;

    TextSelectionOverlay _selectionOverlay;

    ScrollController _internalScrollController;

    LayerLink _toolbarLayerLink;

    LayerLink _startHandleLayerLink;

    LayerLink _endHandleLayerLink;

    bool _didAutoFocus;

    AutofillGroupState _currentAutofillScope;

    static Duration _floatingCursorResetTime;

    AnimationController _floatingCursorResetController;

    Orientation _lastOrientation;

    bool _tickersEnabled;

    TextEditingValue _lastKnownRemoteTextEditingValue;

    Rect _startCaretRect;

    TextPosition _lastTextPosition;

    Offset _pointOffsetOrigin;

    Offset _lastBoundedOffset;

    int _batchEditDepth;

    bool _restartConnectionScheduled;

    Rect _currentCaretRect;

    static Duration _caretAnimationDuration;

    static Curve _caretAnimationCurve;

    bool _showCaretOnScreenScheduled;

    double _lastBottomViewInset;

    int _obscureShowCharTicksPending;

    int _obscureLatestCharIndex;

    bool _cursorActive;

    String _cachedText;

    Rect _cachedFirstRect;

    Size _cachedSize;

    int _cachedPlaceholder;

    TextStyle _cachedTextStyle;

    int _placeholderLocation;

    TextRange _currentPromptRectRange;

    Action<TransposeCharactersIntent> _transposeCharactersAction;

    Action<ReplaceTextIntent> _replaceTextAction;

    Action<UpdateSelectionIntent> _updateSelectionAction;

    _UpdateTextSelectionToAdjacentLineAction<ExtendSelectionVerticallyToAdjacentLineIntent> _adjacentLineAction;

    Map<Type, Action<Intent>> _actions;


    virtual AnimationController _cursorBlinkOpacityController();

    virtual ScrollController _scrollController();

    virtual AutofillClient _effectiveAutofillClient();

    virtual bool _shouldCreateInputConnection();

    virtual Color _cursorColor();

    virtual void _onChangedClipboardStatus();

    virtual TextEditingValue _textEditingValueforTextLayoutMetrics();

    virtual Offset _floatingCursorOffset();

    virtual void _onFloatingCursorResetTick();

    virtual void _finalizeEditing(TextInputAction action, bool shouldUnfocus);

    virtual void _updateRemoteEditingValueIfNeeded();

    virtual TextEditingValue _value();

    virtual void  _value(TextEditingValue value);

    virtual bool _hasFocus();

    virtual bool _isMultiline();

    virtual RevealedOffset _getOffsetToRevealCaret(Rect rect);

    virtual bool _hasInputConnection();

    virtual bool _needsAutofill();

    virtual void _openInputConnection();

    virtual void _closeInputConnectionIfNeeded();

    virtual void _openOrCloseInputConnectionIfNeeded();

    virtual void _scheduleRestartConnection();

    virtual void _restartConnectionIfNeeded();

    virtual void _updateOrDisposeSelectionOverlayIfNeeded();

    virtual void _updateSelectionOverlayForScroll();

    virtual void _createSelectionOverlay();

    virtual void _handleSelectionChanged(TextSelection selection, SelectionChangedCause cause);

    virtual void _handleCaretChanged(Rect caretRect);

    virtual void _scheduleShowCaretOnScreen(bool withAnimation);

    virtual void _formatAndSetValue(TextEditingValue value, SelectionChangedCause cause, bool userInteraction);

    virtual void _onCursorColorTick();

    virtual void _startCursorBlink();

    virtual void _onCursorTick();

    virtual void _stopCursorBlink(bool resetCharTicks);

    virtual void _startOrStopCursorTimerIfNeeded();

    virtual void _didChangeTextEditingValue();

    virtual void _handleFocusChanged();

    virtual void _updateSelectionRects(bool force);

    virtual void _updateSizeAndTransform();

    virtual void _updateComposingRectIfNeeded();

    virtual void _updateCaretRectIfNeeded();

    virtual TextDirection _textDirection();

    virtual double _devicePixelRatio();

    virtual VoidCallback _semanticsOnCopy(TextSelectionControls controls);

    virtual VoidCallback _semanticsOnCut(TextSelectionControls controls);

    virtual VoidCallback _semanticsOnPaste(TextSelectionControls controls);

    virtual _TextBoundary _characterBoundary(DirectionalTextEditingIntent intent);

    virtual _TextBoundary _nextWordBoundary(DirectionalTextEditingIntent intent);

    virtual _TextBoundary _linebreak(DirectionalTextEditingIntent intent);

    virtual _TextBoundary _documentBoundary(DirectionalTextEditingIntent intent);

    template<typename T>
 virtual Action<T> _makeOverridable(Action<T> defaultAction);

    virtual void _transposeCharacters(TransposeCharactersIntent intent);

    virtual void _replaceText(ReplaceTextIntent intent);

    virtual void _scrollToDocumentBoundary(ScrollToDocumentBoundaryIntent intent);

    virtual void _updateSelection(UpdateSelectionIntent intent);

    virtual void _expandSelectionToDocumentBoundary(ExpandSelectionToDocumentBoundaryIntent intent);

    virtual void _expandSelectionToLinebreak(ExpandSelectionToLineBreakIntent intent);

    virtual void _expandSelection(bool forward, _TextBoundary textBoundary, bool extentAtIndex);

    virtual Object _hideToolbarIfVisible(DismissIntent intent);

};
using EditableTextState = std::shared_ptr<EditableTextStateCls>;

class _EditableCls : public MultiChildRenderObjectWidgetCls {
public:
    InlineSpan inlineSpan;

    TextEditingValue value;

    Color cursorColor;

    LayerLink startHandleLayerLink;

    LayerLink endHandleLayerLink;

    Color backgroundCursorColor;

    ValueNotifier<bool> showCursor;

    bool forceLine;

    bool readOnly;

    bool hasFocus;

    int maxLines;

    int minLines;

    bool expands;

    StrutStyle strutStyle;

    Color selectionColor;

    double textScaleFactor;

    TextAlign textAlign;

    TextDirection textDirection;

    Locale locale;

    String obscuringCharacter;

    bool obscureText;

    TextHeightBehavior textHeightBehavior;

    TextWidthBasis textWidthBasis;

    ViewportOffset offset;

    CaretChangedHandler onCaretChanged;

    bool rendererIgnoresPointer;

    double cursorWidth;

    double cursorHeight;

    Radius cursorRadius;

    Offset cursorOffset;

    bool paintCursorAboveText;

    BoxHeightStyle selectionHeightStyle;

    BoxWidthStyle selectionWidthStyle;

    bool enableInteractiveSelection;

    TextSelectionDelegate textSelectionDelegate;

    double devicePixelRatio;

    TextRange promptRectRange;

    Color promptRectColor;

    Clip clipBehavior;


    virtual RenderEditable createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderEditable renderObject);

private:

     _EditableCls(Color backgroundCursorColor, Clip clipBehavior, Color cursorColor, double cursorHeight, Offset cursorOffset, Radius cursorRadius, double cursorWidth, double devicePixelRatio, bool enableInteractiveSelection, LayerLink endHandleLayerLink, bool expands, bool forceLine, bool hasFocus, InlineSpan inlineSpan, Unknown key, Locale locale, int maxLines, int minLines, bool obscureText, String obscuringCharacter, ViewportOffset offset, CaretChangedHandler onCaretChanged, bool paintCursorAboveText, Color promptRectColor, TextRange promptRectRange, bool readOnly, bool rendererIgnoresPointer, Color selectionColor, BoxHeightStyle selectionHeightStyle, BoxWidthStyle selectionWidthStyle, ValueNotifier<bool> showCursor, LayerLink startHandleLayerLink, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextSelectionDelegate textSelectionDelegate, TextWidthBasis textWidthBasis, TextEditingValue value);

    static List<Widget> _extractChildren(InlineSpan span);

};
using _Editable = std::shared_ptr<_EditableCls>;

class _ScribbleFocusableCls : public StatefulWidgetCls {
public:
    Widget child;

    FocusNode focusNode;

    GlobalKey editableKey;

    VoidCallback updateSelectionRects;

    bool enabled;


    virtual _ScribbleFocusableState createState();

private:

     _ScribbleFocusableCls(Widget child, GlobalKey editableKey, bool enabled, FocusNode focusNode, VoidCallback updateSelectionRects);
};
using _ScribbleFocusable = std::shared_ptr<_ScribbleFocusableCls>;

class _ScribbleFocusableStateCls : public StateCls<_ScribbleFocusable> {
public:

    virtual void initState();

    virtual void didUpdateWidget(_ScribbleFocusable oldWidget);

    virtual void dispose();

    virtual RenderEditable renderEditable();

    virtual String elementIdentifier();

    virtual void onScribbleFocus(Offset offset);

    virtual bool isInScribbleRect(Rect rect);

    virtual Rect bounds();

    virtual Widget build(BuildContext context);

private:
    static int _nextElementIdentifier;

    String _elementIdentifier;


     _ScribbleFocusableStateCls();

};
using _ScribbleFocusableState = std::shared_ptr<_ScribbleFocusableStateCls>;

class _ScribblePlaceholderCls : public WidgetSpanCls {
public:
    Size size;


    virtual void build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor);

private:

     _ScribblePlaceholderCls(Unknown alignment, Unknown baseline, Unknown child, Size size);

};
using _ScribblePlaceholder = std::shared_ptr<_ScribblePlaceholderCls>;

class _TextBoundaryCls : public ObjectCls {
public:

    virtual TextEditingValue textEditingValue();
    virtual TextPosition getLeadingTextBoundaryAt(TextPosition position);
    virtual TextPosition getTrailingTextBoundaryAt(TextPosition position);
    virtual TextRange getTextBoundaryAt(TextPosition position);

private:

     _TextBoundaryCls();
};
using _TextBoundary = std::shared_ptr<_TextBoundaryCls>;

class _CodeUnitBoundaryCls : public _TextBoundaryCls {
public:
    TextEditingValue textEditingValue;


    virtual TextPosition getLeadingTextBoundaryAt(TextPosition position);

    virtual TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _CodeUnitBoundaryCls(TextEditingValue textEditingValue);
};
using _CodeUnitBoundary = std::shared_ptr<_CodeUnitBoundaryCls>;

class _WhitespaceBoundaryCls : public _TextBoundaryCls {
public:
    TextEditingValue textEditingValue;


    virtual TextPosition getLeadingTextBoundaryAt(TextPosition position);

    virtual TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _WhitespaceBoundaryCls(TextEditingValue textEditingValue);
};
using _WhitespaceBoundary = std::shared_ptr<_WhitespaceBoundaryCls>;

class _CharacterBoundaryCls : public _TextBoundaryCls {
public:
    TextEditingValue textEditingValue;


    virtual TextPosition getLeadingTextBoundaryAt(TextPosition position);

    virtual TextPosition getTrailingTextBoundaryAt(TextPosition position);

    virtual TextRange getTextBoundaryAt(TextPosition position);

private:

     _CharacterBoundaryCls(TextEditingValue textEditingValue);
};
using _CharacterBoundary = std::shared_ptr<_CharacterBoundaryCls>;

class _WordBoundaryCls : public _TextBoundaryCls {
public:
    TextLayoutMetrics textLayout;

    TextEditingValue textEditingValue;


    virtual TextPosition getLeadingTextBoundaryAt(TextPosition position);

    virtual TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _WordBoundaryCls(TextLayoutMetrics textLayout, TextEditingValue textEditingValue);
};
using _WordBoundary = std::shared_ptr<_WordBoundaryCls>;

class _LineBreakCls : public _TextBoundaryCls {
public:
    TextLayoutMetrics textLayout;

    TextEditingValue textEditingValue;


    virtual TextPosition getLeadingTextBoundaryAt(TextPosition position);

    virtual TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _LineBreakCls(TextLayoutMetrics textLayout, TextEditingValue textEditingValue);
};
using _LineBreak = std::shared_ptr<_LineBreakCls>;

class _DocumentBoundaryCls : public _TextBoundaryCls {
public:
    TextEditingValue textEditingValue;


    virtual TextPosition getLeadingTextBoundaryAt(TextPosition position);

    virtual TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _DocumentBoundaryCls(TextEditingValue textEditingValue);
};
using _DocumentBoundary = std::shared_ptr<_DocumentBoundaryCls>;

class _ExpandedTextBoundaryCls : public _TextBoundaryCls {
public:
    _TextBoundary innerTextBoundary;

    _TextBoundary outerTextBoundary;


    virtual TextEditingValue textEditingValue();

    virtual TextPosition getLeadingTextBoundaryAt(TextPosition position);

    virtual TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _ExpandedTextBoundaryCls(_TextBoundary innerTextBoundary, _TextBoundary outerTextBoundary);
};
using _ExpandedTextBoundary = std::shared_ptr<_ExpandedTextBoundaryCls>;

class _CollapsedSelectionBoundaryCls : public _TextBoundaryCls {
public:
    _TextBoundary innerTextBoundary;

    bool isForward;


    virtual TextEditingValue textEditingValue();

    virtual TextPosition getLeadingTextBoundaryAt(TextPosition position);

    virtual TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _CollapsedSelectionBoundaryCls(_TextBoundary innerTextBoundary, bool isForward);
};
using _CollapsedSelectionBoundary = std::shared_ptr<_CollapsedSelectionBoundaryCls>;

class _MixedBoundaryCls : public _TextBoundaryCls {
public:
    _TextBoundary leadingTextBoundary;

    _TextBoundary trailingTextBoundary;


    virtual TextEditingValue textEditingValue();

    virtual TextPosition getLeadingTextBoundaryAt(TextPosition position);

    virtual TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _MixedBoundaryCls(_TextBoundary leadingTextBoundary, _TextBoundary trailingTextBoundary);
};
using _MixedBoundary = std::shared_ptr<_MixedBoundaryCls>;

template<typename T>
class _DeleteTextActionCls : public ContextActionCls<T> {
public:
    EditableTextState state;

    std::function<_TextBoundary(T intent)> getTextBoundariesForIntent;


    virtual Object invoke(T intent, BuildContext context);

    virtual bool isActionEnabled();

private:

     _DeleteTextActionCls(EditableTextState state, std::function<_TextBoundary(T intent)> getTextBoundariesForIntent);
    virtual TextRange _expandNonCollapsedRange(TextEditingValue value);

};
template<typename T>
using _DeleteTextAction = std::shared_ptr<_DeleteTextActionCls<T>>;

template<typename T>
class _UpdateTextSelectionActionCls : public ContextActionCls<T> {
public:
    EditableTextState state;

    bool ignoreNonCollapsedSelection;

    std::function<_TextBoundary(T intent)> getTextBoundariesForIntent;

    static int NEWLINE_CODE_UNIT;


    virtual Object invoke(T intent, BuildContext context);

    virtual bool isActionEnabled();

private:

     _UpdateTextSelectionActionCls(EditableTextState state, bool ignoreNonCollapsedSelection, std::function<_TextBoundary(T intent)> getTextBoundariesForIntent);
    virtual bool _isAtWordwrapUpstream(TextPosition position);

    virtual bool _isAtWordwrapDownstream(TextPosition position);

};
template<typename T>
using _UpdateTextSelectionAction = std::shared_ptr<_UpdateTextSelectionActionCls<T>>;

class _ExtendSelectionOrCaretPositionActionCls : public ContextActionCls<ExtendSelectionToNextWordBoundaryOrCaretLocationIntent> {
public:
    EditableTextState state;

    std::function<_TextBoundary(ExtendSelectionToNextWordBoundaryOrCaretLocationIntent intent)> getTextBoundariesForIntent;


    virtual Object invoke(ExtendSelectionToNextWordBoundaryOrCaretLocationIntent intent, BuildContext context);

    virtual bool isActionEnabled();

private:

     _ExtendSelectionOrCaretPositionActionCls(EditableTextState state, std::function<_TextBoundary(ExtendSelectionToNextWordBoundaryOrCaretLocationIntent intent)> getTextBoundariesForIntent);
};
using _ExtendSelectionOrCaretPositionAction = std::shared_ptr<_ExtendSelectionOrCaretPositionActionCls>;

template<typename T>
class _UpdateTextSelectionToAdjacentLineActionCls : public ContextActionCls<T> {
public:
    EditableTextState state;


    virtual void stopCurrentVerticalRunIfSelectionChanges();

    virtual void invoke(T intent, BuildContext context);

    virtual bool isActionEnabled();

private:
    VerticalCaretMovementRun _verticalMovementRun;

    TextSelection _runSelection;


     _UpdateTextSelectionToAdjacentLineActionCls(EditableTextState state);
};
template<typename T>
using _UpdateTextSelectionToAdjacentLineAction = std::shared_ptr<_UpdateTextSelectionToAdjacentLineActionCls<T>>;

class _SelectAllActionCls : public ContextActionCls<SelectAllTextIntent> {
public:
    EditableTextState state;


    virtual Object invoke(SelectAllTextIntent intent, BuildContext context);

    virtual bool isActionEnabled();

private:

     _SelectAllActionCls(EditableTextState state);
};
using _SelectAllAction = std::shared_ptr<_SelectAllActionCls>;

class _CopySelectionActionCls : public ContextActionCls<CopySelectionTextIntent> {
public:
    EditableTextState state;


    virtual void invoke(CopySelectionTextIntent intent, BuildContext context);

    virtual bool isActionEnabled();

private:

     _CopySelectionActionCls(EditableTextState state);
};
using _CopySelectionAction = std::shared_ptr<_CopySelectionActionCls>;

class _TextEditingHistoryCls : public StatefulWidgetCls {
public:
    Widget child;

    TextEditingController controller;

    TextEditingValueCallback onTriggered;


    virtual State<_TextEditingHistory> createState();

private:

     _TextEditingHistoryCls(Widget child, TextEditingController controller, TextEditingValueCallback onTriggered);
};
using _TextEditingHistory = std::shared_ptr<_TextEditingHistoryCls>;

class _TextEditingHistoryStateCls : public StateCls<_TextEditingHistory> {
public:

    virtual void initState();

    virtual void didUpdateWidget(_TextEditingHistory oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    _UndoStack<TextEditingValue> _stack;

    _Throttled<TextEditingValue> _throttledPush;

    Timer _throttleTimer;

    static Duration _kThrottleDuration;


    virtual void _undo(UndoTextIntent intent);

    virtual void _redo(RedoTextIntent intent);

    virtual void _update(TextEditingValue nextValue);

    virtual void _push();

};
using _TextEditingHistoryState = std::shared_ptr<_TextEditingHistoryStateCls>;

template<typename T>
class _UndoStackCls : public ObjectCls {
public:

    virtual T currentValue();

    virtual void push(T value);

    virtual T undo();

    virtual T redo();

    virtual void clear();

    virtual String toString();

private:
    List<T> _list;

    int _index;


     _UndoStackCls();
};
template<typename T>
using _UndoStack = std::shared_ptr<_UndoStackCls<T>>;
template<typename T>
 _Throttled<T> _throttle(Duration duration, _Throttleable<T> function, bool leadingEdge);



#endif