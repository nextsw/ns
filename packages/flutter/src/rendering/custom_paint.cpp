#include "custom_paint.hpp"
CustomPainter::CustomPainter(Listenable repaint) {
    {
        _repaint = repaint;
    }
}

void CustomPainter::addListener(VoidCallback listener) {
    return _repaint?.addListener(listener);
}

void CustomPainter::removeListener(VoidCallback listener) {
    return _repaint?.removeListener(listener);
}

SemanticsBuilderCallback CustomPainter::semanticsBuilder() {
    return nullptr;
}

bool CustomPainter::shouldRebuildSemantics(CustomPainter oldDelegate) {
    return shouldRepaint(oldDelegate);
}

bool CustomPainter::hitTest(Offset position) {
    return nullptr;
}

String CustomPainter::toString() {
    return "${describeIdentity(this)}(${ _repaint?.toString() ?? "" })";
}

CustomPainterSemantics::CustomPainterSemantics(Key key, SemanticsProperties properties, Rect rect, Set<SemanticsTag> tags, Matrix4 transform) {
    {
        assert(rect != nullptr);
        assert(properties != nullptr);
    }
}

RenderCustomPaint::RenderCustomPaint(RenderBox child, CustomPainter foregroundPainter, bool isComplex, CustomPainter painter, Size preferredSize, bool willChange) {
    {
        assert(preferredSize != nullptr);
        _painter = painter;
        _foregroundPainter = foregroundPainter;
        _preferredSize = preferredSize;
        super(child);
    }
}

CustomPainter RenderCustomPaint::painter() {
    return _painter;
}

void RenderCustomPaint::painter(CustomPainter value) {
    if (_painter == value) {
        return;
    }
    CustomPainter oldPainter = _painter;
    _painter = value;
    _didUpdatePainter(_painter, oldPainter);
}

CustomPainter RenderCustomPaint::foregroundPainter() {
    return _foregroundPainter;
}

void RenderCustomPaint::foregroundPainter(CustomPainter value) {
    if (_foregroundPainter == value) {
        return;
    }
    CustomPainter oldPainter = _foregroundPainter;
    _foregroundPainter = value;
    _didUpdatePainter(_foregroundPainter, oldPainter);
}

Size RenderCustomPaint::preferredSize() {
    return _preferredSize;
}

void RenderCustomPaint::preferredSize(Size value) {
    assert(value != nullptr);
    if (preferredSize == value) {
        return;
    }
    _preferredSize = value;
    markNeedsLayout();
}

double RenderCustomPaint::computeMinIntrinsicWidth(double height) {
    if (child == nullptr) {
        return preferredSize.width.isFinite? preferredSize.width : 0;
    }
    return super.computeMinIntrinsicWidth(height);
}

double RenderCustomPaint::computeMaxIntrinsicWidth(double height) {
    if (child == nullptr) {
        return preferredSize.width.isFinite? preferredSize.width : 0;
    }
    return super.computeMaxIntrinsicWidth(height);
}

double RenderCustomPaint::computeMinIntrinsicHeight(double width) {
    if (child == nullptr) {
        return preferredSize.height.isFinite? preferredSize.height : 0;
    }
    return super.computeMinIntrinsicHeight(width);
}

double RenderCustomPaint::computeMaxIntrinsicHeight(double width) {
    if (child == nullptr) {
        return preferredSize.height.isFinite? preferredSize.height : 0;
    }
    return super.computeMaxIntrinsicHeight(width);
}

void RenderCustomPaint::attach(PipelineOwner owner) {
    super.attach(owner);
    _painter?.addListener(markNeedsPaint);
    _foregroundPainter?.addListener(markNeedsPaint);
}

void RenderCustomPaint::detach() {
    _painter?.removeListener(markNeedsPaint);
    _foregroundPainter?.removeListener(markNeedsPaint);
    super.detach();
}

bool RenderCustomPaint::hitTestChildren(Offset position, BoxHitTestResult result) {
    if (_foregroundPainter != nullptr && (_foregroundPainter!.hitTest(position) ?? false)) {
        return true;
    }
    return super.hitTestChildren(resultposition);
}

bool RenderCustomPaint::hitTestSelf(Offset position) {
    return _painter != nullptr && (_painter!.hitTest(position) ?? true);
}

void RenderCustomPaint::performLayout() {
    super.performLayout();
    markNeedsSemanticsUpdate();
}

Size RenderCustomPaint::computeSizeForNoChild(BoxConstraints constraints) {
    return constraints.constrain(preferredSize);
}

void RenderCustomPaint::paint(PaintingContext context, Offset offset) {
    if (_painter != nullptr) {
        _paintWithPainter(context.canvas, offset, _painter!);
        _setRasterCacheHints(context);
    }
    super.paint(context, offset);
    if (_foregroundPainter != nullptr) {
        _paintWithPainter(context.canvas, offset, _foregroundPainter!);
        _setRasterCacheHints(context);
    }
}

void RenderCustomPaint::describeSemanticsConfiguration(SemanticsConfiguration config) {
    super.describeSemanticsConfiguration(config);
    _backgroundSemanticsBuilder = painter?.semanticsBuilder;
    _foregroundSemanticsBuilder = foregroundPainter?.semanticsBuilder;
    config.isSemanticBoundary = _backgroundSemanticsBuilder != nullptr || _foregroundSemanticsBuilder != nullptr;
}

void RenderCustomPaint::assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node) {
    assert(());
    List<CustomPainterSemantics> backgroundSemantics = _backgroundSemanticsBuilder != nullptr? _backgroundSemanticsBuilder!(size) : const ;
    _backgroundSemanticsNodes = _updateSemanticsChildren(_backgroundSemanticsNodes, backgroundSemantics);
    List<CustomPainterSemantics> foregroundSemantics = _foregroundSemanticsBuilder != nullptr? _foregroundSemanticsBuilder!(size) : const ;
    _foregroundSemanticsNodes = _updateSemanticsChildren(_foregroundSemanticsNodes, foregroundSemantics);
    bool hasBackgroundSemantics = _backgroundSemanticsNodes != nullptr && _backgroundSemanticsNodes!.isNotEmpty;
    bool hasForegroundSemantics = _foregroundSemanticsNodes != nullptr && _foregroundSemanticsNodes!.isNotEmpty;
    List<SemanticsNode> finalChildren = ;
    super.assembleSemanticsNode(node, config, finalChildren);
}

void RenderCustomPaint::clearSemantics() {
    super.clearSemantics();
    _backgroundSemanticsNodes = nullptr;
    _foregroundSemanticsNodes = nullptr;
}

void RenderCustomPaint::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(MessageProperty("painter", "$painter"));
    properties.add(MessageProperty("foregroundPainter", "$foregroundPainter"foregroundPainter != nullptr? DiagnosticLevel.info : DiagnosticLevel.fine));
    properties.add(<Size>DiagnosticsProperty("preferredSize", preferredSizeSize.zero));
    properties.add(<bool>DiagnosticsProperty("isComplex", isComplexfalse));
    properties.add(<bool>DiagnosticsProperty("willChange", willChangefalse));
}

void RenderCustomPaint::_didUpdatePainter(CustomPainter newPainter, CustomPainter oldPainter) {
    if (newPainter == nullptr) {
        assert(oldPainter != nullptr);
        markNeedsPaint();
    } else     {
        if (oldPainter == nullptr || newPainter.runtimeType != oldPainter.runtimeType || newPainter.shouldRepaint(oldPainter)) {
        markNeedsPaint();
    }
;
    }    if (attached) {
        oldPainter?.removeListener(markNeedsPaint);
        newPainter?.addListener(markNeedsPaint);
    }
    if (newPainter == nullptr) {
        assert(oldPainter != nullptr);
        if (attached) {
            markNeedsSemanticsUpdate();
        }
    } else     {
        if (oldPainter == nullptr || newPainter.runtimeType != oldPainter.runtimeType || newPainter.shouldRebuildSemantics(oldPainter)) {
        markNeedsSemanticsUpdate();
    }
;
    }}

void RenderCustomPaint::_paintWithPainter(Canvas canvas, Offset offset, CustomPainter painter) {
    int debugPreviousCanvasSaveCount;
    canvas.save();
    assert(());
    if (offset != Offset.zero) {
        canvas.translate(offset.dx, offset.dy);
    }
    painter.paint(canvas, size);
    assert(());
    canvas.restore();
}

void RenderCustomPaint::_setRasterCacheHints(PaintingContext context) {
    if (isComplex) {
        context.setIsComplexHint();
    }
    if (willChange) {
        context.setWillChangeHint();
    }
}

List<SemanticsNode> RenderCustomPaint::_updateSemanticsChildren(List<CustomPainterSemantics> newChildSemantics, List<SemanticsNode> oldSemantics) {
    oldSemantics = oldSemantics ?? const ;
    newChildSemantics = newChildSemantics ?? const ;
    assert(());
    int newChildrenTop = 0;
    int oldChildrenTop = 0;
    int newChildrenBottom = newChildSemantics.length - 1;
    int oldChildrenBottom = oldSemantics.length - 1;
    List<SemanticsNode> newChildren = <SemanticsNode>filled(newChildSemantics.length, nullptr);
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        SemanticsNode oldChild = oldSemantics[oldChildrenTop];
        CustomPainterSemantics newSemantics = newChildSemantics[newChildrenTop];
        if (!_canUpdateSemanticsChild(oldChild, newSemantics)) {
                        break;
        }
        SemanticsNode newChild = _updateSemanticsChild(oldChild, newSemantics);
        newChildren[newChildrenTop] = newChild;
        newChildrenTop = 1;
        oldChildrenTop = 1;
    }
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        SemanticsNode oldChild = oldSemantics[oldChildrenBottom];
        CustomPainterSemantics newChild = newChildSemantics[newChildrenBottom];
        if (!_canUpdateSemanticsChild(oldChild, newChild)) {
                        break;
        }
        oldChildrenBottom = 1;
        newChildrenBottom = 1;
    }
    bool haveOldChildren = oldChildrenTop <= oldChildrenBottom;
    Map<Key, SemanticsNode> oldKeyedChildren;
    if (haveOldChildren) {
        oldKeyedChildren = ;
        while (oldChildrenTop <= oldChildrenBottom) {
            SemanticsNode oldChild = oldSemantics[oldChildrenTop];
            if (oldChild.key != nullptr) {
                oldKeyedChildren[oldChild.key!] = oldChild;
            }
            oldChildrenTop = 1;
        }
    }
    while (newChildrenTop <= newChildrenBottom) {
        SemanticsNode oldChild;
        CustomPainterSemantics newSemantics = newChildSemantics[newChildrenTop];
        if (haveOldChildren) {
            Key key = newSemantics.key;
            if (key != nullptr) {
                oldChild = oldKeyedChildren[key];
                if (oldChild != nullptr) {
                    if (_canUpdateSemanticsChild(oldChild, newSemantics)) {
                        oldKeyedChildren.remove(key);
                    } else {
                        oldChild = nullptr;
                    }
                }
            }
        }
        assert(oldChild == nullptr || _canUpdateSemanticsChild(oldChild, newSemantics));
        SemanticsNode newChild = _updateSemanticsChild(oldChild, newSemantics);
        assert(oldChild == newChild || oldChild == nullptr);
        newChildren[newChildrenTop] = newChild;
        newChildrenTop = 1;
    }
    assert(oldChildrenTop == oldChildrenBottom + 1);
    assert(newChildrenTop == newChildrenBottom + 1);
    assert(newChildSemantics.length - newChildrenTop == oldSemantics.length - oldChildrenTop);
    newChildrenBottom = newChildSemantics.length - 1;
    oldChildrenBottom = oldSemantics.length - 1;
    while ((oldChildrenTop <= oldChildrenBottom) && (newChildrenTop <= newChildrenBottom)) {
        SemanticsNode oldChild = oldSemantics[oldChildrenTop];
        CustomPainterSemantics newSemantics = newChildSemantics[newChildrenTop];
        assert(_canUpdateSemanticsChild(oldChild, newSemantics));
        SemanticsNode newChild = _updateSemanticsChild(oldChild, newSemantics);
        assert(oldChild == newChild);
        newChildren[newChildrenTop] = newChild;
        newChildrenTop = 1;
        oldChildrenTop = 1;
    }
    assert(());
    return newChildren.<SemanticsNode>cast();
}

bool RenderCustomPaint::_canUpdateSemanticsChild(CustomPainterSemantics newSemantics, SemanticsNode oldChild) {
    return oldChild.key == newSemantics.key;
}

SemanticsNode RenderCustomPaint::_updateSemanticsChild(CustomPainterSemantics newSemantics, SemanticsNode oldChild) {
    assert(oldChild == nullptr || _canUpdateSemanticsChild(oldChild, newSemantics));
    SemanticsNode newChild = oldChild ?? SemanticsNode(newSemantics.key);
    SemanticsProperties properties = newSemantics.properties;
    SemanticsConfiguration config = SemanticsConfiguration();
    if (properties.sortKey != nullptr) {
        config.sortKey = properties.sortKey;
    }
    if (properties.checked != nullptr) {
        config.isChecked = properties.checked;
    }
    if (properties.selected != nullptr) {
        config.isSelected = properties.selected!;
    }
    if (properties.button != nullptr) {
        config.isButton = properties.button!;
    }
    if (properties.link != nullptr) {
        config.isLink = properties.link!;
    }
    if (properties.textField != nullptr) {
        config.isTextField = properties.textField!;
    }
    if (properties.slider != nullptr) {
        config.isSlider = properties.slider!;
    }
    if (properties.keyboardKey != nullptr) {
        config.isKeyboardKey = properties.keyboardKey!;
    }
    if (properties.readOnly != nullptr) {
        config.isReadOnly = properties.readOnly!;
    }
    if (properties.focusable != nullptr) {
        config.isFocusable = properties.focusable!;
    }
    if (properties.focused != nullptr) {
        config.isFocused = properties.focused!;
    }
    if (properties.enabled != nullptr) {
        config.isEnabled = properties.enabled;
    }
    if (properties.inMutuallyExclusiveGroup != nullptr) {
        config.isInMutuallyExclusiveGroup = properties.inMutuallyExclusiveGroup!;
    }
    if (properties.obscured != nullptr) {
        config.isObscured = properties.obscured!;
    }
    if (properties.multiline != nullptr) {
        config.isMultiline = properties.multiline!;
    }
    if (properties.hidden != nullptr) {
        config.isHidden = properties.hidden!;
    }
    if (properties.header != nullptr) {
        config.isHeader = properties.header!;
    }
    if (properties.scopesRoute != nullptr) {
        config.scopesRoute = properties.scopesRoute!;
    }
    if (properties.namesRoute != nullptr) {
        config.namesRoute = properties.namesRoute!;
    }
    if (properties.liveRegion != nullptr) {
        config.liveRegion = properties.liveRegion!;
    }
    if (properties.maxValueLength != nullptr) {
        config.maxValueLength = properties.maxValueLength;
    }
    if (properties.currentValueLength != nullptr) {
        config.currentValueLength = properties.currentValueLength;
    }
    if (properties.toggled != nullptr) {
        config.isToggled = properties.toggled;
    }
    if (properties.image != nullptr) {
        config.isImage = properties.image!;
    }
    if (properties.label != nullptr) {
        config.label = properties.label!;
    }
    if (properties.value != nullptr) {
        config.value = properties.value!;
    }
    if (properties.increasedValue != nullptr) {
        config.increasedValue = properties.increasedValue!;
    }
    if (properties.decreasedValue != nullptr) {
        config.decreasedValue = properties.decreasedValue!;
    }
    if (properties.hint != nullptr) {
        config.hint = properties.hint!;
    }
    if (properties.textDirection != nullptr) {
        config.textDirection = properties.textDirection;
    }
    if (properties.onTap != nullptr) {
        config.onTap = properties.onTap;
    }
    if (properties.onLongPress != nullptr) {
        config.onLongPress = properties.onLongPress;
    }
    if (properties.onScrollLeft != nullptr) {
        config.onScrollLeft = properties.onScrollLeft;
    }
    if (properties.onScrollRight != nullptr) {
        config.onScrollRight = properties.onScrollRight;
    }
    if (properties.onScrollUp != nullptr) {
        config.onScrollUp = properties.onScrollUp;
    }
    if (properties.onScrollDown != nullptr) {
        config.onScrollDown = properties.onScrollDown;
    }
    if (properties.onIncrease != nullptr) {
        config.onIncrease = properties.onIncrease;
    }
    if (properties.onDecrease != nullptr) {
        config.onDecrease = properties.onDecrease;
    }
    if (properties.onCopy != nullptr) {
        config.onCopy = properties.onCopy;
    }
    if (properties.onCut != nullptr) {
        config.onCut = properties.onCut;
    }
    if (properties.onPaste != nullptr) {
        config.onPaste = properties.onPaste;
    }
    if (properties.onMoveCursorForwardByCharacter != nullptr) {
        config.onMoveCursorForwardByCharacter = properties.onMoveCursorForwardByCharacter;
    }
    if (properties.onMoveCursorBackwardByCharacter != nullptr) {
        config.onMoveCursorBackwardByCharacter = properties.onMoveCursorBackwardByCharacter;
    }
    if (properties.onMoveCursorForwardByWord != nullptr) {
        config.onMoveCursorForwardByWord = properties.onMoveCursorForwardByWord;
    }
    if (properties.onMoveCursorBackwardByWord != nullptr) {
        config.onMoveCursorBackwardByWord = properties.onMoveCursorBackwardByWord;
    }
    if (properties.onSetSelection != nullptr) {
        config.onSetSelection = properties.onSetSelection;
    }
    if (properties.onSetText != nullptr) {
        config.onSetText = properties.onSetText;
    }
    if (properties.onDidGainAccessibilityFocus != nullptr) {
        config.onDidGainAccessibilityFocus = properties.onDidGainAccessibilityFocus;
    }
    if (properties.onDidLoseAccessibilityFocus != nullptr) {
        config.onDidLoseAccessibilityFocus = properties.onDidLoseAccessibilityFocus;
    }
    if (properties.onDismiss != nullptr) {
        config.onDismiss = properties.onDismiss;
    }
    newChild.updateWith(config, const );
    ;
    return newChild;
}
