#ifndef PARAGRAPH_H
#define PARAGRAPH_H
#include <memory>

#include <collection/collection.hpp>
#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/semantics.hpp>
#include "box.hpp"
#include "debug.hpp"
#include "layer.hpp"
#include "object.hpp"
#include "selection.hpp"


const String _kEllipsis;


class TextParentData : ContainerBoxParentData<RenderBox> {
public:
    double scale;


    String toString();

private:

};

class PlaceholderSpanIndexSemanticsTag : SemanticsTag {
public:
    int index;


     PlaceholderSpanIndexSemanticsTag(int index);

    bool ==(Object other);

    int hashCode();

private:

};

class RenderParagraph : RenderBox {
public:

     RenderParagraph(List<RenderBox> children, Locale locale, int maxLines, TextOverflow overflow, SelectionRegistrar registrar, Color selectionColor, bool softWrap, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis);

    void setupParentData(RenderBox child);

    InlineSpan text();

    void  text(InlineSpan value);

    List<TextSelection> selections();

    SelectionRegistrar registrar();

    void  registrar(SelectionRegistrar value);

    void markNeedsLayout();

    void dispose();

    TextAlign textAlign();

    void  textAlign(TextAlign value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    bool softWrap();

    void  softWrap(bool value);

    TextOverflow overflow();

    void  overflow(TextOverflow value);

    double textScaleFactor();

    void  textScaleFactor(double value);

    int maxLines();

    void  maxLines(int value);

    Locale locale();

    void  locale(Locale value);

    StrutStyle strutStyle();

    void  strutStyle(StrutStyle value);

    TextWidthBasis textWidthBasis();

    void  textWidthBasis(TextWidthBasis value);

    TextHeightBehavior textHeightBehavior();

    void  textHeightBehavior(TextHeightBehavior value);

    Color selectionColor();

    void  selectionColor(Color value);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    double computeDistanceToActualBaseline(TextBaseline baseline);

    bool hitTestSelf(Offset position);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    bool debugHasOverflowShader();

    void systemFontsDidChange();

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void paint(PaintingContext context, Offset offset);

    Offset getOffsetForCaret(Rect caretPrototype, TextPosition position);

    double getFullHeightForCaret(TextPosition position);

    List<TextBox> getBoxesForSelection(BoxHeightStyle boxHeightStyle, BoxWidthStyle boxWidthStyle, TextSelection selection);

    TextPosition getPositionForOffset(Offset offset);

    TextRange getWordBoundary(TextPosition position);

    Size textSize();

    void describeSemanticsConfiguration(SemanticsConfiguration config);

    void assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node);

    void clearSemantics();

    List<DiagnosticsNode> debugDescribeChildren();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    static String _placeholderCharacter;

    TextPainter _textPainter;

    AttributedString _cachedAttributedLabel;

    List<InlineSpanSemanticsInformation> _cachedCombinedSemanticsInfos;

    List<_SelectableFragment> _lastSelectableFragments;

    SelectionRegistrar _registrar;

    List<PlaceholderSpan> _placeholderSpans;

    bool _softWrap;

    TextOverflow _overflow;

    Color _selectionColor;

    bool _needsClipping;

    Shader _overflowShader;

    List<PlaceholderDimensions> _placeholderDimensions;

    List<InlineSpanSemanticsInformation> _semanticsInfo;

    LinkedHashMap<Key, SemanticsNode> _cachedChildNodes;


    void _updateSelectionRegistrarSubscription();

    void _removeSelectionRegistrarSubscription();

    List<_SelectableFragment> _getSelectableFragments();

    void _disposeSelectableFragments();

    void _extractPlaceholderSpans(InlineSpan span);

    Offset _getOffsetForPosition(TextPosition position);

    double _computeIntrinsicHeight(double width);

    bool _canComputeIntrinsics();

    void _computeChildrenWidthWithMaxIntrinsics(double height);

    void _computeChildrenWidthWithMinIntrinsics(double height);

    void _computeChildrenHeightWithMinIntrinsics(double width);

    void _layoutText(double maxWidth, double minWidth);

    void _layoutTextWithConstraints(BoxConstraints constraints);

    List<PlaceholderDimensions> _layoutChildren(BoxConstraints constraints, bool dry);

    void _setParentData();

    bool _canComputeDryLayout();

    VoidCallback _createShowOnScreenFor(Key key);

};

class _SelectableFragment {
public:
    TextRange range;

    RenderParagraph paragraph;


    SelectionGeometry value();

    SelectionResult dispatchSelectionEvent(SelectionEvent event);

    SelectedContent getSelectedContent();

    Matrix4 getTransformToParagraph();

    Matrix4 getTransformTo(RenderObject ancestor);

    void pushHandleLayers(LayerLink endHandle, LayerLink startHandle);

    void didChangeParagraphLayout();

    Size size();

    void paint(PaintingContext context, Offset offset);

private:
    TextPosition _textSelectionStart;

    TextPosition _textSelectionEnd;

    LayerLink _startHandleLayerLink;

    LayerLink _endHandleLayerLink;

    SelectionGeometry _selectionGeometry;

    Rect _cachedRect;


     _SelectableFragment(RenderParagraph paragraph, TextRange range);

    void _updateSelectionGeometry();

    SelectionGeometry _getSelectionGeometry();

    void _didChangeSelection();

    SelectionResult _updateSelectionEdge(Offset globalPosition, bool isEnd);

    TextPosition _clampTextPosition(TextPosition position);

    void _setSelectionPosition(bool isEnd, TextPosition position);

    SelectionResult _handleClearSelection();

    SelectionResult _handleSelectAll();

    SelectionResult _handleSelectWord(Offset globalPosition);

    bool _positionIsWithinCurrentSelection(TextPosition position);

    static int _compareTextPositions(TextPosition otherPosition, TextPosition position);

    Rect _rect();

};

#endif