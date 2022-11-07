#ifndef STRING_BUFFER_H
#define STRING_BUFFER_H
#include <memory>




class StringBuffer {
public:

    external  StringBuffer(Object content);

    external int length();

    bool isEmpty();

    bool isNotEmpty();

    external void write(Object object);

    external void writeCharCode(int charCode);

    external void writeAll(Iterable<dynamic> objects, String separator);

    external void writeln(Object obj);

    external void clear();

    external String toString();

private:

};

#endif