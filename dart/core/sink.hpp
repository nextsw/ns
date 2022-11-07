#ifndef SINK_H
#define SINK_H
#include <memory>




class Sink<T> {
public:

    void add(T data);

    void close();

private:

};

#endif