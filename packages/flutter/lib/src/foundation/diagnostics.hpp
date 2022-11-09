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

    virtual void write(bool allowWrap, String s);

    virtual void writeRawLines(String lines);

    virtual void writeStretched(int targetLineLength, String text);

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

    static Iterable<String> _wordWrapLine(String message, int otherLineOffset, int startOffset, int width, List<int> wrapRanges);

    virtual void _updatePrefix();

    virtual void _writeLine(bool firstLine, bool includeLineBreak, String line);

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

    virtual void  message(bool allowWrap, DiagnosticLevel level, String message, DiagnosticsTreeStyle style);

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

    static List<Map<String, Object>> toJsonList(DiagnosticsSerializationDelegate delegate, List<DiagnosticsNode> nodes, DiagnosticsNode parent);

    virtual String toString(DiagnosticLevel minLevel, TextTreeConfiguration parentConfiguration);

    virtual TextTreeConfiguration textTreeConfiguration();

    virtual String toStringDeep(DiagnosticLevel minLevel, TextTreeConfiguration parentConfiguration, String prefixLineOne, String prefixOtherLines);

private:

    virtual String _separator();

};
using DiagnosticsNode = std::shared_ptr<DiagnosticsNodeCls>;

class MessagePropertyCls : public DiagnosticsPropertyCls<void> {
public:

     MessagePropertyCls(DiagnosticLevel level, String message, String name, DiagnosticsTreeStyle style);

private:

};
using MessageProperty = std::shared_ptr<MessagePropertyCls>;

class StringPropertyCls : public DiagnosticsPropertyCls<String> {
public:
    bool quoted;


     StringPropertyCls(Unknown defaultValue, Unknown description, Unknown ifEmpty, Unknown level, String name, bool quoted, Unknown showName, Unknown style, Unknown tooltip, Unknown value);

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

private:

};
using StringProperty = std::shared_ptr<StringPropertyCls>;

template<typename T : num> class _NumPropertyCls : public DiagnosticsPropertyCls<T> {
public:
    String unit;


    virtual void  lazy(Unknown computeValue, Unknown defaultValue, Unknown ifNull, Unknown level, String name, Unknown showName, Unknown style, Unknown tooltip, String unit);

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

    virtual String numberToString();
    virtual String valueToString(TextTreeConfiguration parentConfiguration);

private:

     _NumPropertyCls(Unknown defaultValue, Unknown ifNull, Unknown level, String name, Unknown showName, Unknown style, Unknown tooltip, String unit, Unknown value);
};
template<typename T : num> using _NumProperty = std::shared_ptr<_NumPropertyCls<T : num>>;

class DoublePropertyCls : public _NumPropertyCls<double> {
public:

     DoublePropertyCls(Unknown defaultValue, Unknown ifNull, Unknown level, Unknown name, Unknown showName, Unknown style, Unknown tooltip, Unknown unit, Unknown value);

    virtual void  lazy(Unknown computeValue, Unknown defaultValue, Unknown ifNull, Unknown level, Unknown name, Unknown showName, Unknown tooltip, Unknown unit);

    virtual String numberToString();

private:

};
using DoubleProperty = std::shared_ptr<DoublePropertyCls>;

class IntPropertyCls : public _NumPropertyCls<int> {
public:

     IntPropertyCls(Unknown defaultValue, Unknown ifNull, Unknown level, Unknown name, Unknown showName, Unknown style, Unknown unit, Unknown value);

    virtual String numberToString();

private:

};
using IntProperty = std::shared_ptr<IntPropertyCls>;

class PercentPropertyCls : public DoublePropertyCls {
public:

     PercentPropertyCls(Unknown fraction, Unknown ifNull, Unknown level, Unknown name, Unknown showName, Unknown tooltip, Unknown unit);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

    virtual String numberToString();

private:

};
using PercentProperty = std::shared_ptr<PercentPropertyCls>;

class FlagPropertyCls : public DiagnosticsPropertyCls<bool> {
public:
    String ifTrue;

    String ifFalse;


     FlagPropertyCls(Object defaultValue, String ifFalse, String ifTrue, DiagnosticLevel level, String name, bool showName, bool value);

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

    virtual bool showName();

    virtual DiagnosticLevel level();

private:

};
using FlagProperty = std::shared_ptr<FlagPropertyCls>;

template<typename T> class IterablePropertyCls : public DiagnosticsPropertyCls<Iterable<T>> {
public:

     IterablePropertyCls(Unknown defaultValue, Unknown ifEmpty, Unknown ifNull, Unknown level, String name, Unknown showName, Unknown showSeparator, Unknown style, Unknown value);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

    virtual DiagnosticLevel level();

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

};
template<typename T> using IterableProperty = std::shared_ptr<IterablePropertyCls<T>>;

template<typename T> class EnumPropertyCls : public DiagnosticsPropertyCls<T> {
public:

     EnumPropertyCls(Unknown defaultValue, Unknown level, String name, Unknown value);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

private:

};
template<typename T> using EnumProperty = std::shared_ptr<EnumPropertyCls<T>>;

template<typename T> class ObjectFlagPropertyCls : public DiagnosticsPropertyCls<T> {
public:
    String ifPresent;


     ObjectFlagPropertyCls(Unknown ifNull, String ifPresent, Unknown level, String name, Unknown showName, Unknown value);

    virtual void  has(Unknown level, String name, Unknown value);

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

    virtual bool showName();

    virtual DiagnosticLevel level();

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

};
template<typename T> using ObjectFlagProperty = std::shared_ptr<ObjectFlagPropertyCls<T>>;

template<typename T> class FlagsSummaryCls : public DiagnosticsPropertyCls<Map<String, T>> {
public:

     FlagsSummaryCls(Unknown ifEmpty, Unknown level, String name, Unknown showName, Unknown showSeparator, Map<String, T> value);

    virtual Map<String, T> value();

    virtual String valueToString(TextTreeConfiguration parentConfiguration);

    virtual DiagnosticLevel level();

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

    virtual bool _hasNonNullEntry();

    virtual Iterable<String> _formattedValues();

};
template<typename T> using FlagsSummary = std::shared_ptr<FlagsSummaryCls<T>>;

template<typename T> class DiagnosticsPropertyCls : public DiagnosticsNodeCls {
public:
    bool expandableValue;

    bool allowWrap;

    bool allowNameWrap;

    String ifNull;

    String ifEmpty;

    String tooltip;

    bool missingIfNull;

    Object defaultValue;


     DiagnosticsPropertyCls(bool allowNameWrap, bool allowWrap, Object defaultValue, String description, bool expandableValue, String ifEmpty, String ifNull, DiagnosticLevel level, Unknown linePrefix, bool missingIfNull, String name, Unknown showName, Unknown showSeparator, DiagnosticsTreeStyle style, String tooltip, T value);

    virtual void  lazy(bool allowNameWrap, bool allowWrap, ComputePropertyValueCallback<T> computeValue, Object defaultValue, String description, bool expandableValue, String ifEmpty, String ifNull, DiagnosticLevel level, bool missingIfNull, String name, Unknown showName, Unknown showSeparator, DiagnosticsTreeStyle style, String tooltip);

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
template<typename T> using DiagnosticsProperty = std::shared_ptr<DiagnosticsPropertyCls<T>>;

template<typename T : Diagnosticable> class DiagnosticableNodeCls : public DiagnosticsNodeCls {
public:
    T value;


     DiagnosticableNodeCls(Unknown name, Unknown style, T value);

    virtual DiagnosticPropertiesBuilder builder();

    virtual DiagnosticsTreeStyle style();

    virtual String emptyBodyDescription();

    virtual List<DiagnosticsNode> getProperties();

    virtual List<DiagnosticsNode> getChildren();

    virtual String toDescription(TextTreeConfiguration parentConfiguration);

private:
    DiagnosticPropertiesBuilder _cachedBuilder;


};
template<typename T : Diagnosticable> using DiagnosticableNode = std::shared_ptr<DiagnosticableNodeCls<T : Diagnosticable>>;

class DiagnosticableTreeNodeCls : public DiagnosticableNodeCls<DiagnosticableTree> {
public:

     DiagnosticableTreeNodeCls(Unknown name, Unknown style, Unknown value);
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


     DiagnosticsBlockCls(bool allowTruncate, List<DiagnosticsNode> children, String description, DiagnosticLevel level, Unknown linePrefix, Unknown name, List<DiagnosticsNode> properties, bool showName, Unknown showSeparator, DiagnosticsTreeStyle style, Object value);

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