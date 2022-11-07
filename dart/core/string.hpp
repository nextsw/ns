#ifndef STRING_H
#define STRING_H
#include <memory>




class String {
public:

    external void  fromCharCodes(Iterable<int> charCodes, int end, int start);

    external void  fromCharCode(int charCode);

    external void  fromEnvironment(String defaultValue, String name);

    String [](int index);

    int codeUnitAt(int index);

    int length();

    int hashCode();

    bool ==(Object other);

    int compareTo(String other);

    bool endsWith(String other);

    bool startsWith(int index, Pattern pattern);

    int indexOf(Pattern pattern, int start);

    int lastIndexOf(Pattern pattern, int start);

    bool isEmpty();

    bool isNotEmpty();

    String +(String other);

    String substring(int end, int start);

    String trim();

    String trimLeft();

    String trimRight();

    String *(int times);

    String padLeft(String padding, int width);

    String padRight(String padding, int width);

    bool contains(Pattern other, int startIndex);

    String replaceFirst(Pattern from, int startIndex, String to);

    String replaceFirstMapped(Pattern from, FunctionType replace, int startIndex);

    String replaceAll(Pattern from, String replace);

    String replaceAllMapped(Pattern from, FunctionType replace);

    String replaceRange(int end, String replacement, int start);

    List<String> split(Pattern pattern);

    String splitMapJoin(FunctionType onMatch, FunctionType onNonMatch, Pattern pattern);

    List<int> codeUnits();

    Runes runes();

    String toLowerCase();

    String toUpperCase();

private:

};

class Runes : Iterable<int> {
public:
    String string;


     Runes(String string);

    RuneIterator iterator();

    int last();

private:

};
bool _isLeadSurrogate(int code);

bool _isTrailSurrogate(int code);

int _combineSurrogatePair(int end, int start);


class RuneIterator {
public:
    String string;


     RuneIterator(String string);

    void  at(int index, String string);

    int rawIndex();

    void rawIndex(int rawIndex);

    void reset(int rawIndex);

    int current();

    int currentSize();

    String currentAsString();

    bool moveNext();

    bool movePrevious();

private:
    int _position;

    int _nextPosition;

    int _currentCodePoint;


    void _checkSplitSurrogate(int index);

};

#endif