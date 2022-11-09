#ifndef DART_CORE_PATTERN
#define DART_CORE_PATTERN
#include <base.hpp>

#include <dart/core/core.hpp>


class PatternCls : public ObjectCls {
public:

    virtual Iterable<Match> allMatches(int start, String stringValue);
    virtual Match matchAsPrefix(int start, String stringValue);
private:

};
using Pattern = std::shared_ptr<PatternCls>;

class MatchCls : public ObjectCls {
public:

    virtual int start();
    virtual int end();
    virtual String group(int group);
    virtual String operator[](int group);
    virtual List<String> groups(List<int> groupIndices);
    virtual int groupCount();
    virtual String input();
    virtual Pattern pattern();
private:

};
using Match = std::shared_ptr<MatchCls>;


#endif