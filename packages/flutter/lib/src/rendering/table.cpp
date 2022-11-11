#include "table.hpp"
String TableCellParentDataCls::toString() {
    return __s("${super.toString()}; ${verticalAlignment == null ? "default vertical alignment" : "$verticalAlignment"}");
}

double TableColumnWidthCls::flex(Iterable<RenderBox> cells) {
    return nullptr;
}

String TableColumnWidthCls::toString() {
    return objectRuntimeType(this, __s("TableColumnWidth"));
}

IntrinsicColumnWidthCls::IntrinsicColumnWidthCls(double flex) {
    {
        _flex = flex;
    }
}

double IntrinsicColumnWidthCls::minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    double result = 0.0;
    for (RenderBox cell : cells) {
        result = math->max(result, cell->getMinIntrinsicWidth(double->infinity));
    }
    return result;
}

double IntrinsicColumnWidthCls::maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    double result = 0.0;
    for (RenderBox cell : cells) {
        result = math->max(result, cell->getMaxIntrinsicWidth(double->infinity));
    }
    return result;
}

double IntrinsicColumnWidthCls::flex(Iterable<RenderBox> cells) {
    return _flex;
}

String IntrinsicColumnWidthCls::toString() {
    return __s("${objectRuntimeType(this, 'IntrinsicColumnWidth')}(flex: ${_flex?.toStringAsFixed(1)})");
}

FixedColumnWidthCls::FixedColumnWidthCls(double value) {
    {
        assert(value != nullptr);
    }
}

double FixedColumnWidthCls::minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return value;
}

double FixedColumnWidthCls::maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return value;
}

String FixedColumnWidthCls::toString() {
    return __s("${objectRuntimeType(this, 'FixedColumnWidth')}(${debugFormatDouble(value)})");
}

FractionColumnWidthCls::FractionColumnWidthCls(double value) {
    {
        assert(value != nullptr);
    }
}

double FractionColumnWidthCls::minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    if (!containerWidth->isFinite) {
        return 0.0;
    }
    return value * containerWidth;
}

double FractionColumnWidthCls::maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    if (!containerWidth->isFinite) {
        return 0.0;
    }
    return value * containerWidth;
}

String FractionColumnWidthCls::toString() {
    return __s("${objectRuntimeType(this, 'FractionColumnWidth')}($value)");
}

FlexColumnWidthCls::FlexColumnWidthCls(double value) {
    {
        assert(value != nullptr);
    }
}

double FlexColumnWidthCls::minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return 0.0;
}

double FlexColumnWidthCls::maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return 0.0;
}

double FlexColumnWidthCls::flex(Iterable<RenderBox> cells) {
    return value;
}

String FlexColumnWidthCls::toString() {
    return __s("${objectRuntimeType(this, 'FlexColumnWidth')}(${debugFormatDouble(value)})");
}

double MaxColumnWidthCls::minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return math->max(a->minIntrinsicWidth(cells, containerWidth), b->minIntrinsicWidth(cells, containerWidth));
}

double MaxColumnWidthCls::maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return math->max(a->maxIntrinsicWidth(cells, containerWidth), b->maxIntrinsicWidth(cells, containerWidth));
}

double MaxColumnWidthCls::flex(Iterable<RenderBox> cells) {
    double aFlex = a->flex(cells);
    if (aFlex == nullptr) {
        return b->flex(cells);
    }
    double bFlex = b->flex(cells);
    if (bFlex == nullptr) {
        return nullptr;
    }
    return math->max(aFlex, bFlex);
}

String MaxColumnWidthCls::toString() {
    return __s("${objectRuntimeType(this, 'MaxColumnWidth')}($a, $b)");
}

double MinColumnWidthCls::minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return math->min(a->minIntrinsicWidth(cells, containerWidth), b->minIntrinsicWidth(cells, containerWidth));
}

double MinColumnWidthCls::maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return math->min(a->maxIntrinsicWidth(cells, containerWidth), b->maxIntrinsicWidth(cells, containerWidth));
}

double MinColumnWidthCls::flex(Iterable<RenderBox> cells) {
    double aFlex = a->flex(cells);
    if (aFlex == nullptr) {
        return b->flex(cells);
    }
    double bFlex = b->flex(cells);
    if (bFlex == nullptr) {
        return nullptr;
    }
    return math->min(aFlex, bFlex);
}

String MinColumnWidthCls::toString() {
    return __s("${objectRuntimeType(this, 'MinColumnWidth')}($a, $b)");
}

RenderTableCls::RenderTableCls(TableBorder border, List<List<RenderBox>> children, Map<int, TableColumnWidth> columnWidths, int columns, ImageConfiguration configuration, TableColumnWidth defaultColumnWidth, TableCellVerticalAlignment defaultVerticalAlignment, List<Decoration> rowDecorations, int rows, TextBaseline textBaseline, TextDirection textDirection) {
    {
        assert(columns == nullptr || columns >= 0);
        assert(rows == nullptr || rows >= 0);
        assert(rows == nullptr || children == nullptr);
        assert(defaultColumnWidth != nullptr);
        assert(textDirection != nullptr);
        assert(configuration != nullptr);
        _textDirection = textDirection;
        _columns = columns | (children != nullptr && children->isNotEmpty? children->first->length : 0);
        _rows = rows | 0;
        _columnWidths = columnWidths | <int, TableColumnWidth>make<HashMapCls>();
        _defaultColumnWidth = defaultColumnWidth;
        _border = border;
        _textBaseline = textBaseline;
        _defaultVerticalAlignment = defaultVerticalAlignment;
        _configuration = configuration;
    }
    {
            auto _c1 = makeList();    _c1.length = _columns * _rows;_children = _c1;
        this->rowDecorations = rowDecorations;
        children?->forEach(addRow);
    }
}

int RenderTableCls::columns() {
    return _columns;
}

void RenderTableCls::columns(int value) {
    assert(value != nullptr);
    assert(value >= 0);
    if (value == columns()) {
        return;
    }
    int oldColumns = columns();
    List<RenderBox> oldChildren = _children;
    _columns = value;
    _children = <RenderBox>filled(columns() * rows(), nullptr);
    int columnsToCopy = math->min(columns(), oldColumns);
    for (;  < rows(); y += 1) {
        for (;  < columnsToCopy; x += 1) {
            _children[x + y * columns()] = oldChildren[x + y * oldColumns];
        }
    }
    if (oldColumns > columns()) {
        for (;  < rows(); y += 1) {
            for (;  < oldColumns; x += 1) {
                int xy = x + y * oldColumns;
                if (oldChildren[xy] != nullptr) {
                    dropChild(oldChildren[xy]!);
                }
            }
        }
    }
    markNeedsLayout();
}

int RenderTableCls::rows() {
    return _rows;
}

void RenderTableCls::rows(int value) {
    assert(value != nullptr);
    assert(value >= 0);
    if (value == rows()) {
        return;
    }
    if (_rows > value) {
        for (;  < _children->length(); xy += 1) {
            if (_children[xy] != nullptr) {
                dropChild(_children[xy]!);
            }
        }
    }
    _rows = value;
    _children->length() = columns() * rows();
    markNeedsLayout();
}

Map<int, TableColumnWidth> RenderTableCls::columnWidths() {
    return <int, TableColumnWidth>unmodifiable(_columnWidths);
}

void RenderTableCls::columnWidths(Map<int, TableColumnWidth> value) {
    if (_columnWidths == value) {
        return;
    }
    if (_columnWidths->isEmpty() && value == nullptr) {
        return;
    }
    _columnWidths = value | <int, TableColumnWidth>make<HashMapCls>();
    markNeedsLayout();
}

void RenderTableCls::setColumnWidth(int column, TableColumnWidth value) {
    if (_columnWidths[column] == value) {
        return;
    }
    _columnWidths[column] = value;
    markNeedsLayout();
}

TableColumnWidth RenderTableCls::defaultColumnWidth() {
    return _defaultColumnWidth;
}

void RenderTableCls::defaultColumnWidth(TableColumnWidth value) {
    assert(value != nullptr);
    if (defaultColumnWidth() == value) {
        return;
    }
    _defaultColumnWidth = value;
    markNeedsLayout();
}

TextDirection RenderTableCls::textDirection() {
    return _textDirection;
}

void RenderTableCls::textDirection(TextDirection value) {
    assert(value != nullptr);
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    markNeedsLayout();
}

TableBorder RenderTableCls::border() {
    return _border;
}

void RenderTableCls::border(TableBorder value) {
    if (border() == value) {
        return;
    }
    _border = value;
    markNeedsPaint();
}

List<Decoration> RenderTableCls::rowDecorations() {
    return <Decoration>unmodifiable(_rowDecorations | makeList());
}

void RenderTableCls::rowDecorations(List<Decoration> value) {
    if (_rowDecorations == value) {
        return;
    }
    _rowDecorations = value;
    if (_rowDecorationPainters != nullptr) {
        for (BoxPainter painter : _rowDecorationPainters!) {
            painter?->dispose();
        }
    }
    _rowDecorationPainters = _rowDecorations != nullptr? <BoxPainter>filled(_rowDecorations!->length(), nullptr) : nullptr;
}

ImageConfiguration RenderTableCls::configuration() {
    return _configuration;
}

void RenderTableCls::configuration(ImageConfiguration value) {
    assert(value != nullptr);
    if (value == _configuration) {
        return;
    }
    _configuration = value;
    markNeedsPaint();
}

TableCellVerticalAlignment RenderTableCls::defaultVerticalAlignment() {
    return _defaultVerticalAlignment;
}

void RenderTableCls::defaultVerticalAlignment(TableCellVerticalAlignment value) {
    assert(value != nullptr);
    if (_defaultVerticalAlignment == value) {
        return;
    }
    _defaultVerticalAlignment = value;
    markNeedsLayout();
}

TextBaseline RenderTableCls::textBaseline() {
    return _textBaseline;
}

void RenderTableCls::textBaseline(TextBaseline value) {
    if (_textBaseline == value) {
        return;
    }
    _textBaseline = value;
    markNeedsLayout();
}

void RenderTableCls::setupParentData(RenderObject child) {
    if (!is<TableCellParentData>(child->parentData)) {
        child->parentData = make<TableCellParentDataCls>();
    }
}

void RenderTableCls::setFlatChildren(int columns, List<RenderBox> cells) {
    if (cells == _children && columns == _columns) {
        return;
    }
    assert(columns >= 0);
    if (columns == 0 || cells->isEmpty) {
        assert(cells == nullptr || cells->isEmpty);
        _columns = columns;
        if (_children->isEmpty) {
            assert(_rows == 0);
            return;
        }
        for (RenderBox oldChild : _children) {
            if (oldChild != nullptr) {
                dropChild(oldChild);
            }
        }
        _rows = 0;
        _children->clear();
        markNeedsLayout();
        return;
    }
    assert(cells != nullptr);
    assert(cells->length() % columns == 0);
    Set<RenderBox> lostChildren = <RenderBox>make<HashSetCls>();
    for (;  < _rows; y += 1) {
        for (;  < _columns; x += 1) {
            int xyOld = x + y * _columns;
            int xyNew = x + y * columns;
            if (_children[xyOld] != nullptr && (x >= columns || xyNew >= cells->length() || _children[xyOld] != cells[xyNew])) {
                lostChildren->add(_children[xyOld]!);
            }
        }
    }
    int y = 0;
    while (y *  < cells->length()) {
        for (;  < columns; x += 1) {
            int xyNew = x + y * columns;
            int xyOld = x + y * _columns;
            if (cells[xyNew] != nullptr && (x >= _columns || y >= _rows || _children[xyOld] != cells[xyNew])) {
                if (!lostChildren->remove(cells[xyNew])) {
                    adoptChild(cells[xyNew]!);
                }
            }
        }
        y += 1;
    }
    lostChildren->forEach(dropChild);
    _columns = columns;
    _rows = cells->length() ~/ columns;
    _children = <RenderBox>of(cells);
    assert(_children->length() == rows() * columns);
    markNeedsLayout();
}

void RenderTableCls::setChildren(List<List<RenderBox>> cells) {
    if (cells == nullptr) {
        setFlatChildren(0, makeList());
        return;
    }
    for (RenderBox oldChild : _children) {
        if (oldChild != nullptr) {
            dropChild(oldChild);
        }
    }
    _children->clear();
    _columns = cells->isNotEmpty? cells->first->length : 0;
    _rows = 0;
    cells->forEach(addRow);
    assert(_children->length() == rows() * columns());
}

void RenderTableCls::addRow(List<RenderBox> cells) {
    assert(cells->length() == columns());
    assert(_children->length() == rows() * columns());
    _rows += 1;
    _children->addAll(cells);
    for (RenderBox cell : cells) {
        if (cell != nullptr) {
            adoptChild(cell);
        }
    }
    markNeedsLayout();
}

void RenderTableCls::setChild(int x, int y, RenderBox value) {
    assert(x != nullptr);
    assert(y != nullptr);
    assert(x >= 0 &&  < columns() && y >= 0 &&  < rows());
    assert(_children->length() == rows() * columns());
    int xy = x + y * columns();
    RenderBox oldChild = _children[xy];
    if (oldChild == value) {
        return;
    }
    if (oldChild != nullptr) {
        dropChild(oldChild);
    }
    _children[xy] = value;
    if (value != nullptr) {
        adoptChild(value);
    }
}

void RenderTableCls::attach(PipelineOwner owner) {
    super->attach(owner);
    for (RenderBox child : _children) {
        child?->attach(owner);
    }
}

void RenderTableCls::detach() {
    super->detach();
    if (_rowDecorationPainters != nullptr) {
        for (BoxPainter painter : _rowDecorationPainters!) {
            painter?->dispose();
        }
        _rowDecorationPainters = <BoxPainter>filled(_rowDecorations!->length(), nullptr);
    }
    for (RenderBox child : _children) {
        child?->detach();
    }
}

void RenderTableCls::visitChildren(RenderObjectVisitor visitor) {
    assert(_children->length() == rows() * columns());
    for (RenderBox child : _children) {
        if (child != nullptr) {
            visitor(child);
        }
    }
}

double RenderTableCls::computeMinIntrinsicWidth(double height) {
    assert(_children->length() == rows() * columns());
    double totalMinWidth = 0.0;
    for (;  < columns(); x += 1) {
        TableColumnWidth columnWidth = _columnWidths[x] | defaultColumnWidth();
        Iterable<RenderBox> columnCells = column(x);
        totalMinWidth += columnWidth->minIntrinsicWidth(columnCells, double->infinity);
    }
    return totalMinWidth;
}

double RenderTableCls::computeMaxIntrinsicWidth(double height) {
    assert(_children->length() == rows() * columns());
    double totalMaxWidth = 0.0;
    for (;  < columns(); x += 1) {
        TableColumnWidth columnWidth = _columnWidths[x] | defaultColumnWidth();
        Iterable<RenderBox> columnCells = column(x);
        totalMaxWidth += columnWidth->maxIntrinsicWidth(columnCells, double->infinity);
    }
    return totalMaxWidth;
}

double RenderTableCls::computeMinIntrinsicHeight(double width) {
    assert(_children->length() == rows() * columns());
    List<double> widths = _computeColumnWidths(BoxConstraintsCls->tightForFinite(width));
    double rowTop = 0.0;
    for (;  < rows(); y += 1) {
        double rowHeight = 0.0;
        for (;  < columns(); x += 1) {
            int xy = x + y * columns();
            RenderBox child = _children[xy];
            if (child != nullptr) {
                rowHeight = math->max(rowHeight, child->getMaxIntrinsicHeight(widths[x]));
            }
        }
        rowTop += rowHeight;
    }
    return rowTop;
}

double RenderTableCls::computeMaxIntrinsicHeight(double width) {
    return computeMinIntrinsicHeight(width);
}

double RenderTableCls::computeDistanceToActualBaseline(TextBaseline baseline) {
    assert(!debugNeedsLayout);
    return _baselineDistance;
}

Iterable<RenderBox> RenderTableCls::column(int x) {
    for (;  < rows(); y += 1) {
        int xy = x + y * columns();
        RenderBox child = _children[xy];
        if (child != nullptr) {
            yield yield;
            child;
        }
    }
}

Iterable<RenderBox> RenderTableCls::row(int y) {
    int start = y * columns();
    int end = (y + 1) * columns();
    for (;  < end; xy += 1) {
        RenderBox child = _children[xy];
        if (child != nullptr) {
            yield yield;
            child;
        }
    }
}

Rect RenderTableCls::getRowBox(int row) {
    assert(row >= 0);
    assert( < rows());
    assert(!debugNeedsLayout);
    return RectCls->fromLTRB(0.0, _rowTops[row], size->width, _rowTops[row + 1]);
}

Size RenderTableCls::computeDryLayout(BoxConstraints constraints) {
    if (rows() * columns() == 0) {
        return constraints->constrain(SizeCls::zero);
    }
    List<double> widths = _computeColumnWidths(constraints);
    double tableWidth = widths->fold(0.0, [=] (double a,double b) {
    a + b;
});
    double rowTop = 0.0;
    for (;  < rows(); y += 1) {
        double rowHeight = 0.0;
        for (;  < columns(); x += 1) {
            int xy = x + y * columns();
            RenderBox child = _children[xy];
            if (child != nullptr) {
                TableCellParentData childParentData = as<TableCellParentData>(child->parentData!);
                assert(childParentData != nullptr);
                ;
            }
        }
        rowTop += rowHeight;
    }
    return constraints->constrain(make<SizeCls>(tableWidth, rowTop));
}

void RenderTableCls::performLayout() {
    BoxConstraints constraints = this->constraints;
    int rows = this->rows();
    int columns = this->columns();
    assert(_children->length() == rows * columns);
    if (rows * columns == 0) {
        _tableWidth = 0.0;
        size = constraints->constrain(SizeCls::zero);
        return;
    }
    List<double> widths = _computeColumnWidths(constraints);
    List<double> positions = <double>filled(columns, 0.0);
    ;
    _rowTops->clear();
    _baselineDistance = nullptr;
    double rowTop = 0.0;
    for (;  < rows; y += 1) {
        _rowTops->add(rowTop);
        double rowHeight = 0.0;
        bool haveBaseline = false;
        double beforeBaselineDistance = 0.0;
        double afterBaselineDistance = 0.0;
        List<double> baselines = <double>filled(columns, 0.0);
        for (;  < columns; x += 1) {
            int xy = x + y * columns;
            RenderBox child = _children[xy];
            if (child != nullptr) {
                TableCellParentData childParentData = as<TableCellParentData>(child->parentData!);
                assert(childParentData != nullptr);
                childParentData->x = x;
                childParentData->y = y;
                ;
            }
        }
        if (haveBaseline) {
            if (y == 0) {
                _baselineDistance = beforeBaselineDistance;
            }
            rowHeight = math->max(rowHeight, beforeBaselineDistance + afterBaselineDistance);
        }
        for (;  < columns; x += 1) {
            int xy = x + y * columns;
            RenderBox child = _children[xy];
            if (child != nullptr) {
                TableCellParentData childParentData = as<TableCellParentData>(child->parentData!);
                ;
            }
        }
        rowTop += rowHeight;
    }
    _rowTops->add(rowTop);
    size = constraints->constrain(make<SizeCls>(_tableWidth, rowTop));
    assert(_rowTops->length() == rows + 1);
}

bool RenderTableCls::hitTestChildren(BoxHitTestResult result, Offset position) {
    assert(_children->length() == rows() * columns());
    for (; index >= 0; index -= 1) {
        RenderBox child = _children[index];
        if (child != nullptr) {
            BoxParentData childParentData = as<BoxParentData>(child->parentData!);
            bool isHit = result->addWithPaintOffset(childParentData->offset, position, [=] (BoxHitTestResult result,Offset transformed) {
    assert(transformed == position - childParentData->offset);
    return child->hitTest(resulttransformed);
});
            if (isHit) {
                return true;
            }
        }
    }
    return false;
}

void RenderTableCls::paint(PaintingContext context, Offset offset) {
    assert(_children->length() == rows() * columns());
    if (rows() * columns() == 0) {
        if (border() != nullptr) {
            Rect borderRect = RectCls->fromLTWH(offset->dx(), offset->dy(), _tableWidth, 0.0);
            border()!->paint(context->canvas(), borderRectmakeList(), makeList());
        }
        return;
    }
    assert(_rowTops->length() == rows() + 1);
    if (_rowDecorations != nullptr) {
        assert(_rowDecorations!->length() == _rowDecorationPainters!->length());
        Canvas canvas = context->canvas();
        for (;  < rows(); y += 1) {
            if (_rowDecorations!->length() <= y) {
                break;
            }
            if (_rowDecorations![y] != nullptr) {
                _rowDecorationPainters![y] |= _rowDecorations![y]!->createBoxPainter(markNeedsPaint);
                _rowDecorationPainters![y]!->paint(canvas, make<OffsetCls>(offset->dx(), offset->dy() + _rowTops[y]), configuration()->copyWith(make<SizeCls>(size->width, _rowTops[y + 1] - _rowTops[y])));
            }
        }
    }
    for (;  < _children->length(); index += 1) {
        RenderBox child = _children[index];
        if (child != nullptr) {
            BoxParentData childParentData = as<BoxParentData>(child->parentData!);
            context->paintChild(child, childParentData->offset + offset);
        }
    }
    assert(_rows == _rowTops->length() - 1);
    assert(_columns == _columnLefts!->length());
    if (border() != nullptr) {
        Rect borderRect = RectCls->fromLTWH(offset->dx(), offset->dy(), _tableWidth, _rowTops->last);
        Iterable<double> rows = _rowTops->getRange(1, _rowTops->length() - 1);
        Iterable<double> columns = _columnLefts!->skip(1);
        border()!->paint(context->canvas(), borderRectrows, columns);
    }
}

void RenderTableCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<TableBorder>make<DiagnosticsPropertyCls>(__s("border"), border()nullptr));
    properties->add(<Map<int, TableColumnWidth>>make<DiagnosticsPropertyCls>(__s("specified column widths"), _columnWidths_columnWidths->isEmpty()? DiagnosticLevelCls::hidden : DiagnosticLevelCls::info));
    properties->add(<TableColumnWidth>make<DiagnosticsPropertyCls>(__s("default column width"), defaultColumnWidth()));
    properties->add(make<MessagePropertyCls>(__s("table size"), __s("$columns\u00D7$rows")));
    properties->add(<String>make<IterablePropertyCls>(__s("column offsets"), _columnLefts?->map(debugFormatDouble)__s("unknown")));
    properties->add(<String>make<IterablePropertyCls>(__s("row offsets"), _rowTops->map(debugFormatDouble)__s("unknown")));
}

List<DiagnosticsNode> RenderTableCls::debugDescribeChildren() {
    if (_children->isEmpty) {
        return makeList(ArrayItem);
    }
    List<DiagnosticsNode> children = makeList();
    for (;  < rows(); y += 1) {
        for (;  < columns(); x += 1) {
            int xy = x + y * columns();
            RenderBox child = _children[xy];
            String name = __s("child ($x, $y)");
            if (child != nullptr) {
                children->add(child->toDiagnosticsNode(name));
            } else {
                children->add(<Object>make<DiagnosticsPropertyCls>(name, nullptr__s("is null"), false));
            }
        }
    }
    return children;
}

List<double> RenderTableCls::_computeColumnWidths(BoxConstraints constraints) {
    assert(constraints != nullptr);
    assert(_children->length() == rows() * columns());
    List<double> widths = <double>filled(columns(), 0.0);
    List<double> minWidths = <double>filled(columns(), 0.0);
    List<double> flexes = <double>filled(columns(), nullptr);
    double tableWidth = 0.0;
    double unflexedTableWidth = 0.0;
    double totalFlex = 0.0;
    for (;  < columns(); x += 1) {
        TableColumnWidth columnWidth = _columnWidths[x] | defaultColumnWidth();
        Iterable<RenderBox> columnCells = column(x);
        double maxIntrinsicWidth = columnWidth->maxIntrinsicWidth(columnCells, constraints->maxWidth);
        assert(maxIntrinsicWidth->isFinite);
        assert(maxIntrinsicWidth >= 0.0);
        widths[x] = maxIntrinsicWidth;
        tableWidth += maxIntrinsicWidth;
        double minIntrinsicWidth = columnWidth->minIntrinsicWidth(columnCells, constraints->maxWidth);
        assert(minIntrinsicWidth->isFinite);
        assert(minIntrinsicWidth >= 0.0);
        minWidths[x] = minIntrinsicWidth;
        assert(maxIntrinsicWidth >= minIntrinsicWidth);
        double flex = columnWidth->flex(columnCells);
        if (flex != nullptr) {
            assert(flex->isFinite);
            assert(flex > 0.0);
            flexes[x] = flex;
            totalFlex += flex;
        } else {
            unflexedTableWidth = unflexedTableWidth + maxIntrinsicWidth;
        }
    }
    double maxWidthConstraint = constraints->maxWidth;
    double minWidthConstraint = constraints->minWidth;
    if (totalFlex > 0.0) {
        double targetWidth;
        if (maxWidthConstraint->isFinite) {
            targetWidth = maxWidthConstraint;
        } else {
            targetWidth = minWidthConstraint;
        }
        if ( < targetWidth) {
            double remainingWidth = targetWidth - unflexedTableWidth;
            assert(remainingWidth->isFinite);
            assert(remainingWidth >= 0.0);
            for (;  < columns(); x += 1) {
                if (flexes[x] != nullptr) {
                    double flexedWidth = remainingWidth * flexes[x]! / totalFlex;
                    assert(flexedWidth->isFinite);
                    assert(flexedWidth >= 0.0);
                    if (widths[x] < flexedWidth) {
                        double delta = flexedWidth - widths[x];
                        tableWidth += delta;
                        widths[x] = flexedWidth;
                    }
                }
            }
            assert(tableWidth + precisionErrorTolerance >= targetWidth);
        }
    } else     {
        if ( < minWidthConstraint) {
        double delta = (minWidthConstraint - tableWidth) / columns();
        for (;  < columns(); x += 1) {
            widths[x] = widths[x] + delta;
        }
        tableWidth = minWidthConstraint;
    }
;
    }    if (tableWidth > maxWidthConstraint) {
        double deficit = tableWidth - maxWidthConstraint;
        int availableColumns = columns();
        while (deficit > precisionErrorTolerance && totalFlex > precisionErrorTolerance) {
            double newTotalFlex = 0.0;
            for (;  < columns(); x += 1) {
                if (flexes[x] != nullptr) {
                    double newWidth = widths[x] - deficit * flexes[x]! / totalFlex;
                    assert(newWidth->isFinite);
                    if (newWidth <= minWidths[x]) {
                        deficit -= widths[x] - minWidths[x];
                        widths[x] = minWidths[x];
                        flexes[x] = nullptr;
                        availableColumns -= 1;
                    } else {
                        deficit -= widths[x] - newWidth;
                        widths[x] = newWidth;
                        newTotalFlex += flexes[x]!;
                    }
                    assert(widths[x] >= 0.0);
                }
            }
            totalFlex = newTotalFlex;
        }
        while (deficit > precisionErrorTolerance && availableColumns > 0) {
            double delta = deficit / availableColumns;
            assert(delta != 0);
            int newAvailableColumns = 0;
            for (;  < columns(); x += 1) {
                double availableDelta = widths[x] - minWidths[x];
                if (availableDelta > 0.0) {
                    if (availableDelta <= delta) {
                        deficit -= widths[x] - minWidths[x];
                        widths[x] = minWidths[x];
                    } else {
                        deficit -= delta;
                        widths[x] = widths[x] - delta;
                        newAvailableColumns += 1;
                    }
                }
            }
            availableColumns = newAvailableColumns;
        }
    }
    return widths;
}
