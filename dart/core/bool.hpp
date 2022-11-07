#ifndef BOOL_H
#define BOOL_H
#include <memory>




class bool {
public:

    external void  fromEnvironment(bool defaultValue, String name);

    external void  hasEnvironment(String name);

    external int hashCode();

    bool &(bool other);

    bool |(bool other);

    bool ^(bool other);

    String toString();

private:

};

#endif