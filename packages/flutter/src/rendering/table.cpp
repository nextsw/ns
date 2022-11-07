#include "table.hpp"
String TableCellParentData::toString() {
    return "${super.toString()}; ${verticalAlignment == null ? "default vertical alignment" : "$verticalAlignment"}";
}

double TableColumnWidth::flex(Iterable<RenderBox> cells) {
    return nullptr;
}

String TableColumnWidth::toString() {
    return objectRuntimeType(this, "TableColumnWidth");
}

IntrinsicColumnWidth::IntrinsicColumnWidth(double flex) {
    {
        _flex = flex;
    }
}

double IntrinsicColumnWidth::minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    double result = 0.0;
    for (RenderBox cell : cells) {
        result = math.max(result, cell.getMinIntrinsicWidth(double.infinity));
    }
    return result;
}

double IntrinsicColumnWidth::maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    double result = 0.0;
    for (RenderBox cell : cells) {
        result = math.max(result, cell.getMaxIntrinsicWidth(double.infinity));
    }
    return result;
}

double IntrinsicColumnWidth::flex(Iterable<RenderBox> cells) {
    return _flex;
}

String IntrinsicColumnWidth::toString() {
    return "${objectRuntimeType(this, 'IntrinsicColumnWidth')}(flex: ${_flex?.toStringAsFixed(1)})";
}

FixedColumnWidth::FixedColumnWidth(double value) {
    {
        assert(value != nullptr);
    }
}

double FixedColumnWidth::minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return value;
}

double FixedColumnWidth::maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return value;
}

String FixedColumnWidth::toString() {
    return "${objectRuntimeType(this, 'FixedColumnWidth')}(${debugFormatDouble(value)})";
}

FractionColumnWidth::FractionColumnWidth(double value) {
    {
        assert(value != nullptr);
    }
}

double FractionColumnWidth::minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    if (!containerWidth.isFinite) {
        return 0.0;
    }
    return value * containerWidth;
}

double FractionColumnWidth::maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    if (!containerWidth.isFinite) {
        return 0.0;
    }
    return value * containerWidth;
}

String FractionColumnWidth::toString() {
    return "${objectRuntimeType(this, 'FractionColumnWidth')}($value)";
}

FlexColumnWidth::FlexColumnWidth(double value) {
    {
        assert(value != nullptr);
    }
}

double FlexColumnWidth::minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return 0.0;
}

double FlexColumnWidth::maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return 0.0;
}

double FlexColumnWidth::flex(Iterable<RenderBox> cells) {
    return value;
}

String FlexColumnWidth::toString() {
    return "${objectRuntimeType(this, 'FlexColumnWidth')}(${debugFormatDouble(value)})";
}

double MaxColumnWidth::minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return math.max(a.minIntrinsicWidth(cells, containerWidth), b.minIntrinsicWidth(cells, containerWidth));
}

double MaxColumnWidth::maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return math.max(a.maxIntrinsicWidth(cells, containerWidth), b.maxIntrinsicWidth(cells, containerWidth));
}

double MaxColumnWidth::flex(Iterable<RenderBox> cells) {
    double aFlex = a.flex(cells);
    if (aFlex == nullptr) {
        return b.flex(cells);
    }
    double bFlex = b.flex(cells);
    if (bFlex == nullptr) {
        return nullptr;
    }
    return math.max(aFlex, bFlex);
}

String MaxColumnWidth::toString() {
    return "${objectRuntimeType(this, 'MaxColumnWidth')}($a, $b)";
}

double MinColumnWidth::minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return math.min(a.minIntrinsicWidth(cells, containerWidth), b.minIntrinsicWidth(cells, containerWidth));
}

double MinColumnWidth::maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth) {
    return math.min(a.maxIntrinsicWidth(cells, containerWidth), b.maxIntrinsicWidth(cells, containerWidth));
}

double MinColumnWidth::flex(Iterable<RenderBox> cells) {
    double aFlex = a.flex(cells);
    if (aFlex == nullptr) {
        return b.flex(cells);
    }
    double bFlex = b.flex(cells);
    if (bFlex == nullptr) {
        return nullptr;
    }
    return math.min(aFlex, bFlex);
}

String MinColumnWidth::toString() {
    return "${objectRuntimeType(this, 'MinColumnWidth')}($a, $b)";
}

RenderTable::RenderTable(TableBorder border, List<List<RenderBox>> children, Map<int, TableColumnWidth> columnWidths, int columns, ImageConfiguration configuration, TableColumnWidth defaultColumnWidth, TableCellVerticalAlignment defaultVerticalAlignment, List<Decoration> rowDecorations, int rows, TextBaseline textBaseline, TextDirection textDirection) {
    {
        assert(columns == nullptr || columns >= 0);
        assert(rows == nullptr || rows >= 0);
        assert(rows == nullptr || children == nullptr);
        assert(defaultColumnWidth != nullptr);
        assert(textDirection != nullptr);
        assert(configuration != nullptr);
        _textDirection = textDirection;
        _columns = columns ?? (children != nullptr && children.isNotEmpty? children.first.length : 0);
        _rows = rows ?? 0;
        _columnWidths = columnWidths ?? <int, TableColumnWidth>HashMap();
        _defaultColumnWidth = defaultColumnWidth;
        _border = border;
        _textBaseline = textBaseline;
        _defaultVerticalAlignment = defaultVerticalAlignment;
        _configuration = configuration;
    }
    {
        _children = ;
        this.rowDecorations = rowDecorations;
        children?.forEach(addRow);
    }
}

int RenderTable::columns() {
    return _columns;
}

void RenderTable::columns(int value) {
    assert(value != nullptr);
    assert(value >= 0);
    if (value == columns) {
        return;
    }
    int oldColumns = columns;
    List<RenderBox> oldChildren = _children;
    _columns = value;
    _children = <RenderBox>filled(columns * rows, nullptr);
    int columnsToCopy = math.min(columns, oldColumns);
    for (;  < rows; y = 1) {
        for (;  < columnsToCopy; x = 1) {
            _children[x + y * columns] = oldChildren[x + y * oldColumns];
        }
    }
    if (oldColumns > columns) {
        for (;  < rows; y = 1) {
            for (;  < oldColumns; x = 1) {
                int xy = x + y * oldColumns;
                if (oldChildren[xy] != nullptr) {
                    dropChild(oldChildren[xy]!);
                }
            }
        }
    }
    markNeedsLayout();
}

int RenderTable::rows() {
    return _rows;
}

void RenderTable::rows(int value) {
    assert(value != nullptr);
    assert(value >= 0);
    if (value == rows) {
        return;
    }
    if (_rows > value) {
        for (;  < _children.length; xy = 1) {
            if (_children[xy] != nullptr) {
                dropChild(_children[xy]!);
            }
        }
    }
    _rows = value;
    _children.length = columns * rows;
    markNeedsLayout();
}

Map<int, TableColumnWidth> RenderTable::columnWidths() {
    return <int, TableColumnWidth>unmodifiable(_columnWidths);
}

void RenderTable::columnWidths(Map<int, TableColumnWidth> value) {
    if (_columnWidths == value) {
        return;
    }
    if (_columnWidths.isEmpty && value == nullptr) {
        return;
    }
    _columnWidths = value ?? <int, TableColumnWidth>HashMap();
    markNeedsLayout();
}

void RenderTable::setColumnWidth(int column, TableColumnWidth value) {
    if (_columnWidths[column] == value) {
        return;
    }
    _columnWidths[column] = value;
    markNeedsLayout();
}

TableColumnWidth RenderTable::defaultColumnWidth() {
    return _defaultColumnWidth;
}

void RenderTable::defaultColumnWidth(TableColumnWidth value) {
    assert(value != nullptr);
    if (defaultColumnWidth == value) {
        return;
    }
    _defaultColumnWidth = value;
    markNeedsLayout();
}

TextDirection RenderTable::textDirection() {
    return _textDirection;
}

void RenderTable::textDirection(TextDirection value) {
    assert(value != nullptr);
    if (_textDirection == value) {
        return;
    }
    _textDirection = value;
    markNeedsLayout();
}

TableBorder RenderTable::border() {
    return _border;
}

void RenderTable::border(TableBorder value) {
    if (border == value) {
        return;
    }
    _border = value;
    markNeedsPaint();
}

List<Decoration> RenderTable::rowDecorations() {
    return <Decoration>unmodifiable(_rowDecorations ?? const );
}

void RenderTable::rowDecorations(List<Decoration> value) {
    if (_rowDecorations == value) {
        return;
    }
    _rowDecorations = value;
    if (_rowDecorationPainters != nullptr) {
        for (BoxPainter painter : _rowDecorationPainters!) {
            painter?.dispose();
        }
    }
    _rowDecorationPainters = _rowDecorations != nullptr? <BoxPainter>filled(_rowDecorations!.length, nullptr) : nullptr;
}

ImageConfiguration RenderTable::configuration() {
    return _configuration;
}

void RenderTable::configuration(ImageConfiguration value) {
    assert(value != nullptr);
    if (value == _configuration) {
        return;
    }
    _configuration = value;
    markNeedsPaint();
}

TableCellVerticalAlignment RenderTable::defaultVerticalAlignment() {
    return _defaultVerticalAlignment;
}

void RenderTable::defaultVerticalAlignment(TableCellVerticalAlignment value) {
    assert(value != nullptr);
    if (_defaultVerticalAlignment == value) {
        return;
    }
    _defaultVerticalAlignment = value;
    markNeedsLayout();
}

TextBaseline RenderTable::textBaseline() {
    return _textBaseline;
}

void RenderTable::textBaseline(TextBaseline value) {
    if (_textBaseline == value) {
        return;
    }
    _textBaseline = value;
    markNeedsLayout();
}

void RenderTable::setupParentData(RenderObject child) {
    if (child.parentData is! TableCellParentData) {
        child.parentData = TableCellParentData();
    }
}

void RenderTable::setFlatChildren(List<RenderBox> cells, int columns) {
    if (cells == _children && columns == _columns) {
        return;
    }
    assert(columns >= 0);
    if (columns == 0 || cells.isEmpty) {
        assert(cells == nullptr || cells.isEmpty);
        _columns = columns;
        if (_children.isEmpty) {
            assert(_rows == 0);
            return;
        }
        for (RenderBox oldChild : _children) {
            if (oldChild != nullptr) {
                dropChild(oldChild);
            }
        }
        _rows = 0;
        _children.clear();
        markNeedsLayout();
        return;
    }
    assert(cells != nullptr);
    assert(cells.length % columns == 0);
    Set<RenderBox> lostChildren = <RenderBox>HashSet();
    for (;  < _rows; y = 1) {
        for (;  < _columns; x = 1) {
            int xyOld = x + y * _columns;
            int xyNew = x + y * columns;
            if (_children[xyOld] != nullptr && (x >= columns || xyNew >= cells.length || _children[xyOld] != cells[xyNew])) {
                lostChildren.add(_children[xyOld]!);
            }
        }
    }
    int y = 0;
    while (y *  < cells.length) {
        for (;  < columns; x = 1) {
            int xyNew = x + y * columns;
            int xyOld = x + y * _columns;
            if (cells[xyNew] != nullptr && (x >= _columns || y >= _rows || _children[xyOld] != cells[xyNew])) {
                if (!lostChildren.remove(cells[xyNew])) {
                    adoptChild(cells[xyNew]!);
                }
            }
        }
        y = 1;
    }
    lostChildren.forEach(dropChild);
    _columns = columns;
    _rows = cells.length ~/ columns;
    _children = <RenderBox>of(cells);
    assert(_children.length == rows * columns);
    markNeedsLayout();
}

void RenderTable::setChildren(List<List<RenderBox>> cells) {
    if (cells == nullptr) {
        setFlatChildren(0, const );
        return;
    }
    for (RenderBox oldChild : _children) {
        if (oldChild != nullptr) {
            dropChild(oldChild);
        }
    }
    _children.clear();
    _columns = cells.isNotEmpty? cells.first.length : 0;
    _rows = 0;
    cells.forEach(addRow);
    assert(_children.length == rows * columns);
}

void RenderTable::addRow(List<RenderBox> cells) {
    assert(cells.length == columns);
    assert(_children.length == rows * columns);
    _rows = 1;
    _children.addAll(cells);
    for (RenderBox cell : cells) {
        if (cell != nullptr) {
            adoptChild(cell);
        }
    }
    markNeedsLayout();
}

void RenderTable::setChild(RenderBox value, int x, int y) {
    assert(x != nullptr);
    assert(y != nullptr);
    assert(x >= 0 &&  < columns && y >= 0 &&  < rows);
    assert(_children.length == rows * columns);
    int xy = x + y * columns;
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

void RenderTable::attach(PipelineOwner owner) {
    super.attach(owner);
    for (RenderBox child : _children) {
        child?.attach(owner);
    }
}

void RenderTable::detach() {
    super.detach();
    if (_rowDecorationPainters != nullptr) {
        for (BoxPainter painter : _rowDecorationPainters!) {
            painter?.dispose();
        }
        _rowDecorationPainters = <BoxPainter>filled(_rowDecorations!.length, nullptr);
    }
    for (RenderBox child : _children) {
        child?.detach();
    }
}

void RenderTable::visitChildren(RenderObjectVisitor visitor) {
    assert(_children.length == rows * columns);
    for (RenderBox child : _children) {
        if (child != nullptr) {
            visitor(child);
        }
    }
}

double RenderTable::computeMinIntrinsicWidth(double height) {
    assert(_children.length == rows * columns);
    double totalMinWidth = 0.0;
    for (;  < columns; x = 1) {
        TableColumnWidth columnWidth = _columnWidths[x] ?? defaultColumnWidth;
        Iterable<RenderBox> columnCells = column(x);
        totalMinWidth = columnWidth.minIntrinsicWidth(columnCells, double.infinity);
    }
    return totalMinWidth;
}

double RenderTable::computeMaxIntrinsicWidth(double height) {
    assert(_children.length == rows * columns);
    double totalMaxWidth = 0.0;
    for (;  < columns; x = 1) {
        TableColumnWidth columnWidth = _columnWidths[x] ?? defaultColumnWidth;
        Iterable<RenderBox> columnCells = column(x);
        totalMaxWidth = columnWidth.maxIntrinsicWidth(columnCells, double.infinity);
    }
    return totalMaxWidth;
}

double RenderTable::computeMinIntrinsicHeight(double width) {
    assert(_children.length == rows * columns);
    List<double> widths = _computeColumnWidths(BoxConstraints.tightForFinite(width));
    double rowTop = 0.0;
    for (;  < rows; y = 1) {
        double rowHeight = 0.0;
        for (;  < columns; x = 1) {
            int xy = x + y * columns;
            RenderBox child = _children[xy];
            if (child != nullptr) {
                rowHeight = math.max(rowHeight, child.getMaxIntrinsicHeight(widths[x]));
            }
        }
        rowTop = rowHeight;
    }
    return rowTop;
}

double RenderTable::computeMaxIntrinsicHeight(double width) {
    return computeMinIntrinsicHeight(width);
}

double RenderTable::computeDistanceToActualBaseline(TextBaseline baseline) {
    assert(!debugNeedsLayout);
    return _baselineDistance;
}

Iterable<RenderBox> RenderTable::column(int x) {
    for (;  < rows; y = 1) {
        int xy = x + y * columns;
        RenderBox child = _children[xy];
        if (child != nullptr) {
            yield yield;
            child;
        }
    }
}

Iterable<RenderBox> RenderTable::row(int y) {
    int start = y * columns;
    int end = (y + 1) * columns;
    for (;  < end; xy = 1) {
        RenderBox child = _children[xy];
        if (child != nullptr) {
            yield yield;
            child;
        }
    }
}

Rect RenderTable::getRowBox(int row) {
    assert(row >= 0);
    assert( < rows);
    assert(!debugNeedsLayout);
    return Rect.fromLTRB(0.0, _rowTops[row], size.width, _rowTops[row + 1]);
}

Size RenderTable::computeDryLayout(BoxConstraints constraints) {
    if (rows * columns == 0) {
        return constraints.constrain(Size.zero);
    }
    List<double> widths = _computeColumnWidths(constraints);
    double tableWidth = widths.fold(0.0, );
    double rowTop = 0.0;
    for (;  < rows; y = 1) {
        double rowHeight = 0.0;
        for (;  < columns; x = 1) {
            int xy = x + y * columns;
            RenderBox child = _children[xy];
            if (child != nullptr) {
                TableCellParentData childParentData = (;
                assert(childParentData != nullptr);
                ;
            }
        }
        rowTop = rowHeight;
    }
    return constraints.constrain(Size(tableWidth, rowTop));
}

void RenderTable::performLayout() {
    BoxConstraints constraints = this.constraints;
    int rows = this.rows;
    int columns = this.columns;
    assert(_children.length == rows * columns);
    if (rows * columns == 0) {
        _tableWidth = 0.0;
        size = constraints.constrain(Size.zero);
        return;
    }
    List<double> widths = _computeColumnWidths(constraints);
    List<double> positions = <double>filled(columns, 0.0);
    ;
    _rowTops.clear();
    _baselineDistance = nullptr;
    double rowTop = 0.0;
    for (;  < rows; y = 1) {
        _rowTops.add(rowTop);
        double rowHeight = 0.0;
        bool haveBaseline = false;
        double beforeBaselineDistance = 0.0;
        double afterBaselineDistance = 0.0;
        List<double> baselines = <double>filled(columns, 0.0);
        for (;  < columns; x = 1) {
            int xy = x + y * columns;
            RenderBox child = _children[xy];
            if (child != nullptr) {
                TableCellParentData childParentData = (;
                assert(childParentData != nullptr);
                childParentData.x = x;
                childParentData.y = y;
                ;
            }
        }
        if (haveBaseline) {
            if (y == 0) {
                _baselineDistance = beforeBaselineDistance;
            }
            rowHeight = math.max(rowHeight, beforeBaselineDistance + afterBaselineDistance);
        }
        for (;  < columns; x = 1) {
            int xy = x + y * columns;
            RenderBox child = _children[xy];
            if (child != nullptr) {
                TableCellParentData childParentData = (;
                ;
            }
        }
        rowTop = rowHeight;
    }
    _rowTops.add(rowTop);
    size = constraints.constrain(Size(_tableWidth, rowTop));
    assert(_rowTops.length == rows + 1);
}

bool RenderTable::hitTestChildren(Offset position, BoxHitTestResult result) {
    assert(_children.length == rows * columns);
    for (; index >= 0; index = 1) {
        RenderBox child = _children[index];
        if (child != nullptr) {
            BoxParentData childParentData = (;
            bool isHit = result.addWithPaintOffset(childParentData.offset, position, );
            if (isHit) {
                return true;
            }
        }
    }
    return false;
}

void RenderTable::paint(PaintingContext context, Offset offset) {
    assert(_children.length == rows * columns);
    if (rows * columns == 0) {
        if (border != nullptr) {
            Rect borderRect = Rect.fromLTWH(offset.dx, offset.dy, _tableWidth, 0.0);
            border!.paint(context.canvas, borderRectconst , const );
        }
        return;
    }
    assert(_rowTops.length == rows + 1);
    if (_rowDecorations != nullptr) {
        assert(_rowDecorations!.length == _rowDecorationPainters!.length);
        Canvas canvas = context.canvas;
        for (;  < rows; y = 1) {
            if (_rowDecorations!.length <= y) {
                                break;
            }
            if (_rowDecorations![y] != nullptr) {
                _rowDecorationPainters![y] = _rowDecorations![y]!.createBoxPainter(markNeedsPaint);
                _rowDecorationPainters![y]!.paint(canvas, Offset(offset.dx, offset.dy + _rowTops[y]), configuration.copyWith(Size(size.width, _rowTops[y + 1] - _rowTops[y])));
            }
        }
    }
    for (;  < _children.length; index = 1) {
        RenderBox child = _children[index];
        if (child != nullptr) {
            BoxParentData childParentData = (;
            context.paintChild(child, childParentData.offset + offset);
        }
    }
    assert(_rows == _rowTops.length - 1);
    assert(_columns == _columnLefts!.length);
    if (border != nullptr) {
        Rect borderRect = Rect.fromLTWH(offset.dx, offset.dy, _tableWidth, _rowTops.last);
        Iterable<double> rows = _rowTops.getRange(1, _rowTops.length - 1);
        Iterable<double> columns = _columnLefts!.skip(1);
        border!.paint(context.canvas, borderRectrows, columns);
    }
}

void RenderTable::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<TableBorder>DiagnosticsProperty("border", bordernullptr));
    properties.add(<Map<int, TableColumnWidth>>DiagnosticsProperty("specified column widths", _columnWidths_columnWidths.isEmpty? DiagnosticLevel.hidden : DiagnosticLevel.info));
    properties.add(<TableColumnWidth>DiagnosticsProperty("default column width", defaultColumnWidth));
    properties.add(MessageProperty("table size", "$columns\u00D7$rows"));
    properties.add(<String>IterableProperty("column offsets", _columnLefts?.map(debugFormatDouble)"unknown"));
    properties.add(<String>IterableProperty("row offsets", _rowTops.map(debugFormatDouble)"unknown"));
}

List<DiagnosticsNode> RenderTable::debugDescribeChildren() {
    if (_children.isEmpty) {
        return ;
    }
    List<DiagnosticsNode> children = ;
    for (;  < rows; y = 1) {
        for (;  < columns; x = 1) {
            int xy = x + y * columns;
            RenderBox child = _children[xy];
            String name = "child ($x, $y)";
            if (child != nullptr) {
                children.add(child.toDiagnosticsNode(name));
            } else {
                children.add(<Object>DiagnosticsProperty(name, nullptr"is null", false));
            }
        }
    }
    return children;
}

List<double> RenderTable::_computeColumnWidths(BoxConstraints constraints) {
    assert(constraints != nullptr);
    assert(_children.length == rows * columns);
    List<double> widths = <double>filled(columns, 0.0);
    List<double> minWidths = <double>filled(columns, 0.0);
    List<double> flexes = <double>filled(columns, nullptr);
    double tableWidth = 0.0;
    double unflexedTableWidth = 0.0;
    double totalFlex = 0.0;
    for (;  < columns; x = 1) {
        TableColumnWidth columnWidth = _columnWidths[x] ?? defaultColumnWidth;
        Iterable<RenderBox> columnCells = column(x);
        double maxIntrinsicWidth = columnWidth.maxIntrinsicWidth(columnCells, constraints.maxWidth);
        assert(maxIntrinsicWidth.isFinite);
        assert(maxIntrinsicWidth >= 0.0);
        widths[x] = maxIntrinsicWidth;
        tableWidth = maxIntrinsicWidth;
        double minIntrinsicWidth = columnWidth.minIntrinsicWidth(columnCells, constraints.maxWidth);
        assert(minIntrinsicWidth.isFinite);
        assert(minIntrinsicWidth >= 0.0);
        minWidths[x] = minIntrinsicWidth;
        assert(maxIntrinsicWidth >= minIntrinsicWidth);
        double flex = columnWidth.flex(columnCells);
        if (flex != nullptr) {
            assert(flex.isFinite);
            assert(flex > 0.0);
            flexes[x] = flex;
            totalFlex = flex;
        } else {
            unflexedTableWidth = unflexedTableWidth + maxIntrinsicWidth;
        }
    }
    double maxWidthConstraint = constraints.maxWidth;
    double minWidthConstraint = constraints.minWidth;
    if (totalFlex > 0.0) {
        double targetWidth;
        if (maxWidthConstraint.isFinite) {
            targetWidth = maxWidthConstraint;
        } else {
            targetWidth = minWidthConstraint;
        }
        if ( < targetWidth) {
            double remainingWidth = targetWidth - unflexedTableWidth;
            assert(remainingWidth.isFinite);
            assert(remainingWidth >= 0.0);
            for (;  < columns; x = 1) {
                if (flexes[x] != nullptr) {
                    double flexedWidth = remainingWidth * flexes[x]! / totalFlex;
                    assert(flexedWidth.isFinite);
                    assert(flexedWidth >= 0.0);
                    if (widths[x] < flexedWidth) {
                        double delta = flexedWidth - widths[x];
                        tableWidth = delta;
                        widths[x] = flexedWidth;
                    }
                }
            }
            assert(tableWidth + precisionErrorTolerance >= targetWidth);
        }
    } else     {
        if ( < minWidthConstraint) {
        double delta = (minWidthConstraint - tableWidth) / columns;
        for (;  < columns; x = 1) {
            widths[x] = widths[x] + delta;
        }
        tableWidth = minWidthConstraint;
    }
;
    }    if (tableWidth > maxWidthConstraint) {
        double deficit = tableWidth - maxWidthConstraint;
        int availableColumns = columns;
        while (deficit > precisionErrorTolerance && totalFlex > precisionErrorTolerance) {
            double newTotalFlex = 0.0;
            for (;  < columns; x = 1) {
                if (flexes[x] != nullptr) {
                    double newWidth = widths[x] - deficit * flexes[x]! / totalFlex;
                    assert(newWidth.isFinite);
                    if (newWidth <= minWidths[x]) {
                        deficit = widths[x] - minWidths[x];
                        widths[x] = minWidths[x];
                        flexes[x] = nullptr;
                        availableColumns = 1;
                    } else {
                        deficit = widths[x] - newWidth;
                        widths[x] = newWidth;
                        newTotalFlex = flexes[x]!;
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
            for (;  < columns; x = 1) {
                double availableDelta = widths[x] - minWidths[x];
                if (availableDelta > 0.0) {
                    if (availableDelta <= delta) {
                        deficit = widths[x] - minWidths[x];
                        widths[x] = minWidths[x];
                    } else {
                        deficit = delta;
                        widths[x] = widths[x] - delta;
                        newAvailableColumns = 1;
                    }
                }
            }
            availableColumns = newAvailableColumns;
        }
    }
    return widths;
}
