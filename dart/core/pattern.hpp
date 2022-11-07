#ifndef PATTERN_H
#define PATTERN_H
#include <memory>




class Pattern {
public:

    Iterable<Match> allMatches(int start, String string);

    Match matchAsPrefix(int start, String string);

private:

};

class Match {
public:

    int start();

    int end();

    String group(int group);

    String [](int group);

    List<String> groups(List<int> groupIndices);

    int groupCount();

    String input();

    Pattern pattern();

private:

};

#endif