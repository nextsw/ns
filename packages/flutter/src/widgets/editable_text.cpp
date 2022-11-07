#include "editable_text.hpp"
TextEditingController::TextEditingController(String text) {
    {
        super(text == nullptr? TextEditingValue.empty : TextEditingValue(text));
    }
}

void TextEditingController::fromValue(TextEditingValue value)

String TextEditingController::text() {
    return value.text;
}

void TextEditingController::text(String newText) {
    value = value.copyWith(newText, const TextSelection.collapsed(-1), TextRange.empty);
}

void TextEditingController::value(TextEditingValue newValue) {
    assert(!newValue.composing.isValid || newValue.isComposingRangeValid, "New TextEditingValue $newValue has an invalid non-empty composing range ${newValue.composing}. It is recommended to use a valid composing range, even for readonly text fields");
    super.value = newValue;
}

TextSpan TextEditingController::buildTextSpan(BuildContext context, TextStyle style, bool withComposing) {
    assert(!value.composing.isValid || !withComposing || value.isComposingRangeValid);
    if (!value.isComposingRangeValid || !withComposing) {
        return TextSpan(style, text);
    }
    TextStyle composingStyle = style?.merge(const TextStyle(TextDecoration.underline)) ?? const TextStyle(TextDecoration.underline);
    return TextSpan(style, );
}

TextSelection TextEditingController::selection() {
    return value.selection;
}

void TextEditingController::selection(TextSelection newSelection) {
    if (!isSelectionWithinTextBounds(newSelection)) {
        ;
    }
    TextRange newComposing = newSelection.isCollapsed && _isSelectionWithinComposingRange(newSelection)? value.composing : TextRange.empty;
    value = value.copyWith(newSelection, newComposing);
}

void TextEditingController::clear() {
    value = const TextEditingValue(TextSelection.collapsed(0));
}

void TextEditingController::clearComposing() {
    value = value.copyWith(TextRange.empty);
}

bool TextEditingController::isSelectionWithinTextBounds(TextSelection selection) {
    return selection.start <= text.length && selection.end <= text.length;
}

bool TextEditingController::_isSelectionWithinComposingRange(TextSelection selection) {
    return selection.start >= value.composing.start && selection.end <= value.composing.end;
}

ToolbarOptions::ToolbarOptions(bool copy, bool cut, bool paste, bool selectAll) {
    {
        assert(copy != nullptr);
        assert(cut != nullptr);
        assert(paste != nullptr);
        assert(selectAll != nullptr);
    }
}

void _DiscreteKeyFrameSimulation::iOSBlinkingCaret()

double _DiscreteKeyFrameSimulation::dx(double time) {
    return 0;
}

bool _DiscreteKeyFrameSimulation::isDone(double time) {
    return time >= maxDuration;
}

double _DiscreteKeyFrameSimulation::x(double time) {
    int length = _keyFrames.length;
    int searchIndex;
    int endIndex;
    if (_keyFrames[_lastKeyFrameIndex].time > time) {
        searchIndex = 0;
        endIndex = _lastKeyFrameIndex;
    } else {
        searchIndex = _lastKeyFrameIndex;
        endIndex = length;
    }
    while ( < endIndex - 1) {
        assert(_keyFrames[searchIndex].time <= time);
        _KeyFrame next = _keyFrames[searchIndex + 1];
        if ( < next.time) {
                        break;
        }
        searchIndex = 1;
    }
    _lastKeyFrameIndex = searchIndex;
    return _keyFrames[_lastKeyFrameIndex].value;
}

void _DiscreteKeyFrameSimulation::_(List<_KeyFrame> _keyFrames, double maxDuration)

EditableText::EditableText(bool autocorrect, Color autocorrectionTextRectColor, AutofillClient autofillClient, Iterable<String> autofillHints, bool autofocus, Color backgroundCursorColor, Clip clipBehavior, TextEditingController controller, Color cursorColor, double cursorHeight, Offset cursorOffset, bool cursorOpacityAnimates, Radius cursorRadius, double cursorWidth, DragStartBehavior dragStartBehavior, bool enableIMEPersonalizedLearning, bool enableInteractiveSelection, bool enableSuggestions, bool expands, FocusNode focusNode, bool forceLine, List<TextInputFormatter> inputFormatters, Unknown, Brightness keyboardAppearance, TextInputType keyboardType, Locale locale, int maxLines, int minLines, MouseCursor mouseCursor, bool obscureText, String obscuringCharacter, AppPrivateCommandCallback onAppPrivateCommand, ValueChanged<String> onChanged, VoidCallback onEditingComplete, SelectionChangedCallback onSelectionChanged, VoidCallback onSelectionHandleTapped, ValueChanged<String> onSubmitted, bool paintCursorAboveText, bool readOnly, bool rendererIgnoresPointer, String restorationId, bool scribbleEnabled, ScrollBehavior scrollBehavior, ScrollController scrollController, EdgeInsets scrollPadding, ScrollPhysics scrollPhysics, Color selectionColor, TextSelectionControls selectionControls, BoxHeightStyle selectionHeightStyle, BoxWidthStyle selectionWidthStyle, bool showCursor, bool showSelectionHandles, SmartDashesType smartDashesType, SmartQuotesType smartQuotesType, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextCapitalization textCapitalization, TextDirection textDirection, TextHeightBehavior textHeightBehavior, TextInputAction textInputAction, double textScaleFactor, TextWidthBasis textWidthBasis, ToolbarOptions toolbarOptions) {
    {
        assert(controller != nullptr);
        assert(focusNode != nullptr);
        assert(obscuringCharacter != nullptr && obscuringCharacter.length == 1);
        assert(obscureText != nullptr);
        assert(autocorrect != nullptr);
        smartDashesType = smartDashesType ?? (obscureText? SmartDashesType.disabled : SmartDashesType.enabled);
        smartQuotesType = smartQuotesType ?? (obscureText? SmartQuotesType.disabled : SmartQuotesType.enabled);
        assert(enableSuggestions != nullptr);
        assert(showSelectionHandles != nullptr);
        assert(readOnly != nullptr);
        assert(forceLine != nullptr);
        assert(style != nullptr);
        assert(cursorColor != nullptr);
        assert(cursorOpacityAnimates != nullptr);
        assert(paintCursorAboveText != nullptr);
        assert(backgroundCursorColor != nullptr);
        assert(selectionHeightStyle != nullptr);
        assert(selectionWidthStyle != nullptr);
        assert(textAlign != nullptr);
        assert(maxLines == nullptr || maxLines > 0);
        assert(minLines == nullptr || minLines > 0);
        assert((maxLines == nullptr) || (minLines == nullptr) || (maxLines >= minLines), "minLines can't be greater than maxLines");
        assert(expands != nullptr);
        assert(!expands || (maxLines == nullptr && minLines == nullptr), "minLines and maxLines must be null when expands is true.");
        assert(!obscureText || maxLines == 1, "Obscured fields cannot be multiline.");
        assert(autofocus != nullptr);
        assert(rendererIgnoresPointer != nullptr);
        assert(scrollPadding != nullptr);
        assert(dragStartBehavior != nullptr);
        enableInteractiveSelection = enableInteractiveSelection ?? (!readOnly || !obscureText);
        toolbarOptions = toolbarOptions ?? (obscureText? (readOnly? const ToolbarOptions() : const ToolbarOptions(true, true)) : (readOnly? const ToolbarOptions(true, true) : const ToolbarOptions(true, true, true, true)));
        assert(clipBehavior != nullptr);
        assert(enableIMEPersonalizedLearning != nullptr);
        _strutStyle = strutStyle;
        keyboardType = keyboardType ?? _inferKeyboardType(autofillHints, maxLines);
        inputFormatters = maxLines == 1?  : inputFormatters;
        showCursor = showCursor ?? !readOnly;
    }
}

StrutStyle EditableText::strutStyle() {
    if (_strutStyle == nullptr) {
        return StrutStyle.fromTextStyle(styletrue);
    }
    return _strutStyle!.inheritFromTextStyle(style);
}

bool EditableText::selectionEnabled() {
    return enableInteractiveSelection;
}

EditableTextState EditableText::createState() {
    return EditableTextState();
}

void EditableText::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<TextEditingController>DiagnosticsProperty("controller", controller));
    properties.add(<FocusNode>DiagnosticsProperty("focusNode", focusNode));
    properties.add(<bool>DiagnosticsProperty("obscureText", obscureTextfalse));
    properties.add(<bool>DiagnosticsProperty("readOnly", readOnlyfalse));
    properties.add(<bool>DiagnosticsProperty("autocorrect", autocorrecttrue));
    properties.add(<SmartDashesType>EnumProperty("smartDashesType", smartDashesTypeobscureText? SmartDashesType.disabled : SmartDashesType.enabled));
    properties.add(<SmartQuotesType>EnumProperty("smartQuotesType", smartQuotesTypeobscureText? SmartQuotesType.disabled : SmartQuotesType.enabled));
    properties.add(<bool>DiagnosticsProperty("enableSuggestions", enableSuggestionstrue));
    style.debugFillProperties(properties);
    properties.add(<TextAlign>EnumProperty("textAlign", textAlignnullptr));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirectionnullptr));
    properties.add(<Locale>DiagnosticsProperty("locale", localenullptr));
    properties.add(DoubleProperty("textScaleFactor", textScaleFactornullptr));
    properties.add(IntProperty("maxLines", maxLines1));
    properties.add(IntProperty("minLines", minLinesnullptr));
    properties.add(<bool>DiagnosticsProperty("expands", expandsfalse));
    properties.add(<bool>DiagnosticsProperty("autofocus", autofocusfalse));
    properties.add(<TextInputType>DiagnosticsProperty("keyboardType", keyboardTypenullptr));
    properties.add(<ScrollController>DiagnosticsProperty("scrollController", scrollControllernullptr));
    properties.add(<ScrollPhysics>DiagnosticsProperty("scrollPhysics", scrollPhysicsnullptr));
    properties.add(<Iterable<String>>DiagnosticsProperty("autofillHints", autofillHintsnullptr));
    properties.add(<TextHeightBehavior>DiagnosticsProperty("textHeightBehavior", textHeightBehaviornullptr));
    properties.add(<bool>DiagnosticsProperty("scribbleEnabled", scribbleEnabledtrue));
    properties.add(<bool>DiagnosticsProperty("enableIMEPersonalizedLearning", enableIMEPersonalizedLearningtrue));
    properties.add(<bool>DiagnosticsProperty("enableInteractiveSelection", enableInteractiveSelectiontrue));
}

bool EditableText::_userSelectionEnabled() {
    return enableInteractiveSelection && (!readOnly || !obscureText);
}

TextInputType EditableText::_inferKeyboardType(Iterable<String> autofillHints, int maxLines) {
    if (autofillHints == nullptr || autofillHints.isEmpty) {
        return maxLines == 1? TextInputType.text : TextInputType.multiline;
    }
    String effectiveHint = autofillHints.first;
    if (!kIsWeb) {
        ;
    }
    if (maxLines != 1) {
        return TextInputType.multiline;
    }
    Map<String, TextInputType> inferKeyboardType = ;
    return inferKeyboardType[effectiveHint] ?? TextInputType.text;
}

AutofillScope EditableTextState::currentAutofillScope() {
    return _currentAutofillScope;
}

bool EditableTextState::wantKeepAlive() {
    return widget.focusNode.hasFocus;
}

bool EditableTextState::cutEnabled() {
    return widget.toolbarOptions.cut && !widget.readOnly && !widget.obscureText;
}

bool EditableTextState::copyEnabled() {
    return widget.toolbarOptions.copy && !widget.obscureText;
}

bool EditableTextState::pasteEnabled() {
    return widget.toolbarOptions.paste && !widget.readOnly;
}

bool EditableTextState::selectAllEnabled() {
    return widget.toolbarOptions.selectAll && (!widget.readOnly || !widget.obscureText) && widget.enableInteractiveSelection;
}

void EditableTextState::copySelection(SelectionChangedCause cause) {
    TextSelection selection = textEditingValue.selection;
    assert(selection != nullptr);
    if (selection.isCollapsed || widget.obscureText) {
        return;
    }
    String text = textEditingValue.text;
    Clipboard.setData(ClipboardData(selection.textInside(text)));
    if (cause == SelectionChangedCause.toolbar) {
        bringIntoView(textEditingValue.selection.extent);
        hideToolbar(false);
        ;
    }
    _clipboardStatus?.update();
}

void EditableTextState::cutSelection(SelectionChangedCause cause) {
    if (widget.readOnly || widget.obscureText) {
        return;
    }
    TextSelection selection = textEditingValue.selection;
    String text = textEditingValue.text;
    assert(selection != nullptr);
    if (selection.isCollapsed) {
        return;
    }
    Clipboard.setData(ClipboardData(selection.textInside(text)));
    _replaceText(ReplaceTextIntent(textEditingValue, "", selection, cause));
    if (cause == SelectionChangedCause.toolbar) {
        SchedulerBinding.instance.addPostFrameCallback();
        hideToolbar();
    }
    _clipboardStatus?.update();
}

Future<void> EditableTextState::pasteText(SelectionChangedCause cause) {
    if (widget.readOnly) {
        return;
    }
    TextSelection selection = textEditingValue.selection;
    assert(selection != nullptr);
    if (!selection.isValid) {
        return;
    }
    ClipboardData data = await Clipboard.getData(Clipboard.kTextPlain);
    if (data == nullptr) {
        return;
    }
    int lastSelectionIndex = math.max(selection.baseOffset, selection.extentOffset);
    TextEditingValue collapsedTextEditingValue = textEditingValue.copyWith(TextSelection.collapsed(lastSelectionIndex));
    userUpdateTextEditingValue(collapsedTextEditingValue.replaced(selection, data.text!), cause);
    if (cause == SelectionChangedCause.toolbar) {
        SchedulerBinding.instance.addPostFrameCallback();
        hideToolbar();
    }
}

void EditableTextState::selectAll(SelectionChangedCause cause) {
    if (widget.readOnly && widget.obscureText) {
        return;
    }
    userUpdateTextEditingValue(textEditingValue.copyWith(TextSelection(0, textEditingValue.text.length)), cause);
    if (cause == SelectionChangedCause.toolbar) {
        bringIntoView(textEditingValue.selection.extent);
    }
}

void EditableTextState::initState() {
    super.initState();
    _clipboardStatus?.addListener(_onChangedClipboardStatus);
    widget.controller.addListener(_didChangeTextEditingValue);
    widget.focusNode.addListener(_handleFocusChanged);
    _scrollController.addListener(_updateSelectionOverlayForScroll);
    _cursorVisibilityNotifier.value = widget.showCursor;
}

void EditableTextState::didChangeDependencies() {
    super.didChangeDependencies();
    AutofillGroupState newAutofillGroup = AutofillGroup.of(context);
    if (currentAutofillScope != newAutofillGroup) {
        _currentAutofillScope?.unregister(autofillId);
        _currentAutofillScope = newAutofillGroup;
        _currentAutofillScope?.register(_effectiveAutofillClient);
    }
    if (!_didAutoFocus && widget.autofocus) {
        _didAutoFocus = true;
        SchedulerBinding.instance.addPostFrameCallback();
    }
    bool newTickerEnabled = TickerMode.of(context);
    if (_tickersEnabled != newTickerEnabled) {
        _tickersEnabled = newTickerEnabled;
        if (_tickersEnabled && _cursorActive) {
            _startCursorBlink();
        } else         {
            if (!_tickersEnabled && _cursorTimer != nullptr) {
            _cursorTimer!.cancel();
            _cursorTimer = nullptr;
        }
;
        }    }
    if (defaultTargetPlatform != TargetPlatform.iOS && defaultTargetPlatform != TargetPlatform.android) {
        return;
    }
    Orientation orientation = MediaQuery.of(context).orientation;
    if (_lastOrientation == nullptr) {
        _lastOrientation = orientation;
        return;
    }
    if (orientation != _lastOrientation) {
        _lastOrientation = orientation;
        if (defaultTargetPlatform == TargetPlatform.iOS) {
            hideToolbar(false);
        }
        if (defaultTargetPlatform == TargetPlatform.android) {
            hideToolbar();
        }
    }
}

void EditableTextState::didUpdateWidget(EditableText oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.controller != oldWidget.controller) {
        oldWidget.controller.removeListener(_didChangeTextEditingValue);
        widget.controller.addListener(_didChangeTextEditingValue);
        _updateRemoteEditingValueIfNeeded();
    }
    if (widget.controller.selection != oldWidget.controller.selection) {
        _selectionOverlay?.update(_value);
    }
    _selectionOverlay?.handlesVisible = widget.showSelectionHandles;
    if (widget.autofillClient != oldWidget.autofillClient) {
        _currentAutofillScope?.unregister(oldWidget.autofillClient?.autofillId ?? autofillId);
        _currentAutofillScope?.register(_effectiveAutofillClient);
    }
    if (widget.focusNode != oldWidget.focusNode) {
        oldWidget.focusNode.removeListener(_handleFocusChanged);
        widget.focusNode.addListener(_handleFocusChanged);
        updateKeepAlive();
    }
    if (widget.scrollController != oldWidget.scrollController) {
        (oldWidget.scrollController ?? _internalScrollController)?.removeListener(_updateSelectionOverlayForScroll);
        _scrollController.addListener(_updateSelectionOverlayForScroll);
    }
    if (!_shouldCreateInputConnection) {
        _closeInputConnectionIfNeeded();
    } else     {
        if (oldWidget.readOnly && _hasFocus) {
        _openInputConnection();
    }
;
    }    if (kIsWeb && _hasInputConnection) {
        if (oldWidget.readOnly != widget.readOnly) {
            _textInputConnection!.updateConfig(_effectiveAutofillClient.textInputConfiguration);
        }
    }
    if (widget.style != oldWidget.style) {
        TextStyle style = widget.style;
        if (_hasInputConnection) {
            _textInputConnection!.setStyle(style.fontFamily, style.fontSize, style.fontWeight, _textDirection, widget.textAlign);
        }
    }
    if (widget.selectionEnabled && pasteEnabled && (widget.selectionControls?.canPaste(this) ?? false)) {
        _clipboardStatus?.update();
    }
}

void EditableTextState::dispose() {
    _internalScrollController?.dispose();
    _currentAutofillScope?.unregister(autofillId);
    widget.controller.removeListener(_didChangeTextEditingValue);
    _floatingCursorResetController?.dispose();
    _floatingCursorResetController = nullptr;
    _closeInputConnectionIfNeeded();
    assert(!_hasInputConnection);
    _cursorTimer?.cancel();
    _cursorTimer = nullptr;
    _backingCursorBlinkOpacityController?.dispose();
    _backingCursorBlinkOpacityController = nullptr;
    _selectionOverlay?.dispose();
    _selectionOverlay = nullptr;
    widget.focusNode.removeListener(_handleFocusChanged);
    WidgetsBinding.instance.removeObserver(this);
    _clipboardStatus?.removeListener(_onChangedClipboardStatus);
    _clipboardStatus?.dispose();
    _cursorVisibilityNotifier.dispose();
    super.dispose();
    assert(_batchEditDepth <= 0, "unfinished batch edits: $_batchEditDepth");
}

TextEditingValue EditableTextState::currentTextEditingValue() {
    return _value;
}

void EditableTextState::updateEditingValue(TextEditingValue value) {
    if (!_shouldCreateInputConnection) {
        return;
    }
    if (widget.readOnly) {
        value = _value.copyWith(value.selection);
    }
    _lastKnownRemoteTextEditingValue = value;
    if (value == _value) {
        return;
    }
    if (value.text == _value.text && value.composing == _value.composing) {
        _handleSelectionChanged(value.selection, (_textInputConnection?.scribbleInProgress ?? false)? SelectionChangedCause.scribble : SelectionChangedCause.keyboard);
    } else {
        hideToolbar();
        _currentPromptRectRange = nullptr;
        bool revealObscuredInput = _hasInputConnection && widget.obscureText && WidgetsBinding.instance.platformDispatcher.brieflyShowPassword && value.text.length == _value.text.length + 1;
        _obscureShowCharTicksPending = revealObscuredInput? _kObscureShowLatestCharCursorTicks : 0;
        _obscureLatestCharIndex = revealObscuredInput? _value.selection.baseOffset : nullptr;
        _formatAndSetValue(value, SelectionChangedCause.keyboard);
    }
    _scheduleShowCaretOnScreen(true);
    if (_hasInputConnection) {
        _stopCursorBlink(false);
        _startCursorBlink();
    }
}

void EditableTextState::performAction(TextInputAction action) {
    ;
}

void EditableTextState::performPrivateCommand(String action, Map<String, dynamic> data) {
    widget.onAppPrivateCommand!(action, data);
}

void EditableTextState::updateFloatingCursor(RawFloatingCursorPoint point) {
    _floatingCursorResetController = ;
    ;
}

void EditableTextState::beginBatchEdit() {
    _batchEditDepth = 1;
}

void EditableTextState::endBatchEdit() {
    _batchEditDepth = 1;
    assert(_batchEditDepth >= 0, "Unbalanced call to endBatchEdit: beginBatchEdit must be called first.");
    _updateRemoteEditingValueIfNeeded();
}

void EditableTextState::connectionClosed() {
    if (_hasInputConnection) {
        _textInputConnection!.connectionClosedReceived();
        _textInputConnection = nullptr;
        _lastKnownRemoteTextEditingValue = nullptr;
        _finalizeEditing(TextInputAction.donetrue);
    }
}

void EditableTextState::requestKeyboard() {
    if (_hasFocus) {
        _openInputConnection();
    } else {
        widget.focusNode.requestFocus();
    }
}

void EditableTextState::didChangeMetrics() {
    if (_lastBottomViewInset != WidgetsBinding.instance.window.viewInsets.bottom) {
        SchedulerBinding.instance.addPostFrameCallback();
        if ( < WidgetsBinding.instance.window.viewInsets.bottom) {
            _scheduleShowCaretOnScreen(false);
        }
    }
    _lastBottomViewInset = WidgetsBinding.instance.window.viewInsets.bottom;
}

bool EditableTextState::cursorCurrentlyVisible() {
    return _cursorBlinkOpacityController.value > 0;
}

Duration EditableTextState::cursorBlinkInterval() {
    return _kCursorBlinkHalfPeriod;
}

TextSelectionOverlay EditableTextState::selectionOverlay() {
    return _selectionOverlay;
}

RenderEditable EditableTextState::renderEditable() {
    return (;
}

TextEditingValue EditableTextState::textEditingValue() {
    return _value;
}

void EditableTextState::userUpdateTextEditingValue(SelectionChangedCause cause, TextEditingValue value) {
    bool shouldShowCaret = widget.readOnly? _value.selection != value.selection : _value != value;
    if (shouldShowCaret) {
        _scheduleShowCaretOnScreen(true);
    }
    if (value == textEditingValue) {
        if (!widget.focusNode.hasFocus) {
            widget.focusNode.requestFocus();
            _createSelectionOverlay();
        }
        return;
    }
    _formatAndSetValue(value, causetrue);
}

void EditableTextState::bringIntoView(TextPosition position) {
    Rect localRect = renderEditable.getLocalRectForCaret(position);
    RevealedOffset targetOffset = _getOffsetToRevealCaret(localRect);
    _scrollController.jumpTo(targetOffset.offset);
    renderEditable.showOnScreen(targetOffset.rect);
}

bool EditableTextState::showToolbar() {
    if (kIsWeb) {
        return false;
    }
    if (_selectionOverlay == nullptr || _selectionOverlay!.toolbarIsVisible) {
        return false;
    }
    _clipboardStatus?.update();
    _selectionOverlay!.showToolbar();
    return true;
}

void EditableTextState::hideToolbar(bool hideHandles) {
    if (hideHandles) {
        _selectionOverlay?.hide();
    } else     {
        if (_selectionOverlay?.toolbarIsVisible ?? false) {
        _selectionOverlay?.hideToolbar();
    }
;
    }}

void EditableTextState::toggleToolbar() {
    assert(_selectionOverlay != nullptr);
    if (_selectionOverlay!.toolbarIsVisible) {
        hideToolbar();
    } else {
        showToolbar();
    }
}

void EditableTextState::insertTextPlaceholder(Size size) {
    if (!widget.scribbleEnabled) {
        return;
    }
    if (!widget.controller.selection.isValid) {
        return;
    }
    setState();
}

void EditableTextState::removeTextPlaceholder() {
    if (!widget.scribbleEnabled) {
        return;
    }
    setState();
}

String EditableTextState::autofillId() {
    return "EditableText-$hashCode";
}

TextInputConfiguration EditableTextState::textInputConfiguration() {
    List<String> autofillHints = widget.autofillHints?.toList(false);
    AutofillConfiguration autofillConfiguration = autofillHints != nullptr? AutofillConfiguration(autofillId, autofillHints, currentTextEditingValue) : AutofillConfiguration.disabled;
    return TextInputConfiguration(widget.keyboardType, widget.readOnly, widget.obscureText, widget.autocorrect, widget.smartDashesType, widget.smartQuotesType, widget.enableSuggestions, widget._userSelectionEnabled, widget.textInputAction ?? (widget.keyboardType == TextInputType.multiline? TextInputAction.newline : TextInputAction.done), widget.textCapitalization, widget.keyboardAppearance, autofillConfiguration, widget.enableIMEPersonalizedLearning);
}

void EditableTextState::autofill(TextEditingValue value) {
    return updateEditingValue(value);
}

void EditableTextState::showAutocorrectionPromptRect(int end, int start) {
    setState();
}

Widget EditableTextState::build(BuildContext context) {
    assert(debugCheckHasMediaQuery(context));
    super.build(context);
    TextSelectionControls controls = widget.selectionControls;
    return MouseRegion(widget.mouseCursor ?? SystemMouseCursors.text, Actions(_actions, _TextEditingHistory(widget.controller, , Focus(widget.focusNode, false, "EditableText", Scrollable(true, _isMultiline? AxisDirection.down : AxisDirection.right, _scrollController, widget.scrollPhysics, widget.dragStartBehavior, widget.restorationId, widget.scrollBehavior ?? ScrollConfiguration.of(context).copyWith(_isMultiline, false), )))));
}

TextSpan EditableTextState::buildTextSpan() {
    if (widget.obscureText) {
        String text = _value.text;
        text = widget.obscuringCharacter * text.length;
        Set<TargetPlatform> mobilePlatforms = ;
        bool breiflyShowPassword = WidgetsBinding.instance.platformDispatcher.brieflyShowPassword && mobilePlatforms.contains(defaultTargetPlatform);
        if (breiflyShowPassword) {
            int o = _obscureShowCharTicksPending > 0? _obscureLatestCharIndex : nullptr;
            if (o != nullptr && o >= 0 &&  < text.length) {
                text = text.replaceRange(o, o + 1, _value.text.substring(o, o + 1));
            }
        }
        return TextSpan(widget.style, text);
    }
    if (_placeholderLocation >= 0 && _placeholderLocation <= _value.text.length) {
        List<_ScribblePlaceholder> placeholders = ;
        int placeholderLocation = _value.text.length - _placeholderLocation;
        if (_isMultiline) {
            placeholders.add(const _ScribblePlaceholder(SizedBox(), Size.zero));
            placeholders.add(_ScribblePlaceholder(const SizedBox(), Size(renderEditable.size.width, 0.0)));
        } else {
            placeholders.add(const _ScribblePlaceholder(SizedBox(), Size(100.0, 0.0)));
        }
        return TextSpan(widget.style, );
    }
    return widget.controller.buildTextSpan(context, widget.style, !widget.readOnly && _hasFocus);
}

AnimationController EditableTextState::_cursorBlinkOpacityController() {
    return _backingCursorBlinkOpacityController ??= ;
}

ScrollController EditableTextState::_scrollController() {
    return widget.scrollController ?? (_internalScrollController ??= ScrollController());
}

AutofillClient EditableTextState::_effectiveAutofillClient() {
    return widget.autofillClient ?? this;
}

bool EditableTextState::_shouldCreateInputConnection() {
    return kIsWeb || !widget.readOnly;
}

Color EditableTextState::_cursorColor() {
    return widget.cursorColor.withOpacity(_cursorBlinkOpacityController.value);
}

void EditableTextState::_onChangedClipboardStatus() {
    setState();
}

TextEditingValue EditableTextState::_textEditingValueforTextLayoutMetrics() {
    Widget editableWidget = _editableKey.currentContext?.widget;
    if (editableWidget is! _Editable) {
        ;
    }
    return editableWidget.value;
}

Offset EditableTextState::_floatingCursorOffset() {
    return Offset(0, renderEditable.preferredLineHeight / 2);
}

void EditableTextState::_onFloatingCursorResetTick() {
    Offset finalPosition = renderEditable.getLocalRectForCaret(_lastTextPosition!).centerLeft - _floatingCursorOffset;
    if (_floatingCursorResetController!.isCompleted) {
        renderEditable.setFloatingCursor(FloatingCursorDragState.End, finalPosition, _lastTextPosition!);
        if (_lastTextPosition!.offset != renderEditable.selection!.baseOffset) {
            _handleSelectionChanged(TextSelection.collapsed(_lastTextPosition!.offset), SelectionChangedCause.forcePress);
        }
        _startCaretRect = nullptr;
        _lastTextPosition = nullptr;
        _pointOffsetOrigin = nullptr;
        _lastBoundedOffset = nullptr;
    } else {
        double lerpValue = _floatingCursorResetController!.value;
        double lerpX = ui.lerpDouble(_lastBoundedOffset!.dx, finalPosition.dx, lerpValue)!;
        double lerpY = ui.lerpDouble(_lastBoundedOffset!.dy, finalPosition.dy, lerpValue)!;
        renderEditable.setFloatingCursor(FloatingCursorDragState.Update, Offset(lerpX, lerpY), _lastTextPosition!lerpValue);
    }
}

void EditableTextState::_finalizeEditing(TextInputAction action, bool shouldUnfocus) {
    if (widget.onEditingComplete != nullptr) {
        ;
    } else {
        widget.controller.clearComposing();
        if (shouldUnfocus) {
            ;
        }
    }
    ValueChanged<String> onSubmitted = widget.onSubmitted;
    if (onSubmitted == nullptr) {
        return;
    }
    ;
    if (shouldUnfocus) {
        _scheduleRestartConnection();
    }
}

void EditableTextState::_updateRemoteEditingValueIfNeeded() {
    if (_batchEditDepth > 0 || !_hasInputConnection) {
        return;
    }
    TextEditingValue localValue = _value;
    if (localValue == _lastKnownRemoteTextEditingValue) {
        return;
    }
    _textInputConnection!.setEditingState(localValue);
    _lastKnownRemoteTextEditingValue = localValue;
}

TextEditingValue EditableTextState::_value() {
    return widget.controller.value;
}

void EditableTextState::_value(TextEditingValue value) {
    widget.controller.value = value;
}

bool EditableTextState::_hasFocus() {
    return widget.focusNode.hasFocus;
}

bool EditableTextState::_isMultiline() {
    return widget.maxLines != 1;
}

RevealedOffset EditableTextState::_getOffsetToRevealCaret(Rect rect) {
    if (!_scrollController.position.allowImplicitScrolling) {
        return RevealedOffset(_scrollController.offset, rect);
    }
    Size editableSize = renderEditable.size;
    double additionalOffset;
    Offset unitOffset;
    if (!_isMultiline) {
        additionalOffset = rect.width >= editableSize.width? editableSize.width / 2 - rect.center.dx : clampDouble(0.0, rect.right - editableSize.width, rect.left);
        unitOffset = const Offset(1, 0);
    } else {
        Rect expandedRect = Rect.fromCenter(rect.center, rect.width, math.max(rect.height, renderEditable.preferredLineHeight));
        additionalOffset = expandedRect.height >= editableSize.height? editableSize.height / 2 - expandedRect.center.dy : clampDouble(0.0, expandedRect.bottom - editableSize.height, expandedRect.top);
        unitOffset = const Offset(0, 1);
    }
    double targetOffset = clampDouble(additionalOffset + _scrollController.offset, _scrollController.position.minScrollExtent, _scrollController.position.maxScrollExtent);
    double offsetDelta = _scrollController.offset - targetOffset;
    return RevealedOffset(rect.shift(unitOffset * offsetDelta), targetOffset);
}

bool EditableTextState::_hasInputConnection() {
    return _textInputConnection?.attached ?? false;
}

bool EditableTextState::_needsAutofill() {
    return _effectiveAutofillClient.textInputConfiguration.autofillConfiguration.enabled;
}

void EditableTextState::_openInputConnection() {
    if (!_shouldCreateInputConnection) {
        return;
    }
    if (!_hasInputConnection) {
        TextEditingValue localValue = _value;
        _textInputConnection = _needsAutofill && currentAutofillScope != nullptr? currentAutofillScope!.attach(this, _effectiveAutofillClient.textInputConfiguration) : TextInput.attach(this, _effectiveAutofillClient.textInputConfiguration);
        _updateSizeAndTransform();
        _updateComposingRectIfNeeded();
        _updateCaretRectIfNeeded();
        TextStyle style = widget.style;
        ;
        if (_needsAutofill) {
            _textInputConnection!.requestAutofill();
        }
        _lastKnownRemoteTextEditingValue = localValue;
    } else {
        _textInputConnection!.show();
    }
}

void EditableTextState::_closeInputConnectionIfNeeded() {
    if (_hasInputConnection) {
        _textInputConnection!.close();
        _textInputConnection = nullptr;
        _lastKnownRemoteTextEditingValue = nullptr;
    }
}

void EditableTextState::_openOrCloseInputConnectionIfNeeded() {
    if (_hasFocus && widget.focusNode.consumeKeyboardToken()) {
        _openInputConnection();
    } else     {
        if (!_hasFocus) {
        _closeInputConnectionIfNeeded();
        widget.controller.clearComposing();
    }
;
    }}

void EditableTextState::_scheduleRestartConnection() {
    if (_restartConnectionScheduled) {
        return;
    }
    _restartConnectionScheduled = true;
    scheduleMicrotask(_restartConnectionIfNeeded);
}

void EditableTextState::_restartConnectionIfNeeded() {
    _restartConnectionScheduled = false;
    if (!_hasInputConnection || !_shouldCreateInputConnection) {
        return;
    }
    _textInputConnection!.close();
    _textInputConnection = nullptr;
    _lastKnownRemoteTextEditingValue = nullptr;
    AutofillScope currentAutofillScope = _needsAutofill? this.currentAutofillScope : nullptr;
    TextInputConnection newConnection = currentAutofillScope?.attach(this, textInputConfiguration) ?? TextInput.attach(this, _effectiveAutofillClient.textInputConfiguration);
    _textInputConnection = newConnection;
    TextStyle style = widget.style;
    ;
    _lastKnownRemoteTextEditingValue = _value;
}

void EditableTextState::_updateOrDisposeSelectionOverlayIfNeeded() {
    if (_selectionOverlay != nullptr) {
        if (_hasFocus) {
            _selectionOverlay!.update(_value);
        } else {
            _selectionOverlay!.dispose();
            _selectionOverlay = nullptr;
        }
    }
}

void EditableTextState::_updateSelectionOverlayForScroll() {
    _selectionOverlay?.updateForScroll();
}

void EditableTextState::_createSelectionOverlay() {
    _selectionOverlay = TextSelectionOverlay(_clipboardStatus, context, _value, widget, _toolbarLayerLink, _startHandleLayerLink, _endHandleLayerLink, renderEditable, widget.selectionControls, this, widget.dragStartBehavior, widget.onSelectionHandleTapped);
}

void EditableTextState::_handleSelectionChanged(SelectionChangedCause cause, TextSelection selection) {
    if (!widget.controller.isSelectionWithinTextBounds(selection)) {
        return;
    }
    widget.controller.selection = selection;
    ;
    if (widget.selectionControls == nullptr) {
        _selectionOverlay?.dispose();
        _selectionOverlay = nullptr;
    } else {
        if (_selectionOverlay == nullptr) {
            _createSelectionOverlay();
        } else {
            _selectionOverlay!.update(_value);
        }
        _selectionOverlay!.handlesVisible = widget.showSelectionHandles;
        _selectionOverlay!.showHandles();
    }
    ;
    if (_cursorTimer != nullptr) {
        _stopCursorBlink(false);
        _startCursorBlink();
    }
}

void EditableTextState::_handleCaretChanged(Rect caretRect) {
    _currentCaretRect = caretRect;
}

void EditableTextState::_scheduleShowCaretOnScreen(bool withAnimation) {
    if (_showCaretOnScreenScheduled) {
        return;
    }
    _showCaretOnScreenScheduled = true;
    SchedulerBinding.instance.addPostFrameCallback();
}

void EditableTextState::_formatAndSetValue(SelectionChangedCause cause, bool userInteraction, TextEditingValue value) {
    bool textChanged = _value.text != value.text || (!_value.composing.isCollapsed && value.composing.isCollapsed);
    bool selectionChanged = _value.selection != value.selection;
    if (textChanged) {
        ;
    }
    beginBatchEdit();
    _value = value;
    if (selectionChanged || (userInteraction && (cause == SelectionChangedCause.longPress || cause == SelectionChangedCause.keyboard))) {
        _handleSelectionChanged(_value.selection, cause);
    }
    if (textChanged) {
        ;
    }
    endBatchEdit();
}

void EditableTextState::_onCursorColorTick() {
    renderEditable.cursorColor = widget.cursorColor.withOpacity(_cursorBlinkOpacityController.value);
    _cursorVisibilityNotifier.value = widget.showCursor && _cursorBlinkOpacityController.value > 0;
}

void EditableTextState::_startCursorBlink() {
    assert(!(_cursorTimer?.isActive ?? false) || !(_backingCursorBlinkOpacityController?.isAnimating ?? false));
    _cursorActive = true;
    if (!_tickersEnabled) {
        return;
    }
    _cursorTimer?.cancel();
    _cursorBlinkOpacityController.value = 1.0;
    if (EditableText.debugDeterministicCursor) {
        return;
    }
    if (widget.cursorOpacityAnimates) {
        _cursorBlinkOpacityController.animateWith(_iosBlinkCursorSimulation).whenComplete(_onCursorTick);
    } else {
        _cursorTimer = Timer.periodic(_kCursorBlinkHalfPeriod, );
    }
}

void EditableTextState::_onCursorTick() {
    if (_obscureShowCharTicksPending > 0) {
        _obscureShowCharTicksPending = WidgetsBinding.instance.platformDispatcher.brieflyShowPassword? _obscureShowCharTicksPending - 1 : 0;
        if (_obscureShowCharTicksPending == 0) {
            setState();
        }
    }
    if (widget.cursorOpacityAnimates) {
        _cursorTimer?.cancel();
        _cursorTimer = Timer(Duration.zero, );
    } else {
        if (!(_cursorTimer?.isActive ?? false) && _tickersEnabled) {
            _cursorTimer = Timer.periodic(_kCursorBlinkHalfPeriod, );
        }
        _cursorBlinkOpacityController.value = _cursorBlinkOpacityController.value == 0? 1 : 0;
    }
}

void EditableTextState::_stopCursorBlink(bool resetCharTicks) {
    _cursorActive = false;
    _cursorBlinkOpacityController.value = 0.0;
    _cursorTimer?.cancel();
    _cursorTimer = nullptr;
    if (resetCharTicks) {
        _obscureShowCharTicksPending = 0;
    }
}

void EditableTextState::_startOrStopCursorTimerIfNeeded() {
    if (_cursorTimer == nullptr && _hasFocus && _value.selection.isCollapsed) {
        _startCursorBlink();
    } else     {
        if (_cursorActive && (!_hasFocus || !_value.selection.isCollapsed)) {
        _stopCursorBlink();
    }
;
    }}

void EditableTextState::_didChangeTextEditingValue() {
    _updateRemoteEditingValueIfNeeded();
    _startOrStopCursorTimerIfNeeded();
    _updateOrDisposeSelectionOverlayIfNeeded();
    setState();
    _adjacentLineAction.stopCurrentVerticalRunIfSelectionChanges();
}

void EditableTextState::_handleFocusChanged() {
    _openOrCloseInputConnectionIfNeeded();
    _startOrStopCursorTimerIfNeeded();
    _updateOrDisposeSelectionOverlayIfNeeded();
    if (_hasFocus) {
        WidgetsBinding.instance.addObserver(this);
        _lastBottomViewInset = WidgetsBinding.instance.window.viewInsets.bottom;
        if (!widget.readOnly) {
            _scheduleShowCaretOnScreen(true);
        }
        if (!_value.selection.isValid) {
            _handleSelectionChanged(TextSelection.collapsed(_value.text.length), nullptr);
        }
        _cachedText = "";
        _cachedFirstRect = nullptr;
        _cachedSize = Size.zero;
        _cachedPlaceholder = -1;
    } else {
        WidgetsBinding.instance.removeObserver(this);
        setState();
    }
    updateKeepAlive();
}

void EditableTextState::_updateSelectionRects(bool force) {
    if (!widget.scribbleEnabled) {
        return;
    }
    if (defaultTargetPlatform != TargetPlatform.iOS) {
        return;
    }
    if (WidgetsBinding.instance.window.physicalSize.shortestSide < _kIPadWidth) {
        return;
    }
    String text = renderEditable.text?.toPlainText(false) ?? "";
    List<Rect> firstSelectionBoxes = renderEditable.getBoxesForSelection(const TextSelection(0, 1));
    Rect firstRect = firstSelectionBoxes.isNotEmpty? firstSelectionBoxes.first : nullptr;
    ScrollDirection scrollDirection = _scrollController.position.userScrollDirection;
    Size size = renderEditable.size;
    bool textChanged = text != _cachedText;
    bool textStyleChanged = _cachedTextStyle != widget.style;
    bool firstRectChanged = _cachedFirstRect != firstRect;
    bool sizeChanged = _cachedSize != size;
    bool placeholderChanged = _cachedPlaceholder != _placeholderLocation;
    if (scrollDirection == ScrollDirection.idle && (force || textChanged || textStyleChanged || firstRectChanged || sizeChanged || placeholderChanged)) {
        _cachedText = text;
        _cachedFirstRect = firstRect;
        _cachedTextStyle = widget.style;
        _cachedSize = size;
        _cachedPlaceholder = _placeholderLocation;
        bool belowRenderEditableBottom = false;
        List<SelectionRect> rects = <SelectionRect>generate(_cachedText.characters.length, ).where().<SelectionRect>map().toList();
        _textInputConnection!.setSelectionRects(rects);
    }
}

void EditableTextState::_updateSizeAndTransform() {
    if (_hasInputConnection) {
        Size size = renderEditable.size;
        Matrix4 transform = renderEditable.getTransformTo(nullptr);
        _textInputConnection!.setEditableSizeAndTransform(size, transform);
        _updateSelectionRects();
        SchedulerBinding.instance.addPostFrameCallback();
    } else     {
        if (_placeholderLocation != -1) {
        removeTextPlaceholder();
    }
;
    }}

void EditableTextState::_updateComposingRectIfNeeded() {
    TextRange composingRange = _value.composing;
    if (_hasInputConnection) {
        assert(mounted);
        Rect composingRect = renderEditable.getRectForComposingRange(composingRange);
        if (composingRect == nullptr) {
            assert(!composingRange.isValid || composingRange.isCollapsed);
            int offset = composingRange.isValid? composingRange.start : 0;
            composingRect = renderEditable.getLocalRectForCaret(TextPosition(offset));
        }
        assert(composingRect != nullptr);
        _textInputConnection!.setComposingRect(composingRect);
        SchedulerBinding.instance.addPostFrameCallback();
    }
}

void EditableTextState::_updateCaretRectIfNeeded() {
    if (_hasInputConnection) {
        if (renderEditable.selection != nullptr && renderEditable.selection!.isValid && renderEditable.selection!.isCollapsed) {
            TextPosition currentTextPosition = TextPosition(renderEditable.selection!.baseOffset);
            Rect caretRect = renderEditable.getLocalRectForCaret(currentTextPosition);
            _textInputConnection!.setCaretRect(caretRect);
        }
        SchedulerBinding.instance.addPostFrameCallback();
    }
}

TextDirection EditableTextState::_textDirection() {
    TextDirection result = widget.textDirection ?? Directionality.of(context);
    assert(result != nullptr, "$runtimeType created without a textDirection and with no ambient Directionality.");
    return result;
}

double EditableTextState::_devicePixelRatio() {
    return MediaQuery.of(context).devicePixelRatio;
}

VoidCallback EditableTextState::_semanticsOnCopy(TextSelectionControls controls) {
    return widget.selectionEnabled && copyEnabled && _hasFocus && (controls?.canCopy(this) ?? false)?  : nullptr;
}

VoidCallback EditableTextState::_semanticsOnCut(TextSelectionControls controls) {
    return widget.selectionEnabled && cutEnabled && _hasFocus && (controls?.canCut(this) ?? false)?  : nullptr;
}

VoidCallback EditableTextState::_semanticsOnPaste(TextSelectionControls controls) {
    return widget.selectionEnabled && pasteEnabled && _hasFocus && (controls?.canPaste(this) ?? false) && (_clipboardStatus == nullptr || _clipboardStatus!.value == ClipboardStatus.pasteable)?  : nullptr;
}

_TextBoundary EditableTextState::_characterBoundary(DirectionalTextEditingIntent intent) {
    _TextBoundary atomicTextBoundary = widget.obscureText? _CodeUnitBoundary(_value) : _CharacterBoundary(_value);
    return _CollapsedSelectionBoundary(atomicTextBoundary, intent.forward);
}

_TextBoundary EditableTextState::_nextWordBoundary(DirectionalTextEditingIntent intent) {
    _TextBoundary atomicTextBoundary;
    _TextBoundary boundary;
    if (widget.obscureText) {
        atomicTextBoundary = _CodeUnitBoundary(_value);
        boundary = _DocumentBoundary(_value);
    } else {
        TextEditingValue textEditingValue = _textEditingValueforTextLayoutMetrics;
        atomicTextBoundary = _CharacterBoundary(textEditingValue);
        boundary = _ExpandedTextBoundary(_WhitespaceBoundary(textEditingValue), _WordBoundary(renderEditable, textEditingValue));
    }
    _MixedBoundary mixedBoundary = intent.forward? _MixedBoundary(atomicTextBoundary, boundary) : _MixedBoundary(boundary, atomicTextBoundary);
    return _CollapsedSelectionBoundary(mixedBoundary, intent.forward);
}

_TextBoundary EditableTextState::_linebreak(DirectionalTextEditingIntent intent) {
    _TextBoundary atomicTextBoundary;
    _TextBoundary boundary;
    if (widget.obscureText) {
        atomicTextBoundary = _CodeUnitBoundary(_value);
        boundary = _DocumentBoundary(_value);
    } else {
        TextEditingValue textEditingValue = _textEditingValueforTextLayoutMetrics;
        atomicTextBoundary = _CharacterBoundary(textEditingValue);
        boundary = _LineBreak(renderEditable, textEditingValue);
    }
    return intent.forward? _MixedBoundary(_CollapsedSelectionBoundary(atomicTextBoundary, true), boundary) : _MixedBoundary(boundary, _CollapsedSelectionBoundary(atomicTextBoundary, false));
}

_TextBoundary EditableTextState::_documentBoundary(DirectionalTextEditingIntent intent) {
    return _DocumentBoundary(_value);
}

Action<T> EditableTextState::_makeOverridable<T extends Intent>(Action<T> defaultAction) {
    return <T>overridable(context, defaultAction);
}

void EditableTextState::_transposeCharacters(TransposeCharactersIntent intent) {
    if (_value.text.characters.length <= 1 || _value.selection == nullptr || !_value.selection.isCollapsed || _value.selection.baseOffset == 0) {
        return;
    }
    String text = _value.text;
    TextSelection selection = _value.selection;
    bool atEnd = selection.baseOffset == text.length;
    CharacterRange transposing = CharacterRange.at(text, selection.baseOffset);
    if (atEnd) {
        transposing.moveBack(2);
    } else {
        ;
    }
    assert(transposing.currentCharacters.length == 2);
    userUpdateTextEditingValue(TextEditingValue(transposing.stringBefore + transposing.currentCharacters.last + transposing.currentCharacters.first + transposing.stringAfter, TextSelection.collapsed(transposing.stringBeforeLength + transposing.current.length)), SelectionChangedCause.keyboard);
}

void EditableTextState::_replaceText(ReplaceTextIntent intent) {
    TextEditingValue oldValue = _value;
    TextEditingValue newValue = intent.currentTextEditingValue.replaced(intent.replacementRange, intent.replacementText);
    userUpdateTextEditingValue(newValue, intent.cause);
    if (newValue == oldValue) {
        _didChangeTextEditingValue();
    }
}

void EditableTextState::_scrollToDocumentBoundary(ScrollToDocumentBoundaryIntent intent) {
    if (intent.forward) {
        bringIntoView(TextPosition(_value.text.length));
    } else {
        bringIntoView(const TextPosition(0));
    }
}

void EditableTextState::_updateSelection(UpdateSelectionIntent intent) {
    bringIntoView(intent.newSelection.extent);
    userUpdateTextEditingValue(intent.currentTextEditingValue.copyWith(intent.newSelection), intent.cause);
}

void EditableTextState::_expandSelectionToDocumentBoundary(ExpandSelectionToDocumentBoundaryIntent intent) {
    _TextBoundary textBoundary = _documentBoundary(intent);
    _expandSelection(intent.forward, textBoundary, true);
}

void EditableTextState::_expandSelectionToLinebreak(ExpandSelectionToLineBreakIntent intent) {
    _TextBoundary textBoundary = _linebreak(intent);
    _expandSelection(intent.forward, textBoundary);
}

void EditableTextState::_expandSelection(bool extentAtIndex, bool forward, _TextBoundary textBoundary) {
    TextSelection textBoundarySelection = textBoundary.textEditingValue.selection;
    if (!textBoundarySelection.isValid) {
        return;
    }
    bool inOrder = textBoundarySelection.baseOffset <= textBoundarySelection.extentOffset;
    bool towardsExtent = forward == inOrder;
    TextPosition position = towardsExtent? textBoundarySelection.extent : textBoundarySelection.base;
    TextPosition newExtent = forward? textBoundary.getTrailingTextBoundaryAt(position) : textBoundary.getLeadingTextBoundaryAt(position);
    TextSelection newSelection = textBoundarySelection.expandTo(newExtent, textBoundarySelection.isCollapsed || extentAtIndex);
    userUpdateTextEditingValue(_value.copyWith(newSelection), SelectionChangedCause.keyboard);
    bringIntoView(newSelection.extent);
}

Object EditableTextState::_hideToolbarIfVisible(DismissIntent intent) {
    if (_selectionOverlay?.toolbarIsVisible ?? false) {
        hideToolbar(false);
        return nullptr;
    }
    return Actions.invoke(context, intent);
}

RenderEditable _Editable::createRenderObject(BuildContext context) {
    return RenderEditable(inlineSpan, cursorColor, startHandleLayerLink, endHandleLayerLink, backgroundCursorColor, showCursor, forceLine, readOnly, hasFocus, maxLines, minLines, expands, strutStyle, selectionColor, textScaleFactor, textAlign, textDirection, locale ?? Localizations.maybeLocaleOf(context), value.selection, offset, onCaretChanged, rendererIgnoresPointer, obscuringCharacter, obscureText, textHeightBehavior, textWidthBasis, cursorWidth, cursorHeight, cursorRadius, cursorOffset, paintCursorAboveText, selectionHeightStyle, selectionWidthStyle, enableInteractiveSelection, textSelectionDelegate, devicePixelRatio, promptRectRange, promptRectColor, clipBehavior);
}

void _Editable::updateRenderObject(BuildContext context, RenderEditable renderObject) {
    ;
}

_Editable::_Editable(Color backgroundCursorColor, Clip clipBehavior, Color cursorColor, double cursorHeight, Offset cursorOffset, Radius cursorRadius, double cursorWidth, double devicePixelRatio, bool enableInteractiveSelection, LayerLink endHandleLayerLink, bool expands, bool forceLine, bool hasFocus, InlineSpan inlineSpan, Unknown, Locale locale, int maxLines, int minLines, bool obscureText, String obscuringCharacter, ViewportOffset offset, CaretChangedHandler onCaretChanged, bool paintCursorAboveText, Color promptRectColor, TextRange promptRectRange, bool readOnly, bool rendererIgnoresPointer, Color selectionColor, BoxHeightStyle selectionHeightStyle, BoxWidthStyle selectionWidthStyle, ValueNotifier<bool> showCursor, LayerLink startHandleLayerLink, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextSelectionDelegate textSelectionDelegate, TextWidthBasis textWidthBasis, TextEditingValue value) {
    {
        assert(textDirection != nullptr);
        assert(rendererIgnoresPointer != nullptr);
        super(_extractChildren(inlineSpan));
    }
}

List<Widget> _Editable::_extractChildren(InlineSpan span) {
    List<Widget> result = ;
    span.visitChildren();
    return result;
}

_ScribbleFocusableState _ScribbleFocusable::createState() {
    return _ScribbleFocusableState();
}

void _ScribbleFocusableState::initState() {
    super.initState();
    if (widget.enabled) {
        TextInput.registerScribbleElement(elementIdentifier, this);
    }
}

void _ScribbleFocusableState::didUpdateWidget(_ScribbleFocusable oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (!oldWidget.enabled && widget.enabled) {
        TextInput.registerScribbleElement(elementIdentifier, this);
    }
    if (oldWidget.enabled && !widget.enabled) {
        TextInput.unregisterScribbleElement(elementIdentifier);
    }
}

void _ScribbleFocusableState::dispose() {
    TextInput.unregisterScribbleElement(elementIdentifier);
    super.dispose();
}

RenderEditable _ScribbleFocusableState::renderEditable() {
    return (;
}

String _ScribbleFocusableState::elementIdentifier() {
    return _elementIdentifier;
}

void _ScribbleFocusableState::onScribbleFocus(Offset offset) {
    widget.focusNode.requestFocus();
    renderEditable?.selectPositionAt(offset, SelectionChangedCause.scribble);
    widget.updateSelectionRects();
}

bool _ScribbleFocusableState::isInScribbleRect(Rect rect) {
    Rect calculatedBounds = bounds;
    if (renderEditable?.readOnly ?? false) {
        return false;
    }
    if (calculatedBounds == Rect.zero) {
        return false;
    }
    if (!calculatedBounds.overlaps(rect)) {
        return false;
    }
    Rect intersection = calculatedBounds.intersect(rect);
    HitTestResult result = HitTestResult();
    WidgetsBinding.instance.hitTest(result, intersection.center);
    return result.path.any();
}

Rect _ScribbleFocusableState::bounds() {
    RenderBox box = (;
    if (box == nullptr || !mounted || !box.attached) {
        return Rect.zero;
    }
    Matrix4 transform = box.getTransformTo(nullptr);
    return MatrixUtils.transformRect(transform, Rect.fromLTWH(0, 0, box.size.width, box.size.height));
}

Widget _ScribbleFocusableState::build(BuildContext context) {
    return widget.child;
}

_ScribbleFocusableState::_ScribbleFocusableState() {
    {
        _elementIdentifier = (_nextElementIdentifier++).toString();
    }
}

void _ScribblePlaceholder::build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor) {
    assert(debugAssertIsValid());
    bool hasStyle = style != nullptr;
    if (hasStyle) {
        builder.pushStyle(style!.getTextStyle(textScaleFactor));
    }
    builder.addPlaceholder(size.width, size.height, alignmenttextScaleFactor);
    if (hasStyle) {
        builder.pop();
    }
}

_ScribblePlaceholder::_ScribblePlaceholder(Unknown, Unknown, Unknown, Size size) {
    {
        assert(child != nullptr);
        assert(baseline != nullptr || !(identical(alignment, ui.PlaceholderAlignment.aboveBaseline) || identical(alignment, ui.PlaceholderAlignment.belowBaseline) || identical(alignment, ui.PlaceholderAlignment.baseline)));
    }
}

TextRange _TextBoundary::getTextBoundaryAt(TextPosition position) {
    return TextRange(getLeadingTextBoundaryAt(position).offset, getTrailingTextBoundaryAt(position).offset);
}

TextPosition _CodeUnitBoundary::getLeadingTextBoundaryAt(TextPosition position) {
    return TextPosition(position.offset);
}

TextPosition _CodeUnitBoundary::getTrailingTextBoundaryAt(TextPosition position) {
    return TextPosition(math.min(position.offset + 1, textEditingValue.text.length));
}

TextPosition _WhitespaceBoundary::getLeadingTextBoundaryAt(TextPosition position) {
    for (; index >= 0; index = 1) {
        if (!TextLayoutMetrics.isWhitespace(textEditingValue.text.codeUnitAt(index))) {
            return TextPosition(index);
        }
    }
    return const TextPosition(0);
}

TextPosition _WhitespaceBoundary::getTrailingTextBoundaryAt(TextPosition position) {
    for (;  < textEditingValue.text.length; index = 1) {
        if (!TextLayoutMetrics.isWhitespace(textEditingValue.text.codeUnitAt(index))) {
            return TextPosition(index + 1);
        }
    }
    return TextPosition(textEditingValue.text.length);
}

TextPosition _CharacterBoundary::getLeadingTextBoundaryAt(TextPosition position) {
    int endOffset = math.min(position.offset + 1, textEditingValue.text.length);
    return TextPosition(CharacterRange.at(textEditingValue.text, position.offset, endOffset).stringBeforeLength);
}

TextPosition _CharacterBoundary::getTrailingTextBoundaryAt(TextPosition position) {
    int endOffset = math.min(position.offset + 1, textEditingValue.text.length);
    CharacterRange range = CharacterRange.at(textEditingValue.text, position.offset, endOffset);
    return TextPosition(textEditingValue.text.length - range.stringAfterLength);
}

TextRange _CharacterBoundary::getTextBoundaryAt(TextPosition position) {
    int endOffset = math.min(position.offset + 1, textEditingValue.text.length);
    CharacterRange range = CharacterRange.at(textEditingValue.text, position.offset, endOffset);
    return TextRange(range.stringBeforeLength, textEditingValue.text.length - range.stringAfterLength);
}

TextPosition _WordBoundary::getLeadingTextBoundaryAt(TextPosition position) {
    return TextPosition(textLayout.getWordBoundary(position).start, TextAffinity.downstream);
}

TextPosition _WordBoundary::getTrailingTextBoundaryAt(TextPosition position) {
    return TextPosition(textLayout.getWordBoundary(position).end, TextAffinity.downstream);
}

TextPosition _LineBreak::getLeadingTextBoundaryAt(TextPosition position) {
    return TextPosition(textLayout.getLineAtOffset(position).start);
}

TextPosition _LineBreak::getTrailingTextBoundaryAt(TextPosition position) {
    return TextPosition(textLayout.getLineAtOffset(position).end, TextAffinity.upstream);
}

TextPosition _DocumentBoundary::getLeadingTextBoundaryAt(TextPosition position) {
    return const TextPosition(0);
}

TextPosition _DocumentBoundary::getTrailingTextBoundaryAt(TextPosition position) {
    return TextPosition(textEditingValue.text.length, TextAffinity.upstream);
}

TextEditingValue _ExpandedTextBoundary::textEditingValue() {
    assert(innerTextBoundary.textEditingValue == outerTextBoundary.textEditingValue);
    return innerTextBoundary.textEditingValue;
}

TextPosition _ExpandedTextBoundary::getLeadingTextBoundaryAt(TextPosition position) {
    return outerTextBoundary.getLeadingTextBoundaryAt(innerTextBoundary.getLeadingTextBoundaryAt(position));
}

TextPosition _ExpandedTextBoundary::getTrailingTextBoundaryAt(TextPosition position) {
    return outerTextBoundary.getTrailingTextBoundaryAt(innerTextBoundary.getTrailingTextBoundaryAt(position));
}

TextEditingValue _CollapsedSelectionBoundary::textEditingValue() {
    return innerTextBoundary.textEditingValue;
}

TextPosition _CollapsedSelectionBoundary::getLeadingTextBoundaryAt(TextPosition position) {
    return isForward? innerTextBoundary.getLeadingTextBoundaryAt(position) : position.offset <= 0? const TextPosition(0) : innerTextBoundary.getLeadingTextBoundaryAt(TextPosition(position.offset - 1));
}

TextPosition _CollapsedSelectionBoundary::getTrailingTextBoundaryAt(TextPosition position) {
    return isForward? innerTextBoundary.getTrailingTextBoundaryAt(position) : position.offset <= 0? const TextPosition(0) : innerTextBoundary.getTrailingTextBoundaryAt(TextPosition(position.offset - 1));
}

TextEditingValue _MixedBoundary::textEditingValue() {
    assert(leadingTextBoundary.textEditingValue == trailingTextBoundary.textEditingValue);
    return leadingTextBoundary.textEditingValue;
}

TextPosition _MixedBoundary::getLeadingTextBoundaryAt(TextPosition position) {
    return leadingTextBoundary.getLeadingTextBoundaryAt(position);
}

TextPosition _MixedBoundary::getTrailingTextBoundaryAt(TextPosition position) {
    return trailingTextBoundary.getTrailingTextBoundaryAt(position);
}

Object _DeleteTextAction::invoke(BuildContext context, T intent) {
    TextSelection selection = state._value.selection;
    assert(selection.isValid);
    if (!selection.isCollapsed) {
        return Actions.invoke(context!, ReplaceTextIntent(state._value, "", _expandNonCollapsedRange(state._value), SelectionChangedCause.keyboard));
    }
    _TextBoundary textBoundary = getTextBoundariesForIntent(intent);
    if (!textBoundary.textEditingValue.selection.isValid) {
        return nullptr;
    }
    if (!textBoundary.textEditingValue.selection.isCollapsed) {
        return Actions.invoke(context!, ReplaceTextIntent(state._value, "", _expandNonCollapsedRange(textBoundary.textEditingValue), SelectionChangedCause.keyboard));
    }
    return Actions.invoke(context!, ReplaceTextIntent(textBoundary.textEditingValue, "", textBoundary.getTextBoundaryAt(textBoundary.textEditingValue.selection.base), SelectionChangedCause.keyboard));
}

bool _DeleteTextAction::isActionEnabled() {
    return !state.widget.readOnly && state._value.selection.isValid;
}

TextRange _DeleteTextAction::_expandNonCollapsedRange(TextEditingValue value) {
    TextRange selection = value.selection;
    assert(selection.isValid);
    assert(!selection.isCollapsed);
    _TextBoundary atomicBoundary = state.widget.obscureText? _CodeUnitBoundary(value) : _CharacterBoundary(value);
    return TextRange(atomicBoundary.getLeadingTextBoundaryAt(TextPosition(selection.start)).offset, atomicBoundary.getTrailingTextBoundaryAt(TextPosition(selection.end - 1)).offset);
}

Object _UpdateTextSelectionAction::invoke(BuildContext context, T intent) {
    TextSelection selection = state._value.selection;
    assert(selection.isValid);
    bool collapseSelection = intent.collapseSelection || !state.widget.selectionEnabled;
    ;
    if (!selection.isCollapsed && !ignoreNonCollapsedSelection && collapseSelection) {
        return Actions.invoke(context!, UpdateSelectionIntent(state._value, collapse(selection), SelectionChangedCause.keyboard));
    }
    _TextBoundary textBoundary = getTextBoundariesForIntent(intent);
    TextSelection textBoundarySelection = textBoundary.textEditingValue.selection;
    if (!textBoundarySelection.isValid) {
        return nullptr;
    }
    if (!textBoundarySelection.isCollapsed && !ignoreNonCollapsedSelection && collapseSelection) {
        return Actions.invoke(context!, UpdateSelectionIntent(state._value, collapse(textBoundarySelection), SelectionChangedCause.keyboard));
    }
    TextPosition extent = textBoundarySelection.extent;
    if (intent.continuesAtWrap) {
        if (intent.forward && _isAtWordwrapUpstream(extent)) {
            extent = TextPosition(extent.offset);
        } else         {
            if (!intent.forward && _isAtWordwrapDownstream(extent)) {
            extent = TextPosition(extent.offset, TextAffinity.upstream);
        }
;
        }    }
    TextPosition newExtent = intent.forward? textBoundary.getTrailingTextBoundaryAt(extent) : textBoundary.getLeadingTextBoundaryAt(extent);
    TextSelection newSelection = collapseSelection? TextSelection.fromPosition(newExtent) : textBoundarySelection.extendTo(newExtent);
    if (!selection.isCollapsed && intent.collapseAtReversal && (selection.baseOffset < selection.extentOffset != newSelection.baseOffset < newSelection.extentOffset)) {
        return Actions.invoke(context!, UpdateSelectionIntent(state._value, TextSelection.fromPosition(selection.base), SelectionChangedCause.keyboard));
    }
    return Actions.invoke(context!, UpdateSelectionIntent(textBoundary.textEditingValue, newSelection, SelectionChangedCause.keyboard));
}

bool _UpdateTextSelectionAction::isActionEnabled() {
    return state._value.selection.isValid;
}

bool _UpdateTextSelectionAction::_isAtWordwrapUpstream(TextPosition position) {
    TextPosition end = TextPosition(state.renderEditable.getLineAtOffset(position).end, TextAffinity.upstream);
    return end == position && end.offset != state.textEditingValue.text.length && state.textEditingValue.text.codeUnitAt(position.offset) != NEWLINE_CODE_UNIT;
}

bool _UpdateTextSelectionAction::_isAtWordwrapDownstream(TextPosition position) {
    TextPosition start = TextPosition(state.renderEditable.getLineAtOffset(position).start);
    return start == position && start.offset != 0 && state.textEditingValue.text.codeUnitAt(position.offset - 1) != NEWLINE_CODE_UNIT;
}

Object _ExtendSelectionOrCaretPositionAction::invoke(BuildContext context, ExtendSelectionToNextWordBoundaryOrCaretLocationIntent intent) {
    TextSelection selection = state._value.selection;
    assert(selection.isValid);
    _TextBoundary textBoundary = getTextBoundariesForIntent(intent);
    TextSelection textBoundarySelection = textBoundary.textEditingValue.selection;
    if (!textBoundarySelection.isValid) {
        return nullptr;
    }
    TextPosition extent = textBoundarySelection.extent;
    TextPosition newExtent = intent.forward? textBoundary.getTrailingTextBoundaryAt(extent) : textBoundary.getLeadingTextBoundaryAt(extent);
    TextSelection newSelection = (newExtent.offset - textBoundarySelection.baseOffset) * (textBoundarySelection.extentOffset - textBoundarySelection.baseOffset) < 0? textBoundarySelection.copyWith(textBoundarySelection.baseOffset, textBoundarySelection.extentOffset > textBoundarySelection.baseOffset? TextAffinity.downstream : TextAffinity.upstream) : textBoundarySelection.extendTo(newExtent);
    return Actions.invoke(context!, UpdateSelectionIntent(textBoundary.textEditingValue, newSelection, SelectionChangedCause.keyboard));
}

bool _ExtendSelectionOrCaretPositionAction::isActionEnabled() {
    return state.widget.selectionEnabled && state._value.selection.isValid;
}

void _UpdateTextSelectionToAdjacentLineAction::stopCurrentVerticalRunIfSelectionChanges() {
    TextSelection runSelection = _runSelection;
    if (runSelection == nullptr) {
        assert(_verticalMovementRun == nullptr);
        return;
    }
    _runSelection = state._value.selection;
    TextSelection currentSelection = state.widget.controller.selection;
    bool continueCurrentRun = currentSelection.isValid && currentSelection.isCollapsed && currentSelection.baseOffset == runSelection.baseOffset && currentSelection.extentOffset == runSelection.extentOffset;
    if (!continueCurrentRun) {
        _verticalMovementRun = nullptr;
        _runSelection = nullptr;
    }
}

void _UpdateTextSelectionToAdjacentLineAction::invoke(BuildContext context, T intent) {
    assert(state._value.selection.isValid);
    bool collapseSelection = intent.collapseSelection || !state.widget.selectionEnabled;
    TextEditingValue value = state._textEditingValueforTextLayoutMetrics;
    if (!value.selection.isValid) {
        return;
    }
    if (_verticalMovementRun?.isValid == false) {
        _verticalMovementRun = nullptr;
        _runSelection = nullptr;
    }
    VerticalCaretMovementRun currentRun = _verticalMovementRun ?? state.renderEditable.startVerticalCaretMovement(state.renderEditable.selection!.extent);
    bool shouldMove = intent.forward? currentRun.moveNext() : currentRun.movePrevious();
    TextPosition newExtent = shouldMove? currentRun.current : (intent.forward? TextPosition(state._value.text.length) : const TextPosition(0));
    TextSelection newSelection = collapseSelection? TextSelection.fromPosition(newExtent) : value.selection.extendTo(newExtent);
    Actions.invoke(context!, UpdateSelectionIntent(value, newSelection, SelectionChangedCause.keyboard));
    if (state._value.selection == newSelection) {
        _verticalMovementRun = currentRun;
        _runSelection = newSelection;
    }
}

bool _UpdateTextSelectionToAdjacentLineAction::isActionEnabled() {
    return state._value.selection.isValid;
}

Object _SelectAllAction::invoke(BuildContext context, SelectAllTextIntent intent) {
    return Actions.invoke(context!, UpdateSelectionIntent(state._value, TextSelection(0, state._value.text.length), intent.cause));
}

bool _SelectAllAction::isActionEnabled() {
    return state.widget.selectionEnabled;
}

void _CopySelectionAction::invoke(BuildContext context, CopySelectionTextIntent intent) {
    if (intent.collapseSelection) {
        state.cutSelection(intent.cause);
    } else {
        state.copySelection(intent.cause);
    }
}

bool _CopySelectionAction::isActionEnabled() {
    return state._value.selection.isValid && !state._value.selection.isCollapsed;
}

State<_TextEditingHistory> _TextEditingHistory::createState() {
    return _TextEditingHistoryState();
}

void _TextEditingHistoryState::initState() {
    super.initState();
    _throttledPush = <TextEditingValue>_throttle(_kThrottleDuration, _stack.push);
    _push();
    widget.controller.addListener(_push);
}

void _TextEditingHistoryState::didUpdateWidget(_TextEditingHistory oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.controller != oldWidget.controller) {
        _stack.clear();
        oldWidget.controller.removeListener(_push);
        widget.controller.addListener(_push);
    }
}

void _TextEditingHistoryState::dispose() {
    widget.controller.removeListener(_push);
    _throttleTimer?.cancel();
    super.dispose();
}

Widget _TextEditingHistoryState::build(BuildContext context) {
    return Actions(, widget.child);
}

void _TextEditingHistoryState::_undo(UndoTextIntent intent) {
    _update(_stack.undo());
}

void _TextEditingHistoryState::_redo(RedoTextIntent intent) {
    _update(_stack.redo());
}

void _TextEditingHistoryState::_update(TextEditingValue nextValue) {
    if (nextValue == nullptr) {
        return;
    }
    if (nextValue.text == widget.controller.text) {
        return;
    }
    widget.onTriggered(widget.controller.value.copyWith(nextValue.text, nextValue.selection));
}

void _TextEditingHistoryState::_push() {
    if (widget.controller.value == TextEditingValue.empty) {
        return;
    }
    _throttleTimer = _throttledPush(widget.controller.value);
}

T _UndoStack::currentValue() {
    return _list.isEmpty? nullptr : _list[_index];
}

void _UndoStack::push(T value) {
    if (_list.isEmpty) {
        _index = 0;
        _list.add(value);
        return;
    }
    assert( < _list.length && _index >= 0);
    if (value == currentValue) {
        return;
    }
    if (_index != nullptr && _index != _list.length - 1) {
        _list.removeRange(_index + 1, _list.length);
    }
    _list.add(value);
    _index = _list.length - 1;
}

T _UndoStack::undo() {
    if (_list.isEmpty) {
        return nullptr;
    }
    assert( < _list.length && _index >= 0);
    if (_index != 0) {
        _index = _index - 1;
    }
    return currentValue;
}

T _UndoStack::redo() {
    if (_list.isEmpty) {
        return nullptr;
    }
    assert( < _list.length && _index >= 0);
    if ( < _list.length - 1) {
        _index = _index + 1;
    }
    return currentValue;
}

void _UndoStack::clear() {
    _list.clear();
    _index = -1;
}

String _UndoStack::toString() {
    return "_UndoStack $_list";
}

_Throttled<T> _throttle<T>(Duration duration, _Throttleable<T> function, bool leadingEdge) {
    Timer timer;
    bool calledDuringTimer = false;
    T arg;
    return ;
}
