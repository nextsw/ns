#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H
#include <memory>

#include <math/math.hpp>
#include <meta/meta.hpp>
#include "assertions.hpp"
#include "constants.hpp"
#include "debug.hpp"
#include "math.hpp"
#include "object.hpp"



enum DiagnosticLevel{
    hidden,
    fine,
    debug,
    info,
    warning,
    hint,
    summary,
    error,
    off,
} // end DiagnosticLevel

enum DiagnosticsTreeStyle{
    none,
    sparse,
    offstage,
    dense,
    transition,
    error,
    whitespace,
    flat,
    singleLine,
    errorProperty,
    shallow,
    truncateChildren,
} // end DiagnosticsTreeStyle

class TextTreeConfiguration {
public:
    String prefixLineOne;

    String suffixLineOne;

    String prefixOtherLines;

    String prefixLastChildLineOne;

    String prefixOtherLinesRootNode;

    String propertyPrefixIfChildren;

    String propertyPrefixNoChildren;

    String linkCharacter;

    String childLinkSpace;

    String lineBreak;

    bool lineBreakProperties;

    String beforeName;

    String afterName;

    String afterDescriptionIfBody;

    String afterDescription;

    String beforeProperties;

    String afterProperties;

    String mandatoryAfterProperties;

    String propertySeparator;

    String bodyIndent;

    bool showChildren;

    bool addBlankLineIfNoChildren;

    bool isNameOnOwnLine;

    String footer;

    String mandatoryFooter;

    bool isBlankLineBetweenPropertiesAndChildren;


     TextTreeConfiguration(bool addBlankLineIfNoChildren, String afterDescription, String afterDescriptionIfBody, String afterName, String afterProperties, String beforeName, String beforeProperties, String bodyIndent, String footer, bool isBlankLineBetweenPropertiesAndChildren, bool isNameOnOwnLine, String lineBreak, bool lineBreakProperties, String linkCharacter, String mandatoryAfterProperties, String mandatoryFooter, String prefixLastChildLineOne, String prefixLineOne, String prefixOtherLines, String prefixOtherLinesRootNode, String propertyPrefixIfChildren, String propertyPrefixNoChildren, String propertySeparator, bool showChildren, String suffixLineOne);

private:

};
TextTreeConfiguration sparseTextConfiguration;

TextTreeConfiguration dashedTextConfiguration;

TextTreeConfiguration denseTextConfiguration;

TextTreeConfiguration transitionTextConfiguration;

TextTreeConfiguration errorTextConfiguration;

TextTreeConfiguration whitespaceTextConfiguration;

TextTreeConfiguration flatTextConfiguration;

TextTreeConfiguration singleLineTextConfiguration;

TextTreeConfiguration errorPropertyTextConfiguration;

TextTreeConfiguration shallowTextConfiguration;


enum _WordWrapParseMode{
    inSpace,
    inWord,
    atBreak,
} // end _WordWrapParseMode

class _PrefixedStringBuilder {
public:
    String prefixLineOne;

    int wrapWidth;


    String prefixOtherLines();

    void  prefixOtherLines(String prefix);

    void incrementPrefixOtherLines(String suffix, bool updateCurrentLine);

    bool requiresMultipleLines();

    bool isCurrentLineEmpty();

    void write(bool allowWrap, String s);

    void writeRawLines(String lines);

    void writeStretched(int targetLineLength, String text);

    String build();

private:
    String _prefixOtherLines;

    String _nextPrefixOtherLines;

    StringBuffer _buffer;

    StringBuffer _currentLine;

    List<int> _wrappableRanges;

    int _numLines;


     _PrefixedStringBuilder(String prefixLineOne, String prefixOtherLines, int wrapWidth);

    void _finalizeLine(bool addTrailingLineBreak);

    static Iterable<String> _wordWrapLine(String message, int otherLineOffset, int startOffset, int width, List<int> wrapRanges);

    void _updatePrefix();

    void _writeLine(bool firstLine, bool includeLineBreak, String line);

    String _getCurrentPrefix(bool firstLine);

};

class _NoDefaultValue {
public:

private:

     _NoDefaultValue();

};
const Object kNoDefaultValue;

bool _isSingleLine(DiagnosticsTreeStyle style);


class TextTreeRenderer {
public:

     TextTreeRenderer(int maxDescendentsTruncatableNode, DiagnosticLevel minLevel, int wrapWidth, int wrapWidthProperties);

    String render(DiagnosticsNode node, TextTreeConfiguration parentConfiguration, String prefixLineOne, String prefixOtherLines);

private:
    int _wrapWidth;

    int _wrapWidthProperties;

    DiagnosticLevel _minLevel;

    int _maxDescendentsTruncatableNode;


    TextTreeConfiguration _childTextConfiguration(DiagnosticsNode child, TextTreeConfiguration textStyle);

    String _debugRender(DiagnosticsNode node, TextTreeConfiguration parentConfiguration, String prefixLineOne, String prefixOtherLines);

};

class DiagnosticsNode {
public:
    String name;

    bool showSeparator;

    bool showName;

    String linePrefix;

    DiagnosticsTreeStyle style;


     DiagnosticsNode(String linePrefix, String name, bool showName, bool showSeparator, DiagnosticsTreeStyle style);

    void  message(bool allowWrap, DiagnosticLevel level, String message, DiagnosticsTreeStyle style);

    String toDescription(TextTreeConfiguration parentConfiguration);

    bool isFiltered(DiagnosticLevel minLevel);

    DiagnosticLevel level();

    String emptyBodyDescription();

    Object value();

    bool allowWrap();

    bool allowNameWrap();

    bool allowTruncate();

    List<DiagnosticsNode> getProperties();

    List<DiagnosticsNode> getChildren();

    Map<String, String> toTimelineArguments();

    Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

    static List<Map<String, Object>> toJsonList(DiagnosticsSerializationDelegate delegate, List<DiagnosticsNode> nodes, DiagnosticsNode parent);

    String toString(DiagnosticLevel minLevel, TextTreeConfiguration parentConfiguration);

    TextTreeConfiguration textTreeConfiguration();

    String toStringDeep(DiagnosticLevel minLevel, TextTreeConfiguration parentConfiguration, String prefixLineOne, String prefixOtherLines);

private:

    String _separator();

};

class MessageProperty : DiagnosticsProperty<void> {
public:

     MessageProperty(DiagnosticLevel level, String message, String name, DiagnosticsTreeStyle style);

private:

};

class StringProperty : DiagnosticsProperty<String> {
public:
    bool quoted;


     StringProperty(Unknown, Unknown, Unknown, Unknown, String name, bool quoted, Unknown, Unknown, Unknown, Unknown);

    Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

    String valueToString(TextTreeConfiguration parentConfiguration);

private:

};

class _NumProperty<T extends num> : DiagnosticsProperty<T> {
public:
    String unit;


    void  lazy(Unknown, Unknown, Unknown, Unknown, String name, Unknown, Unknown, Unknown, String unit);

    Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

    String numberToString();

    String valueToString(TextTreeConfiguration parentConfiguration);

private:

     _NumProperty(Unknown, Unknown, Unknown, String name, Unknown, Unknown, Unknown, String unit, Unknown);

};

class DoubleProperty : _NumProperty<double> {
public:

     DoubleProperty(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    void  lazy(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    String numberToString();

private:

};

class IntProperty : _NumProperty<int> {
public:

     IntProperty(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    String numberToString();

private:

};

class PercentProperty : DoubleProperty {
public:

     PercentProperty(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown);

    String valueToString(TextTreeConfiguration parentConfiguration);

    String numberToString();

private:

};

class FlagProperty : DiagnosticsProperty<bool> {
public:
    String ifTrue;

    String ifFalse;


     FlagProperty(Object defaultValue, String ifFalse, String ifTrue, DiagnosticLevel level, String name, bool showName, bool value);

    Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

    String valueToString(TextTreeConfiguration parentConfiguration);

    bool showName();

    DiagnosticLevel level();

private:

};

class IterableProperty<T> : DiagnosticsProperty<Iterable<T>> {
public:

     IterableProperty(Unknown, Unknown, Unknown, Unknown, String name, Unknown, Unknown, Unknown, Unknown);

    String valueToString(TextTreeConfiguration parentConfiguration);

    DiagnosticLevel level();

    Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

};

class EnumProperty<T> : DiagnosticsProperty<T> {
public:

     EnumProperty(Unknown, Unknown, String name, Unknown);

    String valueToString(TextTreeConfiguration parentConfiguration);

private:

};

class ObjectFlagProperty<T> : DiagnosticsProperty<T> {
public:
    String ifPresent;


     ObjectFlagProperty(Unknown, String ifPresent, Unknown, String name, Unknown, Unknown);

    void  has(Unknown, String name, Unknown);

    String valueToString(TextTreeConfiguration parentConfiguration);

    bool showName();

    DiagnosticLevel level();

    Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

};

class FlagsSummary<T> : DiagnosticsProperty<Map<String, T>> {
public:

     FlagsSummary(Unknown, Unknown, String name, Unknown, Unknown, Map<String, T> value);

    Map<String, T> value();

    String valueToString(TextTreeConfiguration parentConfiguration);

    DiagnosticLevel level();

    Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

    bool _hasNonNullEntry();

    Iterable<String> _formattedValues();

};

class DiagnosticsProperty<T> : DiagnosticsNode {
public:
    bool expandableValue;

    bool allowWrap;

    bool allowNameWrap;

    String ifNull;

    String ifEmpty;

    String tooltip;

    bool missingIfNull;

    Object defaultValue;


     DiagnosticsProperty(bool allowNameWrap, bool allowWrap, Object defaultValue, String description, bool expandableValue, String ifEmpty, String ifNull, DiagnosticLevel level, Unknown, bool missingIfNull, String name, Unknown, Unknown, DiagnosticsTreeStyle style, String tooltip, T value);

    void  lazy(bool allowNameWrap, bool allowWrap, ComputePropertyValueCallback<T> computeValue, Object defaultValue, String description, bool expandableValue, String ifEmpty, String ifNull, DiagnosticLevel level, bool missingIfNull, String name, Unknown, Unknown, DiagnosticsTreeStyle style, String tooltip);

    Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

    String valueToString(TextTreeConfiguration parentConfiguration);

    String toDescription(TextTreeConfiguration parentConfiguration);

    Type propertyType();

    T value();

    Object exception();

    bool isInteresting();

    DiagnosticLevel level();

    List<DiagnosticsNode> getProperties();

    List<DiagnosticsNode> getChildren();

private:
    String _description;

    T _value;

    bool _valueComputed;

    Object _exception;

    DiagnosticLevel _defaultLevel;

    ComputePropertyValueCallback<T> _computeValue;


    String _addTooltip(String text);

    void _maybeCacheValue();

};

class DiagnosticableNode<T extends Diagnosticable> : DiagnosticsNode {
public:
    T value;


     DiagnosticableNode(Unknown, Unknown, T value);

    DiagnosticPropertiesBuilder builder();

    DiagnosticsTreeStyle style();

    String emptyBodyDescription();

    List<DiagnosticsNode> getProperties();

    List<DiagnosticsNode> getChildren();

    String toDescription(TextTreeConfiguration parentConfiguration);

private:
    DiagnosticPropertiesBuilder _cachedBuilder;


};

class DiagnosticableTreeNode : DiagnosticableNode<DiagnosticableTree> {
public:

     DiagnosticableTreeNode(Unknown, Unknown, Unknown);

    List<DiagnosticsNode> getChildren();

private:

};
String shortHash(Object object);

String describeIdentity(Object object);

String describeEnum(Object enumEntry);


class DiagnosticPropertiesBuilder {
public:
    List<DiagnosticsNode> properties;

    DiagnosticsTreeStyle defaultDiagnosticsTreeStyle;

    String emptyBodyDescription;


     DiagnosticPropertiesBuilder();

    void  fromProperties(List<DiagnosticsNode> properties);

    void add(DiagnosticsNode property);

private:

};

class Diagnosticable {
public:

    String toStringShort();

    String toString(DiagnosticLevel minLevel);

    DiagnosticsNode toDiagnosticsNode(String name, DiagnosticsTreeStyle style);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class DiagnosticableTree {
public:

     DiagnosticableTree();

    String toStringShallow(String joiner, DiagnosticLevel minLevel);

    String toStringDeep(DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines);

    String toStringShort();

    DiagnosticsNode toDiagnosticsNode(String name, DiagnosticsTreeStyle style);

    List<DiagnosticsNode> debugDescribeChildren();

private:

};

class DiagnosticableTreeMixin {
public:

    String toString(DiagnosticLevel minLevel);

    String toStringShallow(String joiner, DiagnosticLevel minLevel);

    String toStringDeep(DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines);

    String toStringShort();

    DiagnosticsNode toDiagnosticsNode(String name, DiagnosticsTreeStyle style);

    List<DiagnosticsNode> debugDescribeChildren();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class DiagnosticsBlock : DiagnosticsNode {
public:
    DiagnosticLevel level;

    Object value;

    bool allowTruncate;


     DiagnosticsBlock(bool allowTruncate, List<DiagnosticsNode> children, String description, DiagnosticLevel level, Unknown, Unknown, List<DiagnosticsNode> properties, bool showName, Unknown, DiagnosticsTreeStyle style, Object value);

    List<DiagnosticsNode> getChildren();

    List<DiagnosticsNode> getProperties();

    String toDescription(TextTreeConfiguration parentConfiguration);

private:
    List<DiagnosticsNode> _children;

    List<DiagnosticsNode> _properties;

    String _description;


};

class DiagnosticsSerializationDelegate {
public:

     DiagnosticsSerializationDelegate(bool includeProperties, int subtreeDepth);

    Map<String, Object> additionalNodeProperties(DiagnosticsNode node);

    List<DiagnosticsNode> filterChildren(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    List<DiagnosticsNode> filterProperties(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    List<DiagnosticsNode> truncateNodesList(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    DiagnosticsSerializationDelegate delegateForNode(DiagnosticsNode node);

    int subtreeDepth();

    bool includeProperties();

    bool expandPropertyValues();

    DiagnosticsSerializationDelegate copyWith(bool includeProperties, int subtreeDepth);

private:

};

class _DefaultDiagnosticsSerializationDelegate {
public:
    bool includeProperties;

    int subtreeDepth;


    Map<String, Object> additionalNodeProperties(DiagnosticsNode node);

    DiagnosticsSerializationDelegate delegateForNode(DiagnosticsNode node);

    bool expandPropertyValues();

    List<DiagnosticsNode> filterChildren(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    List<DiagnosticsNode> filterProperties(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    List<DiagnosticsNode> truncateNodesList(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    DiagnosticsSerializationDelegate copyWith(bool includeProperties, int subtreeDepth);

private:

     _DefaultDiagnosticsSerializationDelegate(bool includeProperties, int subtreeDepth);

};

#endif