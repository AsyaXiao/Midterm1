//
// MKAD
//
#include <iostream>

using namespace std;

int main() {
    int s, v, t = 0;
    cin >> v;
    cin >> t;
    s = v * t;
    if (v > 0) {
        if (s < 109) {
            cout << s;
        } else {
            while (s > 108) {
                s = s - 109;
            }
            cout << s;
        }
    } else {
        if (s > -109) {
            cout << (109 + s);
        } else {
            while (s < -109) {
                s = s + 109;
            }
            cout << 109 + s;
        }
    }
    return 0;
}