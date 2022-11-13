#include "text_input.hpp"
void TextInputTypeCls::numberWithOptions(bool decimal, bool signed)

Map<String, Object> TextInputTypeCls::toJson() {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("name"), _name());map1.set(__s("signed"), signed);map1.set(__s("decimal"), decimal);return list1;
}

String TextInputTypeCls::toString() {
    return __sf("%s(name: %s, signed: %s, decimal: %s)", objectRuntimeType(this, __s("TextInputType")), _name(), signed, decimal);
}

bool TextInputTypeCls::==(Object other) {
    return is<TextInputType>(other) && other->index == index && other->signed == signed && other->decimal == decimal;
}

int TextInputTypeCls::hashCode() {
    return ObjectCls->hash(index, signed, decimal);
}

void TextInputTypeCls::_(int index)

String TextInputTypeCls::_name() {
    return __sf("TextInputType.%s", _names[index]);
}

TextInputConfigurationCls::TextInputConfigurationCls(String actionLabel, bool autocorrect, AutofillConfiguration autofillConfiguration, bool enableDeltaModel, bool enableIMEPersonalizedLearning, bool enableInteractiveSelection, bool enableSuggestions, TextInputAction inputAction, TextInputType inputType, Brightness keyboardAppearance, bool obscureText, bool readOnly, SmartDashesType smartDashesType, SmartQuotesType smartQuotesType, TextCapitalization textCapitalization) {
    {
        assert(inputType != nullptr);
        assert(obscureText != nullptr);
        smartDashesType = smartDashesType | (obscureText? SmartDashesTypeCls::disabled : SmartDashesTypeCls::enabled);
        smartQuotesType = smartQuotesType | (obscureText? SmartQuotesTypeCls::disabled : SmartQuotesTypeCls::enabled);
        assert(autocorrect != nullptr);
        assert(enableSuggestions != nullptr);
        assert(keyboardAppearance != nullptr);
        assert(inputAction != nullptr);
        assert(textCapitalization != nullptr);
        assert(enableIMEPersonalizedLearning != nullptr);
        assert(enableDeltaModel != nullptr);
    }
}

TextInputConfiguration TextInputConfigurationCls::copyWith(String actionLabel, bool autocorrect, AutofillConfiguration autofillConfiguration, bool enableDeltaModel, bool enableIMEPersonalizedLearning, bool enableInteractiveSelection, bool enableSuggestions, TextInputAction inputAction, TextInputType inputType, Brightness keyboardAppearance, bool obscureText, bool readOnly, SmartDashesType smartDashesType, SmartQuotesType smartQuotesType, TextCapitalization textCapitalization) {
    return make<TextInputConfigurationCls>(inputType | this->inputType, readOnly | this->readOnly, obscureText | this->obscureText, autocorrect | this->autocorrect, smartDashesType | this->smartDashesType, smartQuotesType | this->smartQuotesType, enableSuggestions | this->enableSuggestions, enableInteractiveSelection | this->enableInteractiveSelection, inputAction | this->inputAction, textCapitalization | this->textCapitalization, keyboardAppearance | this->keyboardAppearance, enableIMEPersonalizedLearning | this->enableIMEPersonalizedLearning, autofillConfiguration | this->autofillConfiguration, enableDeltaModel | this->enableDeltaModel);
}

Map<String, Object> TextInputConfigurationCls::toJson() {
    Map<String, Object> autofill = autofillConfiguration->toJson();
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("inputType"), inputType->toJson());map1.set(__s("readOnly"), readOnly);map1.set(__s("obscureText"), obscureText);map1.set(__s("autocorrect"), autocorrect);map1.set(__s("smartDashesType"), smartDashesType->index->toString());map1.set(__s("smartQuotesType"), smartQuotesType->index->toString());map1.set(__s("enableSuggestions"), enableSuggestions);map1.set(__s("enableInteractiveSelection"), enableInteractiveSelection);map1.set(__s("actionLabel"), actionLabel);map1.set(__s("inputAction"), inputAction->toString());map1.set(__s("textCapitalization"), textCapitalization->toString());map1.set(__s("keyboardAppearance"), keyboardAppearance->toString());map1.set(__s("enableIMEPersonalizedLearning"), enableIMEPersonalizedLearning);if (autofill != nullptr) {    map1.set(__s("autofill"), autofill);}map1.set(__s("enableDeltaModel"), enableDeltaModel);return list1;
}

TextAffinity _toTextAffinity(String affinity) {
    ;
    return nullptr;
}

RawFloatingCursorPointCls::RawFloatingCursorPointCls(Offset offset, FloatingCursorDragState state) {
    {
        assert(state != nullptr);
        assert(state != FloatingCursorDragStateCls::UpdateCls || offset != nullptr);
    }
}

TextEditingValueCls::TextEditingValueCls(TextRange composing, TextSelection selection, String text) {
    {
        assert(text != nullptr);
        assert(selection != nullptr);
        assert(composing != nullptr);
    }
}

void TextEditingValueCls::fromJSON(Map<String, Object> encoded) {
    String text = as<String>(encoded[__s("text")]);
    TextSelection selection = make<TextSelectionCls>(as<int>(encoded[__s("selectionBase")]) | -1, as<int>(encoded[__s("selectionExtent")]) | -1, _toTextAffinity(as<String>(encoded[__s("selectionAffinity")])) | TextAffinityCls::downstream, as<bool>(encoded[__s("selectionIsDirectional")]) | false);
    TextRange composing = make<TextRangeCls>(as<int>(encoded[__s("composingBase")]) | -1, as<int>(encoded[__s("composingExtent")]) | -1);
    assert(_textRangeIsValid(selection, text));
    assert(_textRangeIsValid(composing, text));
    return make<TextEditingValueCls>(text, selection, composing);
}

TextEditingValue TextEditingValueCls::copyWith(TextRange composing, TextSelection selection, String text) {
    return make<TextEditingValueCls>(text | this->text, selection | this->selection, composing | this->composing);
}

bool TextEditingValueCls::isComposingRangeValid() {
    return composing->isValid() && composing->isNormalized() && composing->end <= text->length();
}

TextEditingValue TextEditingValueCls::replaced(TextRange replacementRange, String replacementString) {
    if (!replacementRange->isValid()) {
        return this;
    }
    String newText = text->replaceRange(replacementRange->start, replacementRange->end, replacementString);
    if (replacementRange->end - replacementRange->start == replacementString->length()) {
        return copyWith(newText);
    }
    InlineMethod;
    TextSelection adjustedSelection = make<TextSelectionCls>(adjustIndex(selection->baseOffset), adjustIndex(selection->extentOffset));
    TextRange adjustedComposing = make<TextRangeCls>(adjustIndex(composing->start), adjustIndex(composing->end));
    assert(_textRangeIsValid(adjustedSelection, newText));
    assert(_textRangeIsValid(adjustedComposing, newText));
    return make<TextEditingValueCls>(newText, adjustedSelection, adjustedComposing);
}

Map<String, Object> TextEditingValueCls::toJSON() {
    assert(_textRangeIsValid(selection, text));
    assert(_textRangeIsValid(composing, text));
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("text"), text);map1.set(__s("selectionBase"), selection->baseOffset);map1.set(__s("selectionExtent"), selection->extentOffset);map1.set(__s("selectionAffinity"), selection->affinity->toString());map1.set(__s("selectionIsDirectional"), selection->isDirectional);map1.set(__s("composingBase"), composing->start);map1.set(__s("composingExtent"), composing->end);return list1;
}

String TextEditingValueCls::toString() {
    return __sf("%s(text: \u2524%s\u251C, selection: %s, composing: %s)", objectRuntimeType(this, __s("TextEditingValue")), text, selection, composing);
}

bool TextEditingValueCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    return is<TextEditingValue>(other) && other->text == text && other->selection == selection && other->composing == composing;
}

int TextEditingValueCls::hashCode() {
    return ObjectCls->hash(text->hashCode(), selection->hashCode(), composing->hashCode());
}

bool TextEditingValueCls::_textRangeIsValid(TextRange range, String text) {
    if (range->start == -1 && range->end == -1) {
        return true;
    }
    assert(range->start >= 0 && range->start <= text->length(), __sf("Range start %s is out of text of length %s", range->start, text->length()));
    assert(range->end >= 0 && range->end <= text->length(), __sf("Range end %s is out of text of length %s", range->end, text->length()));
    return true;
}

bool TextSelectionDelegateCls::cutEnabled() {
    return true;
}

bool TextSelectionDelegateCls::copyEnabled() {
    return true;
}

bool TextSelectionDelegateCls::pasteEnabled() {
    return true;
}

bool TextSelectionDelegateCls::selectAllEnabled() {
    return true;
}

void TextInputClientCls::showToolbar() {
}

void TextInputClientCls::insertTextPlaceholder(Size size) {
}

void TextInputClientCls::removeTextPlaceholder() {
}

bool SelectionRectCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (runtimeType != other->runtimeType()) {
        return false;
    }
    return is<SelectionRect>(other) && other->position == position && other->bounds == bounds;
}

int SelectionRectCls::hashCode() {
    return ObjectCls->hash(position, bounds);
}

String SelectionRectCls::toString() {
    return __sf("SelectionRect(%s, %s)", position, bounds);
}

void TextInputConnectionCls::debugResetId(int to) {
    assert(to != nullptr);
    assert([=] () {
        _nextId = to;
        return true;
    }());
}

bool TextInputConnectionCls::attached() {
    return TextInputCls::_instance->_currentConnection == this;
}

bool TextInputConnectionCls::scribbleInProgress() {
    return TextInputCls::_instance->scribbleInProgress;
}

void TextInputConnectionCls::show() {
    assert(attached());
    TextInputCls::_instance->_show();
}

void TextInputConnectionCls::requestAutofill() {
    assert(attached());
    TextInputCls::_instance->_requestAutofill();
}

void TextInputConnectionCls::updateConfig(TextInputConfiguration configuration) {
    assert(attached());
    TextInputCls::_instance->_updateConfig(configuration);
}

void TextInputConnectionCls::setEditingState(TextEditingValue value) {
    assert(attached());
    TextInputCls::_instance->_setEditingState(value);
}

void TextInputConnectionCls::setEditableSizeAndTransform(Size editableBoxSize, Matrix4 transform) {
    if (editableBoxSize != _cachedSize || transform != _cachedTransform) {
        _cachedSize = editableBoxSize;
        _cachedTransform = transform;
            Map<String, Object> map1 = make<MapCls<>>();    map1.set(__s("width"), editableBoxSize->width());    map1.set(__s("height"), editableBoxSize->height());    map1.set(__s("transform"), transform->storage());TextInputCls::_instance->_setEditableSizeAndTransform(list1);
    }
}

void TextInputConnectionCls::setComposingRect(Rect rect) {
    assert(rect != nullptr);
    if (rect == _cachedRect) {
        return;
    }
    _cachedRect = rect;
    Rect validRect = rect->isFinite()? rect : OffsetCls::zero & make<SizeCls>(-1, -1);
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("width"), validRect->width());map1.set(__s("height"), validRect->height());map1.set(__s("x"), validRect->left);map1.set(__s("y"), validRect->top);TextInputCls::_instance->_setComposingTextRect(list1);
}

void TextInputConnectionCls::setCaretRect(Rect rect) {
    assert(rect != nullptr);
    if (rect == _cachedCaretRect) {
        return;
    }
    _cachedCaretRect = rect;
    Rect validRect = rect->isFinite()? rect : OffsetCls::zero & make<SizeCls>(-1, -1);
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("width"), validRect->width());map1.set(__s("height"), validRect->height());map1.set(__s("x"), validRect->left);map1.set(__s("y"), validRect->top);TextInputCls::_instance->_setCaretRect(list1);
}

void TextInputConnectionCls::setSelectionRects(List<SelectionRect> selectionRects) {
    if (!listEquals(_cachedSelectionRects, selectionRects)) {
        _cachedSelectionRects = selectionRects;
        TextInputCls::_instance->_setSelectionRects(selectionRects->map([=] (SelectionRect rect) {
            return makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem);
        })->toList());
    }
}

void TextInputConnectionCls::setStyle(String fontFamily, double fontSize, FontWeight fontWeight, TextAlign textAlign, TextDirection textDirection) {
    assert(attached());
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("fontFamily"), fontFamily);map1.set(__s("fontSize"), fontSize);map1.set(__s("fontWeightIndex"), fontWeight?->index);map1.set(__s("textAlignIndex"), textAlign->index);map1.set(__s("textDirectionIndex"), textDirection->index);TextInputCls::_instance->_setStyle(list1);
}

void TextInputConnectionCls::close() {
    if (attached()) {
        TextInputCls::_instance->_clearClient();
    }
    assert(!attached());
}

void TextInputConnectionCls::connectionClosedReceived() {
    TextInputCls::_instance->_currentConnection = nullptr;
    assert(!attached());
}

void TextInputConnectionCls::_(TextInputClient _client)

TextInputAction _toTextInputAction(String action) {
    ;
    throw FlutterErrorCls->fromParts(makeList(ArrayItem));
}

FloatingCursorDragState _toTextCursorAction(String state) {
    ;
    throw FlutterErrorCls->fromParts(makeList(ArrayItem));
}

RawFloatingCursorPoint _toTextPoint(FloatingCursorDragState state, Map<String, Object> encoded) {
    assert(state != nullptr, __s("You must provide a state to set a new editing point."));
    assert(encoded[__s("X")] != nullptr, __s("You must provide a value for the horizontal location of the floating cursor."));
    assert(encoded[__s("Y")] != nullptr, __s("You must provide a value for the vertical location of the floating cursor."));
    Offset offset = state == FloatingCursorDragStateCls::UpdateCls? make<OffsetCls>(as<double>(encoded[__s("X")]), as<double>(encoded[__s("Y")])) : OffsetCls::zero;
    return make<RawFloatingCursorPointCls>(offset, state);
}

void TextInputCls::setChannel(MethodChannel newChannel) {
    assert([=] () {
            auto _c1 = newChannel;    _c1.setMethodCallHandler(_instance->_loudlyHandleTextInputInvocation);_instance->_channel = _c1;
        return true;
    }());
}

void TextInputCls::ensureInitialized() {
    _instance;
}

TextInputConnection TextInputCls::attach(TextInputClient client, TextInputConfiguration configuration) {
    assert(client != nullptr);
    assert(configuration != nullptr);
    TextInputConnection connection = TextInputConnectionCls->_(client);
    _instance->_attach(connection, configuration);
    return connection;
}

Map<String, ScribbleClient> TextInputCls::scribbleClients() {
    return TextInputCls::_instance->_scribbleClients;
}

bool TextInputCls::scribbleInProgress() {
    return _scribbleInProgress;
}

void TextInputCls::finishAutofillContext(bool shouldSave) {
    assert(shouldSave != nullptr);
    TextInputCls::_instance->_channel-><void>invokeMethod(__s("TextInput.finishAutofillContext"), shouldSave);
}

void TextInputCls::registerScribbleElement(String elementIdentifier, ScribbleClient scribbleClient) {
    TextInputCls::_instance->_scribbleClients[elementIdentifier] = scribbleClient;
}

void TextInputCls::unregisterScribbleElement(String elementIdentifier) {
    TextInputCls::_instance->_scribbleClients->remove(elementIdentifier);
}

void TextInputCls::_() {
    _channel = SystemChannelsCls::textInput;
    _channel->setMethodCallHandler(_loudlyHandleTextInputInvocation);
}

void TextInputCls::_attach(TextInputConnection connection, TextInputConfiguration configuration) {
    assert(connection != nullptr);
    assert(connection->_client != nullptr);
    assert(configuration != nullptr);
    assert(_debugEnsureInputActionWorksOnPlatform(configuration->inputAction));
    _channel-><void>invokeMethod(__s("TextInput.setClient"), makeList(ArrayItem, ArrayItem));
    _currentConnection = connection;
    _currentConfiguration = configuration;
}

bool TextInputCls::_debugEnsureInputActionWorksOnPlatform(TextInputAction inputAction) {
    assert([=] () {
        if (kIsWeb) {
            return true;
        }
        if (PlatformCls::isIOS) {
            assert(_iOSSupportedInputActions->contains(inputAction), __sf("The requested TextInputAction "%s" is not supported on iOS.", inputAction));
        } else {
            if (PlatformCls::isAndroid) {
            assert(_androidSupportedInputActions->contains(inputAction), __sf("The requested TextInputAction "%s" is not supported on Android.", inputAction));
        }
;
        }        return true;
    }());
    return true;
}

Future<Object> TextInputCls::_loudlyHandleTextInputInvocation(MethodCall call) {
    try {
        return await _handleTextInputInvocation(call);
    } catch (Unknown exception) {
        FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("services library"), make<ErrorDescriptionCls>(__sf("during method call %s", call->method)), [=] () {
            makeList(ArrayItem);
        }));
        throw;
    };
}

Future<Object> TextInputCls::_handleTextInputInvocation(MethodCall methodCall) {
    String method = methodCall->method;
    if (method == __s("TextInputClient.focusElement")) {
        List<Object> args = as<List<Object>>(methodCall->arguments);
        _scribbleClients[args[0]]?->onScribbleFocus(make<OffsetCls>((as<num>(args[1]))->toDouble(), (as<num>(args[2]))->toDouble()));
        return;
    } else {
        if (method == __s("TextInputClient.requestElementsInRect")) {
        List<double> args = (as<List<Object>>(methodCall->arguments))-><num>cast()-><double>map([=] (num value) {
    value->toDouble();
})->toList();
        return _scribbleClients->keys()->where([=] (String elementIdentifier) {
            Rect rect = RectCls->fromLTWH(args[0], args[1], args[2], args[3]);
            if (!(_scribbleClients[elementIdentifier]?->isInScribbleRect(rect) | false)) {
                return false;
            }
            Rect bounds = _scribbleClients[elementIdentifier]?->bounds | RectCls::zero;
            return !(bounds == RectCls::zero || bounds->hasNaN() || bounds->isInfinite());
        })->map([=] (String elementIdentifier) {
            Rect bounds = _scribbleClients[elementIdentifier]!->bounds;
                    List<Object> list1 = make<ListCls<>>();        list1.add(ArrayItem);        for (auto _x1 : makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem)) {        {            list1.add(_x1);        }return list1;
        })->toList();
    } else {
        if (method == __s("TextInputClient.scribbleInteractionBegan")) {
        _scribbleInProgress = true;
        return;
    } else {
        if (method == __s("TextInputClient.scribbleInteractionFinished")) {
        _scribbleInProgress = false;
        return;
    }
;
    };
    };
    }    if (_currentConnection == nullptr) {
        return;
    }
    if (method == __s("TextInputClient.requestExistingInputState")) {
        assert(_currentConnection!->_client != nullptr);
        _attach(_currentConnection!, _currentConfiguration);
        TextEditingValue editingValue = _currentConnection!->_client->currentTextEditingValue();
        if (editingValue != nullptr) {
            _setEditingState(editingValue);
        }
        return;
    }
    List<Object> args = as<List<Object>>(methodCall->arguments);
    if (method == __s("TextInputClient.updateEditingStateWithTag")) {
        assert(_currentConnection!->_client != nullptr);
        TextInputClient client = _currentConnection!->_client;
        AutofillScope scope = client->currentAutofillScope();
        Map<String, Object> editingValue = as<Map<String, Object>>(args[1]);
        for (String tag : editingValue->keys()) {
            TextEditingValue textEditingValue = TextEditingValueCls->fromJSON(as<Map<String, Object>>(editingValue[tag]));
            AutofillClient client = scope?->getAutofillClient(tag);
            if (client != nullptr && client->textInputConfiguration()->autofillConfiguration->enabled) {
                client->autofill(textEditingValue);
            }
        }
        return;
    }
    int client = as<int>(args[0]);
    if (client != _currentConnection!->_id) {
        bool debugAllowAnyway = false;
        assert([=] () {
            if (client == -1) {
                debugAllowAnyway = true;
            }
            return true;
        }());
        if (!debugAllowAnyway) {
            return;
        }
    }
    ;
}

void TextInputCls::_scheduleHide() {
    if (_hidePending) {
        return;
    }
    _hidePending = true;
    scheduleMicrotask([=] () {
        _hidePending = false;
        if (_currentConnection == nullptr) {
            _channel-><void>invokeMethod(__s("TextInput.hide"));
        }
    });
}

void TextInputCls::_clearClient() {
    _channel-><void>invokeMethod(__s("TextInput.clearClient"));
    _currentConnection = nullptr;
    _scheduleHide();
}

void TextInputCls::_updateConfig(TextInputConfiguration configuration) {
    assert(configuration != nullptr);
    _channel-><void>invokeMethod(__s("TextInput.updateConfig"), configuration->toJson());
}

void TextInputCls::_setEditingState(TextEditingValue value) {
    assert(value != nullptr);
    _channel-><void>invokeMethod(__s("TextInput.setEditingState"), value->toJSON());
}

void TextInputCls::_show() {
    _channel-><void>invokeMethod(__s("TextInput.show"));
}

void TextInputCls::_requestAutofill() {
    _channel-><void>invokeMethod(__s("TextInput.requestAutofill"));
}

void TextInputCls::_setEditableSizeAndTransform(Map<String, Object> args) {
    _channel-><void>invokeMethod(__s("TextInput.setEditableSizeAndTransform"), args);
}

void TextInputCls::_setComposingTextRect(Map<String, Object> args) {
    _channel-><void>invokeMethod(__s("TextInput.setMarkedTextRect"), args);
}

void TextInputCls::_setCaretRect(Map<String, Object> args) {
    _channel-><void>invokeMethod(__s("TextInput.setCaretRect"), args);
}

void TextInputCls::_setSelectionRects(List<List<num>> args) {
    _channel-><void>invokeMethod(__s("TextInput.setSelectionRects"), args);
}

void TextInputCls::_setStyle(Map<String, Object> args) {
    _channel-><void>invokeMethod(__s("TextInput.setStyle"), args);
}
