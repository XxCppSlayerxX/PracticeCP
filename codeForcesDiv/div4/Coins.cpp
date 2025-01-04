#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n; cin >> n;
    long long coins = 1;
    if(n < 4){
        cout << 1 << endl;
        return;
    }
    while(n >= 4){
        n /= 4;
        coins *= 2;
    }
    cout << coins << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}