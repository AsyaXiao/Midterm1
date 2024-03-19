//
// ln 2
//
#include <iostream>
#include <cmath>

int main() {
    double count = 0, n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        count = count + pow((-1), i + 1) * (1. / i);
    }
    std::cout << count;
    return 0;
}
