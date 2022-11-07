#include "text_input.hpp"
void TextInputType::numberWithOptions(bool decimal, bool signed)

Map<String, dynamic> TextInputType::toJson() {
    return ;
}

String TextInputType::toString() {
    return "${objectRuntimeType(this, 'TextInputType')}(name: $_name, signed: $signed, decimal: $decimal)";
}

bool TextInputType::==(Object other) {
    return other is TextInputType && other.index == index && other.signed == signed && other.decimal == decimal;
}

int TextInputType::hashCode() {
    return Object.hash(index, signed, decimal);
}

void TextInputType::_(int index)

String TextInputType::_name() {
    return "TextInputType.${_names[index]}";
}

TextInputConfiguration::TextInputConfiguration(String actionLabel, bool autocorrect, AutofillConfiguration autofillConfiguration, bool enableDeltaModel, bool enableIMEPersonalizedLearning, bool enableInteractiveSelection, bool enableSuggestions, TextInputAction inputAction, TextInputType inputType, Brightness keyboardAppearance, bool obscureText, bool readOnly, SmartDashesType smartDashesType, SmartQuotesType smartQuotesType, TextCapitalization textCapitalization) {
    {
        assert(inputType != nullptr);
        assert(obscureText != nullptr);
        smartDashesType = smartDashesType ?? (obscureText? SmartDashesType.disabled : SmartDashesType.enabled);
        smartQuotesType = smartQuotesType ?? (obscureText? SmartQuotesType.disabled : SmartQuotesType.enabled);
        assert(autocorrect != nullptr);
        assert(enableSuggestions != nullptr);
        assert(keyboardAppearance != nullptr);
        assert(inputAction != nullptr);
        assert(textCapitalization != nullptr);
        assert(enableIMEPersonalizedLearning != nullptr);
        assert(enableDeltaModel != nullptr);
    }
}

TextInputConfiguration TextInputConfiguration::copyWith(String actionLabel, bool autocorrect, AutofillConfiguration autofillConfiguration, bool enableDeltaModel, bool enableIMEPersonalizedLearning, bool enableInteractiveSelection, bool enableSuggestions, TextInputAction inputAction, TextInputType inputType, Brightness keyboardAppearance, bool obscureText, bool readOnly, SmartDashesType smartDashesType, SmartQuotesType smartQuotesType, TextCapitalization textCapitalization) {
    return TextInputConfiguration(inputType ?? this.inputType, readOnly ?? this.readOnly, obscureText ?? this.obscureText, autocorrect ?? this.autocorrect, smartDashesType ?? this.smartDashesType, smartQuotesType ?? this.smartQuotesType, enableSuggestions ?? this.enableSuggestions, enableInteractiveSelection ?? this.enableInteractiveSelection, inputAction ?? this.inputAction, textCapitalization ?? this.textCapitalization, keyboardAppearance ?? this.keyboardAppearance, enableIMEPersonalizedLearning ?? this.enableIMEPersonalizedLearning, autofillConfiguration ?? this.autofillConfiguration, enableDeltaModel ?? this.enableDeltaModel);
}

Map<String, dynamic> TextInputConfiguration::toJson() {
    Map<String, dynamic> autofill = autofillConfiguration.toJson();
    return ;
}

TextAffinity _toTextAffinity(String affinity) {
    ;
    return nullptr;
}

RawFloatingCursorPoint::RawFloatingCursorPoint(Offset offset, FloatingCursorDragState state) {
    {
        assert(state != nullptr);
        assert(state != FloatingCursorDragState.Update || offset != nullptr);
    }
}

TextEditingValue::TextEditingValue(TextRange composing, TextSelection selection, String text) {
    {
        assert(text != nullptr);
        assert(selection != nullptr);
        assert(composing != nullptr);
    }
}

void TextEditingValue::fromJSON(Map<String, dynamic> encoded) {
    String text = (;
    TextSelection selection = TextSelection(( ?? -1, ( ?? -1, _toTextAffinity(() ?? TextAffinity.downstream, ( ?? false);
    TextRange composing = TextRange(( ?? -1, ( ?? -1);
    assert(_textRangeIsValid(selection, text));
    assert(_textRangeIsValid(composing, text));
    return TextEditingValue(text, selection, composing);
}

TextEditingValue TextEditingValue::copyWith(TextRange composing, TextSelection selection, String text) {
    return TextEditingValue(text ?? this.text, selection ?? this.selection, composing ?? this.composing);
}

bool TextEditingValue::isComposingRangeValid() {
    return composing.isValid && composing.isNormalized && composing.end <= text.length;
}

TextEditingValue TextEditingValue::replaced(TextRange replacementRange, String replacementString) {
    if (!replacementRange.isValid) {
        return this;
    }
    String newText = text.replaceRange(replacementRange.start, replacementRange.end, replacementString);
    if (replacementRange.end - replacementRange.start == replacementString.length) {
        return copyWith(newText);
    }
    ;
    TextSelection adjustedSelection = TextSelection(adjustIndex(selection.baseOffset), adjustIndex(selection.extentOffset));
    TextRange adjustedComposing = TextRange(adjustIndex(composing.start), adjustIndex(composing.end));
    assert(_textRangeIsValid(adjustedSelection, newText));
    assert(_textRangeIsValid(adjustedComposing, newText));
    return TextEditingValue(newText, adjustedSelection, adjustedComposing);
}

Map<String, dynamic> TextEditingValue::toJSON() {
    assert(_textRangeIsValid(selection, text));
    assert(_textRangeIsValid(composing, text));
    return ;
}

String TextEditingValue::toString() {
    return "${objectRuntimeType(this, 'TextEditingValue')}(text: \u2524$text\u251C, selection: $selection, composing: $composing)";
}

bool TextEditingValue::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    return other is TextEditingValue && other.text == text && other.selection == selection && other.composing == composing;
}

int TextEditingValue::hashCode() {
    return Object.hash(text.hashCode, selection.hashCode, composing.hashCode);
}

bool TextEditingValue::_textRangeIsValid(TextRange range, String text) {
    if (range.start == -1 && range.end == -1) {
        return true;
    }
    assert(range.start >= 0 && range.start <= text.length, "Range start ${range.start} is out of text of length ${text.length}");
    assert(range.end >= 0 && range.end <= text.length, "Range end ${range.end} is out of text of length ${text.length}");
    return true;
}

bool TextSelectionDelegate::cutEnabled() {
    return true;
}

bool TextSelectionDelegate::copyEnabled() {
    return true;
}

bool TextSelectionDelegate::pasteEnabled() {
    return true;
}

bool TextSelectionDelegate::selectAllEnabled() {
    return true;
}

void TextInputClient::showToolbar() {
}

void TextInputClient::insertTextPlaceholder(Size size) {
}

void TextInputClient::removeTextPlaceholder() {
}

bool SelectionRect::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (runtimeType != other.runtimeType) {
        return false;
    }
    return other is SelectionRect && other.position == position && other.bounds == bounds;
}

int SelectionRect::hashCode() {
    return Object.hash(position, bounds);
}

String SelectionRect::toString() {
    return "SelectionRect($position, $bounds)";
}

void TextInputConnection::debugResetId(int to) {
    assert(to != nullptr);
    assert(());
}

bool TextInputConnection::attached() {
    return TextInput._instance._currentConnection == this;
}

bool TextInputConnection::scribbleInProgress() {
    return TextInput._instance.scribbleInProgress;
}

void TextInputConnection::show() {
    assert(attached);
    TextInput._instance._show();
}

void TextInputConnection::requestAutofill() {
    assert(attached);
    TextInput._instance._requestAutofill();
}

void TextInputConnection::updateConfig(TextInputConfiguration configuration) {
    assert(attached);
    TextInput._instance._updateConfig(configuration);
}

void TextInputConnection::setEditingState(TextEditingValue value) {
    assert(attached);
    TextInput._instance._setEditingState(value);
}

void TextInputConnection::setEditableSizeAndTransform(Size editableBoxSize, Matrix4 transform) {
    if (editableBoxSize != _cachedSize || transform != _cachedTransform) {
        _cachedSize = editableBoxSize;
        _cachedTransform = transform;
        TextInput._instance._setEditableSizeAndTransform();
    }
}

void TextInputConnection::setComposingRect(Rect rect) {
    assert(rect != nullptr);
    if (rect == _cachedRect) {
        return;
    }
    _cachedRect = rect;
    Rect validRect = rect.isFinite? rect : Offset.zero & const Size(-1, -1);
    TextInput._instance._setComposingTextRect();
}

void TextInputConnection::setCaretRect(Rect rect) {
    assert(rect != nullptr);
    if (rect == _cachedCaretRect) {
        return;
    }
    _cachedCaretRect = rect;
    Rect validRect = rect.isFinite? rect : Offset.zero & const Size(-1, -1);
    TextInput._instance._setCaretRect();
}

void TextInputConnection::setSelectionRects(List<SelectionRect> selectionRects) {
    if (!listEquals(_cachedSelectionRects, selectionRects)) {
        _cachedSelectionRects = selectionRects;
        TextInput._instance._setSelectionRects(selectionRects.map().toList());
    }
}

void TextInputConnection::setStyle(String fontFamily, double fontSize, FontWeight fontWeight, TextAlign textAlign, TextDirection textDirection) {
    assert(attached);
    TextInput._instance._setStyle();
}

void TextInputConnection::close() {
    if (attached) {
        TextInput._instance._clearClient();
    }
    assert(!attached);
}

void TextInputConnection::connectionClosedReceived() {
    TextInput._instance._currentConnection = nullptr;
    assert(!attached);
}

void TextInputConnection::_(TextInputClient _client)

TextInputAction _toTextInputAction(String action) {
    ;
    ;
}

FloatingCursorDragState _toTextCursorAction(String state) {
    ;
    ;
}

RawFloatingCursorPoint _toTextPoint(Map<String, dynamic> encoded, FloatingCursorDragState state) {
    assert(state != nullptr, "You must provide a state to set a new editing point.");
    assert(encoded["X"] != nullptr, "You must provide a value for the horizontal location of the floating cursor.");
    assert(encoded["Y"] != nullptr, "You must provide a value for the vertical location of the floating cursor.");
    Offset offset = state == FloatingCursorDragState.Update? Offset((, () : Offset.zero;
    return RawFloatingCursorPoint(offset, state);
}

void TextInput::setChannel(MethodChannel newChannel) {
    assert(());
}

void TextInput::ensureInitialized() {
    _instance;
}

TextInputConnection TextInput::attach(TextInputClient client, TextInputConfiguration configuration) {
    assert(client != nullptr);
    assert(configuration != nullptr);
    TextInputConnection connection = TextInputConnection._(client);
    _instance._attach(connection, configuration);
    return connection;
}

Map<String, ScribbleClient> TextInput::scribbleClients() {
    return TextInput._instance._scribbleClients;
}

bool TextInput::scribbleInProgress() {
    return _scribbleInProgress;
}

void TextInput::finishAutofillContext(bool shouldSave) {
    assert(shouldSave != nullptr);
    TextInput._instance._channel.<void>invokeMethod("TextInput.finishAutofillContext", shouldSave);
}

void TextInput::registerScribbleElement(String elementIdentifier, ScribbleClient scribbleClient) {
    TextInput._instance._scribbleClients[elementIdentifier] = scribbleClient;
}

void TextInput::unregisterScribbleElement(String elementIdentifier) {
    TextInput._instance._scribbleClients.remove(elementIdentifier);
}

void TextInput::_() {
    _channel = SystemChannels.textInput;
    _channel.setMethodCallHandler(_loudlyHandleTextInputInvocation);
}

void TextInput::_attach(TextInputConfiguration configuration, TextInputConnection connection) {
    assert(connection != nullptr);
    assert(connection._client != nullptr);
    assert(configuration != nullptr);
    assert(_debugEnsureInputActionWorksOnPlatform(configuration.inputAction));
    _channel.<void>invokeMethod("TextInput.setClient", );
    _currentConnection = connection;
    _currentConfiguration = configuration;
}

bool TextInput::_debugEnsureInputActionWorksOnPlatform(TextInputAction inputAction) {
    assert(());
    return true;
}

Future<dynamic> TextInput::_loudlyHandleTextInputInvocation(MethodCall call) {
    ;
}

Future<dynamic> TextInput::_handleTextInputInvocation(MethodCall methodCall) {
    String method = methodCall.method;
    if (method == "TextInputClient.focusElement") {
        List<dynamic> args = (;
        _scribbleClients[args[0]]?.onScribbleFocus(Offset((().toDouble(), (().toDouble()));
        return;
    } else     {
        if (method == "TextInputClient.requestElementsInRect") {
        List<double> args = (().<num>cast().<double>map().toList();
        return _scribbleClients.keys.where().map().toList();
    } else     {
        if (method == "TextInputClient.scribbleInteractionBegan") {
        _scribbleInProgress = true;
        return;
    } else     {
        if (method == "TextInputClient.scribbleInteractionFinished") {
        _scribbleInProgress = false;
        return;
    }
;
    };
    };
    }    if (_currentConnection == nullptr) {
        return;
    }
    if (method == "TextInputClient.requestExistingInputState") {
        assert(_currentConnection!._client != nullptr);
        _attach(_currentConnection!, _currentConfiguration);
        TextEditingValue editingValue = _currentConnection!._client.currentTextEditingValue;
        if (editingValue != nullptr) {
            _setEditingState(editingValue);
        }
        return;
    }
    List<dynamic> args = (;
    if (method == "TextInputClient.updateEditingStateWithTag") {
        assert(_currentConnection!._client != nullptr);
        TextInputClient client = _currentConnection!._client;
        AutofillScope scope = client.currentAutofillScope;
        Map<String, dynamic> editingValue = (;
        for (String tag : editingValue.keys) {
            TextEditingValue textEditingValue = TextEditingValue.fromJSON(();
            AutofillClient client = scope?.getAutofillClient(tag);
            if (client != nullptr && client.textInputConfiguration.autofillConfiguration.enabled) {
                client.autofill(textEditingValue);
            }
        }
        return;
    }
    int client = (;
    if (client != _currentConnection!._id) {
        bool debugAllowAnyway = false;
        assert(());
        if (!debugAllowAnyway) {
            return;
        }
    }
    ;
}

void TextInput::_scheduleHide() {
    if (_hidePending) {
        return;
    }
    _hidePending = true;
    scheduleMicrotask();
}

void TextInput::_clearClient() {
    _channel.<void>invokeMethod("TextInput.clearClient");
    _currentConnection = nullptr;
    _scheduleHide();
}

void TextInput::_updateConfig(TextInputConfiguration configuration) {
    assert(configuration != nullptr);
    _channel.<void>invokeMethod("TextInput.updateConfig", configuration.toJson());
}

void TextInput::_setEditingState(TextEditingValue value) {
    assert(value != nullptr);
    _channel.<void>invokeMethod("TextInput.setEditingState", value.toJSON());
}

void TextInput::_show() {
    _channel.<void>invokeMethod("TextInput.show");
}

void TextInput::_requestAutofill() {
    _channel.<void>invokeMethod("TextInput.requestAutofill");
}

void TextInput::_setEditableSizeAndTransform(Map<String, dynamic> args) {
    _channel.<void>invokeMethod("TextInput.setEditableSizeAndTransform", args);
}

void TextInput::_setComposingTextRect(Map<String, dynamic> args) {
    _channel.<void>invokeMethod("TextInput.setMarkedTextRect", args);
}

void TextInput::_setCaretRect(Map<String, dynamic> args) {
    _channel.<void>invokeMethod("TextInput.setCaretRect", args);
}

void TextInput::_setSelectionRects(List<List<num>> args) {
    _channel.<void>invokeMethod("TextInput.setSelectionRects", args);
}

void TextInput::_setStyle(Map<String, dynamic> args) {
    _channel.<void>invokeMethod("TextInput.setStyle", args);
}
