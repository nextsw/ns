#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_PARAGRAPH
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_PARAGRAPH
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "box.hpp"
#include "debug.hpp"
#include "layer.hpp"
#include "object.hpp"
#include "selection.hpp"

String _kEllipsis;


class TextParentDataCls : public ContainerBoxParentDataCls<RenderBox> {
public:
    double scale;


    virtual String toString();

private:

};
using TextParentData = std::shared_ptr<TextParentDataCls>;

class PlaceholderSpanIndexSemanticsTagCls : public SemanticsTagCls {
public:
    int index;


     PlaceholderSpanIndexSemanticsTagCls(int index);

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

};
using PlaceholderSpanIndexSemanticsTag = std::shared_ptr<PlaceholderSpanIndexSemanticsTagCls>;

class RenderParagraphCls : public RenderBoxCls {
public:

     RenderParagraphCls(List<RenderBox> children, Locale locale, int maxLines, TextOverflow overflow, SelectionRegistrar registrar, Color selectionColor, bool softWrap, StrutStyle strutStyle, InlineSpan text, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior, double textScaleFactor, TextWidthBasis textWidthBasis);

    virtual void setupParentData(RenderBox child);

    virtual InlineSpan text();

    virtual void  text(InlineSpan value);

    virtual List<TextSelection> selections();

    virtual SelectionRegistrar registrar();

    virtual void  registrar(SelectionRegistrar value);

    virtual void markNeedsLayout();

    virtual void dispose();

    virtual TextAlign textAlign();

    virtual void  textAlign(TextAlign value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual bool softWrap();

    virtual void  softWrap(bool value);

    virtual TextOverflow overflow();

    virtual void  overflow(TextOverflow value);

    virtual double textScaleFactor();

    virtual void  textScaleFactor(double value);

    virtual int maxLines();

    virtual void  maxLines(int value);

    virtual Locale locale();

    virtual void  locale(Locale value);

    virtual StrutStyle strutStyle();

    virtual void  strutStyle(StrutStyle value);

    virtual TextWidthBasis textWidthBasis();

    virtual void  textWidthBasis(TextWidthBasis value);

    virtual TextHeightBehavior textHeightBehavior();

    virtual void  textHeightBehavior(TextHeightBehavior value);

    virtual Color selectionColor();

    virtual void  selectionColor(Color value);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual bool hitTestSelf(Offset position);

    virtual bool hitTestChildren(Offset position, BoxHitTestResult result);

    virtual bool debugHasOverflowShader();

    virtual void systemFontsDidChange();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void paint(PaintingContext context, Offset offset);

    virtual Offset getOffsetForCaret(Rect caretPrototype, TextPosition position);

    virtual double getFullHeightForCaret(TextPosition position);

    virtual List<TextBox> getBoxesForSelection(BoxHeightStyle boxHeightStyle, BoxWidthStyle boxWidthStyle, TextSelection selection);

    virtual TextPosition getPositionForOffset(Offset offset);

    virtual TextRange getWordBoundary(TextPosition position);

    virtual Size textSize();

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

    virtual void assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node);

    virtual void clearSemantics();

    virtual List<DiagnosticsNode> debugDescribeChildren();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

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


    virtual void _updateSelectionRegistrarSubscription();

    virtual void _removeSelectionRegistrarSubscription();

    virtual List<_SelectableFragment> _getSelectableFragments();

    virtual void _disposeSelectableFragments();

    virtual void _extractPlaceholderSpans(InlineSpan span);

    virtual Offset _getOffsetForPosition(TextPosition position);

    virtual double _computeIntrinsicHeight(double width);

    virtual bool _canComputeIntrinsics();

    virtual void _computeChildrenWidthWithMaxIntrinsics(double height);

    virtual void _computeChildrenWidthWithMinIntrinsics(double height);

    virtual void _computeChildrenHeightWithMinIntrinsics(double width);

    virtual void _layoutText(double maxWidth, double minWidth);

    virtual void _layoutTextWithConstraints(BoxConstraints constraints);

    virtual List<PlaceholderDimensions> _layoutChildren(BoxConstraints constraints, bool dry);

    virtual void _setParentData();

    virtual bool _canComputeDryLayout();

    virtual VoidCallback _createShowOnScreenFor(Key key);

};
using RenderParagraph = std::shared_ptr<RenderParagraphCls>;

class _SelectableFragmentCls : public ObjectCls {
public:
    TextRange range;

    RenderParagraph paragraph;


    virtual SelectionGeometry value();

    virtual SelectionResult dispatchSelectionEvent(SelectionEvent event);

    virtual SelectedContent getSelectedContent();

    virtual Matrix4 getTransformToParagraph();

    virtual Matrix4 getTransformTo(RenderObject ancestor);

    virtual void pushHandleLayers(LayerLink endHandle, LayerLink startHandle);

    virtual void didChangeParagraphLayout();

    virtual Size size();

    virtual void paint(PaintingContext context, Offset offset);

private:
    TextPosition _textSelectionStart;

    TextPosition _textSelectionEnd;

    LayerLink _startHandleLayerLink;

    LayerLink _endHandleLayerLink;

    SelectionGeometry _selectionGeometry;

    Rect _cachedRect;


     _SelectableFragmentCls(RenderParagraph paragraph, TextRange range);

    virtual void _updateSelectionGeometry();

    virtual SelectionGeometry _getSelectionGeometry();

    virtual void _didChangeSelection();

    virtual SelectionResult _updateSelectionEdge(Offset globalPosition, bool isEnd);

    virtual TextPosition _clampTextPosition(TextPosition position);

    virtual void _setSelectionPosition(bool isEnd, TextPosition position);

    virtual SelectionResult _handleClearSelection();

    virtual SelectionResult _handleSelectAll();

    virtual SelectionResult _handleSelectWord(Offset globalPosition);

    virtual bool _positionIsWithinCurrentSelection(TextPosition position);

    static int _compareTextPositions(TextPosition otherPosition, TextPosition position);

    virtual Rect _rect();

};
using _SelectableFragment = std::shared_ptr<_SelectableFragmentCls>;


#endif