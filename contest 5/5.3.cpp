//
// Created by Анастасия Смирнова on 3/19/24.
//
#include <iostream>
#include <cmath>

class Complex {
    double _re;
    double _im;

public:
    Complex(double re, double im) {
        _re = re;
        _im = im;
    }

    Complex(double re) {
        _re = re;
        _im = 0;
    }

    bool operator==(const Complex &rhs) const {
        return rhs.Re() == Re() && rhs.Im() == Im();
    }

    bool operator!=(const Complex &rhs) const {
        return !(*this == rhs);
    }

    Complex operator+(const Complex &rhs) const {
        return Complex(rhs.Re() + Re(), rhs.Im() + Im());
    }

    Complex operator-(const Complex &rhs) const {
        return Complex(Re() - rhs.Re(), Im() - rhs.Im());
    }

    Complex operator*(const Complex &rhs) const {
        double re = Re() * rhs.Re() - Im() * rhs.Im();
        double im = Re() * rhs.Im() + Im() * rhs.Re();
        return Complex(re, im);
    }

    Complex operator/(const Complex &rhs) const {
        double denominator = rhs.Re() * rhs.Re() + rhs.Im() * rhs.Im();
        double re = (Re() * rhs.Re() + Im() * rhs.Im()) / denominator;
        double im = (Im() * rhs.Re() - Re() * rhs.Im()) / denominator;
        return Complex(re, im);
    }

    Complex operator-() const {
        return Complex(-_re, -_im);
    }

    Complex operator+() const {
        return *this;
    }

    double Re() const {
        return _re;
    }

    double Im() const {
        return _im;
    }
};

Complex operator*(const Complex &lhs, const double &rhs) {
    return Complex(lhs.Re() * rhs, lhs.Im() * rhs);
}

Complex operator*(const double &lhs, const Complex &rhs) {
    return rhs * lhs;
}

double abs(const Complex &a) {
    return sqrt(a.Re() * a.Re() + a.Im() * a.Im());
}

