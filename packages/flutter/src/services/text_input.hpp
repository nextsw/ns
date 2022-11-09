#ifndef PACKAGES_FLUTTER_SRC_SERVICES_TEXT_INPUT
#define PACKAGES_FLUTTER_SRC_SERVICES_TEXT_INPUT
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "autofill.hpp"
#include "text_editing.hpp"

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/io/io.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/vector_math/vector_math.hpp>
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

class TextInputTypeCls : public ObjectCls {
public:
    int index;

    bool signed;

    bool decimal;

    static TextInputType text;

    static TextInputType multiline;

    static TextInputType number;

    static TextInputType phone;

    static TextInputType datetime;

    static TextInputType emailAddress;

    static TextInputType url;

    static TextInputType visiblePassword;

    static TextInputType name;

    static TextInputType streetAddress;

    static TextInputType none;

    static List<TextInputType> values;


    virtual void  numberWithOptions(bool decimal, bool signed);

    virtual Map<String, dynamic> toJson();

    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

private:
    static List<String> _names;


    virtual void  _(int index);

    virtual String _name();

};
using TextInputType = std::shared_ptr<TextInputTypeCls>;

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

class TextInputConfigurationCls : public ObjectCls {
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


     TextInputConfigurationCls(String actionLabel, bool autocorrect, AutofillConfiguration autofillConfiguration, bool enableDeltaModel, bool enableIMEPersonalizedLearning, bool enableInteractiveSelection, bool enableSuggestions, TextInputAction inputAction, TextInputType inputType, Brightness keyboardAppearance, bool obscureText, bool readOnly, SmartDashesType smartDashesType, SmartQuotesType smartQuotesType, TextCapitalization textCapitalization);

    virtual TextInputConfiguration copyWith(String actionLabel, bool autocorrect, AutofillConfiguration autofillConfiguration, bool enableDeltaModel, bool enableIMEPersonalizedLearning, bool enableInteractiveSelection, bool enableSuggestions, TextInputAction inputAction, TextInputType inputType, Brightness keyboardAppearance, bool obscureText, bool readOnly, SmartDashesType smartDashesType, SmartQuotesType smartQuotesType, TextCapitalization textCapitalization);

    virtual Map<String, dynamic> toJson();

private:

};
using TextInputConfiguration = std::shared_ptr<TextInputConfigurationCls>;
TextAffinity _toTextAffinity(String affinity);


enum FloatingCursorDragState{
    Start,
    Update,
    End,
} // end FloatingCursorDragState

class RawFloatingCursorPointCls : public ObjectCls {
public:
    Offset offset;

    FloatingCursorDragState state;


     RawFloatingCursorPointCls(Offset offset, FloatingCursorDragState state);

private:

};
using RawFloatingCursorPoint = std::shared_ptr<RawFloatingCursorPointCls>;

class TextEditingValueCls : public ObjectCls {
public:
    String text;

    TextSelection selection;

    TextRange composing;

    static TextEditingValue empty;


     TextEditingValueCls(TextRange composing, TextSelection selection, String text);

    virtual void  fromJSON(Map<String, dynamic> encoded);

    virtual TextEditingValue copyWith(TextRange composing, TextSelection selection, String text);

    virtual bool isComposingRangeValid();

    virtual TextEditingValue replaced(TextRange replacementRange, String replacementString);

    virtual Map<String, dynamic> toJSON();

    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

    static bool _textRangeIsValid(TextRange range, String text);

};
using TextEditingValue = std::shared_ptr<TextEditingValueCls>;

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

class TextSelectionDelegateCls : public ObjectCls {
public:

    virtual TextEditingValue textEditingValue();
    virtual void userUpdateTextEditingValue(SelectionChangedCause cause, TextEditingValue value);
    virtual void hideToolbar(bool hideHandles);
    virtual void bringIntoView(TextPosition position);
    virtual bool cutEnabled();

    virtual bool copyEnabled();

    virtual bool pasteEnabled();

    virtual bool selectAllEnabled();

    virtual void cutSelection(SelectionChangedCause cause);
    virtual Future<void> pasteText(SelectionChangedCause cause);
    virtual void selectAll(SelectionChangedCause cause);
    virtual void copySelection(SelectionChangedCause cause);
private:

};
using TextSelectionDelegate = std::shared_ptr<TextSelectionDelegateCls>;

class TextInputClientCls : public ObjectCls {
public:

    virtual TextEditingValue currentTextEditingValue();
    virtual AutofillScope currentAutofillScope();
    virtual void updateEditingValue(TextEditingValue value);
    virtual void performAction(TextInputAction action);
    virtual void performPrivateCommand(String action, Map<String, dynamic> data);
    virtual void updateFloatingCursor(RawFloatingCursorPoint point);
    virtual void showAutocorrectionPromptRect(int end, int start);
    virtual void connectionClosed();
    virtual void showToolbar();

    virtual void insertTextPlaceholder(Size size);

    virtual void removeTextPlaceholder();

private:

};
using TextInputClient = std::shared_ptr<TextInputClientCls>;

class ScribbleClientCls : public ObjectCls {
public:

    virtual String elementIdentifier();
    virtual void onScribbleFocus(Offset offset);
    virtual bool isInScribbleRect(Rect rect);
    virtual Rect bounds();
private:

};
using ScribbleClient = std::shared_ptr<ScribbleClientCls>;

class SelectionRectCls : public ObjectCls {
public:
    int position;

    Rect bounds;


     SelectionRectCls(Rect bounds, int position);
    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using SelectionRect = std::shared_ptr<SelectionRectCls>;

class DeltaTextInputClientCls : public ObjectCls {
public:

    virtual void updateEditingValueWithDeltas(List<TextEditingDelta> textEditingDeltas);
private:

};
using DeltaTextInputClient = std::shared_ptr<DeltaTextInputClientCls>;

class TextInputConnectionCls : public ObjectCls {
public:

    static void debugResetId(int to);

    virtual bool attached();

    virtual bool scribbleInProgress();

    virtual void show();

    virtual void requestAutofill();

    virtual void updateConfig(TextInputConfiguration configuration);

    virtual void setEditingState(TextEditingValue value);

    virtual void setEditableSizeAndTransform(Size editableBoxSize, Matrix4 transform);

    virtual void setComposingRect(Rect rect);

    virtual void setCaretRect(Rect rect);

    virtual void setSelectionRects(List<SelectionRect> selectionRects);

    virtual void setStyle(String fontFamily, double fontSize, FontWeight fontWeight, TextAlign textAlign, TextDirection textDirection);

    virtual void close();

    virtual void connectionClosedReceived();

private:
    Size _cachedSize;

    Matrix4 _cachedTransform;

    Rect _cachedRect;

    Rect _cachedCaretRect;

    List<SelectionRect> _cachedSelectionRects;

    static int _nextId;

    int _id;

    TextInputClient _client;


    virtual void  _(TextInputClient _client);

};
using TextInputConnection = std::shared_ptr<TextInputConnectionCls>;
TextInputAction _toTextInputAction(String action);

FloatingCursorDragState _toTextCursorAction(String state);

RawFloatingCursorPoint _toTextPoint(Map<String, dynamic> encoded, FloatingCursorDragState state);


class TextInputCls : public ObjectCls {
public:

    static void setChannel(MethodChannel newChannel);

    static void ensureInitialized();

    static TextInputConnection attach(TextInputClient client, TextInputConfiguration configuration);

    static Map<String, ScribbleClient> scribbleClients();

    virtual bool scribbleInProgress();

    static void finishAutofillContext(bool shouldSave);

    static void registerScribbleElement(String elementIdentifier, ScribbleClient scribbleClient);

    static void unregisterScribbleElement(String elementIdentifier);

private:
    static TextInput _instance;

    static List<TextInputAction> _androidSupportedInputActions;

    static List<TextInputAction> _iOSSupportedInputActions;

    MethodChannel _channel;

    TextInputConnection _currentConnection;

    TextInputConfiguration _currentConfiguration;

    Map<String, ScribbleClient> _scribbleClients;

    bool _scribbleInProgress;

    bool _hidePending;


    virtual void  _();

    virtual void _attach(TextInputConfiguration configuration, TextInputConnection connection);

    static bool _debugEnsureInputActionWorksOnPlatform(TextInputAction inputAction);

    virtual Future<dynamic> _loudlyHandleTextInputInvocation(MethodCall call);

    virtual Future<dynamic> _handleTextInputInvocation(MethodCall methodCall);

    virtual void _scheduleHide();

    virtual void _clearClient();

    virtual void _updateConfig(TextInputConfiguration configuration);

    virtual void _setEditingState(TextEditingValue value);

    virtual void _show();

    virtual void _requestAutofill();

    virtual void _setEditableSizeAndTransform(Map<String, dynamic> args);

    virtual void _setComposingTextRect(Map<String, dynamic> args);

    virtual void _setCaretRect(Map<String, dynamic> args);

    virtual void _setSelectionRects(List<List<num>> args);

    virtual void _setStyle(Map<String, dynamic> args);

};
using TextInput = std::shared_ptr<TextInputCls>;


#endif