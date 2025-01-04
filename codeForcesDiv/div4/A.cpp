#include <bits/stdc++.h>
using namespace std;

void solve() {
   string s;
   cin>>s;
   for(int i = s.size() - 1; i >= 0;i--){
        if(s[i] == 'q'){
            cout << 'p';
        }else if(s[i] == 'p'){
            cout<<'q';
        }else{
            cout <<'w';
        }
   }
   cout << endl;
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