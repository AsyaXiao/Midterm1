//
// Created by Анастасия Смирнова on 3/19/24.
//

#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cout << "\t";
    for (int i = 1; i <= n; i++)
        cout << i << "\t";
    cout<<endl;
    for (int i = 1; i <= n; i++) {
        cout << i << "\t";
        for (int j = 1; j <= n; j++) {
            cout << (i * j) % k << "\t";
        }
        cout << endl;
    }

    return 0;
}