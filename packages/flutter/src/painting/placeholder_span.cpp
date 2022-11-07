#include "placeholder_span.hpp"
void PlaceholderSpan::computeToPlainText(StringBuffer buffer, bool includePlaceholders, bool includeSemanticsLabels) {
    if (includePlaceholders) {
        buffer.writeCharCode(placeholderCodeUnit);
    }
}

void PlaceholderSpan::computeSemanticsInformation(List<InlineSpanSemanticsInformation> collector) {
    collector.add(InlineSpanSemanticsInformation.placeholder);
}

void PlaceholderSpan::describeSemantics(Accumulator offset, List<dynamic> semanticsElements, List<int> semanticsOffsets) {
    semanticsOffsets.add(offset.value);
    semanticsOffsets.add(offset.value + 1);
    semanticsElements.add(nullptr);
    offset.increment(1);
}

void PlaceholderSpan::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<PlaceholderAlignment>EnumProperty("alignment", alignmentnullptr));
    properties.add(<TextBaseline>EnumProperty("baseline", baselinenullptr));
}
