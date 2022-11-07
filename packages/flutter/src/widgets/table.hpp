#ifndef TABLE_H
#define TABLE_H
#include <memory>
#include <flutter/rendering.hpp>

#include <collection/collection.hpp>
#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "image.hpp"



class TableRow {
public:
    LocalKey key;

    Decoration decoration;

    List<Widget> children;


     TableRow(List<Widget> children, Decoration decoration, LocalKey key);

    String toString();

private:

};

class _TableElementRow {
public:
    LocalKey key;

    List<Element> children;


private:

     _TableElementRow(List<Element> children, LocalKey key);

};

class Table : RenderObjectWidget {
public:
    List<TableRow> children;

    Map<int, TableColumnWidth> columnWidths;

    TableColumnWidth defaultColumnWidth;

    TextDirection textDirection;

    TableBorder border;

    TableCellVerticalAlignment defaultVerticalAlignment;

    TextBaseline textBaseline;


     Table(TableBorder border, List<TableRow> children, Map<int, TableColumnWidth> columnWidths, TableColumnWidth defaultColumnWidth, TableCellVerticalAlignment defaultVerticalAlignment, Unknown, TextBaseline textBaseline, TextDirection textDirection);

    RenderObjectElement createElement();

    RenderTable createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderTable renderObject);

private:
    List<Decoration> _rowDecorations;


};

class _TableElement : RenderObjectElement {
public:

    RenderTable renderObject();

    void mount(Object newSlot, Element parent);

    void insertRenderObjectChild(RenderBox child, _TableSlot slot);

    void moveRenderObjectChild(RenderBox child, _TableSlot newSlot, _TableSlot oldSlot);

    void removeRenderObjectChild(RenderBox child, _TableSlot slot);

    void update(Table newWidget);

    void visitChildren(ElementVisitor visitor);

    bool forgetChild(Element child);

private:
    List<_TableElementRow> _children;

    bool _doingMountOrUpdate;

    Set<Element> _forgottenChildren;


     _TableElement(Table widget);

    void _updateRenderObjectChildren();

};

class TableCell : ParentDataWidget<TableCellParentData> {
public:
    TableCellVerticalAlignment verticalAlignment;


     TableCell(Unknown, Unknown, TableCellVerticalAlignment verticalAlignment);

    void applyParentData(RenderObject renderObject);

    Type debugTypicalAncestorWidgetClass();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _TableSlot {
public:
    int column;

    int row;


    bool ==(Object other);

    int hashCode();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

     _TableSlot(int column, int row);

};

#endif