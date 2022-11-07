#ifndef TEXT_LAYOUT_METRICS_H
#define TEXT_LAYOUT_METRICS_H
#include <memory>
#include <ui.hpp>
#include "text_editing.hpp"

#include <ui/ui.hpp>
#include "text_editing.hpp"



class TextLayoutMetrics {
public:

    static bool isWhitespace(int codeUnit);

    TextSelection getLineAtOffset(TextPosition position);

    TextRange getWordBoundary(TextPosition position);

    TextPosition getTextPositionAbove(TextPosition position);

    TextPosition getTextPositionBelow(TextPosition position);

private:

};

#endif