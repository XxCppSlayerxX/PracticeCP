#include <bits/stdc++.h>
using namespace std;

bool isComposite(int x) {
    if (x <= 3) return false; 
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return true; 
    }
    return false; 
}

void solve(int n) {
    vector<int> result;

    for (int i = 1; i <= n; i += 2) {
        result.push_back(i);
    }

    for (int i = 2; i <= n; i += 2) {
        result.push_back(i);
    }

    if (n % 2 == 0) { 
        int i = n / 2;
        while (!isComposite(result[n / 2 - 1] + result[n / 2])) {
            if (i + 1 >= n) { 
                cout << -1 << endl;
                return;
            }
            swap(result[n / 2], result[i + 1]);
            i++;
        }
    } else { 
        int i = n / 2 + 1;

        while (!isComposite(result[n / 2] + result[n / 2 + 1])) {
            if (i + 1 >= n) { 
                cout << -1 << endl;
                return;
            }
            swap(result[n / 2 + 1], result[i + 1]);
            i++;
        }
    }

    

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n;
        if (n < 5) {
            cout << -1 << endl;
        } else {
            solve(n);
        }
    }

    return 0;
}
