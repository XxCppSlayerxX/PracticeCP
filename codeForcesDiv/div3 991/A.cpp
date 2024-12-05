#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        int len = 0;
        bool res = false;
        
        for(int i = 0; i < n; ++i){
            string s; cin >> s;
            len += s.size();
            if(len > m && !res){
                cout << i << endl;
                res = true;
            }
        }
        if(!res){
            cout << n << endl;
        }
    }

    return 0;
}