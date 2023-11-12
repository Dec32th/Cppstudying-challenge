//Practice 9 #3 Rational Class
//실습 9 3번 분수를 표현하는 Rational Class를 만드시오.


#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

//Rational Class 선언. 
//숫자를 입력받아서 그 수를 분수로 바꿔서 저장함. 

class Rational
{
public:
    //분자 Numerator, 분모 Denomiator
    int iNumerator;
    int iDemoniator;
    
    //입력받은 수를 이용해서 기약 분수로 저장하는 생성자
    //최대 공약수 함수인 GCD를 이용해서 작성했다. #include<numeric>을 이용
    Rational(int x = 0, int y = 1)
    {
        if (gcd(x, y) != 0 && x != 0)
        {
            iNumerator = x / gcd(x, y);
            iDemoniator = y / gcd(x, y);
        }
        else
        {
            iNumerator = x;
            iDemoniator = y;
        }

    }

    //Rational 함수의 method 정의. 
    //method이기 때문에 instance_name.add(parameter)의 형태로 구성된다. parameter가 2개가 아님에 유의할 것
    //실제 분수의 형태로 값을 더한 후, 더한 값을 returm해주는 method.
    //numeric에 있는 LCM 함수를 사용했다.
    Rational Add(Rational rA)
    {
        Rational rResult;
        int iLcm = lcm(iDemoniator, rA.iDemoniator);
        rResult.iNumerator = iNumerator * (iLcm / iDemoniator) + rA.iNumerator * (iLcm / rA.iDemoniator);
        rResult.iDemoniator = iLcm;
        return rResult;
    }
    
    //Rational class를 parameter로 입력받고 값을 비교함. 같은 경우에는 true 출력, 같지 않은 경우엔 false return
    bool Equal(Rational rA)
    {
        if (iNumerator == rA.iNumerator && iDemoniator == rA.iDemoniator )
        {
            return true;
        }
        return false;
    }
};

//Raitonal을 parameter로 하고 그 값을 분수 형태로 출력하는 함수.
//Rational 함수를 출력하고, 동일한 이름의 vector를 출력하는 함수로 overloading
void Print(Rational Ra)
{
    cout << Ra.iNumerator <<'/' << Ra.iDemoniator << endl;
}

//Rational class type의 원소로 가지는 vector를 출력하는 함수. 
// Rational class를 출력하는 Print함수를 call하고 for문을 이용해서 그 함수를 벡터의 원소의 개수만큼 반복한다.  
void Print(vector<Rational> v)
{
    for(int i = 0 ; i<v.size() ;i++)
    {
        Print(v[i]);
        cout << ',';
    }
}

//Rational class를 통해 표현하는 분수들을 곱하는 함수
//분자는 분자끼리, 분모는 분모끼리 곲한 후에 그 값을 기약분수에 맞는 형태로 변환한다. Rational class에서.
//그 후 Rational class type으로 return한다. 
Rational Mul(Rational Ra, Rational Rb)
{
    Rational tR;
    tR.iNumerator = Ra.iNumerator * Rb.iNumerator;
    tR.iDemoniator = Ra.iDemoniator * Rb.iDemoniator;
    if (gcd(tR.iNumerator, tR.iDemoniator) != 1 && tR.iNumerator !=0 )
    {
        tR.iNumerator = tR.iNumerator / gcd(tR.iNumerator, tR.iDemoniator);
        tR.iDemoniator = tR.iDemoniator / gcd(tR.iNumerator, tR.iDemoniator);
    }
    return tR;
}

//string type의 값을 parameter로 해서 string type의 값에 맨 처음과 맨 뒤에 ^^^을 추가하는 함수
//추가 후에는 그 추가한 값을 새로 반환한다. 
string NewString(string sA)
{
    string sStr1(sA);
    sStr1.append("***");
    sStr1.insert(0, "***");
    return sStr1;
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

    std::vector<Rational> v1;
    v1.push_back({ 1 }); v1.push_back({ 3, 7 });
    Print(v1); // prints 1/1, 3/7

    std::string s1 = "C++ programming", s2;
    s2 = NewString(s1); // s2: "***C++ programming***"
    std::cout << s2 << std::endl; // prints ***C++ programming***
}