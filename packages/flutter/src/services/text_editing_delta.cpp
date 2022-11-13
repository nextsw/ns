#include "text_editing_delta.hpp"
TextAffinity _toTextAffinity(String affinity) {
    ;
    return nullptr;
}

String _replace(String originalText, String replacementText, int start, int end) {
    String textStart = originalText->substring(0, start);
    String textEnd = originalText->substring(end, originalText->length());
    String newText = textStart + replacementText + textEnd;
    return newText;
}

TextEditingDeltaCls::TextEditingDeltaCls(TextRange composing, String oldText, TextSelection selection) {
    {
        assert(oldText != nullptr);
        assert(selection != nullptr);
        assert(composing != nullptr);
    }
}

void TextEditingDeltaCls::fromJSON(Map<String, Object> encoded) {
    String oldText = as<String>(encoded[__s("oldText")]);
    int replacementDestinationStart = as<int>(encoded[__s("deltaStart")]);
    int replacementDestinationEnd = as<int>(encoded[__s("deltaEnd")]);
    String replacementSource = as<String>(encoded[__s("deltaText")]);
    int replacementSourceStart = 0;
    int replacementSourceEnd = replacementSource->length();
    bool isNonTextUpdate = replacementDestinationStart == -1 && replacementDestinationStart == replacementDestinationEnd;
    TextRange newComposing = make<TextRangeCls>(as<int>(encoded[__s("composingBase")]) | -1, as<int>(encoded[__s("composingExtent")]) | -1);
    TextSelection newSelection = make<TextSelectionCls>(as<int>(encoded[__s("selectionBase")]) | -1, as<int>(encoded[__s("selectionExtent")]) | -1, _toTextAffinity(as<String>(encoded[__s("selectionAffinity")])) | TextAffinityCls::downstream, as<bool>(encoded[__s("selectionIsDirectional")]) | false);
    if (isNonTextUpdate) {
        return make<TextEditingDeltaNonTextUpdateCls>(oldText, newSelection, newComposing);
    }
    String newText = _replace(oldText, replacementSource, replacementDestinationStart, replacementDestinationEnd);
    bool isEqual = oldText == newText;
    bool isDeletionGreaterThanOne = (replacementDestinationEnd - replacementDestinationStart) - (replacementSourceEnd - replacementSourceStart) > 1;
    bool isDeletingByReplacingWithEmpty = replacementSource->isEmpty() && replacementSourceStart == 0 && replacementSourceStart == replacementSourceEnd;
    bool isReplacedByShorter = isDeletionGreaterThanOne && (replacementSourceEnd -  < replacementDestinationEnd - replacementDestinationStart);
    bool isReplacedByLonger = replacementSourceEnd - replacementSourceStart > replacementDestinationEnd - replacementDestinationStart;
    bool isReplacedBySame = replacementSourceEnd - replacementSourceStart == replacementDestinationEnd - replacementDestinationStart;
    bool isInsertingInsideComposingRegion = replacementDestinationStart + replacementSourceEnd > replacementDestinationEnd;
    bool isDeletingInsideComposingRegion = !isReplacedByShorter && !isDeletingByReplacingWithEmpty && replacementDestinationStart +  < replacementDestinationEnd;
    String newComposingText;
    String originalComposingText;
    if (isDeletingByReplacingWithEmpty || isDeletingInsideComposingRegion || isReplacedByShorter) {
        newComposingText = replacementSource->substring(replacementSourceStart, replacementSourceEnd);
        originalComposingText = oldText->substring(replacementDestinationStart, replacementDestinationStart + replacementSourceEnd);
    } else {
        newComposingText = replacementSource->substring(replacementSourceStart, replacementSourceStart + (replacementDestinationEnd - replacementDestinationStart));
        originalComposingText = oldText->substring(replacementDestinationStart, replacementDestinationEnd);
    }
    bool isOriginalComposingRegionTextChanged = !(originalComposingText == newComposingText);
    bool isReplaced = isOriginalComposingRegionTextChanged || (isReplacedByLonger || isReplacedByShorter || isReplacedBySame);
    if (isEqual) {
        return make<TextEditingDeltaNonTextUpdateCls>(oldText, newSelection, newComposing);
    } else {
        if ((isDeletingByReplacingWithEmpty || isDeletingInsideComposingRegion) && !isOriginalComposingRegionTextChanged) {
        int actualStart = replacementDestinationStart;
        if (!isDeletionGreaterThanOne) {
            actualStart = replacementDestinationEnd - 1;
        }
        return make<TextEditingDeltaDeletionCls>(oldText, make<TextRangeCls>(actualStart, replacementDestinationEnd), newSelection, newComposing);
    } else {
        if ((replacementDestinationStart == replacementDestinationEnd || isInsertingInsideComposingRegion) && !isOriginalComposingRegionTextChanged) {
        return make<TextEditingDeltaInsertionCls>(oldText, replacementSource->substring(replacementDestinationEnd - replacementDestinationStart, (replacementDestinationEnd - replacementDestinationStart) + (replacementSource->length() - (replacementDestinationEnd - replacementDestinationStart))), replacementDestinationEnd, newSelection, newComposing);
    } else {
        if (isReplaced) {
        return make<TextEditingDeltaReplacementCls>(oldText, replacementSource, make<TextRangeCls>(replacementDestinationStart, replacementDestinationEnd), newSelection, newComposing);
    }
;
    };
    };
    }    assert(false);
    return make<TextEditingDeltaNonTextUpdateCls>(oldText, newSelection, newComposing);
}

TextEditingValue TextEditingDeltaInsertionCls::apply(TextEditingValue value) {
    String newText = oldText;
    newText = _replace(newText, textInserted, insertionOffset, insertionOffset);
    return value->copyWith(newText, selection, composing);
}

String TextEditingDeltaDeletionCls::textDeleted() {
    return oldText->substring(deletedRange->start, deletedRange->end);
}

TextEditingValue TextEditingDeltaDeletionCls::apply(TextEditingValue value) {
    String newText = oldText;
    newText = _replace(newText, __s(""), deletedRange->start, deletedRange->end);
    return value->copyWith(newText, selection, composing);
}

String TextEditingDeltaReplacementCls::textReplaced() {
    return oldText->substring(replacedRange->start, replacedRange->end);
}

TextEditingValue TextEditingDeltaReplacementCls::apply(TextEditingValue value) {
    String newText = oldText;
    newText = _replace(newText, replacementText, replacedRange->start, replacedRange->end);
    return value->copyWith(newText, selection, composing);
}

TextEditingValue TextEditingDeltaNonTextUpdateCls::apply(TextEditingValue value) {
    return make<TextEditingValueCls>(oldText, selection, composing);
}
