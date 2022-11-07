#include "text_span.hpp"
TextSpan::TextSpan(List<InlineSpan> children, Locale locale, MouseCursor mouseCursor, PointerEnterEventListener onEnter, PointerExitEventListener onExit, GestureRecognizer recognizer, String semanticsLabel, bool spellOut, Unknown, String text) {
    {
        mouseCursor = mouseCursor ?? (recognizer == nullptr? MouseCursor.defer : SystemMouseCursors.click);
        assert(!(text == nullptr && semanticsLabel != nullptr));
    }
}

MouseCursor TextSpan::cursor() {
    return mouseCursor;
}

bool TextSpan::validForMouseTracker() {
    return true;
}

void TextSpan::handleEvent(HitTestEntry entry, PointerEvent event) {
    if (event is PointerDownEvent) {
        recognizer?.addPointer(event);
    }
}

void TextSpan::build(ParagraphBuilder builder, List<PlaceholderDimensions> dimensions, double textScaleFactor) {
    assert(debugAssertIsValid());
    bool hasStyle = style != nullptr;
    if (hasStyle) {
        builder.pushStyle(style!.getTextStyle(textScaleFactor));
    }
    if (text != nullptr) {
        ;
    }
    if (children != nullptr) {
        for (InlineSpan child : children!) {
            assert(child != nullptr);
            child.build(buildertextScaleFactor, dimensions);
        }
    }
    if (hasStyle) {
        builder.pop();
    }
}

bool TextSpan::visitChildren(InlineSpanVisitor visitor) {
    if (text != nullptr) {
        if (!visitor(this)) {
            return false;
        }
    }
    if (children != nullptr) {
        for (InlineSpan child : children!) {
            if (!child.visitChildren(visitor)) {
                return false;
            }
        }
    }
    return true;
}

InlineSpan TextSpan::getSpanForPositionVisitor(Accumulator offset, TextPosition position) {
    if (text == nullptr) {
        return nullptr;
    }
    TextAffinity affinity = position.affinity;
    int targetOffset = position.offset;
    int endOffset = offset.value + text!.length;
    if (offset.value == targetOffset && affinity == TextAffinity.downstream || offset.value < targetOffset &&  < endOffset || endOffset == targetOffset && affinity == TextAffinity.upstream) {
        return this;
    }
    offset.increment(text!.length);
    return nullptr;
}

void TextSpan::computeToPlainText(StringBuffer buffer, bool includePlaceholders, bool includeSemanticsLabels) {
    assert(debugAssertIsValid());
    if (semanticsLabel != nullptr && includeSemanticsLabels) {
        buffer.write(semanticsLabel);
    } else     {
        if (text != nullptr) {
        buffer.write(text);
    }
;
    }    if (children != nullptr) {
        for (InlineSpan child : children!) {
            child.computeToPlainText(bufferincludeSemanticsLabels, includePlaceholders);
        }
    }
}

void TextSpan::computeSemanticsInformation(List<InlineSpanSemanticsInformation> collector, Locale inheritedLocale, bool inheritedSpellOut) {
    assert(debugAssertIsValid());
    Locale effectiveLocale = locale ?? inheritedLocale;
    bool effectiveSpellOut = spellOut ?? inheritedSpellOut;
    if (text != nullptr) {
        int textLength = semanticsLabel?.length ?? text!.length;
        collector.add(InlineSpanSemanticsInformation(text!, semanticsLabel, recognizer));
    }
    if (children != nullptr) {
        for (InlineSpan child : children!) {
            if (child is TextSpan) {
                child.computeSemanticsInformation(collectoreffectiveLocale, effectiveSpellOut);
            } else {
                child.computeSemanticsInformation(collector);
            }
        }
    }
}

int TextSpan::codeUnitAtVisitor(int index, Accumulator offset) {
    if (text == nullptr) {
        return nullptr;
    }
    if (index - offset.value < text!.length) {
        return text!.codeUnitAt(index - offset.value);
    }
    offset.increment(text!.length);
    return nullptr;
}

void TextSpan::describeSemantics(Accumulator offset, List<dynamic> semanticsElements, List<int> semanticsOffsets) {
    if (recognizer != nullptr && (recognizer is TapGestureRecognizer || recognizer is LongPressGestureRecognizer)) {
        int length = semanticsLabel?.length ?? text!.length;
        semanticsOffsets.add(offset.value);
        semanticsOffsets.add(offset.value + length);
        semanticsElements.add(recognizer);
    }
    offset.increment(text != nullptr? text!.length : 0);
}

bool TextSpan::debugAssertIsValid() {
    assert(());
    return super.debugAssertIsValid();
}

RenderComparison TextSpan::compareTo(InlineSpan other) {
    if (identical(this, other)) {
        return RenderComparison.identical;
    }
    if (other.runtimeType != runtimeType) {
        return RenderComparison.layout;
    }
    TextSpan textSpan = (;
    if (textSpan.text != text || children?.length != textSpan.children?.length || (style == nullptr) != (textSpan.style == nullptr)) {
        return RenderComparison.layout;
    }
    RenderComparison result = recognizer == textSpan.recognizer? RenderComparison.identical : RenderComparison.metadata;
    if (style != nullptr) {
        RenderComparison candidate = style!.compareTo(textSpan.style!);
        if (candidate.index > result.index) {
            result = candidate;
        }
        if (result == RenderComparison.layout) {
            return result;
        }
    }
    if (children != nullptr) {
        for (;  < children!.length; index = 1) {
            RenderComparison candidate = children![index].compareTo(textSpan.children![index]);
            if (candidate.index > result.index) {
                result = candidate;
            }
            if (result == RenderComparison.layout) {
                return result;
            }
        }
    }
    return result;
}

bool TextSpan::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    if (super != other) {
        return false;
    }
    return other is TextSpan && other.text == text && other.recognizer == recognizer && other.semanticsLabel == semanticsLabel && onEnter == other.onEnter && onExit == other.onExit && mouseCursor == other.mouseCursor && <InlineSpan>listEquals(other.children, children);
}

int TextSpan::hashCode() {
    return Object.hash(super.hashCode, text, recognizer, semanticsLabel, onEnter, onExit, mouseCursor, children == nullptr? nullptr : Object.hashAll(children!));
}

String TextSpan::toStringShort() {
    return objectRuntimeType(this, "TextSpan");
}

void TextSpan::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(StringProperty("text", textfalse, nullptr));
    if (style == nullptr && text == nullptr && children == nullptr) {
        properties.add(DiagnosticsNode.message("(empty)"));
    }
    properties.add(<GestureRecognizer>DiagnosticsProperty("recognizer", recognizerrecognizer?.runtimeType.toString(), nullptr));
    properties.add(<FunctionType>FlagsSummary("callbacks", ));
    properties.add(<MouseCursor>DiagnosticsProperty("mouseCursor", cursorMouseCursor.defer));
    if (semanticsLabel != nullptr) {
        properties.add(StringProperty("semanticsLabel", semanticsLabel));
    }
}

List<DiagnosticsNode> TextSpan::debugDescribeChildren() {
    if (children == nullptr) {
        return const ;
    }
    return children!.<DiagnosticsNode>map().toList();
}
