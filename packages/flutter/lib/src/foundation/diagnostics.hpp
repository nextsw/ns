#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_DIAGNOSTICS
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_DIAGNOSTICS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/meta/meta.hpp>
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

class TextTreeConfigurationCls : public ObjectCls {
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


     TextTreeConfigurationCls(bool addBlankLineIfNoChildren, String afterDescription, String afterDescriptionIfBody, String afterName, String afterProperties, String beforeName, String beforeProperties, String bodyIndent, String footer, bool isBlankLineBetweenPropertiesAndChildren, bool isNameOnOwnLine, String lineBreak, bool lineBreakProperties, String linkCharacter, String mandatoryAfterProperties, String mandatoryFooter, String prefixLastChildLineOne, String prefixLineOne, String prefixOtherLines, String prefixOtherLinesRootNode, String propertyPrefixIfChildren, String propertyPrefixNoChildren, String propertySeparator, bool showChildren, String suffixLineOne);

private:

};
using TextTreeConfiguration = std::shared_ptr<TextTreeConfigurationCls>;
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

class _PrefixedStringBuilderCls : public ObjectCls {
public:
    String prefixLineOne;

    int wrapWidth;


    virtual String prefixOtherLines();

    virtual void  prefixOtherLines(String prefix);

    virtual void incrementPrefixOtherLines(String suffix, bool updateCurrentLine);

    virtual bool requiresMultipleLines();

    virtual bool isCurrentLineEmpty();

    virtual void write(String s, bool allowWrap);

    virtual void writeRawLines(String lines);

    virtual void writeStretched(String text, int targetLineLength);

    virtual String build();

private:
    String _prefixOtherLines;

    String _nextPrefixOtherLines;

    StringBuffer _buffer;

    StringBuffer _currentLine;

    List<int> _wrappableRanges;

    int _numLines;


     _PrefixedStringBuilderCls(String prefixLineOne, String prefixOtherLines, int wrapWidth);

    virtual void _finalizeLine(bool addTrailingLineBreak);

    static Iterable<String> _wordWrapLine(String message, List<int> wrapRanges, int width, int otherLineOffset, int startOffset);

    virtual void _updatePrefix();

    virtual void _writeLine(String line, bool firstLine, bool includeLineBreak);

    virtual String _getCurrentPrefix(bool firstLine);

};
using _PrefixedStringBuilder = std::shared_ptr<_PrefixedStringBuilderCls>;

class _NoDefaultValueCls : public ObjectCls {
public:

private:

     _NoDefaultValueCls();
};
using _NoDefaultValue = std::shared_ptr<_NoDefaultValueCls>;
Object kNoDefaultValue;

bool _isSingleLine(DiagnosticsTreeStyle style);


class TextTreeRendererCls : public ObjectCls {
public:

     TextTreeRendererCls(int maxDescendentsTruncatableNode, DiagnosticLevel minLevel, int wrapWidth, int wrapWidthProperties);

    virtual String render(DiagnosticsNode node, TextTreeConfiguration parentConfiguration, String prefixLineOne, String prefixOtherLines);

private:
    int _wrapWidth;

    int _wrapWidthProperties;

    DiagnosticLevel _minLevel;

    int _maxDescendentsTruncatableNode;


    virtual TextTreeConfiguration _childTextConfiguration(DiagnosticsNode child, TextTreeConfiguration textStyle);

    virtual String _debugRender(DiagnosticsNode node, TextTreeConfiguration parentConfiguration, String prefixLineOne, String prefixOtherLines);

};
using TextTreeRenderer = std::shared_ptr<TextTreeRendererCls>;

class DiagnosticsNodeCls : public ObjectCls {
public:
    String name;

    bool showSeparator;

    bool showName;

    String linePrefix;

    DiagnosticsTreeStyle style;


     DiagnosticsNodeCls(String linePrefix, String name, bool showName, bool showSeparator, DiagnosticsTreeStyle style);

    virtual void  message(String message, bool allowWrap, DiagnosticLevel level, DiagnosticsTreeStyle style);

    virtual String toDescription(TextTreeConfiguration parentConfiguration);
    virtual bool isFiltered(DiagnosticLevel minLevel);

    virtual DiagnosticLevel level();

    virtual String emptyBodyDescription();

    virtual Object value();
    virtual bool allowWrap();

    virtual bool allowNameWrap();

    virtual bool allowTruncate();

    virtual List<DiagnosticsNode> getProperties();
    virtual List<DiagnosticsNode> getChildren();
    virtual Map<String, String> toTimelineArguments();

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

    static List<Map<String, Object>> toJsonList(List<DiagnosticsNode> nodes, DiagnosticsNode parent, DiagnosticsSerializationDelegate delegate);

    virtual String toString(DiagnosticLevel minLevel, TextTreeConfiguration parentConfiguration);

    virtual TextTreeConfiguration textTreeConfiguration();

    virtual String toStringDeep(DiagnosticLevel minLevel, TextTreeConfiguration parentConfiguration, String prefixLineOne, String prefixOtherLines);

private:

    virtual String _separator();

};
using DiagnosticsNode = std::shared_ptr<DiagnosticsNodeCls>;

class MessagePropertyCls : public DiagnosticsPropertyCls<void> {
public:

     MessagePropertyCls(String name, String message, DiagnosticLevel level, DiagnosticsTreeStyle style);

private:

};
using MessageProperty = std::shared_ptr<MessagePropertyCls>;

class StringPropertyCls : public DiagnosticsPropertyCls<String> {
public:
    bool quoted;


     StringPropertyCls(String name, Unknown value, Object defaultValue, Unknown description, String ifEmpty, Unknown level, bool quoted, bool showName, DiagnosticsTreeStyle style, String tooltip);

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

private:

};
using StringProperty = std::shared_ptr<StringPropertyCls>;

template<typename T>
class _NumPropertyCls : public DiagnosticsPropertyCls<T> {
public:
    String unit;


    virtual void  lazy(String name, Unknown computeValue, Object defaultValue, String ifNull, Unknown level, bool showName, DiagnosticsTreeStyle style, String tooltip, String unit);

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

    virtual String numberToString();
    virtual String valueToString(TextTreeConfiguration parentConfiguration);

private:

     _NumPropertyCls(String name, Unknown value, Object defaultValue, String ifNull, Unknown level, bool showName, DiagnosticsTreeStyle style, String tooltip, String unit);
};
template<typename T>
using _NumProperty = std::shared_ptr<_NumPropertyCls<T>>;

class DoublePropertyCls : public _NumPropertyCls<double> {
public:

     DoublePropertyCls(String name, Unknown value, Object defaultValue, String ifNull, Unknown level, bool showName, DiagnosticsTreeStyle style, String tooltip, String unit);

    virtual void  lazy(String name, Unknown computeValue, Object defaultValue, String ifNull, Unknown level, bool showName, String tooltip, String unit);

    virtual String numberToString();

private:

};
using DoubleProperty = std::shared_ptr<DoublePropertyCls>;

class IntPropertyCls : public _NumPropertyCls<int> {
public:

     IntPropertyCls(String name, Unknown value, Object defaultValue, String ifNull, Unknown level, bool showName, DiagnosticsTreeStyle style, String unit);

    virtual String numberToString();

private:

};
using IntProperty = std::shared_ptr<IntPropertyCls>;

class PercentPropertyCls : public DoublePropertyCls {
public:

     PercentPropertyCls(String name, Unknown fraction, String ifNull, Unknown level, bool showName, String tooltip, String unit);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

    virtual String numberToString();

private:

};
using PercentProperty = std::shared_ptr<PercentPropertyCls>;

class FlagPropertyCls : public DiagnosticsPropertyCls<bool> {
public:
    String ifTrue;

    String ifFalse;


     FlagPropertyCls(String name, Object defaultValue, String ifFalse, String ifTrue, DiagnosticLevel level, bool showName, bool value);

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

    virtual bool showName();

    virtual DiagnosticLevel level();

private:

};
using FlagProperty = std::shared_ptr<FlagPropertyCls>;

template<typename T>
class IterablePropertyCls : public DiagnosticsPropertyCls<Iterable<T>> {
public:

     IterablePropertyCls(String name, Unknown value, Object defaultValue, String ifEmpty, String ifNull, Unknown level, bool showName, bool showSeparator, DiagnosticsTreeStyle style);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

    virtual DiagnosticLevel level();

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

};
template<typename T>
using IterableProperty = std::shared_ptr<IterablePropertyCls<T>>;

template<typename T>
class EnumPropertyCls : public DiagnosticsPropertyCls<T> {
public:

     EnumPropertyCls(String name, Unknown value, Object defaultValue, Unknown level);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

private:

};
template<typename T>
using EnumProperty = std::shared_ptr<EnumPropertyCls<T>>;

template<typename T>
class ObjectFlagPropertyCls : public DiagnosticsPropertyCls<T> {
public:
    String ifPresent;


     ObjectFlagPropertyCls(String name, Unknown value, String ifNull, String ifPresent, Unknown level, Unknown showName);

    virtual void  has(String name, Unknown value, Unknown level);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

    virtual bool showName();

    virtual DiagnosticLevel level();

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

};
template<typename T>
using ObjectFlagProperty = std::shared_ptr<ObjectFlagPropertyCls<T>>;

template<typename T>
class FlagsSummaryCls : public DiagnosticsPropertyCls<Map<String, T>> {
public:

     FlagsSummaryCls(String name, Map<String, T> value, String ifEmpty, Unknown level, bool showName, bool showSeparator);

    virtual Map<String, T> value();

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

    virtual DiagnosticLevel level();

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

    virtual bool _hasNonNullEntry();

    virtual Iterable<String> _formattedValues();

};
template<typename T>
using FlagsSummary = std::shared_ptr<FlagsSummaryCls<T>>;

template<typename T>
class DiagnosticsPropertyCls : public DiagnosticsNodeCls {
public:
    bool expandableValue;

    bool allowWrap;

    bool allowNameWrap;

    String ifNull;

    String ifEmpty;

    String tooltip;

    bool missingIfNull;

    Object defaultValue;


     DiagnosticsPropertyCls(String name, T value, bool allowNameWrap, bool allowWrap, Object defaultValue, String description, bool expandableValue, String ifEmpty, String ifNull, DiagnosticLevel level, String linePrefix, bool missingIfNull, bool showName, bool showSeparator, DiagnosticsTreeStyle style, String tooltip);

    virtual void  lazy(String name, ComputePropertyValueCallback<T> computeValue, bool allowNameWrap, bool allowWrap, Object defaultValue, String description, bool expandableValue, String ifEmpty, String ifNull, DiagnosticLevel level, bool missingIfNull, bool showName, bool showSeparator, DiagnosticsTreeStyle style, String tooltip);

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

    virtual String toDescription(TextTreeConfiguration parentConfiguration);

    virtual Type propertyType();

    virtual T value();

    virtual Object exception();

    virtual bool isInteresting();

    virtual DiagnosticLevel level();

    virtual List<DiagnosticsNode> getProperties();

    virtual List<DiagnosticsNode> getChildren();

private:
    String _description;

    T _value;

    bool _valueComputed;

    Object _exception;

    DiagnosticLevel _defaultLevel;

    ComputePropertyValueCallback<T> _computeValue;


    virtual String _addTooltip(String text);

    virtual void _maybeCacheValue();

};
template<typename T>
using DiagnosticsProperty = std::shared_ptr<DiagnosticsPropertyCls<T>>;

template<typename T>
class DiagnosticableNodeCls : public DiagnosticsNodeCls {
public:
    T value;


     DiagnosticableNodeCls(String name, Unknown style, T value);

    virtual DiagnosticPropertiesBuilder builder();

    virtual DiagnosticsTreeStyle style();

    virtual String emptyBodyDescription();

    virtual List<DiagnosticsNode> getProperties();

    virtual List<DiagnosticsNode> getChildren();

    virtual String toDescription(TextTreeConfiguration parentConfiguration);

private:
    DiagnosticPropertiesBuilder _cachedBuilder;


};
template<typename T>
using DiagnosticableNode = std::shared_ptr<DiagnosticableNodeCls<T>>;

class DiagnosticableTreeNodeCls : public DiagnosticableNodeCls<DiagnosticableTree> {
public:

     DiagnosticableTreeNodeCls(String name, Unknown style, T value);
    virtual List<DiagnosticsNode> getChildren();

private:

};
using DiagnosticableTreeNode = std::shared_ptr<DiagnosticableTreeNodeCls>;
String shortHash(Object object);

String describeIdentity(Object object);

String describeEnum(Object enumEntry);


class DiagnosticPropertiesBuilderCls : public ObjectCls {
public:
    List<DiagnosticsNode> properties;

    DiagnosticsTreeStyle defaultDiagnosticsTreeStyle;

    String emptyBodyDescription;


     DiagnosticPropertiesBuilderCls();

    virtual void  fromProperties(List<DiagnosticsNode> properties);
    virtual void add(DiagnosticsNode property);

private:

};
using DiagnosticPropertiesBuilder = std::shared_ptr<DiagnosticPropertiesBuilderCls>;

class DiagnosticableCls : public ObjectCls {
public:

    virtual String toStringShort();

    virtual String toString(DiagnosticLevel minLevel);

    virtual DiagnosticsNode toDiagnosticsNode(String name, DiagnosticsTreeStyle style);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using Diagnosticable = std::shared_ptr<DiagnosticableCls>;

class DiagnosticableTreeCls : public ObjectCls {
public:

     DiagnosticableTreeCls();
    virtual String toStringShallow(String joiner, DiagnosticLevel minLevel);

    virtual String toStringDeep(DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines);

    virtual String toStringShort();

    virtual DiagnosticsNode toDiagnosticsNode(String name, DiagnosticsTreeStyle style);

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:

};
using DiagnosticableTree = std::shared_ptr<DiagnosticableTreeCls>;

class DiagnosticableTreeMixinCls : public ObjectCls {
public:

    virtual String toString(DiagnosticLevel minLevel);

    virtual String toStringShallow(String joiner, DiagnosticLevel minLevel);

    virtual String toStringDeep(DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines);

    virtual String toStringShort();

    virtual DiagnosticsNode toDiagnosticsNode(String name, DiagnosticsTreeStyle style);

    virtual List<DiagnosticsNode> debugDescribeChildren();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using DiagnosticableTreeMixin = std::shared_ptr<DiagnosticableTreeMixinCls>;

class DiagnosticsBlockCls : public DiagnosticsNodeCls {
public:
    DiagnosticLevel level;

    Object value;

    bool allowTruncate;


     DiagnosticsBlockCls(bool allowTruncate, List<DiagnosticsNode> children, String description, DiagnosticLevel level, String linePrefix, String name, List<DiagnosticsNode> properties, bool showName, bool showSeparator, DiagnosticsTreeStyle style, Object value);

    virtual List<DiagnosticsNode> getChildren();

    virtual List<DiagnosticsNode> getProperties();

    virtual String toDescription(TextTreeConfiguration parentConfiguration);

private:
    List<DiagnosticsNode> _children;

    List<DiagnosticsNode> _properties;

    String _description;


};
using DiagnosticsBlock = std::shared_ptr<DiagnosticsBlockCls>;

class DiagnosticsSerializationDelegateCls : public ObjectCls {
public:

     DiagnosticsSerializationDelegateCls(bool includeProperties, int subtreeDepth);
    virtual Map<String, Object> additionalNodeProperties(DiagnosticsNode node);
    virtual List<DiagnosticsNode> filterChildren(List<DiagnosticsNode> nodes, DiagnosticsNode owner);
    virtual List<DiagnosticsNode> filterProperties(List<DiagnosticsNode> nodes, DiagnosticsNode owner);
    virtual List<DiagnosticsNode> truncateNodesList(List<DiagnosticsNode> nodes, DiagnosticsNode owner);
    virtual DiagnosticsSerializationDelegate delegateForNode(DiagnosticsNode node);
    virtual int subtreeDepth();
    virtual bool includeProperties();
    virtual bool expandPropertyValues();
    virtual DiagnosticsSerializationDelegate copyWith(bool includeProperties, int subtreeDepth);
private:

};
using DiagnosticsSerializationDelegate = std::shared_ptr<DiagnosticsSerializationDelegateCls>;

class _DefaultDiagnosticsSerializationDelegateCls : public ObjectCls {
public:
    bool includeProperties;

    int subtreeDepth;


    virtual Map<String, Object> additionalNodeProperties(DiagnosticsNode node);

    virtual DiagnosticsSerializationDelegate delegateForNode(DiagnosticsNode node);

    virtual bool expandPropertyValues();

    virtual List<DiagnosticsNode> filterChildren(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    virtual List<DiagnosticsNode> filterProperties(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    virtual List<DiagnosticsNode> truncateNodesList(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    virtual DiagnosticsSerializationDelegate copyWith(bool includeProperties, int subtreeDepth);

private:

     _DefaultDiagnosticsSerializationDelegateCls(bool includeProperties, int subtreeDepth);
};
using _DefaultDiagnosticsSerializationDelegate = std::shared_ptr<_DefaultDiagnosticsSerializationDelegateCls>;


#endif