#ifndef BIGINT_H
#define BIGINT_H

#include "stdlib.h"
#include <iostream>
#include <cstring>
#include <assert.h>
#include <time.h>
#include <vector>

using namespace std;

#define NEG 0
#define POS 1

class BigInt
{
private:
    int sign;
    static const unsigned int base = 10000;
    vector<unsigned int> number;

public:
    BigInt();
    BigInt(const char *);
    BigInt(const BigInt &bi) : number(bi.number), sign(bi.sign){};
    BigInt(int);
    BigInt(long long);
    BigInt(string str);

    int get_sign();

    BigInt &operator+=(const BigInt &);
    BigInt &operator-=(const BigInt &);
    BigInt &operator*=(const BigInt &);
    BigInt &operator/=(const BigInt &);
    BigInt &operator%=(const BigInt &);

    void output();

private:
    friend bool operator<(const BigInt &, const BigInt &);
    friend ostream &operator<<(ostream &, const BigInt &);
    void add(const vector<unsigned> &);
    void minus(const vector<unsigned> &, const vector<unsigned> &);
    void minus(const vector<unsigned> &);
    static bool tlt(const vector<unsigned> &, const vector<unsigned> &);
};

const BigInt operator+(const BigInt &, const BigInt &);
const BigInt operator-(const BigInt &, const BigInt &);
const BigInt operator*(const BigInt &, const BigInt &);
const BigInt operator/(const BigInt &, const BigInt &);
const BigInt operator%(const BigInt &, const BigInt &);
bool operator<(const BigInt &, const BigInt &);
bool operator<=(const BigInt &, const BigInt &);
bool operator==(const BigInt &, const BigInt &);
bool operator>=(const BigInt &, const BigInt &);
bool operator>(const BigInt &, const BigInt &);
ostream &operator<<(ostream &_OStr, const BigInt &rhs);

#endif // BIGINT_H
