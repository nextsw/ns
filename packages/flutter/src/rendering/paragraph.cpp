#include "paragraph.hpp"
String TextParentData::toString() {
    List<String> values = ;
    return values.join("; ");
}

PlaceholderSpanIndexSemanticsTag::PlaceholderSpanIndexSemanticsTag(int index) {
    {
        super("PlaceholderSpanIndexSemanticsTag($index)");
    }
}

bool PlaceholderSpanIndexSemanticsTag::==(Object other) {
    return other is PlaceholderSpanIndexSemanticsTag && other.index == index;
}

int PlaceholderSpanIndexSemanticsTag::hashCode() {
    return Object.hash(PlaceholderSpanIndexSemanticsTag, index);
}

RenderParagraph::RenderParagraph(List<RenderBox> children, Locale locale, int maxLines, TextOverflow overflow, SelectionRegistrar registrar, Color selectionColor, bool softWrap, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis) {
    {
        assert(text != nullptr);
        assert(text.debugAssertIsValid());
        assert(textAlign != nullptr);
        assert(textDirection != nullptr);
        assert(softWrap != nullptr);
        assert(overflow != nullptr);
        assert(textScaleFactor != nullptr);
        assert(maxLines == nullptr || maxLines > 0);
        assert(textWidthBasis != nullptr);
        _softWrap = softWrap;
        _overflow = overflow;
        _selectionColor = selectionColor;
        _textPainter = TextPainter(text, textAlign, textDirection, textScaleFactor, maxLines, overflow == TextOverflow.ellipsis? _kEllipsis : nullptr, locale, strutStyle, textWidthBasis, textHeightBehavior);
    }
    {
        addAll(children);
        _extractPlaceholderSpans(text);
        this.registrar = registrar;
    }
}

void RenderParagraph::setupParentData(RenderBox child) {
    if (child.parentData is! TextParentData) {
        child.parentData = TextParentData();
    }
}

InlineSpan RenderParagraph::text() {
    return _textPainter.text!;
}

void RenderParagraph::text(InlineSpan value) {
    assert(value != nullptr);
    ;
    _removeSelectionRegistrarSubscription();
    _disposeSelectableFragments();
    _updateSelectionRegistrarSubscription();
}

List<TextSelection> RenderParagraph::selections() {
    if (_lastSelectableFragments == nullptr) {
        return const ;
    }
    List<TextSelection> results = ;
    for (_SelectableFragment fragment : _lastSelectableFragments!) {
        if (fragment._textSelectionStart != nullptr && fragment._textSelectionEnd != nullptr && fragment._textSelectionStart!.offset != fragment._textSelectionEnd!.offset) {
            results.add(TextSelection(fragment._textSelectionStart!.offset, fragment._textSelectionEnd!.offset));
        }
    }
    return results;
}

SelectionRegistrar RenderParagraph::registrar() {
    return _registrar;
}

void RenderParagraph::registrar(SelectionRegistrar value) {
    if (value == _registrar) {
        return;
    }
    _removeSelectionRegistrarSubscription();
    _disposeSelectableFragments();
    _registrar = value;
    _updateSelectionRegistrarSubscription();
}

void RenderParagraph::markNeedsLayout() {
    _lastSelectableFragments?.forEach();
    super.markNeedsLayout();
}

void RenderParagraph::dispose() {
    _removeSelectionRegistrarSubscription();
    _lastSelectableFragments = nullptr;
    super.dispose();
}

TextAlign RenderParagraph::textAlign() {
    return _textPainter.textAlign;
}

void RenderParagraph::textAlign(TextAlign value) {
    assert(value != nullptr);
    if (_textPainter.textAlign == value) {
        return;
    }
    _textPainter.textAlign = value;
    markNeedsPaint();
}

TextDirection RenderParagraph::textDirection() {
    return _textPainter.textDirection!;
}

void RenderParagraph::textDirection(TextDirection value) {
    assert(value != nullptr);
    if (_textPainter.textDirection == value) {
        return;
    }
    _textPainter.textDirection = value;
    markNeedsLayout();
}

bool RenderParagraph::softWrap() {
    return _softWrap;
}

void RenderParagraph::softWrap(bool value) {
    assert(value != nullptr);
    if (_softWrap == value) {
        return;
    }
    _softWrap = value;
    markNeedsLayout();
}

TextOverflow RenderParagraph::overflow() {
    return _overflow;
}

void RenderParagraph::overflow(TextOverflow value) {
    assert(value != nullptr);
    if (_overflow == value) {
        return;
    }
    _overflow = value;
    _textPainter.ellipsis = value == TextOverflow.ellipsis? _kEllipsis : nullptr;
    markNeedsLayout();
}

double RenderParagraph::textScaleFactor() {
    return _textPainter.textScaleFactor;
}

void RenderParagraph::textScaleFactor(double value) {
    assert(value != nullptr);
    if (_textPainter.textScaleFactor == value) {
        return;
    }
    _textPainter.textScaleFactor = value;
    _overflowShader = nullptr;
    markNeedsLayout();
}

int RenderParagraph::maxLines() {
    return _textPainter.maxLines;
}

void RenderParagraph::maxLines(int value) {
    assert(value == nullptr || value > 0);
    if (_textPainter.maxLines == value) {
        return;
    }
    _textPainter.maxLines = value;
    _overflowShader = nullptr;
    markNeedsLayout();
}

Locale RenderParagraph::locale() {
    return _textPainter.locale;
}

void RenderParagraph::locale(Locale value) {
    if (_textPainter.locale == value) {
        return;
    }
    _textPainter.locale = value;
    _overflowShader = nullptr;
    markNeedsLayout();
}

StrutStyle RenderParagraph::strutStyle() {
    return _textPainter.strutStyle;
}

void RenderParagraph::strutStyle(StrutStyle value) {
    if (_textPainter.strutStyle == value) {
        return;
    }
    _textPainter.strutStyle = value;
    _overflowShader = nullptr;
    markNeedsLayout();
}

TextWidthBasis RenderParagraph::textWidthBasis() {
    return _textPainter.textWidthBasis;
}

void RenderParagraph::textWidthBasis(TextWidthBasis value) {
    assert(value != nullptr);
    if (_textPainter.textWidthBasis == value) {
        return;
    }
    _textPainter.textWidthBasis = value;
    _overflowShader = nullptr;
    markNeedsLayout();
}

TextHeightBehavior RenderParagraph::textHeightBehavior() {
    return _textPainter.textHeightBehavior;
}

void RenderParagraph::textHeightBehavior(TextHeightBehavior value) {
    if (_textPainter.textHeightBehavior == value) {
        return;
    }
    _textPainter.textHeightBehavior = value;
    _overflowShader = nullptr;
    markNeedsLayout();
}

Color RenderParagraph::selectionColor() {
    return _selectionColor;
}

void RenderParagraph::selectionColor(Color value) {
    if (_selectionColor == value) {
        return;
    }
    _selectionColor = value;
    if (_lastSelectableFragments?.any() ?? false) {
        markNeedsPaint();
    }
}

double RenderParagraph::computeMinIntrinsicWidth(double height) {
    if (!_canComputeIntrinsics()) {
        return 0.0;
    }
    _computeChildrenWidthWithMinIntrinsics(height);
    _layoutText();
    return _textPainter.minIntrinsicWidth;
}

double RenderParagraph::computeMaxIntrinsicWidth(double height) {
    if (!_canComputeIntrinsics()) {
        return 0.0;
    }
    _computeChildrenWidthWithMaxIntrinsics(height);
    _layoutText();
    return _textPainter.maxIntrinsicWidth;
}

double RenderParagraph::computeMinIntrinsicHeight(double width) {
    return _computeIntrinsicHeight(width);
}

double RenderParagraph::computeMaxIntrinsicHeight(double width) {
    return _computeIntrinsicHeight(width);
}

double RenderParagraph::computeDistanceToActualBaseline(TextBaseline baseline) {
    assert(!debugNeedsLayout);
    assert(constraints != nullptr);
    assert(constraints.debugAssertIsValid());
    _layoutTextWithConstraints(constraints);
    return _textPainter.computeDistanceToActualBaseline(TextBaseline.alphabetic);
}

bool RenderParagraph::hitTestSelf(Offset position) {
    return true;
}

bool RenderParagraph::hitTestChildren(Offset position, BoxHitTestResult result) {
    bool hitText = false;
    TextPosition textPosition = _textPainter.getPositionForOffset(position);
    InlineSpan span = _textPainter.text!.getSpanForPosition(textPosition);
    if (span != nullptr && span is HitTestTarget) {
        result.add(HitTestEntry(());
        hitText = true;
    }
    RenderBox child = firstChild;
    int childIndex = 0;
    while (child != nullptr &&  < _textPainter.inlinePlaceholderBoxes!.length) {
        TextParentData textParentData = (;
        Matrix4 transform = ;
        bool isHit = result.addWithPaintTransform(transform, position, );
        if (isHit) {
            return true;
        }
        child = childAfter(child);
        childIndex = 1;
    }
    return hitText;
}

bool RenderParagraph::debugHasOverflowShader() {
    return _overflowShader != nullptr;
}

void RenderParagraph::systemFontsDidChange() {
    super.systemFontsDidChange();
    _textPainter.markNeedsLayout();
}

Size RenderParagraph::computeDryLayout(BoxConstraints constraints) {
    if (!_canComputeDryLayout()) {
        assert(debugCannotComputeDryLayout("Dry layout not available for alignments that require baseline."));
        return Size.zero;
    }
    _textPainter.setPlaceholderDimensions(_layoutChildren(constraintstrue));
    _layoutText(constraints.minWidth, constraints.maxWidth);
    return constraints.constrain(_textPainter.size);
}

void RenderParagraph::performLayout() {
    BoxConstraints constraints = this.constraints;
    _placeholderDimensions = _layoutChildren(constraints);
    _layoutTextWithConstraints(constraints);
    _setParentData();
    Size textSize = _textPainter.size;
    bool textDidExceedMaxLines = _textPainter.didExceedMaxLines;
    size = constraints.constrain(textSize);
    bool didOverflowHeight = size.height < textSize.height || textDidExceedMaxLines;
    bool didOverflowWidth = size.width < textSize.width;
    bool hasVisualOverflow = didOverflowWidth || didOverflowHeight;
    if (hasVisualOverflow) {
        ;
    } else {
        _needsClipping = false;
        _overflowShader = nullptr;
    }
}

void RenderParagraph::paint(PaintingContext context, Offset offset) {
    _layoutTextWithConstraints(constraints);
    assert(());
    if (_needsClipping) {
        Rect bounds = offset & size;
        if (_overflowShader != nullptr) {
            context.canvas.saveLayer(bounds, Paint());
        } else {
            context.canvas.save();
        }
        context.canvas.clipRect(bounds);
    }
    _textPainter.paint(context.canvas, offset);
    RenderBox child = firstChild;
    int childIndex = 0;
    while (child != nullptr &&  < _textPainter.inlinePlaceholderBoxes!.length) {
        TextParentData textParentData = (;
        double scale = textParentData.scale!;
        context.pushTransform(needsCompositing, offset + textParentData.offset, Matrix4.diagonal3Values(scale, scale, scale), );
        child = childAfter(child);
        childIndex = 1;
    }
    if (_needsClipping) {
        if (_overflowShader != nullptr) {
            context.canvas.translate(offset.dx, offset.dy);
            Paint paint = ;
            context.canvas.drawRect(Offset.zero & size, paint);
        }
        context.canvas.restore();
    }
    if (_lastSelectableFragments != nullptr) {
        for (_SelectableFragment fragment : _lastSelectableFragments!) {
            fragment.paint(context, offset);
        }
    }
    super.paint(context, offset);
}

Offset RenderParagraph::getOffsetForCaret(Rect caretPrototype, TextPosition position) {
    assert(!debugNeedsLayout);
    _layoutTextWithConstraints(constraints);
    return _textPainter.getOffsetForCaret(position, caretPrototype);
}

double RenderParagraph::getFullHeightForCaret(TextPosition position) {
    assert(!debugNeedsLayout);
    _layoutTextWithConstraints(constraints);
    return _textPainter.getFullHeightForCaret(position, Rect.zero);
}

List<TextBox> RenderParagraph::getBoxesForSelection(BoxHeightStyle boxHeightStyle, BoxWidthStyle boxWidthStyle, TextSelection selection) {
    assert(!debugNeedsLayout);
    assert(boxHeightStyle != nullptr);
    assert(boxWidthStyle != nullptr);
    _layoutTextWithConstraints(constraints);
    return _textPainter.getBoxesForSelection(selectionboxHeightStyle, boxWidthStyle);
}

TextPosition RenderParagraph::getPositionForOffset(Offset offset) {
    assert(!debugNeedsLayout);
    _layoutTextWithConstraints(constraints);
    return _textPainter.getPositionForOffset(offset);
}

TextRange RenderParagraph::getWordBoundary(TextPosition position) {
    assert(!debugNeedsLayout);
    _layoutTextWithConstraints(constraints);
    return _textPainter.getWordBoundary(position);
}

Size RenderParagraph::textSize() {
    assert(!debugNeedsLayout);
    return _textPainter.size;
}

void RenderParagraph::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    _semanticsInfo = text.getSemanticsInformation();
    if (_semanticsInfo!.any()) {
        config.explicitChildNodes = true;
        config.isSemanticBoundary = true;
    } else {
        if (_cachedAttributedLabel == nullptr) {
            StringBuffer buffer = StringBuffer();
            int offset = 0;
            List<StringAttribute> attributes = ;
            for (InlineSpanSemanticsInformation info : _semanticsInfo!) {
                String label = info.semanticsLabel ?? info.text;
                for (StringAttribute infoAttribute : info.stringAttributes) {
                    TextRange originalRange = infoAttribute.range;
                    attributes.add(infoAttribute.copy(TextRange(offset + originalRange.start, offset + originalRange.end)));
                }
                buffer.write(label);
                offset = label.length;
            }
            _cachedAttributedLabel = AttributedString(buffer.toString()attributes);
        }
        config.attributedLabel = _cachedAttributedLabel!;
        config.textDirection = textDirection;
    }
}

void RenderParagraph::assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node) {
    assert(_semanticsInfo != nullptr && _semanticsInfo!.isNotEmpty);
    List<SemanticsNode> newChildren = ;
    TextDirection currentDirection = textDirection;
    Rect currentRect;
    double ordinal = 0.0;
    int start = 0;
    int placeholderIndex = 0;
    int childIndex = 0;
    RenderBox child = firstChild;
    LinkedHashMap<Key, SemanticsNode> newChildCache = <Key, SemanticsNode>LinkedHashMap();
    _cachedCombinedSemanticsInfos = combineSemanticsInfo(_semanticsInfo!);
    for (InlineSpanSemanticsInformation info : _cachedCombinedSemanticsInfos!) {
        TextSelection selection = TextSelection(start, start + info.text.length);
        start = info.text.length;
        if (info.isPlaceholder) {
            while (children.length > childIndex && children.elementAt(childIndex).isTagged(PlaceholderSpanIndexSemanticsTag(placeholderIndex))) {
                SemanticsNode childNode = children.elementAt(childIndex);
                TextParentData parentData = (;
                assert(parentData.scale != nullptr || parentData.offset == Offset.zero);
                if (parentData.scale != nullptr) {
                    childNode.rect = Rect.fromLTWH(childNode.rect.left, childNode.rect.top, childNode.rect.width * parentData.scale!, childNode.rect.height * parentData.scale!);
                    newChildren.add(childNode);
                }
                childIndex = 1;
            }
            child = childAfter(child!);
            placeholderIndex = 1;
        } else {
            TextDirection initialDirection = currentDirection;
            List<TextBox> rects = getBoxesForSelection(selection);
            if (rects.isEmpty) {
                continue;
            }
            Rect rect = rects.first.toRect();
            currentDirection = rects.first.direction;
            for (TextBox textBox : rects.skip(1)) {
                rect = rect.expandToInclude(textBox.toRect());
                currentDirection = textBox.direction;
            }
            rect = Rect.fromLTWH(math.max(0.0, rect.left), math.max(0.0, rect.top), math.min(rect.width, constraints.maxWidth), math.min(rect.height, constraints.maxHeight));
            currentRect = Rect.fromLTRB(rect.left.floorToDouble() - 4.0, rect.top.floorToDouble() - 4.0, rect.right.ceilToDouble() + 4.0, rect.bottom.ceilToDouble() + 4.0);
            SemanticsConfiguration configuration = ;
            GestureRecognizer recognizer = info.recognizer;
            if (recognizer != nullptr) {
                if (recognizer is TapGestureRecognizer) {
                    if (recognizer.onTap != nullptr) {
                        configuration.onTap = recognizer.onTap;
                        configuration.isLink = true;
                    }
                } else                 {
                    if (recognizer is DoubleTapGestureRecognizer) {
                    if (recognizer.onDoubleTap != nullptr) {
                        configuration.onTap = recognizer.onDoubleTap;
                        configuration.isLink = true;
                    }
                } else                 {
                    if (recognizer is LongPressGestureRecognizer) {
                    if (recognizer.onLongPress != nullptr) {
                        configuration.onLongPress = recognizer.onLongPress;
                    }
                } else {
                    assert(false, "${recognizer.runtimeType} is not supported.");
                }
;
                };
                }            }
            if (node.parentPaintClipRect != nullptr) {
                Rect paintRect = node.parentPaintClipRect!.intersect(currentRect);
                configuration.isHidden = paintRect.isEmpty && !currentRect.isEmpty;
            }
            SemanticsNode newChild;
            if (_cachedChildNodes?.isNotEmpty ?? false) {
                newChild = _cachedChildNodes!.remove(_cachedChildNodes!.keys.first)!;
            } else {
                UniqueKey key = UniqueKey();
                newChild = SemanticsNode(key, _createShowOnScreenFor(key));
            }
            ;
            newChildCache[newChild.key!] = newChild;
            newChildren.add(newChild);
        }
    }
    assert(childIndex == children.length);
    assert(child == nullptr);
    _cachedChildNodes = newChildCache;
    node.updateWith(config, newChildren);
}

void RenderParagraph::clearSemantics() {
    super.clearSemantics();
    _cachedChildNodes = nullptr;
}

List<DiagnosticsNode> RenderParagraph::debugDescribeChildren() {
    return ;
}

void RenderParagraph::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<TextAlign>EnumProperty("textAlign", textAlign));
    properties.add(<TextDirection>EnumProperty("textDirection", textDirection));
    properties.add(FlagProperty("softWrap"softWrap, "wrapping at box width", "no wrapping except at line break characters", true));
    properties.add(<TextOverflow>EnumProperty("overflow", overflow));
    properties.add(DoubleProperty("textScaleFactor", textScaleFactor1.0));
    properties.add(<Locale>DiagnosticsProperty("locale", localenullptr));
    properties.add(IntProperty("maxLines", maxLines"unlimited"));
}

void RenderParagraph::_updateSelectionRegistrarSubscription() {
    if (_registrar == nullptr) {
        return;
    }
    _lastSelectableFragments = _getSelectableFragments();
    _lastSelectableFragments!.forEach(_registrar!.add);
}

void RenderParagraph::_removeSelectionRegistrarSubscription() {
    if (_registrar == nullptr || _lastSelectableFragments == nullptr) {
        return;
    }
    _lastSelectableFragments!.forEach(_registrar!.remove);
}

List<_SelectableFragment> RenderParagraph::_getSelectableFragments() {
    String plainText = text.toPlainText(false);
    List<_SelectableFragment> result = ;
    int start = 0;
    while ( < plainText.length) {
        int end = plainText.indexOf(_placeholderCharacter, start);
        if (start != end) {
            if (end == -1) {
                end = plainText.length;
            }
            result.add(_SelectableFragment(this, TextRange(start, end)));
            start = end;
        }
        start = 1;
    }
    return result;
}

void RenderParagraph::_disposeSelectableFragments() {
    if (_lastSelectableFragments == nullptr) {
        return;
    }
    for (_SelectableFragment fragment : _lastSelectableFragments!) {
        fragment.dispose();
    }
    _lastSelectableFragments = nullptr;
}

void RenderParagraph::_extractPlaceholderSpans(InlineSpan span) {
    _placeholderSpans = ;
    span.visitChildren();
}

Offset RenderParagraph::_getOffsetForPosition(TextPosition position) {
    return getOffsetForCaret(position, Rect.zero) + Offset(0, getFullHeightForCaret(position) ?? 0.0);
}

double RenderParagraph::_computeIntrinsicHeight(double width) {
    if (!_canComputeIntrinsics()) {
        return 0.0;
    }
    _computeChildrenHeightWithMinIntrinsics(width);
    _layoutText(width, width);
    return _textPainter.height;
}

bool RenderParagraph::_canComputeIntrinsics() {
    for (PlaceholderSpan span : _placeholderSpans) {
        ;
    }
    return true;
}

void RenderParagraph::_computeChildrenWidthWithMaxIntrinsics(double height) {
    RenderBox child = firstChild;
    List<PlaceholderDimensions> placeholderDimensions = <PlaceholderDimensions>filled(childCount, PlaceholderDimensions.empty);
    int childIndex = 0;
    while (child != nullptr) {
        placeholderDimensions[childIndex] = PlaceholderDimensions(Size(child.getMaxIntrinsicWidth(double.infinity), 0.0), _placeholderSpans[childIndex].alignment, _placeholderSpans[childIndex].baseline);
        child = childAfter(child);
        childIndex = 1;
    }
    _textPainter.setPlaceholderDimensions(placeholderDimensions);
}

void RenderParagraph::_computeChildrenWidthWithMinIntrinsics(double height) {
    RenderBox child = firstChild;
    List<PlaceholderDimensions> placeholderDimensions = <PlaceholderDimensions>filled(childCount, PlaceholderDimensions.empty);
    int childIndex = 0;
    while (child != nullptr) {
        placeholderDimensions[childIndex] = PlaceholderDimensions(Size(child.getMinIntrinsicWidth(double.infinity), 0.0), _placeholderSpans[childIndex].alignment, _placeholderSpans[childIndex].baseline);
        child = childAfter(child);
        childIndex = 1;
    }
    _textPainter.setPlaceholderDimensions(placeholderDimensions);
}

void RenderParagraph::_computeChildrenHeightWithMinIntrinsics(double width) {
    RenderBox child = firstChild;
    List<PlaceholderDimensions> placeholderDimensions = <PlaceholderDimensions>filled(childCount, PlaceholderDimensions.empty);
    int childIndex = 0;
    width = width / textScaleFactor;
    while (child != nullptr) {
        Size size = child.getDryLayout(BoxConstraints(width));
        placeholderDimensions[childIndex] = PlaceholderDimensions(size, _placeholderSpans[childIndex].alignment, _placeholderSpans[childIndex].baseline);
        child = childAfter(child);
        childIndex = 1;
    }
    _textPainter.setPlaceholderDimensions(placeholderDimensions);
}

void RenderParagraph::_layoutText(double maxWidth, double minWidth) {
    bool widthMatters = softWrap || overflow == TextOverflow.ellipsis;
    _textPainter.layout(minWidth, widthMatters? maxWidth : double.infinity);
}

void RenderParagraph::_layoutTextWithConstraints(BoxConstraints constraints) {
    _textPainter.setPlaceholderDimensions(_placeholderDimensions);
    _layoutText(constraints.minWidth, constraints.maxWidth);
}

List<PlaceholderDimensions> RenderParagraph::_layoutChildren(BoxConstraints constraints, bool dry) {
    if (childCount == 0) {
        return ;
    }
    RenderBox child = firstChild;
    List<PlaceholderDimensions> placeholderDimensions = <PlaceholderDimensions>filled(childCount, PlaceholderDimensions.empty);
    int childIndex = 0;
    BoxConstraints boxConstraints = BoxConstraints(constraints.maxWidth);
    boxConstraints = boxConstraints / textScaleFactor;
    while (child != nullptr) {
        double baselineOffset;
        Size childSize;
        if (!dry) {
            child.layout(boxConstraintstrue);
            childSize = child.size;
            ;
        } else {
            assert(_placeholderSpans[childIndex].alignment != ui.PlaceholderAlignment.baseline);
            childSize = child.getDryLayout(boxConstraints);
        }
        placeholderDimensions[childIndex] = PlaceholderDimensions(childSize, _placeholderSpans[childIndex].alignment, _placeholderSpans[childIndex].baseline, baselineOffset);
        child = childAfter(child);
        childIndex = 1;
    }
    return placeholderDimensions;
}

void RenderParagraph::_setParentData() {
    RenderBox child = firstChild;
    int childIndex = 0;
    while (child != nullptr &&  < _textPainter.inlinePlaceholderBoxes!.length) {
        TextParentData textParentData = (;
        textParentData.offset = Offset(_textPainter.inlinePlaceholderBoxes![childIndex].left, _textPainter.inlinePlaceholderBoxes![childIndex].top);
        textParentData.scale = _textPainter.inlinePlaceholderScales![childIndex];
        child = childAfter(child);
        childIndex = 1;
    }
}

bool RenderParagraph::_canComputeDryLayout() {
    for (PlaceholderSpan span : _placeholderSpans) {
        ;
    }
    return true;
}

VoidCallback RenderParagraph::_createShowOnScreenFor(Key key) {
    return ;
}

SelectionGeometry _SelectableFragment::value() {
    return _selectionGeometry;
}

SelectionResult _SelectableFragment::dispatchSelectionEvent(SelectionEvent event) {
    SelectionResult result;
    TextPosition existingSelectionStart = _textSelectionStart;
    TextPosition existingSelectionEnd = _textSelectionEnd;
    ;
    if (existingSelectionStart != _textSelectionStart || existingSelectionEnd != _textSelectionEnd) {
        _didChangeSelection();
    }
    return result;
}

SelectedContent _SelectableFragment::getSelectedContent() {
    if (_textSelectionStart == nullptr || _textSelectionEnd == nullptr) {
        return nullptr;
    }
    int start = math.min(_textSelectionStart!.offset, _textSelectionEnd!.offset);
    int end = math.max(_textSelectionStart!.offset, _textSelectionEnd!.offset);
    return SelectedContent(paragraph.text.toPlainText(false).substring(start, end));
}

Matrix4 _SelectableFragment::getTransformToParagraph() {
    return Matrix4.translationValues(_rect.left, _rect.top, 0.0);
}

Matrix4 _SelectableFragment::getTransformTo(RenderObject ancestor) {
    return ;
}

void _SelectableFragment::pushHandleLayers(LayerLink endHandle, LayerLink startHandle) {
    if (!paragraph.attached) {
        assert(startHandle == nullptr && endHandle == nullptr, "Only clean up can be called.");
        return;
    }
    if (_startHandleLayerLink != startHandle) {
        _startHandleLayerLink = startHandle;
        paragraph.markNeedsPaint();
    }
    if (_endHandleLayerLink != endHandle) {
        _endHandleLayerLink = endHandle;
        paragraph.markNeedsPaint();
    }
}

void _SelectableFragment::didChangeParagraphLayout() {
    _cachedRect = nullptr;
}

Size _SelectableFragment::size() {
    return _rect.size;
}

void _SelectableFragment::paint(PaintingContext context, Offset offset) {
    if (_textSelectionStart == nullptr || _textSelectionEnd == nullptr) {
        return;
    }
    if (paragraph.selectionColor != nullptr) {
        TextSelection selection = TextSelection(_textSelectionStart!.offset, _textSelectionEnd!.offset);
        Paint selectionPaint = ;
        for (TextBox textBox : paragraph.getBoxesForSelection(selection)) {
            context.canvas.drawRect(textBox.toRect().shift(offset), selectionPaint);
        }
    }
    Matrix4 transform = getTransformToParagraph();
    if (_startHandleLayerLink != nullptr && value.startSelectionPoint != nullptr) {
        context.pushLayer(LeaderLayer(_startHandleLayerLink!, offset + MatrixUtils.transformPoint(transform, value.startSelectionPoint!.localPosition)), , Offset.zero);
    }
    if (_endHandleLayerLink != nullptr && value.endSelectionPoint != nullptr) {
        context.pushLayer(LeaderLayer(_endHandleLayerLink!, offset + MatrixUtils.transformPoint(transform, value.endSelectionPoint!.localPosition)), , Offset.zero);
    }
}

_SelectableFragment::_SelectableFragment(RenderParagraph paragraph, TextRange range) {
    {
        assert(range.isValid && !range.isCollapsed && range.isNormalized);
    }
    {
        _selectionGeometry = _getSelectionGeometry();
    }
}

void _SelectableFragment::_updateSelectionGeometry() {
    SelectionGeometry newValue = _getSelectionGeometry();
    if (_selectionGeometry == newValue) {
        return;
    }
    _selectionGeometry = newValue;
    notifyListeners();
}

SelectionGeometry _SelectableFragment::_getSelectionGeometry() {
    if (_textSelectionStart == nullptr || _textSelectionEnd == nullptr) {
        return const SelectionGeometry(SelectionStatus.none, true);
    }
    int selectionStart = _textSelectionStart!.offset;
    int selectionEnd = _textSelectionEnd!.offset;
    bool isReversed = selectionStart > selectionEnd;
    Offset startOffsetInParagraphCoordinates = paragraph._getOffsetForPosition(TextPosition(selectionStart));
    Offset endOffsetInParagraphCoordinates = selectionStart == selectionEnd? startOffsetInParagraphCoordinates : paragraph._getOffsetForPosition(TextPosition(selectionEnd));
    bool flipHandles = isReversed != (TextDirection.rtl == paragraph.textDirection);
    Matrix4 paragraphToFragmentTransform = ;
    return SelectionGeometry(SelectionPoint(MatrixUtils.transformPoint(paragraphToFragmentTransform, startOffsetInParagraphCoordinates), paragraph._textPainter.preferredLineHeight, flipHandles? TextSelectionHandleType.right : TextSelectionHandleType.left), SelectionPoint(MatrixUtils.transformPoint(paragraphToFragmentTransform, endOffsetInParagraphCoordinates), paragraph._textPainter.preferredLineHeight, flipHandles? TextSelectionHandleType.left : TextSelectionHandleType.right), _textSelectionStart!.offset == _textSelectionEnd!.offset? SelectionStatus.collapsed : SelectionStatus.uncollapsed, true);
}

void _SelectableFragment::_didChangeSelection() {
    paragraph.markNeedsPaint();
    _updateSelectionGeometry();
}

SelectionResult _SelectableFragment::_updateSelectionEdge(Offset globalPosition, bool isEnd) {
    _setSelectionPosition(nullptrisEnd);
    Matrix4 transform = paragraph.getTransformTo(nullptr);
    transform.invert();
    Offset localPosition = MatrixUtils.transformPoint(transform, globalPosition);
    if (_rect.isEmpty) {
        return SelectionUtils.getResultBasedOnRect(_rect, localPosition);
    }
    Offset adjustedOffset = SelectionUtils.adjustDragOffset(_rect, localPositionparagraph.textDirection);
    TextPosition position = _clampTextPosition(paragraph.getPositionForOffset(adjustedOffset));
    _setSelectionPosition(positionisEnd);
    if (position.offset == range.end) {
        return SelectionResult.next;
    }
    if (position.offset == range.start) {
        return SelectionResult.previous;
    }
    return SelectionUtils.getResultBasedOnRect(_rect, localPosition);
}

TextPosition _SelectableFragment::_clampTextPosition(TextPosition position) {
    if (position.offset > range.end || (position.offset == range.end && position.affinity == TextAffinity.downstream)) {
        return TextPosition(range.end, TextAffinity.upstream);
    }
    if (position.offset < range.start) {
        return TextPosition(range.start);
    }
    return position;
}

void _SelectableFragment::_setSelectionPosition(bool isEnd, TextPosition position) {
    if (isEnd) {
        _textSelectionEnd = position;
    } else {
        _textSelectionStart = position;
    }
}

SelectionResult _SelectableFragment::_handleClearSelection() {
    _textSelectionStart = nullptr;
    _textSelectionEnd = nullptr;
    return SelectionResult.none;
}

SelectionResult _SelectableFragment::_handleSelectAll() {
    _textSelectionStart = TextPosition(range.start);
    _textSelectionEnd = TextPosition(range.end, TextAffinity.upstream);
    return SelectionResult.none;
}

SelectionResult _SelectableFragment::_handleSelectWord(Offset globalPosition) {
    TextPosition position = paragraph.getPositionForOffset(paragraph.globalToLocal(globalPosition));
    if (_positionIsWithinCurrentSelection(position)) {
        return SelectionResult.end;
    }
    TextRange word = paragraph.getWordBoundary(position);
    assert(word.isNormalized);
    assert(word.start >= range.start && word.end <= range.end);
    TextPosition start;
    TextPosition end;
    if (position.offset >= word.end) {
        start = end = TextPosition(position.offset);
    } else {
        start = TextPosition(word.start);
        end = TextPosition(word.end, TextAffinity.upstream);
    }
    _textSelectionStart = start;
    _textSelectionEnd = end;
    return SelectionResult.end;
}

bool _SelectableFragment::_positionIsWithinCurrentSelection(TextPosition position) {
    if (_textSelectionStart == nullptr || _textSelectionEnd == nullptr) {
        return false;
    }
    TextPosition currentStart;
    TextPosition currentEnd;
    if (_compareTextPositions(_textSelectionStart!, _textSelectionEnd!) > 0) {
        currentStart = _textSelectionStart!;
        currentEnd = _textSelectionEnd!;
    } else {
        currentStart = _textSelectionEnd!;
        currentEnd = _textSelectionStart!;
    }
    return _compareTextPositions(currentStart, position) >= 0 && _compareTextPositions(currentEnd, position) <= 0;
}

int _SelectableFragment::_compareTextPositions(TextPosition otherPosition, TextPosition position) {
    if (position.offset < otherPosition.offset) {
        return 1;
    } else     {
        if (position.offset > otherPosition.offset) {
        return -1;
    } else     {
        if (position.affinity == otherPosition.affinity) {
        return 0;
    } else {
        return position.affinity == TextAffinity.upstream? 1 : -1;
    }
;
    };
    }}

Rect _SelectableFragment::_rect() {
    if (_cachedRect == nullptr) {
        List<TextBox> boxes = paragraph.getBoxesForSelection(TextSelection(range.start, range.end));
        if (boxes.isNotEmpty) {
            Rect result = boxes.first.toRect();
            for (;  < boxes.length; index = 1) {
                result = result.expandToInclude(boxes[index].toRect());
            }
            _cachedRect = result;
        } else {
            Offset offset = paragraph._getOffsetForPosition(TextPosition(range.start));
            _cachedRect = Rect.fromPoints(offset, offset.translate(0, -paragraph._textPainter.preferredLineHeight));
        }
    }
    return _cachedRect!;
}
