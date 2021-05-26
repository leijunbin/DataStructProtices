#include "calculate.h"
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

calculateBehind::calculateBehind(point *b, int n)
{
    root = b;
    bits = n;
}

BigInt calculateBehind::calculate()
{
    stack<BigInt> s;
    for (int i = 0; i < bits; i++)
    {
        if (root[i].b == '\0')
        {
            s.push(root[i].a);
        }
        else
        {
            BigInt c;
            c = s.top();
            s.pop();
            BigInt d;
            d = s.top();
            s.pop();
            char m = root[i].b;
            BigInt sum;
            switch (m)
            {
            case '+':
                sum = c + d;
                break;
            case '-':
                sum = c - d;
                break;
            case '*':
                sum = c * d;
                break;
            case '/':
                sum = c / d;
                break;
            }
            s.push(sum);
        }
    }
    BigInt result;
    result = s.top();
    return result;
}
