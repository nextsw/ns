#ifndef TEXT_EDITING_H
#define TEXT_EDITING_H
#include <memory>
#include <ui.hpp>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>



class TextSelection : TextRange {
public:
    int baseOffset;

    int extentOffset;

    TextAffinity affinity;

    bool isDirectional;


     TextSelection(TextAffinity affinity, int baseOffset, int extentOffset, bool isDirectional);

    void  collapsed(TextAffinity affinity, int offset);

    void  fromPosition(TextPosition position);

    TextPosition base();

    TextPosition extent();

    String toString();

    bool ==(Object other);

    int hashCode();

    TextSelection copyWith(TextAffinity affinity, int baseOffset, int extentOffset, bool isDirectional);

    TextSelection expandTo(bool extentAtIndex, TextPosition position);

    TextSelection extendTo(TextPosition position);

private:

};

#endif