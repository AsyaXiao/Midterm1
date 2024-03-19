//
// Created by Анастасия Смирнова on 3/19/24.
//
#include <vector>
#include <iostream>
#include <sstream>

std::vector<std::string> split(const std::string &str, char delimiter) {
    std::string line;
    std::stringstream ss(str);
    std::vector<std::string> answ;
    while (ss.good()) {
        std::getline(ss, line, delimiter);
        answ.push_back(line);
    }
    return answ;
}