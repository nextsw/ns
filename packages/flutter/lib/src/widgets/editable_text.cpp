#include "editable_text.hpp"
TextEditingControllerCls::TextEditingControllerCls(String text) : ValueNotifier<TextEditingValue>(text == nullptr? TextEditingValueCls::empty : make<TextEditingValueCls>(text)) {
}

void TextEditingControllerCls::fromValue(TextEditingValue value)

String TextEditingControllerCls::text() {
    return value->text;
}

void TextEditingControllerCls::text(String newText) {
    value = value->copyWith(newText, TextSelectionCls->collapsed(-1), TextRangeCls::empty);
}

void TextEditingControllerCls::value(TextEditingValue newValue) {
    assert(!newValue->composing->isValid() || newValue->isComposingRangeValid(), __s("New TextEditingValue $newValue has an invalid non-empty composing range ${newValue.composing}. It is recommended to use a valid composing range, even for readonly text fields"));
    super->value = newValue;
}

TextSpan TextEditingControllerCls::buildTextSpan(BuildContext context, TextStyle style, bool withComposing) {
    assert(!value->composing->isValid || !withComposing || value->isComposingRangeValid);
    if (!value->isComposingRangeValid || !withComposing) {
        return make<TextSpanCls>(style, text());
    }
    TextStyle composingStyle = style?->merge(make<TextStyleCls>(TextDecorationCls::underline)) | make<TextStyleCls>(TextDecorationCls::underline);
    return make<TextSpanCls>(style, makeList(ArrayItem, ArrayItem, ArrayItem));
}

TextSelection TextEditingControllerCls::selection() {
    return value->selection;
}

void TextEditingControllerCls::selection(TextSelection newSelection) {
    if (!isSelectionWithinTextBounds(newSelection)) {
        throw make<FlutterErrorCls>(__s("invalid text selection: $newSelection"));
    }
    TextRange newComposing = newSelection->isCollapsed() && _isSelectionWithinComposingRange(newSelection)? value->composing : TextRangeCls::empty;
    value = value->copyWith(newSelection, newComposing);
}

void TextEditingControllerCls::clear() {
    value = make<TextEditingValueCls>(TextSelectionCls->collapsed(0));
}

void TextEditingControllerCls::clearComposing() {
    value = value->copyWith(TextRangeCls::empty);
}

bool TextEditingControllerCls::isSelectionWithinTextBounds(TextSelection selection) {
    return selection->start <= text()->length() && selection->end <= text()->length();
}

bool TextEditingControllerCls::_isSelectionWithinComposingRange(TextSelection selection) {
    return selection->start >= value->composing->start && selection->end <= value->composing->end;
}

ToolbarOptionsCls::ToolbarOptionsCls(bool copy, bool cut, bool paste, bool selectAll) {
    {
        assert(copy != nullptr);
        assert(cut != nullptr);
        assert(paste != nullptr);
        assert(selectAll != nullptr);
    }
}

void _DiscreteKeyFrameSimulationCls::iOSBlinkingCaret()

double _DiscreteKeyFrameSimulationCls::dx(double time) {
    return 0;
}

bool _DiscreteKeyFrameSimulationCls::isDone(double time) {
    return time >= maxDuration;
}

double _DiscreteKeyFrameSimulationCls::x(double time) {
    int length = _keyFrames->length();
    int searchIndex;
    int endIndex;
    if (_keyFrames[_lastKeyFrameIndex]->time > time) {
        searchIndex = 0;
        endIndex = _lastKeyFrameIndex;
    } else {
        searchIndex = _lastKeyFrameIndex;
        endIndex = length;
    }
    while ( < endIndex - 1) {
        assert(_keyFrames[searchIndex]->time <= time);
        _KeyFrame next = _keyFrames[searchIndex + 1];
        if ( < next->time) {
            break;
        }
        searchIndex += 1;
    }
    _lastKeyFrameIndex = searchIndex;
    return _keyFrames[_lastKeyFrameIndex]->value;
}

void _DiscreteKeyFrameSimulationCls::_(List<_KeyFrame> _keyFrames, double maxDuration)

EditableTextCls::EditableTextCls(bool autocorrect, Color autocorrectionTextRectColor, AutofillClient autofillClient, Iterable<String> autofillHints, bool autofocus, Color backgroundCursorColor, Clip clipBehavior, TextEditingController controller, Color cursorColor, double cursorHeight, Offset cursorOffset, bool cursorOpacityAnimates, Radius cursorRadius, double cursorWidth, DragStartBehavior dragStartBehavior, bool enableIMEPersonalizedLearning, bool enableInteractiveSelection, bool enableSuggestions, bool expands, FocusNode focusNode, bool forceLine, List<TextInputFormatter> inputFormatters, Key key, Brightness keyboardAppearance, TextInputType keyboardType, Locale locale, int maxLines, int minLines, MouseCursor mouseCursor, bool obscureText, String obscuringCharacter, AppPrivateCommandCallback onAppPrivateCommand, ValueChanged<String> onChanged, VoidCallback onEditingComplete, SelectionChangedCallback onSelectionChanged, VoidCallback onSelectionHandleTapped, ValueChanged<String> onSubmitted, bool paintCursorAboveText, bool readOnly, bool rendererIgnoresPointer, String restorationId, bool scribbleEnabled, ScrollBehavior scrollBehavior, ScrollController scrollController, EdgeInsets scrollPadding, ScrollPhysics scrollPhysics, Color selectionColor, TextSelectionControls selectionControls, BoxHeightStyle selectionHeightStyle, BoxWidthStyle selectionWidthStyle, bool showCursor, bool showSelectionHandles, SmartDashesType smartDashesType, SmartQuotesType smartQuotesType, StrutStyle strutStyle, TextStyle style, TextAlign textAlign, TextCapitalization textCapitalization, TextDirection textDirection, TextHeightBehavior textHeightBehavior, TextInputAction textInputAction, double textScaleFactor, TextWidthBasis textWidthBasis, ToolbarOptions toolbarOptions) {
    {
        assert(controller != nullptr);
        assert(focusNode != nullptr);
        assert(obscuringCharacter != nullptr && obscuringCharacter->length() == 1);
        assert(obscureText != nullptr);
        assert(autocorrect != nullptr);
        smartDashesType = smartDashesType | (obscureText? SmartDashesTypeCls::disabled : SmartDashesTypeCls::enabled);
        smartQuotesType = smartQuotesType | (obscureText? SmartQuotesTypeCls::disabled : SmartQuotesTypeCls::enabled);
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
        assert((maxLines == nullptr) || (minLines == nullptr) || (maxLines >= minLines), __s("minLines can't be greater than maxLines"));
        assert(expands != nullptr);
        assert(!expands || (maxLines == nullptr && minLines == nullptr), __s("minLines and maxLines must be null when expands is true."));
        assert(!obscureText || maxLines == 1, __s("Obscured fields cannot be multiline."));
        assert(autofocus != nullptr);
        assert(rendererIgnoresPointer != nullptr);
        assert(scrollPadding != nullptr);
        assert(dragStartBehavior != nullptr);
        enableInteractiveSelection = enableInteractiveSelection | (!readOnly || !obscureText);
        toolbarOptions = toolbarOptions | (obscureText? (readOnly? make<ToolbarOptionsCls>() : make<ToolbarOptionsCls>(true, true)) : (readOnly? make<ToolbarOptionsCls>(true, true) : make<ToolbarOptionsCls>(true, true, true, true)));
        assert(clipBehavior != nullptr);
        assert(enableIMEPersonalizedLearning != nullptr);
        _strutStyle = strutStyle;
        keyboardType = keyboardType | _inferKeyboardType(autofillHints, maxLines);
            List<TextInputFormatter> list1 = make<ListCls<>>();    list1.add(ArrayItem);    for (auto _x1 : inputFormatters | <TextInputFormatter>empty()) {    {        list1.add(_x1);    }inputFormatters = maxLines == 1? list1 : inputFormatters;
        showCursor = showCursor | !readOnly;
    }
}

StrutStyle EditableTextCls::strutStyle() {
    if (_strutStyle == nullptr) {
        return StrutStyleCls->fromTextStyle(style, true);
    }
    return _strutStyle!->inheritFromTextStyle(style);
}

bool EditableTextCls::selectionEnabled() {
    return enableInteractiveSelection;
}

EditableTextState EditableTextCls::createState() {
    return make<EditableTextStateCls>();
}

void EditableTextCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<TextEditingController>make<DiagnosticsPropertyCls>(__s("controller"), controller));
    properties->add(<FocusNode>make<DiagnosticsPropertyCls>(__s("focusNode"), focusNode));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("obscureText"), obscureText, false));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("readOnly"), readOnly, false));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("autocorrect"), autocorrect, true));
    properties->add(<SmartDashesType>make<EnumPropertyCls>(__s("smartDashesType"), smartDashesType, obscureText? SmartDashesTypeCls::disabled : SmartDashesTypeCls::enabled));
    properties->add(<SmartQuotesType>make<EnumPropertyCls>(__s("smartQuotesType"), smartQuotesType, obscureText? SmartQuotesTypeCls::disabled : SmartQuotesTypeCls::enabled));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("enableSuggestions"), enableSuggestions, true));
    style->debugFillProperties(properties);
    properties->add(<TextAlign>make<EnumPropertyCls>(__s("textAlign"), textAlign, nullptr));
    properties->add(<TextDirection>make<EnumPropertyCls>(__s("textDirection"), textDirection, nullptr));
    properties->add(<Locale>make<DiagnosticsPropertyCls>(__s("locale"), locale, nullptr));
    properties->add(make<DoublePropertyCls>(__s("textScaleFactor"), textScaleFactor, nullptr));
    properties->add(make<IntPropertyCls>(__s("maxLines"), maxLines, 1));
    properties->add(make<IntPropertyCls>(__s("minLines"), minLines, nullptr));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("expands"), expands, false));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("autofocus"), autofocus, false));
    properties->add(<TextInputType>make<DiagnosticsPropertyCls>(__s("keyboardType"), keyboardType, nullptr));
    properties->add(<ScrollController>make<DiagnosticsPropertyCls>(__s("scrollController"), scrollController, nullptr));
    properties->add(<ScrollPhysics>make<DiagnosticsPropertyCls>(__s("scrollPhysics"), scrollPhysics, nullptr));
    properties->add(<Iterable<String>>make<DiagnosticsPropertyCls>(__s("autofillHints"), autofillHints, nullptr));
    properties->add(<TextHeightBehavior>make<DiagnosticsPropertyCls>(__s("textHeightBehavior"), textHeightBehavior, nullptr));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("scribbleEnabled"), scribbleEnabled, true));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("enableIMEPersonalizedLearning"), enableIMEPersonalizedLearning, true));
    properties->add(<bool>make<DiagnosticsPropertyCls>(__s("enableInteractiveSelection"), enableInteractiveSelection, true));
}

bool EditableTextCls::_userSelectionEnabled() {
    return enableInteractiveSelection && (!readOnly || !obscureText);
}

TextInputType EditableTextCls::_inferKeyboardType(Iterable<String> autofillHints, int maxLines) {
    if (autofillHints == nullptr || autofillHints->isEmpty()) {
        return maxLines == 1? TextInputTypeCls::text : TextInputTypeCls::multiline;
    }
    String effectiveHint = autofillHints->first();
    if (!kIsWeb) {
        ;
    }
    if (maxLines != 1) {
        return TextInputTypeCls::multiline;
    }
    Map<String, TextInputType> map1 = make<MapCls<>>();map1.set(AutofillHintsCls::addressCity, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::addressCityAndState, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::addressState, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::birthday, TextInputTypeCls::datetime);map1.set(AutofillHintsCls::birthdayDay, TextInputTypeCls::datetime);map1.set(AutofillHintsCls::birthdayMonth, TextInputTypeCls::datetime);map1.set(AutofillHintsCls::birthdayYear, TextInputTypeCls::datetime);map1.set(AutofillHintsCls::countryCode, TextInputTypeCls::number);map1.set(AutofillHintsCls::countryName, TextInputTypeCls::text);map1.set(AutofillHintsCls::creditCardExpirationDate, TextInputTypeCls::datetime);map1.set(AutofillHintsCls::creditCardExpirationDay, TextInputTypeCls::datetime);map1.set(AutofillHintsCls::creditCardExpirationMonth, TextInputTypeCls::datetime);map1.set(AutofillHintsCls::creditCardExpirationYear, TextInputTypeCls::datetime);map1.set(AutofillHintsCls::creditCardFamilyName, TextInputTypeCls::name);map1.set(AutofillHintsCls::creditCardGivenName, TextInputTypeCls::name);map1.set(AutofillHintsCls::creditCardMiddleName, TextInputTypeCls::name);map1.set(AutofillHintsCls::creditCardName, TextInputTypeCls::name);map1.set(AutofillHintsCls::creditCardNumber, TextInputTypeCls::number);map1.set(AutofillHintsCls::creditCardSecurityCode, TextInputTypeCls::number);map1.set(AutofillHintsCls::creditCardType, TextInputTypeCls::text);map1.set(AutofillHintsCls::email, TextInputTypeCls::emailAddress);map1.set(AutofillHintsCls::familyName, TextInputTypeCls::name);map1.set(AutofillHintsCls::fullStreetAddress, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::gender, TextInputTypeCls::text);map1.set(AutofillHintsCls::givenName, TextInputTypeCls::name);map1.set(AutofillHintsCls::impp, TextInputTypeCls::url);map1.set(AutofillHintsCls::jobTitle, TextInputTypeCls::text);map1.set(AutofillHintsCls::language, TextInputTypeCls::text);map1.set(AutofillHintsCls::location, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::middleInitial, TextInputTypeCls::name);map1.set(AutofillHintsCls::middleName, TextInputTypeCls::name);map1.set(AutofillHintsCls::name, TextInputTypeCls::name);map1.set(AutofillHintsCls::namePrefix, TextInputTypeCls::name);map1.set(AutofillHintsCls::nameSuffix, TextInputTypeCls::name);map1.set(AutofillHintsCls::newPassword, TextInputTypeCls::text);map1.set(AutofillHintsCls::newUsername, TextInputTypeCls::text);map1.set(AutofillHintsCls::nickname, TextInputTypeCls::text);map1.set(AutofillHintsCls::oneTimeCode, TextInputTypeCls::text);map1.set(AutofillHintsCls::organizationName, TextInputTypeCls::text);map1.set(AutofillHintsCls::password, TextInputTypeCls::text);map1.set(AutofillHintsCls::photo, TextInputTypeCls::text);map1.set(AutofillHintsCls::postalAddress, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::postalAddressExtended, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::postalAddressExtendedPostalCode, TextInputTypeCls::number);map1.set(AutofillHintsCls::postalCode, TextInputTypeCls::number);map1.set(AutofillHintsCls::streetAddressLevel1, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::streetAddressLevel2, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::streetAddressLevel3, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::streetAddressLevel4, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::streetAddressLine1, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::streetAddressLine2, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::streetAddressLine3, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::sublocality, TextInputTypeCls::streetAddress);map1.set(AutofillHintsCls::telephoneNumber, TextInputTypeCls::phone);map1.set(AutofillHintsCls::telephoneNumberAreaCode, TextInputTypeCls::phone);map1.set(AutofillHintsCls::telephoneNumberCountryCode, TextInputTypeCls::phone);map1.set(AutofillHintsCls::telephoneNumberDevice, TextInputTypeCls::phone);map1.set(AutofillHintsCls::telephoneNumberExtension, TextInputTypeCls::phone);map1.set(AutofillHintsCls::telephoneNumberLocal, TextInputTypeCls::phone);map1.set(AutofillHintsCls::telephoneNumberLocalPrefix, TextInputTypeCls::phone);map1.set(AutofillHintsCls::telephoneNumberLocalSuffix, TextInputTypeCls::phone);map1.set(AutofillHintsCls::telephoneNumberNational, TextInputTypeCls::phone);map1.set(AutofillHintsCls::transactionAmount, TextInputTypeCls->numberWithOptions(true));map1.set(AutofillHintsCls::transactionCurrency, TextInputTypeCls::text);map1.set(AutofillHintsCls::url, TextInputTypeCls::url);map1.set(AutofillHintsCls::username, TextInputTypeCls::text);Map<String, TextInputType> inferKeyboardType = list1;
    return inferKeyboardType[effectiveHint] | TextInputTypeCls::text;
}

AutofillScope EditableTextStateCls::currentAutofillScope() {
    return _currentAutofillScope;
}

bool EditableTextStateCls::wantKeepAlive() {
    return widget()->focusNode->hasFocus;
}

bool EditableTextStateCls::cutEnabled() {
    return widget()->toolbarOptions->cut && !widget()->readOnly && !widget()->obscureText;
}

bool EditableTextStateCls::copyEnabled() {
    return widget()->toolbarOptions->copy && !widget()->obscureText;
}

bool EditableTextStateCls::pasteEnabled() {
    return widget()->toolbarOptions->paste && !widget()->readOnly;
}

bool EditableTextStateCls::selectAllEnabled() {
    return widget()->toolbarOptions->selectAll && (!widget()->readOnly || !widget()->obscureText) && widget()->enableInteractiveSelection;
}

void EditableTextStateCls::copySelection(SelectionChangedCause cause) {
    TextSelection selection = textEditingValue()->selection;
    assert(selection != nullptr);
    if (selection->isCollapsed() || widget()->obscureText) {
        return;
    }
    String text = textEditingValue()->text;
    ClipboardCls->setData(make<ClipboardDataCls>(selection->textInside(text)));
    if (cause == SelectionChangedCauseCls::toolbar) {
        bringIntoView(textEditingValue()->selection->extent());
        hideToolbar(false);
        ;
    }
    _clipboardStatus?->update();
}

void EditableTextStateCls::cutSelection(SelectionChangedCause cause) {
    if (widget()->readOnly || widget()->obscureText) {
        return;
    }
    TextSelection selection = textEditingValue()->selection;
    String text = textEditingValue()->text;
    assert(selection != nullptr);
    if (selection->isCollapsed()) {
        return;
    }
    ClipboardCls->setData(make<ClipboardDataCls>(selection->textInside(text)));
    _replaceText(make<ReplaceTextIntentCls>(textEditingValue(), __s(""), selection, cause));
    if (cause == SelectionChangedCauseCls::toolbar) {
        SchedulerBindingCls::instance->addPostFrameCallback([=] () {
            if (mounted()) {
                bringIntoView(textEditingValue()->selection->extent());
            }
        });
        hideToolbar();
    }
    _clipboardStatus?->update();
}

Future<void> EditableTextStateCls::pasteText(SelectionChangedCause cause) {
    if (widget()->readOnly) {
        return;
    }
    TextSelection selection = textEditingValue()->selection;
    assert(selection != nullptr);
    if (!selection->isValid()) {
        return;
    }
    ClipboardData data = await ClipboardCls->getData(ClipboardCls::kTextPlain);
    if (data == nullptr) {
        return;
    }
    int lastSelectionIndex = math->max(selection->baseOffset, selection->extentOffset);
    TextEditingValue collapsedTextEditingValue = textEditingValue()->copyWith(TextSelectionCls->collapsed(lastSelectionIndex));
    userUpdateTextEditingValue(collapsedTextEditingValue->replaced(selection, data->text!), cause);
    if (cause == SelectionChangedCauseCls::toolbar) {
        SchedulerBindingCls::instance->addPostFrameCallback([=] () {
            if (mounted()) {
                bringIntoView(textEditingValue()->selection->extent());
            }
        });
        hideToolbar();
    }
}

void EditableTextStateCls::selectAll(SelectionChangedCause cause) {
    if (widget()->readOnly && widget()->obscureText) {
        return;
    }
    userUpdateTextEditingValue(textEditingValue()->copyWith(make<TextSelectionCls>(0, textEditingValue()->text->length())), cause);
    if (cause == SelectionChangedCauseCls::toolbar) {
        bringIntoView(textEditingValue()->selection->extent());
    }
}

void EditableTextStateCls::initState() {
    super->initState();
    _clipboardStatus?->addListener(_onChangedClipboardStatus);
    widget()->controller->addListener(_didChangeTextEditingValue);
    widget()->focusNode->addListener(_handleFocusChanged);
    _scrollController()->addListener(_updateSelectionOverlayForScroll);
    _cursorVisibilityNotifier->value() = widget()->showCursor;
}

void EditableTextStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    AutofillGroupState newAutofillGroup = AutofillGroupCls->of(context());
    if (currentAutofillScope() != newAutofillGroup) {
        _currentAutofillScope?->unregister(autofillId());
        _currentAutofillScope = newAutofillGroup;
        _currentAutofillScope?->register(_effectiveAutofillClient());
    }
    if (!_didAutoFocus && widget()->autofocus) {
        _didAutoFocus = true;
        SchedulerBindingCls::instance->addPostFrameCallback([=] () {
            if (mounted() && renderEditable()->hasSize()) {
                FocusScopeCls->of(context())->autofocus(widget()->focusNode);
            }
        });
    }
    bool newTickerEnabled = TickerModeCls->of(context());
    if (_tickersEnabled != newTickerEnabled) {
        _tickersEnabled = newTickerEnabled;
        if (_tickersEnabled && _cursorActive) {
            _startCursorBlink();
        } else {
            if (!_tickersEnabled && _cursorTimer != nullptr) {
            _cursorTimer!->cancel();
            _cursorTimer = nullptr;
        }
;
        }    }
    if (defaultTargetPlatform != TargetPlatformCls::iOS && defaultTargetPlatform != TargetPlatformCls::android) {
        return;
    }
    Orientation orientation = MediaQueryCls->of(context())->orientation;
    if (_lastOrientation == nullptr) {
        _lastOrientation = orientation;
        return;
    }
    if (orientation != _lastOrientation) {
        _lastOrientation = orientation;
        if (defaultTargetPlatform == TargetPlatformCls::iOS) {
            hideToolbar(false);
        }
        if (defaultTargetPlatform == TargetPlatformCls::android) {
            hideToolbar();
        }
    }
}

void EditableTextStateCls::didUpdateWidget(EditableText oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget()->controller != oldWidget->controller) {
        oldWidget->controller->removeListener(_didChangeTextEditingValue);
        widget()->controller->addListener(_didChangeTextEditingValue);
        _updateRemoteEditingValueIfNeeded();
    }
    if (widget()->controller->selection != oldWidget->controller->selection()) {
        _selectionOverlay?->update(_value());
    }
    _selectionOverlay?->handlesVisible() = widget()->showSelectionHandles;
    if (widget()->autofillClient != oldWidget->autofillClient) {
        _currentAutofillScope?->unregister(oldWidget->autofillClient?->autofillId() | autofillId());
        _currentAutofillScope?->register(_effectiveAutofillClient());
    }
    if (widget()->focusNode != oldWidget->focusNode) {
        oldWidget->focusNode->removeListener(_handleFocusChanged);
        widget()->focusNode->addListener(_handleFocusChanged);
        updateKeepAlive();
    }
    if (widget()->scrollController != oldWidget->scrollController) {
        (oldWidget->scrollController | _internalScrollController)?->removeListener(_updateSelectionOverlayForScroll);
        _scrollController()->addListener(_updateSelectionOverlayForScroll);
    }
    if (!_shouldCreateInputConnection()) {
        _closeInputConnectionIfNeeded();
    } else {
        if (oldWidget->readOnly && _hasFocus()) {
        _openInputConnection();
    }
;
    }    if (kIsWeb && _hasInputConnection()) {
        if (oldWidget->readOnly != widget()->readOnly) {
            _textInputConnection!->updateConfig(_effectiveAutofillClient()->textInputConfiguration());
        }
    }
    if (widget()->style != oldWidget->style) {
        TextStyle style = widget()->style;
        if (_hasInputConnection()) {
            _textInputConnection!->setStyle(style->fontFamily, style->fontSize, style->fontWeight, _textDirection(), widget()->textAlign);
        }
    }
    if (widget()->selectionEnabled && pasteEnabled() && (widget()->selectionControls?->canPaste(this) | false)) {
        _clipboardStatus?->update();
    }
}

void EditableTextStateCls::dispose() {
    _internalScrollController?->dispose();
    _currentAutofillScope?->unregister(autofillId());
    widget()->controller->removeListener(_didChangeTextEditingValue);
    _floatingCursorResetController?->dispose();
    _floatingCursorResetController = nullptr;
    _closeInputConnectionIfNeeded();
    assert(!_hasInputConnection());
    _cursorTimer?->cancel();
    _cursorTimer = nullptr;
    _backingCursorBlinkOpacityController?->dispose();
    _backingCursorBlinkOpacityController = nullptr;
    _selectionOverlay?->dispose();
    _selectionOverlay = nullptr;
    widget()->focusNode->removeListener(_handleFocusChanged);
    WidgetsBindingCls::instance->removeObserver(this);
    _clipboardStatus?->removeListener(_onChangedClipboardStatus);
    _clipboardStatus?->dispose();
    _cursorVisibilityNotifier->dispose();
    super->dispose();
    assert(_batchEditDepth <= 0, __s("unfinished batch edits: $_batchEditDepth"));
}

TextEditingValue EditableTextStateCls::currentTextEditingValue() {
    return _value();
}

void EditableTextStateCls::updateEditingValue(TextEditingValue value) {
    if (!_shouldCreateInputConnection()) {
        return;
    }
    if (widget()->readOnly) {
        value = _value()->copyWith(value->selection);
    }
    _lastKnownRemoteTextEditingValue = value;
    if (value == _value()) {
        return;
    }
    if (value->text == _value()->text && value->composing == _value()->composing) {
        _handleSelectionChanged(value->selection, (_textInputConnection?->scribbleInProgress() | false)? SelectionChangedCauseCls::scribble : SelectionChangedCauseCls::keyboard);
    } else {
        hideToolbar();
        _currentPromptRectRange = nullptr;
        bool revealObscuredInput = _hasInputConnection() && widget()->obscureText && WidgetsBindingCls::instance->platformDispatcher->brieflyShowPassword && value->text->length() == _value()->text->length() + 1;
        _obscureShowCharTicksPending = revealObscuredInput? _kObscureShowLatestCharCursorTicks : 0;
        _obscureLatestCharIndex = revealObscuredInput? _value()->selection->baseOffset : nullptr;
        _formatAndSetValue(value, SelectionChangedCauseCls::keyboard);
    }
    _scheduleShowCaretOnScreen(true);
    if (_hasInputConnection()) {
        _stopCursorBlink(false);
        _startCursorBlink();
    }
}

void EditableTextStateCls::performAction(TextInputAction action) {
    ;
}

void EditableTextStateCls::performPrivateCommand(String action, Map<String, dynamic> data) {
    widget()->onAppPrivateCommand!(action, data);
}

void EditableTextStateCls::updateFloatingCursor(RawFloatingCursorPoint point) {
    auto _c1 = make<AnimationControllerCls>(this);_c1.addListener(_onFloatingCursorResetTick);_floatingCursorResetController |= _c1;
    ;
}

void EditableTextStateCls::beginBatchEdit() {
    _batchEditDepth += 1;
}

void EditableTextStateCls::endBatchEdit() {
    _batchEditDepth -= 1;
    assert(_batchEditDepth >= 0, __s("Unbalanced call to endBatchEdit: beginBatchEdit must be called first."));
    _updateRemoteEditingValueIfNeeded();
}

void EditableTextStateCls::connectionClosed() {
    if (_hasInputConnection()) {
        _textInputConnection!->connectionClosedReceived();
        _textInputConnection = nullptr;
        _lastKnownRemoteTextEditingValue = nullptr;
        _finalizeEditing(TextInputActionCls::done, true);
    }
}

void EditableTextStateCls::requestKeyboard() {
    if (_hasFocus()) {
        _openInputConnection();
    } else {
        widget()->focusNode->requestFocus();
    }
}

void EditableTextStateCls::didChangeMetrics() {
    if (_lastBottomViewInset != WidgetsBindingCls::instance->window->viewInsets->bottom) {
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration _) {
            _selectionOverlay?->updateForScroll();
        });
        if ( < WidgetsBindingCls::instance->window->viewInsets->bottom) {
            _scheduleShowCaretOnScreen(false);
        }
    }
    _lastBottomViewInset = WidgetsBindingCls::instance->window->viewInsets->bottom;
}

bool EditableTextStateCls::cursorCurrentlyVisible() {
    return _cursorBlinkOpacityController()->value() > 0;
}

Duration EditableTextStateCls::cursorBlinkInterval() {
    return _kCursorBlinkHalfPeriod;
}

TextSelectionOverlay EditableTextStateCls::selectionOverlay() {
    return _selectionOverlay;
}

RenderEditable EditableTextStateCls::renderEditable() {
    return as<RenderEditable>(_editableKey->currentContext()!->findRenderObject()!);
}

TextEditingValue EditableTextStateCls::textEditingValue() {
    return _value();
}

void EditableTextStateCls::userUpdateTextEditingValue(TextEditingValue value, SelectionChangedCause cause) {
    bool shouldShowCaret = widget()->readOnly? _value()->selection != value->selection : _value() != value;
    if (shouldShowCaret) {
        _scheduleShowCaretOnScreen(true);
    }
    if (value == textEditingValue()) {
        if (!widget()->focusNode->hasFocus) {
            widget()->focusNode->requestFocus();
            _createSelectionOverlay();
        }
        return;
    }
    _formatAndSetValue(value, cause, true);
}

void EditableTextStateCls::bringIntoView(TextPosition position) {
    Rect localRect = renderEditable()->getLocalRectForCaret(position);
    RevealedOffset targetOffset = _getOffsetToRevealCaret(localRect);
    _scrollController()->jumpTo(targetOffset->offset);
    renderEditable()->showOnScreen(targetOffset->rect);
}

bool EditableTextStateCls::showToolbar() {
    if (kIsWeb) {
        return false;
    }
    if (_selectionOverlay == nullptr || _selectionOverlay!->toolbarIsVisible()) {
        return false;
    }
    _clipboardStatus?->update();
    _selectionOverlay!->showToolbar();
    return true;
}

void EditableTextStateCls::hideToolbar(bool hideHandles) {
    if (hideHandles) {
        _selectionOverlay?->hide();
    } else {
        if (_selectionOverlay?->toolbarIsVisible() | false) {
        _selectionOverlay?->hideToolbar();
    }
;
    }}

void EditableTextStateCls::toggleToolbar() {
    assert(_selectionOverlay != nullptr);
    if (_selectionOverlay!->toolbarIsVisible()) {
        hideToolbar();
    } else {
        showToolbar();
    }
}

void EditableTextStateCls::insertTextPlaceholder(Size size) {
    if (!widget()->scribbleEnabled) {
        return;
    }
    if (!widget()->controller->selection->isValid) {
        return;
    }
    setState([=] () {
        _placeholderLocation = _value()->text->length() - widget()->controller->selection->end;
    });
}

void EditableTextStateCls::removeTextPlaceholder() {
    if (!widget()->scribbleEnabled) {
        return;
    }
    setState([=] () {
        _placeholderLocation = -1;
    });
}

String EditableTextStateCls::autofillId() {
    return __s("EditableText-$hashCode");
}

TextInputConfiguration EditableTextStateCls::textInputConfiguration() {
    List<String> autofillHints = widget()->autofillHints?->toList(false);
    AutofillConfiguration autofillConfiguration = autofillHints != nullptr? make<AutofillConfigurationCls>(autofillId(), autofillHints, currentTextEditingValue()) : AutofillConfigurationCls::disabled;
    return make<TextInputConfigurationCls>(widget()->keyboardType, widget()->readOnly, widget()->obscureText, widget()->autocorrect, widget()->smartDashesType, widget()->smartQuotesType, widget()->enableSuggestions, widget()->_userSelectionEnabled, widget()->textInputAction | (widget()->keyboardType == TextInputTypeCls::multiline? TextInputActionCls::newline : TextInputActionCls::done), widget()->textCapitalization, widget()->keyboardAppearance, autofillConfiguration, widget()->enableIMEPersonalizedLearning);
}

void EditableTextStateCls::autofill(TextEditingValue value) {
    return updateEditingValue(value);
}

void EditableTextStateCls::showAutocorrectionPromptRect(int start, int end) {
    setState([=] () {
        _currentPromptRectRange = make<TextRangeCls>(start, end);
    });
}

Widget EditableTextStateCls::build(BuildContext context) {
    assert(debugCheckHasMediaQuery(context));
    super->build(context);
    TextSelectionControls controls = widget()->selectionControls;
    return make<MouseRegionCls>(widget()->mouseCursor | SystemMouseCursorsCls::text, make<ActionsCls>(_actions, make<_TextEditingHistoryCls>(widget()->controller, [=] (TextEditingValue value) {
        userUpdateTextEditingValue(value, SelectionChangedCauseCls::keyboard);
    }, make<FocusCls>(widget()->focusNode, false, __s("EditableText"), make<ScrollableCls>(true, _isMultiline()? AxisDirectionCls::down : AxisDirectionCls::right, _scrollController(), widget()->scrollPhysics, widget()->dragStartBehavior, widget()->restorationId, widget()->scrollBehavior | ScrollConfigurationCls->of(context)->copyWith(_isMultiline(), false), [=] (BuildContext context,ViewportOffset offset) {
        return make<CompositedTransformTargetCls>(_toolbarLayerLink, make<SemanticsCls>(_semanticsOnCopy(controls), _semanticsOnCut(controls), _semanticsOnPaste(controls), make<_ScribbleFocusableCls>(widget()->focusNode, _editableKey, widget()->scribbleEnabled, [=] () {
            _openInputConnection();
            _updateSelectionRects(true);
        }, make<_EditableCls>(_editableKey, _startHandleLayerLink, _endHandleLayerLink, buildTextSpan(), _value(), _cursorColor(), widget()->backgroundCursorColor, EditableTextCls::debugDeterministicCursor? <bool>make<ValueNotifierCls>(widget()->showCursor) : _cursorVisibilityNotifier, widget()->forceLine, widget()->readOnly, _hasFocus(), widget()->maxLines, widget()->minLines, widget()->expands, widget()->strutStyle, widget()->selectionColor, widget()->textScaleFactor | MediaQueryCls->textScaleFactorOf(context), widget()->textAlign, _textDirection(), widget()->locale, widget()->textHeightBehavior | DefaultTextHeightBehaviorCls->of(context), widget()->textWidthBasis, widget()->obscuringCharacter, widget()->obscureText, offset, _handleCaretChanged, widget()->rendererIgnoresPointer, widget()->cursorWidth, widget()->cursorHeight, widget()->cursorRadius, widget()->cursorOffset | OffsetCls::zero, widget()->selectionHeightStyle, widget()->selectionWidthStyle, widget()->paintCursorAboveText, widget()->_userSelectionEnabled, this, _devicePixelRatio(), _currentPromptRectRange, widget()->autocorrectionTextRectColor, widget()->clipBehavior))));
    })))));
}

TextSpan EditableTextStateCls::buildTextSpan() {
    if (widget()->obscureText) {
        String text = _value()->text;
        text = widget()->obscuringCharacter * text->length();
        Set<TargetPlatform> mobilePlatforms = makeSet(ArrayItem, ArrayItem);
        bool breiflyShowPassword = WidgetsBindingCls::instance->platformDispatcher->brieflyShowPassword && mobilePlatforms->contains(defaultTargetPlatform);
        if (breiflyShowPassword) {
            int o = _obscureShowCharTicksPending > 0? _obscureLatestCharIndex : nullptr;
            if (o != nullptr && o >= 0 &&  < text->length()) {
                text = text->replaceRange(o, o + 1, _value()->text->substring(o, o + 1));
            }
        }
        return make<TextSpanCls>(widget()->style, text);
    }
    if (_placeholderLocation >= 0 && _placeholderLocation <= _value()->text->length()) {
        List<_ScribblePlaceholder> placeholders = makeList();
        int placeholderLocation = _value()->text->length() - _placeholderLocation;
        if (_isMultiline()) {
            placeholders->add(make<_ScribblePlaceholderCls>(make<SizedBoxCls>(), SizeCls::zero));
            placeholders->add(make<_ScribblePlaceholderCls>(make<SizedBoxCls>(), make<SizeCls>(renderEditable()->size()->width(), 0.0)));
        } else {
            placeholders->add(make<_ScribblePlaceholderCls>(make<SizedBoxCls>(), make<SizeCls>(100.0, 0.0)));
        }
            List<InlineSpan> list1 = make<ListCls<>>();    list1.add(ArrayItem);    for (auto _x1 : placeholders) {    {        list1.add(_x1);    }list1.add(ArrayItem);return make<TextSpanCls>(widget()->style, list1);
    }
    return widget()->controller->buildTextSpan(context(), widget()->style, !widget()->readOnly && _hasFocus());
}

AnimationController EditableTextStateCls::_cursorBlinkOpacityController() {
    auto _c1 = make<AnimationControllerCls>(this);_c1.addListener(_onCursorColorTick);return _backingCursorBlinkOpacityController ??= _c1;
}

ScrollController EditableTextStateCls::_scrollController() {
    return widget()->scrollController | (_internalScrollController ??= make<ScrollControllerCls>());
}

AutofillClient EditableTextStateCls::_effectiveAutofillClient() {
    return widget()->autofillClient | this;
}

bool EditableTextStateCls::_shouldCreateInputConnection() {
    return kIsWeb || !widget()->readOnly;
}

Color EditableTextStateCls::_cursorColor() {
    return widget()->cursorColor->withOpacity(_cursorBlinkOpacityController()->value());
}

void EditableTextStateCls::_onChangedClipboardStatus() {
    setState([=] () {
    });
}

TextEditingValue EditableTextStateCls::_textEditingValueforTextLayoutMetrics() {
    Widget editableWidget = _editableKey->currentContext()?->widget();
    if (!is<_Editable>(editableWidget)) {
        throw make<StateErrorCls>(__s("_Editable must be mounted."));
    }
    return editableWidget->value;
}

Offset EditableTextStateCls::_floatingCursorOffset() {
    return make<OffsetCls>(0, renderEditable()->preferredLineHeight() / 2);
}

void EditableTextStateCls::_onFloatingCursorResetTick() {
    Offset finalPosition = renderEditable()->getLocalRectForCaret(_lastTextPosition!)->centerLeft() - _floatingCursorOffset();
    if (_floatingCursorResetController!->isCompleted()) {
        renderEditable()->setFloatingCursor(FloatingCursorDragStateCls::EndCls, finalPosition, _lastTextPosition!);
        if (_lastTextPosition!->offset != renderEditable()->selection()!->baseOffset) {
            _handleSelectionChanged(TextSelectionCls->collapsed(_lastTextPosition!->offset), SelectionChangedCauseCls::forcePress);
        }
        _startCaretRect = nullptr;
        _lastTextPosition = nullptr;
        _pointOffsetOrigin = nullptr;
        _lastBoundedOffset = nullptr;
    } else {
        double lerpValue = _floatingCursorResetController!->value();
        double lerpX = ui->lerpDouble(_lastBoundedOffset!->dx(), finalPosition->dx(), lerpValue)!;
        double lerpY = ui->lerpDouble(_lastBoundedOffset!->dy(), finalPosition->dy(), lerpValue)!;
        renderEditable()->setFloatingCursor(FloatingCursorDragStateCls::UpdateCls, make<OffsetCls>(lerpX, lerpY), _lastTextPosition!, lerpValue);
    }
}

void EditableTextStateCls::_finalizeEditing(TextInputAction action, bool shouldUnfocus) {
    if (widget()->onEditingComplete != nullptr) {
        try {
            widget()->onEditingComplete!();
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("widgets"), make<ErrorDescriptionCls>(__s("while calling onEditingComplete for $action"))));
        };
    } else {
        widget()->controller->clearComposing();
        if (shouldUnfocus) {
            ;
        }
    }
    ValueChanged<String> onSubmitted = widget()->onSubmitted;
    if (onSubmitted == nullptr) {
        return;
    }
    try {
        onSubmitted(_value()->text);
    } catch (Unknown exception) {
        FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("widgets"), make<ErrorDescriptionCls>(__s("while calling onSubmitted for $action"))));
    };
    if (shouldUnfocus) {
        _scheduleRestartConnection();
    }
}

void EditableTextStateCls::_updateRemoteEditingValueIfNeeded() {
    if (_batchEditDepth > 0 || !_hasInputConnection()) {
        return;
    }
    TextEditingValue localValue = _value();
    if (localValue == _lastKnownRemoteTextEditingValue) {
        return;
    }
    _textInputConnection!->setEditingState(localValue);
    _lastKnownRemoteTextEditingValue = localValue;
}

TextEditingValue EditableTextStateCls::_value() {
    return widget()->controller->value;
}

void EditableTextStateCls::_value(TextEditingValue value) {
    widget()->controller->value = value;
}

bool EditableTextStateCls::_hasFocus() {
    return widget()->focusNode->hasFocus;
}

bool EditableTextStateCls::_isMultiline() {
    return widget()->maxLines != 1;
}

RevealedOffset EditableTextStateCls::_getOffsetToRevealCaret(Rect rect) {
    if (!_scrollController()->position()->allowImplicitScrolling()) {
        return make<RevealedOffsetCls>(_scrollController()->offset(), rect);
    }
    Size editableSize = renderEditable()->size();
    double additionalOffset;
    Offset unitOffset;
    if (!_isMultiline()) {
        additionalOffset = rect->width() >= editableSize->width()? editableSize->width() / 2 - rect->center()->dx() : clampDouble(0.0, rect->right - editableSize->width(), rect->left);
        unitOffset = make<OffsetCls>(1, 0);
    } else {
        Rect expandedRect = RectCls->fromCenter(rect->center(), rect->width(), math->max(rect->height(), renderEditable()->preferredLineHeight()));
        additionalOffset = expandedRect->height() >= editableSize->height()? editableSize->height() / 2 - expandedRect->center()->dy() : clampDouble(0.0, expandedRect->bottom - editableSize->height(), expandedRect->top);
        unitOffset = make<OffsetCls>(0, 1);
    }
    double targetOffset = clampDouble(additionalOffset + _scrollController()->offset(), _scrollController()->position()->minScrollExtent(), _scrollController()->position()->maxScrollExtent());
    double offsetDelta = _scrollController()->offset() - targetOffset;
    return make<RevealedOffsetCls>(rect->shift(unitOffset * offsetDelta), targetOffset);
}

bool EditableTextStateCls::_hasInputConnection() {
    return _textInputConnection?->attached() | false;
}

bool EditableTextStateCls::_needsAutofill() {
    return _effectiveAutofillClient()->textInputConfiguration()->autofillConfiguration->enabled;
}

void EditableTextStateCls::_openInputConnection() {
    if (!_shouldCreateInputConnection()) {
        return;
    }
    if (!_hasInputConnection()) {
        TextEditingValue localValue = _value();
        _textInputConnection = _needsAutofill() && currentAutofillScope() != nullptr? currentAutofillScope()!->attach(this, _effectiveAutofillClient()->textInputConfiguration()) : TextInputCls->attach(this, _effectiveAutofillClient()->textInputConfiguration());
        _updateSizeAndTransform();
        _updateComposingRectIfNeeded();
        _updateCaretRectIfNeeded();
        TextStyle style = widget()->style;
            auto _c1 = _textInputConnection!;    _c1.auto _c2 = setStyle(style->fontFamily, style->fontSize, style->fontWeight, _textDirection(), widget()->textAlign);    _c2.auto _c3 = setEditingState(localValue);    _c3.show();    _c3;    _c2;_c1;
        if (_needsAutofill()) {
            _textInputConnection!->requestAutofill();
        }
        _lastKnownRemoteTextEditingValue = localValue;
    } else {
        _textInputConnection!->show();
    }
}

void EditableTextStateCls::_closeInputConnectionIfNeeded() {
    if (_hasInputConnection()) {
        _textInputConnection!->close();
        _textInputConnection = nullptr;
        _lastKnownRemoteTextEditingValue = nullptr;
    }
}

void EditableTextStateCls::_openOrCloseInputConnectionIfNeeded() {
    if (_hasFocus() && widget()->focusNode->consumeKeyboardToken()) {
        _openInputConnection();
    } else {
        if (!_hasFocus()) {
        _closeInputConnectionIfNeeded();
        widget()->controller->clearComposing();
    }
;
    }}

void EditableTextStateCls::_scheduleRestartConnection() {
    if (_restartConnectionScheduled) {
        return;
    }
    _restartConnectionScheduled = true;
    scheduleMicrotask(_restartConnectionIfNeeded);
}

void EditableTextStateCls::_restartConnectionIfNeeded() {
    _restartConnectionScheduled = false;
    if (!_hasInputConnection() || !_shouldCreateInputConnection()) {
        return;
    }
    _textInputConnection!->close();
    _textInputConnection = nullptr;
    _lastKnownRemoteTextEditingValue = nullptr;
    AutofillScope currentAutofillScope = _needsAutofill()? this->currentAutofillScope() : nullptr;
    TextInputConnection newConnection = currentAutofillScope?->attach(this, textInputConfiguration()) | TextInputCls->attach(this, _effectiveAutofillClient()->textInputConfiguration());
    _textInputConnection = newConnection;
    TextStyle style = widget()->style;
    auto _c1 = newConnection;_c1.auto _c2 = show();_c2.auto _c3 = setStyle(style->fontFamily, style->fontSize, style->fontWeight, _textDirection(), widget()->textAlign);_c3.setEditingState(_value());_c3;_c2;_c1;
    _lastKnownRemoteTextEditingValue = _value();
}

void EditableTextStateCls::_updateOrDisposeSelectionOverlayIfNeeded() {
    if (_selectionOverlay != nullptr) {
        if (_hasFocus()) {
            _selectionOverlay!->update(_value());
        } else {
            _selectionOverlay!->dispose();
            _selectionOverlay = nullptr;
        }
    }
}

void EditableTextStateCls::_updateSelectionOverlayForScroll() {
    _selectionOverlay?->updateForScroll();
}

void EditableTextStateCls::_createSelectionOverlay() {
    _selectionOverlay = make<TextSelectionOverlayCls>(_clipboardStatus, context(), _value(), widget(), _toolbarLayerLink, _startHandleLayerLink, _endHandleLayerLink, renderEditable(), widget()->selectionControls, this, widget()->dragStartBehavior, widget()->onSelectionHandleTapped);
}

void EditableTextStateCls::_handleSelectionChanged(TextSelection selection, SelectionChangedCause cause) {
    if (!widget()->controller->isSelectionWithinTextBounds(selection)) {
        return;
    }
    widget()->controller->selection = selection;
    ;
    if (widget()->selectionControls == nullptr) {
        _selectionOverlay?->dispose();
        _selectionOverlay = nullptr;
    } else {
        if (_selectionOverlay == nullptr) {
            _createSelectionOverlay();
        } else {
            _selectionOverlay!->update(_value());
        }
        _selectionOverlay!->handlesVisible() = widget()->showSelectionHandles;
        _selectionOverlay!->showHandles();
    }
    try {
        widget()->onSelectionChanged?->call(selection, cause);
    } catch (Unknown exception) {
        FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("widgets"), make<ErrorDescriptionCls>(__s("while calling onSelectionChanged for $cause"))));
    };
    if (_cursorTimer != nullptr) {
        _stopCursorBlink(false);
        _startCursorBlink();
    }
}

void EditableTextStateCls::_handleCaretChanged(Rect caretRect) {
    _currentCaretRect = caretRect;
}

void EditableTextStateCls::_scheduleShowCaretOnScreen(bool withAnimation) {
    if (_showCaretOnScreenScheduled) {
        return;
    }
    _showCaretOnScreenScheduled = true;
    SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration _) {
        _showCaretOnScreenScheduled = false;
        if (_currentCaretRect == nullptr || !_scrollController()->hasClients()) {
            return;
        }
        double lineHeight = renderEditable()->preferredLineHeight();
        double bottomSpacing = widget()->scrollPadding->bottom;
        if (_selectionOverlay?->selectionControls != nullptr) {
            double handleHeight = _selectionOverlay!->selectionControls!->getHandleSize(lineHeight)->height();
            double interactiveHandleHeight = math->max(handleHeight, kMinInteractiveDimension);
            Offset anchor = _selectionOverlay!->selectionControls!->getHandleAnchor(TextSelectionHandleTypeCls::collapsed, lineHeight);
            double handleCenter = handleHeight / 2 - anchor->dy();
            bottomSpacing = math->max(handleCenter + interactiveHandleHeight / 2, bottomSpacing);
        }
        EdgeInsets caretPadding = widget()->scrollPadding->copyWith(bottomSpacing);
        RevealedOffset targetOffset = _getOffsetToRevealCaret(_currentCaretRect!);
        if (withAnimation) {
            _scrollController()->animateTo(targetOffset->offset, _caretAnimationDuration, _caretAnimationCurve);
            renderEditable()->showOnScreen(caretPadding->inflateRect(targetOffset->rect), _caretAnimationDuration, _caretAnimationCurve);
        } else {
            _scrollController()->jumpTo(targetOffset->offset);
            renderEditable()->showOnScreen(caretPadding->inflateRect(targetOffset->rect));
        }
    });
}

void EditableTextStateCls::_formatAndSetValue(TextEditingValue value, SelectionChangedCause cause, bool userInteraction) {
    bool textChanged = _value()->text != value->text || (!_value()->composing->isCollapsed() && value->composing->isCollapsed());
    bool selectionChanged = _value()->selection != value->selection;
    if (textChanged) {
        try {
            value = widget()->inputFormatters?-><TextEditingValue>fold(value, [=] (TextEditingValue newValue,TextInputFormatter formatter) {
                formatter->formatEditUpdate(_value(), newValue);
            }) | value;
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("widgets"), make<ErrorDescriptionCls>(__s("while applying input formatters"))));
        };
    }
    beginBatchEdit();
    _value() = value;
    if (selectionChanged || (userInteraction && (cause == SelectionChangedCauseCls::longPress || cause == SelectionChangedCauseCls::keyboard))) {
        _handleSelectionChanged(_value()->selection, cause);
    }
    if (textChanged) {
        try {
            widget()->onChanged?->call(_value()->text);
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("widgets"), make<ErrorDescriptionCls>(__s("while calling onChanged"))));
        };
    }
    endBatchEdit();
}

void EditableTextStateCls::_onCursorColorTick() {
    renderEditable()->cursorColor() = widget()->cursorColor->withOpacity(_cursorBlinkOpacityController()->value());
    _cursorVisibilityNotifier->value() = widget()->showCursor && _cursorBlinkOpacityController()->value() > 0;
}

void EditableTextStateCls::_startCursorBlink() {
    assert(!(_cursorTimer?->isActive() | false) || !(_backingCursorBlinkOpacityController?->isAnimating() | false));
    _cursorActive = true;
    if (!_tickersEnabled) {
        return;
    }
    _cursorTimer?->cancel();
    _cursorBlinkOpacityController()->value() = 1.0;
    if (EditableTextCls::debugDeterministicCursor) {
        return;
    }
    if (widget()->cursorOpacityAnimates) {
        _cursorBlinkOpacityController()->animateWith(_iosBlinkCursorSimulation)->whenComplete(_onCursorTick);
    } else {
        _cursorTimer = TimerCls->periodic(_kCursorBlinkHalfPeriod, [=] (Timer timer) {
            _onCursorTick();
        });
    }
}

void EditableTextStateCls::_onCursorTick() {
    if (_obscureShowCharTicksPending > 0) {
        _obscureShowCharTicksPending = WidgetsBindingCls::instance->platformDispatcher->brieflyShowPassword? _obscureShowCharTicksPending - 1 : 0;
        if (_obscureShowCharTicksPending == 0) {
            setState([=] () {
            });
        }
    }
    if (widget()->cursorOpacityAnimates) {
        _cursorTimer?->cancel();
        _cursorTimer = make<TimerCls>(DurationCls::zero, [=] () {
            _cursorBlinkOpacityController()->animateWith(_iosBlinkCursorSimulation)->whenComplete(_onCursorTick);
        });
    } else {
        if (!(_cursorTimer?->isActive() | false) && _tickersEnabled) {
            _cursorTimer = TimerCls->periodic(_kCursorBlinkHalfPeriod, [=] (Timer timer) {
                _onCursorTick();
            });
        }
        _cursorBlinkOpacityController()->value() = _cursorBlinkOpacityController()->value() == 0? 1 : 0;
    }
}

void EditableTextStateCls::_stopCursorBlink(bool resetCharTicks) {
    _cursorActive = false;
    _cursorBlinkOpacityController()->value() = 0.0;
    _cursorTimer?->cancel();
    _cursorTimer = nullptr;
    if (resetCharTicks) {
        _obscureShowCharTicksPending = 0;
    }
}

void EditableTextStateCls::_startOrStopCursorTimerIfNeeded() {
    if (_cursorTimer == nullptr && _hasFocus() && _value()->selection->isCollapsed()) {
        _startCursorBlink();
    } else {
        if (_cursorActive && (!_hasFocus() || !_value()->selection->isCollapsed())) {
        _stopCursorBlink();
    }
;
    }}

void EditableTextStateCls::_didChangeTextEditingValue() {
    _updateRemoteEditingValueIfNeeded();
    _startOrStopCursorTimerIfNeeded();
    _updateOrDisposeSelectionOverlayIfNeeded();
    setState([=] () {
    });
    _adjacentLineAction->stopCurrentVerticalRunIfSelectionChanges();
}

void EditableTextStateCls::_handleFocusChanged() {
    _openOrCloseInputConnectionIfNeeded();
    _startOrStopCursorTimerIfNeeded();
    _updateOrDisposeSelectionOverlayIfNeeded();
    if (_hasFocus()) {
        WidgetsBindingCls::instance->addObserver(this);
        _lastBottomViewInset = WidgetsBindingCls::instance->window->viewInsets->bottom;
        if (!widget()->readOnly) {
            _scheduleShowCaretOnScreen(true);
        }
        if (!_value()->selection->isValid()) {
            _handleSelectionChanged(TextSelectionCls->collapsed(_value()->text->length()), nullptr);
        }
        _cachedText = __s("");
        _cachedFirstRect = nullptr;
        _cachedSize = SizeCls::zero;
        _cachedPlaceholder = -1;
    } else {
        WidgetsBindingCls::instance->removeObserver(this);
        setState([=] () {
            _currentPromptRectRange = nullptr;
        });
    }
    updateKeepAlive();
}

void EditableTextStateCls::_updateSelectionRects(bool force) {
    if (!widget()->scribbleEnabled) {
        return;
    }
    if (defaultTargetPlatform != TargetPlatformCls::iOS) {
        return;
    }
    if (WidgetsBindingCls::instance->window->physicalSize->shortestSide < _kIPadWidth) {
        return;
    }
    String text = renderEditable()->text()?->toPlainText(false) | __s("");
    List<Rect> firstSelectionBoxes = renderEditable()->getBoxesForSelection(make<TextSelectionCls>(0, 1));
    Rect firstRect = firstSelectionBoxes->isNotEmpty()? firstSelectionBoxes->first : nullptr;
    ScrollDirection scrollDirection = _scrollController()->position()->userScrollDirection();
    Size size = renderEditable()->size();
    bool textChanged = text != _cachedText;
    bool textStyleChanged = _cachedTextStyle != widget()->style;
    bool firstRectChanged = _cachedFirstRect != firstRect;
    bool sizeChanged = _cachedSize != size;
    bool placeholderChanged = _cachedPlaceholder != _placeholderLocation;
    if (scrollDirection == ScrollDirectionCls::idle && (force || textChanged || textStyleChanged || firstRectChanged || sizeChanged || placeholderChanged)) {
        _cachedText = text;
        _cachedFirstRect = firstRect;
        _cachedTextStyle = widget()->style;
        _cachedSize = size;
        _cachedPlaceholder = _placeholderLocation;
        bool belowRenderEditableBottom = false;
        List<SelectionRect> rects = <SelectionRect>generate(_cachedText->characters->length, [=] (int i) {
    if (belowRenderEditableBottom) {
        return nullptr;
    }
    int offset = _cachedText->characters->getRange(0, i)->stringValue->length;
    List<Rect> boxes = renderEditable()->getBoxesForSelection(make<TextSelectionCls>(offset, offset + _cachedText->characters->characterAt(i)->stringValue->length));
    if (boxes->isEmpty()) {
        return nullptr;
    }
    SelectionRect selectionRect = make<SelectionRectCls>(boxes->first, offset);
    if (renderEditable()->paintBounds()->bottom < selectionRect->bounds->top) {
        belowRenderEditableBottom = true;
        return nullptr;
    }
    return selectionRect;
})->where([=] (SelectionRect selectionRect) {
    if (selectionRect == nullptr) {
        return false;
    }
    if (renderEditable()->paintBounds()->right < selectionRect->bounds->left || selectionRect->bounds->right < renderEditable()->paintBounds()->left) {
        return false;
    }
    if (renderEditable()->paintBounds()->bottom < selectionRect->bounds->top || selectionRect->bounds->bottom < renderEditable()->paintBounds()->top) {
        return false;
    }
    return true;
})-><SelectionRect>map([=] (SelectionRect selectionRect) {
    selectionRect!;
})->toList();
        _textInputConnection!->setSelectionRects(rects);
    }
}

void EditableTextStateCls::_updateSizeAndTransform() {
    if (_hasInputConnection()) {
        Size size = renderEditable()->size();
        Matrix4 transform = renderEditable()->getTransformTo(nullptr);
        _textInputConnection!->setEditableSizeAndTransform(size, transform);
        _updateSelectionRects();
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration _) {
            _updateSizeAndTransform();
        });
    } else {
        if (_placeholderLocation != -1) {
        removeTextPlaceholder();
    }
;
    }}

void EditableTextStateCls::_updateComposingRectIfNeeded() {
    TextRange composingRange = _value()->composing;
    if (_hasInputConnection()) {
        assert(mounted());
        Rect composingRect = renderEditable()->getRectForComposingRange(composingRange);
        if (composingRect == nullptr) {
            assert(!composingRange->isValid() || composingRange->isCollapsed());
            int offset = composingRange->isValid()? composingRange->start : 0;
            composingRect = renderEditable()->getLocalRectForCaret(make<TextPositionCls>(offset));
        }
        assert(composingRect != nullptr);
        _textInputConnection!->setComposingRect(composingRect);
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration _) {
            _updateComposingRectIfNeeded();
        });
    }
}

void EditableTextStateCls::_updateCaretRectIfNeeded() {
    if (_hasInputConnection()) {
        if (renderEditable()->selection() != nullptr && renderEditable()->selection()!->isValid() && renderEditable()->selection()!->isCollapsed()) {
            TextPosition currentTextPosition = make<TextPositionCls>(renderEditable()->selection()!->baseOffset);
            Rect caretRect = renderEditable()->getLocalRectForCaret(currentTextPosition);
            _textInputConnection!->setCaretRect(caretRect);
        }
        SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration _) {
            _updateCaretRectIfNeeded();
        });
    }
}

TextDirection EditableTextStateCls::_textDirection() {
    TextDirection result = widget()->textDirection | DirectionalityCls->of(context());
    assert(result != nullptr, __s("$runtimeType created without a textDirection and with no ambient Directionality."));
    return result;
}

double EditableTextStateCls::_devicePixelRatio() {
    return MediaQueryCls->of(context())->devicePixelRatio;
}

VoidCallback EditableTextStateCls::_semanticsOnCopy(TextSelectionControls controls) {
    return widget()->selectionEnabled && copyEnabled() && _hasFocus() && (controls?->canCopy(this) | false)? [=] () {
        controls!->handleCopy(this);
    } : nullptr;
}

VoidCallback EditableTextStateCls::_semanticsOnCut(TextSelectionControls controls) {
    return widget()->selectionEnabled && cutEnabled() && _hasFocus() && (controls?->canCut(this) | false)? [=] () {
        controls!->handleCut(this);
    } : nullptr;
}

VoidCallback EditableTextStateCls::_semanticsOnPaste(TextSelectionControls controls) {
    return widget()->selectionEnabled && pasteEnabled() && _hasFocus() && (controls?->canPaste(this) | false) && (_clipboardStatus == nullptr || _clipboardStatus!->value() == ClipboardStatusCls::pasteable)? [=] () {
        controls!->handlePaste(this);
    } : nullptr;
}

_TextBoundary EditableTextStateCls::_characterBoundary(DirectionalTextEditingIntent intent) {
    _TextBoundary atomicTextBoundary = widget()->obscureText? make<_CodeUnitBoundaryCls>(_value()) : make<_CharacterBoundaryCls>(_value());
    return make<_CollapsedSelectionBoundaryCls>(atomicTextBoundary, intent->forward);
}

_TextBoundary EditableTextStateCls::_nextWordBoundary(DirectionalTextEditingIntent intent) {
    _TextBoundary atomicTextBoundary;
    _TextBoundary boundary;
    if (widget()->obscureText) {
        atomicTextBoundary = make<_CodeUnitBoundaryCls>(_value());
        boundary = make<_DocumentBoundaryCls>(_value());
    } else {
        TextEditingValue textEditingValue = _textEditingValueforTextLayoutMetrics();
        atomicTextBoundary = make<_CharacterBoundaryCls>(textEditingValue);
        boundary = make<_ExpandedTextBoundaryCls>(make<_WhitespaceBoundaryCls>(textEditingValue), make<_WordBoundaryCls>(renderEditable(), textEditingValue));
    }
    _MixedBoundary mixedBoundary = intent->forward? make<_MixedBoundaryCls>(atomicTextBoundary, boundary) : make<_MixedBoundaryCls>(boundary, atomicTextBoundary);
    return make<_CollapsedSelectionBoundaryCls>(mixedBoundary, intent->forward);
}

_TextBoundary EditableTextStateCls::_linebreak(DirectionalTextEditingIntent intent) {
    _TextBoundary atomicTextBoundary;
    _TextBoundary boundary;
    if (widget()->obscureText) {
        atomicTextBoundary = make<_CodeUnitBoundaryCls>(_value());
        boundary = make<_DocumentBoundaryCls>(_value());
    } else {
        TextEditingValue textEditingValue = _textEditingValueforTextLayoutMetrics();
        atomicTextBoundary = make<_CharacterBoundaryCls>(textEditingValue);
        boundary = make<_LineBreakCls>(renderEditable(), textEditingValue);
    }
    return intent->forward? make<_MixedBoundaryCls>(make<_CollapsedSelectionBoundaryCls>(atomicTextBoundary, true), boundary) : make<_MixedBoundaryCls>(boundary, make<_CollapsedSelectionBoundaryCls>(atomicTextBoundary, false));
}

_TextBoundary EditableTextStateCls::_documentBoundary(DirectionalTextEditingIntent intent) {
    return make<_DocumentBoundaryCls>(_value());
}

template<typename T>
Action<T> EditableTextStateCls::_makeOverridable(Action<T> defaultAction) {
    return <T>overridable(context(), defaultAction);
}

void EditableTextStateCls::_transposeCharacters(TransposeCharactersIntent intent) {
    if (_value()->text->characters->length <= 1 || _value()->selection == nullptr || !_value()->selection->isCollapsed() || _value()->selection->baseOffset == 0) {
        return;
    }
    String text = _value()->text;
    TextSelection selection = _value()->selection;
    bool atEnd = selection->baseOffset == text->length();
    CharacterRange transposing = CharacterRangeCls->at(text, selection->baseOffset);
    if (atEnd) {
        transposing->moveBack(2);
    } else {
            auto _c1 = transposing;    _c1.auto _c2 = moveBack();    _c2.expandNext();    _c2;_c1;
    }
    assert(transposing->currentCharacters()->length() == 2);
    userUpdateTextEditingValue(make<TextEditingValueCls>(transposing->stringBefore() + transposing->currentCharacters()->last() + transposing->currentCharacters()->first() + transposing->stringAfter(), TextSelectionCls->collapsed(transposing->stringBeforeLength() + transposing->current()->length)), SelectionChangedCauseCls::keyboard);
}

void EditableTextStateCls::_replaceText(ReplaceTextIntent intent) {
    TextEditingValue oldValue = _value();
    TextEditingValue newValue = intent->currentTextEditingValue->replaced(intent->replacementRange, intent->replacementText);
    userUpdateTextEditingValue(newValue, intent->cause);
    if (newValue == oldValue) {
        _didChangeTextEditingValue();
    }
}

void EditableTextStateCls::_scrollToDocumentBoundary(ScrollToDocumentBoundaryIntent intent) {
    if (intent->forward) {
        bringIntoView(make<TextPositionCls>(_value()->text->length()));
    } else {
        bringIntoView(make<TextPositionCls>(0));
    }
}

void EditableTextStateCls::_updateSelection(UpdateSelectionIntent intent) {
    bringIntoView(intent->newSelection->extent());
    userUpdateTextEditingValue(intent->currentTextEditingValue->copyWith(intent->newSelection), intent->cause);
}

void EditableTextStateCls::_expandSelectionToDocumentBoundary(ExpandSelectionToDocumentBoundaryIntent intent) {
    _TextBoundary textBoundary = _documentBoundary(intent);
    _expandSelection(intent->forward, textBoundary, true);
}

void EditableTextStateCls::_expandSelectionToLinebreak(ExpandSelectionToLineBreakIntent intent) {
    _TextBoundary textBoundary = _linebreak(intent);
    _expandSelection(intent->forward, textBoundary);
}

void EditableTextStateCls::_expandSelection(bool forward, _TextBoundary textBoundary, bool extentAtIndex) {
    TextSelection textBoundarySelection = textBoundary->textEditingValue()->selection;
    if (!textBoundarySelection->isValid()) {
        return;
    }
    bool inOrder = textBoundarySelection->baseOffset <= textBoundarySelection->extentOffset;
    bool towardsExtent = forward == inOrder;
    TextPosition position = towardsExtent? textBoundarySelection->extent() : textBoundarySelection->base();
    TextPosition newExtent = forward? textBoundary->getTrailingTextBoundaryAt(position) : textBoundary->getLeadingTextBoundaryAt(position);
    TextSelection newSelection = textBoundarySelection->expandTo(newExtent, textBoundarySelection->isCollapsed() || extentAtIndex);
    userUpdateTextEditingValue(_value()->copyWith(newSelection), SelectionChangedCauseCls::keyboard);
    bringIntoView(newSelection->extent());
}

Object EditableTextStateCls::_hideToolbarIfVisible(DismissIntent intent) {
    if (_selectionOverlay?->toolbarIsVisible() | false) {
        hideToolbar(false);
        return nullptr;
    }
    return ActionsCls->invoke(context(), intent);
}

RenderEditable _EditableCls::createRenderObject(BuildContext context) {
    return make<RenderEditableCls>(inlineSpan, cursorColor, startHandleLayerLink, endHandleLayerLink, backgroundCursorColor, showCursor, forceLine, readOnly, hasFocus, maxLines, minLines, expands, strutStyle, selectionColor, textScaleFactor, textAlign, textDirection, locale | LocalizationsCls->maybeLocaleOf(context), value->selection, offset, onCaretChanged, rendererIgnoresPointer, obscuringCharacter, obscureText, textHeightBehavior, textWidthBasis, cursorWidth, cursorHeight, cursorRadius, cursorOffset, paintCursorAboveText, selectionHeightStyle, selectionWidthStyle, enableInteractiveSelection, textSelectionDelegate, devicePixelRatio, promptRectRange, promptRectColor, clipBehavior);
}

void _EditableCls::updateRenderObject(BuildContext context, RenderEditable renderObject) {
    auto _c1 = renderObject;_c1.text = auto _c2 = inlineSpan;_c2.cursorColor = auto _c3 = cursorColor;_c3.startHandleLayerLink = auto _c4 = startHandleLayerLink;_c4.endHandleLayerLink = auto _c5 = endHandleLayerLink;_c5.showCursor = auto _c6 = showCursor;_c6.forceLine = auto _c7 = forceLine;_c7.readOnly = auto _c8 = readOnly;_c8.hasFocus = auto _c9 = hasFocus;_c9.maxLines = auto _c10 = maxLines;_c10.minLines = auto _c11 = minLines;_c11.expands = auto _c12 = expands;_c12.strutStyle = auto _c13 = strutStyle;_c13.selectionColor = auto _c14 = selectionColor;_c14.textScaleFactor = auto _c15 = textScaleFactor;_c15.textAlign = auto _c16 = textAlign;_c16.textDirection = auto _c17 = textDirection;_c17.locale = auto _c18 = locale | LocalizationsCls->maybeLocaleOf(context);_c18.selection = auto _c19 = value->selection;_c19.offset = auto _c20 = offset;_c20.onCaretChanged = auto _c21 = onCaretChanged;_c21.ignorePointer = auto _c22 = rendererIgnoresPointer;_c22.textHeightBehavior = auto _c23 = textHeightBehavior;_c23.textWidthBasis = auto _c24 = textWidthBasis;_c24.obscuringCharacter = auto _c25 = obscuringCharacter;_c25.obscureText = auto _c26 = obscureText;_c26.cursorWidth = auto _c27 = cursorWidth;_c27.cursorHeight = auto _c28 = cursorHeight;_c28.cursorRadius = auto _c29 = cursorRadius;_c29.cursorOffset = auto _c30 = cursorOffset;_c30.selectionHeightStyle = auto _c31 = selectionHeightStyle;_c31.selectionWidthStyle = auto _c32 = selectionWidthStyle;_c32.enableInteractiveSelection = auto _c33 = enableInteractiveSelection;_c33.textSelectionDelegate = auto _c34 = textSelectionDelegate;_c34.devicePixelRatio = auto _c35 = devicePixelRatio;_c35.paintCursorAboveText = auto _c36 = paintCursorAboveText;_c36.promptRectColor = auto _c37 = promptRectColor;_c37.clipBehavior = auto _c38 = clipBehavior;_c38.setPromptRectRange(promptRectRange);_c38;_c37;_c36;_c35;_c34;_c33;_c32;_c31;_c30;_c29;_c28;_c27;_c26;_c25;_c24;_c23;_c22;_c21;_c20;_c19;_c18;_c17;_c16;_c15;_c14;_c13;_c12;_c11;_c10;_c9;_c8;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}

_EditableCls::_EditableCls(Color backgroundCursorColor, Clip clipBehavior, Color cursorColor, double cursorHeight, Offset cursorOffset, Radius cursorRadius, double cursorWidth, double devicePixelRatio, bool enableInteractiveSelection, LayerLink endHandleLayerLink, bool expands, bool forceLine, bool hasFocus, InlineSpan inlineSpan, Key key, Locale locale, int maxLines, int minLines, bool obscureText, String obscuringCharacter, ViewportOffset offset, CaretChangedHandler onCaretChanged, bool paintCursorAboveText, Color promptRectColor, TextRange promptRectRange, bool readOnly, bool rendererIgnoresPointer, Color selectionColor, BoxHeightStyle selectionHeightStyle, BoxWidthStyle selectionWidthStyle, ValueNotifier<bool> showCursor, LayerLink startHandleLayerLink, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextSelectionDelegate textSelectionDelegate, TextWidthBasis textWidthBasis, TextEditingValue value) : MultiChildRenderObjectWidget(_extractChildren(inlineSpan)) {
    {
        assert(textDirection != nullptr);
        assert(rendererIgnoresPointer != nullptr);
    }
}

List<Widget> _EditableCls::_extractChildren(InlineSpan span) {
    List<Widget> result = makeList();
    span->visitChildren([=] (InlineSpan span) {
        if (is<WidgetSpan>(span)) {
            result->add(as<WidgetSpanCls>(span)->child);
        }
        return true;
    });
    return result;
}

_ScribbleFocusableState _ScribbleFocusableCls::createState() {
    return make<_ScribbleFocusableStateCls>();
}

void _ScribbleFocusableStateCls::initState() {
    super->initState();
    if (widget()->enabled) {
        TextInputCls->registerScribbleElement(elementIdentifier(), this);
    }
}

void _ScribbleFocusableStateCls::didUpdateWidget(_ScribbleFocusable oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (!oldWidget->enabled && widget()->enabled) {
        TextInputCls->registerScribbleElement(elementIdentifier(), this);
    }
    if (oldWidget->enabled && !widget()->enabled) {
        TextInputCls->unregisterScribbleElement(elementIdentifier());
    }
}

void _ScribbleFocusableStateCls::dispose() {
    TextInputCls->unregisterScribbleElement(elementIdentifier());
    super->dispose();
}

RenderEditable _ScribbleFocusableStateCls::renderEditable() {
    return as<RenderEditable>(widget()->editableKey->currentContext?->findRenderObject());
}

String _ScribbleFocusableStateCls::elementIdentifier() {
    return _elementIdentifier;
}

void _ScribbleFocusableStateCls::onScribbleFocus(Offset offset) {
    widget()->focusNode->requestFocus();
    renderEditable()?->selectPositionAt(offset, SelectionChangedCauseCls::scribble);
    widget()->updateSelectionRects();
}

bool _ScribbleFocusableStateCls::isInScribbleRect(Rect rect) {
    Rect calculatedBounds = bounds();
    if (renderEditable()?->readOnly() | false) {
        return false;
    }
    if (calculatedBounds == RectCls::zero) {
        return false;
    }
    if (!calculatedBounds->overlaps(rect)) {
        return false;
    }
    Rect intersection = calculatedBounds->intersect(rect);
    HitTestResult result = make<HitTestResultCls>();
    WidgetsBindingCls::instance->hitTest(result, intersection->center());
    return result->path()->any([=] (HitTestEntry<any> entry) {
        entry->target == renderEditable();
    });
}

Rect _ScribbleFocusableStateCls::bounds() {
    RenderBox box = as<RenderBox>(context()->findRenderObject());
    if (box == nullptr || !mounted() || !box->attached()) {
        return RectCls::zero;
    }
    Matrix4 transform = box->getTransformTo(nullptr);
    return MatrixUtilsCls->transformRect(transform, RectCls->fromLTWH(0, 0, box->size()->width(), box->size()->height()));
}

Widget _ScribbleFocusableStateCls::build(BuildContext context) {
    return widget()->child;
}

_ScribbleFocusableStateCls::_ScribbleFocusableStateCls() {
    {
        _elementIdentifier = (_nextElementIdentifier++)->toString();
    }
}

void _ScribblePlaceholderCls::build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor) {
    assert(debugAssertIsValid());
    bool hasStyle = style != nullptr;
    if (hasStyle) {
        builder->pushStyle(style!->getTextStyle(textScaleFactor));
    }
    builder->addPlaceholder(size->width(), size->height(), alignment, textScaleFactor);
    if (hasStyle) {
        builder->pop();
    }
}

_ScribblePlaceholderCls::_ScribblePlaceholderCls(PlaceholderAlignment alignment, TextBaseline baseline, Widget child, Size size) {
    {
        assert(child != nullptr);
        assert(baseline != nullptr || !(identical(alignment, ui->PlaceholderAlignmentCls::aboveBaseline) || identical(alignment, ui->PlaceholderAlignmentCls::belowBaseline) || identical(alignment, ui->PlaceholderAlignmentCls::baseline)));
    }
}

TextRange _TextBoundaryCls::getTextBoundaryAt(TextPosition position) {
    return make<TextRangeCls>(getLeadingTextBoundaryAt(position)->offset, getTrailingTextBoundaryAt(position)->offset);
}

TextPosition _CodeUnitBoundaryCls::getLeadingTextBoundaryAt(TextPosition position) {
    return make<TextPositionCls>(position->offset);
}

TextPosition _CodeUnitBoundaryCls::getTrailingTextBoundaryAt(TextPosition position) {
    return make<TextPositionCls>(math->min(position->offset + 1, textEditingValue->text->length()));
}

TextPosition _WhitespaceBoundaryCls::getLeadingTextBoundaryAt(TextPosition position) {
    for (; index >= 0; index -= 1) {
        if (!TextLayoutMetricsCls->isWhitespace(textEditingValue->text->codeUnitAt(index))) {
            return make<TextPositionCls>(index);
        }
    }
    return make<TextPositionCls>(0);
}

TextPosition _WhitespaceBoundaryCls::getTrailingTextBoundaryAt(TextPosition position) {
    for (;  < textEditingValue->text->length(); index += 1) {
        if (!TextLayoutMetricsCls->isWhitespace(textEditingValue->text->codeUnitAt(index))) {
            return make<TextPositionCls>(index + 1);
        }
    }
    return make<TextPositionCls>(textEditingValue->text->length());
}

TextPosition _CharacterBoundaryCls::getLeadingTextBoundaryAt(TextPosition position) {
    int endOffset = math->min(position->offset + 1, textEditingValue->text->length());
    return make<TextPositionCls>(CharacterRangeCls->at(textEditingValue->text, position->offset, endOffset)->stringBeforeLength);
}

TextPosition _CharacterBoundaryCls::getTrailingTextBoundaryAt(TextPosition position) {
    int endOffset = math->min(position->offset + 1, textEditingValue->text->length());
    CharacterRange range = CharacterRangeCls->at(textEditingValue->text, position->offset, endOffset);
    return make<TextPositionCls>(textEditingValue->text->length() - range->stringAfterLength());
}

TextRange _CharacterBoundaryCls::getTextBoundaryAt(TextPosition position) {
    int endOffset = math->min(position->offset + 1, textEditingValue->text->length());
    CharacterRange range = CharacterRangeCls->at(textEditingValue->text, position->offset, endOffset);
    return make<TextRangeCls>(range->stringBeforeLength(), textEditingValue->text->length() - range->stringAfterLength());
}

TextPosition _WordBoundaryCls::getLeadingTextBoundaryAt(TextPosition position) {
    return make<TextPositionCls>(textLayout->getWordBoundary(position)->start, TextAffinityCls::downstream);
}

TextPosition _WordBoundaryCls::getTrailingTextBoundaryAt(TextPosition position) {
    return make<TextPositionCls>(textLayout->getWordBoundary(position)->end, TextAffinityCls::downstream);
}

TextPosition _LineBreakCls::getLeadingTextBoundaryAt(TextPosition position) {
    return make<TextPositionCls>(textLayout->getLineAtOffset(position)->start);
}

TextPosition _LineBreakCls::getTrailingTextBoundaryAt(TextPosition position) {
    return make<TextPositionCls>(textLayout->getLineAtOffset(position)->end, TextAffinityCls::upstream);
}

TextPosition _DocumentBoundaryCls::getLeadingTextBoundaryAt(TextPosition position) {
    return make<TextPositionCls>(0);
}

TextPosition _DocumentBoundaryCls::getTrailingTextBoundaryAt(TextPosition position) {
    return make<TextPositionCls>(textEditingValue->text->length(), TextAffinityCls::upstream);
}

TextEditingValue _ExpandedTextBoundaryCls::textEditingValue() {
    assert(innerTextBoundary->textEditingValue() == outerTextBoundary->textEditingValue());
    return innerTextBoundary->textEditingValue();
}

TextPosition _ExpandedTextBoundaryCls::getLeadingTextBoundaryAt(TextPosition position) {
    return outerTextBoundary->getLeadingTextBoundaryAt(innerTextBoundary->getLeadingTextBoundaryAt(position));
}

TextPosition _ExpandedTextBoundaryCls::getTrailingTextBoundaryAt(TextPosition position) {
    return outerTextBoundary->getTrailingTextBoundaryAt(innerTextBoundary->getTrailingTextBoundaryAt(position));
}

TextEditingValue _CollapsedSelectionBoundaryCls::textEditingValue() {
    return innerTextBoundary->textEditingValue();
}

TextPosition _CollapsedSelectionBoundaryCls::getLeadingTextBoundaryAt(TextPosition position) {
    return isForward? innerTextBoundary->getLeadingTextBoundaryAt(position) : position->offset <= 0? make<TextPositionCls>(0) : innerTextBoundary->getLeadingTextBoundaryAt(make<TextPositionCls>(position->offset - 1));
}

TextPosition _CollapsedSelectionBoundaryCls::getTrailingTextBoundaryAt(TextPosition position) {
    return isForward? innerTextBoundary->getTrailingTextBoundaryAt(position) : position->offset <= 0? make<TextPositionCls>(0) : innerTextBoundary->getTrailingTextBoundaryAt(make<TextPositionCls>(position->offset - 1));
}

TextEditingValue _MixedBoundaryCls::textEditingValue() {
    assert(leadingTextBoundary->textEditingValue() == trailingTextBoundary->textEditingValue());
    return leadingTextBoundary->textEditingValue();
}

TextPosition _MixedBoundaryCls::getLeadingTextBoundaryAt(TextPosition position) {
    return leadingTextBoundary->getLeadingTextBoundaryAt(position);
}

TextPosition _MixedBoundaryCls::getTrailingTextBoundaryAt(TextPosition position) {
    return trailingTextBoundary->getTrailingTextBoundaryAt(position);
}

template<typename T>
Object _DeleteTextActionCls<T>::invoke(T intent, BuildContext context) {
    TextSelection selection = state->_value()->selection;
    assert(selection->isValid());
    if (!selection->isCollapsed()) {
        return ActionsCls->invoke(context!, make<ReplaceTextIntentCls>(state->_value(), __s(""), _expandNonCollapsedRange(state->_value()), SelectionChangedCauseCls::keyboard));
    }
    _TextBoundary textBoundary = getTextBoundariesForIntent(intent);
    if (!textBoundary->textEditingValue()->selection->isValid()) {
        return nullptr;
    }
    if (!textBoundary->textEditingValue()->selection->isCollapsed()) {
        return ActionsCls->invoke(context!, make<ReplaceTextIntentCls>(state->_value(), __s(""), _expandNonCollapsedRange(textBoundary->textEditingValue()), SelectionChangedCauseCls::keyboard));
    }
    return ActionsCls->invoke(context!, make<ReplaceTextIntentCls>(textBoundary->textEditingValue(), __s(""), textBoundary->getTextBoundaryAt(textBoundary->textEditingValue()->selection->base()), SelectionChangedCauseCls::keyboard));
}

template<typename T>
bool _DeleteTextActionCls<T>::isActionEnabled() {
    return !state->widget()->readOnly && state->_value()->selection->isValid();
}

template<typename T>
TextRange _DeleteTextActionCls<T>::_expandNonCollapsedRange(TextEditingValue value) {
    TextRange selection = value->selection;
    assert(selection->isValid());
    assert(!selection->isCollapsed());
    _TextBoundary atomicBoundary = state->widget()->obscureText? make<_CodeUnitBoundaryCls>(value) : make<_CharacterBoundaryCls>(value);
    return make<TextRangeCls>(atomicBoundary->getLeadingTextBoundaryAt(make<TextPositionCls>(selection->start))->offset, atomicBoundary->getTrailingTextBoundaryAt(make<TextPositionCls>(selection->end - 1))->offset);
}

template<typename T>
Object _UpdateTextSelectionActionCls<T>::invoke(T intent, BuildContext context) {
    TextSelection selection = state->_value()->selection;
    assert(selection->isValid());
    bool collapseSelection = intent->collapseSelection || !state->widget()->selectionEnabled;
    InlineMethod;
    if (!selection->isCollapsed() && !ignoreNonCollapsedSelection && collapseSelection) {
        return ActionsCls->invoke(context!, make<UpdateSelectionIntentCls>(state->_value(), collapse(selection), SelectionChangedCauseCls::keyboard));
    }
    _TextBoundary textBoundary = getTextBoundariesForIntent(intent);
    TextSelection textBoundarySelection = textBoundary->textEditingValue()->selection;
    if (!textBoundarySelection->isValid()) {
        return nullptr;
    }
    if (!textBoundarySelection->isCollapsed() && !ignoreNonCollapsedSelection && collapseSelection) {
        return ActionsCls->invoke(context!, make<UpdateSelectionIntentCls>(state->_value(), collapse(textBoundarySelection), SelectionChangedCauseCls::keyboard));
    }
    TextPosition extent = textBoundarySelection->extent();
    if (intent->continuesAtWrap) {
        if (intent->forward && _isAtWordwrapUpstream(extent)) {
            extent = make<TextPositionCls>(extent->offset);
        } else {
            if (!intent->forward && _isAtWordwrapDownstream(extent)) {
            extent = make<TextPositionCls>(extent->offset, TextAffinityCls::upstream);
        }
;
        }    }
    TextPosition newExtent = intent->forward? textBoundary->getTrailingTextBoundaryAt(extent) : textBoundary->getLeadingTextBoundaryAt(extent);
    TextSelection newSelection = collapseSelection? TextSelectionCls->fromPosition(newExtent) : textBoundarySelection->extendTo(newExtent);
    if (!selection->isCollapsed() && intent->collapseAtReversal && (selection->baseOffset < selection->extentOffset != newSelection->baseOffset < newSelection->extentOffset)) {
        return ActionsCls->invoke(context!, make<UpdateSelectionIntentCls>(state->_value(), TextSelectionCls->fromPosition(selection->base()), SelectionChangedCauseCls::keyboard));
    }
    return ActionsCls->invoke(context!, make<UpdateSelectionIntentCls>(textBoundary->textEditingValue(), newSelection, SelectionChangedCauseCls::keyboard));
}

template<typename T>
bool _UpdateTextSelectionActionCls<T>::isActionEnabled() {
    return state->_value()->selection->isValid();
}

template<typename T>
bool _UpdateTextSelectionActionCls<T>::_isAtWordwrapUpstream(TextPosition position) {
    TextPosition end = make<TextPositionCls>(state->renderEditable()->getLineAtOffset(position)->end, TextAffinityCls::upstream);
    return end == position && end->offset != state->textEditingValue()->text->length() && state->textEditingValue()->text->codeUnitAt(position->offset) != NEWLINE_CODE_UNIT;
}

template<typename T>
bool _UpdateTextSelectionActionCls<T>::_isAtWordwrapDownstream(TextPosition position) {
    TextPosition start = make<TextPositionCls>(state->renderEditable()->getLineAtOffset(position)->start);
    return start == position && start->offset != 0 && state->textEditingValue()->text->codeUnitAt(position->offset - 1) != NEWLINE_CODE_UNIT;
}

Object _ExtendSelectionOrCaretPositionActionCls::invoke(ExtendSelectionToNextWordBoundaryOrCaretLocationIntent intent, BuildContext context) {
    TextSelection selection = state->_value()->selection;
    assert(selection->isValid());
    _TextBoundary textBoundary = getTextBoundariesForIntent(intent);
    TextSelection textBoundarySelection = textBoundary->textEditingValue()->selection;
    if (!textBoundarySelection->isValid()) {
        return nullptr;
    }
    TextPosition extent = textBoundarySelection->extent();
    TextPosition newExtent = intent->forward? textBoundary->getTrailingTextBoundaryAt(extent) : textBoundary->getLeadingTextBoundaryAt(extent);
    TextSelection newSelection = (newExtent->offset - textBoundarySelection->baseOffset) * (textBoundarySelection->extentOffset - textBoundarySelection->baseOffset) < 0? textBoundarySelection->copyWith(textBoundarySelection->baseOffset, textBoundarySelection->extentOffset > textBoundarySelection->baseOffset? TextAffinityCls::downstream : TextAffinityCls::upstream) : textBoundarySelection->extendTo(newExtent);
    return ActionsCls->invoke(context!, make<UpdateSelectionIntentCls>(textBoundary->textEditingValue(), newSelection, SelectionChangedCauseCls::keyboard));
}

bool _ExtendSelectionOrCaretPositionActionCls::isActionEnabled() {
    return state->widget()->selectionEnabled && state->_value()->selection->isValid();
}

template<typename T>
void _UpdateTextSelectionToAdjacentLineActionCls<T>::stopCurrentVerticalRunIfSelectionChanges() {
    TextSelection runSelection = _runSelection;
    if (runSelection == nullptr) {
        assert(_verticalMovementRun == nullptr);
        return;
    }
    _runSelection = state->_value()->selection;
    TextSelection currentSelection = state->widget()->controller->selection;
    bool continueCurrentRun = currentSelection->isValid() && currentSelection->isCollapsed() && currentSelection->baseOffset == runSelection->baseOffset && currentSelection->extentOffset == runSelection->extentOffset;
    if (!continueCurrentRun) {
        _verticalMovementRun = nullptr;
        _runSelection = nullptr;
    }
}

template<typename T>
void _UpdateTextSelectionToAdjacentLineActionCls<T>::invoke(T intent, BuildContext context) {
    assert(state->_value()->selection->isValid());
    bool collapseSelection = intent->collapseSelection || !state->widget()->selectionEnabled;
    TextEditingValue value = state->_textEditingValueforTextLayoutMetrics();
    if (!value->selection->isValid()) {
        return;
    }
    if (_verticalMovementRun?->isValid() == false) {
        _verticalMovementRun = nullptr;
        _runSelection = nullptr;
    }
    VerticalCaretMovementRun currentRun = _verticalMovementRun | state->renderEditable()->startVerticalCaretMovement(state->renderEditable()->selection()!->extent());
    bool shouldMove = intent->forward? currentRun->moveNext() : currentRun->movePrevious();
    TextPosition newExtent = shouldMove? currentRun->current() : (intent->forward? make<TextPositionCls>(state->_value()->text->length()) : make<TextPositionCls>(0));
    TextSelection newSelection = collapseSelection? TextSelectionCls->fromPosition(newExtent) : value->selection->extendTo(newExtent);
    ActionsCls->invoke(context!, make<UpdateSelectionIntentCls>(value, newSelection, SelectionChangedCauseCls::keyboard));
    if (state->_value()->selection == newSelection) {
        _verticalMovementRun = currentRun;
        _runSelection = newSelection;
    }
}

template<typename T>
bool _UpdateTextSelectionToAdjacentLineActionCls<T>::isActionEnabled() {
    return state->_value()->selection->isValid();
}

Object _SelectAllActionCls::invoke(SelectAllTextIntent intent, BuildContext context) {
    return ActionsCls->invoke(context!, make<UpdateSelectionIntentCls>(state->_value(), make<TextSelectionCls>(0, state->_value()->text->length()), intent->cause));
}

bool _SelectAllActionCls::isActionEnabled() {
    return state->widget()->selectionEnabled;
}

void _CopySelectionActionCls::invoke(CopySelectionTextIntent intent, BuildContext context) {
    if (intent->collapseSelection) {
        state->cutSelection(intent->cause);
    } else {
        state->copySelection(intent->cause);
    }
}

bool _CopySelectionActionCls::isActionEnabled() {
    return state->_value()->selection->isValid() && !state->_value()->selection->isCollapsed();
}

State<_TextEditingHistory> _TextEditingHistoryCls::createState() {
    return make<_TextEditingHistoryStateCls>();
}

void _TextEditingHistoryStateCls::initState() {
    super->initState();
    _throttledPush = <TextEditingValue>_throttle(_kThrottleDuration, _stack->push);
    _push();
    widget()->controller->addListener(_push);
}

void _TextEditingHistoryStateCls::didUpdateWidget(_TextEditingHistory oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget()->controller != oldWidget->controller) {
        _stack->clear();
        oldWidget->controller->removeListener(_push);
        widget()->controller->addListener(_push);
    }
}

void _TextEditingHistoryStateCls::dispose() {
    widget()->controller->removeListener(_push);
    _throttleTimer?->cancel();
    super->dispose();
}

Widget _TextEditingHistoryStateCls::build(BuildContext context) {
    Map<Type, Action<Intent>> map1 = make<MapCls<>>();map1.set(UndoTextIntentCls, <UndoTextIntent>overridable(context, <UndoTextIntent>make<CallbackActionCls>(_undo)));map1.set(RedoTextIntentCls, <RedoTextIntent>overridable(context, <RedoTextIntent>make<CallbackActionCls>(_redo)));return make<ActionsCls>(list1, widget()->child);
}

void _TextEditingHistoryStateCls::_undo(UndoTextIntent intent) {
    _update(_stack->undo());
}

void _TextEditingHistoryStateCls::_redo(RedoTextIntent intent) {
    _update(_stack->redo());
}

void _TextEditingHistoryStateCls::_update(TextEditingValue nextValue) {
    if (nextValue == nullptr) {
        return;
    }
    if (nextValue->text == widget()->controller->text) {
        return;
    }
    widget()->onTriggered(widget()->controller->value->copyWith(nextValue->text, nextValue->selection));
}

void _TextEditingHistoryStateCls::_push() {
    if (widget()->controller->value == TextEditingValueCls::empty) {
        return;
    }
    _throttleTimer = _throttledPush(widget()->controller->value);
}

template<typename T>
T _UndoStackCls<T>::currentValue() {
    return _list->isEmpty()? nullptr : _list[_index];
}

template<typename T>
void _UndoStackCls<T>::push(T value) {
    if (_list->isEmpty()) {
        _index = 0;
        _list->add(value);
        return;
    }
    assert( < _list->length() && _index >= 0);
    if (value == currentValue()) {
        return;
    }
    if (_index != nullptr && _index != _list->length() - 1) {
        _list->removeRange(_index + 1, _list->length());
    }
    _list->add(value);
    _index = _list->length() - 1;
}

template<typename T>
T _UndoStackCls<T>::undo() {
    if (_list->isEmpty()) {
        return nullptr;
    }
    assert( < _list->length() && _index >= 0);
    if (_index != 0) {
        _index = _index - 1;
    }
    return currentValue();
}

template<typename T>
T _UndoStackCls<T>::redo() {
    if (_list->isEmpty()) {
        return nullptr;
    }
    assert( < _list->length() && _index >= 0);
    if ( < _list->length() - 1) {
        _index = _index + 1;
    }
    return currentValue();
}

template<typename T>
void _UndoStackCls<T>::clear() {
    _list->clear();
    _index = -1;
}

template<typename T>
String _UndoStackCls<T>::toString() {
    return __s("_UndoStack $_list");
}

template<typename T>
_Throttled<T> _throttle(Duration duration, _Throttleable<T> function, bool leadingEdge) {
    Timer timer;
    bool calledDuringTimer = false;
    T arg;
    return [=] (T currentArg) {
        arg = currentArg;
        if (timer != nullptr) {
            calledDuringTimer = true;
            return timer!;
        }
        if (leadingEdge) {
            function(arg);
        }
        calledDuringTimer = false;
        timer = make<TimerCls>(duration, [=] () {
            if (!leadingEdge || calledDuringTimer) {
                function(arg);
            }
            timer = nullptr;
        });
        return timer!;
    };
}
