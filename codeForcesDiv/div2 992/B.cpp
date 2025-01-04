#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return;
    }else if(n <= 4){
        cout << 2 << endl;
        return;
    }

    int count = 2;
    int cover = 4;
    while(cover < n){
        cover++;
        cover *= 2;
        count++;
    }
    cout << count << endl;
    return;
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