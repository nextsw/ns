#ifndef DART_CORE_STRING
#define DART_CORE_STRING
#include <base.hpp>

#include <dart/core/core.hpp>


class StringCls : public ObjectCls {
public:

    void  fromCharCodes(Iterable<int> charCodes, int start, int end);
    void  fromCharCode(int charCode);
    void  fromEnvironment(String name, String defaultValue);
    virtual String operator[](int index);
    virtual int codeUnitAt(int index);
    virtual int length();
    virtual int hashCode();
    virtual bool operator==(Object other);
    virtual int compareTo(String other);
    virtual bool endsWith(String other);
    virtual bool startsWith(Pattern pattern, int index);
    virtual int indexOf(Pattern pattern, int start);
    virtual int lastIndexOf(Pattern pattern, int start);
    virtual bool isEmpty();
    virtual bool isNotEmpty();
    virtual String operator+(String other);
    virtual String substring(int start, int end);
    virtual String trim();
    virtual String trimLeft();
    virtual String trimRight();
    virtual String operator*(int times);
    virtual String padLeft(int width, String padding);
    virtual String padRight(int width, String padding);
    virtual bool contains(Pattern other, int startIndex);
    virtual String replaceFirst(Pattern from, String to, int startIndex);
    virtual String replaceFirstMapped(Pattern from, std::function<String(Match match)> replace, int startIndex);
    virtual String replaceAll(Pattern from, String replace);
    virtual String replaceAllMapped(Pattern from, std::function<String(Match match)> replace);
    virtual String replaceRange(int start, int end, String replacement);
    virtual List<String> split(Pattern pattern);
    virtual String splitMapJoin(Pattern pattern, std::function<String(Match )> onMatch, std::function<String(String )> onNonMatch);
    virtual List<int> codeUnits();
    virtual Runes runes();
    virtual String toLowerCase();
    virtual String toUpperCase();
private:

};
using String = std::shared_ptr<StringCls>;

class RunesCls : public IterableCls<int> {
public:
    String string;


     RunesCls(String string);
    virtual RuneIterator iterator();

    virtual int last();

private:

};
using Runes = std::shared_ptr<RunesCls>;
bool _isLeadSurrogate(int code);

bool _isTrailSurrogate(int code);

int _combineSurrogatePair(int start, int end);


class RuneIteratorCls : public ObjectCls {
public:
    String string;


     RuneIteratorCls(String stringValue);

    virtual void  at(String stringValue, int index);

    virtual int rawIndex();

    virtual void rawIndex(int rawIndex);

    virtual void reset(int rawIndex);

    virtual int current();

    virtual int currentSize();

    virtual String currentAsString();

    virtual bool moveNext();

    virtual bool movePrevious();

private:
    int _position;

    int _nextPosition;

    int _currentCodePoint;


    virtual void _checkSplitSurrogate(int index);

};
using RuneIterator = std::shared_ptr<RuneIteratorCls>;


#endif