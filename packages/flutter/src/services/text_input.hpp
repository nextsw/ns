#ifndef TEXT_INPUT_H
#define TEXT_INPUT_H
#include <memory>
#include <ui.hpp>
#include <vector_math/vector_math_64.hpp>
#include "autofill.hpp"
#include "text_editing.hpp"

#include <async/async.hpp>
#include <io/io.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <vector_math/vector_math_64.hpp>
#include "autofill.hpp"
#include "clipboard.hpp"
#include "message_codec.hpp"
#include "platform_channel.hpp"
#include "system_channels.hpp"
#include "text_editing.hpp"
#include "text_editing_delta.hpp"



enum SmartDashesType{
    disabled,
    enabled,
} // end SmartDashesType

enum SmartQuotesType{
    disabled,
    enabled,
} // end SmartQuotesType

class TextInputType {
public:
    int index;

    bool signed;

    bool decimal;

    static const TextInputType text;

    static const TextInputType multiline;

    static const TextInputType number;

    static const TextInputType phone;

    static const TextInputType datetime;

    static const TextInputType emailAddress;

    static const TextInputType url;

    static const TextInputType visiblePassword;

    static const TextInputType name;

    static const TextInputType streetAddress;

    static const TextInputType none;

    static const List<TextInputType> values;


    void  numberWithOptions(bool decimal, bool signed);

    Map<String, dynamic> toJson();

    String toString();

    bool ==(Object other);

    int hashCode();

private:
    static const List<String> _names;


    void  _(int index);

    String _name();

};

enum TextInputAction{
    none,
    unspecified,
    done,
    go,
    search,
    send,
    next,
    previous,
    continueAction,
    join,
    route,
    emergencyCall,
    newline,
} // end TextInputAction

enum TextCapitalization{
    words,
    sentences,
    characters,
    none,
} // end TextCapitalization

class TextInputConfiguration {
public:
    TextInputType inputType;

    bool readOnly;

    bool obscureText;

    bool autocorrect;

    AutofillConfiguration autofillConfiguration;

    SmartDashesType smartDashesType;

    SmartQuotesType smartQuotesType;

    bool enableSuggestions;

    bool enableInteractiveSelection;

    String actionLabel;

    TextInputAction inputAction;

    TextCapitalization textCapitalization;

    Brightness keyboardAppearance;

    bool enableIMEPersonalizedLearning;

    bool enableDeltaModel;


     TextInputConfiguration(String actionLabel, bool autocorrect, AutofillConfiguration autofillConfiguration, bool enableDeltaModel, bool enableIMEPersonalizedLearning, bool enableInteractiveSelection, bool enableSuggestions, TextInputAction inputAction, TextInputType inputType, Brightness keyboardAppearance, bool obscureText, bool readOnly, SmartDashesType smartDashesType, SmartQuotesType smartQuotesType, TextCapitalization textCapitalization);

    TextInputConfiguration copyWith(String actionLabel, bool autocorrect, AutofillConfiguration autofillConfiguration, bool enableDeltaModel, bool enableIMEPersonalizedLearning, bool enableInteractiveSelection, bool enableSuggestions, TextInputAction inputAction, TextInputType inputType, Brightness keyboardAppearance, bool obscureText, bool readOnly, SmartDashesType smartDashesType, SmartQuotesType smartQuotesType, TextCapitalization textCapitalization);

    Map<String, dynamic> toJson();

private:

};
TextAffinity _toTextAffinity(String affinity);


enum FloatingCursorDragState{
    Start,
    Update,
    End,
} // end FloatingCursorDragState

class RawFloatingCursorPoint {
public:
    Offset offset;

    FloatingCursorDragState state;


     RawFloatingCursorPoint(Offset offset, FloatingCursorDragState state);

private:

};

class TextEditingValue {
public:
    String text;

    TextSelection selection;

    TextRange composing;

    static const TextEditingValue empty;


     TextEditingValue(TextRange composing, TextSelection selection, String text);

    void  fromJSON(Map<String, dynamic> encoded);

    TextEditingValue copyWith(TextRange composing, TextSelection selection, String text);

    bool isComposingRangeValid();

    TextEditingValue replaced(TextRange replacementRange, String replacementString);

    Map<String, dynamic> toJSON();

    String toString();

    bool ==(Object other);

    int hashCode();

private:

    static bool _textRangeIsValid(TextRange range, String text);

};

enum SelectionChangedCause{
    tap,
    doubleTap,
    longPress,
    forcePress,
    keyboard,
    toolbar,
    drag,
    scribble,
} // end SelectionChangedCause

class TextSelectionDelegate {
public:

    TextEditingValue textEditingValue();

    void userUpdateTextEditingValue(SelectionChangedCause cause, TextEditingValue value);

    void hideToolbar(bool hideHandles);

    void bringIntoView(TextPosition position);

    bool cutEnabled();

    bool copyEnabled();

    bool pasteEnabled();

    bool selectAllEnabled();

    void cutSelection(SelectionChangedCause cause);

    Future<void> pasteText(SelectionChangedCause cause);

    void selectAll(SelectionChangedCause cause);

    void copySelection(SelectionChangedCause cause);

private:

};

class TextInputClient {
public:

    TextEditingValue currentTextEditingValue();

    AutofillScope currentAutofillScope();

    void updateEditingValue(TextEditingValue value);

    void performAction(TextInputAction action);

    void performPrivateCommand(String action, Map<String, dynamic> data);

    void updateFloatingCursor(RawFloatingCursorPoint point);

    void showAutocorrectionPromptRect(int end, int start);

    void connectionClosed();

    void showToolbar();

    void insertTextPlaceholder(Size size);

    void removeTextPlaceholder();

private:

};

class ScribbleClient {
public:

    String elementIdentifier();

    void onScribbleFocus(Offset offset);

    bool isInScribbleRect(Rect rect);

    Rect bounds();

private:

};

class SelectionRect {
public:
    int position;

    Rect bounds;


     SelectionRect(Rect bounds, int position);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class DeltaTextInputClient {
public:

    void updateEditingValueWithDeltas(List<TextEditingDelta> textEditingDeltas);

private:

};

class TextInputConnection {
public:

    static void debugResetId(int to);

    bool attached();

    bool scribbleInProgress();

    void show();

    void requestAutofill();

    void updateConfig(TextInputConfiguration configuration);

    void setEditingState(TextEditingValue value);

    void setEditableSizeAndTransform(Size editableBoxSize, Matrix4 transform);

    void setComposingRect(Rect rect);

    void setCaretRect(Rect rect);

    void setSelectionRects(List<SelectionRect> selectionRects);

    void setStyle(String fontFamily, double fontSize, FontWeight fontWeight, TextAlign textAlign, TextDirection textDirection);

    void close();

    void connectionClosedReceived();

private:
    Size _cachedSize;

    Matrix4 _cachedTransform;

    Rect _cachedRect;

    Rect _cachedCaretRect;

    List<SelectionRect> _cachedSelectionRects;

    static int _nextId;

    int _id;

    TextInputClient _client;


    void  _(TextInputClient _client);

};
TextInputAction _toTextInputAction(String action);

FloatingCursorDragState _toTextCursorAction(String state);

RawFloatingCursorPoint _toTextPoint(Map<String, dynamic> encoded, FloatingCursorDragState state);


class TextInput {
public:

    static void setChannel(MethodChannel newChannel);

    static void ensureInitialized();

    static TextInputConnection attach(TextInputClient client, TextInputConfiguration configuration);

    static Map<String, ScribbleClient> scribbleClients();

    bool scribbleInProgress();

    static void finishAutofillContext(bool shouldSave);

    static void registerScribbleElement(String elementIdentifier, ScribbleClient scribbleClient);

    static void unregisterScribbleElement(String elementIdentifier);

private:
    static TextInput _instance;

    static const List<TextInputAction> _androidSupportedInputActions;

    static const List<TextInputAction> _iOSSupportedInputActions;

    MethodChannel _channel;

    TextInputConnection _currentConnection;

    TextInputConfiguration _currentConfiguration;

    Map<String, ScribbleClient> _scribbleClients;

    bool _scribbleInProgress;

    bool _hidePending;


    void  _();

    void _attach(TextInputConfiguration configuration, TextInputConnection connection);

    static bool _debugEnsureInputActionWorksOnPlatform(TextInputAction inputAction);

    Future<dynamic> _loudlyHandleTextInputInvocation(MethodCall call);

    Future<dynamic> _handleTextInputInvocation(MethodCall methodCall);

    void _scheduleHide();

    void _clearClient();

    void _updateConfig(TextInputConfiguration configuration);

    void _setEditingState(TextEditingValue value);

    void _show();

    void _requestAutofill();

    void _setEditableSizeAndTransform(Map<String, dynamic> args);

    void _setComposingTextRect(Map<String, dynamic> args);

    void _setCaretRect(Map<String, dynamic> args);

    void _setSelectionRects(List<List<num>> args);

    void _setStyle(Map<String, dynamic> args);

};

#endif