#include "bits/stdc++.h"
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int dot = 0;
        int i = 1;

        while (abs(dot) <= n) {
            int x = 2 * i - 1;

            if (i % 2 == 0) {
                dot += x;
            } else {
                dot -= x;
            }

            i++;
        }

        if ((i+1) % 2 == 0) {
            cout << "Kosuke" << endl;
        } else {
            cout << "Sakurako" << endl;
        }
    }

    return 0;
}
