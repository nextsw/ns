#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_TABLE
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_TABLE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "box.hpp"
#include "object.hpp"
#include "table_border.hpp"


class TableCellParentDataCls : public BoxParentDataCls {
public:
    TableCellVerticalAlignment verticalAlignment;

    int x;

    int y;


    virtual String toString();

private:

};
using TableCellParentData = std::shared_ptr<TableCellParentDataCls>;

class TableColumnWidthCls : public ObjectCls {
public:

     TableColumnWidthCls();
    virtual double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);
    virtual double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);
    virtual double flex(Iterable<RenderBox> cells);

    virtual String toString();

private:

};
using TableColumnWidth = std::shared_ptr<TableColumnWidthCls>;

class IntrinsicColumnWidthCls : public TableColumnWidthCls {
public:

     IntrinsicColumnWidthCls(double flex);

    virtual double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    virtual double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    virtual double flex(Iterable<RenderBox> cells);

    virtual String toString();

private:
    double _flex;


};
using IntrinsicColumnWidth = std::shared_ptr<IntrinsicColumnWidthCls>;

class FixedColumnWidthCls : public TableColumnWidthCls {
public:
    double value;


     FixedColumnWidthCls(double value);

    virtual double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    virtual double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    virtual String toString();

private:

};
using FixedColumnWidth = std::shared_ptr<FixedColumnWidthCls>;

class FractionColumnWidthCls : public TableColumnWidthCls {
public:
    double value;


     FractionColumnWidthCls(double value);

    virtual double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    virtual double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    virtual String toString();

private:

};
using FractionColumnWidth = std::shared_ptr<FractionColumnWidthCls>;

class FlexColumnWidthCls : public TableColumnWidthCls {
public:
    double value;


     FlexColumnWidthCls(double value);

    virtual double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    virtual double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    virtual double flex(Iterable<RenderBox> cells);

    virtual String toString();

private:

};
using FlexColumnWidth = std::shared_ptr<FlexColumnWidthCls>;

class MaxColumnWidthCls : public TableColumnWidthCls {
public:
    TableColumnWidth a;

    TableColumnWidth b;


     MaxColumnWidthCls(TableColumnWidth a, TableColumnWidth b);
    virtual double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    virtual double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    virtual double flex(Iterable<RenderBox> cells);

    virtual String toString();

private:

};
using MaxColumnWidth = std::shared_ptr<MaxColumnWidthCls>;

class MinColumnWidthCls : public TableColumnWidthCls {
public:
    TableColumnWidth a;

    TableColumnWidth b;


     MinColumnWidthCls(TableColumnWidth a, TableColumnWidth b);
    virtual double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    virtual double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    virtual double flex(Iterable<RenderBox> cells);

    virtual String toString();

private:

};
using MinColumnWidth = std::shared_ptr<MinColumnWidthCls>;

enum TableCellVerticalAlignment{
    top,
    middle,
    bottom,
    baseline,
    fill,
} // end TableCellVerticalAlignment

class RenderTableCls : public RenderBoxCls {
public:

     RenderTableCls(TableBorder border, List<List<RenderBox>> children, Map<int, TableColumnWidth> columnWidths, int columns, ImageConfiguration configuration, TableColumnWidth defaultColumnWidth, TableCellVerticalAlignment defaultVerticalAlignment, List<Decoration> rowDecorations, int rows, TextBaseline textBaseline, TextDirection textDirection);

    virtual int columns();

    virtual void  columns(int value);

    virtual int rows();

    virtual void  rows(int value);

    virtual Map<int, TableColumnWidth> columnWidths();

    virtual void  columnWidths(Map<int, TableColumnWidth> value);

    virtual void setColumnWidth(int column, TableColumnWidth value);

    virtual TableColumnWidth defaultColumnWidth();

    virtual void  defaultColumnWidth(TableColumnWidth value);

    virtual TextDirection textDirection();

    virtual void  textDirection(TextDirection value);

    virtual TableBorder border();

    virtual void  border(TableBorder value);

    virtual List<Decoration> rowDecorations();

    virtual void  rowDecorations(List<Decoration> value);

    virtual ImageConfiguration configuration();

    virtual void  configuration(ImageConfiguration value);

    virtual TableCellVerticalAlignment defaultVerticalAlignment();

    virtual void  defaultVerticalAlignment(TableCellVerticalAlignment value);

    virtual TextBaseline textBaseline();

    virtual void  textBaseline(TextBaseline value);

    virtual void setupParentData(RenderObject child);

    virtual void setFlatChildren(List<RenderBox> cells, int columns);

    virtual void setChildren(List<List<RenderBox>> cells);

    virtual void addRow(List<RenderBox> cells);

    virtual void setChild(RenderBox value, int x, int y);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual void visitChildren(RenderObjectVisitor visitor);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual double computeDistanceToActualBaseline(TextBaseline baseline);

    virtual Iterable<RenderBox> column(int x);

    virtual Iterable<RenderBox> row(int y);

    virtual Rect getRowBox(int row);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual bool hitTestChildren(Offset position, BoxHitTestResult result);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:
    List<RenderBox> _children;

    int _columns;

    int _rows;

    Map<int, TableColumnWidth> _columnWidths;

    TableColumnWidth _defaultColumnWidth;

    TextDirection _textDirection;

    TableBorder _border;

    List<Decoration> _rowDecorations;

    List<BoxPainter> _rowDecorationPainters;

    ImageConfiguration _configuration;

    TableCellVerticalAlignment _defaultVerticalAlignment;

    TextBaseline _textBaseline;

    double _baselineDistance;

    List<double> _rowTops;

    Iterable<double> _columnLefts;

    double _tableWidth;


    virtual List<double> _computeColumnWidths(BoxConstraints constraints);

};
using RenderTable = std::shared_ptr<RenderTableCls>;


#endif