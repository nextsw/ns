#ifndef DART_CORE_STRING
#define DART_CORE_STRING
#include <base.hpp>

#include <dart/core/core.hpp>


class StringCls : public ObjectCls {
public:

    extern void  fromCharCodes(Iterable<int> charCodes, int end, int start);
    extern void  fromCharCode(int charCode);
    extern void  fromEnvironment(String defaultValue, String name);
    virtual String operator[](int index);
    virtual int codeUnitAt(int index);
    virtual int length();
    virtual int hashCode();
    virtual bool operator==(Object other);
    virtual int compareTo(String other);
    virtual bool endsWith(String other);
    virtual bool startsWith(int index, Pattern pattern);
    virtual int indexOf(Pattern pattern, int start);
    virtual int lastIndexOf(Pattern pattern, int start);
    virtual bool isEmpty();
    virtual bool isNotEmpty();
    virtual String operator+(String other);
    virtual String substring(int end, int start);
    virtual String trim();
    virtual String trimLeft();
    virtual String trimRight();
    virtual String operator*(int times);
    virtual String padLeft(String padding, int width);
    virtual String padRight(String padding, int width);
    virtual bool contains(Pattern other, int startIndex);
    virtual String replaceFirst(Pattern from, int startIndex, String to);
    virtual String replaceFirstMapped(Pattern from, String replace(Match match) , int startIndex);
    virtual String replaceAll(Pattern from, String replace);
    virtual String replaceAllMapped(Pattern from, String replace(Match match) );
    virtual String replaceRange(int end, String replacement, int start);
    virtual List<String> split(Pattern pattern);
    virtual String splitMapJoin(String onMatch(Match ) , String onNonMatch(String ) , Pattern pattern);
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

int _combineSurrogatePair(int end, int start);


class RuneIteratorCls : public ObjectCls {
public:
    String string;


     RuneIteratorCls(String stringValue);

    virtual void  at(int index, String stringValue);

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