#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TEXT_EDITING_INTENTS
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TEXT_EDITING_INTENTS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/flutter.hpp>
#include "actions.hpp"


class DoNothingAndStopPropagationTextIntentCls : public IntentCls {
public:

     DoNothingAndStopPropagationTextIntentCls();
private:

};
using DoNothingAndStopPropagationTextIntent = std::shared_ptr<DoNothingAndStopPropagationTextIntentCls>;

class DirectionalTextEditingIntentCls : public IntentCls {
public:
    bool forward;


     DirectionalTextEditingIntentCls(bool forward);
private:

};
using DirectionalTextEditingIntent = std::shared_ptr<DirectionalTextEditingIntentCls>;

class DeleteCharacterIntentCls : public DirectionalTextEditingIntentCls {
public:

     DeleteCharacterIntentCls(bool forward);

private:

};
using DeleteCharacterIntent = std::shared_ptr<DeleteCharacterIntentCls>;

class DeleteToNextWordBoundaryIntentCls : public DirectionalTextEditingIntentCls {
public:

     DeleteToNextWordBoundaryIntentCls(bool forward);

private:

};
using DeleteToNextWordBoundaryIntent = std::shared_ptr<DeleteToNextWordBoundaryIntentCls>;

class DeleteToLineBreakIntentCls : public DirectionalTextEditingIntentCls {
public:

     DeleteToLineBreakIntentCls(bool forward);

private:

};
using DeleteToLineBreakIntent = std::shared_ptr<DeleteToLineBreakIntentCls>;

class DirectionalCaretMovementIntentCls : public DirectionalTextEditingIntentCls {
public:
    bool collapseSelection;

    bool collapseAtReversal;

    bool continuesAtWrap;


     DirectionalCaretMovementIntentCls(bool forward, bool collapseSelection, bool collapseAtReversal, bool continuesAtWrap);

private:

};
using DirectionalCaretMovementIntent = std::shared_ptr<DirectionalCaretMovementIntentCls>;

class ExtendSelectionByCharacterIntentCls : public DirectionalCaretMovementIntentCls {
public:

     ExtendSelectionByCharacterIntentCls(bool collapseSelection, bool forward);

private:

};
using ExtendSelectionByCharacterIntent = std::shared_ptr<ExtendSelectionByCharacterIntentCls>;

class ExtendSelectionToNextWordBoundaryIntentCls : public DirectionalCaretMovementIntentCls {
public:

     ExtendSelectionToNextWordBoundaryIntentCls(bool collapseSelection, bool forward);

private:

};
using ExtendSelectionToNextWordBoundaryIntent = std::shared_ptr<ExtendSelectionToNextWordBoundaryIntentCls>;

class ExtendSelectionToNextWordBoundaryOrCaretLocationIntentCls : public DirectionalTextEditingIntentCls {
public:

     ExtendSelectionToNextWordBoundaryOrCaretLocationIntentCls(bool forward);

private:

};
using ExtendSelectionToNextWordBoundaryOrCaretLocationIntent = std::shared_ptr<ExtendSelectionToNextWordBoundaryOrCaretLocationIntentCls>;

class ExpandSelectionToDocumentBoundaryIntentCls : public DirectionalTextEditingIntentCls {
public:

     ExpandSelectionToDocumentBoundaryIntentCls(bool forward);

private:

};
using ExpandSelectionToDocumentBoundaryIntent = std::shared_ptr<ExpandSelectionToDocumentBoundaryIntentCls>;

class ExpandSelectionToLineBreakIntentCls : public DirectionalTextEditingIntentCls {
public:

     ExpandSelectionToLineBreakIntentCls(bool forward);

private:

};
using ExpandSelectionToLineBreakIntent = std::shared_ptr<ExpandSelectionToLineBreakIntentCls>;

class ExtendSelectionToLineBreakIntentCls : public DirectionalCaretMovementIntentCls {
public:

     ExtendSelectionToLineBreakIntentCls(bool collapseAtReversal, bool collapseSelection, bool continuesAtWrap, bool forward);

private:

};
using ExtendSelectionToLineBreakIntent = std::shared_ptr<ExtendSelectionToLineBreakIntentCls>;

class ExtendSelectionVerticallyToAdjacentLineIntentCls : public DirectionalCaretMovementIntentCls {
public:

     ExtendSelectionVerticallyToAdjacentLineIntentCls(bool collapseSelection, bool forward);

private:

};
using ExtendSelectionVerticallyToAdjacentLineIntent = std::shared_ptr<ExtendSelectionVerticallyToAdjacentLineIntentCls>;

class ExtendSelectionToDocumentBoundaryIntentCls : public DirectionalCaretMovementIntentCls {
public:

     ExtendSelectionToDocumentBoundaryIntentCls(bool collapseSelection, bool forward);

private:

};
using ExtendSelectionToDocumentBoundaryIntent = std::shared_ptr<ExtendSelectionToDocumentBoundaryIntentCls>;

class ScrollToDocumentBoundaryIntentCls : public DirectionalTextEditingIntentCls {
public:

     ScrollToDocumentBoundaryIntentCls(bool forward);

private:

};
using ScrollToDocumentBoundaryIntent = std::shared_ptr<ScrollToDocumentBoundaryIntentCls>;

class SelectAllTextIntentCls : public IntentCls {
public:
    SelectionChangedCause cause;


     SelectAllTextIntentCls(SelectionChangedCause cause);
private:

};
using SelectAllTextIntent = std::shared_ptr<SelectAllTextIntentCls>;

class CopySelectionTextIntentCls : public IntentCls {
public:
    static CopySelectionTextIntent copy;

    SelectionChangedCause cause;

    bool collapseSelection;


    virtual void  cut(SelectionChangedCause cause);

private:

    virtual void  _(Unknown cause, Unknown collapseSelection);
};
using CopySelectionTextIntent = std::shared_ptr<CopySelectionTextIntentCls>;

class PasteTextIntentCls : public IntentCls {
public:
    SelectionChangedCause cause;


     PasteTextIntentCls(SelectionChangedCause cause);
private:

};
using PasteTextIntent = std::shared_ptr<PasteTextIntentCls>;

class RedoTextIntentCls : public IntentCls {
public:
    SelectionChangedCause cause;


     RedoTextIntentCls(SelectionChangedCause cause);
private:

};
using RedoTextIntent = std::shared_ptr<RedoTextIntentCls>;

class ReplaceTextIntentCls : public IntentCls {
public:
    TextEditingValue currentTextEditingValue;

    String replacementText;

    TextRange replacementRange;

    SelectionChangedCause cause;


     ReplaceTextIntentCls(TextEditingValue currentTextEditingValue, String replacementText, TextRange replacementRange, SelectionChangedCause cause);
private:

};
using ReplaceTextIntent = std::shared_ptr<ReplaceTextIntentCls>;

class UndoTextIntentCls : public IntentCls {
public:
    SelectionChangedCause cause;


     UndoTextIntentCls(SelectionChangedCause cause);
private:

};
using UndoTextIntent = std::shared_ptr<UndoTextIntentCls>;

class UpdateSelectionIntentCls : public IntentCls {
public:
    TextEditingValue currentTextEditingValue;

    TextSelection newSelection;

    SelectionChangedCause cause;


     UpdateSelectionIntentCls(TextEditingValue currentTextEditingValue, TextSelection newSelection, SelectionChangedCause cause);
private:

};
using UpdateSelectionIntent = std::shared_ptr<UpdateSelectionIntentCls>;

class TransposeCharactersIntentCls : public IntentCls {
public:

     TransposeCharactersIntentCls();
private:

};
using TransposeCharactersIntent = std::shared_ptr<TransposeCharactersIntentCls>;


#endif