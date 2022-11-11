#ifndef PACKAGES_CHARACTERS_SRC_GRAPHEME_CLUSTERS_BREAKS
#define PACKAGES_CHARACTERS_SRC_GRAPHEME_CLUSTERS_BREAKS
#include <base.hpp>

#include <dart/core/core.hpp>
#include "constants.hpp"
#include "table.hpp"


class BreaksCls : public ObjectCls {
public:
    String base;

    int end;

    int cursor;

    int state;


     BreaksCls(String base, int cursor, int end, int state);
    virtual Breaks copy();

    virtual int nextBreak();

private:

};
using Breaks = std::shared_ptr<BreaksCls>;

class BackBreaksCls : public ObjectCls {
public:
    String base;

    int start;

    int cursor;

    int state;


     BackBreaksCls(String base, int cursor, int start, int state);
    virtual BackBreaks copy();

    virtual int nextBreak();

private:

    virtual int _lookAhead(int state);

};
using BackBreaks = std::shared_ptr<BackBreaksCls>;
int lookAhead(String base, int start, int cursor, int state);

int lookAheadRegional(String base, int start, int cursor);

int lookAheadPictorgraphicExtend(String base, int start, int cursor);

bool isGraphemeClusterBoundary(String text, int start, int end, int index);

int previousBreak(String text, int start, int end, int index);

int nextBreak(String text, int start, int end, int index);



#endif