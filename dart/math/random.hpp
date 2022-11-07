#ifndef RANDOM_H
#define RANDOM_H
#include <memory>




class Random {
public:

    external  Random(int seed);

    external void  secure();

    int nextInt(int max);

    double nextDouble();

    bool nextBool();

private:

};

#endif