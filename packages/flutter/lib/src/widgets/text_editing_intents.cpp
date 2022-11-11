#include "text_editing_intents.hpp"
DeleteCharacterIntentCls::DeleteCharacterIntentCls(bool forward) : DirectionalTextEditingIntent(forward) {
}

DeleteToNextWordBoundaryIntentCls::DeleteToNextWordBoundaryIntentCls(bool forward) : DirectionalTextEditingIntent(forward) {
}

DeleteToLineBreakIntentCls::DeleteToLineBreakIntentCls(bool forward) : DirectionalTextEditingIntent(forward) {
}

DirectionalCaretMovementIntentCls::DirectionalCaretMovementIntentCls(bool collapseAtReversal, bool collapseSelection, bool continuesAtWrap, Unknown forward) {
    {
        assert(!collapseSelection || !collapseAtReversal);
    }
}

ExtendSelectionByCharacterIntentCls::ExtendSelectionByCharacterIntentCls(bool collapseSelection, bool forward) : DirectionalCaretMovementIntent(forward, collapseSelection) {
}

ExtendSelectionToNextWordBoundaryIntentCls::ExtendSelectionToNextWordBoundaryIntentCls(bool collapseSelection, bool forward) : DirectionalCaretMovementIntent(forward, collapseSelection) {
}

ExtendSelectionToNextWordBoundaryOrCaretLocationIntentCls::ExtendSelectionToNextWordBoundaryOrCaretLocationIntentCls(bool forward) : DirectionalTextEditingIntent(forward) {
}

ExpandSelectionToDocumentBoundaryIntentCls::ExpandSelectionToDocumentBoundaryIntentCls(bool forward) : DirectionalTextEditingIntent(forward) {
}

ExpandSelectionToLineBreakIntentCls::ExpandSelectionToLineBreakIntentCls(bool forward) : DirectionalTextEditingIntent(forward) {
}

ExtendSelectionToLineBreakIntentCls::ExtendSelectionToLineBreakIntentCls(bool collapseAtReversal, bool collapseSelection, bool continuesAtWrap, bool forward) : DirectionalCaretMovementIntent(forward, collapseSelection, collapseAtReversal, continuesAtWrap) {
    {
        assert(!collapseSelection || !collapseAtReversal);
    }
}

ExtendSelectionVerticallyToAdjacentLineIntentCls::ExtendSelectionVerticallyToAdjacentLineIntentCls(bool collapseSelection, bool forward) : DirectionalCaretMovementIntent(forward, collapseSelection) {
}

ExtendSelectionToDocumentBoundaryIntentCls::ExtendSelectionToDocumentBoundaryIntentCls(bool collapseSelection, bool forward) : DirectionalCaretMovementIntent(forward, collapseSelection) {
}

ScrollToDocumentBoundaryIntentCls::ScrollToDocumentBoundaryIntentCls(bool forward) : DirectionalTextEditingIntent(forward) {
}

void CopySelectionTextIntentCls::cut(SelectionChangedCause cause)
