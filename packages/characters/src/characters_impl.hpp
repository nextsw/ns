#ifndef PACKAGES_CHARACTERS_SRC_CHARACTERS_IMPL
#define PACKAGES_CHARACTERS_SRC_CHARACTERS_IMPL
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/characters/characters.hpp>
#include "characters.hpp"
#include "grapheme_clusters/constants.hpp"
#include "grapheme_clusters/breaks.hpp"


class StringCharactersCls : public IterableCls<String> {
public:
    String string;


     StringCharactersCls(String string);
    virtual CharacterRange iterator();

    virtual CharacterRange iteratorAtEnd();

    virtual String first();

    virtual String last();

    virtual String single();

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual int length();

    template<typename T>
 virtual Iterable<T> whereType();

    virtual String join(String separator);

    virtual String lastWhere(std::function<bool(String element)> test, std::function<String()> orElse);

    virtual String elementAt(int index);

    virtual bool contains(Object singleCharacterString);

    virtual bool startsWith(Characters characters);

    virtual bool endsWith(Characters characters);

    virtual Characters replaceAll(Characters pattern, Characters replacement);

    virtual Characters replaceFirst(Characters pattern, Characters replacement);

    virtual Iterable<Characters> split(Characters pattern, int maxParts);

    virtual bool containsAll(Characters characters);

    virtual Characters skip(int count);

    virtual Characters take(int count);

    virtual Characters getRange(int start, int end);

    virtual Characters characterAt(int position);

    virtual Characters skipWhile(std::function<bool(String )> test);

    virtual Characters takeWhile(std::function<bool(String )> test);

    virtual Characters where(std::function<bool(String )> test);

    virtual Characters operator+(Characters characters);

    virtual Characters skipLast(int count);

    virtual Characters skipLastWhile(std::function<bool(String )> test);

    virtual Characters takeLast(int count);

    virtual Characters takeLastWhile(std::function<bool(String )> test);

    virtual Characters toLowerCase();

    virtual Characters toUpperCase();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

    virtual CharacterRange findFirst(Characters characters);

    virtual CharacterRange findLast(Characters characters);

private:

    virtual StringCharacterRange _rangeAll();

    virtual int _skipIndices(int count, int cursor, Breaks breaks);

    virtual Characters _skip(int count);

    virtual Characters _take(int count);

};
using StringCharacters = std::shared_ptr<StringCharactersCls>;

class StringCharacterRangeCls : public ObjectCls {
public:

     StringCharacterRangeCls(String stringValue);

    virtual void  at(String stringValue, int startIndex, int endIndex);

    virtual String current();

    virtual bool moveNext(int count);

    virtual bool moveBack(int count);

    virtual Iterable<int> utf16CodeUnits();

    virtual Runes runes();

    virtual CharacterRange copy();

    virtual void collapseToEnd();

    virtual void collapseToStart();

    virtual bool dropFirst(int count);

    virtual bool dropTo(Characters target);

    virtual bool dropUntil(Characters target);

    virtual void dropWhile(std::function<bool(String )> test);

    virtual bool dropLast(int count);

    virtual bool dropBackTo(Characters target);

    virtual bool dropBackUntil(Characters target);

    virtual void dropBackWhile(std::function<bool(String )> test);

    virtual bool expandNext(int count);

    virtual bool expandTo(Characters target);

    virtual void expandWhile(std::function<bool(String character)> test);

    virtual void expandAll();

    virtual bool expandBack(int count);

    virtual bool expandBackTo(Characters target);

    virtual void expandBackWhile(std::function<bool(String character)> test);

    virtual bool expandBackUntil(Characters target);

    virtual void expandBackAll();

    virtual bool expandUntil(Characters target);

    virtual bool isEmpty();

    virtual bool isNotEmpty();

    virtual bool moveBackUntil(Characters target);

    virtual bool collapseToFirst(Characters target);

    virtual bool collapseToLast(Characters target);

    virtual bool moveUntil(Characters target);

    virtual CharacterRange replaceFirst(Characters pattern, Characters replacement);

    virtual CharacterRange replaceAll(Characters pattern, Characters replacement);

    virtual CharacterRange replaceRange(Characters replacement);

    virtual Characters source();

    virtual bool startsWith(Characters characters);

    virtual bool endsWith(Characters characters);

    virtual bool isFollowedBy(Characters characters);

    virtual bool isPrecededBy(Characters characters);

    virtual bool moveBackTo(Characters target);

    virtual bool moveTo(Characters target);

    virtual Characters charactersAfter();

    virtual Characters charactersBefore();

    virtual Characters currentCharacters();

    virtual void moveBackAll();

    virtual void moveNextAll();

    virtual String stringAfter();

    virtual int stringAfterLength();

    virtual String stringBefore();

    virtual int stringBeforeLength();

    virtual Iterable<CharacterRange> split(Characters pattern, int maxParts);

private:
    String _string;

    int _start;

    int _end;

    String _currentCache;


    virtual void  _(String _string, int _start, int _end);
    virtual void _move(int start, int end);

    virtual Breaks _breaksFromEnd();

    virtual BackBreaks _backBreaksFromStart();

    virtual bool _advanceEnd(int count, int newStart);

    virtual bool _moveNextPattern(String patternString, int start, int end);

    virtual bool _retractStart(int count, int newEnd);

    virtual bool _movePreviousPattern(String patternString, int start, int end);

    virtual bool _retractStartUntil(String targetString, int newEnd);

    virtual bool _advanceEndUntil(String targetString, int newStart);

    static StringCharacterRange _expandRange(String stringValue, int start, int end);

    virtual bool _endsWith(int start, int end, String stringValue);

    virtual bool _startsWith(int start, int end, String stringValue);

};
using StringCharacterRange = std::shared_ptr<StringCharacterRangeCls>;
String _explodeReplace(String stringValue, int start, int end, String internalReplacement, String outerReplacement);

int _indexOf(String source, String pattern, int start, int end);

int _gcIndexOf(String source, String pattern, int start, int end);

int _lastIndexOf(String source, String pattern, int start, int end);

int _gcLastIndexOf(String source, String pattern, int start, int end);



#endif