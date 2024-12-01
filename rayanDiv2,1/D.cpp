#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    vector<pair<int,int>> moves;
    
    // Keep trying until we can't make any more moves
    while (true) {
        bool changed = false;
        
        // Try every possible pair that has difference = 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && a[i] - a[j] == 1) {
                    a[i]--;
                    a[j]++;
                    moves.push_back({i+1, j+1});
                    changed = true;
                    break;
                }
            }
            if (changed) break;
        }
        
        if (!changed) break;
    }
    
    cout << moves.size() << "\n";
    for (const auto &move : moves) {
        cout << move.first << " " << move.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}