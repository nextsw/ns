#include "text_editing_intents.hpp"
DeleteCharacterIntentCls::DeleteCharacterIntentCls(bool forward) {
}

DeleteToNextWordBoundaryIntentCls::DeleteToNextWordBoundaryIntentCls(bool forward) {
}

DeleteToLineBreakIntentCls::DeleteToLineBreakIntentCls(bool forward) {
}

DirectionalCaretMovementIntentCls::DirectionalCaretMovementIntentCls(bool collapseAtReversal, bool collapseSelection, bool continuesAtWrap, Unknown forward) {
    {
        assert(!collapseSelection || !collapseAtReversal);
    }
}

ExtendSelectionByCharacterIntentCls::ExtendSelectionByCharacterIntentCls(bool collapseSelection, bool forward) {
}

ExtendSelectionToNextWordBoundaryIntentCls::ExtendSelectionToNextWordBoundaryIntentCls(bool collapseSelection, bool forward) {
}

ExtendSelectionToNextWordBoundaryOrCaretLocationIntentCls::ExtendSelectionToNextWordBoundaryOrCaretLocationIntentCls(bool forward) {
}

ExpandSelectionToDocumentBoundaryIntentCls::ExpandSelectionToDocumentBoundaryIntentCls(bool forward) {
}

ExpandSelectionToLineBreakIntentCls::ExpandSelectionToLineBreakIntentCls(bool forward) {
}

ExtendSelectionToLineBreakIntentCls::ExtendSelectionToLineBreakIntentCls(bool collapseAtReversal, bool collapseSelection, bool continuesAtWrap, bool forward) {
    {
        assert(!collapseSelection || !collapseAtReversal);
    }
}

ExtendSelectionVerticallyToAdjacentLineIntentCls::ExtendSelectionVerticallyToAdjacentLineIntentCls(bool collapseSelection, bool forward) {
}

ExtendSelectionToDocumentBoundaryIntentCls::ExtendSelectionToDocumentBoundaryIntentCls(bool collapseSelection, bool forward) {
}

ScrollToDocumentBoundaryIntentCls::ScrollToDocumentBoundaryIntentCls(bool forward) {
}

void CopySelectionTextIntentCls::cut(SelectionChangedCause cause)
