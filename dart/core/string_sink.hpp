#ifndef STRING_SINK_H
#define STRING_SINK_H
#include <memory>




class StringSink {
public:

    void write(Object object);

    void writeAll(Iterable<dynamic> objects, String separator);

    void writeln(Object object);

    void writeCharCode(int charCode);

private:

};

#endif