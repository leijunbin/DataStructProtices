#include "bigint.h"
#include <cstring>
using namespace std;

BigInt::BigInt()
{
    number.push_back(0);
}

BigInt::BigInt(int n)
{
    if (n < 0)
        sign = NEG;
    else
        sign = POS;
    if (n == 0)
    {
        number.push_back(0);
    }
    else
    {
        if (n < 0)
            n = -n;
        while (n != 0)
        {
            number.push_back(n % base);
            n /= base;
        }
    }
}
BigInt::BigInt(long long n)
{
    if (n < 0)
        sign = NEG;
    else
        sign = POS;
    if (n == 0)
    {
        number.push_back(0);
    }
    else
    {
        if (n < 0)
            n = -n;
        while (n != 0)
        {
            number.push_back((int)(n % base));
            n /= base;
        }
    }
}
BigInt::BigInt(const char *str)
{
    int len = strlen(str);
    assert(len > 0);
    int from = 0;
    int temp = 0;
    if (str[0] == '-')
    {
        sign = NEG;
        from = 1;
    }
    else
    {
        sign = POS;
    }
    int idx = len - 1;
    int de = 0;
    int times = 1;
    while (idx - de >= from)
    {
        if (de % 4 == 0)
        {
            times = 1;
        }
        temp += (times * (str[idx - de] - '0'));
        times *= 10;
        if (de % 4 == 3)
        {
            number.push_back(temp);
            temp = 0;
        }
        ++de;
    }
    if (temp != 0)
        number.push_back(temp);
    int i = number.size() - 1;
    while (i > 0 && number[i] == 0)
    {
        number.pop_back();
        --i;
    }
    if (number.size() == 0)
    {
        number.push_back(0);
        sign = POS;
    }
}
BigInt::BigInt(string str)
{
    int len = str.length();
    assert(len > 0);
    int from = 0;
    int temp = 0;
    if (str[0] == '-')
    {
        sign = NEG;
        from = 1;
    }
    else
    {
        sign = POS;
    }
    int idx = len - 1;
    int de = 0;
    int times = 1;
    while (idx - de >= from)
    {
        if (de % 4 == 0)
        {
            times = 1;
        }
        temp += (times * (str[idx - de] - '0'));
        times *= 10;
        if (de % 4 == 3)
        {
            number.push_back(temp);
            temp = 0;
        }
        ++de;
    }
    if (temp != 0)
        number.push_back(temp);
    int i = number.size() - 1;
    while (i > 0 && number[i] == 0)
    {
        number.pop_back();
        --i;
    }
    if (number.size() == 0)
    {
        number.push_back(0);
        sign = POS;
    }
}

void BigInt::output()
{
    if (sign == NEG)
        cout << '-';
    cout << number[number.size() - 1];
    for (int i = number.size() - 2; i >= 0; --i)
    {
        cout << number[i] / 1000 << (number[i] % 1000) / 100
             << (number[i] % 100) / 10 << number[i] % 10;
    }
}

bool BigInt::tlt(const vector<unsigned> &lhs, const vector<unsigned> &rhs)
{
    if (lhs.size() < rhs.size())
        return true;
    else if (rhs.size() < lhs.size())
        return false;
    else
    {
        for (int i = lhs.size() - 1; i >= 0; --i)
        {
            if (lhs[i] < rhs[i])
                return true;
            else if (rhs[i] < lhs[i])
                return false;
        }
    }
    return false;
}

void BigInt::add(const vector<unsigned> &rhs)
{
    int nleft = number.size();
    int nright = rhs.size();
    int i = 0;
    unsigned c = 0;
    unsigned temp = 0;
    while (nleft < nright)
    {
        number.push_back(0);
        ++nleft;
    }
    while (i < nright)
    {
        temp = number[i] + rhs[i] + c;
        number[i] = temp % base;
        c = temp / base;
        ++i;
    }
    while (i < nleft && c != 0)
    {
        temp = number[i] + c;
        number[i] = temp % base;
        c = temp / base;
        ++i;
    }
    if (c != 0)
        number.push_back(c);
}
void BigInt::minus(const vector<unsigned> &lhs, const vector<unsigned> &rhs)
{
    vector<unsigned> res;
    int nleft = lhs.size();
    int nright = rhs.size();
    int i = 0;
    unsigned c = 0;
    unsigned temp = 0;
    res.resize(nleft);
    for (i = nleft - 1; i >= 0; --i)
        res[i] = 0;
    i = 0;
    while (i < nright)
    {
        temp = lhs[i] + base - rhs[i] - c;
        res[i] = temp % base;
        c = temp / base;
        c = (c == 1 ? 0 : 1);
        ++i;
    }
    while (i < nleft)
    {
        temp = lhs[i] + base - c;
        res[i] = temp % base;
        c = temp / base;
        c = (c == 1 ? 0 : 1);
        ++i;
    }
    i = nleft - 1;
    while (i > 0 && res[i] == 0)
    {
        res.pop_back();
        --i;
    }
    number = res;
}
void BigInt::minus(const vector<unsigned> &rhs)
{
    int nleft = number.size();
    int nright = rhs.size();
    int i = 0;
    unsigned c = 0;
    unsigned temp = 0;
    while (i < nright)
    {
        temp = number[i] + base - rhs[i] - c;
        number[i] = temp % base;
        c = temp / base;
        c = (c == 1 ? 0 : 1);
        ++i;
    }
    while (i < nleft)
    {
        temp = number[i] + base - c;
        number[i] = temp % base;
        c = temp / base;
        c = (c == 1 ? 0 : 1);
        ++i;
    }
    i = nleft - 1;
    while (i > 0 && number[i] == 0)
    {
        number.pop_back();
        --i;
    }
}

BigInt &BigInt::operator+=(const BigInt &rhs)
{
    if (rhs.sign == sign)
    {
        add(rhs.number);
    }                                 //同号相加
    else if (tlt(number, rhs.number)) //绝对值较小
    {
        sign = rhs.sign;
        minus(rhs.number, number);
    }
    else
    {
        minus(rhs.number);
    }
    return *this;
}
BigInt &BigInt::operator-=(const BigInt &rhs)
{
    if (rhs.sign != sign)
    {
        add(rhs.number);
    } //异号则相加
    else if (tlt(number, rhs.number))
    {
        sign = sign ^ 1;
        minus(rhs.number, number);
    }
    else
    {
        minus(rhs.number);
    }
    return *this;
}
BigInt &BigInt::operator*=(const BigInt &rhs)
{
    if (sign != rhs.sign)
        sign = NEG;
    else
        sign = POS;
    int nleft = number.size();
    int nright = rhs.number.size();
    int i, j, c, temp, idx;
    int maxlen = nleft + nright + 1;
    vector<unsigned> res;
    res.resize(maxlen);
    for (i = 0; i < maxlen; ++i)
    {
        res[i] = 0;
    };
    for (i = 0; i < nright; ++i)
    {
        c = 0;
        temp = 0;
        idx = i;
        for (j = 0; j < nleft; ++j)
        {
            temp = number[j] * rhs.number[i] + res[idx] + c;
            res[idx] = temp % base;
            c = temp / base;
            ++idx;
        }
        while (c != 0)
        {
            temp = res[idx] + c;
            res[idx] = temp % base;
            c = temp / base;
            ++idx;
        }
    }
    i = res.size() - 1;
    while (i > 0 && res[i] == 0)
    {
        res.pop_back();
        --i;
    }
    number = res;
    return *this;
}
BigInt &BigInt::operator/=(const BigInt &rhs)
{
    int nleft = number.size();
    int nright = rhs.number.size();
    int i, temp;
    if (sign != rhs.sign)
        sign = NEG;
    else
        sign = POS;
    assert(!(nright == 1 && rhs.number[0] == 0)); //除数不为0
    if (tlt(number, rhs.number))
    {
        number.resize(0);
        number.push_back(0);
        sign = POS;
        return *this;
    }
    vector<unsigned> diver;
    vector<unsigned> mid;
    vector<unsigned> res;
    diver.resize(nright + 1);
    mid.resize(nright + 1);
    for (i = 0; i <= nright; ++i)
        diver[i] = 0;
    res.resize(nleft - nright + 1);
    for (i = 0; i <= nleft - nright; ++i)
        res[i] = 0;
    int ires = nleft - nright;
    int idx = nleft - nright + 1;
    for (i = 0; i < nright - 1; ++i)
    {
        diver[i] = number[idx + i];
    }
    --idx;
    int max_idx_diver = diver.size() - 1;
    int max_idx_right = rhs.number.size() - 1;
    int temp_res;
    int c, temp2;
    for (; idx >= 0; --idx)
    {
        for (i = max_idx_diver; i > 0; --i)
            diver[i] = diver[i - 1];
        diver[0] = number[idx];
        temp = diver[max_idx_diver] * base + diver[max_idx_diver - 1];
        temp_res = temp / rhs.number[max_idx_right];

        while (temp_res >= 0)
        {
            c = 0;
            for (i = 0; i <= max_idx_right; ++i)
            {
                temp2 = rhs.number[i] * temp_res + c;
                mid[i] = temp2 % base;
                c = temp2 / base;
            }
            mid[max_idx_diver] = c;
            if (tlt(diver, mid))
                --temp_res;
            else
                break;
        }

        c = 0;
        for (i = 0; i <= max_idx_right; ++i)
        {
            temp2 = rhs.number[i] * temp_res + c;
            mid[i] = temp2 % base;
            c = temp2 / base;
        }
        mid[max_idx_diver] = c;
        c = 0;
        for (i = 0; i <= max_idx_diver; ++i)
        {
            temp2 = diver[i] + base - mid[i] - c;
            diver[i] = temp2 % base;
            c = temp2 / base;
            c = c ^ 1;
        }
        res[idx] = temp_res;
    }
    i = res.size() - 1;
    while (i > 0 && res[i] == 0)
    {
        res.pop_back();
        --i;
    }
    number = res;
    return *this;
}
BigInt &BigInt::operator%=(const BigInt &rhs)
{
    int nleft = number.size();
    int nright = number.size();
    assert(!(nright == 1 && rhs.number[0] == 0));
    //符号不变
    if (tlt(number, rhs.number))
        return *this;
    BigInt bi1(*this);
    bi1 /= rhs;
    bi1 *= rhs;
    BigInt bi2(*this);
    bi2 -= bi1;
    number = bi2.number;
    if (number.size() == 1 && number[0] == 0)
        sign = POS;
    return *this;
}

const BigInt operator+(const BigInt &lhs, const BigInt &rhs)
{
    BigInt res(lhs);
    res += rhs;
    return res;
}
const BigInt operator-(const BigInt &lhs, const BigInt &rhs)
{
    BigInt res(lhs);
    res -= rhs;
    return res;
}
const BigInt operator*(const BigInt &lhs, const BigInt &rhs)
{
    BigInt res(lhs);
    res *= rhs;
    return res;
}
const BigInt operator/(const BigInt &lhs, const BigInt &rhs)
{
    BigInt res(lhs);
    res /= rhs;
    return res;
}
const BigInt operator%(const BigInt &lhs, const BigInt &rhs)
{
    BigInt res(lhs);
    res %= rhs;
    return res;
}

bool operator<(const BigInt &lhs, const BigInt &rhs)
{
    if (lhs.sign < rhs.sign)
        return true;
    else if (rhs.sign < lhs.sign)
        return false;
    else if (lhs.sign == POS)
        return BigInt::tlt(lhs.number, rhs.number);
    else
        return BigInt::tlt(rhs.number, lhs.number);
}
bool operator<=(const BigInt &lhs, const BigInt &rhs)
{
    return !(rhs < lhs);
}
bool operator==(const BigInt &lhs, const BigInt &rhs)
{
    return !(rhs < lhs) && !(lhs < rhs);
}
bool operator>=(const BigInt &lhs, const BigInt &rhs)
{
    return !(lhs < rhs);
}
bool operator>(const BigInt &lhs, const BigInt &rhs)
{
    return rhs < lhs;
}

ostream &operator<<(ostream &_OStr, const BigInt &rhs)
{
    if (rhs.sign == NEG)
        _OStr << '-';
    _OStr << rhs.number[rhs.number.size() - 1];
    for (int i = rhs.number.size() - 2; i >= 0; --i)
    {
        _OStr << rhs.number[i] / 1000 << (rhs.number[i] % 1000) / 100
              << (rhs.number[i] % 100) / 10 << rhs.number[i] % 10;
    }
    return _OStr;
}
