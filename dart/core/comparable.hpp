#ifndef COMPARABLE_H
#define COMPARABLE_H
#include <memory>




class Comparable<T> {
public:

    int compareTo(T other);

    static int compare(Comparable a, Comparable b);

private:

};

#endif