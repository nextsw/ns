#include "text_editing.hpp"
TextSelectionCls::TextSelectionCls(TextAffinity affinity, int baseOffset, int extentOffset, bool isDirectional) : TextRange( < extentOffset? baseOffset : extentOffset,  < extentOffset? extentOffset : baseOffset) {
}

void TextSelectionCls::collapsed(TextAffinity affinity, int offset)

void TextSelectionCls::fromPosition(TextPosition position)

TextPosition TextSelectionCls::base() {
    TextAffinity affinity;
    if (!isValid || baseOffset == extentOffset) {
        affinity = this->affinity;
    } else {
        if ( < extentOffset) {
        affinity = TextAffinityCls::downstream;
    } else {
        affinity = TextAffinityCls::upstream;
    }
;
    }    return make<TextPositionCls>(baseOffset, affinity);
}

TextPosition TextSelectionCls::extent() {
    TextAffinity affinity;
    if (!isValid || baseOffset == extentOffset) {
        affinity = this->affinity;
    } else {
        if ( < extentOffset) {
        affinity = TextAffinityCls::upstream;
    } else {
        affinity = TextAffinityCls::downstream;
    }
;
    }    return make<TextPositionCls>(extentOffset, affinity);
}

String TextSelectionCls::toString() {
    String typeName = objectRuntimeType(this, __s("TextSelection"));
    if (!isValid) {
        return __s("$typeName.invalid");
    }
    return isCollapsed? __s("$typeName.collapsed(offset: $baseOffset, affinity: $affinity, isDirectional: $isDirectional)") : __s("$typeName(baseOffset: $baseOffset, extentOffset: $extentOffset, isDirectional: $isDirectional)");
}

bool TextSelectionCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (!is<TextSelection>(other)) {
        return false;
    }
    if (!isValid) {
        return !other->isValid;
    }
    return other->baseOffset == baseOffset && other->extentOffset == extentOffset && (!isCollapsed || other->affinity == affinity) && other->isDirectional == isDirectional;
}

int TextSelectionCls::hashCode() {
    if (!isValid) {
        return ObjectCls->hash(-1->hashCode, -1->hashCode, TextAffinityCls::downstream->hashCode());
    }
    int affinityHash = isCollapsed? affinity->hashCode() : TextAffinityCls::downstream->hashCode();
    return ObjectCls->hash(baseOffset->hashCode, extentOffset->hashCode, affinityHash, isDirectional->hashCode());
}

TextSelection TextSelectionCls::copyWith(TextAffinity affinity, int baseOffset, int extentOffset, bool isDirectional) {
    return make<TextSelectionCls>(baseOffset | this->baseOffset, extentOffset | this->extentOffset, affinity | this->affinity, isDirectional | this->isDirectional);
}

TextSelection TextSelectionCls::expandTo(TextPosition position, bool extentAtIndex) {
    if (position->offset >= start && position->offset <= end) {
        return this;
    }
    bool normalized = baseOffset <= extentOffset;
    if (position->offset <= start) {
        if (extentAtIndex) {
            return copyWith(end, position->offset, position->affinity);
        }
        return copyWith(normalized? position->offset : baseOffset, normalized? extentOffset : position->offset);
    }
    if (extentAtIndex) {
        return copyWith(start, position->offset, position->affinity);
    }
    return copyWith(normalized? baseOffset : position->offset, normalized? position->offset : extentOffset);
}

TextSelection TextSelectionCls::extendTo(TextPosition position) {
    if (extent() == position) {
        return this;
    }
    return copyWith(position->offset, position->affinity);
}
