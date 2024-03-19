//
// Created by Анастасия Смирнова on 3/19/24.
//
#include <iostream>

using namespace std;

int main() {
    int d;
    int m;
    int y;
    bool x = false;
    cin >> d >> m >> y;
    d = d + 2;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        x = true;
    }
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10) {
        if (d > 31) {
            d = d % 31;
            m++;
        }
    } else if (m == 2) {
        if (x) {
            if (d > 29) {
                d = d % 29;
                m++;
            }
        } else {
            if (d > 28) {
                d = d % 28;
                m++;
            }
        }
    } else if (m == 12) {
        if (d > 31) {
            d = d % 31;
            m = 1;
            y++;
        }
    } else {
        if (d > 30) {
            d = d % 30;
            m++;
        }
    }
    cout << d << " " << m << " " << y;
    return 0;
}