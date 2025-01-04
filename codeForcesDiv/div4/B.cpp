#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n; cin>>n;
   if(n ==1){
    cout << 0 << endl;
    return;
   }
   cout << n-1 << endl;
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