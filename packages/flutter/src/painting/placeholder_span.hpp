#ifndef PLACEHOLDER_SPAN_H
#define PLACEHOLDER_SPAN_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"
#include "inline_span.hpp"
#include "text_painter.hpp"
#include "text_span.hpp"
#include "text_style.hpp"



class PlaceholderSpan : InlineSpan {
public:
    static const int placeholderCodeUnit;

    PlaceholderAlignment alignment;

    TextBaseline baseline;


     PlaceholderSpan(PlaceholderAlignment alignment, TextBaseline baseline, Unknown);

    void computeToPlainText(StringBuffer buffer, bool includePlaceholders, bool includeSemanticsLabels);

    void computeSemanticsInformation(List<InlineSpanSemanticsInformation> collector);

    void describeSemantics(Accumulator offset, List<dynamic> semanticsElements, List<int> semanticsOffsets);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif