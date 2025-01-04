#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    
    int row1_seated = min(m, a); 
    int row2_seated = min(m, b);  // Don't seat more than m in row 2
    
    int row1_remaining = m - row1_seated;
    int row2_remaining = m - row2_seated;
        int c_used = min(c, row1_remaining + row2_remaining);
    
    cout << row1_seated + row2_seated + c_used << '\n';
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