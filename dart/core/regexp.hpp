#ifndef REGEXP_H
#define REGEXP_H
#include <memory>




class RegExp {
public:

    external  RegExp(bool caseSensitive, bool dotAll, bool multiLine, String source, bool unicode);

    external static String escape(String text);

    RegExpMatch firstMatch(String input);

    Iterable<RegExpMatch> allMatches(String input, int start);

    bool hasMatch(String input);

    String stringMatch(String input);

    String pattern();

    bool isMultiLine();

    bool isCaseSensitive();

    bool isUnicode();

    bool isDotAll();

private:

};

class RegExpMatch {
public:

    String namedGroup(String name);

    Iterable<String> groupNames();

private:

};

#endif