#ifndef TABLE_H
#define TABLE_H
#include <memory>

#include <collection/collection.hpp>
#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include "box.hpp"
#include "object.hpp"
#include "table_border.hpp"



class TableCellParentData : BoxParentData {
public:
    TableCellVerticalAlignment verticalAlignment;

    int x;

    int y;


    String toString();

private:

};

class TableColumnWidth {
public:

     TableColumnWidth();

    double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    double flex(Iterable<RenderBox> cells);

    String toString();

private:

};

class IntrinsicColumnWidth : TableColumnWidth {
public:

     IntrinsicColumnWidth(double flex);

    double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    double flex(Iterable<RenderBox> cells);

    String toString();

private:
    double _flex;


};

class FixedColumnWidth : TableColumnWidth {
public:
    double value;


     FixedColumnWidth(double value);

    double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    String toString();

private:

};

class FractionColumnWidth : TableColumnWidth {
public:
    double value;


     FractionColumnWidth(double value);

    double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    String toString();

private:

};

class FlexColumnWidth : TableColumnWidth {
public:
    double value;


     FlexColumnWidth(double value);

    double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    double flex(Iterable<RenderBox> cells);

    String toString();

private:

};

class MaxColumnWidth : TableColumnWidth {
public:
    TableColumnWidth a;

    TableColumnWidth b;


     MaxColumnWidth(TableColumnWidth a, TableColumnWidth b);

    double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    double flex(Iterable<RenderBox> cells);

    String toString();

private:

};

class MinColumnWidth : TableColumnWidth {
public:
    TableColumnWidth a;

    TableColumnWidth b;


     MinColumnWidth(TableColumnWidth a, TableColumnWidth b);

    double minIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    double maxIntrinsicWidth(Iterable<RenderBox> cells, double containerWidth);

    double flex(Iterable<RenderBox> cells);

    String toString();

private:

};

enum TableCellVerticalAlignment{
    top,
    middle,
    bottom,
    baseline,
    fill,
} // end TableCellVerticalAlignment

class RenderTable : RenderBox {
public:

     RenderTable(TableBorder border, List<List<RenderBox>> children, Map<int, TableColumnWidth> columnWidths, int columns, ImageConfiguration configuration, TableColumnWidth defaultColumnWidth, TableCellVerticalAlignment defaultVerticalAlignment, List<Decoration> rowDecorations, int rows, TextBaseline textBaseline, TextDirection textDirection);

    int columns();

    void  columns(int value);

    int rows();

    void  rows(int value);

    Map<int, TableColumnWidth> columnWidths();

    void  columnWidths(Map<int, TableColumnWidth> value);

    void setColumnWidth(int column, TableColumnWidth value);

    TableColumnWidth defaultColumnWidth();

    void  defaultColumnWidth(TableColumnWidth value);

    TextDirection textDirection();

    void  textDirection(TextDirection value);

    TableBorder border();

    void  border(TableBorder value);

    List<Decoration> rowDecorations();

    void  rowDecorations(List<Decoration> value);

    ImageConfiguration configuration();

    void  configuration(ImageConfiguration value);

    TableCellVerticalAlignment defaultVerticalAlignment();

    void  defaultVerticalAlignment(TableCellVerticalAlignment value);

    TextBaseline textBaseline();

    void  textBaseline(TextBaseline value);

    void setupParentData(RenderObject child);

    void setFlatChildren(List<RenderBox> cells, int columns);

    void setChildren(List<List<RenderBox>> cells);

    void addRow(List<RenderBox> cells);

    void setChild(RenderBox value, int x, int y);

    void attach(PipelineOwner owner);

    void detach();

    void visitChildren(RenderObjectVisitor visitor);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    double computeDistanceToActualBaseline(TextBaseline baseline);

    Iterable<RenderBox> column(int x);

    Iterable<RenderBox> row(int y);

    Rect getRowBox(int row);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    List<DiagnosticsNode> debugDescribeChildren();

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


    List<double> _computeColumnWidths(BoxConstraints constraints);

};

#endif