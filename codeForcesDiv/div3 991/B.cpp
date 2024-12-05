#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum % n != 0) {
            cout << "NO" << endl;
            continue;
        }

        long long target = sum / n;
        long long balance = 0;
        bool possible = true;

        long long even_balance = 0, odd_balance = 0;

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                even_balance += a[i] - target; 
            } else {
                odd_balance += a[i] - target; 
            }
        }

        if (even_balance == 0 && odd_balance == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
