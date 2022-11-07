#ifndef TEXT_EDITING_INTENTS_H
#define TEXT_EDITING_INTENTS_H
#include <memory>

#include <flutter/services.hpp>
#include "actions.hpp"



class DoNothingAndStopPropagationTextIntent : Intent {
public:

     DoNothingAndStopPropagationTextIntent();

private:

};

class DirectionalTextEditingIntent : Intent {
public:
    bool forward;


     DirectionalTextEditingIntent(bool forward);

private:

};

class DeleteCharacterIntent : DirectionalTextEditingIntent {
public:

     DeleteCharacterIntent(bool forward);

private:

};

class DeleteToNextWordBoundaryIntent : DirectionalTextEditingIntent {
public:

     DeleteToNextWordBoundaryIntent(bool forward);

private:

};

class DeleteToLineBreakIntent : DirectionalTextEditingIntent {
public:

     DeleteToLineBreakIntent(bool forward);

private:

};

class DirectionalCaretMovementIntent : DirectionalTextEditingIntent {
public:
    bool collapseSelection;

    bool collapseAtReversal;

    bool continuesAtWrap;


     DirectionalCaretMovementIntent(bool collapseAtReversal, bool collapseSelection, bool continuesAtWrap, Unknown);

private:

};

class ExtendSelectionByCharacterIntent : DirectionalCaretMovementIntent {
public:

     ExtendSelectionByCharacterIntent(bool collapseSelection, bool forward);

private:

};

class ExtendSelectionToNextWordBoundaryIntent : DirectionalCaretMovementIntent {
public:

     ExtendSelectionToNextWordBoundaryIntent(bool collapseSelection, bool forward);

private:

};

class ExtendSelectionToNextWordBoundaryOrCaretLocationIntent : DirectionalTextEditingIntent {
public:

     ExtendSelectionToNextWordBoundaryOrCaretLocationIntent(bool forward);

private:

};

class ExpandSelectionToDocumentBoundaryIntent : DirectionalTextEditingIntent {
public:

     ExpandSelectionToDocumentBoundaryIntent(bool forward);

private:

};

class ExpandSelectionToLineBreakIntent : DirectionalTextEditingIntent {
public:

     ExpandSelectionToLineBreakIntent(bool forward);

private:

};

class ExtendSelectionToLineBreakIntent : DirectionalCaretMovementIntent {
public:

     ExtendSelectionToLineBreakIntent(bool collapseAtReversal, bool collapseSelection, bool continuesAtWrap, bool forward);

private:

};

class ExtendSelectionVerticallyToAdjacentLineIntent : DirectionalCaretMovementIntent {
public:

     ExtendSelectionVerticallyToAdjacentLineIntent(bool collapseSelection, bool forward);

private:

};

class ExtendSelectionToDocumentBoundaryIntent : DirectionalCaretMovementIntent {
public:

     ExtendSelectionToDocumentBoundaryIntent(bool collapseSelection, bool forward);

private:

};

class ScrollToDocumentBoundaryIntent : DirectionalTextEditingIntent {
public:

     ScrollToDocumentBoundaryIntent(bool forward);

private:

};

class SelectAllTextIntent : Intent {
public:
    SelectionChangedCause cause;


     SelectAllTextIntent(SelectionChangedCause cause);

private:

};

class CopySelectionTextIntent : Intent {
public:
    static const CopySelectionTextIntent copy;

    SelectionChangedCause cause;

    bool collapseSelection;


    void  cut(SelectionChangedCause cause);

private:

    void  _(SelectionChangedCause cause, bool collapseSelection);

};

class PasteTextIntent : Intent {
public:
    SelectionChangedCause cause;


     PasteTextIntent(SelectionChangedCause cause);

private:

};

class RedoTextIntent : Intent {
public:
    SelectionChangedCause cause;


     RedoTextIntent(SelectionChangedCause cause);

private:

};

class ReplaceTextIntent : Intent {
public:
    TextEditingValue currentTextEditingValue;

    String replacementText;

    TextRange replacementRange;

    SelectionChangedCause cause;


     ReplaceTextIntent(SelectionChangedCause cause, TextEditingValue currentTextEditingValue, TextRange replacementRange, String replacementText);

private:

};

class UndoTextIntent : Intent {
public:
    SelectionChangedCause cause;


     UndoTextIntent(SelectionChangedCause cause);

private:

};

class UpdateSelectionIntent : Intent {
public:
    TextEditingValue currentTextEditingValue;

    TextSelection newSelection;

    SelectionChangedCause cause;


     UpdateSelectionIntent(SelectionChangedCause cause, TextEditingValue currentTextEditingValue, TextSelection newSelection);

private:

};

class TransposeCharactersIntent : Intent {
public:

     TransposeCharactersIntent();

private:

};

#endif