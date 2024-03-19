//
// Created by Анастасия Смирнова on 3/19/24.
//
#include <iostream>


std::basic_string<char> removeSpace(std::string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            s.erase(s.begin() + i);
            i--;
        }
    }
    return s;
}

bool checkForPalindrome(std::string str) {
    if (str[0] == '\0')
        return false;
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << (checkForPalindrome(removeSpace(str)) ? "yes" : "no");
    return 0;
}