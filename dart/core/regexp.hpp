#ifndef DART_CORE_REGEXP
#define DART_CORE_REGEXP
#include <base.hpp>

#include <dart/core/core.hpp>


class RegExpCls : public ObjectCls {
public:

     RegExpCls(bool caseSensitive, bool dotAll, bool multiLine, String source, bool unicode);
    static String escape(String text);
    virtual RegExpMatch firstMatch(String input);
    virtual Iterable<RegExpMatch> allMatches(String input, int start);
    virtual bool hasMatch(String input);
    virtual String stringMatch(String input);
    virtual String pattern();
    virtual bool isMultiLine();
    virtual bool isCaseSensitive();
    virtual bool isUnicode();
    virtual bool isDotAll();
private:

};
using RegExp = std::shared_ptr<RegExpCls>;

class RegExpMatchCls : public ObjectCls {
public:

    virtual String namedGroup(String name);
    virtual Iterable<String> groupNames();
private:

};
using RegExpMatch = std::shared_ptr<RegExpMatchCls>;


#endif