#include "diagnostics.hpp"
TextTreeConfiguration::TextTreeConfiguration(bool addBlankLineIfNoChildren, String afterDescription, String afterDescriptionIfBody, String afterName, String afterProperties, String beforeName, String beforeProperties, String bodyIndent, String footer, bool isBlankLineBetweenPropertiesAndChildren, bool isNameOnOwnLine, String lineBreak, bool lineBreakProperties, String linkCharacter, String mandatoryAfterProperties, String mandatoryFooter, String prefixLastChildLineOne, String prefixLineOne, String prefixOtherLines, String prefixOtherLinesRootNode, String propertyPrefixIfChildren, String propertyPrefixNoChildren, String propertySeparator, bool showChildren, String suffixLineOne) {
    {
        assert(prefixLineOne != nullptr);
        assert(prefixOtherLines != nullptr);
        assert(prefixLastChildLineOne != nullptr);
        assert(prefixOtherLinesRootNode != nullptr);
        assert(linkCharacter != nullptr);
        assert(propertyPrefixIfChildren != nullptr);
        assert(propertyPrefixNoChildren != nullptr);
        assert(lineBreak != nullptr);
        assert(lineBreakProperties != nullptr);
        assert(afterName != nullptr);
        assert(afterDescriptionIfBody != nullptr);
        assert(afterDescription != nullptr);
        assert(beforeProperties != nullptr);
        assert(afterProperties != nullptr);
        assert(propertySeparator != nullptr);
        assert(bodyIndent != nullptr);
        assert(footer != nullptr);
        assert(showChildren != nullptr);
        assert(addBlankLineIfNoChildren != nullptr);
        assert(isNameOnOwnLine != nullptr);
        assert(isBlankLineBetweenPropertiesAndChildren != nullptr);
        childLinkSpace = " " * linkCharacter.length;
    }
}

String _PrefixedStringBuilder::prefixOtherLines() {
    return _nextPrefixOtherLines ?? _prefixOtherLines;
}

void _PrefixedStringBuilder::prefixOtherLines(String prefix) {
    _prefixOtherLines = prefix;
    _nextPrefixOtherLines = nullptr;
}

void _PrefixedStringBuilder::incrementPrefixOtherLines(String suffix, bool updateCurrentLine) {
    if (_currentLine.isEmpty || updateCurrentLine) {
        _prefixOtherLines = prefixOtherLines! + suffix;
        _nextPrefixOtherLines = nullptr;
    } else {
        _nextPrefixOtherLines = prefixOtherLines! + suffix;
    }
}

bool _PrefixedStringBuilder::requiresMultipleLines() {
    return _numLines > 1 || (_numLines == 1 && _currentLine.isNotEmpty) || (_currentLine.length + _getCurrentPrefix(true)!.length > wrapWidth!);
}

bool _PrefixedStringBuilder::isCurrentLineEmpty() {
    return _currentLine.isEmpty;
}

void _PrefixedStringBuilder::write(bool allowWrap, String s) {
    if (s.isEmpty) {
        return;
    }
    List<String> lines = s.split("\n");
    for (;  < lines.length; i = 1) {
        if (i > 0) {
            _finalizeLine(true);
            _updatePrefix();
        }
        String line = lines[i];
        if (line.isNotEmpty) {
            if (allowWrap && wrapWidth != nullptr) {
                int wrapStart = _currentLine.length;
                int wrapEnd = wrapStart + line.length;
                if (_wrappableRanges.isNotEmpty && _wrappableRanges.last == wrapStart) {
                    _wrappableRanges.last = wrapEnd;
                } else {
                    ;
                }
            }
            _currentLine.write(line);
        }
    }
}

void _PrefixedStringBuilder::writeRawLines(String lines) {
    if (lines.isEmpty) {
        return;
    }
    if (_currentLine.isNotEmpty) {
        _finalizeLine(true);
    }
    assert(_currentLine.isEmpty);
    _buffer.write(lines);
    if (!lines.endsWith("\n")) {
        _buffer.write("\n");
    }
    _numLines++;
    _updatePrefix();
}

void _PrefixedStringBuilder::writeStretched(int targetLineLength, String text) {
    write(text);
    int currentLineLength = _currentLine.length + _getCurrentPrefix(_buffer.isEmpty)!.length;
    assert(_currentLine.length > 0);
    int targetLength = targetLineLength - currentLineLength;
    if (targetLength > 0) {
        assert(text.isNotEmpty);
        String lastChar = text[text.length - 1];
        assert(lastChar != "\n");
        _currentLine.write(lastChar * targetLength);
    }
    _wrappableRanges.clear();
}

String _PrefixedStringBuilder::build() {
    if (_currentLine.isNotEmpty) {
        _finalizeLine(false);
    }
    return _buffer.toString();
}

_PrefixedStringBuilder::_PrefixedStringBuilder(String prefixLineOne, String prefixOtherLines, int wrapWidth) {
    {
        _prefixOtherLines = prefixOtherLines;
    }
}

void _PrefixedStringBuilder::_finalizeLine(bool addTrailingLineBreak) {
    bool firstLine = _buffer.isEmpty;
    String text = _currentLine.toString();
    _currentLine.clear();
    if (_wrappableRanges.isEmpty) {
        _writeLine(textaddTrailingLineBreak, firstLine);
        return;
    }
    Iterable<String> lines = _wordWrapLine(text, _wrappableRanges, wrapWidth!firstLine? prefixLineOne.length : _prefixOtherLines!.length, _prefixOtherLines!.length);
    int i = 0;
    int length = lines.length;
    for (String line : lines) {
        i++;
        _writeLine(lineaddTrailingLineBreak ||  < length, firstLine);
    }
    _wrappableRanges.clear();
}

Iterable<String> _PrefixedStringBuilder::_wordWrapLine(String message, int otherLineOffset, int startOffset, int width, List<int> wrapRanges) {
    if (message.length +  < width) {
        return ;
    }
    List<String> wrappedLine = ;
    int startForLengthCalculations = -startOffset;
    bool addPrefix = false;
    int index = 0;
    _WordWrapParseMode mode = _WordWrapParseMode.inSpace;
    int lastWordStart;
    int lastWordEnd;
    int start = 0;
    int currentChunk = 0;
    ;
    while (true) {
        ;
    }
}

void _PrefixedStringBuilder::_updatePrefix() {
    if (_nextPrefixOtherLines != nullptr) {
        _prefixOtherLines = _nextPrefixOtherLines;
        _nextPrefixOtherLines = nullptr;
    }
}

void _PrefixedStringBuilder::_writeLine(bool firstLine, bool includeLineBreak, String line) {
    line = "${_getCurrentPrefix(firstLine)}$line";
    _buffer.write(line.trimRight());
    if (includeLineBreak) {
        _buffer.write("\n");
    }
    _numLines++;
}

String _PrefixedStringBuilder::_getCurrentPrefix(bool firstLine) {
    return _buffer.isEmpty? prefixLineOne : _prefixOtherLines;
}

bool _isSingleLine(DiagnosticsTreeStyle style) {
    return style == DiagnosticsTreeStyle.singleLine;
}

TextTreeRenderer::TextTreeRenderer(int maxDescendentsTruncatableNode, DiagnosticLevel minLevel, int wrapWidth, int wrapWidthProperties) {
    {
        assert(minLevel != nullptr);
        _minLevel = minLevel;
        _wrapWidth = wrapWidth;
        _wrapWidthProperties = wrapWidthProperties;
        _maxDescendentsTruncatableNode = maxDescendentsTruncatableNode;
    }
}

String TextTreeRenderer::render(DiagnosticsNode node, TextTreeConfiguration parentConfiguration, String prefixLineOne, String prefixOtherLines) {
    if (kReleaseMode) {
        return "";
    } else {
        return _debugRender(nodeprefixLineOne, prefixOtherLines, parentConfiguration);
    }
}

TextTreeConfiguration TextTreeRenderer::_childTextConfiguration(DiagnosticsNode child, TextTreeConfiguration textStyle) {
    DiagnosticsTreeStyle childStyle = child.style;
    return (_isSingleLine(childStyle) || childStyle == DiagnosticsTreeStyle.errorProperty)? textStyle : child.textTreeConfiguration;
}

String TextTreeRenderer::_debugRender(DiagnosticsNode node, TextTreeConfiguration parentConfiguration, String prefixLineOne, String prefixOtherLines) {
    bool isSingleLine = _isSingleLine(node.style) && parentConfiguration?.lineBreakProperties != true;
    prefixOtherLines = prefixLineOne;
    if (node.linePrefix != nullptr) {
        prefixLineOne = node.linePrefix!;
        prefixOtherLines = node.linePrefix!;
    }
    TextTreeConfiguration config = node.textTreeConfiguration!;
    if (prefixOtherLines.isEmpty) {
        prefixOtherLines = config.prefixOtherLinesRootNode;
    }
    if (node.style == DiagnosticsTreeStyle.truncateChildren) {
        List<String> descendants = ;
        int maxDepth = 5;
        int depth = 0;
        int maxLines = 25;
        int lines = 0;
        ;
        visitor(node);
        StringBuffer information = StringBuffer(prefixLineOne);
        if (lines > 1) {
            information.writeln("This ${node.name} had the following descendants (showing up to depth $maxDepth):");
        } else         {
            if (descendants.length == 1) {
            information.writeln("This ${node.name} had the following child:");
        } else {
            information.writeln("This ${node.name} has no descendants.");
        }
;
        }        information.writeAll(descendants, "\n");
        return information.toString();
    }
    _PrefixedStringBuilder builder = _PrefixedStringBuilder(prefixLineOne, prefixOtherLines, math.max(_wrapWidth, prefixOtherLines.length + _wrapWidthProperties));
    List<DiagnosticsNode> children = node.getChildren();
    String description = node.toDescription(parentConfiguration);
    if (config.beforeName.isNotEmpty) {
        builder.write(config.beforeName);
    }
    bool wrapName = !isSingleLine && node.allowNameWrap;
    bool wrapDescription = !isSingleLine && node.allowWrap;
    bool uppercaseTitle = node.style == DiagnosticsTreeStyle.error;
    String name = node.name;
    if (uppercaseTitle) {
        name = name?.toUpperCase();
    }
    if (description == nullptr || description.isEmpty) {
        if (node.showName && name != nullptr) {
            builder.write(namewrapName);
        }
    } else {
        bool includeName = false;
        if (name != nullptr && name.isNotEmpty && node.showName) {
            includeName = true;
            builder.write(namewrapName);
            if (node.showSeparator) {
                builder.write(config.afterNamewrapName);
            }
            builder.write(config.isNameOnOwnLine || description.contains("\n")? "\n" : " "wrapName);
        }
        if (!isSingleLine && builder.requiresMultipleLines && !builder.isCurrentLineEmpty) {
            builder.write("\n");
        }
        if (includeName) {
            builder.incrementPrefixOtherLines(children.isEmpty? config.propertyPrefixNoChildren : config.propertyPrefixIfChildrentrue);
        }
        if (uppercaseTitle) {
            description = description.toUpperCase();
        }
        builder.write(description.trimRight()wrapDescription);
        if (!includeName) {
            builder.incrementPrefixOtherLines(children.isEmpty? config.propertyPrefixNoChildren : config.propertyPrefixIfChildrenfalse);
        }
    }
    if (config.suffixLineOne.isNotEmpty) {
        builder.writeStretched(config.suffixLineOne, builder.wrapWidth!);
    }
    Iterable<DiagnosticsNode> propertiesIterable = node.getProperties().where();
    List<DiagnosticsNode> properties;
    if (_maxDescendentsTruncatableNode >= 0 && node.allowTruncate) {
        if (propertiesIterable.length < _maxDescendentsTruncatableNode) {
            properties = propertiesIterable.take(_maxDescendentsTruncatableNode).toList();
            properties.add(DiagnosticsNode.message("..."));
        } else {
            properties = propertiesIterable.toList();
        }
        if ( < children.length) {
            children = children.take(_maxDescendentsTruncatableNode).toList();
            children.add(DiagnosticsNode.message("..."));
        }
    } else {
        properties = propertiesIterable.toList();
    }
    if ((properties.isNotEmpty || children.isNotEmpty || node.emptyBodyDescription != nullptr) && (node.showSeparator || description.isNotEmpty)) {
        builder.write(config.afterDescriptionIfBody);
    }
    if (config.lineBreakProperties) {
        builder.write(config.lineBreak);
    }
    if (properties.isNotEmpty) {
        builder.write(config.beforeProperties);
    }
    builder.incrementPrefixOtherLines(config.bodyIndentfalse);
    if (node.emptyBodyDescription != nullptr && properties.isEmpty && children.isEmpty && prefixLineOne.isNotEmpty) {
        builder.write(node.emptyBodyDescription!);
        if (config.lineBreakProperties) {
            builder.write(config.lineBreak);
        }
    }
    for (;  < properties.length; ++i) {
        DiagnosticsNode property = properties[i];
        if (i > 0) {
            builder.write(config.propertySeparator);
        }
        TextTreeConfiguration propertyStyle = property.textTreeConfiguration!;
        if (_isSingleLine(property.style)) {
            String propertyRender = render(propertypropertyStyle.prefixLineOne, "${propertyStyle.childLinkSpace}${propertyStyle.prefixOtherLines}", config);
            List<String> propertyLines = propertyRender.split("\n");
            if (propertyLines.length == 1 && !config.lineBreakProperties) {
                builder.write(propertyLines.first);
            } else {
                builder.write(propertyRender);
                if (!propertyRender.endsWith("\n")) {
                    builder.write("\n");
                }
            }
        } else {
            String propertyRender = render(property"${builder.prefixOtherLines}${propertyStyle.prefixLineOne}", "${builder.prefixOtherLines}${propertyStyle.childLinkSpace}${propertyStyle.prefixOtherLines}", config);
            builder.writeRawLines(propertyRender);
        }
    }
    if (properties.isNotEmpty) {
        builder.write(config.afterProperties);
    }
    builder.write(config.mandatoryAfterProperties);
    if (!config.lineBreakProperties) {
        builder.write(config.lineBreak);
    }
    String prefixChildren = config.bodyIndent;
    String prefixChildrenRaw = "$prefixOtherLines$prefixChildren";
    if (children.isEmpty && config.addBlankLineIfNoChildren && builder.requiresMultipleLines && builder.prefixOtherLines!.trimRight().isNotEmpty) {
        builder.write(config.lineBreak);
    }
    if (children.isNotEmpty && config.showChildren) {
        if (config.isBlankLineBetweenPropertiesAndChildren && properties.isNotEmpty && children.first.textTreeConfiguration!.isBlankLineBetweenPropertiesAndChildren) {
            builder.write(config.lineBreak);
        }
        builder.prefixOtherLines = prefixOtherLines;
        for (;  < children.length; i++) {
            DiagnosticsNode child = children[i];
            assert(child != nullptr);
            TextTreeConfiguration childConfig = _childTextConfiguration(child, config)!;
            if (i == children.length - 1) {
                String lastChildPrefixLineOne = "$prefixChildrenRaw${childConfig.prefixLastChildLineOne}";
                String childPrefixOtherLines = "$prefixChildrenRaw${childConfig.childLinkSpace}${childConfig.prefixOtherLines}";
                builder.writeRawLines(render(childlastChildPrefixLineOne, childPrefixOtherLines, config));
                if (childConfig.footer.isNotEmpty) {
                    builder.prefixOtherLines = prefixChildrenRaw;
                    builder.write("${childConfig.childLinkSpace}${childConfig.footer}");
                    if (childConfig.mandatoryFooter.isNotEmpty) {
                        builder.writeStretched(childConfig.mandatoryFooter, math.max(builder.wrapWidth!, _wrapWidthProperties + childPrefixOtherLines.length));
                    }
                    builder.write(config.lineBreak);
                }
            } else {
                TextTreeConfiguration nextChildStyle = _childTextConfiguration(children[i + 1], config)!;
                String childPrefixLineOne = "$prefixChildrenRaw${childConfig.prefixLineOne}";
                String childPrefixOtherLines = "$prefixChildrenRaw${nextChildStyle.linkCharacter}${childConfig.prefixOtherLines}";
                builder.writeRawLines(render(childchildPrefixLineOne, childPrefixOtherLines, config));
                if (childConfig.footer.isNotEmpty) {
                    builder.prefixOtherLines = prefixChildrenRaw;
                    builder.write("${childConfig.linkCharacter}${childConfig.footer}");
                    if (childConfig.mandatoryFooter.isNotEmpty) {
                        builder.writeStretched(childConfig.mandatoryFooter, math.max(builder.wrapWidth!, _wrapWidthProperties + childPrefixOtherLines.length));
                    }
                    builder.write(config.lineBreak);
                }
            }
        }
    }
    if (parentConfiguration == nullptr && config.mandatoryFooter.isNotEmpty) {
        builder.writeStretched(config.mandatoryFooter, builder.wrapWidth!);
        builder.write(config.lineBreak);
    }
    return builder.build();
}

DiagnosticsNode::DiagnosticsNode(String linePrefix, String name, bool showName, bool showSeparator, DiagnosticsTreeStyle style) {
    {
        assert(showName != nullptr);
        assert(showSeparator != nullptr);
        assert(name == nullptr || !name.endsWith(":"), "Names of diagnostic nodes must not end with colons.\nname:\n  "$name"");
    }
}

void DiagnosticsNode::message(bool allowWrap, DiagnosticLevel level, String message, DiagnosticsTreeStyle style) {
    assert(style != nullptr);
    assert(level != nullptr);
    return <void>DiagnosticsProperty("", nullptrmessage, style, false, allowWrap, level);
}

bool DiagnosticsNode::isFiltered(DiagnosticLevel minLevel) {
    return kReleaseMode || level.index < minLevel.index;
}

DiagnosticLevel DiagnosticsNode::level() {
    return kReleaseMode? DiagnosticLevel.hidden : DiagnosticLevel.info;
}

String DiagnosticsNode::emptyBodyDescription() {
    return nullptr;
}

bool DiagnosticsNode::allowWrap() {
    return false;
}

bool DiagnosticsNode::allowNameWrap() {
    return false;
}

bool DiagnosticsNode::allowTruncate() {
    return false;
}

Map<String, String> DiagnosticsNode::toTimelineArguments() {
    if (!kReleaseMode) {
        if (kProfileMode) {
            ;
        }
        Map<String, String> result = ;
        for (DiagnosticsNode property : getProperties()) {
            if (property.name != nullptr) {
                result[property.name!] = property.toDescription(singleLineTextConfiguration);
            }
        }
        return result;
    }
    return nullptr;
}

Map<String, Object> DiagnosticsNode::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> result = ;
    assert(());
    return result;
}

List<Map<String, Object>> DiagnosticsNode::toJsonList(DiagnosticsSerializationDelegate delegate, List<DiagnosticsNode> nodes, DiagnosticsNode parent) {
    bool truncated = false;
    if (nodes == nullptr) {
        return const ;
    }
    int originalNodeCount = nodes.length;
    nodes = delegate.truncateNodesList(nodes, parent);
    if (nodes.length != originalNodeCount) {
        nodes.add(DiagnosticsNode.message("..."));
        truncated = true;
    }
    List<Map<String, Object>> json = nodes.<Map<String, Object>>map().toList();
    if (truncated) {
        json.last["truncated"] = true;
    }
    return json;
}

String DiagnosticsNode::toString(DiagnosticLevel minLevel, TextTreeConfiguration parentConfiguration) {
    String result = super.toString();
    assert(style != nullptr);
    assert(minLevel != nullptr);
    assert(());
    return result;
}

TextTreeConfiguration DiagnosticsNode::textTreeConfiguration() {
    assert(style != nullptr);
    ;
}

String DiagnosticsNode::toStringDeep(DiagnosticLevel minLevel, TextTreeConfiguration parentConfiguration, String prefixLineOne, String prefixOtherLines) {
    String result = "";
    assert(());
    return result;
}

String DiagnosticsNode::_separator() {
    return showSeparator? ":" : "";
}

MessageProperty::MessageProperty(DiagnosticLevel level, String message, String name, DiagnosticsTreeStyle style) {
    {
        assert(name != nullptr);
        assert(message != nullptr);
        assert(style != nullptr);
        assert(level != nullptr);
        super(name, nullptrmessage, style, level);
    }
}

StringProperty::StringProperty(Unknown, Unknown, Unknown, Unknown, String name, bool quoted, Unknown, Unknown, Unknown, Unknown) {
    {
        assert(showName != nullptr);
        assert(quoted != nullptr);
        assert(style != nullptr);
        assert(level != nullptr);
    }
}

Map<String, Object> StringProperty::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super.toJsonMap(delegate);
    json["quoted"] = quoted;
    return json;
}

String StringProperty::valueToString(TextTreeConfiguration parentConfiguration) {
    String text = _description ?? value;
    if (parentConfiguration != nullptr && !parentConfiguration.lineBreakProperties && text != nullptr) {
        text = text.replaceAll("\n", "\n");
    }
    if (quoted && text != nullptr) {
        if (ifEmpty != nullptr && text.isEmpty) {
            return ifEmpty!;
        }
        return ""$text"";
    }
    return text.toString();
}

void _NumProperty::lazy(Unknown, Unknown, Unknown, Unknown, String name, Unknown, Unknown, Unknown, String unit)

Map<String, Object> _NumProperty::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super.toJsonMap(delegate);
    if (unit != nullptr) {
        json["unit"] = unit;
    }
    json["numberToString"] = numberToString();
    return json;
}

String _NumProperty::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value == nullptr) {
        return value.toString();
    }
    return unit != nullptr? "${numberToString()}$unit" : numberToString();
}

DoubleProperty::DoubleProperty(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        assert(showName != nullptr);
        assert(style != nullptr);
        assert(level != nullptr);
    }
}

void DoubleProperty::lazy(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown)

String DoubleProperty::numberToString() {
    return debugFormatDouble(value);
}

IntProperty::IntProperty(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        assert(showName != nullptr);
        assert(level != nullptr);
        assert(style != nullptr);
    }
}

String IntProperty::numberToString() {
    return value.toString();
}

PercentProperty::PercentProperty(Unknown, Unknown, Unknown, Unknown, Unknown, Unknown, Unknown) {
    {
        assert(showName != nullptr);
        assert(level != nullptr);
    }
}

String PercentProperty::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value == nullptr) {
        return value.toString();
    }
    return unit != nullptr? "${numberToString()} $unit" : numberToString();
}

String PercentProperty::numberToString() {
    double v = value;
    if (v == nullptr) {
        return value.toString();
    }
    return "${(clampDouble(v, 0.0, 1.0) * 100.0).toStringAsFixed(1)}%";
}

FlagProperty::FlagProperty(Object defaultValue, String ifFalse, String ifTrue, DiagnosticLevel level, String name, bool showName, bool value) {
    {
        assert(showName != nullptr);
        assert(level != nullptr);
        assert(ifTrue != nullptr || ifFalse != nullptr);
        super(name, valueshowName, defaultValue, level);
    }
}

Map<String, Object> FlagProperty::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super.toJsonMap(delegate);
    if (ifTrue != nullptr) {
        json["ifTrue"] = ifTrue;
    }
    if (ifFalse != nullptr) {
        json["ifFalse"] = ifFalse;
    }
    return json;
}

String FlagProperty::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value ?? false) {
        if (ifTrue != nullptr) {
            return ifTrue!;
        }
    } else     {
        if (value == false) {
        if (ifFalse != nullptr) {
            return ifFalse!;
        }
    }
;
    }    return super.valueToString(parentConfiguration);
}

bool FlagProperty::showName() {
    if (value == nullptr || ((value ?? false) && ifTrue == nullptr) || (!(value ?? true) && ifFalse == nullptr)) {
        return true;
    }
    return super.showName;
}

DiagnosticLevel FlagProperty::level() {
    if (value ?? false) {
        if (ifTrue == nullptr) {
            return DiagnosticLevel.hidden;
        }
    }
    if (value == false) {
        if (ifFalse == nullptr) {
            return DiagnosticLevel.hidden;
        }
    }
    return super.level;
}

IterableProperty::IterableProperty(Unknown, Unknown, Unknown, Unknown, String name, Unknown, Unknown, Unknown, Unknown) {
    {
        assert(style != nullptr);
        assert(showName != nullptr);
        assert(showSeparator != nullptr);
        assert(level != nullptr);
    }
}

String IterableProperty::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value == nullptr) {
        return value.toString();
    }
    if (value!.isEmpty) {
        return ifEmpty ?? "[]";
    }
    Iterable<String> formattedValues = value!.map();
    if (parentConfiguration != nullptr && !parentConfiguration.lineBreakProperties) {
        return "[${formattedValues.join(', ')}]";
    }
    return formattedValues.join(_isSingleLine(style)? ", " : "\n");
}

DiagnosticLevel IterableProperty::level() {
    if (ifEmpty == nullptr && value != nullptr && value!.isEmpty && super.level != DiagnosticLevel.hidden) {
        return DiagnosticLevel.fine;
    }
    return super.level;
}

Map<String, Object> IterableProperty::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super.toJsonMap(delegate);
    if (value != nullptr) {
        json["values"] = value!.<String>map().toList();
    }
    return json;
}

EnumProperty::EnumProperty(Unknown, Unknown, String name, Unknown) {
    {
        assert(level != nullptr);
    }
}

String EnumProperty::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value == nullptr) {
        return value.toString();
    }
    return describeEnum(value!);
}

ObjectFlagProperty::ObjectFlagProperty(Unknown, String ifPresent, Unknown, String name, Unknown, Unknown) {
    {
        assert(ifPresent != nullptr || ifNull != nullptr);
        assert(showName != nullptr);
        assert(level != nullptr);
    }
}

void ObjectFlagProperty::has(Unknown, String name, Unknown)

String ObjectFlagProperty::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value != nullptr) {
        if (ifPresent != nullptr) {
            return ifPresent!;
        }
    } else {
        if (ifNull != nullptr) {
            return ifNull!;
        }
    }
    return super.valueToString(parentConfiguration);
}

bool ObjectFlagProperty::showName() {
    if ((value != nullptr && ifPresent == nullptr) || (value == nullptr && ifNull == nullptr)) {
        return true;
    }
    return super.showName;
}

DiagnosticLevel ObjectFlagProperty::level() {
    if (value != nullptr) {
        if (ifPresent == nullptr) {
            return DiagnosticLevel.hidden;
        }
    } else {
        if (ifNull == nullptr) {
            return DiagnosticLevel.hidden;
        }
    }
    return super.level;
}

Map<String, Object> ObjectFlagProperty::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super.toJsonMap(delegate);
    if (ifPresent != nullptr) {
        json["ifPresent"] = ifPresent;
    }
    return json;
}

FlagsSummary::FlagsSummary(Unknown, Unknown, String name, Unknown, Unknown, Map<String, T> value) {
    {
        assert(value != nullptr);
        assert(showName != nullptr);
        assert(showSeparator != nullptr);
        assert(level != nullptr);
    }
}

Map<String, T> FlagsSummary::value() {
    return super.value!;
}

String FlagsSummary::valueToString(TextTreeConfiguration parentConfiguration) {
    assert(value != nullptr);
    if (!_hasNonNullEntry() && ifEmpty != nullptr) {
        return ifEmpty!;
    }
    Iterable<String> formattedValues = _formattedValues();
    if (parentConfiguration != nullptr && !parentConfiguration.lineBreakProperties) {
        return "[${formattedValues.join(', ')}]";
    }
    return formattedValues.join(_isSingleLine(style)? ", " : "\n");
}

DiagnosticLevel FlagsSummary::level() {
    if (!_hasNonNullEntry() && ifEmpty == nullptr) {
        return DiagnosticLevel.hidden;
    }
    return super.level;
}

Map<String, Object> FlagsSummary::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super.toJsonMap(delegate);
    if (value.isNotEmpty) {
        json["values"] = _formattedValues().toList();
    }
    return json;
}

bool FlagsSummary::_hasNonNullEntry() {
    return value.values.any();
}

Iterable<String> FlagsSummary::_formattedValues() {
    return value.entries.where().map();
}

DiagnosticsProperty::DiagnosticsProperty(bool allowNameWrap, bool allowWrap, Object defaultValue, String description, bool expandableValue, String ifEmpty, String ifNull, DiagnosticLevel level, Unknown, bool missingIfNull, String name, Unknown, Unknown, DiagnosticsTreeStyle style, String tooltip, T value) {
    {
        assert(showName != nullptr);
        assert(showSeparator != nullptr);
        assert(style != nullptr);
        assert(level != nullptr);
        _description = description;
        _valueComputed = true;
        _value = value;
        _computeValue = nullptr;
        ifNull = ifNull ?? (missingIfNull? "MISSING" : nullptr);
        _defaultLevel = level;
        super(name);
    }
}

void DiagnosticsProperty::lazy(bool allowNameWrap, bool allowWrap, ComputePropertyValueCallback<T> computeValue, Object defaultValue, String description, bool expandableValue, String ifEmpty, String ifNull, DiagnosticLevel level, bool missingIfNull, String name, Unknown, Unknown, DiagnosticsTreeStyle style, String tooltip)

Map<String, Object> DiagnosticsProperty::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    T v = value;
    List<Map<String, Object>> properties;
    if (delegate.expandPropertyValues && delegate.includeProperties && v is Diagnosticable && getProperties().isEmpty) {
        delegate = delegate.copyWith(0, false);
        properties = DiagnosticsNode.toJsonList(delegate.filterProperties(v.toDiagnosticsNode().getProperties(), this), this, delegate);
    }
    Map<String, Object> json = super.toJsonMap(delegate);
    if (properties != nullptr) {
        json["properties"] = properties;
    }
    if (defaultValue != kNoDefaultValue) {
        json["defaultValue"] = defaultValue.toString();
    }
    if (ifEmpty != nullptr) {
        json["ifEmpty"] = ifEmpty;
    }
    if (ifNull != nullptr) {
        json["ifNull"] = ifNull;
    }
    if (tooltip != nullptr) {
        json["tooltip"] = tooltip;
    }
    json["missingIfNull"] = missingIfNull;
    if (exception != nullptr) {
        json["exception"] = exception.toString();
    }
    json["propertyType"] = propertyType.toString();
    json["defaultLevel"] = _defaultLevel.name;
    if (value is Diagnosticable || value is DiagnosticsNode) {
        json["isDiagnosticableValue"] = true;
    }
    if (v is num) {
        json["value"] = v.isFinite? v : v.toString();
    }
    if (value is String || value is bool || value == nullptr) {
        json["value"] = value;
    }
    return json;
}

String DiagnosticsProperty::valueToString(TextTreeConfiguration parentConfiguration) {
    T v = value;
    return v is DiagnosticableTree? v.toStringShort() : v.toString();
}

String DiagnosticsProperty::toDescription(TextTreeConfiguration parentConfiguration) {
    if (_description != nullptr) {
        return _addTooltip(_description!);
    }
    if (exception != nullptr) {
        return "EXCEPTION (${exception.runtimeType})";
    }
    if (ifNull != nullptr && value == nullptr) {
        return _addTooltip(ifNull!);
    }
    String result = valueToString(parentConfiguration);
    if (result.isEmpty && ifEmpty != nullptr) {
        result = ifEmpty!;
    }
    return _addTooltip(result);
}

Type DiagnosticsProperty::propertyType() {
    return T;
}

T DiagnosticsProperty::value() {
    _maybeCacheValue();
    return _value;
}

Object DiagnosticsProperty::exception() {
    _maybeCacheValue();
    return _exception;
}

bool DiagnosticsProperty::isInteresting() {
    return defaultValue == kNoDefaultValue || value != defaultValue;
}

DiagnosticLevel DiagnosticsProperty::level() {
    if (_defaultLevel == DiagnosticLevel.hidden) {
        return _defaultLevel;
    }
    if (exception != nullptr) {
        return DiagnosticLevel.error;
    }
    if (value == nullptr && missingIfNull) {
        return DiagnosticLevel.warning;
    }
    if (!isInteresting) {
        return DiagnosticLevel.fine;
    }
    return _defaultLevel;
}

List<DiagnosticsNode> DiagnosticsProperty::getProperties() {
    if (expandableValue) {
        T object = value;
        if (object is DiagnosticsNode) {
            return object.getProperties();
        }
        if (object is Diagnosticable) {
            return object.toDiagnosticsNode(style).getProperties();
        }
    }
    return const ;
}

List<DiagnosticsNode> DiagnosticsProperty::getChildren() {
    if (expandableValue) {
        T object = value;
        if (object is DiagnosticsNode) {
            return object.getChildren();
        }
        if (object is Diagnosticable) {
            return object.toDiagnosticsNode(style).getChildren();
        }
    }
    return const ;
}

String DiagnosticsProperty::_addTooltip(String text) {
    assert(text != nullptr);
    return tooltip == nullptr? text : "$text ($tooltip)";
}

void DiagnosticsProperty::_maybeCacheValue() {
    if (_valueComputed) {
        return;
    }
    _valueComputed = true;
    assert(_computeValue != nullptr);
    ;
}

DiagnosticableNode::DiagnosticableNode(Unknown, Unknown, T value) {
    {
        assert(value != nullptr);
    }
}

DiagnosticPropertiesBuilder DiagnosticableNode::builder() {
    if (kReleaseMode) {
        return nullptr;
    } else {
        assert(());
        return _cachedBuilder;
    }
}

DiagnosticsTreeStyle DiagnosticableNode::style() {
    return kReleaseMode? DiagnosticsTreeStyle.none : super.style ?? builder!.defaultDiagnosticsTreeStyle;
}

String DiagnosticableNode::emptyBodyDescription() {
    return (kReleaseMode || kProfileMode)? "" : builder!.emptyBodyDescription;
}

List<DiagnosticsNode> DiagnosticableNode::getProperties() {
    return (kReleaseMode || kProfileMode)? const  : builder!.properties;
}

List<DiagnosticsNode> DiagnosticableNode::getChildren() {
    return const ;
}

String DiagnosticableNode::toDescription(TextTreeConfiguration parentConfiguration) {
    String result = "";
    assert(());
    return result;
}

List<DiagnosticsNode> DiagnosticableTreeNode::getChildren() {
    return value.debugDescribeChildren();
}

String shortHash(Object object) {
    return object.hashCode.toUnsigned(20).toRadixString(16).padLeft(5, "0");
}

String describeIdentity(Object object) {
    return "${objectRuntimeType(object, '<optimized out>')}#${shortHash(object)}";
}

String describeEnum(Object enumEntry) {
    if (enumEntry is Enum) {
        return enumEntry.name;
    }
    String description = enumEntry.toString();
    int indexOfDot = description.indexOf(".");
    assert(indexOfDot != -1 &&  < description.length - 1, "The provided object "$enumEntry" is not an enum.");
    return description.substring(indexOfDot + 1);
}

DiagnosticPropertiesBuilder::DiagnosticPropertiesBuilder() {
    {
        properties = ;
    }
}

void DiagnosticPropertiesBuilder::add(DiagnosticsNode property) {
    assert(());
}

String Diagnosticable::toStringShort() {
    return describeIdentity(this);
}

String Diagnosticable::toString(DiagnosticLevel minLevel) {
    String fullString;
    assert(());
    return fullString ?? toStringShort();
}

DiagnosticsNode Diagnosticable::toDiagnosticsNode(String name, DiagnosticsTreeStyle style) {
    return <Diagnosticable>DiagnosticableNode(name, this, style);
}

void Diagnosticable::debugFillProperties(DiagnosticPropertiesBuilder properties) {
}

String DiagnosticableTree::toStringShallow(String joiner, DiagnosticLevel minLevel) {
    String shallowString;
    assert(());
    return shallowString ?? toString();
}

String DiagnosticableTree::toStringDeep(DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines) {
    return toDiagnosticsNode().toStringDeep(prefixLineOne, prefixOtherLines, minLevel);
}

String DiagnosticableTree::toStringShort() {
    return describeIdentity(this);
}

DiagnosticsNode DiagnosticableTree::toDiagnosticsNode(String name, DiagnosticsTreeStyle style) {
    return DiagnosticableTreeNode(name, this, style);
}

List<DiagnosticsNode> DiagnosticableTree::debugDescribeChildren() {
    return const ;
}

String DiagnosticableTreeMixin::toString(DiagnosticLevel minLevel) {
    return toDiagnosticsNode(DiagnosticsTreeStyle.singleLine).toString(minLevel);
}

String DiagnosticableTreeMixin::toStringShallow(String joiner, DiagnosticLevel minLevel) {
    String shallowString;
    assert(());
    return shallowString ?? toString();
}

String DiagnosticableTreeMixin::toStringDeep(DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines) {
    return toDiagnosticsNode().toStringDeep(prefixLineOne, prefixOtherLines, minLevel);
}

String DiagnosticableTreeMixin::toStringShort() {
    return describeIdentity(this);
}

DiagnosticsNode DiagnosticableTreeMixin::toDiagnosticsNode(String name, DiagnosticsTreeStyle style) {
    return DiagnosticableTreeNode(name, this, style);
}

List<DiagnosticsNode> DiagnosticableTreeMixin::debugDescribeChildren() {
    return const ;
}

void DiagnosticableTreeMixin::debugFillProperties(DiagnosticPropertiesBuilder properties) {
}

DiagnosticsBlock::DiagnosticsBlock(bool allowTruncate, List<DiagnosticsNode> children, String description, DiagnosticLevel level, Unknown, Unknown, List<DiagnosticsNode> properties, bool showName, Unknown, DiagnosticsTreeStyle style, Object value) {
    {
        _description = description ?? "";
        _children = children;
        _properties = properties;
        super(showName && name != nullptr);
    }
}

List<DiagnosticsNode> DiagnosticsBlock::getChildren() {
    return _children;
}

List<DiagnosticsNode> DiagnosticsBlock::getProperties() {
    return _properties;
}

String DiagnosticsBlock::toDescription(TextTreeConfiguration parentConfiguration) {
    return _description;
}

Map<String, Object> _DefaultDiagnosticsSerializationDelegate::additionalNodeProperties(DiagnosticsNode node) {
    return const ;
}

DiagnosticsSerializationDelegate _DefaultDiagnosticsSerializationDelegate::delegateForNode(DiagnosticsNode node) {
    return subtreeDepth > 0? copyWith(subtreeDepth - 1) : this;
}

bool _DefaultDiagnosticsSerializationDelegate::expandPropertyValues() {
    return false;
}

List<DiagnosticsNode> _DefaultDiagnosticsSerializationDelegate::filterChildren(List<DiagnosticsNode> nodes, DiagnosticsNode owner) {
    return nodes;
}

List<DiagnosticsNode> _DefaultDiagnosticsSerializationDelegate::filterProperties(List<DiagnosticsNode> nodes, DiagnosticsNode owner) {
    return nodes;
}

List<DiagnosticsNode> _DefaultDiagnosticsSerializationDelegate::truncateNodesList(List<DiagnosticsNode> nodes, DiagnosticsNode owner) {
    return nodes;
}

DiagnosticsSerializationDelegate _DefaultDiagnosticsSerializationDelegate::copyWith(bool includeProperties, int subtreeDepth) {
    return _DefaultDiagnosticsSerializationDelegate(subtreeDepth ?? this.subtreeDepth, includeProperties ?? this.includeProperties);
}
