#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    
    if(k == 1) {
        cout << max(0LL, min(r1, r2) - max(l1, l2) + 1) << "\n";
        return;
    }
    
    ll ans = 0;
    ll pwr = 1;
    
    while(true) {
        ll y_min = max(l2, pwr * l1);
        ll y_max = min(r2, pwr * r1);
        
        if(y_min <= y_max) {
            ll x_min = max(l1, (y_min + pwr - 1) / pwr);
            ll x_max = min(r1, y_max / pwr);
            
            if(x_min <= x_max) {
                ans += x_max - x_min + 1;
            }
        }
        
        if(r2/k < pwr || pwr > r2/l1) break;
        pwr *= k;
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}