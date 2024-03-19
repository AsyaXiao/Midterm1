//
// Reversed permutation
//
#include <vector>
#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> Mas1(n + 1);
    vector<int> Answ(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> Mas1[i];
    }

    for (int i = 1; i <= n; ++i) {
        Answ[Mas1[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        cout << Answ[i] << " ";
    }
}