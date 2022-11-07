#ifndef EDITABLE_H
#define EDITABLE_H
#include <memory>

#include <collection/collection.hpp>
#include <math/math.hpp>
#include <ui/ui.hpp>
#include <characters/characters.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/semantics.hpp>
#include <flutter/services.hpp>
#include "box.hpp"
#include "custom_paint.hpp"
#include "layer.hpp"
#include "object.hpp"
#include "paragraph.hpp"
#include "viewport_offset.hpp"


const double _kCaretGap;

const double _kCaretHeightOffset;

const EdgeInsets _kFloatingCaretSizeIncrease;

const Radius _kFloatingCaretRadius;


class TextSelectionPoint {
public:
    Offset point;

    TextDirection direction;


     TextSelectionPoint(TextDirection direction, Offset point);

    String toString();

private:

};

class VerticalCaretMovementRun : Iterator<TextPosition> {
public:

    bool isValid();

    TextPosition current();

    bool moveNext();

    bool movePrevious();

private:
    Offset _currentOffset;

    int _currentLine;

    TextPosition _currentTextPosition;

    List<LineMetrics> _lineMetrics;

    RenderEditable _editable;

    bool _isValid;

    Map<int, MapEntry<Offset, TextPosition>> _positionCache;


    void  _(int _currentLine, Offset _currentOffset, TextPosition _currentTextPosition, RenderEditable _editable, List<LineMetrics> _lineMetrics);

    MapEntry<Offset, TextPosition> _getTextPositionForLine(int lineNumber);

};

class RenderEditable : RenderBox {
public:
    CaretChangedHandler onCaretChanged;

    bool ignorePointer;

    TextSelectionDelegate textSelectionDelegate;

    EdgeInsets floatingCursorAddedMargin;


     RenderEditable(Color backgroundCursorColor, List<RenderBox> children, Clip clipBehavior, Color cursorColor, double cursorHeight, Offset cursorOffset, Radius cursorRadius, double cursorWidth, double devicePixelRatio, bool enableInteractiveSelection, LayerLink endHandleLayerLink, bool expands, EdgeInsets floatingCursorAddedMargin, bool forceLine, RenderEditablePainter foregroundPainter, bool hasFocus, bool ignorePointer, Locale locale, int maxLines, int minLines, bool obscureText, String obscuringCharacter, ViewportOffset offset, CaretChangedHandler onCaretChanged, bool paintCursorAboveText, RenderEditablePainter painter, Color promptRectColor, TextRange promptRectRange, bool readOnly, TextSelection selection, Color selectionColor, BoxHeightStyle selectionHeightStyle, BoxWidthStyle selectionWidthStyle, ValueNotifier<bool> showCursor, LayerLink startHandleLayerLink, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextSelectionDelegate textSelectionDelegate, TextWidthBasis textWidthBasis);

    void setupParentData(RenderBox child);

    void dispose();

    RenderEditablePainter foregroundPainter();

    void  foregroundPainter(RenderEditablePainter newPainter);

    RenderEditablePainter painter();

    void  painter(RenderEditablePainter newPainter);

    void debugAssertLayoutUpToDate();

    TextHeightBehavior textHeightBehavior();

    void  textHeightBehavior(TextHeightBehavior value);

    TextWidthBasis textWidthBasis();

    void  textWidthBasis(TextWidthBasis value);

    double devicePixelRatio();

    void  devicePixelRatio(double value);

    String obscuringCharacter();

    void  obscuringCharacter(String value);

    bool obscureText();

    void  obscureText(bool value);

    BoxHeightStyle selectionHeightStyle();

    void  selectionHeightStyle(BoxHeightStyle value);

    BoxWidthStyle selectionWidthStyle();

    void  selectionWidthStyle(BoxWidthStyle value);

    ValueListenable<bool> selectionStartInViewport();

    ValueListenable<bool> selectionEndInViewport();

    TextSelection getLineAtOffset(TextPosition position);

    TextRange getWordBoundary(TextPosition position);

    TextPosition getTextPositionAbove(TextPosition position);

    TextPosition getTextPositionBelow(TextPosition position);

    void markNeedsPaint();

    void markNeedsTextLayout();

    void systemFontsDidChange();

    InlineSpan text();

    void  text(InlineSpan value);

    TextAlign textAlign();

    void  textAlign(TextAlign value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    Locale locale();

    void  locale(Locale value);

    StrutStyle strutStyle();

    void  strutStyle(StrutStyle value);

    Color cursorColor();

    void  cursorColor(Color value);

    Color backgroundCursorColor();

    void  backgroundCursorColor(Color value);

    ValueNotifier<bool> showCursor();

    void  showCursor(ValueNotifier<bool> value);

    bool hasFocus();

    void  hasFocus(bool value);

    bool forceLine();

    void  forceLine(bool value);

    bool readOnly();

    void  readOnly(bool value);

    int maxLines();

    void  maxLines(int value);

    int minLines();

    void  minLines(int value);

    bool expands();

    void  expands(bool value);

    Color selectionColor();

    void  selectionColor(Color value);

    double textScaleFactor();

    void  textScaleFactor(double value);

    TextSelection selection();

    void  selection(TextSelection value);

    ViewportOffset offset();

    void  offset(ViewportOffset value);

    double cursorWidth();

    void  cursorWidth(double value);

    double cursorHeight();

    void  cursorHeight(double value);

    bool paintCursorAboveText();

    void  paintCursorAboveText(bool value);

    Offset cursorOffset();

    void  cursorOffset(Offset value);

    Radius cursorRadius();

    void  cursorRadius(Radius value);

    LayerLink startHandleLayerLink();

    void  startHandleLayerLink(LayerLink value);

    LayerLink endHandleLayerLink();

    void  endHandleLayerLink(LayerLink value);

    bool enableInteractiveSelection();

    void  enableInteractiveSelection(bool value);

    bool selectionEnabled();

    Color promptRectColor();

    void  promptRectColor(Color newValue);

    void setPromptRectRange(TextRange newRange);

    double maxScrollExtent();

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    List<Rect> getBoxesForSelection(TextSelection selection);

    void describeSemanticsConfiguration(SemanticsConfiguration config);

    void assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node);

    void attach(PipelineOwner owner);

    void detach();

    void redepthChildren();

    void visitChildren(RenderObjectVisitor visitor);

    List<TextSelectionPoint> getEndpointsForSelection(TextSelection selection);

    Rect getRectForComposingRange(TextRange range);

    TextPosition getPositionForPoint(Offset globalPosition);

    Rect getLocalRectForCaret(TextPosition caretPosition);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double preferredLineHeight();

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    double computeDistanceToActualBaseline(TextBaseline baseline);

    bool hitTestSelf(Offset position);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void handleEvent(BoxHitTestEntry entry, PointerEvent event);

    Offset lastSecondaryTapDownPosition();

    void handleSecondaryTapDown(TapDownDetails details);

    void handleTapDown(TapDownDetails details);

    void handleTap();

    void handleDoubleTap();

    void handleLongPress();

    void selectPosition(SelectionChangedCause cause);

    void selectPositionAt(SelectionChangedCause cause, Offset from, Offset to);

    void selectWord(SelectionChangedCause cause);

    void selectWordsInRange(SelectionChangedCause cause, Offset from, Offset to);

    void selectWordEdge(SelectionChangedCause cause);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    Offset calculateBoundedFloatingCursorOffset(Offset rawCursorOffset);

    void setFloatingCursor(Offset boundedOffset, TextPosition lastTextPosition, double resetLerpValue, FloatingCursorDragState state);

    VerticalCaretMovementRun startVerticalCaretMovement(TextPosition startPosition);

    void paint(PaintingContext context, Offset offset);

    Rect describeApproximatePaintClip(RenderObject child);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    List<DiagnosticsNode> debugDescribeChildren();

private:
    _RenderEditableCustomPaint _foregroundRenderObject;

    _RenderEditableCustomPaint _backgroundRenderObject;

    List<PlaceholderSpan> _placeholderSpans;

    RenderEditablePainter _foregroundPainter;

    RenderEditablePainter _painter;

    _FloatingCursorPainter _caretPainter;

    _TextHighlightPainter _selectionPainter;

    _TextHighlightPainter _autocorrectHighlightPainter;

    _CompositeRenderEditablePainter _cachedBuiltInForegroundPainters;

    _CompositeRenderEditablePainter _cachedBuiltInPainters;

    double _textLayoutLastMaxWidth;

    double _textLayoutLastMinWidth;

    Rect _lastCaretRect;

    double _devicePixelRatio;

    String _obscuringCharacter;

    bool _obscureText;

    ValueNotifier<bool> _selectionStartInViewport;

    ValueNotifier<bool> _selectionEndInViewport;

    String _cachedPlainText;

    TextPainter _textPainter;

    AttributedString _cachedAttributedValue;

    List<InlineSpanSemanticsInformation> _cachedCombinedSemanticsInfos;

    ValueNotifier<bool> _showCursor;

    bool _hasFocus;

    bool _forceLine;

    bool _readOnly;

    int _maxLines;

    int _minLines;

    bool _expands;

    TextSelection _selection;

    ViewportOffset _offset;

    double _cursorWidth;

    double _cursorHeight;

    bool _paintCursorOnTop;

    LayerLink _startHandleLayerLink;

    LayerLink _endHandleLayerLink;

    bool _floatingCursorOn;

    TextPosition _floatingCursorTextPosition;

    bool _enableInteractiveSelection;

    double _maxScrollExtent;

    Clip _clipBehavior;

    List<InlineSpanSemanticsInformation> _semanticsInfo;

    LinkedHashMap<Key, SemanticsNode> _cachedChildNodes;

    TapGestureRecognizer _tap;

    LongPressGestureRecognizer _longPress;

    Offset _lastTapDownPosition;

    Offset _lastSecondaryTapDownPosition;

    List<PlaceholderDimensions> _placeholderDimensions;

    Rect _caretPrototype;

    Offset _relativeOrigin;

    Offset _previousOffset;

    bool _resetOriginOnLeft;

    bool _resetOriginOnRight;

    bool _resetOriginOnTop;

    bool _resetOriginOnBottom;

    double _resetFloatingCursorAnimationValue;

    LayerHandle<ClipRectLayer> _clipRectLayer;


    void _updateForegroundPainter(RenderEditablePainter newPainter);

    void _extractPlaceholderSpans(InlineSpan span);

    void _updatePainter(RenderEditablePainter newPainter);

    _CompositeRenderEditablePainter _builtInForegroundPainters();

    _CompositeRenderEditablePainter _createBuiltInForegroundPainters();

    _CompositeRenderEditablePainter _builtInPainters();

    _CompositeRenderEditablePainter _createBuiltInPainters();

    void _onCaretChanged(Rect caretRect);

    TextPosition _getTextPositionVertical(TextPosition position, double verticalOffset);

    void _updateSelectionExtentsVisibility(Offset effectiveOffset);

    void _setTextEditingValue(SelectionChangedCause cause, TextEditingValue newValue);

    void _setSelection(SelectionChangedCause cause, TextSelection nextSelection);

    String _plainText();

    void _showHideCursor();

    double _caretMargin();

    void _handleSetText(String text);

    VoidCallback _createShowOnScreenFor(Key key);

    void _handleSetSelection(TextSelection selection);

    void _handleMoveCursorForwardByCharacter(bool extendSelection);

    void _handleMoveCursorBackwardByCharacter(bool extendSelection);

    void _handleMoveCursorForwardByWord(bool extendSelection);

    void _handleMoveCursorBackwardByWord(bool extendSelection);

    TextRange _getNextWord(int offset);

    TextRange _getPreviousWord(int offset);

    bool _onlyWhitespace(TextRange range);

    bool _isMultiline();

    Axis _viewportAxis();

    Offset _paintOffset();

    double _viewportExtent();

    double _getMaxScrollExtent(Size contentSize);

    bool _hasVisualOverflow();

    double _preferredHeight(double width);

    void _handleTapDown(TapDownDetails details);

    void _handleTap();

    void _handleLongPress();

    TextSelection _getWordAtOffset(TextPosition position);

    List<PlaceholderDimensions> _layoutChildren(BoxConstraints constraints, bool dry);

    void _setParentData();

    void _layoutText(double maxWidth, double minWidth);

    void _computeTextMetricsIfNeeded();

    void _computeCaretPrototype();

    Offset _snapToPhysicalPixel(Offset sourceOffset);

    bool _canComputeDryLayout();

    MapEntry<int, Offset> _lineNumberFor(List<LineMetrics> metrics, TextPosition startPosition);

    void _paintContents(PaintingContext context, Offset offset);

    void _paintHandleLayers(PaintingContext context, List<TextSelectionPoint> endpoints);

};

class _RenderEditableCustomPaint : RenderBox {
public:

    RenderEditable parent();

    bool isRepaintBoundary();

    bool sizedByParent();

    RenderEditablePainter painter();

    void  painter(RenderEditablePainter newValue);

    void paint(PaintingContext context, Offset offset);

    void attach(PipelineOwner owner);

    void detach();

    Size computeDryLayout(BoxConstraints constraints);

private:
    RenderEditablePainter _painter;


     _RenderEditableCustomPaint(RenderEditablePainter painter);

};

class RenderEditablePainter : ChangeNotifier {
public:

    bool shouldRepaint(RenderEditablePainter oldDelegate);

    void paint(Canvas canvas, RenderEditable renderEditable, Size size);

private:

};

class _TextHighlightPainter : RenderEditablePainter {
public:
    Paint highlightPaint;


    Color highlightColor();

    void  highlightColor(Color newValue);

    TextRange highlightedRange();

    void  highlightedRange(TextRange newValue);

    BoxHeightStyle selectionHeightStyle();

    void  selectionHeightStyle(BoxHeightStyle value);

    BoxWidthStyle selectionWidthStyle();

    void  selectionWidthStyle(BoxWidthStyle value);

    void paint(Canvas canvas, RenderEditable renderEditable, Size size);

    bool shouldRepaint(RenderEditablePainter oldDelegate);

private:
    Color _highlightColor;

    TextRange _highlightedRange;

    BoxHeightStyle _selectionHeightStyle;

    BoxWidthStyle _selectionWidthStyle;


     _TextHighlightPainter(Color highlightColor, TextRange highlightedRange);

};

class _FloatingCursorPainter : RenderEditablePainter {
public:
    CaretChangedHandler caretPaintCallback;

    bool showRegularCaret;

    Paint caretPaint;

    Paint floatingCursorPaint;


    bool shouldPaint();

    void  shouldPaint(bool value);

    Color caretColor();

    void  caretColor(Color value);

    Radius cursorRadius();

    void  cursorRadius(Radius value);

    Offset cursorOffset();

    void  cursorOffset(Offset value);

    Color backgroundCursorColor();

    void  backgroundCursorColor(Color value);

    Rect floatingCursorRect();

    void  floatingCursorRect(Rect value);

    void paintRegularCursor(Canvas canvas, Color caretColor, RenderEditable renderEditable, TextPosition textPosition);

    void paint(Canvas canvas, RenderEditable renderEditable, Size size);

    bool shouldRepaint(RenderEditablePainter oldDelegate);

private:
    bool _shouldPaint;

    Color _caretColor;

    Radius _cursorRadius;

    Offset _cursorOffset;

    Color _backgroundCursorColor;

    Rect _floatingCursorRect;


     _FloatingCursorPainter(CaretChangedHandler caretPaintCallback);

};

class _CompositeRenderEditablePainter : RenderEditablePainter {
public:
    List<RenderEditablePainter> painters;


    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void paint(Canvas canvas, RenderEditable renderEditable, Size size);

    bool shouldRepaint(RenderEditablePainter oldDelegate);

private:

     _CompositeRenderEditablePainter(List<RenderEditablePainter> painters);

};

#endif