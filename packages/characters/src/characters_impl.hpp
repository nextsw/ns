#ifndef CHARACTERS_IMPL_H
#define CHARACTERS_IMPL_H
#include <memory>

#include <characters/src/grapheme_clusters/table.hpp>
#include "characters.hpp"
#include "grapheme_clusters/constants.hpp"
#include "grapheme_clusters/breaks.hpp"



class StringCharacters : Iterable<String> {
public:
    String string;


     StringCharacters(String string);

    CharacterRange iterator();

    CharacterRange iteratorAtEnd();

    String first();

    String last();

    String single();

    bool isEmpty();

    bool isNotEmpty();

    int length();

    Iterable<T> whereType<T>();

    String join(String separator);

    String lastWhere(FunctionType orElse, FunctionType test);

    String elementAt(int index);

    bool contains(Object singleCharacterString);

    bool startsWith(Characters characters);

    bool endsWith(Characters characters);

    Characters replaceAll(Characters pattern, Characters replacement);

    Characters replaceFirst(Characters pattern, Characters replacement);

    Iterable<Characters> split(int maxParts, Characters pattern);

    bool containsAll(Characters characters);

    Characters skip(int count);

    Characters take(int count);

    Characters getRange(int end, int start);

    Characters characterAt(int position);

    Characters skipWhile(FunctionType test);

    Characters takeWhile(FunctionType test);

    Characters where(FunctionType test);

    Characters +(Characters characters);

    Characters skipLast(int count);

    Characters skipLastWhile(FunctionType test);

    Characters takeLast(int count);

    Characters takeLastWhile(FunctionType test);

    Characters toLowerCase();

    Characters toUpperCase();

    bool ==(Object other);

    int hashCode();

    String toString();

    CharacterRange findFirst(Characters characters);

    CharacterRange findLast(Characters characters);

private:

    StringCharacterRange _rangeAll();

    int _skipIndices(Breaks breaks, int count, int cursor);

    Characters _skip(int count);

    Characters _take(int count);

};

class StringCharacterRange {
public:

     StringCharacterRange(String string);

    void  at(int endIndex, int startIndex, String string);

    String current();

    bool moveNext(int count);

    bool moveBack(int count);

    Iterable<int> utf16CodeUnits();

    Runes runes();

    CharacterRange copy();

    void collapseToEnd();

    void collapseToStart();

    bool dropFirst(int count);

    bool dropTo(Characters target);

    bool dropUntil(Characters target);

    void dropWhile(FunctionType test);

    bool dropLast(int count);

    bool dropBackTo(Characters target);

    bool dropBackUntil(Characters target);

    void dropBackWhile(FunctionType test);

    bool expandNext(int count);

    bool expandTo(Characters target);

    void expandWhile(FunctionType test);

    void expandAll();

    bool expandBack(int count);

    bool expandBackTo(Characters target);

    void expandBackWhile(FunctionType test);

    bool expandBackUntil(Characters target);

    void expandBackAll();

    bool expandUntil(Characters target);

    bool isEmpty();

    bool isNotEmpty();

    bool moveBackUntil(Characters target);

    bool collapseToFirst(Characters target);

    bool collapseToLast(Characters target);

    bool moveUntil(Characters target);

    CharacterRange replaceFirst(Characters pattern, Characters replacement);

    CharacterRange replaceAll(Characters pattern, Characters replacement);

    CharacterRange replaceRange(Characters replacement);

    Characters source();

    bool startsWith(Characters characters);

    bool endsWith(Characters characters);

    bool isFollowedBy(Characters characters);

    bool isPrecededBy(Characters characters);

    bool moveBackTo(Characters target);

    bool moveTo(Characters target);

    Characters charactersAfter();

    Characters charactersBefore();

    Characters currentCharacters();

    void moveBackAll();

    void moveNextAll();

    String stringAfter();

    int stringAfterLength();

    String stringBefore();

    int stringBeforeLength();

    Iterable<CharacterRange> split(int maxParts, Characters pattern);

private:
    String _string;

    int _start;

    int _end;

    String _currentCache;


    void  _(int _end, int _start, String _string);

    void _move(int end, int start);

    Breaks _breaksFromEnd();

    BackBreaks _backBreaksFromStart();

    bool _advanceEnd(int count, int newStart);

    bool _moveNextPattern(int end, String patternString, int start);

    bool _retractStart(int count, int newEnd);

    bool _movePreviousPattern(int end, String patternString, int start);

    bool _retractStartUntil(int newEnd, String targetString);

    bool _advanceEndUntil(int newStart, String targetString);

    static StringCharacterRange _expandRange(int end, int start, String string);

    bool _endsWith(int end, int start, String string);

    bool _startsWith(int end, int start, String string);

};
String _explodeReplace(int end, String internalReplacement, String outerReplacement, int start, String string);

int _indexOf(int end, String pattern, String source, int start);

int _gcIndexOf(int end, String pattern, String source, int start);

int _lastIndexOf(int end, String pattern, String source, int start);

int _gcLastIndexOf(int end, String pattern, String source, int start);


#endif