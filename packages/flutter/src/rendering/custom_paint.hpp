#ifndef CUSTOM_PAINT_H
#define CUSTOM_PAINT_H
#include <memory>

#include <collection/collection.hpp>
#include <flutter/foundation.hpp>
#include <flutter/semantics.hpp>
#include "box.hpp"
#include "object.hpp"
#include "proxy_box.hpp"



class CustomPainter : Listenable {
public:

     CustomPainter(Listenable repaint);

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void paint(Canvas canvas, Size size);

    SemanticsBuilderCallback semanticsBuilder();

    bool shouldRebuildSemantics(CustomPainter oldDelegate);

    bool shouldRepaint(CustomPainter oldDelegate);

    bool hitTest(Offset position);

    String toString();

private:
    Listenable _repaint;


};

class CustomPainterSemantics {
public:
    Key key;

    Rect rect;

    Matrix4 transform;

    SemanticsProperties properties;

    Set<SemanticsTag> tags;


     CustomPainterSemantics(Key key, SemanticsProperties properties, Rect rect, Set<SemanticsTag> tags, Matrix4 transform);

private:

};

class RenderCustomPaint : RenderProxyBox {
public:
    bool isComplex;

    bool willChange;


     RenderCustomPaint(RenderBox child, CustomPainter foregroundPainter, bool isComplex, CustomPainter painter, Size preferredSize, bool willChange);

    CustomPainter painter();

    void  painter(CustomPainter value);

    CustomPainter foregroundPainter();

    void  foregroundPainter(CustomPainter value);

    Size preferredSize();

    void  preferredSize(Size value);

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    void attach(PipelineOwner owner);

    void detach();

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    bool hitTestSelf(Offset position);

    void performLayout();

    Size computeSizeForNoChild(BoxConstraints constraints);

    void paint(PaintingContext context, Offset offset);

    void describeSemanticsConfiguration(SemanticsConfiguration config);

    void assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node);

    void clearSemantics();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    CustomPainter _painter;

    CustomPainter _foregroundPainter;

    Size _preferredSize;

    SemanticsBuilderCallback _backgroundSemanticsBuilder;

    SemanticsBuilderCallback _foregroundSemanticsBuilder;

    List<SemanticsNode> _backgroundSemanticsNodes;

    List<SemanticsNode> _foregroundSemanticsNodes;


    void _didUpdatePainter(CustomPainter newPainter, CustomPainter oldPainter);

    void _paintWithPainter(Canvas canvas, Offset offset, CustomPainter painter);

    void _setRasterCacheHints(PaintingContext context);

    static List<SemanticsNode> _updateSemanticsChildren(List<CustomPainterSemantics> newChildSemantics, List<SemanticsNode> oldSemantics);

    static bool _canUpdateSemanticsChild(CustomPainterSemantics newSemantics, SemanticsNode oldChild);

    static SemanticsNode _updateSemanticsChild(CustomPainterSemantics newSemantics, SemanticsNode oldChild);

};

#endif