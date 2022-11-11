#include "text.hpp"
FontWeight FontWeightCls::lerp(FontWeight a, FontWeight b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr)     {
        return nullptr;
    }
    return values[_lerpInt((a | normal)->index, (b | normal)->index, t)->round()->clamp(0, 8)];
}

String FontWeightCls::toString() {
    Map<int, String> map1 = make<MapCls<>>();map1.set(0, __s("FontWeight.w100"));map1.set(1, __s("FontWeight.w200"));map1.set(2, __s("FontWeight.w300"));map1.set(3, __s("FontWeight.w400"));map1.set(4, __s("FontWeight.w500"));map1.set(5, __s("FontWeight.w600"));map1.set(6, __s("FontWeight.w700"));map1.set(7, __s("FontWeight.w800"));map1.set(8, __s("FontWeight.w900"));return list1[index]!;
}

FontFeatureCls::FontFeatureCls(String feature, int value) {
    {
        assert(feature != nullptr);
        assert(feature->length() == 4, __s("Feature tag must be exactly four characters long."));
        assert(value != nullptr);
        assert(value >= 0, __s("Feature value must be zero or a positive integer."));
    }
}

void FontFeatureCls::enable(String feature)

void FontFeatureCls::disable(String feature)

void FontFeatureCls::alternative(int value)

void FontFeatureCls::alternativeFractions()

void FontFeatureCls::contextualAlternates()

void FontFeatureCls::caseSensitiveForms()

void FontFeatureCls::characterVariant(int value) {
    assert(value >= 1);
    assert(value <= 99);
    return make<FontFeatureCls>(__s("cv${value.toString().padLeft(2, "0")}"));
}

void FontFeatureCls::denominator()

void FontFeatureCls::fractions()

void FontFeatureCls::historicalForms()

void FontFeatureCls::historicalLigatures()

void FontFeatureCls::liningFigures()

void FontFeatureCls::localeAware(bool enable)

void FontFeatureCls::notationalForms(int value)

void FontFeatureCls::numerators()

void FontFeatureCls::oldstyleFigures()

void FontFeatureCls::ordinalForms()

void FontFeatureCls::proportionalFigures()

void FontFeatureCls::randomize()

void FontFeatureCls::stylisticAlternates()

void FontFeatureCls::scientificInferiors()

void FontFeatureCls::stylisticSet(int value) {
    assert(value >= 1);
    assert(value <= 20);
    return make<FontFeatureCls>(__s("ss${value.toString().padLeft(2, "0")}"));
}

void FontFeatureCls::subscripts()

void FontFeatureCls::superscripts()

void FontFeatureCls::swash(int value)

void FontFeatureCls::tabularFigures()

void FontFeatureCls::slashedZero()

bool FontFeatureCls::==(Object other) {
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<FontFeature>(other) && other->feature == feature && other->value == value;
}

int FontFeatureCls::hashCode() {
    return ObjectCls->hash(feature, value);
}

String FontFeatureCls::toString() {
    return __s("FontFeature('$feature', $value)");
}

void FontFeatureCls::_encode(ByteData byteData) {
    assert(feature->codeUnits()->every([=] (int c)     {
        c >= 0x20 && c <= 0x7F;
    }));
    for (;  < 4; i++) {
        byteData->setUint8(i, feature->codeUnitAt(i));
    }
    byteData->setInt32(4, value, _kFakeHostEndian);
}

FontVariationCls::FontVariationCls(String axis, double value) {
    {
        assert(axis != nullptr);
        assert(axis->length() == 4, __s("Axis tag must be exactly four characters long."));
        assert(value != nullptr);
    }
}

bool FontVariationCls::==(Object other) {
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<FontVariation>(other) && other->axis == axis && other->value == value;
}

int FontVariationCls::hashCode() {
    return ObjectCls->hash(axis, value);
}

String FontVariationCls::toString() {
    return __s("FontVariation('$axis', $value)");
}

void FontVariationCls::_encode(ByteData byteData) {
    assert(axis->codeUnits()->every([=] (int c)     {
        c >= 0x20 && c <= 0x7F;
    }));
    for (;  < 4; i++) {
        byteData->setUint8(i, axis->codeUnitAt(i));
    }
    byteData->setFloat32(4, value, _kFakeHostEndian);
}

void TextDecorationCls::combine(List<TextDecoration> decorations) {
    int mask = 0;
    for (TextDecoration decoration : decorations)     {
        mask |= decoration->_mask;
    }
    return TextDecorationCls->_(mask);
}

bool TextDecorationCls::contains(TextDecoration other) {
    return (_mask | other->_mask) == _mask;
}

bool TextDecorationCls::==(Object other) {
    return is<TextDecoration>(other) && other->_mask == _mask;
}

int TextDecorationCls::hashCode() {
    return _mask->hashCode;
}

String TextDecorationCls::toString() {
    if (_mask == 0)     {
        return __s("TextDecoration.none");
    }
    List<String> values = makeList();
    if (_mask & underline->_mask != 0)     {
        values->add(__s("underline"));
    }
    if (_mask & overline->_mask != 0)     {
        values->add(__s("overline"));
    }
    if (_mask & lineThrough->_mask != 0)     {
        values->add(__s("lineThrough"));
    }
    if (values->length() == 1)     {
        return __s("TextDecoration.${values[0]}");
    }
    return __s("TextDecoration.combine([${values.join(", ")}])");
}

bool TextHeightBehaviorCls::==(Object other) {
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<TextHeightBehavior>(other) && other->applyHeightToFirstAscent == applyHeightToFirstAscent && other->applyHeightToLastDescent == applyHeightToLastDescent && other->leadingDistribution == leadingDistribution;
}

int TextHeightBehaviorCls::hashCode() {
    return ObjectCls->hash(applyHeightToFirstAscent, applyHeightToLastDescent, leadingDistribution->index);
}

String TextHeightBehaviorCls::toString() {
    return __s("TextHeightBehavior(applyHeightToFirstAscent: $applyHeightToFirstAscent, applyHeightToLastDescent: $applyHeightToLastDescent, leadingDistribution: $leadingDistribution)");
}

void TextHeightBehaviorCls::_fromEncoded(int encoded, TextLeadingDistribution leadingDistribution)

int TextHeightBehaviorCls::_encode() {
    return (applyHeightToFirstAscent? 0 : 1 << 0) | (applyHeightToLastDescent? 0 : 1 << 1);
}

template<typename T>
bool _listEquals(List<T> a, List<T> b) {
    if (a == nullptr)     {
        return b == nullptr;
    }
    if (b == nullptr || a->length() != b->length())     {
        return false;
    }
    for (;  < a->length(); index += 1) {
        if (a[index] != b[index])         {
            return false;
        }
    }
    return true;
}

Int32List _encodeTextStyle(Color color, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, FontWeight fontWeight, FontStyle fontStyle, TextBaseline textBaseline, String fontFamily, List<String> fontFamilyFallback, double fontSize, double letterSpacing, double wordSpacing, double height, Locale locale, Paint background, Paint foreground, List<Shadow> shadows, List<FontFeature> fontFeatures, List<FontVariation> fontVariations) {
    Int32List result = make<Int32ListCls>(9);
    if (color != nullptr) {
        result[0] |= 1 << 1;
        result[1] = color->value;
    }
    if (decoration != nullptr) {
        result[0] |= 1 << 2;
        result[2] = decoration->_mask;
    }
    if (decorationColor != nullptr) {
        result[0] |= 1 << 3;
        result[3] = decorationColor->value;
    }
    if (decorationStyle != nullptr) {
        result[0] |= 1 << 4;
        result[4] = decorationStyle->index;
    }
    if (fontWeight != nullptr) {
        result[0] |= 1 << 5;
        result[5] = fontWeight->index;
    }
    if (fontStyle != nullptr) {
        result[0] |= 1 << 6;
        result[6] = fontStyle->index;
    }
    if (textBaseline != nullptr) {
        result[0] |= 1 << 7;
        result[7] = textBaseline->index;
    }
    if (decorationThickness != nullptr) {
        result[0] |= 1 << 8;
    }
    if (fontFamily != nullptr || (fontFamilyFallback != nullptr && fontFamilyFallback->isNotEmpty)) {
        result[0] |= 1 << 9;
    }
    if (fontSize != nullptr) {
        result[0] |= 1 << 10;
    }
    if (letterSpacing != nullptr) {
        result[0] |= 1 << 11;
    }
    if (wordSpacing != nullptr) {
        result[0] |= 1 << 12;
    }
    if (height != nullptr) {
        result[0] |= 1 << 13;
    }
    if (locale != nullptr) {
        result[0] |= 1 << 14;
    }
    if (background != nullptr) {
        result[0] |= 1 << 15;
    }
    if (foreground != nullptr) {
        result[0] |= 1 << 16;
    }
    if (shadows != nullptr) {
        result[0] |= 1 << 17;
    }
    if (fontFeatures != nullptr) {
        result[0] |= 1 << 18;
    }
    if (fontVariations != nullptr) {
        result[0] |= 1 << 19;
    }
    return result;
}

TextStyleCls::TextStyleCls(Paint background, Color color, TextDecoration decoration, Color decorationColor, TextDecorationStyle decorationStyle, double decorationThickness, String fontFamily, List<String> fontFamilyFallback, List<FontFeature> fontFeatures, double fontSize, FontStyle fontStyle, List<FontVariation> fontVariations, FontWeight fontWeight, Paint foreground, double height, TextLeadingDistribution leadingDistribution, double letterSpacing, Locale locale, List<Shadow> shadows, TextBaseline textBaseline, double wordSpacing) {
    {
        assert(color == nullptr || foreground == nullptr, __s("Cannot provide both a color and a foreground\nThe color argument is just a shorthand for "foreground: Paint()..color = color"."));
        _encoded = _encodeTextStyle(color, decoration, decorationColor, decorationStyle, decorationThickness, fontWeight, fontStyle, textBaseline, fontFamily, fontFamilyFallback, fontSize, letterSpacing, wordSpacing, height, locale, background, foreground, shadows, fontFeatures, fontVariations);
        _leadingDistribution = leadingDistribution;
        _fontFamily = fontFamily | __s("");
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

bool TextStyleCls::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    return is<TextStyle>(other) && other->_leadingDistribution == _leadingDistribution && other->_fontFamily == _fontFamily && other->_fontSize == _fontSize && other->_letterSpacing == _letterSpacing && other->_wordSpacing == _wordSpacing && other->_height == _height && other->_decorationThickness == _decorationThickness && other->_locale == _locale && other->_background == _background && other->_foreground == _foreground && <int>_listEquals(other->_encoded, _encoded) && <Shadow>_listEquals(other->_shadows, _shadows) && <String>_listEquals(other->_fontFamilyFallback, _fontFamilyFallback) && <FontFeature>_listEquals(other->_fontFeatures, _fontFeatures) && <FontVariation>_listEquals(other->_fontVariations, _fontVariations);
}

int TextStyleCls::hashCode() {
    return ObjectCls->hash(ObjectCls->hashAll(_encoded), _leadingDistribution, _fontFamily, _fontFamilyFallback, _fontSize, _letterSpacing, _wordSpacing, _height, _locale, _background, _foreground, _shadows == nullptr? nullptr : ObjectCls->hashAll(_shadows!), _decorationThickness, _fontFeatures == nullptr? nullptr : ObjectCls->hashAll(_fontFeatures!), _fontVariations == nullptr? nullptr : ObjectCls->hashAll(_fontVariations!));
}

String TextStyleCls::toString() {
    return __s("TextStyle(color: ${              _encoded[0] & 0x00002 == 0x00002  ? Color(_encoded[1])                           : "unspecified"}, decoration: ${         _encoded[0] & 0x00004 == 0x00004  ? TextDecoration._(_encoded[2])                : "unspecified"}, decorationColor: ${    _encoded[0] & 0x00008 == 0x00008  ? Color(_encoded[3])                           : "unspecified"}, decorationStyle: ${    _encoded[0] & 0x00010 == 0x00010  ? TextDecorationStyle.values[_encoded[4]]      : "unspecified"}, decorationThickness: ${_encoded[0] & 0x00100 == 0x00100  ? _decorationThickness                         : "unspecified"}, fontWeight: ${         _encoded[0] & 0x00020 == 0x00020  ? FontWeight.values[_encoded[5]]               : "unspecified"}, fontStyle: ${          _encoded[0] & 0x00040 == 0x00040  ? FontStyle.values[_encoded[6]]                : "unspecified"}, textBaseline: ${       _encoded[0] & 0x00080 == 0x00080  ? TextBaseline.values[_encoded[7]]             : "unspecified"}, fontFamily: ${         _encoded[0] & 0x00200 == 0x00200                                     && _fontFamily != ''              ? _fontFamily                                  : "unspecified"}, fontFamilyFallback: ${ _encoded[0] & 0x00200 == 0x00200                                     && _fontFamilyFallback != null                                     && _fontFamilyFallback!.isNotEmpty ? _fontFamilyFallback                         : "unspecified"}, fontSize: ${           _encoded[0] & 0x00400 == 0x00400  ? _fontSize                                    : "unspecified"}, letterSpacing: ${      _encoded[0] & 0x00800 == 0x00800  ? "${_letterSpacing}x"                         : "unspecified"}, wordSpacing: ${        _encoded[0] & 0x01000 == 0x01000  ? "${_wordSpacing}x"                           : "unspecified"}, height: ${             _encoded[0] & 0x02000 == 0x02000  ? "${_height}x"                                : "unspecified"}, leadingDistribution: ${_leadingDistribution ?? "unspecified"}, locale: ${             _encoded[0] & 0x04000 == 0x04000  ? _locale                                      : "unspecified"}, background: ${         _encoded[0] & 0x08000 == 0x08000  ? _background                                  : "unspecified"}, foreground: ${         _encoded[0] & 0x10000 == 0x10000  ? _foreground                                  : "unspecified"}, shadows: ${            _encoded[0] & 0x20000 == 0x20000  ? _shadows                                     : "unspecified"}, fontFeatures: ${       _encoded[0] & 0x40000 == 0x40000  ? _fontFeatures                                : "unspecified"}, fontVariations: ${     _encoded[0] & 0x80000 == 0x80000  ? _fontVariations                              : "unspecified"})");
}

Int32List _encodeParagraphStyle(TextAlign textAlign, TextDirection textDirection, int maxLines, String fontFamily, double fontSize, double height, TextHeightBehavior textHeightBehavior, FontWeight fontWeight, FontStyle fontStyle, StrutStyle strutStyle, String ellipsis, Locale locale) {
    Int32List result = make<Int32ListCls>(7);
    if (textAlign != nullptr) {
        result[0] |= 1 << 1;
        result[1] = textAlign->index;
    }
    if (textDirection != nullptr) {
        result[0] |= 1 << 2;
        result[2] = textDirection->index;
    }
    if (fontWeight != nullptr) {
        result[0] |= 1 << 3;
        result[3] = fontWeight->index;
    }
    if (fontStyle != nullptr) {
        result[0] |= 1 << 4;
        result[4] = fontStyle->index;
    }
    if (maxLines != nullptr) {
        result[0] |= 1 << 5;
        result[5] = maxLines;
    }
    if (textHeightBehavior != nullptr) {
        result[0] |= 1 << 6;
        result[6] = textHeightBehavior->_encode();
    }
    if (fontFamily != nullptr) {
        result[0] |= 1 << 7;
    }
    if (fontSize != nullptr) {
        result[0] |= 1 << 8;
    }
    if (height != nullptr) {
        result[0] |= 1 << 9;
    }
    if (strutStyle != nullptr) {
        result[0] |= 1 << 10;
    }
    if (ellipsis != nullptr) {
        result[0] |= 1 << 11;
    }
    if (locale != nullptr) {
        result[0] |= 1 << 12;
    }
    return result;
}

ParagraphStyleCls::ParagraphStyleCls(String ellipsis, String fontFamily, double fontSize, FontStyle fontStyle, FontWeight fontWeight, double height, Locale locale, int maxLines, StrutStyle strutStyle, TextAlign textAlign, TextDirection textDirection, TextHeightBehavior textHeightBehavior) {
    {
        _encoded = _encodeParagraphStyle(textAlign, textDirection, maxLines, fontFamily, fontSize, height, textHeightBehavior, fontWeight, fontStyle, strutStyle, ellipsis, locale);
        _fontFamily = fontFamily;
        _fontSize = fontSize;
        _height = height;
        _strutStyle = strutStyle;
        _ellipsis = ellipsis;
        _locale = locale;
        _leadingDistribution = textHeightBehavior?->leadingDistribution | TextLeadingDistributionCls::proportional;
    }
}

bool ParagraphStyleCls::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<ParagraphStyle>(other) && other->_fontFamily == _fontFamily && other->_fontSize == _fontSize && other->_height == _height && other->_strutStyle == _strutStyle && other->_ellipsis == _ellipsis && other->_locale == _locale && other->_leadingDistribution == _leadingDistribution && <int>_listEquals(other->_encoded, _encoded);
}

int ParagraphStyleCls::hashCode() {
    return ObjectCls->hash(ObjectCls->hashAll(_encoded), _fontFamily, _fontSize, _height, _ellipsis, _locale, _leadingDistribution);
}

String ParagraphStyleCls::toString() {
    return __s("ParagraphStyle(textAlign: ${     _encoded[0] & 0x002 == 0x002 ? TextAlign.values[_encoded[1]]     : "unspecified"}, textDirection: ${ _encoded[0] & 0x004 == 0x004 ? TextDirection.values[_encoded[2]] : "unspecified"}, fontWeight: ${    _encoded[0] & 0x008 == 0x008 ? FontWeight.values[_encoded[3]]    : "unspecified"}, fontStyle: ${     _encoded[0] & 0x010 == 0x010 ? FontStyle.values[_encoded[4]]     : "unspecified"}, maxLines: ${      _encoded[0] & 0x020 == 0x020 ? _encoded[5]                       : "unspecified"}, textHeightBehavior: ${                                _encoded[0] & 0x040 == 0x040 ?                                          TextHeightBehavior._fromEncoded(_encoded[6], _leadingDistribution).toString() : "unspecified"}, fontFamily: ${    _encoded[0] & 0x080 == 0x080 ? _fontFamily                       : "unspecified"}, fontSize: ${      _encoded[0] & 0x100 == 0x100 ? _fontSize                         : "unspecified"}, height: ${        _encoded[0] & 0x200 == 0x200 ? "${_height}x"                     : "unspecified"}, ellipsis: ${      _encoded[0] & 0x400 == 0x400 ? "\"$_ellipsis\""                  : "unspecified"}, locale: ${        _encoded[0] & 0x800 == 0x800 ? _locale                           : "unspecified"})");
}

ByteData _encodeStrut(String fontFamily, List<String> fontFamilyFallback, double fontSize, double height, TextLeadingDistribution leadingDistribution, double leading, FontWeight fontWeight, FontStyle fontStyle, bool forceStrutHeight) {
    if (fontFamily == nullptr && fontSize == nullptr && height == nullptr && leadingDistribution == nullptr && leading == nullptr && fontWeight == nullptr && fontStyle == nullptr && forceStrutHeight == nullptr)     {
        return make<ByteDataCls>(0);
    }
    ByteData data = make<ByteDataCls>(16);
    int bitmask = 0;
    int byteCount = 1;
    if (fontWeight != nullptr) {
        bitmask |= 1 << 0;
        data->setInt8(byteCount, fontWeight->index);
        byteCount += 1;
    }
    if (fontStyle != nullptr) {
        bitmask |= 1 << 1;
        data->setInt8(byteCount, fontStyle->index);
        byteCount += 1;
    }
    if (fontFamily != nullptr || (fontFamilyFallback != nullptr && fontFamilyFallback->isNotEmpty)) {
        bitmask |= 1 << 2;
    }
    if (fontSize != nullptr) {
        bitmask |= 1 << 4;
        data->setFloat32(byteCount, fontSize, _kFakeHostEndian);
        byteCount += 4;
    }
    if (height != nullptr) {
        bitmask |= 1 << 5;
        data->setFloat32(byteCount, height, _kFakeHostEndian);
        byteCount += 4;
    }
    if (leading != nullptr) {
        bitmask |= 1 << 6;
        data->setFloat32(byteCount, leading, _kFakeHostEndian);
        byteCount += 4;
    }
    if (forceStrutHeight | false) {
        bitmask |= 1 << 7;
    }
    data->setInt8(0, bitmask);
    assert(byteCount <= 16);
    assert(bitmask >> 8 == 0, __s("strut bitmask overflow: $bitmask"));
    return ByteDataCls->view(data->buffer, 0, byteCount);
}

StrutStyleCls::StrutStyleCls(String fontFamily, List<String> fontFamilyFallback, double fontSize, FontStyle fontStyle, FontWeight fontWeight, bool forceStrutHeight, double height, double leading, TextLeadingDistribution leadingDistribution) {
    {
        _encoded = _encodeStrut(fontFamily, fontFamilyFallback, fontSize, height, leadingDistribution, leading, fontWeight, fontStyle, forceStrutHeight);
        _leadingDistribution = leadingDistribution;
        _fontFamily = fontFamily;
        _fontFamilyFallback = fontFamilyFallback;
    }
}

bool StrutStyleCls::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<StrutStyle>(other) && other->_fontFamily == _fontFamily && other->_leadingDistribution == _leadingDistribution && <String>_listEquals(other->_fontFamilyFallback, _fontFamilyFallback) && <int>_listEquals(other->_encoded->buffer->asInt8List(), _encoded->buffer->asInt8List());
}

int StrutStyleCls::hashCode() {
    return ObjectCls->hash(ObjectCls->hashAll(_encoded->buffer->asInt8List()), _fontFamily, _leadingDistribution);
}

bool StrutStyleCls::_enabled() {
    return _encoded->lengthInBytes > 0;
}

Rect TextBoxCls::toRect() {
    return RectCls->fromLTRB(left, top, right, bottom);
}

double TextBoxCls::start() {
    return (direction == TextDirectionCls::ltr)? left : right;
}

double TextBoxCls::end() {
    return (direction == TextDirectionCls::ltr)? right : left;
}

bool TextBoxCls::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<TextBox>(other) && other->left == left && other->top == top && other->right == right && other->bottom == bottom && other->direction == direction;
}

int TextBoxCls::hashCode() {
    return ObjectCls->hash(left, top, right, bottom, direction);
}

String TextBoxCls::toString() {
    return __s("TextBox.fromLTRBD(${left.toStringAsFixed(1)}, ${top.toStringAsFixed(1)}, ${right.toStringAsFixed(1)}, ${bottom.toStringAsFixed(1)}, $direction)");
}

TextPositionCls::TextPositionCls(TextAffinity affinity, int offset) {
    {
        assert(offset != nullptr);
        assert(affinity != nullptr);
    }
}

bool TextPositionCls::==(Object other) {
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<TextPosition>(other) && other->offset == offset && other->affinity == affinity;
}

int TextPositionCls::hashCode() {
    return ObjectCls->hash(offset, affinity);
}

String TextPositionCls::toString() {
    return __s("TextPosition(offset: $offset, affinity: $affinity)");
}

TextRangeCls::TextRangeCls(int end, int start) {
    {
        assert(start != nullptr && start >= -1);
        assert(end != nullptr && end >= -1);
    }
}

void TextRangeCls::collapsed(int offset)

bool TextRangeCls::isValid() {
    return start >= 0 && end >= 0;
}

bool TextRangeCls::isCollapsed() {
    return start == end;
}

bool TextRangeCls::isNormalized() {
    return end >= start;
}

String TextRangeCls::textBefore(String text) {
    assert(isNormalized());
    return text->substring(0, start);
}

String TextRangeCls::textAfter(String text) {
    assert(isNormalized());
    return text->substring(end);
}

String TextRangeCls::textInside(String text) {
    assert(isNormalized());
    return text->substring(start, end);
}

bool TextRangeCls::==(Object other) {
    if (identical(this, other))     {
        return true;
    }
    return is<TextRange>(other) && other->start == start && other->end == end;
}

int TextRangeCls::hashCode() {
    return ObjectCls->hash(start->hashCode, end->hashCode);
}

String TextRangeCls::toString() {
    return __s("TextRange(start: $start, end: $end)");
}

ParagraphConstraintsCls::ParagraphConstraintsCls(double width) {
    {
        assert(width != nullptr);
    }
}

bool ParagraphConstraintsCls::==(Object other) {
    if (other->runtimeType() != runtimeType)     {
        return false;
    }
    return is<ParagraphConstraints>(other) && other->width == width;
}

int ParagraphConstraintsCls::hashCode() {
    return width->hashCode;
}

String ParagraphConstraintsCls::toString() {
    return __s("ParagraphConstraints(width: $width)");
}

bool LineMetricsCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<LineMetrics>(other) && other->hardBreak == hardBreak && other->ascent == ascent && other->descent == descent && other->unscaledAscent == unscaledAscent && other->height == height && other->width == width && other->left == left && other->baseline == baseline && other->lineNumber == lineNumber;
}

int LineMetricsCls::hashCode() {
    return ObjectCls->hash(hardBreak, ascent, descent, unscaledAscent, height, width, left, baseline, lineNumber);
}

String LineMetricsCls::toString() {
    return __s("LineMetrics(hardBreak: $hardBreak, ascent: $ascent, descent: $descent, unscaledAscent: $unscaledAscent, height: $height, width: $width, left: $left, baseline: $baseline, lineNumber: $lineNumber)");
}

void ParagraphCls::layout(ParagraphConstraints constraints) {
    _layout(constraints->width);
    assert([=] () {
        _needsLayout = false;
        return true;
    }());
}

List<TextBox> ParagraphCls::getBoxesForRange(int start, int end, BoxHeightStyle boxHeightStyle, BoxWidthStyle boxWidthStyle) {
    assert(boxHeightStyle != nullptr);
    assert(boxWidthStyle != nullptr);
    return _decodeTextBoxes(_getBoxesForRange(start, end, boxHeightStyle->index, boxWidthStyle->index));
}

List<TextBox> ParagraphCls::getBoxesForPlaceholders() {
    return _decodeTextBoxes(_getBoxesForPlaceholders());
}

TextPosition ParagraphCls::getPositionForOffset(Offset offset) {
    List<int> encoded = _getPositionForOffset(offset->dx(), offset->dy());
    return make<TextPositionCls>(encoded[0], TextAffinityCls::values[encoded[1]]);
}

TextRange ParagraphCls::getWordBoundary(TextPosition position) {
    List<int> boundary = _getWordBoundary(position->offset);
    return make<TextRangeCls>(boundary[0], boundary[1]);
}

TextRange ParagraphCls::getLineBoundary(TextPosition position) {
    List<int> boundary = _getLineBoundary(position->offset);
    TextRange line = make<TextRangeCls>(boundary[0], boundary[1]);
    List<int> nextBoundary = _getLineBoundary(position->offset + 1);
    TextRange nextLine = make<TextRangeCls>(nextBoundary[0], nextBoundary[1]);
    if (!nextLine->isValid()) {
        return line;
    }
    if (position->affinity == TextAffinityCls::downstream && line != nextLine && position->offset == line->end && line->end == nextLine->start) {
        List<int> nextBoundary = _getLineBoundary(position->offset + 1);
        return make<TextRangeCls>(nextBoundary[0], nextBoundary[1]);
    }
    return line;
}

List<LineMetrics> ParagraphCls::computeLineMetrics() {
    Float64List encoded = _computeLineMetrics();
    int count = encoded->length ~/ 9;
    int position = 0;
    List<LineMetrics> list1 = make<ListCls<>>();for (;  < count; index += 1) {    ;}{    list1.add(ArrayItem);}List<LineMetrics> metrics = list1;
    return metrics;
}

List<TextBox> ParagraphCls::_decodeTextBoxes(Float32List encoded) {
    int count = encoded->length ~/ 5;
    List<TextBox> boxes = makeList();
    int position = 0;
    for (;  < count; index += 1) {
        boxes->add(TextBoxCls->fromLTRBD(encoded[position++], encoded[position++], encoded[position++], encoded[position++], TextDirectionCls::values[encoded[position++]->toInt()]));
    }
    return boxes;
}

ParagraphBuilderCls::ParagraphBuilderCls(ParagraphStyle style) {
    {
        _defaultLeadingDistribution = style->_leadingDistribution;
    }
    {
        List<String> strutFontFamilies;
        StrutStyle strutStyle = style->_strutStyle;
        ByteData encodedStrutStyle;
        if (strutStyle != nullptr && strutStyle->_enabled) {
            String fontFamily = strutStyle->_fontFamily;
                    List<String> list1 = make<ListCls<>>();        if (fontFamily != nullptr) {            list1.add(ArrayItem);        }for (auto _x1 : strutStyle->_fontFamilyFallback) {        {            list1.add(_x1);        }strutFontFamilies = list1;
            assert(TextLeadingDistributionCls::values->length <= 2);
            TextLeadingDistribution leadingDistribution = strutStyle->_leadingDistribution | style->_leadingDistribution;
            encodedStrutStyle = strutStyle->_encoded;
            int bitmask = encodedStrutStyle->getInt8(0);
            bitmask |= (leadingDistribution->index) << 3;
            encodedStrutStyle->setInt8(0, bitmask);
        } else {
            encodedStrutStyle = nullptr;
        }
        _constructor(style->_encoded, encodedStrutStyle, style->_fontFamily | __s(""), strutFontFamilies, style->_fontSize | 0, style->_height | 0, style->_ellipsis | __s(""), _encodeLocale(style->_locale));
    }
}

int ParagraphBuilderCls::placeholderCount() {
    return _placeholderCount;
}

List<double> ParagraphBuilderCls::placeholderScales() {
    return _placeholderScales;
}

void ParagraphBuilderCls::pushStyle(TextStyle style) {
    List<String> fullFontFamilies = makeList();
    fullFontFamilies->add(style->_fontFamily());
    if (style->_fontFamilyFallback != nullptr)     {
        fullFontFamilies->addAll(style->_fontFamilyFallback!);
    }
    Int32List encoded = style->_encoded;
    TextLeadingDistribution finalLeadingDistribution = style->_leadingDistribution | _defaultLeadingDistribution;
    assert(TextLeadingDistributionCls::values->length <= 2);
    encoded[0] |= finalLeadingDistribution->index << 0;
    ByteData encodedFontFeatures;
    List<FontFeature> fontFeatures = style->_fontFeatures;
    if (fontFeatures != nullptr) {
        encodedFontFeatures = make<ByteDataCls>(fontFeatures->length() * FontFeatureCls::_kEncodedSize);
        int byteOffset = 0;
        for (FontFeature feature : fontFeatures) {
            feature->_encode(ByteDataCls->view(encodedFontFeatures->buffer, byteOffset, FontFeatureCls::_kEncodedSize));
            byteOffset += FontFeatureCls::_kEncodedSize;
        }
    }
    ByteData encodedFontVariations;
    List<FontVariation> fontVariations = style->_fontVariations;
    if (fontVariations != nullptr) {
        encodedFontVariations = make<ByteDataCls>(fontVariations->length() * FontVariationCls::_kEncodedSize);
        int byteOffset = 0;
        for (FontVariation variation : fontVariations) {
            variation->_encode(ByteDataCls->view(encodedFontVariations->buffer, byteOffset, FontVariationCls::_kEncodedSize));
            byteOffset += FontVariationCls::_kEncodedSize;
        }
    }
    _pushStyle(encoded, fullFontFamilies, style->_fontSize | 0, style->_letterSpacing | 0, style->_wordSpacing | 0, style->_height | 0, style->_decorationThickness | 0, _encodeLocale(style->_locale), style->_background?->_objects, style->_background?->_data, style->_foreground?->_objects, style->_foreground?->_data, ShadowCls->_encodeShadows(style->_shadows), encodedFontFeatures, encodedFontVariations);
}

void ParagraphBuilderCls::addText(String text) {
    String error = _addText(text);
    if (error != nullptr)     {
        throw make<ArgumentErrorCls>(error);
    }
}

void ParagraphBuilderCls::addPlaceholder(double width, double height, PlaceholderAlignment alignment, TextBaseline baseline, double baselineOffset, double scale) {
    assert(!(alignment == PlaceholderAlignmentCls::aboveBaseline || alignment == PlaceholderAlignmentCls::belowBaseline || alignment == PlaceholderAlignmentCls::baseline) || baseline != nullptr);
    baselineOffset = baselineOffset | height;
    _addPlaceholder(width * scale, height * scale, alignment->index, baselineOffset * scale, (baseline | TextBaselineCls::alphabetic)->index);
    _placeholderCount++;
    _placeholderScales->add(scale);
}

Paragraph ParagraphBuilderCls::build() {
    Paragraph paragraph = ParagraphCls->_();
    _build(paragraph);
    return paragraph;
}

String ParagraphBuilderCls::_encodeLocale(Locale locale) {
    return locale?->toString() | __s("");
}

Future<void> loadFontFromList(Uint8List list, String fontFamily) {
    return _futurize([=] (_Callback<void> callback) {
        _loadFontFromList(list, callback, fontFamily | __s(""));
    })->then([=] ()     {
        _sendFontChangeMessage();
    });
}
