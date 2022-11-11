#ifndef PACKAGES_FLUTTER_SRC_PAINTING_PLACEHOLDER_SPAN
#define PACKAGES_FLUTTER_SRC_PAINTING_PLACEHOLDER_SPAN
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"
#include "inline_span.hpp"
#include "text_painter.hpp"
#include "text_span.hpp"
#include "text_style.hpp"


class PlaceholderSpanCls : public InlineSpanCls {
public:
    static int placeholderCodeUnit;

    PlaceholderAlignment alignment;

    TextBaseline baseline;


     PlaceholderSpanCls(PlaceholderAlignment alignment, TextBaseline baseline, TextStyle style);
    virtual void computeToPlainText(StringBuffer buffer, bool includePlaceholders, bool includeSemanticsLabels);

    virtual void computeSemanticsInformation(List<InlineSpanSemanticsInformation> collector);

    virtual void describeSemantics(Accumulator offset, List<int> semanticsOffsets, List<dynamic> semanticsElements);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using PlaceholderSpan = std::shared_ptr<PlaceholderSpanCls>;


#endif