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

    virtual String lastWhere(String orElse() , bool test(String element) );

    virtual String elementAt(int index);

    virtual bool contains(Object singleCharacterString);

    virtual bool startsWith(Characters characters);

    virtual bool endsWith(Characters characters);

    virtual Characters replaceAll(Characters pattern, Characters replacement);

    virtual Characters replaceFirst(Characters pattern, Characters replacement);

    virtual Iterable<Characters> split(int maxParts, Characters pattern);

    virtual bool containsAll(Characters characters);

    virtual Characters skip(int count);

    virtual Characters take(int count);

    virtual Characters getRange(int end, int start);

    virtual Characters characterAt(int position);

    virtual Characters skipWhile(bool test(String ) );

    virtual Characters takeWhile(bool test(String ) );

    virtual Characters where(bool test(String ) );

    virtual Characters operator+(Characters characters);

    virtual Characters skipLast(int count);

    virtual Characters skipLastWhile(bool test(String ) );

    virtual Characters takeLast(int count);

    virtual Characters takeLastWhile(bool test(String ) );

    virtual Characters toLowerCase();

    virtual Characters toUpperCase();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

    virtual CharacterRange findFirst(Characters characters);

    virtual CharacterRange findLast(Characters characters);

private:

    virtual StringCharacterRange _rangeAll();

    virtual int _skipIndices(Breaks breaks, int count, int cursor);

    virtual Characters _skip(int count);

    virtual Characters _take(int count);

};
using StringCharacters = std::shared_ptr<StringCharactersCls>;

class StringCharacterRangeCls : public ObjectCls {
public:

     StringCharacterRangeCls(String stringValue);

    virtual void  at(int endIndex, int startIndex, String stringValue);

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

    virtual void dropWhile(bool test(String ) );

    virtual bool dropLast(int count);

    virtual bool dropBackTo(Characters target);

    virtual bool dropBackUntil(Characters target);

    virtual void dropBackWhile(bool test(String ) );

    virtual bool expandNext(int count);

    virtual bool expandTo(Characters target);

    virtual void expandWhile(bool test(String character) );

    virtual void expandAll();

    virtual bool expandBack(int count);

    virtual bool expandBackTo(Characters target);

    virtual void expandBackWhile(bool test(String character) );

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

    virtual Iterable<CharacterRange> split(int maxParts, Characters pattern);

private:
    String _string;

    int _start;

    int _end;

    String _currentCache;


    virtual void  _(int _end, int _start, String _string);
    virtual void _move(int end, int start);

    virtual Breaks _breaksFromEnd();

    virtual BackBreaks _backBreaksFromStart();

    virtual bool _advanceEnd(int count, int newStart);

    virtual bool _moveNextPattern(int end, String patternString, int start);

    virtual bool _retractStart(int count, int newEnd);

    virtual bool _movePreviousPattern(int end, String patternString, int start);

    virtual bool _retractStartUntil(int newEnd, String targetString);

    virtual bool _advanceEndUntil(int newStart, String targetString);

    static StringCharacterRange _expandRange(int end, int start, String stringValue);

    virtual bool _endsWith(int end, int start, String stringValue);

    virtual bool _startsWith(int end, int start, String stringValue);

};
using StringCharacterRange = std::shared_ptr<StringCharacterRangeCls>;
String _explodeReplace(int end, String internalReplacement, String outerReplacement, int start, String stringValue);

int _indexOf(int end, String pattern, String source, int start);

int _gcIndexOf(int end, String pattern, String source, int start);

int _lastIndexOf(int end, String pattern, String source, int start);

int _gcLastIndexOf(int end, String pattern, String source, int start);



#endif