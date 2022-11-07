#ifndef BREAKS_H
#define BREAKS_H
#include <memory>

#include "constants.hpp"
#include "table.hpp"



class Breaks {
public:
    String base;

    int end;

    int cursor;

    int state;


     Breaks(String base, int cursor, int end, int state);

    Breaks copy();

    int nextBreak();

private:

};

class BackBreaks {
public:
    String base;

    int start;

    int cursor;

    int state;


     BackBreaks(String base, int cursor, int start, int state);

    BackBreaks copy();

    int nextBreak();

private:

    int _lookAhead(int state);

};
int lookAhead(String base, int cursor, int start, int state);

int lookAheadRegional(String base, int cursor, int start);

int lookAheadPictorgraphicExtend(String base, int cursor, int start);

bool isGraphemeClusterBoundary(int end, int index, int start, String text);

int previousBreak(int end, int index, int start, String text);

int nextBreak(int end, int index, int start, String text);


#endif