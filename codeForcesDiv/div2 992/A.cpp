#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n,k; cin >>n>>k;
   vector<int> a(n + 1);
   for(int i = 1; i <= n; ++i){
        cin>>a[i];
   }
   bool ans = true;
   for(int i = 1; i <= n; ++i){
        ans = true;
        for(int j = 1; j <=n; ++j){
            if(i == j){
                continue;
            }
            if(abs(a[i] - a[j]) %  k == 0){
                ans = false;
                break;
            } 
        }
        if(ans){
            cout << "YES" << endl << i << endl;
            return;
        }
   }
   cout <<"NO" << endl;
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