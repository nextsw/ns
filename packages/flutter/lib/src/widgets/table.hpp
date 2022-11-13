#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TABLE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_TABLE
#include <base.hpp>
#include <packages/flutter/lib/rendering.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "image.hpp"


class TableRowCls : public ObjectCls {
public:
    LocalKey key;

    Decoration decoration;

    List<Widget> children;


     TableRowCls(List<Widget> children, Decoration decoration, LocalKey key);
    virtual String toString();

private:

};
using TableRow = std::shared_ptr<TableRowCls>;

class _TableElementRowCls : public ObjectCls {
public:
    LocalKey key;

    List<Element> children;


private:

     _TableElementRowCls(List<Element> children, LocalKey key);
};
using _TableElementRow = std::shared_ptr<_TableElementRowCls>;

class TableCls : public RenderObjectWidgetCls {
public:
    List<TableRow> children;

    Map<int, TableColumnWidth> columnWidths;

    TableColumnWidth defaultColumnWidth;

    TextDirection textDirection;

    TableBorder border;

    TableCellVerticalAlignment defaultVerticalAlignment;

    TextBaseline textBaseline;


     TableCls(TableBorder border, List<TableRow> children, Map<int, TableColumnWidth> columnWidths, TableColumnWidth defaultColumnWidth, TableCellVerticalAlignment defaultVerticalAlignment, Key key, TextBaseline textBaseline, TextDirection textDirection);

    virtual RenderObjectElement createElement();

    virtual RenderTable createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderTable renderObject);

private:
    List<Decoration> _rowDecorations;


};
using Table = std::shared_ptr<TableCls>;

class _TableElementCls : public RenderObjectElementCls {
public:

    virtual RenderTable renderObject();

    virtual void mount(Element parent, Object newSlot);

    virtual void insertRenderObjectChild(RenderBox child, _TableSlot slot);

    virtual void moveRenderObjectChild(RenderBox child, _TableSlot oldSlot, _TableSlot newSlot);

    virtual void removeRenderObjectChild(RenderBox child, _TableSlot slot);

    virtual void update(Table newWidget);

    virtual void visitChildren(ElementVisitor visitor);

    virtual bool forgetChild(Element child);

private:
    List<_TableElementRow> _children;

    bool _doingMountOrUpdate;

    Set<Element> _forgottenChildren;


     _TableElementCls(Widget widget);
    virtual void _updateRenderObjectChildren();

};
using _TableElement = std::shared_ptr<_TableElementCls>;

class TableCellCls : public ParentDataWidgetCls<TableCellParentData> {
public:
    TableCellVerticalAlignment verticalAlignment;


     TableCellCls(Widget child, Key key, TableCellVerticalAlignment verticalAlignment);
    virtual void applyParentData(RenderObject renderObject);

    virtual Type debugTypicalAncestorWidgetClass();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using TableCell = std::shared_ptr<TableCellCls>;

class _TableSlotCls : public ObjectCls {
public:
    int column;

    int row;


    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

     _TableSlotCls(int column, int row);
};
using _TableSlot = std::shared_ptr<_TableSlotCls>;


#endif