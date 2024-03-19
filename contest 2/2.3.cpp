//
// Created by Анастасия Смирнова on 3/19/24.
//
#include <iostream>
#include <string>

void Append(std::string &res, char c) {
    if (res.back() != c) {
        res.push_back(c);
    }
}

std::string soundex_check(const std::string &text) {
    std::string res;
    res.push_back(text[0]);
    for (int i = 1; i != text.size(); ++i) {
        char smth = text[i];
        switch (smth) {
            case 'b':
            case 'f':
            case 'p':
            case 'v':
                Append(res, '1');
                break;
            case 'c':
            case 'g':
            case 'j':
            case 'k':
            case 'q':
            case 's':
            case 'x':
            case 'z':
                Append(res, '2');
                break;
            case 'd':
            case 't':
                Append(res, '3');
                break;
            case 'l':
                Append(res, '4');
                break;
            case 'm':
            case 'n':
                Append(res, '5');
                break;
            case 'r':
                Append(res, '6');
                break;
        }
    }
    while (res.size() < 4) {
        res.push_back('0');
    }
    res.resize(4);
    return res;
}

int main() {
    std::string text;
    std::cin >> text;
    std::cout << soundex_check(text) << std::endl;
}
