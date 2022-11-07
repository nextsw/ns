#include "text_editing_intents.hpp"
DeleteCharacterIntent::DeleteCharacterIntent(bool forward) {
    {
        super(forward);
    }
}

DeleteToNextWordBoundaryIntent::DeleteToNextWordBoundaryIntent(bool forward) {
    {
        super(forward);
    }
}

DeleteToLineBreakIntent::DeleteToLineBreakIntent(bool forward) {
    {
        super(forward);
    }
}

DirectionalCaretMovementIntent::DirectionalCaretMovementIntent(bool collapseAtReversal, bool collapseSelection, bool continuesAtWrap, Unknown) {
    {
        assert(!collapseSelection || !collapseAtReversal);
    }
}

ExtendSelectionByCharacterIntent::ExtendSelectionByCharacterIntent(bool collapseSelection, bool forward) {
    {
        super(forward, collapseSelection);
    }
}

ExtendSelectionToNextWordBoundaryIntent::ExtendSelectionToNextWordBoundaryIntent(bool collapseSelection, bool forward) {
    {
        super(forward, collapseSelection);
    }
}

ExtendSelectionToNextWordBoundaryOrCaretLocationIntent::ExtendSelectionToNextWordBoundaryOrCaretLocationIntent(bool forward) {
    {
        super(forward);
    }
}

ExpandSelectionToDocumentBoundaryIntent::ExpandSelectionToDocumentBoundaryIntent(bool forward) {
    {
        super(forward);
    }
}

ExpandSelectionToLineBreakIntent::ExpandSelectionToLineBreakIntent(bool forward) {
    {
        super(forward);
    }
}

ExtendSelectionToLineBreakIntent::ExtendSelectionToLineBreakIntent(bool collapseAtReversal, bool collapseSelection, bool continuesAtWrap, bool forward) {
    {
        assert(!collapseSelection || !collapseAtReversal);
        super(forward, collapseSelection, collapseAtReversal, continuesAtWrap);
    }
}

ExtendSelectionVerticallyToAdjacentLineIntent::ExtendSelectionVerticallyToAdjacentLineIntent(bool collapseSelection, bool forward) {
    {
        super(forward, collapseSelection);
    }
}

ExtendSelectionToDocumentBoundaryIntent::ExtendSelectionToDocumentBoundaryIntent(bool collapseSelection, bool forward) {
    {
        super(forward, collapseSelection);
    }
}

ScrollToDocumentBoundaryIntent::ScrollToDocumentBoundaryIntent(bool forward) {
    {
        super(forward);
    }
}

void CopySelectionTextIntent::cut(SelectionChangedCause cause)
