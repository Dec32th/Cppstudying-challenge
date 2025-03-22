// temperature_staticlib.cpp : 정적 라이브러리를 위한 함수를 정의합니다.
//

#include "framework.h"

#pragma once

#include <iostream>
#include <stdexcept>
using namespace std;


enum Unit { CELCIUS, KELVIN, FAHRENHEIT };

template <typename Value>
class Temperature
{
private:
    Value amount; // 항상 섭씨(Celsius) 기준으로 저장
    Unit unit;

public:
    Temperature(Value v, Unit u);

    // 리터럴 연산자 선언
    friend Temperature<Value> operator"" _C(long double v);
    friend Temperature<Value> operator"" _F(long double v);
    friend Temperature<Value> operator"" _K(long double v);

    // 비교 연산자
    bool operator==(const Temperature& other) const;
    bool operator!=(const Temperature& other) const;
    bool operator>(const Temperature& other) const;
    bool operator>=(const Temperature& other) const;
    bool operator<(const Temperature& other) const;
    bool operator<=(const Temperature& other) const;

    // 산술 연산자
    Temperature operator+(const Temperature& other) const;
    Temperature operator-(const Temperature& other) const;

    // 변환 메소드
    Temperature<Value> to_Celcius() const;
    Temperature<Value> to_Fahrenheit() const;
    Temperature<Value> to_Kelvin() const;

    // 값 반환 메소드
    Value get_amount() const { return amount; }
    Unit get_unit() const { return unit; }
};

// ------------------ 구현부 ------------------

// 생성자 정의
template <typename Value>
Temperature<Value>::Temperature(Value v, Unit u) {
    if (u == CELCIUS) {
        amount = v;
    }
    else if (u == KELVIN) {
        amount = v - static_cast<Value>(273.15);
    }
    else {
        amount = (v - 32) * static_cast<Value>(5.0 / 9.0);
    }
    unit = u;
}

// 리터럴 연산자 구현

Temperature<long double> operator"" _C(long double v) {
    return Temperature<long double>(static_cast<long double>(v), CELCIUS);
}

Temperature<long double> operator"" _F(long double v) {
    return Temperature<long double>(static_cast<long double>((v - 32) * 5.0 / 9.0), FAHRENHEIT);
}

Temperature<long double> operator"" _K(long double v) {
    return Temperature<long double>(static_cast<long double>(v - 273.15), KELVIN);
}

// 비교 연산자
template <typename Value>
bool Temperature<Value>::operator==(const Temperature& other) const {
    return amount == other.amount;
}

template <typename Value>
bool Temperature<Value>::operator!=(const Temperature& other) const {
    return !(*this == other);
}

template <typename Value>
bool Temperature<Value>::operator>(const Temperature& other) const {
    return amount > other.amount;
}

template <typename Value>
bool Temperature<Value>::operator>=(const Temperature& other) const {
    return amount >= other.amount;
}

template <typename Value>
bool Temperature<Value>::operator<(const Temperature& other) const {
    return amount < other.amount;
}

template <typename Value>
bool Temperature<Value>::operator<=(const Temperature& other) const {
    return amount <= other.amount;
}

// 산술 연산자
template <typename Value>
Temperature<Value> Temperature<Value>::operator+(const Temperature& other) const {
    if (unit != other.unit) {
        throw domain_error("Different units cannot be added.");
    }
    return Temperature(amount + other.amount, unit);
}

template <typename Value>
Temperature<Value> Temperature<Value>::operator-(const Temperature& other) const {
    if (unit != other.unit) {
        throw domain_error("Different units cannot be subtracted.");
    }
    return Temperature(amount - other.amount, unit);
}

// 변환 메소드
template <typename Value>
Temperature<Value> Temperature<Value>::to_Celcius() const {
    return *this;
}

template <typename Value>
Temperature<Value> Temperature<Value>::to_Fahrenheit() const {
    return Temperature<Value>(amount * static_cast<Value>(9.0 / 5.0) + 32, FAHRENHEIT);
}

template <typename Value>
Temperature<Value> Temperature<Value>::to_Kelvin() const {
    return Temperature<Value>(amount + static_cast<Value>(273.15), KELVIN);
}