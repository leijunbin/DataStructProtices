#ifndef CALCULATE_H
#define CALCULATE_H

#include <iostream>
#include <stack>
#include <cstring>
#include "bigint.h"
#include "buildtree.h"
using namespace std;

class calculateBehind
{
public:
    calculateBehind(point *b, int n);
    BigInt calculate();

private:
    point *root;
    int bits;
};

#endif // CALCULATE_H
