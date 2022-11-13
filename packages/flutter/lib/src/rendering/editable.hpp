#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_EDITABLE
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_EDITABLE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/characters/characters.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "box.hpp"
#include "custom_paint.hpp"
#include "layer.hpp"
#include "object.hpp"
#include "paragraph.hpp"
#include "viewport_offset.hpp"

double _kCaretGap;

double _kCaretHeightOffset;

EdgeInsets _kFloatingCaretSizeIncrease;

Radius _kFloatingCaretRadius;


class TextSelectionPointCls : public ObjectCls {
public:
    Offset point;

    TextDirection direction;


     TextSelectionPointCls(Offset point, TextDirection direction);

    virtual String toString();

private:

};
using TextSelectionPoint = std::shared_ptr<TextSelectionPointCls>;

class VerticalCaretMovementRunCls : public IteratorCls<TextPosition> {
public:

    virtual bool isValid();

    virtual TextPosition current();

    virtual bool moveNext();

    virtual bool movePrevious();

private:
    Offset _currentOffset;

    int _currentLine;

    TextPosition _currentTextPosition;

    List<LineMetrics> _lineMetrics;

    RenderEditable _editable;

    bool _isValid;

    Map<int, MapEntry<Offset, TextPosition>> _positionCache;


    virtual void  _(Unknown _editable, Unknown _lineMetrics, Unknown _currentTextPosition, Unknown _currentLine, Unknown _currentOffset);
    virtual MapEntry<Offset, TextPosition> _getTextPositionForLine(int lineNumber);

};
using VerticalCaretMovementRun = std::shared_ptr<VerticalCaretMovementRunCls>;

class RenderEditableCls : public RenderBoxCls {
public:
    CaretChangedHandler onCaretChanged;

    bool ignorePointer;

    TextSelectionDelegate textSelectionDelegate;

    EdgeInsets floatingCursorAddedMargin;


     RenderEditableCls(Color backgroundCursorColor, List<RenderBox> children, Clip clipBehavior, Color cursorColor, double cursorHeight, Offset cursorOffset, Radius cursorRadius, double cursorWidth, double devicePixelRatio, bool enableInteractiveSelection, LayerLink endHandleLayerLink, bool expands, EdgeInsets floatingCursorAddedMargin, bool forceLine, RenderEditablePainter foregroundPainter, bool hasFocus, bool ignorePointer, Locale locale, int maxLines, int minLines, bool obscureText, String obscuringCharacter, ViewportOffset offset, CaretChangedHandler onCaretChanged, bool paintCursorAboveText, RenderEditablePainter painter, Color promptRectColor, TextRange promptRectRange, bool readOnly, TextSelection selection, Color selectionColor, BoxHeightStyle selectionHeightStyle, BoxWidthStyle selectionWidthStyle, ValueNotifier<bool> showCursor, LayerLink startHandleLayerLink, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextSelectionDelegate textSelectionDelegate, TextWidthBasis textWidthBasis);

    virtual void setupParentData(RenderBox child);

    virtual void dispose();

    virtual RenderEditablePainter foregroundPainter();

    virtual void  foregroundPainter(RenderEditablePainter newPainter);

    virtual RenderEditablePainter painter();

    virtual void  painter(RenderEditablePainter newPainter);

    virtual void debugAssertLayoutUpToDate();

    virtual TextHeightBehavior textHeightBehavior();

    virtual void  textHeightBehavior(TextHeightBehavior value);

    virtual TextWidthBasis textWidthBasis();

    virtual void  textWidthBasis(TextWidthBasis value);

    virtual double devicePixelRatio();

    virtual void  devicePixelRatio(double value);

    virtual String obscuringCharacter();

    virtual void  obscuringCharacter(String value);

    virtual bool obscureText();

    virtual void  obscureText(bool value);

    virtual BoxHeightStyle selectionHeightStyle();

    virtual void  selectionHeightStyle(BoxHeightStyle value);

    virtual BoxWidthStyle selectionWidthStyle();

    virtual void  selectionWidthStyle(BoxWidthStyle value);

    virtual ValueListenable<bool> selectionStartInViewport();

    virtual ValueListenable<bool> selectionEndInViewport();

    virtual TextSelection getLineAtOffset(TextPosition position);

    virtual TextRange getWordBoundary(TextPosition position);

    virtual TextPosition getTextPositionAbove(TextPosition position);

    virtual TextPosition getTextPositionBelow(TextPosition position);

    virtual void markNeedsPaint();

    virtual void markNeedsTextLayout();

    virtual void systemFontsDidChange();

    virtual InlineSpan text();

    virtual void  text(InlineSpan value);

    virtual TextAlign textAlign();

    virtual void  textAlign(TextAlign value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual Locale locale();

    virtual void  locale(Locale value);

    virtual StrutStyle strutStyle();

    virtual void  strutStyle(StrutStyle value);

    virtual Color cursorColor();

    virtual void  cursorColor(Color value);

    virtual Color backgroundCursorColor();

    virtual void  backgroundCursorColor(Color value);

    virtual ValueNotifier<bool> showCursor();

    virtual void  showCursor(ValueNotifier<bool> value);

    virtual bool hasFocus();

    virtual void  hasFocus(bool value);

    virtual bool forceLine();

    virtual void  forceLine(bool value);

    virtual bool readOnly();

    virtual void  readOnly(bool value);

    virtual int maxLines();

    virtual void  maxLines(int value);

    virtual int minLines();

    virtual void  minLines(int value);

    virtual bool expands();

    virtual void  expands(bool value);

    virtual Color selectionColor();

    virtual void  selectionColor(Color value);

    virtual double textScaleFactor();

    virtual void  textScaleFactor(double value);

    virtual TextSelection selection();

    virtual void  selection(TextSelection value);

    virtual ViewportOffset offset();

    virtual void  offset(ViewportOffset value);

    virtual double cursorWidth();

    virtual void  cursorWidth(double value);

    virtual double cursorHeight();

    virtual void  cursorHeight(double value);

    virtual bool paintCursorAboveText();

    virtual void  paintCursorAboveText(bool value);

    virtual Offset cursorOffset();

    virtual void  cursorOffset(Offset value);

    virtual Radius cursorRadius();

    virtual void  cursorRadius(Radius value);

    virtual LayerLink startHandleLayerLink();

    virtual void  startHandleLayerLink(LayerLink value);

    virtual LayerLink endHandleLayerLink();

    virtual void  endHandleLayerLink(LayerLink value);

    virtual bool enableInteractiveSelection();

    virtual void  enableInteractiveSelection(bool value);

    virtual bool selectionEnabled();

    virtual Color promptRectColor();

    virtual void  promptRectColor(Color newValue);

    virtual void setPromptRectRange(TextRange newRange);

    virtual double maxScrollExtent();

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual List<Rect> getBoxesForSelection(TextSelection selection);

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

    virtual void assembleSemanticsNode(SemanticsNode node, SemanticsConfiguration config, Iterable<SemanticsNode> children);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual void redepthChildren();

    virtual void visitChildren(RenderObjectVisitor visitor);

    virtual List<TextSelectionPoint> getEndpointsForSelection(TextSelection selection);

    virtual Rect getRectForComposingRange(TextRange range);

    virtual TextPosition getPositionForPoint(Offset globalPosition);

    virtual Rect getLocalRectForCaret(TextPosition caretPosition);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double preferredLineHeight();

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual bool hitTestSelf(Offset position);

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual void handleEvent(PointerEvent event, BoxHitTestEntry entry);

    virtual Offset lastSecondaryTapDownPosition();

    virtual void handleSecondaryTapDown(TapDownDetails details);

    virtual void handleTapDown(TapDownDetails details);

    virtual void handleTap();

    virtual void handleDoubleTap();

    virtual void handleLongPress();

    virtual void selectPosition(SelectionChangedCause cause);

    virtual void selectPositionAt(SelectionChangedCause cause, Offset from, Offset to);

    virtual void selectWord(SelectionChangedCause cause);

    virtual void selectWordsInRange(SelectionChangedCause cause, Offset from, Offset to);

    virtual void selectWordEdge(SelectionChangedCause cause);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual Offset calculateBoundedFloatingCursorOffset(Offset rawCursorOffset);

    virtual void setFloatingCursor(FloatingCursorDragState state, Offset boundedOffset, TextPosition lastTextPosition, double resetLerpValue);

    virtual VerticalCaretMovementRun startVerticalCaretMovement(TextPosition startPosition);

    virtual void paint(PaintingContext context, Offset offset);

    virtual Rect describeApproximatePaintClip(RenderObject child);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual List<DiagnosticsNode> debugDescribeChildren();

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


    virtual void _updateForegroundPainter(RenderEditablePainter newPainter);

    virtual void _extractPlaceholderSpans(InlineSpan span);

    virtual void _updatePainter(RenderEditablePainter newPainter);

    virtual _CompositeRenderEditablePainter _builtInForegroundPainters();

    virtual _CompositeRenderEditablePainter _createBuiltInForegroundPainters();

    virtual _CompositeRenderEditablePainter _builtInPainters();

    virtual _CompositeRenderEditablePainter _createBuiltInPainters();

    virtual void _onCaretChanged(Rect caretRect);

    virtual TextPosition _getTextPositionVertical(TextPosition position, double verticalOffset);

    virtual void _updateSelectionExtentsVisibility(Offset effectiveOffset);

    virtual void _setTextEditingValue(TextEditingValue newValue, SelectionChangedCause cause);

    virtual void _setSelection(TextSelection nextSelection, SelectionChangedCause cause);

    virtual String _plainText();

    virtual void _showHideCursor();

    virtual double _caretMargin();

    virtual void _handleSetText(String text);

    virtual VoidCallback _createShowOnScreenFor(Key key);

    virtual void _handleSetSelection(TextSelection selection);

    virtual void _handleMoveCursorForwardByCharacter(bool extendSelection);

    virtual void _handleMoveCursorBackwardByCharacter(bool extendSelection);

    virtual void _handleMoveCursorForwardByWord(bool extendSelection);

    virtual void _handleMoveCursorBackwardByWord(bool extendSelection);

    virtual TextRange _getNextWord(int offset);

    virtual TextRange _getPreviousWord(int offset);

    virtual bool _onlyWhitespace(TextRange range);

    virtual bool _isMultiline();

    virtual Axis _viewportAxis();

    virtual Offset _paintOffset();

    virtual double _viewportExtent();

    virtual double _getMaxScrollExtent(Size contentSize);

    virtual bool _hasVisualOverflow();

    virtual double _preferredHeight(double width);

    virtual void _handleTapDown(TapDownDetails details);

    virtual void _handleTap();

    virtual void _handleLongPress();

    virtual TextSelection _getWordAtOffset(TextPosition position);

    virtual List<PlaceholderDimensions> _layoutChildren(BoxConstraints constraints, bool dry);

    virtual void _setParentData();

    virtual void _layoutText(double maxWidth, double minWidth);

    virtual void _computeTextMetricsIfNeeded();

    virtual void _computeCaretPrototype();

    virtual Offset _snapToPhysicalPixel(Offset sourceOffset);

    virtual bool _canComputeDryLayout();

    virtual MapEntry<int, Offset> _lineNumberFor(TextPosition startPosition, List<LineMetrics> metrics);

    virtual void _paintContents(PaintingContext context, Offset offset);

    virtual void _paintHandleLayers(PaintingContext context, List<TextSelectionPoint> endpoints);

};
using RenderEditable = std::shared_ptr<RenderEditableCls>;

class _RenderEditableCustomPaintCls : public RenderBoxCls {
public:

    virtual RenderEditable parent();

    virtual bool isRepaintBoundary();

    virtual bool sizedByParent();

    virtual RenderEditablePainter painter();

    virtual void  painter(RenderEditablePainter newValue);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual Size computeDryLayout(BoxConstraints constraints);

private:
    RenderEditablePainter _painter;


     _RenderEditableCustomPaintCls(RenderEditablePainter painter);

};
using _RenderEditableCustomPaint = std::shared_ptr<_RenderEditableCustomPaintCls>;

class RenderEditablePainterCls : public ChangeNotifierCls {
public:

    virtual bool shouldRepaint(RenderEditablePainter oldDelegate);
    virtual void paint(Canvas canvas, Size size, RenderEditable renderEditable);
private:

};
using RenderEditablePainter = std::shared_ptr<RenderEditablePainterCls>;

class _TextHighlightPainterCls : public RenderEditablePainterCls {
public:
    Paint highlightPaint;


    virtual Color highlightColor();

    virtual void  highlightColor(Color newValue);

    virtual TextRange highlightedRange();

    virtual void  highlightedRange(TextRange newValue);

    virtual BoxHeightStyle selectionHeightStyle();

    virtual void  selectionHeightStyle(BoxHeightStyle value);

    virtual BoxWidthStyle selectionWidthStyle();

    virtual void  selectionWidthStyle(BoxWidthStyle value);

    virtual void paint(Canvas canvas, Size size, RenderEditable renderEditable);

    virtual bool shouldRepaint(RenderEditablePainter oldDelegate);

private:
    Color _highlightColor;

    TextRange _highlightedRange;

    BoxHeightStyle _selectionHeightStyle;

    BoxWidthStyle _selectionWidthStyle;


     _TextHighlightPainterCls(Color highlightColor, TextRange highlightedRange);

};
using _TextHighlightPainter = std::shared_ptr<_TextHighlightPainterCls>;

class _FloatingCursorPainterCls : public RenderEditablePainterCls {
public:
    CaretChangedHandler caretPaintCallback;

    bool showRegularCaret;

    Paint caretPaint;

    Paint floatingCursorPaint;


    virtual bool shouldPaint();

    virtual void  shouldPaint(bool value);

    virtual Color caretColor();

    virtual void  caretColor(Color value);

    virtual Radius cursorRadius();

    virtual void  cursorRadius(Radius value);

    virtual Offset cursorOffset();

    virtual void  cursorOffset(Offset value);

    virtual Color backgroundCursorColor();

    virtual void  backgroundCursorColor(Color value);

    virtual Rect floatingCursorRect();

    virtual void  floatingCursorRect(Rect value);

    virtual void paintRegularCursor(Canvas canvas, RenderEditable renderEditable, Color caretColor, TextPosition textPosition);

    virtual void paint(Canvas canvas, Size size, RenderEditable renderEditable);

    virtual bool shouldRepaint(RenderEditablePainter oldDelegate);

private:
    bool _shouldPaint;

    Color _caretColor;

    Radius _cursorRadius;

    Offset _cursorOffset;

    Color _backgroundCursorColor;

    Rect _floatingCursorRect;


     _FloatingCursorPainterCls(CaretChangedHandler caretPaintCallback);
};
using _FloatingCursorPainter = std::shared_ptr<_FloatingCursorPainterCls>;

class _CompositeRenderEditablePainterCls : public RenderEditablePainterCls {
public:
    List<RenderEditablePainter> painters;


    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

    virtual void paint(Canvas canvas, Size size, RenderEditable renderEditable);

    virtual bool shouldRepaint(RenderEditablePainter oldDelegate);

private:

     _CompositeRenderEditablePainterCls(List<RenderEditablePainter> painters);
};
using _CompositeRenderEditablePainter = std::shared_ptr<_CompositeRenderEditablePainterCls>;


#endif