#include "diagnostics.hpp"
TextTreeConfigurationCls::TextTreeConfigurationCls(bool addBlankLineIfNoChildren, String afterDescription, String afterDescriptionIfBody, String afterName, String afterProperties, String beforeName, String beforeProperties, String bodyIndent, String footer, bool isBlankLineBetweenPropertiesAndChildren, bool isNameOnOwnLine, String lineBreak, bool lineBreakProperties, String linkCharacter, String mandatoryAfterProperties, String mandatoryFooter, String prefixLastChildLineOne, String prefixLineOne, String prefixOtherLines, String prefixOtherLinesRootNode, String propertyPrefixIfChildren, String propertyPrefixNoChildren, String propertySeparator, bool showChildren, String suffixLineOne) {
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
        childLinkSpace = __s(" ") * linkCharacter->length();
    }
}

String _PrefixedStringBuilderCls::prefixOtherLines() {
    return _nextPrefixOtherLines | _prefixOtherLines;
}

void _PrefixedStringBuilderCls::prefixOtherLines(String prefix) {
    _prefixOtherLines = prefix;
    _nextPrefixOtherLines = nullptr;
}

void _PrefixedStringBuilderCls::incrementPrefixOtherLines(String suffix, bool updateCurrentLine) {
    if (_currentLine->isEmpty() || updateCurrentLine) {
        _prefixOtherLines = prefixOtherLines()! + suffix;
        _nextPrefixOtherLines = nullptr;
    } else {
        _nextPrefixOtherLines = prefixOtherLines()! + suffix;
    }
}

bool _PrefixedStringBuilderCls::requiresMultipleLines() {
    return _numLines > 1 || (_numLines == 1 && _currentLine->isNotEmpty()) || (_currentLine->length() + _getCurrentPrefix(true)!->length() > wrapWidth!);
}

bool _PrefixedStringBuilderCls::isCurrentLineEmpty() {
    return _currentLine->isEmpty();
}

void _PrefixedStringBuilderCls::write(String s, bool allowWrap) {
    if (s->isEmpty()) {
        return;
    }
    List<String> lines = s->split(__s("\n"));
    for (;  < lines->length(); i += 1) {
        if (i > 0) {
            _finalizeLine(true);
            _updatePrefix();
        }
        String line = lines[i];
        if (line->isNotEmpty()) {
            if (allowWrap && wrapWidth != nullptr) {
                int wrapStart = _currentLine->length();
                int wrapEnd = wrapStart + line->length();
                if (_wrappableRanges->isNotEmpty() && _wrappableRanges->last == wrapStart) {
                    _wrappableRanges->last = wrapEnd;
                } else {
                                    auto _c1 = _wrappableRanges;                _c1.auto _c2 = add(wrapStart);                _c2.add(wrapEnd);                _c2;_c1;
                }
            }
            _currentLine->write(line);
        }
    }
}

void _PrefixedStringBuilderCls::writeRawLines(String lines) {
    if (lines->isEmpty()) {
        return;
    }
    if (_currentLine->isNotEmpty()) {
        _finalizeLine(true);
    }
    assert(_currentLine->isEmpty());
    _buffer->write(lines);
    if (!lines->endsWith(__s("\n"))) {
        _buffer->write(__s("\n"));
    }
    _numLines++;
    _updatePrefix();
}

void _PrefixedStringBuilderCls::writeStretched(String text, int targetLineLength) {
    write(text);
    int currentLineLength = _currentLine->length() + _getCurrentPrefix(_buffer->isEmpty())!->length();
    assert(_currentLine->length() > 0);
    int targetLength = targetLineLength - currentLineLength;
    if (targetLength > 0) {
        assert(text->isNotEmpty());
        String lastChar = text[text->length() - 1];
        assert(lastChar != __s("\n"));
        _currentLine->write(lastChar * targetLength);
    }
    _wrappableRanges->clear();
}

String _PrefixedStringBuilderCls::build() {
    if (_currentLine->isNotEmpty()) {
        _finalizeLine(false);
    }
    return _buffer->toString();
}

_PrefixedStringBuilderCls::_PrefixedStringBuilderCls(String prefixLineOne, String prefixOtherLines, int wrapWidth) {
    {
        _prefixOtherLines = prefixOtherLines;
    }
}

void _PrefixedStringBuilderCls::_finalizeLine(bool addTrailingLineBreak) {
    bool firstLine = _buffer->isEmpty();
    String text = _currentLine->toString();
    _currentLine->clear();
    if (_wrappableRanges->isEmpty()) {
        _writeLine(text, addTrailingLineBreak, firstLine);
        return;
    }
    Iterable<String> lines = _wordWrapLine(text, _wrappableRanges, wrapWidth!, firstLine? prefixLineOne->length() : _prefixOtherLines!->length(), _prefixOtherLines!->length());
    int i = 0;
    int length = lines->length();
    for (String line : lines) {
        i++;
        _writeLine(line, addTrailingLineBreak ||  < length, firstLine);
    }
    _wrappableRanges->clear();
}

Iterable<String> _PrefixedStringBuilderCls::_wordWrapLine(String message, List<int> wrapRanges, int width, int otherLineOffset, int startOffset) {
    if (message->length() +  < width) {
        return makeList(ArrayItem);
    }
    List<String> wrappedLine = makeList();
    int startForLengthCalculations = -startOffset;
    bool addPrefix = false;
    int index = 0;
    _WordWrapParseMode mode = _WordWrapParseModeCls::inSpace;
    int lastWordStart;
    int lastWordEnd;
    int start = 0;
    int currentChunk = 0;
    InlineMethod;
    while (true) {
        ;
    }
}

void _PrefixedStringBuilderCls::_updatePrefix() {
    if (_nextPrefixOtherLines != nullptr) {
        _prefixOtherLines = _nextPrefixOtherLines;
        _nextPrefixOtherLines = nullptr;
    }
}

void _PrefixedStringBuilderCls::_writeLine(String line, bool firstLine, bool includeLineBreak) {
    line = __sf("%s%s", _getCurrentPrefix(firstLine), line);
    _buffer->write(line->trimRight());
    if (includeLineBreak) {
        _buffer->write(__s("\n"));
    }
    _numLines++;
}

String _PrefixedStringBuilderCls::_getCurrentPrefix(bool firstLine) {
    return _buffer->isEmpty()? prefixLineOne : _prefixOtherLines;
}

bool _isSingleLine(DiagnosticsTreeStyle style) {
    return style == DiagnosticsTreeStyleCls::singleLine;
}

TextTreeRendererCls::TextTreeRendererCls(int maxDescendentsTruncatableNode, DiagnosticLevel minLevel, int wrapWidth, int wrapWidthProperties) {
    {
        assert(minLevel != nullptr);
        _minLevel = minLevel;
        _wrapWidth = wrapWidth;
        _wrapWidthProperties = wrapWidthProperties;
        _maxDescendentsTruncatableNode = maxDescendentsTruncatableNode;
    }
}

String TextTreeRendererCls::render(DiagnosticsNode node, TextTreeConfiguration parentConfiguration, String prefixLineOne, String prefixOtherLines) {
    if (kReleaseMode) {
        return __s("");
    } else {
        return _debugRender(node, prefixLineOne, prefixOtherLines, parentConfiguration);
    }
}

TextTreeConfiguration TextTreeRendererCls::_childTextConfiguration(DiagnosticsNode child, TextTreeConfiguration textStyle) {
    DiagnosticsTreeStyle childStyle = child->style;
    return (_isSingleLine(childStyle) || childStyle == DiagnosticsTreeStyleCls::errorProperty)? textStyle : child->textTreeConfiguration();
}

String TextTreeRendererCls::_debugRender(DiagnosticsNode node, TextTreeConfiguration parentConfiguration, String prefixLineOne, String prefixOtherLines) {
    bool isSingleLine = _isSingleLine(node->style) && parentConfiguration?->lineBreakProperties != true;
    prefixOtherLines |= prefixLineOne;
    if (node->linePrefix != nullptr) {
        prefixLineOne += node->linePrefix!;
        prefixOtherLines += node->linePrefix!;
    }
    TextTreeConfiguration config = node->textTreeConfiguration()!;
    if (prefixOtherLines->isEmpty()) {
        prefixOtherLines += config->prefixOtherLinesRootNode;
    }
    if (node->style == DiagnosticsTreeStyleCls::truncateChildren) {
        List<String> descendants = makeList();
        int maxDepth = 5;
        int depth = 0;
        int maxLines = 25;
        int lines = 0;
        InlineMethod;
        visitor(node);
        StringBuffer information = make<StringBufferCls>(prefixLineOne);
        if (lines > 1) {
            information->writeln(__sf("This %s had the following descendants (showing up to depth %s):", node->name, maxDepth));
        } else {
            if (descendants->length() == 1) {
            information->writeln(__sf("This %s had the following child:", node->name));
        } else {
            information->writeln(__sf("This %s has no descendants.", node->name));
        }
;
        }        information->writeAll(descendants, __s("\n"));
        return information->toString();
    }
    _PrefixedStringBuilder builder = make<_PrefixedStringBuilderCls>(prefixLineOne, prefixOtherLines, math->max(_wrapWidth, prefixOtherLines->length() + _wrapWidthProperties));
    List<DiagnosticsNode> children = node->getChildren();
    String description = node->toDescription(parentConfiguration);
    if (config->beforeName->isNotEmpty()) {
        builder->write(config->beforeName);
    }
    bool wrapName = !isSingleLine && node->allowNameWrap();
    bool wrapDescription = !isSingleLine && node->allowWrap();
    bool uppercaseTitle = node->style == DiagnosticsTreeStyleCls::error;
    String name = node->name;
    if (uppercaseTitle) {
        name = name?->toUpperCase();
    }
    if (description == nullptr || description->isEmpty()) {
        if (node->showName && name != nullptr) {
            builder->write(name, wrapName);
        }
    } else {
        bool includeName = false;
        if (name != nullptr && name->isNotEmpty() && node->showName) {
            includeName = true;
            builder->write(name, wrapName);
            if (node->showSeparator) {
                builder->write(config->afterName, wrapName);
            }
            builder->write(config->isNameOnOwnLine || description->contains(__s("\n"))? __s("\n") : __s(" "), wrapName);
        }
        if (!isSingleLine && builder->requiresMultipleLines() && !builder->isCurrentLineEmpty()) {
            builder->write(__s("\n"));
        }
        if (includeName) {
            builder->incrementPrefixOtherLines(children->isEmpty()? config->propertyPrefixNoChildren : config->propertyPrefixIfChildren, true);
        }
        if (uppercaseTitle) {
            description = description->toUpperCase();
        }
        builder->write(description->trimRight(), wrapDescription);
        if (!includeName) {
            builder->incrementPrefixOtherLines(children->isEmpty()? config->propertyPrefixNoChildren : config->propertyPrefixIfChildren, false);
        }
    }
    if (config->suffixLineOne->isNotEmpty()) {
        builder->writeStretched(config->suffixLineOne, builder->wrapWidth!);
    }
    Iterable<DiagnosticsNode> propertiesIterable = node->getProperties()->where([=] (DiagnosticsNode n) {
    !n->isFiltered(_minLevel);
});
    List<DiagnosticsNode> properties;
    if (_maxDescendentsTruncatableNode >= 0 && node->allowTruncate()) {
        if (propertiesIterable->length() < _maxDescendentsTruncatableNode) {
            properties = propertiesIterable->take(_maxDescendentsTruncatableNode)->toList();
            properties->add(DiagnosticsNodeCls->message(__s("...")));
        } else {
            properties = propertiesIterable->toList();
        }
        if ( < children->length()) {
            children = children->take(_maxDescendentsTruncatableNode)->toList();
            children->add(DiagnosticsNodeCls->message(__s("...")));
        }
    } else {
        properties = propertiesIterable->toList();
    }
    if ((properties->isNotEmpty() || children->isNotEmpty() || node->emptyBodyDescription() != nullptr) && (node->showSeparator || description->isNotEmpty())) {
        builder->write(config->afterDescriptionIfBody);
    }
    if (config->lineBreakProperties) {
        builder->write(config->lineBreak);
    }
    if (properties->isNotEmpty()) {
        builder->write(config->beforeProperties);
    }
    builder->incrementPrefixOtherLines(config->bodyIndent, false);
    if (node->emptyBodyDescription() != nullptr && properties->isEmpty() && children->isEmpty() && prefixLineOne->isNotEmpty()) {
        builder->write(node->emptyBodyDescription()!);
        if (config->lineBreakProperties) {
            builder->write(config->lineBreak);
        }
    }
    for (;  < properties->length(); ++i) {
        DiagnosticsNode property = properties[i];
        if (i > 0) {
            builder->write(config->propertySeparator);
        }
        TextTreeConfiguration propertyStyle = property->textTreeConfiguration()!;
        if (_isSingleLine(property->style)) {
            String propertyRender = render(property, propertyStyle->prefixLineOne, __sf("%s%s", propertyStyle->childLinkSpace, propertyStyle->prefixOtherLines), config);
            List<String> propertyLines = propertyRender->split(__s("\n"));
            if (propertyLines->length() == 1 && !config->lineBreakProperties) {
                builder->write(propertyLines->first);
            } else {
                builder->write(propertyRender);
                if (!propertyRender->endsWith(__s("\n"))) {
                    builder->write(__s("\n"));
                }
            }
        } else {
            String propertyRender = render(property, __sf("%s%s", builder->prefixOtherLines, propertyStyle->prefixLineOne), __sf("%s%s%s", builder->prefixOtherLines, propertyStyle->childLinkSpace, propertyStyle->prefixOtherLines), config);
            builder->writeRawLines(propertyRender);
        }
    }
    if (properties->isNotEmpty()) {
        builder->write(config->afterProperties);
    }
    builder->write(config->mandatoryAfterProperties);
    if (!config->lineBreakProperties) {
        builder->write(config->lineBreak);
    }
    String prefixChildren = config->bodyIndent;
    String prefixChildrenRaw = __sf("%s%s", prefixOtherLines, prefixChildren);
    if (children->isEmpty() && config->addBlankLineIfNoChildren && builder->requiresMultipleLines() && builder->prefixOtherLines!->trimRight()->isNotEmpty()) {
        builder->write(config->lineBreak);
    }
    if (children->isNotEmpty() && config->showChildren) {
        if (config->isBlankLineBetweenPropertiesAndChildren && properties->isNotEmpty() && children->first->textTreeConfiguration!->isBlankLineBetweenPropertiesAndChildren) {
            builder->write(config->lineBreak);
        }
        builder->prefixOtherLines = prefixOtherLines;
        for (;  < children->length(); i++) {
            DiagnosticsNode child = children[i];
            assert(child != nullptr);
            TextTreeConfiguration childConfig = _childTextConfiguration(child, config)!;
            if (i == children->length() - 1) {
                String lastChildPrefixLineOne = __sf("%s%s", prefixChildrenRaw, childConfig->prefixLastChildLineOne);
                String childPrefixOtherLines = __sf("%s%s%s", prefixChildrenRaw, childConfig->childLinkSpace, childConfig->prefixOtherLines);
                builder->writeRawLines(render(child, lastChildPrefixLineOne, childPrefixOtherLines, config));
                if (childConfig->footer->isNotEmpty()) {
                    builder->prefixOtherLines = prefixChildrenRaw;
                    builder->write(__sf("%s%s", childConfig->childLinkSpace, childConfig->footer));
                    if (childConfig->mandatoryFooter->isNotEmpty()) {
                        builder->writeStretched(childConfig->mandatoryFooter, math->max(builder->wrapWidth!, _wrapWidthProperties + childPrefixOtherLines->length()));
                    }
                    builder->write(config->lineBreak);
                }
            } else {
                TextTreeConfiguration nextChildStyle = _childTextConfiguration(children[i + 1], config)!;
                String childPrefixLineOne = __sf("%s%s", prefixChildrenRaw, childConfig->prefixLineOne);
                String childPrefixOtherLines = __sf("%s%s%s", prefixChildrenRaw, nextChildStyle->linkCharacter, childConfig->prefixOtherLines);
                builder->writeRawLines(render(child, childPrefixLineOne, childPrefixOtherLines, config));
                if (childConfig->footer->isNotEmpty()) {
                    builder->prefixOtherLines = prefixChildrenRaw;
                    builder->write(__sf("%s%s", childConfig->linkCharacter, childConfig->footer));
                    if (childConfig->mandatoryFooter->isNotEmpty()) {
                        builder->writeStretched(childConfig->mandatoryFooter, math->max(builder->wrapWidth!, _wrapWidthProperties + childPrefixOtherLines->length()));
                    }
                    builder->write(config->lineBreak);
                }
            }
        }
    }
    if (parentConfiguration == nullptr && config->mandatoryFooter->isNotEmpty()) {
        builder->writeStretched(config->mandatoryFooter, builder->wrapWidth!);
        builder->write(config->lineBreak);
    }
    return builder->build();
}

DiagnosticsNodeCls::DiagnosticsNodeCls(String linePrefix, String name, bool showName, bool showSeparator, DiagnosticsTreeStyle style) {
    {
        assert(showName != nullptr);
        assert(showSeparator != nullptr);
        assert(name == nullptr || !name->endsWith(__s(":")), __sf("Names of diagnostic nodes must not end with colons.\nname:\n  "%s"", name));
    }
}

void DiagnosticsNodeCls::message(String message, bool allowWrap, DiagnosticLevel level, DiagnosticsTreeStyle style) {
    assert(style != nullptr);
    assert(level != nullptr);
    return <void>make<DiagnosticsPropertyCls>(__s(""), nullptr, message, style, false, allowWrap, level);
}

bool DiagnosticsNodeCls::isFiltered(DiagnosticLevel minLevel) {
    return kReleaseMode || level()->index < minLevel->index;
}

DiagnosticLevel DiagnosticsNodeCls::level() {
    return kReleaseMode? DiagnosticLevelCls::hidden : DiagnosticLevelCls::info;
}

String DiagnosticsNodeCls::emptyBodyDescription() {
    return nullptr;
}

bool DiagnosticsNodeCls::allowWrap() {
    return false;
}

bool DiagnosticsNodeCls::allowNameWrap() {
    return false;
}

bool DiagnosticsNodeCls::allowTruncate() {
    return false;
}

Map<String, String> DiagnosticsNodeCls::toTimelineArguments() {
    if (!kReleaseMode) {
        if (kProfileMode) {
            throw make<FlutterErrorCls>(__sf("%s.toTimelineArguments used in non-debug build.\nThe %s.toTimelineArguments API is expensive and causes timeline traces to be non-representative. As such, it should not be used in profile builds. However, this application is compiled in profile mode and yet still invoked the method.", DiagnosticsNodeCls, DiagnosticsNodeCls));
        }
        Map<String, String> result = makeMap(makeList(), makeList();
        for (DiagnosticsNode property : getProperties()) {
            if (property->name != nullptr) {
                result[property->name!] = property->toDescription(singleLineTextConfiguration);
            }
        }
        return result;
    }
    return nullptr;
}

Map<String, Object> DiagnosticsNodeCls::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> result = makeMap(makeList(), makeList();
    assert([=] () {
        bool hasChildren = getChildren()->isNotEmpty();
            Map<String, Object> map1 = make<MapCls<>>();    map1.set(__s("description"), toDescription());    map1.set(__s("type"), runtimeType->toString());    if (name != nullptr) {        map1.set(__s("name"), name);    }if (!showSeparator) {        map1.set(__s("showSeparator"), showSeparator);    }if (level() != DiagnosticLevelCls::info) {        map1.set(__s("level"), level()->name);    }if (showName == false) {        map1.set(__s("showName"), showName);    }if (emptyBodyDescription() != nullptr) {        map1.set(__s("emptyBodyDescription"), emptyBodyDescription());    }if (style != DiagnosticsTreeStyleCls::sparse) {        map1.set(__s("style"), style!->name);    }if (allowTruncate()) {        map1.set(__s("allowTruncate"), allowTruncate());    }if (hasChildren) {        map1.set(__s("hasChildren"), hasChildren);    }if (linePrefix?->isNotEmpty() | false) {        map1.set(__s("linePrefix"), linePrefix);    }if (!allowWrap()) {        map1.set(__s("allowWrap"), allowWrap());    }if (allowNameWrap()) {        map1.set(__s("allowNameWrap"), allowNameWrap());    }map1.addAll(delegate->additionalNodeProperties(this));if (delegate->includeProperties()) {        map1.set(__s("properties"), toJsonList(delegate->filterProperties(getProperties(), this), this, delegate));    }if (delegate->subtreeDepth() > 0) {        map1.set(__s("children"), toJsonList(delegate->filterChildren(getChildren(), this), this, delegate));    }result = list1;
        return true;
    }());
    return result;
}

List<Map<String, Object>> DiagnosticsNodeCls::toJsonList(List<DiagnosticsNode> nodes, DiagnosticsNode parent, DiagnosticsSerializationDelegate delegate) {
    bool truncated = false;
    if (nodes == nullptr) {
        return makeList();
    }
    int originalNodeCount = nodes->length();
    nodes = delegate->truncateNodesList(nodes, parent);
    if (nodes->length() != originalNodeCount) {
        nodes->add(DiagnosticsNodeCls->message(__s("...")));
        truncated = true;
    }
    List<Map<String, Object>> json = nodes-><Map<String, Object>>map([=] (DiagnosticsNode node) {
    return node->toJsonMap(delegate->delegateForNode(node));
})->toList();
    if (truncated) {
        json->last[__s("truncated")] = true;
    }
    return json;
}

String DiagnosticsNodeCls::toString(DiagnosticLevel minLevel, TextTreeConfiguration parentConfiguration) {
    String result = super->toString();
    assert(style != nullptr);
    assert(minLevel != nullptr);
    assert([=] () {
        if (_isSingleLine(style)) {
            result = toStringDeep(parentConfiguration, minLevel);
        } else {
            String description = toDescription(parentConfiguration);
            if (name == nullptr || name!->isEmpty() || !showName) {
                result = description;
            } else {
                result = description->contains(__s("\n"))? __sf("%s%s\n%s", name, _separator(), description) : __sf("%s%s %s", name, _separator(), description);
            }
        }
        return true;
    }());
    return result;
}

TextTreeConfiguration DiagnosticsNodeCls::textTreeConfiguration() {
    assert(style != nullptr);
    ;
}

String DiagnosticsNodeCls::toStringDeep(DiagnosticLevel minLevel, TextTreeConfiguration parentConfiguration, String prefixLineOne, String prefixOtherLines) {
    String result = __s("");
    assert([=] () {
        result = make<TextTreeRendererCls>(minLevel, 65)->render(this, prefixLineOne, prefixOtherLines, parentConfiguration);
        return true;
    }());
    return result;
}

String DiagnosticsNodeCls::_separator() {
    return showSeparator? __s(":") : __s("");
}

MessagePropertyCls::MessagePropertyCls(String name, String message, DiagnosticLevel level, DiagnosticsTreeStyle style) : DiagnosticsProperty<void>(name, nullptrmessage, style, level) {
    {
        assert(name != nullptr);
        assert(message != nullptr);
        assert(style != nullptr);
        assert(level != nullptr);
    }
}

StringPropertyCls::StringPropertyCls(String name, Unknown value, Object defaultValue, Unknown description, String ifEmpty, Unknown level, bool quoted, bool showName, DiagnosticsTreeStyle style, String tooltip) {
    {
        assert(showName != nullptr);
        assert(quoted != nullptr);
        assert(style != nullptr);
        assert(level() != nullptr);
    }
}

Map<String, Object> StringPropertyCls::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super->toJsonMap(delegate);
    json[__s("quoted")] = quoted;
    return json;
}

String StringPropertyCls::valueToString(TextTreeConfiguration parentConfiguration) {
    String text = _description | value();
    if (parentConfiguration != nullptr && !parentConfiguration->lineBreakProperties && text != nullptr) {
        text = text->replaceAll(__s("\n"), __s("\n"));
    }
    if (quoted && text != nullptr) {
        if (ifEmpty != nullptr && text->isEmpty()) {
            return ifEmpty!;
        }
        return __sf(""%s"", text);
    }
    return text->toString();
}

template<typename T>
void _NumPropertyCls<T>::lazy(String name, Unknown computeValue, Object defaultValue, String ifNull, Unknown level, bool showName, DiagnosticsTreeStyle style, String tooltip, String unit)

template<typename T>
Map<String, Object> _NumPropertyCls<T>::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super->toJsonMap(delegate);
    if (unit != nullptr) {
        json[__s("unit")] = unit;
    }
    json[__s("numberToString")] = numberToString();
    return json;
}

template<typename T>
String _NumPropertyCls<T>::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value() == nullptr) {
        return value()->toString();
    }
    return unit != nullptr? __sf("%s%s", numberToString(), unit) : numberToString();
}

DoublePropertyCls::DoublePropertyCls(String name, Unknown value, Object defaultValue, String ifNull, Unknown level, bool showName, DiagnosticsTreeStyle style, String tooltip, String unit) {
    {
        assert(showName != nullptr);
        assert(style != nullptr);
        assert(level() != nullptr);
    }
}

void DoublePropertyCls::lazy(String name, Unknown computeValue, Object defaultValue, String ifNull, Unknown level, bool showName, String tooltip, String unit)

String DoublePropertyCls::numberToString() {
    return debugFormatDouble(value());
}

IntPropertyCls::IntPropertyCls(String name, Unknown value, Object defaultValue, String ifNull, Unknown level, bool showName, DiagnosticsTreeStyle style, String unit) {
    {
        assert(showName != nullptr);
        assert(level() != nullptr);
        assert(style != nullptr);
    }
}

String IntPropertyCls::numberToString() {
    return value()->toString();
}

PercentPropertyCls::PercentPropertyCls(String name, Unknown fraction, String ifNull, Unknown level, bool showName, String tooltip, String unit) {
    {
        assert(showName != nullptr);
        assert(level() != nullptr);
    }
}

String PercentPropertyCls::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value() == nullptr) {
        return value()->toString();
    }
    return unit != nullptr? __sf("%s %s", numberToString(), unit) : numberToString();
}

String PercentPropertyCls::numberToString() {
    double v = value();
    if (v == nullptr) {
        return value()->toString();
    }
    return __sf("%s%", (clampDouble(v, 0.0, 1.0) * 100.0)->toStringAsFixed(1));
}

FlagPropertyCls::FlagPropertyCls(String name, Object defaultValue, String ifFalse, String ifTrue, DiagnosticLevel level, bool showName, bool value) : DiagnosticsProperty<bool>(name, valueshowName, defaultValue, level) {
    {
        assert(showName != nullptr);
        assert(level != nullptr);
        assert(ifTrue != nullptr || ifFalse != nullptr);
    }
}

Map<String, Object> FlagPropertyCls::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super->toJsonMap(delegate);
    if (ifTrue != nullptr) {
        json[__s("ifTrue")] = ifTrue;
    }
    if (ifFalse != nullptr) {
        json[__s("ifFalse")] = ifFalse;
    }
    return json;
}

String FlagPropertyCls::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value() | false) {
        if (ifTrue != nullptr) {
            return ifTrue!;
        }
    } else {
        if (value() == false) {
        if (ifFalse != nullptr) {
            return ifFalse!;
        }
    }
;
    }    return super->valueToString(parentConfiguration);
}

bool FlagPropertyCls::showName() {
    if (value() == nullptr || ((value() | false) && ifTrue == nullptr) || (!(value() | true) && ifFalse == nullptr)) {
        return true;
    }
    return super->showName;
}

DiagnosticLevel FlagPropertyCls::level() {
    if (value() | false) {
        if (ifTrue == nullptr) {
            return DiagnosticLevelCls::hidden;
        }
    }
    if (value() == false) {
        if (ifFalse == nullptr) {
            return DiagnosticLevelCls::hidden;
        }
    }
    return super->level;
}

template<typename T>
IterablePropertyCls<T>::IterablePropertyCls(String name, Unknown value, Object defaultValue, String ifEmpty, String ifNull, Unknown level, bool showName, bool showSeparator, DiagnosticsTreeStyle style) {
    {
        assert(style != nullptr);
        assert(showName != nullptr);
        assert(showSeparator != nullptr);
        assert(level() != nullptr);
    }
}

template<typename T>
String IterablePropertyCls<T>::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value() == nullptr) {
        return value()->toString();
    }
    if (value()!->isEmpty) {
        return ifEmpty | __s("[]");
    }
    Iterable<String> formattedValues = value()!->map([=] (T v) {
    if (T == double && is<double>(v)) {
        return debugFormatDouble(v);
    } else {
        return v->toString();
    }
});
    if (parentConfiguration != nullptr && !parentConfiguration->lineBreakProperties) {
        return __sf("[%s]", formattedValues->join(__s(", ")));
    }
    return formattedValues->join(_isSingleLine(style)? __s(", ") : __s("\n"));
}

template<typename T>
DiagnosticLevel IterablePropertyCls<T>::level() {
    if (ifEmpty == nullptr && value() != nullptr && value()!->isEmpty && super->level != DiagnosticLevelCls::hidden) {
        return DiagnosticLevelCls::fine;
    }
    return super->level;
}

template<typename T>
Map<String, Object> IterablePropertyCls<T>::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super->toJsonMap(delegate);
    if (value() != nullptr) {
        json[__s("values")] = value()!-><String>map([=] (T value) {
            value()->toString();
        })->toList();
    }
    return json;
}

template<typename T>
EnumPropertyCls<T>::EnumPropertyCls(String name, Unknown value, Object defaultValue, Unknown level) {
    {
        assert(level() != nullptr);
    }
}

template<typename T>
String EnumPropertyCls<T>::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value() == nullptr) {
        return value()->toString();
    }
    return describeEnum(value()!);
}

template<typename T>
ObjectFlagPropertyCls<T>::ObjectFlagPropertyCls(String name, Unknown value, String ifNull, String ifPresent, Unknown level, Unknown showName) {
    {
        assert(ifPresent != nullptr || ifNull != nullptr);
        assert(showName() != nullptr);
        assert(level() != nullptr);
    }
}

template<typename T>
void ObjectFlagPropertyCls<T>::has(String name, Unknown value, Unknown level)

template<typename T>
String ObjectFlagPropertyCls<T>::valueToString(TextTreeConfiguration parentConfiguration) {
    if (value() != nullptr) {
        if (ifPresent != nullptr) {
            return ifPresent!;
        }
    } else {
        if (ifNull != nullptr) {
            return ifNull!;
        }
    }
    return super->valueToString(parentConfiguration);
}

template<typename T>
bool ObjectFlagPropertyCls<T>::showName() {
    if ((value() != nullptr && ifPresent == nullptr) || (value() == nullptr && ifNull == nullptr)) {
        return true;
    }
    return super->showName;
}

template<typename T>
DiagnosticLevel ObjectFlagPropertyCls<T>::level() {
    if (value() != nullptr) {
        if (ifPresent == nullptr) {
            return DiagnosticLevelCls::hidden;
        }
    } else {
        if (ifNull == nullptr) {
            return DiagnosticLevelCls::hidden;
        }
    }
    return super->level;
}

template<typename T>
Map<String, Object> ObjectFlagPropertyCls<T>::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super->toJsonMap(delegate);
    if (ifPresent != nullptr) {
        json[__s("ifPresent")] = ifPresent;
    }
    return json;
}

template<typename T>
FlagsSummaryCls<T>::FlagsSummaryCls(String name, Map<String, T> value, String ifEmpty, Unknown level, bool showName, bool showSeparator) {
    {
        assert(value != nullptr);
        assert(showName != nullptr);
        assert(showSeparator != nullptr);
        assert(level() != nullptr);
    }
}

template<typename T>
Map<String, T> FlagsSummaryCls<T>::value() {
    return super->value!;
}

template<typename T>
String FlagsSummaryCls<T>::valueToString(TextTreeConfiguration parentConfiguration) {
    assert(value() != nullptr);
    if (!_hasNonNullEntry() && ifEmpty != nullptr) {
        return ifEmpty!;
    }
    Iterable<String> formattedValues = _formattedValues();
    if (parentConfiguration != nullptr && !parentConfiguration->lineBreakProperties) {
        return __sf("[%s]", formattedValues->join(__s(", ")));
    }
    return formattedValues->join(_isSingleLine(style)? __s(", ") : __s("\n"));
}

template<typename T>
DiagnosticLevel FlagsSummaryCls<T>::level() {
    if (!_hasNonNullEntry() && ifEmpty == nullptr) {
        return DiagnosticLevelCls::hidden;
    }
    return super->level;
}

template<typename T>
Map<String, Object> FlagsSummaryCls<T>::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    Map<String, Object> json = super->toJsonMap(delegate);
    if (value()->isNotEmpty()) {
        json[__s("values")] = _formattedValues()->toList();
    }
    return json;
}

template<typename T>
bool FlagsSummaryCls<T>::_hasNonNullEntry() {
    return value()->values()->any([=] (T o) {
        o != nullptr;
    });
}

template<typename T>
Iterable<String> FlagsSummaryCls<T>::_formattedValues() {
    return value()->entries()->where([=] (MapEntry<String, T> entry) {
        entry->value != nullptr;
    })->map([=] (MapEntry<String, T> entry) {
        entry->key;
    });
}

template<typename T>
DiagnosticsPropertyCls<T>::DiagnosticsPropertyCls(String name, T value, bool allowNameWrap, bool allowWrap, Object defaultValue, String description, bool expandableValue, String ifEmpty, String ifNull, DiagnosticLevel level, String linePrefix, bool missingIfNull, bool showName, bool showSeparator, DiagnosticsTreeStyle style, String tooltip) : DiagnosticsNode(name) {
    {
        assert(showName != nullptr);
        assert(showSeparator != nullptr);
        assert(style != nullptr);
        assert(level != nullptr);
        _description = description;
        _valueComputed = true;
        _value = value;
        _computeValue = nullptr;
        ifNull = ifNull | (missingIfNull? __s("MISSING") : nullptr);
        _defaultLevel = level;
    }
}

template<typename T>
void DiagnosticsPropertyCls<T>::lazy(String name, ComputePropertyValueCallback<T> computeValue, bool allowNameWrap, bool allowWrap, Object defaultValue, String description, bool expandableValue, String ifEmpty, String ifNull, DiagnosticLevel level, bool missingIfNull, bool showName, bool showSeparator, DiagnosticsTreeStyle style, String tooltip)

template<typename T>
Map<String, Object> DiagnosticsPropertyCls<T>::toJsonMap(DiagnosticsSerializationDelegate delegate) {
    T v = value();
    List<Map<String, Object>> properties;
    if (delegate->expandPropertyValues() && delegate->includeProperties() && is<Diagnosticable>(v) && getProperties()->isEmpty()) {
        delegate = delegate->copyWith(0, false);
        properties = DiagnosticsNodeCls->toJsonList(delegate->filterProperties(v->toDiagnosticsNode()->getProperties(), this), this, delegate);
    }
    Map<String, Object> json = super->toJsonMap(delegate);
    if (properties != nullptr) {
        json[__s("properties")] = properties;
    }
    if (defaultValue != kNoDefaultValue) {
        json[__s("defaultValue")] = defaultValue->toString();
    }
    if (ifEmpty != nullptr) {
        json[__s("ifEmpty")] = ifEmpty;
    }
    if (ifNull != nullptr) {
        json[__s("ifNull")] = ifNull;
    }
    if (tooltip != nullptr) {
        json[__s("tooltip")] = tooltip;
    }
    json[__s("missingIfNull")] = missingIfNull;
    if (exception() != nullptr) {
        json[__s("exception")] = exception()->toString();
    }
    json[__s("propertyType")] = propertyType()->toString();
    json[__s("defaultLevel")] = _defaultLevel->name;
    if (is<Diagnosticable>(value()) || is<DiagnosticsNode>(value())) {
        json[__s("isDiagnosticableValue")] = true;
    }
    if (is<num>(v)) {
        json[__s("value")] = as<numCls>(v)->isFinite()? as<numCls>(v) : as<numCls>(v)->toString();
    }
    if (is<String>(value()) || is<bool>(value()) || value() == nullptr) {
        json[__s("value")] = value();
    }
    return json;
}

template<typename T>
String DiagnosticsPropertyCls<T>::valueToString(TextTreeConfiguration parentConfiguration) {
    T v = value();
    return is<DiagnosticableTree>(v)? v->toStringShort() : v->toString();
}

template<typename T>
String DiagnosticsPropertyCls<T>::toDescription(TextTreeConfiguration parentConfiguration) {
    if (_description != nullptr) {
        return _addTooltip(_description!);
    }
    if (exception() != nullptr) {
        return __sf("EXCEPTION (%s)", exception()->runtimeType());
    }
    if (ifNull != nullptr && value() == nullptr) {
        return _addTooltip(ifNull!);
    }
    String result = valueToString(parentConfiguration);
    if (result->isEmpty() && ifEmpty != nullptr) {
        result = ifEmpty!;
    }
    return _addTooltip(result);
}

template<typename T>
Type DiagnosticsPropertyCls<T>::propertyType() {
    return T;
}

template<typename T>
T DiagnosticsPropertyCls<T>::value() {
    _maybeCacheValue();
    return _value;
}

template<typename T>
Object DiagnosticsPropertyCls<T>::exception() {
    _maybeCacheValue();
    return _exception;
}

template<typename T>
bool DiagnosticsPropertyCls<T>::isInteresting() {
    return defaultValue == kNoDefaultValue || value() != defaultValue;
}

template<typename T>
DiagnosticLevel DiagnosticsPropertyCls<T>::level() {
    if (_defaultLevel == DiagnosticLevelCls::hidden) {
        return _defaultLevel;
    }
    if (exception() != nullptr) {
        return DiagnosticLevelCls::error;
    }
    if (value() == nullptr && missingIfNull) {
        return DiagnosticLevelCls::warning;
    }
    if (!isInteresting()) {
        return DiagnosticLevelCls::fine;
    }
    return _defaultLevel;
}

template<typename T>
List<DiagnosticsNode> DiagnosticsPropertyCls<T>::getProperties() {
    if (expandableValue) {
        T object = value();
        if (is<DiagnosticsNode>(object)) {
            return as<DiagnosticsNodeCls>(object)->getProperties();
        }
        if (is<Diagnosticable>(object)) {
            return as<DiagnosticableCls>(object)->toDiagnosticsNode(style)->getProperties();
        }
    }
    return makeList();
}

template<typename T>
List<DiagnosticsNode> DiagnosticsPropertyCls<T>::getChildren() {
    if (expandableValue) {
        T object = value();
        if (is<DiagnosticsNode>(object)) {
            return as<DiagnosticsNodeCls>(object)->getChildren();
        }
        if (is<Diagnosticable>(object)) {
            return as<DiagnosticableCls>(object)->toDiagnosticsNode(style)->getChildren();
        }
    }
    return makeList();
}

template<typename T>
String DiagnosticsPropertyCls<T>::_addTooltip(String text) {
    assert(text != nullptr);
    return tooltip == nullptr? text : __sf("%s (%s)", text, tooltip);
}

template<typename T>
void DiagnosticsPropertyCls<T>::_maybeCacheValue() {
    if (_valueComputed) {
        return;
    }
    _valueComputed = true;
    assert(_computeValue != nullptr);
    try {
        _value = _computeValue!();
    } catch (Unknown exception) {
        _exception = exception();
        _value = nullptr;
    };
}

template<typename T>
DiagnosticableNodeCls<T>::DiagnosticableNodeCls(String name, Unknown style, T value) {
    {
        assert(value != nullptr);
    }
}

template<typename T>
DiagnosticPropertiesBuilder DiagnosticableNodeCls<T>::builder() {
    if (kReleaseMode) {
        return nullptr;
    } else {
        assert([=] () {
            if (_cachedBuilder == nullptr) {
                _cachedBuilder = make<DiagnosticPropertiesBuilderCls>();
                value->debugFillProperties(_cachedBuilder!);
            }
            return true;
        }());
        return _cachedBuilder;
    }
}

template<typename T>
DiagnosticsTreeStyle DiagnosticableNodeCls<T>::style() {
    return kReleaseMode? DiagnosticsTreeStyleCls::none : super->style | builder()!->defaultDiagnosticsTreeStyle;
}

template<typename T>
String DiagnosticableNodeCls<T>::emptyBodyDescription() {
    return (kReleaseMode || kProfileMode)? __s("") : builder()!->emptyBodyDescription;
}

template<typename T>
List<DiagnosticsNode> DiagnosticableNodeCls<T>::getProperties() {
    return (kReleaseMode || kProfileMode)? makeList() : builder()!->properties;
}

template<typename T>
List<DiagnosticsNode> DiagnosticableNodeCls<T>::getChildren() {
    return makeList();
}

template<typename T>
String DiagnosticableNodeCls<T>::toDescription(TextTreeConfiguration parentConfiguration) {
    String result = __s("");
    assert([=] () {
        result = value->toStringShort();
        return true;
    }());
    return result;
}

List<DiagnosticsNode> DiagnosticableTreeNodeCls::getChildren() {
    return value->debugDescribeChildren();
}

String shortHash(Object object) {
    return object->hashCode()->toUnsigned(20)->toRadixString(16)->padLeft(5, __s("0"));
}

String describeIdentity(Object object) {
    return __sf("%s#%s", objectRuntimeType(object, __s("<optimized out>")), shortHash(object));
}

String describeEnum(Object enumEntry) {
    if (is<Enum>(enumEntry)) {
        return as<EnumCls>(enumEntry)->name;
    }
    String description = enumEntry->toString();
    int indexOfDot = description->indexOf(__s("."));
    assert(indexOfDot != -1 &&  < description->length() - 1, __sf("The provided object "%s" is not an enum.", enumEntry));
    return description->substring(indexOfDot + 1);
}

DiagnosticPropertiesBuilderCls::DiagnosticPropertiesBuilderCls() {
    {
        properties = makeList();
    }
}

void DiagnosticPropertiesBuilderCls::add(DiagnosticsNode property) {
    assert([=] () {
        properties->add(property);
        return true;
    }());
}

String DiagnosticableCls::toStringShort() {
    return describeIdentity(this);
}

String DiagnosticableCls::toString(DiagnosticLevel minLevel) {
    String fullString;
    assert([=] () {
        fullString = toDiagnosticsNode(DiagnosticsTreeStyleCls::singleLine)->toString(minLevel);
        return true;
    }());
    return fullString | toStringShort();
}

DiagnosticsNode DiagnosticableCls::toDiagnosticsNode(String name, DiagnosticsTreeStyle style) {
    return <Diagnosticable>make<DiagnosticableNodeCls>(name, this, style);
}

void DiagnosticableCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
}

String DiagnosticableTreeCls::toStringShallow(String joiner, DiagnosticLevel minLevel) {
    String shallowString;
    assert([=] () {
        StringBuffer result = make<StringBufferCls>();
        result->write(toString());
        result->write(joiner);
        DiagnosticPropertiesBuilder builder = make<DiagnosticPropertiesBuilderCls>();
        debugFillProperties(builder);
        result->write(builder->properties->where([=] (DiagnosticsNode n) {
            !n->isFiltered(minLevel);
        })->join(joiner));
        shallowString = result->toString();
        return true;
    }());
    return shallowString | toString();
}

String DiagnosticableTreeCls::toStringDeep(DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines) {
    return toDiagnosticsNode()->toStringDeep(prefixLineOne, prefixOtherLines, minLevel);
}

String DiagnosticableTreeCls::toStringShort() {
    return describeIdentity(this);
}

DiagnosticsNode DiagnosticableTreeCls::toDiagnosticsNode(String name, DiagnosticsTreeStyle style) {
    return make<DiagnosticableTreeNodeCls>(name, this, style);
}

List<DiagnosticsNode> DiagnosticableTreeCls::debugDescribeChildren() {
    return makeList();
}

String DiagnosticableTreeMixinCls::toString(DiagnosticLevel minLevel) {
    return toDiagnosticsNode(DiagnosticsTreeStyleCls::singleLine)->toString(minLevel);
}

String DiagnosticableTreeMixinCls::toStringShallow(String joiner, DiagnosticLevel minLevel) {
    String shallowString;
    assert([=] () {
        StringBuffer result = make<StringBufferCls>();
        result->write(toStringShort());
        result->write(joiner);
        DiagnosticPropertiesBuilder builder = make<DiagnosticPropertiesBuilderCls>();
        debugFillProperties(builder);
        result->write(builder->properties->where([=] (DiagnosticsNode n) {
            !n->isFiltered(minLevel);
        })->join(joiner));
        shallowString = result->toString();
        return true;
    }());
    return shallowString | toString();
}

String DiagnosticableTreeMixinCls::toStringDeep(DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines) {
    return toDiagnosticsNode()->toStringDeep(prefixLineOne, prefixOtherLines, minLevel);
}

String DiagnosticableTreeMixinCls::toStringShort() {
    return describeIdentity(this);
}

DiagnosticsNode DiagnosticableTreeMixinCls::toDiagnosticsNode(String name, DiagnosticsTreeStyle style) {
    return make<DiagnosticableTreeNodeCls>(name, this, style);
}

List<DiagnosticsNode> DiagnosticableTreeMixinCls::debugDescribeChildren() {
    return makeList();
}

void DiagnosticableTreeMixinCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
}

DiagnosticsBlockCls::DiagnosticsBlockCls(bool allowTruncate, List<DiagnosticsNode> children, String description, DiagnosticLevel level, String linePrefix, String name, List<DiagnosticsNode> properties, bool showName, bool showSeparator, DiagnosticsTreeStyle style, Object value) : DiagnosticsNode(showName && name != nullptr) {
    {
        _description = description | __s("");
        _children = children;
        _properties = properties;
    }
}

List<DiagnosticsNode> DiagnosticsBlockCls::getChildren() {
    return _children;
}

List<DiagnosticsNode> DiagnosticsBlockCls::getProperties() {
    return _properties;
}

String DiagnosticsBlockCls::toDescription(TextTreeConfiguration parentConfiguration) {
    return _description;
}

Map<String, Object> _DefaultDiagnosticsSerializationDelegateCls::additionalNodeProperties(DiagnosticsNode node) {
    return makeMap(makeList(), makeList();
}

DiagnosticsSerializationDelegate _DefaultDiagnosticsSerializationDelegateCls::delegateForNode(DiagnosticsNode node) {
    return subtreeDepth > 0? copyWith(subtreeDepth - 1) : this;
}

bool _DefaultDiagnosticsSerializationDelegateCls::expandPropertyValues() {
    return false;
}

List<DiagnosticsNode> _DefaultDiagnosticsSerializationDelegateCls::filterChildren(List<DiagnosticsNode> nodes, DiagnosticsNode owner) {
    return nodes;
}

List<DiagnosticsNode> _DefaultDiagnosticsSerializationDelegateCls::filterProperties(List<DiagnosticsNode> nodes, DiagnosticsNode owner) {
    return nodes;
}

List<DiagnosticsNode> _DefaultDiagnosticsSerializationDelegateCls::truncateNodesList(List<DiagnosticsNode> nodes, DiagnosticsNode owner) {
    return nodes;
}

DiagnosticsSerializationDelegate _DefaultDiagnosticsSerializationDelegateCls::copyWith(bool includeProperties, int subtreeDepth) {
    return make<_DefaultDiagnosticsSerializationDelegateCls>(subtreeDepth | this->subtreeDepth, includeProperties | this->includeProperties);
}
