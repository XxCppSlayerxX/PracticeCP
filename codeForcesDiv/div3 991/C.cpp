#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; 
    cin >> t;
    
    while (t--) {
        string n; 
        cin >> n;

        int sum = 0, twos = 0, threes = 0;
        
        for (char c : n) {
            int digit = c - '0';
            sum += digit;
            if (digit == 2) twos++;
            if (digit == 3) threes++;
        }
        
        if (sum % 9 == 0) {
            cout << "YES" << endl;
            continue;
        }

        
        bool possible = false;

        for (int i = 0; i <= twos; ++i) {
            for (int j = 0; j <= threes; ++j) {
                int new_sum = sum + i * (4 - 2) + j * (9 - 3);
                if (new_sum % 9 == 0) {
                    possible = true;
                    break;
                }
            }
            if (possible) break;
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
