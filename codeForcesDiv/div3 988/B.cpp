#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        vector<int> divisors;
        for (int i = 1; i * i <= n - 2; ++i) {
            if ((n - 2) % i == 0) {
                divisors.push_back(i);
                if (i != (n - 2) / i) {
                    divisors.push_back((n - 2) / i);
                }
            }
        }
        bool found = false;
        for (int i = 0; i < divisors.size(); ++i) {
            int d1 = divisors[i];
            if (find(a.begin(), a.end(), d1) != a.end()) {
                for (int j = i; j < divisors.size(); ++j) {
                    int d2 = divisors[j];
                    if (find(a.begin(), a.end(), d2) != a.end() && d1 * d2 == (n - 2)) {
                        found = true;
                        cout << d1 << " " << d2 << endl;
                        break;
                    }
                }
            }
            if (found) {
                break;
            }
        }

    }
    
    return 0;
}