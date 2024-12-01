#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string horse;
    cin >> horse;

    int res = 0;  
    int consecutive = 0;  

    for (int i = 0; i < n;) {
        if (horse[i] == '0') {
            consecutive++;
        } else {
            consecutive = 0;  
        }

        if (consecutive >= m) {
            res++;
            for (int j = 0; j < k && i + j < n; ++j) {
                horse[i + j] = '1';
            }
            i += k;
            consecutive = 0;  
        } else {
            i++;  
        }
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
