#ifndef EDITABLE_TEXT_H
#define EDITABLE_TEXT_H
#include <memory>
#include <flutter/services.hpp>

#include <async/async.hpp>
#include <math/math.hpp>
#include <ui/ui.hpp>
#include <characters/characters.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/services.hpp>
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


const Duration _kCursorBlinkHalfPeriod;

const int _kObscureShowLatestCharCursorTicks;

const double _kIPadWidth;


class TextEditingController : ValueNotifier<TextEditingValue> {
public:

     TextEditingController(String text);

    void  fromValue(TextEditingValue value);

    String text();

    void  text(String newText);

    void  value(TextEditingValue newValue);

    TextSpan buildTextSpan(BuildContext context, TextStyle style, bool withComposing);

    TextSelection selection();

    void  selection(TextSelection newSelection);

    void clear();

    void clearComposing();

    bool isSelectionWithinTextBounds(TextSelection selection);

private:

    bool _isSelectionWithinComposingRange(TextSelection selection);

};

class ToolbarOptions {
public:
    bool copy;

    bool cut;

    bool paste;

    bool selectAll;


     ToolbarOptions(bool copy, bool cut, bool paste, bool selectAll);

private:

};

class _KeyFrame {
public:
    static const List<_KeyFrame> iOSBlinkingCaretKeyFrames;

    double time;

    double value;


private:

     _KeyFrame(double time, double value);

};

class _DiscreteKeyFrameSimulation : Simulation {
public:
    double maxDuration;


    void  iOSBlinkingCaret();

    double dx(double time);

    bool isDone(double time);

    double x(double time);

private:
    List<_KeyFrame> _keyFrames;

    int _lastKeyFrameIndex;


    void  _(List<_KeyFrame> _keyFrames, double maxDuration);

};

class EditableText : StatefulWidget {
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


     EditableText(bool autocorrect, Color autocorrectionTextRectColor, AutofillClient autofillClient, Iterable<String> autofillHints, bool autofocus, Color backgroundCursorColor, Clip clipBehavior, TextEditingController controller, Color cursorColor, double cursorHeight, Offset cursorOffset, bool cursorOpacityAnimates, Radius cursorRadius, double cursorWidth, DragStartBehavior dragStartBehavior, bool enableIMEPersonalizedLearning, bool enableInteractiveSelection, bool enableSuggestions, bool expands, FocusNode focusNode, bool forceLine, List<TextInputFormatter> inputFormatters, Unknown, Brightness keyboardAppearance, TextInputType keyboardType, Locale locale, int maxLines, int minLines, MouseCursor mouseCursor, bool obscureText, String obscuringCharacter, AppPrivateCommandCallback onAppPrivateCommand, ValueChanged<String> onChanged, VoidCallback onEditingComplete, SelectionChangedCallback onSelectionChanged, VoidCallback onSelectionHandleTapped, ValueChanged<String> onSubmitted, bool paintCursorAboveText, bool readOnly, bool rendererIgnoresPointer, String restorationId, bool scribbleEnabled, ScrollBehavior scrollBehavior, ScrollController scrollController, EdgeInsets scrollPadding, ScrollPhysics scrollPhysics, Color selectionColor, TextSelectionControls selectionControls, BoxHeightStyle selectionHeightStyle, BoxWidthStyle selectionWidthStyle, bool showCursor, bool showSelectionHandles, SmartDashesType smartDashesType, SmartQuotesType smartQuotesType, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextCapitalization textCapitalization, TextDirection textDirection, TextHeightBehavior textHeightBehavior, TextInputAction textInputAction, double textScaleFactor, TextWidthBasis textWidthBasis, ToolbarOptions toolbarOptions);

    StrutStyle strutStyle();

    bool selectionEnabled();

    EditableTextState createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    StrutStyle _strutStyle;


    bool _userSelectionEnabled();

    static TextInputType _inferKeyboardType(Iterable<String> autofillHints, int maxLines);

};

class EditableTextState : State<EditableText> {
public:

    AutofillScope currentAutofillScope();

    bool wantKeepAlive();

    bool cutEnabled();

    bool copyEnabled();

    bool pasteEnabled();

    bool selectAllEnabled();

    void copySelection(SelectionChangedCause cause);

    void cutSelection(SelectionChangedCause cause);

    Future<void> pasteText(SelectionChangedCause cause);

    void selectAll(SelectionChangedCause cause);

    void initState();

    void didChangeDependencies();

    void didUpdateWidget(EditableText oldWidget);

    void dispose();

    TextEditingValue currentTextEditingValue();

    void updateEditingValue(TextEditingValue value);

    void performAction(TextInputAction action);

    void performPrivateCommand(String action, Map<String, dynamic> data);

    void updateFloatingCursor(RawFloatingCursorPoint point);

    void beginBatchEdit();

    void endBatchEdit();

    void connectionClosed();

    void requestKeyboard();

    void didChangeMetrics();

    bool cursorCurrentlyVisible();

    Duration cursorBlinkInterval();

    TextSelectionOverlay selectionOverlay();

    RenderEditable renderEditable();

    TextEditingValue textEditingValue();

    void userUpdateTextEditingValue(SelectionChangedCause cause, TextEditingValue value);

    void bringIntoView(TextPosition position);

    bool showToolbar();

    void hideToolbar(bool hideHandles);

    void toggleToolbar();

    void insertTextPlaceholder(Size size);

    void removeTextPlaceholder();

    String autofillId();

    TextInputConfiguration textInputConfiguration();

    void autofill(TextEditingValue value);

    void showAutocorrectionPromptRect(int end, int start);

    Widget build(BuildContext context);

    TextSpan buildTextSpan();

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

    static const Duration _floatingCursorResetTime;

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

    static const Duration _caretAnimationDuration;

    static const Curve _caretAnimationCurve;

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


    AnimationController _cursorBlinkOpacityController();

    ScrollController _scrollController();

    AutofillClient _effectiveAutofillClient();

    bool _shouldCreateInputConnection();

    Color _cursorColor();

    void _onChangedClipboardStatus();

    TextEditingValue _textEditingValueforTextLayoutMetrics();

    Offset _floatingCursorOffset();

    void _onFloatingCursorResetTick();

    void _finalizeEditing(TextInputAction action, bool shouldUnfocus);

    void _updateRemoteEditingValueIfNeeded();

    TextEditingValue _value();

    void  _value(TextEditingValue value);

    bool _hasFocus();

    bool _isMultiline();

    RevealedOffset _getOffsetToRevealCaret(Rect rect);

    bool _hasInputConnection();

    bool _needsAutofill();

    void _openInputConnection();

    void _closeInputConnectionIfNeeded();

    void _openOrCloseInputConnectionIfNeeded();

    void _scheduleRestartConnection();

    void _restartConnectionIfNeeded();

    void _updateOrDisposeSelectionOverlayIfNeeded();

    void _updateSelectionOverlayForScroll();

    void _createSelectionOverlay();

    void _handleSelectionChanged(SelectionChangedCause cause, TextSelection selection);

    void _handleCaretChanged(Rect caretRect);

    void _scheduleShowCaretOnScreen(bool withAnimation);

    void _formatAndSetValue(SelectionChangedCause cause, bool userInteraction, TextEditingValue value);

    void _onCursorColorTick();

    void _startCursorBlink();

    void _onCursorTick();

    void _stopCursorBlink(bool resetCharTicks);

    void _startOrStopCursorTimerIfNeeded();

    void _didChangeTextEditingValue();

    void _handleFocusChanged();

    void _updateSelectionRects(bool force);

    void _updateSizeAndTransform();

    void _updateComposingRectIfNeeded();

    void _updateCaretRectIfNeeded();

    TextDirection _textDirection();

    double _devicePixelRatio();

    VoidCallback _semanticsOnCopy(TextSelectionControls controls);

    VoidCallback _semanticsOnCut(TextSelectionControls controls);

    VoidCallback _semanticsOnPaste(TextSelectionControls controls);

    _TextBoundary _characterBoundary(DirectionalTextEditingIntent intent);

    _TextBoundary _nextWordBoundary(DirectionalTextEditingIntent intent);

    _TextBoundary _linebreak(DirectionalTextEditingIntent intent);

    _TextBoundary _documentBoundary(DirectionalTextEditingIntent intent);

    Action<T> _makeOverridable<T extends Intent>(Action<T> defaultAction);

    void _transposeCharacters(TransposeCharactersIntent intent);

    void _replaceText(ReplaceTextIntent intent);

    void _scrollToDocumentBoundary(ScrollToDocumentBoundaryIntent intent);

    void _updateSelection(UpdateSelectionIntent intent);

    void _expandSelectionToDocumentBoundary(ExpandSelectionToDocumentBoundaryIntent intent);

    void _expandSelectionToLinebreak(ExpandSelectionToLineBreakIntent intent);

    void _expandSelection(bool extentAtIndex, bool forward, _TextBoundary textBoundary);

    Object _hideToolbarIfVisible(DismissIntent intent);

};

class _Editable : MultiChildRenderObjectWidget {
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


    RenderEditable createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderEditable renderObject);

private:

     _Editable(Color backgroundCursorColor, Clip clipBehavior, Color cursorColor, double cursorHeight, Offset cursorOffset, Radius cursorRadius, double cursorWidth, double devicePixelRatio, bool enableInteractiveSelection, LayerLink endHandleLayerLink, bool expands, bool forceLine, bool hasFocus, InlineSpan inlineSpan, Unknown, Locale locale, int maxLines, int minLines, bool obscureText, String obscuringCharacter, ViewportOffset offset, CaretChangedHandler onCaretChanged, bool paintCursorAboveText, Color promptRectColor, TextRange promptRectRange, bool readOnly, bool rendererIgnoresPointer, Color selectionColor, BoxHeightStyle selectionHeightStyle, BoxWidthStyle selectionWidthStyle, ValueNotifier<bool> showCursor, LayerLink startHandleLayerLink, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextSelectionDelegate textSelectionDelegate, TextWidthBasis textWidthBasis, TextEditingValue value);

    static List<Widget> _extractChildren(InlineSpan span);

};

class _ScribbleFocusable : StatefulWidget {
public:
    Widget child;

    FocusNode focusNode;

    GlobalKey editableKey;

    VoidCallback updateSelectionRects;

    bool enabled;


    _ScribbleFocusableState createState();

private:

     _ScribbleFocusable(Widget child, GlobalKey editableKey, bool enabled, FocusNode focusNode, VoidCallback updateSelectionRects);

};

class _ScribbleFocusableState : State<_ScribbleFocusable> {
public:

    void initState();

    void didUpdateWidget(_ScribbleFocusable oldWidget);

    void dispose();

    RenderEditable renderEditable();

    String elementIdentifier();

    void onScribbleFocus(Offset offset);

    bool isInScribbleRect(Rect rect);

    Rect bounds();

    Widget build(BuildContext context);

private:
    static int _nextElementIdentifier;

    String _elementIdentifier;


     _ScribbleFocusableState();

};

class _ScribblePlaceholder : WidgetSpan {
public:
    Size size;


    void build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor);

private:

     _ScribblePlaceholder(Unknown, Unknown, Unknown, Size size);

};

class _TextBoundary {
public:

    TextEditingValue textEditingValue();

    TextPosition getLeadingTextBoundaryAt(TextPosition position);

    TextPosition getTrailingTextBoundaryAt(TextPosition position);

    TextRange getTextBoundaryAt(TextPosition position);

private:

     _TextBoundary();

};

class _CodeUnitBoundary : _TextBoundary {
public:
    TextEditingValue textEditingValue;


    TextPosition getLeadingTextBoundaryAt(TextPosition position);

    TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _CodeUnitBoundary(TextEditingValue textEditingValue);

};

class _WhitespaceBoundary : _TextBoundary {
public:
    TextEditingValue textEditingValue;


    TextPosition getLeadingTextBoundaryAt(TextPosition position);

    TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _WhitespaceBoundary(TextEditingValue textEditingValue);

};

class _CharacterBoundary : _TextBoundary {
public:
    TextEditingValue textEditingValue;


    TextPosition getLeadingTextBoundaryAt(TextPosition position);

    TextPosition getTrailingTextBoundaryAt(TextPosition position);

    TextRange getTextBoundaryAt(TextPosition position);

private:

     _CharacterBoundary(TextEditingValue textEditingValue);

};

class _WordBoundary : _TextBoundary {
public:
    TextLayoutMetrics textLayout;

    TextEditingValue textEditingValue;


    TextPosition getLeadingTextBoundaryAt(TextPosition position);

    TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _WordBoundary(TextEditingValue textEditingValue, TextLayoutMetrics textLayout);

};

class _LineBreak : _TextBoundary {
public:
    TextLayoutMetrics textLayout;

    TextEditingValue textEditingValue;


    TextPosition getLeadingTextBoundaryAt(TextPosition position);

    TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _LineBreak(TextEditingValue textEditingValue, TextLayoutMetrics textLayout);

};

class _DocumentBoundary : _TextBoundary {
public:
    TextEditingValue textEditingValue;


    TextPosition getLeadingTextBoundaryAt(TextPosition position);

    TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _DocumentBoundary(TextEditingValue textEditingValue);

};

class _ExpandedTextBoundary : _TextBoundary {
public:
    _TextBoundary innerTextBoundary;

    _TextBoundary outerTextBoundary;


    TextEditingValue textEditingValue();

    TextPosition getLeadingTextBoundaryAt(TextPosition position);

    TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _ExpandedTextBoundary(_TextBoundary innerTextBoundary, _TextBoundary outerTextBoundary);

};

class _CollapsedSelectionBoundary : _TextBoundary {
public:
    _TextBoundary innerTextBoundary;

    bool isForward;


    TextEditingValue textEditingValue();

    TextPosition getLeadingTextBoundaryAt(TextPosition position);

    TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _CollapsedSelectionBoundary(_TextBoundary innerTextBoundary, bool isForward);

};

class _MixedBoundary : _TextBoundary {
public:
    _TextBoundary leadingTextBoundary;

    _TextBoundary trailingTextBoundary;


    TextEditingValue textEditingValue();

    TextPosition getLeadingTextBoundaryAt(TextPosition position);

    TextPosition getTrailingTextBoundaryAt(TextPosition position);

private:

     _MixedBoundary(_TextBoundary leadingTextBoundary, _TextBoundary trailingTextBoundary);

};

class _DeleteTextAction<T extends DirectionalTextEditingIntent> : ContextAction<T> {
public:
    EditableTextState state;

    FunctionType getTextBoundariesForIntent;


    Object invoke(BuildContext context, T intent);

    bool isActionEnabled();

private:

     _DeleteTextAction(FunctionType getTextBoundariesForIntent, EditableTextState state);

    TextRange _expandNonCollapsedRange(TextEditingValue value);

};

class _UpdateTextSelectionAction<T extends DirectionalCaretMovementIntent> : ContextAction<T> {
public:
    EditableTextState state;

    bool ignoreNonCollapsedSelection;

    FunctionType getTextBoundariesForIntent;

    static const int NEWLINE_CODE_UNIT;


    Object invoke(BuildContext context, T intent);

    bool isActionEnabled();

private:

     _UpdateTextSelectionAction(FunctionType getTextBoundariesForIntent, bool ignoreNonCollapsedSelection, EditableTextState state);

    bool _isAtWordwrapUpstream(TextPosition position);

    bool _isAtWordwrapDownstream(TextPosition position);

};

class _ExtendSelectionOrCaretPositionAction : ContextAction<ExtendSelectionToNextWordBoundaryOrCaretLocationIntent> {
public:
    EditableTextState state;

    FunctionType getTextBoundariesForIntent;


    Object invoke(BuildContext context, ExtendSelectionToNextWordBoundaryOrCaretLocationIntent intent);

    bool isActionEnabled();

private:

     _ExtendSelectionOrCaretPositionAction(FunctionType getTextBoundariesForIntent, EditableTextState state);

};

class _UpdateTextSelectionToAdjacentLineAction<T extends DirectionalCaretMovementIntent> : ContextAction<T> {
public:
    EditableTextState state;


    void stopCurrentVerticalRunIfSelectionChanges();

    void invoke(BuildContext context, T intent);

    bool isActionEnabled();

private:
    VerticalCaretMovementRun _verticalMovementRun;

    TextSelection _runSelection;


     _UpdateTextSelectionToAdjacentLineAction(EditableTextState state);

};

class _SelectAllAction : ContextAction<SelectAllTextIntent> {
public:
    EditableTextState state;


    Object invoke(BuildContext context, SelectAllTextIntent intent);

    bool isActionEnabled();

private:

     _SelectAllAction(EditableTextState state);

};

class _CopySelectionAction : ContextAction<CopySelectionTextIntent> {
public:
    EditableTextState state;


    void invoke(BuildContext context, CopySelectionTextIntent intent);

    bool isActionEnabled();

private:

     _CopySelectionAction(EditableTextState state);

};

class _TextEditingHistory : StatefulWidget {
public:
    Widget child;

    TextEditingController controller;

    TextEditingValueCallback onTriggered;


    State<_TextEditingHistory> createState();

private:

     _TextEditingHistory(Widget child, TextEditingController controller, TextEditingValueCallback onTriggered);

};

class _TextEditingHistoryState : State<_TextEditingHistory> {
public:

    void initState();

    void didUpdateWidget(_TextEditingHistory oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    _UndoStack<TextEditingValue> _stack;

    _Throttled<TextEditingValue> _throttledPush;

    Timer _throttleTimer;

    static const Duration _kThrottleDuration;


    void _undo(UndoTextIntent intent);

    void _redo(RedoTextIntent intent);

    void _update(TextEditingValue nextValue);

    void _push();

};

class _UndoStack<T> {
public:

    T currentValue();

    void push(T value);

    T undo();

    T redo();

    void clear();

    String toString();

private:
    List<T> _list;

    int _index;


     _UndoStack();

};
_Throttled<T> _throttle<T>(Duration duration, _Throttleable<T> function, bool leadingEdge);


#endif