//
// Created by Анастасия Смирнова on 3/19/24.
//
#include <iostream>
#include <string>

bool validityOfPassword(std::string str) {
    int countL = 0, countS = 0, countN = 0, countE = 0;
    if (str[0] == '\0')
        return false;
    size_t i = 0;
    while (str[i] != '\0') {
        if ((int) str[i] < 33 || (int) str[i] > 127)
            return false;
        else {
            if ((int) str[i] >= 65 && (int) str[i] <= 90)
                ++countL;
            else if ((int) str[i] >= 97 && (int) str[i] <= 122)
                ++countS;
            else if ((int) str[i] >= 48 && (int) str[i] <= 57)
                ++countN;
            else
                ++countE;
        }

        ++i;
    }
    if (countL + countS == 0 || countL + countN == 0 || countL + countE == 0 || countS + countN == 0 ||
        countS + countE == 0 || countN + countE == 0)
        return false;

    if (str.length() < 8 || str.length() > 14)
        return false;

    return true;
}

int main() {
    std::string text;
    std::cin >> text;
    std::cout << (validityOfPassword(text) ? "YES" : "NO");
    return 0;
}