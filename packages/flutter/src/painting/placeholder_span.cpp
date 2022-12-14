#include "placeholder_span.hpp"
void PlaceholderSpanCls::computeToPlainText(StringBuffer buffer, bool includePlaceholders, bool includeSemanticsLabels) {
    if (includePlaceholders) {
        buffer->writeCharCode(placeholderCodeUnit);
    }
}

void PlaceholderSpanCls::computeSemanticsInformation(List<InlineSpanSemanticsInformation> collector) {
    collector->add(InlineSpanSemanticsInformationCls::placeholder);
}

void PlaceholderSpanCls::describeSemantics(Accumulator offset, List<int> semanticsOffsets, List<Object> semanticsElements) {
    semanticsOffsets->add(offset->value());
    semanticsOffsets->add(offset->value() + 1);
    semanticsElements->add(nullptr);
    offset->increment(1);
}

void PlaceholderSpanCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<PlaceholderAlignment>make<EnumPropertyCls>(__s("alignment"), alignment, nullptr));
    properties->add(<TextBaseline>make<EnumPropertyCls>(__s("baseline"), baseline, nullptr));
}
