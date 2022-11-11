#ifndef PACKAGES_CHARACTERS_SRC_CHARACTERS
#define PACKAGES_CHARACTERS_SRC_CHARACTERS
#include <base.hpp>

#include <dart/core/core.hpp>
#include "characters_impl.hpp"


class CharactersCls : public ObjectCls {
public:
    static Characters empty;


     CharactersCls(String stringValue);

    virtual String stringValue();
    virtual CharacterRange iterator();
    virtual CharacterRange iteratorAtEnd();
    virtual bool contains(String singleCharacterString);
    virtual bool containsAll(Characters other);
    virtual bool startsWith(Characters other);
    virtual bool endsWith(Characters other);
    virtual CharacterRange findFirst(Characters characters);
    virtual CharacterRange findLast(Characters characters);
    virtual Characters where(std::function<bool(String )> test);
    virtual Characters skip(int count);
    virtual Characters take(int count);
    virtual Characters getRange(int start, int end);
    virtual Characters characterAt(int position);
    virtual Characters skipLast(int count);
    virtual Characters takeLast(int count);
    virtual Characters skipWhile(std::function<bool(String )> test);
    virtual Characters takeWhile(std::function<bool(String )> test);
    virtual Characters skipLastWhile(std::function<bool(String )> test);
    virtual Characters takeLastWhile(std::function<bool(String )> test);
    virtual Characters operator+(Characters other);
    virtual Characters replaceAll(Characters pattern, Characters replacement);
    virtual Iterable<Characters> split(Characters pattern, int maxParts);
    virtual Characters replaceFirst(Characters pattern, Characters replacement);
    virtual Characters toLowerCase();
    virtual Characters toUpperCase();
    virtual int hashCode();
    virtual bool operator==(Object other);
    virtual String toString();
private:

};
using Characters = std::shared_ptr<CharactersCls>;

class CharacterRangeCls : public ObjectCls {
public:

     CharacterRangeCls(String stringValue);
    virtual void  at(String stringValue, int startIndex, int endIndex);
    virtual Characters source();
    virtual Iterable<int> utf16CodeUnits();
    virtual Runes runes();
    virtual Characters currentCharacters();
    virtual Characters charactersBefore();
    virtual Characters charactersAfter();
    virtual String stringBefore();
    virtual int stringBeforeLength();
    virtual String stringAfter();
    virtual int stringAfterLength();
    virtual CharacterRange copy();
    virtual bool isEmpty();
    virtual bool isNotEmpty();
    virtual bool moveNext(int count);
    virtual void moveNextAll();
    virtual bool moveTo(Characters target);
    virtual bool moveUntil(Characters target);
    virtual bool moveBack(int count);
    virtual void moveBackAll();
    virtual bool moveBackTo(Characters target);
    virtual bool moveBackUntil(Characters target);
    virtual bool expandNext(int count);
    virtual bool expandTo(Characters target);
    virtual bool expandUntil(Characters target);
    virtual void expandWhile(std::function<bool(String )> test);
    virtual void expandAll();
    virtual bool expandBack(int count);
    virtual bool expandBackTo(Characters target);
    virtual bool expandBackUntil(Characters target);
    virtual void expandBackWhile(std::function<bool(String )> test);
    virtual void expandBackAll();
    virtual void collapseToStart();
    virtual bool collapseToFirst(Characters target);
    virtual bool collapseToLast(Characters target);
    virtual void collapseToEnd();
    virtual bool dropFirst(int count);
    virtual bool dropTo(Characters target);
    virtual bool dropUntil(Characters target);
    virtual void dropWhile(std::function<bool(String )> test);
    virtual bool dropLast(int count);
    virtual bool dropBackTo(Characters target);
    virtual bool dropBackUntil(Characters target);
    virtual void dropBackWhile(std::function<bool(String )> test);
    virtual CharacterRange replaceRange(Characters replacement);
    virtual CharacterRange replaceAll(Characters pattern, Characters replacement);
    virtual Iterable<CharacterRange> split(Characters pattern, int maxParts);
    virtual CharacterRange replaceFirst(Characters pattern, Characters replacement);
    virtual bool startsWith(Characters characters);
    virtual bool endsWith(Characters characters);
    virtual bool isPrecededBy(Characters characters);
    virtual bool isFollowedBy(Characters characters);
private:

};
using CharacterRange = std::shared_ptr<CharacterRangeCls>;


#endif