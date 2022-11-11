#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_CUSTOM_PAINT
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_CUSTOM_PAINT
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "box.hpp"
#include "object.hpp"
#include "proxy_box.hpp"


class CustomPainterCls : public ListenableCls {
public:

     CustomPainterCls(Listenable repaint);

    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

    virtual void paint(Canvas canvas, Size size);
    virtual SemanticsBuilderCallback semanticsBuilder();

    virtual bool shouldRebuildSemantics(CustomPainter oldDelegate);

    virtual bool shouldRepaint(CustomPainter oldDelegate);
    virtual bool hitTest(Offset position);

    virtual String toString();

private:
    Listenable _repaint;


};
using CustomPainter = std::shared_ptr<CustomPainterCls>;

class CustomPainterSemanticsCls : public ObjectCls {
public:
    Key key;

    Rect rect;

    Matrix4 transform;

    SemanticsProperties properties;

    Set<SemanticsTag> tags;


     CustomPainterSemanticsCls(Key key, SemanticsProperties properties, Rect rect, Set<SemanticsTag> tags, Matrix4 transform);

private:

};
using CustomPainterSemantics = std::shared_ptr<CustomPainterSemanticsCls>;

class RenderCustomPaintCls : public RenderProxyBoxCls {
public:
    bool isComplex;

    bool willChange;


     RenderCustomPaintCls(RenderBox child, CustomPainter foregroundPainter, bool isComplex, CustomPainter painter, Size preferredSize, bool willChange);

    virtual CustomPainter painter();

    virtual void  painter(CustomPainter value);

    virtual CustomPainter foregroundPainter();

    virtual void  foregroundPainter(CustomPainter value);

    virtual Size preferredSize();

    virtual void  preferredSize(Size value);

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual bool hitTestSelf(Offset position);

    virtual void performLayout();

    virtual Size computeSizeForNoChild(BoxConstraints constraints);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

    virtual void assembleSemanticsNode(SemanticsNode node, SemanticsConfiguration config, Iterable<SemanticsNode> children);

    virtual void clearSemantics();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    CustomPainter _painter;

    CustomPainter _foregroundPainter;

    Size _preferredSize;

    SemanticsBuilderCallback _backgroundSemanticsBuilder;

    SemanticsBuilderCallback _foregroundSemanticsBuilder;

    List<SemanticsNode> _backgroundSemanticsNodes;

    List<SemanticsNode> _foregroundSemanticsNodes;


    virtual void _didUpdatePainter(CustomPainter newPainter, CustomPainter oldPainter);

    virtual void _paintWithPainter(Canvas canvas, Offset offset, CustomPainter painter);

    virtual void _setRasterCacheHints(PaintingContext context);

    static List<SemanticsNode> _updateSemanticsChildren(List<SemanticsNode> oldSemantics, List<CustomPainterSemantics> newChildSemantics);

    static bool _canUpdateSemanticsChild(SemanticsNode oldChild, CustomPainterSemantics newSemantics);

    static SemanticsNode _updateSemanticsChild(SemanticsNode oldChild, CustomPainterSemantics newSemantics);

};
using RenderCustomPaint = std::shared_ptr<RenderCustomPaintCls>;


#endif