//
// Created by Анастасия Смирнова on 3/19/24.
//
#include <string>
#include <iostream>

using namespace std;

std::string join(const std::vector<std::string> &tokens, char delimiter) {
    int count = 0;
    std::string answ;
    while (count < tokens.size()) {
        answ = answ + tokens[count] + delimiter;
        ++count;
    }
    answ.pop_back();
    return answ;
}