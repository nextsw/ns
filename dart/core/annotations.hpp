#ifndef ANNOTATIONS_H
#define ANNOTATIONS_H
#include <memory>




class Deprecated {
public:
    String message;


     Deprecated(String message);

    String expires();

    String toString();

private:

};
const Deprecated deprecated;


class _Override {
public:

private:

     _Override();

};
const Object override;


class Provisional {
public:

    String message();

     Provisional(String message);

private:

};
const Null provisional;

const Null proxy;


#endif