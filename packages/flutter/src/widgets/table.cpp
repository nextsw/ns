#include "table.hpp"
String TableRow::toString() {
    StringBuffer result = StringBuffer();
    result.write("TableRow(");
    if (key != nullptr) {
        result.write("$key, ");
    }
    if (decoration != nullptr) {
        result.write("$decoration, ");
    }
    if (children == nullptr) {
        result.write("child list is null");
    } else     {
        if (children!.isEmpty) {
        result.write("no children");
    } else {
        result.write("$children");
    }
;
    }    result.write(")");
    return result.toString();
}

Table::Table(TableBorder border, List<TableRow> children, Map<int, TableColumnWidth> columnWidths, TableColumnWidth defaultColumnWidth, TableCellVerticalAlignment defaultVerticalAlignment, Unknown, TextBaseline textBaseline, TextDirection textDirection) {
    {
        assert(children != nullptr);
        assert(defaultColumnWidth != nullptr);
        assert(defaultVerticalAlignment != nullptr);
        assert(defaultVerticalAlignment != TableCellVerticalAlignment.baseline || textBaseline != nullptr, "textBaseline is required if you specify the defaultVerticalAlignment with TableCellVerticalAlignment.baseline");
        assert(());
        assert(());
        assert(());
        assert(());
        _rowDecorations = children.any()? children.<Decoration>map().toList(false) : nullptr;
    }
    {
        assert(());
    }
}

RenderObjectElement Table::createElement() {
    return _TableElement(this);
}

RenderTable Table::createRenderObject(BuildContext context) {
    assert(debugCheckHasDirectionality(context));
    return RenderTable(children.isNotEmpty? children[0].children!.length : 0, children.length, columnWidths, defaultColumnWidth, textDirection ?? Directionality.of(context), border, _rowDecorations, createLocalImageConfiguration(context), defaultVerticalAlignment, textBaseline);
}

void Table::updateRenderObject(BuildContext context, RenderTable renderObject) {
    assert(debugCheckHasDirectionality(context));
    assert(renderObject.columns == (children.isNotEmpty? children[0].children!.length : 0));
    assert(renderObject.rows == children.length);
    ;
}

RenderTable _TableElement::renderObject() {
    return (;
}

void _TableElement::mount(Object newSlot, Element parent) {
    assert(!_doingMountOrUpdate);
    _doingMountOrUpdate = true;
    super.mount(parent, newSlot);
    int rowIndex = -1;
    _children = (().children.<_TableElementRow>map().toList(false);
    _updateRenderObjectChildren();
    assert(_doingMountOrUpdate);
    _doingMountOrUpdate = false;
}

void _TableElement::insertRenderObjectChild(RenderBox child, _TableSlot slot) {
    renderObject.setupParentData(child);
    if (!_doingMountOrUpdate) {
        renderObject.setChild(slot.column, slot.row, child);
    }
}

void _TableElement::moveRenderObjectChild(RenderBox child, _TableSlot newSlot, _TableSlot oldSlot) {
    assert(_doingMountOrUpdate);
}

void _TableElement::removeRenderObjectChild(RenderBox child, _TableSlot slot) {
    renderObject.setChild(slot.column, slot.row, nullptr);
}

void _TableElement::update(Table newWidget) {
    assert(!_doingMountOrUpdate);
    _doingMountOrUpdate = true;
    Map<LocalKey, List<Element>> oldKeyedRows = ;
    for (_TableElementRow row : _children) {
        if (row.key != nullptr) {
            oldKeyedRows[row.key!] = row.children;
        }
    }
    Iterator<_TableElementRow> oldUnkeyedRows = _children.where().iterator;
    List<_TableElementRow> newChildren = ;
    Set<List<Element>> taken = ;
    for (;  < newWidget.children.length; rowIndex++) {
        TableRow row = newWidget.children[rowIndex];
        List<Element> oldChildren;
        if (row.key != nullptr && oldKeyedRows.containsKey(row.key)) {
            oldChildren = oldKeyedRows[row.key]!;
            taken.add(oldChildren);
        } else         {
            if (row.key == nullptr && oldUnkeyedRows.moveNext()) {
            oldChildren = oldUnkeyedRows.current.children;
        } else {
            oldChildren = const ;
        }
;
        }        List<_TableSlot> slots = <_TableSlot>generate(row.children!.length, );
        newChildren.add(_TableElementRow(row.key, updateChildren(oldChildren, row.children!_forgottenChildren, slots)));
    }
    while (oldUnkeyedRows.moveNext()) {
        updateChildren(oldUnkeyedRows.current.children, const _forgottenChildren);
    }
    for (List<Element> oldChildren : oldKeyedRows.values.where()) {
        updateChildren(oldChildren, const _forgottenChildren);
    }
    _children = newChildren;
    _updateRenderObjectChildren();
    _forgottenChildren.clear();
    super.update(newWidget);
    assert(widget == newWidget);
    assert(_doingMountOrUpdate);
    _doingMountOrUpdate = false;
}

void _TableElement::visitChildren(ElementVisitor visitor) {
    for (Element child : _children.<Element>expand()) {
        if (!_forgottenChildren.contains(child)) {
            visitor(child);
        }
    }
}

bool _TableElement::forgetChild(Element child) {
    _forgottenChildren.add(child);
    super.forgetChild(child);
    return true;
}

void _TableElement::_updateRenderObjectChildren() {
    assert(renderObject != nullptr);
    renderObject.setFlatChildren(_children.isNotEmpty? _children[0].children.length : 0, _children.<RenderBox>expand().toList());
}

void TableCell::applyParentData(RenderObject renderObject) {
    TableCellParentData parentData = (;
    if (parentData.verticalAlignment != verticalAlignment) {
        parentData.verticalAlignment = verticalAlignment;
        AbstractNode targetParent = renderObject.parent;
        if (targetParent is RenderObject) {
            targetParent.markNeedsLayout();
        }
    }
}

Type TableCell::debugTypicalAncestorWidgetClass() {
    return Table;
}

void TableCell::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<TableCellVerticalAlignment>EnumProperty("verticalAlignment", verticalAlignment));
}

bool _TableSlot::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is _TableSlot && column == other.column && row == other.row;
}

int _TableSlot::hashCode() {
    return Object.hash(column, row);
}

void _TableSlot::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(IntProperty("x", column));
    properties.add(IntProperty("y", row));
}
