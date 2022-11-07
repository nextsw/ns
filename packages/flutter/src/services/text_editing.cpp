#include "text_editing.hpp"
TextSelection::TextSelection(TextAffinity affinity, int baseOffset, int extentOffset, bool isDirectional) {
    {
        super( < extentOffset? baseOffset : extentOffset,  < extentOffset? extentOffset : baseOffset);
    }
}

void TextSelection::collapsed(TextAffinity affinity, int offset)

void TextSelection::fromPosition(TextPosition position)

TextPosition TextSelection::base() {
    TextAffinity affinity;
    if (!isValid || baseOffset == extentOffset) {
        affinity = this.affinity;
    } else     {
        if ( < extentOffset) {
        affinity = TextAffinity.downstream;
    } else {
        affinity = TextAffinity.upstream;
    }
;
    }    return TextPosition(baseOffset, affinity);
}

TextPosition TextSelection::extent() {
    TextAffinity affinity;
    if (!isValid || baseOffset == extentOffset) {
        affinity = this.affinity;
    } else     {
        if ( < extentOffset) {
        affinity = TextAffinity.upstream;
    } else {
        affinity = TextAffinity.downstream;
    }
;
    }    return TextPosition(extentOffset, affinity);
}

String TextSelection::toString() {
    String typeName = objectRuntimeType(this, "TextSelection");
    if (!isValid) {
        return "$typeName.invalid";
    }
    return isCollapsed? "$typeName.collapsed(offset: $baseOffset, affinity: $affinity, isDirectional: $isDirectional)" : "$typeName(baseOffset: $baseOffset, extentOffset: $extentOffset, isDirectional: $isDirectional)";
}

bool TextSelection::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other is! TextSelection) {
        return false;
    }
    if (!isValid) {
        return !other.isValid;
    }
    return other.baseOffset == baseOffset && other.extentOffset == extentOffset && (!isCollapsed || other.affinity == affinity) && other.isDirectional == isDirectional;
}

int TextSelection::hashCode() {
    if (!isValid) {
        return Object.hash(-1.hashCode, -1.hashCode, TextAffinity.downstream.hashCode);
    }
    int affinityHash = isCollapsed? affinity.hashCode : TextAffinity.downstream.hashCode;
    return Object.hash(baseOffset.hashCode, extentOffset.hashCode, affinityHash, isDirectional.hashCode);
}

TextSelection TextSelection::copyWith(TextAffinity affinity, int baseOffset, int extentOffset, bool isDirectional) {
    return TextSelection(baseOffset ?? this.baseOffset, extentOffset ?? this.extentOffset, affinity ?? this.affinity, isDirectional ?? this.isDirectional);
}

TextSelection TextSelection::expandTo(bool extentAtIndex, TextPosition position) {
    if (position.offset >= start && position.offset <= end) {
        return this;
    }
    bool normalized = baseOffset <= extentOffset;
    if (position.offset <= start) {
        if (extentAtIndex) {
            return copyWith(end, position.offset, position.affinity);
        }
        return copyWith(normalized? position.offset : baseOffset, normalized? extentOffset : position.offset);
    }
    if (extentAtIndex) {
        return copyWith(start, position.offset, position.affinity);
    }
    return copyWith(normalized? baseOffset : position.offset, normalized? position.offset : extentOffset);
}

TextSelection TextSelection::extendTo(TextPosition position) {
    if (extent == position) {
        return this;
    }
    return copyWith(position.offset, position.affinity);
}
