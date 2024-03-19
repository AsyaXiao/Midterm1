//
// Created by Анастасия Смирнова on 3/19/24.
//
#include <vector>
#include <iostream>
#include <sstream>
std::string ExtractDigits(const std::string &s) {
    std::string answ;
    for (char const &c: s) {
        if (isdigit(c))
            answ += c;
    }
    return answ;
}