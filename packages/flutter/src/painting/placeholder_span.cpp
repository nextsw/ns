#include "placeholder_span.hpp"
void PlaceholderSpanCls::computeToPlainText(StringBuffer buffer, bool includePlaceholders, bool includeSemanticsLabels) {
    if (includePlaceholders) {
        buffer->writeCharCode(placeholderCodeUnit);
    }
}

void PlaceholderSpanCls::computeSemanticsInformation(List<InlineSpanSemanticsInformation> collector) {
    collector->add(InlineSpanSemanticsInformationCls::placeholder);
}

void PlaceholderSpanCls::describeSemantics(Accumulator offset, List<dynamic> semanticsElements, List<int> semanticsOffsets) {
    semanticsOffsets->add(offset->value);
    semanticsOffsets->add(offset->value + 1);
    semanticsElements->add(nullptr);
    offset->increment(1);
}

void PlaceholderSpanCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<PlaceholderAlignment>make<EnumPropertyCls>("alignment", alignmentnullptr));
    properties->add(<TextBaseline>make<EnumPropertyCls>("baseline", baselinenullptr));
}
