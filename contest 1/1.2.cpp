//
//  Sum of digits
//
#include <iostream>

int main() {
    long int x;
    int count = 0;
    std::cin >> x;
    while (x > 0) {
        count = count + x % 10;
        x = x / 10;
    }
    std::cout << count;
    return 0;
}
