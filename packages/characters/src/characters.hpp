#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <memory>

#include "characters_impl.hpp"



class Characters {
public:
    static const Characters empty;


     Characters(String string);

    String string();

    CharacterRange iterator();

    CharacterRange iteratorAtEnd();

    bool contains(String singleCharacterString);

    bool containsAll(Characters other);

    bool startsWith(Characters other);

    bool endsWith(Characters other);

    CharacterRange findFirst(Characters characters);

    CharacterRange findLast(Characters characters);

    Characters where(FunctionType test);

    Characters skip(int count);

    Characters take(int count);

    Characters getRange(int end, int start);

    Characters characterAt(int position);

    Characters skipLast(int count);

    Characters takeLast(int count);

    Characters skipWhile(FunctionType test);

    Characters takeWhile(FunctionType test);

    Characters skipLastWhile(FunctionType test);

    Characters takeLastWhile(FunctionType test);

    Characters +(Characters other);

    Characters replaceAll(Characters pattern, Characters replacement);

    Iterable<Characters> split(int maxParts, Characters pattern);

    Characters replaceFirst(Characters pattern, Characters replacement);

    Characters toLowerCase();

    Characters toUpperCase();

    int hashCode();

    bool ==(Object other);

    String toString();

private:

};

class CharacterRange {
public:

     CharacterRange(String string);

    void  at(int endIndex, int startIndex, String string);

    Characters source();

    Iterable<int> utf16CodeUnits();

    Runes runes();

    Characters currentCharacters();

    Characters charactersBefore();

    Characters charactersAfter();

    String stringBefore();

    int stringBeforeLength();

    String stringAfter();

    int stringAfterLength();

    CharacterRange copy();

    bool isEmpty();

    bool isNotEmpty();

    bool moveNext(int count);

    void moveNextAll();

    bool moveTo(Characters target);

    bool moveUntil(Characters target);

    bool moveBack(int count);

    void moveBackAll();

    bool moveBackTo(Characters target);

    bool moveBackUntil(Characters target);

    bool expandNext(int count);

    bool expandTo(Characters target);

    bool expandUntil(Characters target);

    void expandWhile(FunctionType test);

    void expandAll();

    bool expandBack(int count);

    bool expandBackTo(Characters target);

    bool expandBackUntil(Characters target);

    void expandBackWhile(FunctionType test);

    void expandBackAll();

    void collapseToStart();

    bool collapseToFirst(Characters target);

    bool collapseToLast(Characters target);

    void collapseToEnd();

    bool dropFirst(int count);

    bool dropTo(Characters target);

    bool dropUntil(Characters target);

    void dropWhile(FunctionType test);

    bool dropLast(int count);

    bool dropBackTo(Characters target);

    bool dropBackUntil(Characters target);

    void dropBackWhile(FunctionType test);

    CharacterRange replaceRange(Characters replacement);

    CharacterRange replaceAll(Characters pattern, Characters replacement);

    Iterable<CharacterRange> split(int maxParts, Characters pattern);

    CharacterRange replaceFirst(Characters pattern, Characters replacement);

    bool startsWith(Characters characters);

    bool endsWith(Characters characters);

    bool isPrecededBy(Characters characters);

    bool isFollowedBy(Characters characters);

private:

};

#endif