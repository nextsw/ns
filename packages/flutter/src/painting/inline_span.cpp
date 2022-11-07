#include "inline_span.hpp"
int Accumulator::value() {
    return _value;
}

void Accumulator::increment(int addend) {
    assert(addend >= 0);
    _value = addend;
}

InlineSpanSemanticsInformation::InlineSpanSemanticsInformation(bool isPlaceholder, GestureRecognizer recognizer, String semanticsLabel, List<StringAttribute> stringAttributes, String text) {
    {
        assert(text != nullptr);
        assert(isPlaceholder != nullptr);
        assert(isPlaceholder == false || (text == "\uFFFC" && semanticsLabel == nullptr && recognizer == nullptr));
        requiresOwnNode = isPlaceholder || recognizer != nullptr;
    }
}

bool InlineSpanSemanticsInformation::==(Object other) {
    return other is InlineSpanSemanticsInformation && other.text == text && other.semanticsLabel == semanticsLabel && other.recognizer == recognizer && other.isPlaceholder == isPlaceholder && <StringAttribute>listEquals(other.stringAttributes, stringAttributes);
}

int InlineSpanSemanticsInformation::hashCode() {
    return Object.hash(text, semanticsLabel, recognizer, isPlaceholder);
}

String InlineSpanSemanticsInformation::toString() {
    return "${objectRuntimeType(this, 'InlineSpanSemanticsInformation')}{text: $text, semanticsLabel: $semanticsLabel, recognizer: $recognizer}";
}

List<InlineSpanSemanticsInformation> combineSemanticsInfo(List<InlineSpanSemanticsInformation> infoList) {
    List<InlineSpanSemanticsInformation> combined = ;
    String workingText = "";
    String workingLabel = "";
    List<StringAttribute> workingAttributes = ;
    for (InlineSpanSemanticsInformation info : infoList) {
        if (info.requiresOwnNode) {
            combined.add(InlineSpanSemanticsInformation(workingTextworkingLabel, workingAttributes));
            workingText = "";
            workingLabel = "";
            workingAttributes = ;
            combined.add(info);
        } else {
            workingText = info.text;
            String effectiveLabel = info.semanticsLabel ?? info.text;
            for (StringAttribute infoAttribute : info.stringAttributes) {
                workingAttributes.add(infoAttribute.copy(TextRange(infoAttribute.range.start + workingLabel.length, infoAttribute.range.end + workingLabel.length)));
            }
            workingLabel = effectiveLabel;
        }
    }
    combined.add(InlineSpanSemanticsInformation(workingTextworkingLabel, workingAttributes));
    return combined;
}

InlineSpan InlineSpan::getSpanForPosition(TextPosition position) {
    assert(debugAssertIsValid());
    Accumulator offset = Accumulator();
    InlineSpan result;
    visitChildren();
    return result;
}

String InlineSpan::toPlainText(bool includePlaceholders, bool includeSemanticsLabels) {
    StringBuffer buffer = StringBuffer();
    computeToPlainText(bufferincludeSemanticsLabels, includePlaceholders);
    return buffer.toString();
}

List<InlineSpanSemanticsInformation> InlineSpan::getSemanticsInformation() {
    List<InlineSpanSemanticsInformation> collector = ;
    computeSemanticsInformation(collector);
    return collector;
}

int InlineSpan::codeUnitAt(int index) {
    if ( < 0) {
        return nullptr;
    }
    Accumulator offset = Accumulator();
    int result;
    visitChildren();
    return result;
}

bool InlineSpan::debugAssertIsValid() {
    return true;
}

bool InlineSpan::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is InlineSpan && other.style == style;
}

int InlineSpan::hashCode() {
    return style.hashCode;
}

void InlineSpan::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.defaultDiagnosticsTreeStyle = DiagnosticsTreeStyle.whitespace;
    if (style != nullptr) {
        style!.debugFillProperties(properties);
    }
}
