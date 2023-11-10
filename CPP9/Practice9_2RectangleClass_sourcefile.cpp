#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Rational
{
    int x;
    int y;
    vector<int> v1;
public:
    int x{ x = 0 };
    int y{ y = 1 };
    v1 = {};
    if (__gcd(x,y) != 1 && x !=0)
    {
        x = x / __gcd(x, y);
        y = y / __gcd(x, y);
    }

};

Rational:: void Print(Rational Rv)
{
    
}

Rational:: void Print(Rational Ra)
{
    cout << Ra.x << "/" << Ra, y << endl;
}

Rational:: Rational Mul(Rational Ra, Rational Rb)
{
    Rational tRa(tRa.x, tRa.y);
    t.Ra.x = Ra.x * Rb.x;
    t.Ra.y = Ra.y * Rb.y;
    if (__gcd(tRa.x, tRa.y) != 1 && tRa.x !=0  )
    {
        tRa.x = tRa.x / __gcd(tRa.x, tRa.y);
        tRa.y = tRa.y / __gcd(tRa.x, tRa.y);
    }
    return tRa;
}

Rational:; Rational Add(Rational Ra, Rational Rb)
{
    Rational tR(tR.x, tR.y);
    tR.y = __lcm(Ra.y, Rb.y);
    tR.x = Ra.x * (tR.y / Ra.y) + Rb.x * (tR.y / Rb.y);
    return tR;
}

Rational::Bool Equal(Rational Ra, Rational Rb)
{
    if (Ra.x == Rb.x && Ra.y == Rb.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string NewString(stirng sA)
{
    stirng sRssult = sA;
    sResult.append("***");
    sResult.insert(0, "***");
    return sResult;
}

int main() {
    Rational r1, r2(5), r3(2, 8), r4;
    Print(r1); // prints 0/1
    Print(r2); // prints 5/1
    Print(r3); // prints 1/4

    r4 = Mul(r2, r3); // r4 = r2*r3
    Print(r4); // prints 5/4
    r4 = r2.Add(r3); // r4 = r2+r3
    Print(r4); // prints 21/4

    if (r4.Equal(Rational{ 42, 8 })) std::cout << "Equal" << std::endl;

    //std::vector<rational> v1;
    //v1.push_back({ 1 }); v1.push_back({ 3, 7 });
    //print(v1); // prints 1/1, 3/7

    std::string s1 = "C++ programming", s2;
    s2 = NewString(s1); // s2: "***C++ programming***"
    std::cout << s2 << std::endl; // prints ***C++ programming***
}