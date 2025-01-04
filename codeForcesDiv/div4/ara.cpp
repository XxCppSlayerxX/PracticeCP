#include <bits/stdc++.h>
using namespace std;
static const int MAXN = 200005;

void solve() {
    int n;
    cin >> n;
    vector<int> r(n + 1);
    
    for(int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    
    bitset<MAXN> curr, next;
    curr.set(); // Set all to 1
    curr[0] = 0; // Don't use index 0
    
    for(int year = 1; year <= n + 2; year++) {
        next.reset();
        for(int i = 1; i <= n; i++) {
            if(curr[i]) {
                next[r[i]] = 1;
            }
        }
        
        if(year > 1 && curr == next) {
            if(year == 2){
                            cout << year << '\n';

            }else{
                            cout << year + 1 << '\n';

            }
            return;
        }
        curr = next;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}