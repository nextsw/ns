#include "text.hpp"
FontWeight FontWeight::lerp(FontWeight a, FontWeight b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr)     {
        return nullptr;
    }
    return values[_lerpInt((a ?? normal).index, (b ?? normal).index, t).round().clamp(0, 8)];
}

String FontWeight::toString() {
    return const [index]!;
}

FontFeature::FontFeature(String feature, int value) {
    {
        assert(feature != nullptr);
        assert(feature.length == 4, "Feature tag must be exactly four characters long.");
        assert(value != nullptr);
        assert(value >= 0, "Feature value must be zero or a positive integer.");
    }
}

void FontFeature::enable(String feature)

void FontFeature::disable(String feature)

void FontFeature::alternative(int value)

void FontFeature::alternativeFractions()

void FontFeature::contextualAlternates()

void FontFeature::caseSensitiveForms()

void FontFeature::characterVariant(int value) {
    assert(value >= 1);
    assert(value <= 99);
    return FontFeature("cv${value.toString().padLeft(2, "0")}");
}

void FontFeature::denominator()

void FontFeature::fractions()

void FontFeature::historicalForms()

void FontFeature::historicalLigatures()

void FontFeature::liningFigures()

void FontFeature::localeAware(bool enable)

void FontFeature::notationalForms(int value)

void FontFeature::numerators()

void FontFeature::oldstyleFigures()

void FontFeature::ordinalForms()

void FontFeature::proportionalFigures()

void FontFeature::randomize()

void FontFeature::stylisticAlternates()

void FontFeature::scientificInferiors()

void FontFeature::stylisticSet(int value) {
    assert(value >= 1);
    assert(value <= 20);
    return FontFeature("ss${value.toString().padLeft(2, "0")}");
}

void FontFeature::subscripts()

void FontFeature::superscripts()

void FontFeature::swash(int value)

void FontFeature::tabularFigures()

void FontFeature::slashedZero()

bool FontFeature::==(Object other) {
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is FontFeature && other.feature == feature && other.value == value;
}

int FontFeature::hashCode() {
    return Object.hash(feature, value);
}

String FontFeature::toString() {
    return "FontFeature('$feature', $value)";
}

void FontFeature::_encode(ByteData byteData) {
    assert(feature.codeUnits.every());
    for (;  < 4; i++) {
        byteData.setUint8(i, feature.codeUnitAt(i));
    }
    byteData.setInt32(4, value, _kFakeHostEndian);
}

FontVariation::FontVariation(String axis, double value) {
    {
        assert(axis != nullptr);
        assert(axis.length == 4, "Axis tag must be exactly four characters long.");
        assert(value != nullptr);
    }
}

bool FontVariation::==(Object other) {
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is FontVariation && other.axis == axis && other.value == value;
}

int FontVariation::hashCode() {
    return Object.hash(axis, value);
}

String FontVariation::toString() {
    return "FontVariation('$axis', $value)";
}

void FontVariation::_encode(ByteData byteData) {
    assert(axis.codeUnits.every());
    for (;  < 4; i++) {
        byteData.setUint8(i, axis.codeUnitAt(i));
    }
    byteData.setFloat32(4, value, _kFakeHostEndian);
}

void TextDecoration::combine(List<TextDecoration> decorations) {
    int mask = 0;
    for (TextDecoration decoration : decorations)     {
        mask = decoration._mask;
    }
    return TextDecoration._(mask);
}

bool TextDecoration::contains(TextDecoration other) {
    return (_mask | other._mask) == _mask;
}

bool TextDecoration::==(Object other) {
    return other is TextDecoration && other._mask == _mask;
}

int TextDecoration::hashCode() {
    return _mask.hashCode;
}

String TextDecoration::toString() {
    if (_mask == 0)     {
        return "TextDecoration.none";
    }
    List<String> values = ;
    if (_mask & underline._mask != 0)     {
        values.add("underline");
    }
    if (_mask & overline._mask != 0)     {
        values.add("overline");
    }
    if (_mask & lineThrough._mask != 0)     {
        values.add("lineThrough");
    }
    if (values.length == 1)     {
        return "TextDecoration.${values[0]}";
    }
    return "TextDecoration.combine([${values.join(", ")}])";
}

bool TextHeightBehavior::==(Object other) {
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is TextHeightBehavior && other.applyHeightToFirstAscent == applyHeightToFirstAscent && other.applyHeightToLastDescent == applyHeightToLastDescent && other.leadingDistribution == leadingDistribution;
}

int TextHeightBehavior::hashCode() {
    return Object.hash(applyHeightToFirstAscent, applyHeightToLastDescent, leadingDistribution.index);
}

String TextHeightBehavior::toString() {
    return "TextHeightBehavior(applyHeightToFirstAscent: $applyHeightToFirstAscent, applyHeightToLastDescent: $applyHeightToLastDescent, leadingDistribution: $leadingDistribution)";
}

void TextHeightBehavior::_fromEncoded(int encoded, TextLeadingDistribution leadingDistribution)

int TextHeightBehavior::_encode() {
    return (applyHeightToFirstAscent? 0 : 1 << 0) | (applyHeightToLastDescent? 0 : 1 << 1);
}

bool _listEquals<T>(List<T> a, List<T> b) {
    if (a == nullptr)     {
        return b == nullptr;
    }
    if (b == nullptr || a.length != b.length)     {
        return false;
    }
    for (;  < a.length; index = 1) {
        if (a[index] != b[index])         {
            return false;
        }
    }
    return true;
}

Int32List _encodeTextStyle(Paint background, Color color, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, double letterSpacing, Locale locale, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing) {
    Int32List result = Int32List(9);
    if (color != nullptr) {
        result[0] = 1 << 1;
        result[1] = color.value;
    }
    if (decoration != nullptr) {
        result[0] = 1 << 2;
        result[2] = decoration._mask;
    }
    if (decorationColor != nullptr) {
        result[0] = 1 << 3;
        result[3] = decorationColor.value;
    }
    if (decorationStyle != nullptr) {
        result[0] = 1 << 4;
        result[4] = decorationStyle.index;
    }
    if (fontWeight != nullptr) {
        result[0] = 1 << 5;
        result[5] = fontWeight.index;
    }
    if (fontStyle != nullptr) {
        result[0] = 1 << 6;
        result[6] = fontStyle.index;
    }
    if (textBaseline != nullptr) {
        result[0] = 1 << 7;
        result[7] = textBaseline.index;
    }
    if (decorationThickness != nullptr) {
        result[0] = 1 << 8;
    }
    if (fontFamily != nullptr || (fontFamilyFallback != nullptr && fontFamilyFallback.isNotEmpty)) {
        result[0] = 1 << 9;
    }
    if (fontSize != nullptr) {
        result[0] = 1 << 10;
    }
    if (letterSpacing != nullptr) {
        result[0] = 1 << 11;
    }
    if (wordSpacing != nullptr) {
        result[0] = 1 << 12;
    }
    if (height != nullptr) {
        result[0] = 1 << 13;
    }
    if (locale != nullptr) {
        result[0] = 1 << 14;
    }
    if (background != nullptr) {
        result[0] = 1 << 15;
    }
    if (foreground != nullptr) {
        result[0] = 1 << 16;
    }
    if (shadows != nullptr) {
        result[0] = 1 << 17;
    }
    if (fontFeatures != nullptr) {
        result[0] = 1 << 18;
    }
    if (fontVariations != nullptr) {
        result[0] = 1 << 19;
    }
    return result;
}

TextStyle::TextStyle(Paint background, Color color, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, TextLeadingDistribution leadingDistribution, double letterSpacing, Locale locale, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing) {
    {
        assert(color == nullptr || foreground == nullptr, "Cannot provide both a color and a foreground\nThe color argument is just a shorthand for "foreground: Paint()..color = color".");
        _encoded = _encodeTextStyle(color, decoration, decorationColor, decorationStyle, decorationThickness, fontWeight, fontStyle, textBaseline, fontFamily, fontFamilyFallback, fontSize, letterSpacing, wordSpacing, height, locale, background, foreground, shadows, fontFeatures, fontVariations);
        _leadingDistribution = leadingDistribution;
        _fontFamily = fontFamily ?? "";
        _fontFamilyFallback = fontFamilyFallback;
        _fontSize = fontSize;
        _letterSpacing = letterSpacing;
        _wordSpacing = wordSpacing;
        _height = height;
        _decorationThickness = decorationThickness;
        _locale = locale;
        _background = background;
        _foreground = foreground;
        _shadows = shadows;
        _fontFeatures = fontFeatures;
        _fontVariations = fontVariations;
    }
}

bool TextStyle::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    return other is TextStyle && other._leadingDistribution == _leadingDistribution && other._fontFamily == _fontFamily && other._fontSize == _fontSize && other._letterSpacing == _letterSpacing && other._wordSpacing == _wordSpacing && other._height == _height && other._decorationThickness == _decorationThickness && other._locale == _locale && other._background == _background && other._foreground == _foreground && <int>_listEquals(other._encoded, _encoded) && <Shadow>_listEquals(other._shadows, _shadows) && <String>_listEquals(other._fontFamilyFallback, _fontFamilyFallback) && <FontFeature>_listEquals(other._fontFeatures, _fontFeatures) && <FontVariation>_listEquals(other._fontVariations, _fontVariations);
}

int TextStyle::hashCode() {
    return Object.hash(Object.hashAll(_encoded), _leadingDistribution, _fontFamily, _fontFamilyFallback, _fontSize, _letterSpacing, _wordSpacing, _height, _locale, _background, _foreground, _shadows == nullptr? nullptr : Object.hashAll(_shadows!), _decorationThickness, _fontFeatures == nullptr? nullptr : Object.hashAll(_fontFeatures!), _fontVariations == nullptr? nullptr : Object.hashAll(_fontVariations!));
}

String TextStyle::toString() {
    return "TextStyle(color: ${              _encoded[0] & 0x00002 == 0x00002  ? Color(_encoded[1])                           : "unspecified"}, decoration: ${         _encoded[0] & 0x00004 == 0x00004  ? TextDecoration._(_encoded[2])                : "unspecified"}, decorationColor: ${    _encoded[0] & 0x00008 == 0x00008  ? Color(_encoded[3])                           : "unspecified"}, decorationStyle: ${    _encoded[0] & 0x00010 == 0x00010  ? TextDecorationStyle.values[_encoded[4]]      : "unspecified"}, decorationThickness: ${_encoded[0] & 0x00100 == 0x00100  ? _decorationThickness                         : "unspecified"}, fontWeight: ${         _encoded[0] & 0x00020 == 0x00020  ? FontWeight.values[_encoded[5]]               : "unspecified"}, fontStyle: ${          _encoded[0] & 0x00040 == 0x00040  ? FontStyle.values[_encoded[6]]                : "unspecified"}, textBaseline: ${       _encoded[0] & 0x00080 == 0x00080  ? TextBaseline.values[_encoded[7]]             : "unspecified"}, fontFamily: ${         _encoded[0] & 0x00200 == 0x00200                                     && _fontFamily != ''              ? _fontFamily                                  : "unspecified"}, fontFamilyFallback: ${ _encoded[0] & 0x00200 == 0x00200                                     && _fontFamilyFallback != null                                     && _fontFamilyFallback!.isNotEmpty ? _fontFamilyFallback                         : "unspecified"}, fontSize: ${           _encoded[0] & 0x00400 == 0x00400  ? _fontSize                                    : "unspecified"}, letterSpacing: ${      _encoded[0] & 0x00800 == 0x00800  ? "${_letterSpacing}x"                         : "unspecified"}, wordSpacing: ${        _encoded[0] & 0x01000 == 0x01000  ? "${_wordSpacing}x"                           : "unspecified"}, height: ${             _encoded[0] & 0x02000 == 0x02000  ? "${_height}x"                                : "unspecified"}, leadingDistribution: ${_leadingDistribution ?? "unspecified"}, locale: ${             _encoded[0] & 0x04000 == 0x04000  ? _locale                                      : "unspecified"}, background: ${         _encoded[0] & 0x08000 == 0x08000  ? _background                                  : "unspecified"}, foreground: ${         _encoded[0] & 0x10000 == 0x10000  ? _foreground                                  : "unspecified"}, shadows: ${            _encoded[0] & 0x20000 == 0x20000  ? _shadows                                     : "unspecified"}, fontFeatures: ${       _encoded[0] & 0x40000 == 0x40000  ? _fontFeatures                                : "unspecified"}, fontVariations: ${     _encoded[0] & 0x80000 == 0x80000  ? _fontVariations                              : "unspecified"})";
}

Int32List _encodeParagraphStyle(String ellipsis, String fontFamily, double fontSize, FontStyle fontStyle, FontWeight fontWeight, double height, Locale locale, int maxLines, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior) {
    Int32List result = Int32List(7);
    if (textAlign != nullptr) {
        result[0] = 1 << 1;
        result[1] = textAlign.index;
    }
    if (textDirection != nullptr) {
        result[0] = 1 << 2;
        result[2] = textDirection.index;
    }
    if (fontWeight != nullptr) {
        result[0] = 1 << 3;
        result[3] = fontWeight.index;
    }
    if (fontStyle != nullptr) {
        result[0] = 1 << 4;
        result[4] = fontStyle.index;
    }
    if (maxLines != nullptr) {
        result[0] = 1 << 5;
        result[5] = maxLines;
    }
    if (textHeightBehavior != nullptr) {
        result[0] = 1 << 6;
        result[6] = textHeightBehavior._encode();
    }
    if (fontFamily != nullptr) {
        result[0] = 1 << 7;
    }
    if (fontSize != nullptr) {
        result[0] = 1 << 8;
    }
    if (height != nullptr) {
        result[0] = 1 << 9;
    }
    if (strutStyle != nullptr) {
        result[0] = 1 << 10;
    }
    if (ellipsis != nullptr) {
        result[0] = 1 << 11;
    }
    if (locale != nullptr) {
        result[0] = 1 << 12;
    }
    return result;
}

ParagraphStyle::ParagraphStyle(String ellipsis, String fontFamily, double fontSize, FontStyle fontStyle, FontWeight fontWeight, double height, Locale locale, int maxLines, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior) {
    {
        _encoded = _encodeParagraphStyle(textAlign, textDirection, maxLines, fontFamily, fontSize, height, textHeightBehavior, fontWeight, fontStyle, strutStyle, ellipsis, locale);
        _fontFamily = fontFamily;
        _fontSize = fontSize;
        _height = height;
        _strutStyle = strutStyle;
        _ellipsis = ellipsis;
        _locale = locale;
        _leadingDistribution = textHeightBehavior?.leadingDistribution ?? TextLeadingDistribution.proportional;
    }
}

bool ParagraphStyle::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is ParagraphStyle && other._fontFamily == _fontFamily && other._fontSize == _fontSize && other._height == _height && other._strutStyle == _strutStyle && other._ellipsis == _ellipsis && other._locale == _locale && other._leadingDistribution == _leadingDistribution && <int>_listEquals(other._encoded, _encoded);
}

int ParagraphStyle::hashCode() {
    return Object.hash(Object.hashAll(_encoded), _fontFamily, _fontSize, _height, _ellipsis, _locale, _leadingDistribution);
}

String ParagraphStyle::toString() {
    return "ParagraphStyle(textAlign: ${     _encoded[0] & 0x002 == 0x002 ? TextAlign.values[_encoded[1]]     : "unspecified"}, textDirection: ${ _encoded[0] & 0x004 == 0x004 ? TextDirection.values[_encoded[2]] : "unspecified"}, fontWeight: ${    _encoded[0] & 0x008 == 0x008 ? FontWeight.values[_encoded[3]]    : "unspecified"}, fontStyle: ${     _encoded[0] & 0x010 == 0x010 ? FontStyle.values[_encoded[4]]     : "unspecified"}, maxLines: ${      _encoded[0] & 0x020 == 0x020 ? _encoded[5]                       : "unspecified"}, textHeightBehavior: ${                                _encoded[0] & 0x040 == 0x040 ?                                          TextHeightBehavior._fromEncoded(_encoded[6], _leadingDistribution).toString() : "unspecified"}, fontFamily: ${    _encoded[0] & 0x080 == 0x080 ? _fontFamily                       : "unspecified"}, fontSize: ${      _encoded[0] & 0x100 == 0x100 ? _fontSize                         : "unspecified"}, height: ${        _encoded[0] & 0x200 == 0x200 ? "${_height}x"                     : "unspecified"}, ellipsis: ${      _encoded[0] & 0x400 == 0x400 ? "\"$_ellipsis\""                  : "unspecified"}, locale: ${        _encoded[0] & 0x800 == 0x800 ? _locale                           : "unspecified"})";
}

ByteData _encodeStrut(String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution) {
    if (fontFamily == nullptr && fontSize == nullptr && height == nullptr && leadingDistribution == nullptr && leading == nullptr && fontWeight == nullptr && fontStyle == nullptr && forceStrutHeight == nullptr)     {
        return ByteData(0);
    }
    ByteData data = ByteData(16);
    int bitmask = 0;
    int byteCount = 1;
    if (fontWeight != nullptr) {
        bitmask = 1 << 0;
        data.setInt8(byteCount, fontWeight.index);
        byteCount = 1;
    }
    if (fontStyle != nullptr) {
        bitmask = 1 << 1;
        data.setInt8(byteCount, fontStyle.index);
        byteCount = 1;
    }
    if (fontFamily != nullptr || (fontFamilyFallback != nullptr && fontFamilyFallback.isNotEmpty)) {
        bitmask = 1 << 2;
    }
    if (fontSize != nullptr) {
        bitmask = 1 << 4;
        data.setFloat32(byteCount, fontSize, _kFakeHostEndian);
        byteCount = 4;
    }
    if (height != nullptr) {
        bitmask = 1 << 5;
        data.setFloat32(byteCount, height, _kFakeHostEndian);
        byteCount = 4;
    }
    if (leading != nullptr) {
        bitmask = 1 << 6;
        data.setFloat32(byteCount, leading, _kFakeHostEndian);
        byteCount = 4;
    }
    if (forceStrutHeight ?? false) {
        bitmask = 1 << 7;
    }
    data.setInt8(0, bitmask);
    assert(byteCount <= 16);
    assert(bitmask >> 8 == 0, "strut bitmask overflow: $bitmask");
    return ByteData.view(data.buffer, 0, byteCount);
}

StrutStyle::StrutStyle(String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution) {
    {
        _encoded = _encodeStrut(fontFamily, fontFamilyFallback, fontSize, height, leadingDistribution, leading, fontWeight, fontStyle, forceStrutHeight);
        _leadingDistribution = leadingDistribution;
        _fontFamily = fontFamily;
        _fontFamilyFallback = fontFamilyFallback;
    }
}

bool StrutStyle::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is StrutStyle && other._fontFamily == _fontFamily && other._leadingDistribution == _leadingDistribution && <String>_listEquals(other._fontFamilyFallback, _fontFamilyFallback) && <int>_listEquals(other._encoded.buffer.asInt8List(), _encoded.buffer.asInt8List());
}

int StrutStyle::hashCode() {
    return Object.hash(Object.hashAll(_encoded.buffer.asInt8List()), _fontFamily, _leadingDistribution);
}

bool StrutStyle::_enabled() {
    return _encoded.lengthInBytes > 0;
}

Rect TextBox::toRect() {
    return Rect.fromLTRB(left, top, right, bottom);
}

double TextBox::start() {
    return (direction == TextDirection.ltr)? left : right;
}

double TextBox::end() {
    return (direction == TextDirection.ltr)? right : left;
}

bool TextBox::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is TextBox && other.left == left && other.top == top && other.right == right && other.bottom == bottom && other.direction == direction;
}

int TextBox::hashCode() {
    return Object.hash(left, top, right, bottom, direction);
}

String TextBox::toString() {
    return "TextBox.fromLTRBD(${left.toStringAsFixed(1)}, ${top.toStringAsFixed(1)}, ${right.toStringAsFixed(1)}, ${bottom.toStringAsFixed(1)}, $direction)";
}

TextPosition::TextPosition(TextAffinity affinity, int offset) {
    {
        assert(offset != nullptr);
        assert(affinity != nullptr);
    }
}

bool TextPosition::==(Object other) {
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is TextPosition && other.offset == offset && other.affinity == affinity;
}

int TextPosition::hashCode() {
    return Object.hash(offset, affinity);
}

String TextPosition::toString() {
    return "TextPosition(offset: $offset, affinity: $affinity)";
}

TextRange::TextRange(int end, int start) {
    {
        assert(start != nullptr && start >= -1);
        assert(end != nullptr && end >= -1);
    }
}

void TextRange::collapsed(int offset)

bool TextRange::isValid() {
    return start >= 0 && end >= 0;
}

bool TextRange::isCollapsed() {
    return start == end;
}

bool TextRange::isNormalized() {
    return end >= start;
}

String TextRange::textBefore(String text) {
    assert(isNormalized);
    return text.substring(0, start);
}

String TextRange::textAfter(String text) {
    assert(isNormalized);
    return text.substring(end);
}

String TextRange::textInside(String text) {
    assert(isNormalized);
    return text.substring(start, end);
}

bool TextRange::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    return other is TextRange && other.start == start && other.end == end;
}

int TextRange::hashCode() {
    return Object.hash(start.hashCode, end.hashCode);
}

String TextRange::toString() {
    return "TextRange(start: $start, end: $end)";
}

ParagraphConstraints::ParagraphConstraints(double width) {
    {
        assert(width != nullptr);
    }
}

bool ParagraphConstraints::==(Object other) {
    if (other.runtimeType != runtimeType)     {
        return false;
    }
    return other is ParagraphConstraints && other.width == width;
}

int ParagraphConstraints::hashCode() {
    return width.hashCode;
}

String ParagraphConstraints::toString() {
    return "ParagraphConstraints(width: $width)";
}

bool LineMetrics::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is LineMetrics && other.hardBreak == hardBreak && other.ascent == ascent && other.descent == descent && other.unscaledAscent == unscaledAscent && other.height == height && other.width == width && other.left == left && other.baseline == baseline && other.lineNumber == lineNumber;
}

int LineMetrics::hashCode() {
    return Object.hash(hardBreak, ascent, descent, unscaledAscent, height, width, left, baseline, lineNumber);
}

String LineMetrics::toString() {
    return "LineMetrics(hardBreak: $hardBreak, ascent: $ascent, descent: $descent, unscaledAscent: $unscaledAscent, height: $height, width: $width, left: $left, baseline: $baseline, lineNumber: $lineNumber)";
}

void Paragraph::layout(ParagraphConstraints constraints) {
    _layout(constraints.width);
    assert(());
}

List<TextBox> Paragraph::getBoxesForRange(BoxHeightStyle boxHeightStyle, BoxWidthStyle boxWidthStyle, int end, int start) {
    assert(boxHeightStyle != nullptr);
    assert(boxWidthStyle != nullptr);
    return _decodeTextBoxes(_getBoxesForRange(start, end, boxHeightStyle.index, boxWidthStyle.index));
}

List<TextBox> Paragraph::getBoxesForPlaceholders() {
    return _decodeTextBoxes(_getBoxesForPlaceholders());
}

TextPosition Paragraph::getPositionForOffset(Offset offset) {
    List<int> encoded = _getPositionForOffset(offset.dx, offset.dy);
    return TextPosition(encoded[0], TextAffinity.values[encoded[1]]);
}

TextRange Paragraph::getWordBoundary(TextPosition position) {
    List<int> boundary = _getWordBoundary(position.offset);
    return TextRange(boundary[0], boundary[1]);
}

TextRange Paragraph::getLineBoundary(TextPosition position) {
    List<int> boundary = _getLineBoundary(position.offset);
    TextRange line = TextRange(boundary[0], boundary[1]);
    List<int> nextBoundary = _getLineBoundary(position.offset + 1);
    TextRange nextLine = TextRange(nextBoundary[0], nextBoundary[1]);
    if (!nextLine.isValid) {
        return line;
    }
    if (position.affinity == TextAffinity.downstream && line != nextLine && position.offset == line.end && line.end == nextLine.start) {
        List<int> nextBoundary = _getLineBoundary(position.offset + 1);
        return TextRange(nextBoundary[0], nextBoundary[1]);
    }
    return line;
}

List<LineMetrics> Paragraph::computeLineMetrics() {
    Float64List encoded = _computeLineMetrics();
    int count = encoded.length ~/ 9;
    int position = 0;
    List<LineMetrics> metrics = ;
    return metrics;
}

List<TextBox> Paragraph::_decodeTextBoxes(Float32List encoded) {
    int count = encoded.length ~/ 5;
    List<TextBox> boxes = ;
    int position = 0;
    for (;  < count; index = 1) {
        boxes.add(TextBox.fromLTRBD(encoded[position++], encoded[position++], encoded[position++], encoded[position++], TextDirection.values[encoded[position++].toInt()]));
    }
    return boxes;
}

ParagraphBuilder::ParagraphBuilder(ParagraphStyle style) {
    {
        _defaultLeadingDistribution = style._leadingDistribution;
    }
    {
        List<String> strutFontFamilies;
        StrutStyle strutStyle = style._strutStyle;
        ByteData encodedStrutStyle;
        if (strutStyle != nullptr && strutStyle._enabled) {
            String fontFamily = strutStyle._fontFamily;
            strutFontFamilies = ;
            assert(TextLeadingDistribution.values.length <= 2);
            TextLeadingDistribution leadingDistribution = strutStyle._leadingDistribution ?? style._leadingDistribution;
            encodedStrutStyle = strutStyle._encoded;
            int bitmask = encodedStrutStyle.getInt8(0);
            bitmask = (leadingDistribution.index) << 3;
            encodedStrutStyle.setInt8(0, bitmask);
        } else {
            encodedStrutStyle = nullptr;
        }
        _constructor(style._encoded, encodedStrutStyle, style._fontFamily ?? "", strutFontFamilies, style._fontSize ?? 0, style._height ?? 0, style._ellipsis ?? "", _encodeLocale(style._locale));
    }
}

int ParagraphBuilder::placeholderCount() {
    return _placeholderCount;
}

List<double> ParagraphBuilder::placeholderScales() {
    return _placeholderScales;
}

void ParagraphBuilder::pushStyle(TextStyle style) {
    List<String> fullFontFamilies = ;
    fullFontFamilies.add(style._fontFamily);
    if (style._fontFamilyFallback != nullptr)     {
        fullFontFamilies.addAll(style._fontFamilyFallback!);
    }
    Int32List encoded = style._encoded;
    TextLeadingDistribution finalLeadingDistribution = style._leadingDistribution ?? _defaultLeadingDistribution;
    assert(TextLeadingDistribution.values.length <= 2);
    encoded[0] = finalLeadingDistribution.index << 0;
    ByteData encodedFontFeatures;
    List<FontFeature> fontFeatures = style._fontFeatures;
    if (fontFeatures != nullptr) {
        encodedFontFeatures = ByteData(fontFeatures.length * FontFeature._kEncodedSize);
        int byteOffset = 0;
        for (FontFeature feature : fontFeatures) {
            feature._encode(ByteData.view(encodedFontFeatures.buffer, byteOffset, FontFeature._kEncodedSize));
            byteOffset = FontFeature._kEncodedSize;
        }
    }
    ByteData encodedFontVariations;
    List<FontVariation> fontVariations = style._fontVariations;
    if (fontVariations != nullptr) {
        encodedFontVariations = ByteData(fontVariations.length * FontVariation._kEncodedSize);
        int byteOffset = 0;
        for (FontVariation variation : fontVariations) {
            variation._encode(ByteData.view(encodedFontVariations.buffer, byteOffset, FontVariation._kEncodedSize));
            byteOffset = FontVariation._kEncodedSize;
        }
    }
    _pushStyle(encoded, fullFontFamilies, style._fontSize ?? 0, style._letterSpacing ?? 0, style._wordSpacing ?? 0, style._height ?? 0, style._decorationThickness ?? 0, _encodeLocale(style._locale), style._background?._objects, style._background?._data, style._foreground?._objects, style._foreground?._data, Shadow._encodeShadows(style._shadows), encodedFontFeatures, encodedFontVariations);
}

void ParagraphBuilder::addText(String text) {
    String error = _addText(text);
    if (error != nullptr)     {
        ;
    }
}

void ParagraphBuilder::addPlaceholder(PlaceholderAlignment alignment, TextBaseline baseline, double baselineOffset, double height, double scale, double width) {
    assert(!(alignment == PlaceholderAlignment.aboveBaseline || alignment == PlaceholderAlignment.belowBaseline || alignment == PlaceholderAlignment.baseline) || baseline != nullptr);
    baselineOffset = baselineOffset ?? height;
    _addPlaceholder(width * scale, height * scale, alignment.index, baselineOffset * scale, (baseline ?? TextBaseline.alphabetic).index);
    _placeholderCount++;
    _placeholderScales.add(scale);
}

Paragraph ParagraphBuilder::build() {
    Paragraph paragraph = Paragraph._();
    _build(paragraph);
    return paragraph;
}

String ParagraphBuilder::_encodeLocale(Locale locale) {
    return locale?.toString() ?? "";
}

Future<void> loadFontFromList(String fontFamily, Uint8List list) {
    return _futurize().then();
}
