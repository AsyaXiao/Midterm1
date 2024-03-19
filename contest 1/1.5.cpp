//
// Machine parts
//
#include <iostream>

int main() {
    int n, k, m, z = 0, answ = 0;
    std::cin >> n >> k >> m;

    while (n >= k) {
        z = n / k;
        n = n - (k / m) * z * m;
        answ = answ + (k / m) * z;
        if (answ == 0)
            break;
    }
    std::cout << answ;
    return 0;
}