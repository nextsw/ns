#include "table.hpp"
String TableRowCls::toString() {
    StringBuffer result = make<StringBufferCls>();
    result->write(__s("TableRow("));
    if (key != nullptr) {
        result->write(__sf("%s, ", key));
    }
    if (decoration != nullptr) {
        result->write(__sf("%s, ", decoration));
    }
    if (children == nullptr) {
        result->write(__s("child list is null"));
    } else {
        if (children!->isEmpty()) {
        result->write(__s("no children"));
    } else {
        result->write(__sf("%s", children));
    }
;
    }    result->write(__s(")"));
    return result->toString();
}

TableCls::TableCls(TableBorder border, List<TableRow> children, Map<int, TableColumnWidth> columnWidths, TableColumnWidth defaultColumnWidth, TableCellVerticalAlignment defaultVerticalAlignment, Key key, TextBaseline textBaseline, TextDirection textDirection) {
    {
        assert(children != nullptr);
        assert(defaultColumnWidth != nullptr);
        assert(defaultVerticalAlignment != nullptr);
        assert(defaultVerticalAlignment != TableCellVerticalAlignmentCls::baseline || textBaseline != nullptr, __s("textBaseline is required if you specify the defaultVerticalAlignment with TableCellVerticalAlignment.baseline"));
        assert([=] () {
            if (children->any([=] (TableRow row) {
                row->children == nullptr;
            })) {
                throw make<FlutterErrorCls>(__s("One of the rows of the table had null children.\nThe children property of TableRow must not be null."));
            }
            return true;
        }());
        assert([=] () {
            if (children->any([=] (TableRow row) {
                row->children!->any([=] (Widget cell) {
                cell == nullptr;
            });
            })) {
                throw make<FlutterErrorCls>(__s("One of the children of one of the rows of the table was null.\nThe children of a TableRow must not be null."));
            }
            return true;
        }());
        assert([=] () {
            if (children->any([=] (TableRow row1) {
                row1->key != nullptr && children->any([=] (TableRow row2) {
                row1 != row2 && row1->key == row2->key;
            });
            })) {
                throw make<FlutterErrorCls>(__s("Two or more TableRow children of this Table had the same key.\nAll the keyed TableRow children of a Table must have different Keys."));
            }
            return true;
        }());
        assert([=] () {
            if (children->isNotEmpty()) {
                int cellCount = children->first->children!->length();
                if (children->any([=] (TableRow row) {
                    row->children!->length() != cellCount;
                })) {
                    throw make<FlutterErrorCls>(__s("Table contains irregular row lengths.\nEvery TableRow in a Table must have the same number of children, so that every cell is filled. Otherwise, the table will contain holes."));
                }
            }
            return true;
        }());
        _rowDecorations = children->any([=] (TableRow row) {
            row->decoration != nullptr;
        })? children-><Decoration>map([=] (TableRow row) {
            row->decoration;
        })->toList(false) : nullptr;
    }
    {
        assert([=] () {
            List<Widget> flatChildren = children-><Widget>expand([=] (TableRow row) {
    row->children!;
})->toList(false);
            if (debugChildrenHaveDuplicateKeys(this, flatChildren)) {
                throw make<FlutterErrorCls>(__s("Two or more cells in this Table contain widgets with the same key.\nEvery widget child of every TableRow in a Table must have different keys. The cells of a Table are flattened out for processing, so separate cells cannot have duplicate keys even if they are in different rows."));
            }
            return true;
        }());
    }
}

RenderObjectElement TableCls::createElement() {
    return make<_TableElementCls>(this);
}

RenderTable TableCls::createRenderObject(BuildContext context) {
    assert(debugCheckHasDirectionality(context));
    return make<RenderTableCls>(children->isNotEmpty()? children[0]->children!->length() : 0, children->length(), columnWidths, defaultColumnWidth, textDirection | DirectionalityCls->of(context), border, _rowDecorations, createLocalImageConfiguration(context), defaultVerticalAlignment, textBaseline);
}

void TableCls::updateRenderObject(BuildContext context, RenderTable renderObject) {
    assert(debugCheckHasDirectionality(context));
    assert(renderObject->columns() == (children->isNotEmpty()? children[0]->children!->length() : 0));
    assert(renderObject->rows() == children->length());
    auto _c1 = renderObject;_c1.columnWidths = auto _c2 = columnWidths;_c2.defaultColumnWidth = auto _c3 = defaultColumnWidth;_c3.textDirection = auto _c4 = textDirection | DirectionalityCls->of(context);_c4.border = auto _c5 = border;_c5.rowDecorations = auto _c6 = _rowDecorations;_c6.configuration = auto _c7 = createLocalImageConfiguration(context);_c7.defaultVerticalAlignment = auto _c8 = defaultVerticalAlignment;_c8.textBaseline = textBaseline;_c8;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}

RenderTable _TableElementCls::renderObject() {
    return as<RenderTable>(super->renderObject);
}

void _TableElementCls::mount(Element parent, Object newSlot) {
    assert(!_doingMountOrUpdate);
    _doingMountOrUpdate = true;
    super->mount(parent, newSlot);
    int rowIndex = -1;
    _children = (as<Table>(widget()))->children-><_TableElementRow>map([=] (TableRow row) {
        int columnIndex = 0;
        rowIndex += 1;
        return make<_TableElementRowCls>(row->key, row->children!-><Element>map([=] (Widget child) {
            assert(child != nullptr);
            return inflateWidget(child, make<_TableSlotCls>(columnIndex++, rowIndex));
        })->toList(false));
    })->toList(false);
    _updateRenderObjectChildren();
    assert(_doingMountOrUpdate);
    _doingMountOrUpdate = false;
}

void _TableElementCls::insertRenderObjectChild(RenderBox child, _TableSlot slot) {
    renderObject()->setupParentData(child);
    if (!_doingMountOrUpdate) {
        renderObject()->setChild(slot->column, slot->row, child);
    }
}

void _TableElementCls::moveRenderObjectChild(RenderBox child, _TableSlot oldSlot, _TableSlot newSlot) {
    assert(_doingMountOrUpdate);
}

void _TableElementCls::removeRenderObjectChild(RenderBox child, _TableSlot slot) {
    renderObject()->setChild(slot->column, slot->row, nullptr);
}

void _TableElementCls::update(Table newWidget) {
    assert(!_doingMountOrUpdate);
    _doingMountOrUpdate = true;
    Map<LocalKey, List<Element>> oldKeyedRows = makeMap(makeList(), makeList();
    for (_TableElementRow row : _children) {
        if (row->key != nullptr) {
            oldKeyedRows[row->key!] = row->children;
        }
    }
    Iterator<_TableElementRow> oldUnkeyedRows = _children->where([=] (_TableElementRow row) {
    row->key == nullptr;
})->iterator;
    List<_TableElementRow> newChildren = makeList();
    Set<List<Element>> taken = makeSet();
    for (;  < newWidget->children->length(); rowIndex++) {
        TableRow row = newWidget->children[rowIndex];
        List<Element> oldChildren;
        if (row->key != nullptr && oldKeyedRows->containsKey(row->key)) {
            oldChildren = oldKeyedRows[row->key]!;
            taken->add(oldChildren);
        } else {
            if (row->key == nullptr && oldUnkeyedRows->moveNext()) {
            oldChildren = oldUnkeyedRows->current()->children;
        } else {
            oldChildren = makeList();
        }
;
        }        List<_TableSlot> slots = <_TableSlot>generate(row->children!->length(), [=] (int columnIndex) {
    make<_TableSlotCls>(columnIndex, rowIndex);
});
        newChildren->add(make<_TableElementRowCls>(row->key, updateChildren(oldChildren, row->children!, _forgottenChildren, slots)));
    }
    while (oldUnkeyedRows->moveNext()) {
        updateChildren(oldUnkeyedRows->current()->children, makeList(), _forgottenChildren);
    }
    for (List<Element> oldChildren : oldKeyedRows->values()->where([=] (List<Element> list) {
        !taken->contains(list);
    })) {
        updateChildren(oldChildren, makeList(), _forgottenChildren);
    }
    _children = newChildren;
    _updateRenderObjectChildren();
    _forgottenChildren->clear();
    super->update(newWidget);
    assert(widget() == newWidget);
    assert(_doingMountOrUpdate);
    _doingMountOrUpdate = false;
}

void _TableElementCls::visitChildren(ElementVisitor visitor) {
    for (Element child : _children-><Element>expand([=] (_TableElementRow row) {
        row->children;
    })) {
        if (!_forgottenChildren->contains(child)) {
            visitor(child);
        }
    }
}

bool _TableElementCls::forgetChild(Element child) {
    _forgottenChildren->add(child);
    super->forgetChild(child);
    return true;
}

void _TableElementCls::_updateRenderObjectChildren() {
    assert(renderObject() != nullptr);
    renderObject()->setFlatChildren(_children->isNotEmpty()? _children[0]->children->length() : 0, _children-><RenderBox>expand([=] (_TableElementRow row) {
        return row->children-><RenderBox>map([=] (Element child) {
            RenderBox box = as<RenderBox>(child->renderObject!);
            return box;
        });
    })->toList());
}

void TableCellCls::applyParentData(RenderObject renderObject) {
    TableCellParentData parentData = as<TableCellParentData>(renderObject->parentData!);
    if (parentData->verticalAlignment != verticalAlignment) {
        parentData->verticalAlignment = verticalAlignment;
        AbstractNode targetParent = renderObject->parent();
        if (is<RenderObject>(targetParent)) {
            as<RenderObjectCls>(targetParent)->markNeedsLayout();
        }
    }
}

Type TableCellCls::debugTypicalAncestorWidgetClass() {
    return TableCls;
}

void TableCellCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<TableCellVerticalAlignment>make<EnumPropertyCls>(__s("verticalAlignment"), verticalAlignment));
}

bool _TableSlotCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<_TableSlot>(other) && column == other->column && row == other->row;
}

int _TableSlotCls::hashCode() {
    return ObjectCls->hash(column, row);
}

void _TableSlotCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<IntPropertyCls>(__s("x"), column));
    properties->add(make<IntPropertyCls>(__s("y"), row));
}
