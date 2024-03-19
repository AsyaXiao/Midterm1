//
// Created by Анастасия Смирнова on 3/19/24.
//
#include <iostream>
#include <cmath>

class Rational
{
    int _numerator;
    int _denominator;

    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    void reduce()
    {
        int common_divisor = gcd(_numerator, _denominator);
        _numerator /= common_divisor;
        _denominator /= common_divisor;

        if (_denominator < 0)
        {
            _numerator *= -1;
            _denominator *= -1;
        }
    }

public:
    Rational(int numerator = 0, int denominator = 1) : _numerator(numerator), _denominator(denominator)
    {
        reduce();
    }

    int numerator() const
    {
        return _numerator;
    }
    int denominator() const
    {
        return _denominator;
    }

    Rational operator+(const Rational& rhs) const
    {
        return Rational(_numerator * rhs._denominator + rhs._numerator * _denominator,
                        _denominator * rhs._denominator);
    }

    Rational operator-(const Rational& rhs) const
    {
        return Rational(_numerator * rhs._denominator - rhs._numerator * _denominator,
                        _denominator * rhs._denominator);
    }

    Rational operator*(const Rational& rhs) const
    {
        return Rational(_numerator * rhs._numerator, _denominator * rhs._denominator);
    }

    Rational operator/(const Rational& rhs) const
    {
        return Rational(_numerator * rhs._denominator, _denominator * rhs._numerator);
    }

    Rational operator-() const
    {
        return Rational(-_numerator, _denominator);
    }

    Rational operator+() const
    {
        return *this;
    }

    Rational& operator+=(const Rational& rhs)
    {
        *this = *this + rhs;
        return *this;
    }

    Rational& operator-=(const Rational& rhs)
    {
        *this = *this - rhs;
        return *this;
    }

    Rational& operator*=(const Rational& rhs)
    {
        *this = *this * rhs;
        return *this;
    }

    Rational& operator/=(const Rational& rhs)
    {
        *this = *this / rhs;
        return *this;
    }

    bool operator==(const Rational& rhs) const
    {
        return _numerator == rhs._numerator && _denominator == rhs._denominator;
    }

    bool operator!=(const Rational& rhs) const
    {
        return !(*this == rhs);
    }

    Rational& operator++()
    {
        *this += Rational(1);
        return *this;
    }

    Rational operator++(int)
    {
        Rational temp = *this;
        *this += Rational(1);
        return temp;
    }

    Rational& operator--()
    {
        *this -= Rational(1);
        return *this;
    }

    Rational operator--(int)
    {
        Rational temp = *this;
        *this -= Rational(1);
        return temp;
    }


    friend Rational operator*(int lhs, const Rational& rhs)
    {
        return Rational(lhs * rhs._numerator, rhs._denominator);
    }
};